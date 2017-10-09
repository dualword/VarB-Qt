/*
 *  VarB - genomic analysis software
 *
 *  software.markdpreston.com/varb
 *
 *  (c) Mark D Preston, H Magnus Manske 2011-
 *
 *  When using this software, commercially or academically, please
 *  get in contact and reference:
 *
 *  Mark D Preston, H Magnus Manske, et al.
 *  VarB: A Variation Browsing tool for polymorphisms derived from
 *  next-generation sequence data
 *  In submission
 *
 *
 *  This software was written, in large part, at the London School of
 *  Hygiene and Tropical Medicine, UK and the Sanger Institute
 *  Cambridge, UK.
 *
 *
 *  This file is part of VarB.
 *
 *  VarB is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  VarB is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with VarB.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include "variation.h"
#include "mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QMessageBox>
#include <QStatusBar>
#include <QTextStream>
#include <QProgressDialog>

Variation::Variation(QObject *parent) : QObject(parent) {
    clear();
}

void Variation::clear() {
    foreach (QList<int> g, groups) g.clear();
    groups.clear();
    groups["Ungrouped"];
    phased = true;
    samples.clear();
    sample_r.clear();
    extrema.clear();
    foreach (QList<VariationPosition*> d, data) {
        foreach (VariationPosition* v, d) delete v;
        d.clear();
    }
}

void Variation::info(SourcesDialog *dialog, QString filename) {
    QString chromosome, lastChromosome = "";
    QMap<QString,int> count;
    QFile file(filename);
    if (! file.exists()) {
        QMessageBox msgBox;
        msgBox.setText("No variation file: " + filename);
        msgBox.exec();
        return;
    }
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull()) {
        if (line.startsWith("#")) {
        } else {
            chromosome = line.trimmed().split(QRegExp("\\s+"))[0];
            count[chromosome]++;
            if (0 == (count[chromosome] % 100)) dialog->update("variation", chromosome, count[chromosome]);
            if (lastChromosome != chromosome) dialog->update("variation", chromosome, count[chromosome]);
            lastChromosome = chromosome;
        }
        line = in.readLine();
    }
    dialog->update("variation", count);
    file.close();
}

bool Variation::loadVCF (QString filename, Sequence *seq, Annotation *ann, QString f) {
    qDebug() << "Variation::loadVCF start";
    bool added = false;
    int linesRead = 0;
    source_file = filename;
    filter = f;
    QFile file(filename);
    if (! file.exists()) return false;
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream parse(&file);
    QString line = parse.readLine(), chr;
    QMap<QString,int> lines;
    MainWindow::instance->feedback.update(3,"Preparing for ");
    while (!line.isNull()) {
        chr = line.simplified().section(' ',0,0);
        if (chr[0] != '#' && (filter == "" || chr == filter)) {
            lines[chr]++;
        }
        line = parse.readLine();
    }
    foreach (QString l, lines.keys()) {
        data[l].reserve(lines[l]);
    }
    parse.reset();
    file.close();
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    line = in.readLine();
    while (!line.isNull()) {
        if (line.startsWith("#")) { // TODO : Parse this better!
            if (line.startsWith("#CHROM\t")) {
                QStringList parts = line.trimmed().split('\t');
                for (int a = 9; a < parts.size(); a++) {
                    groups["Ungrouped"].append(samples.size());
                    samples.append(parts[a]);
//                    qDebug() << "Samples" << parts[a];
                }
            }
        } else {
            if (0 == (linesRead % 1000)) MainWindow::instance->feedback.update(3,QString::number(linesRead));
            linesRead++;
            QStringList parts = line.trimmed().split(QRegExp("\\s+"));
            if (filter != "" && parts[0] != filter) {
                line = in.readLine();
                continue;
            }
//            qDebug() << linesRead << parts.length() << parts[0] << samples.length();
//            if (parts.length() != samples.length() + 9) return false;
            VariationPosition *vp = new VariationPosition();
            vp->chromosome = parts[0];
            vp->position = parts[1].toInt();
            vp->id = parts[2];
            vp->genotypes.append(parts[3].toUpper());
            if ("." != parts[4]) vp->genotypes.append(parts[4].toUpper().split(","));
            vp->quality = parts[5].toDouble();
            vp->filter = parts[6];
            vp->info = parts[7];
            if (0 > vp->quality) { vp->quality = 0; }

            foreach(QString gt, vp->genotypes) vp->genotypeLengths.append(gt.length());

            long readDepth = 1;
            QString info;
            foreach (info, parts[7].split(';')) {
                if (info.split("=")[0] == "DP") readDepth = info.split("=")[1].toLong();
            }

            QStringList format = parts[8].split(':');
            for (int a = 0; a < format.size(); a++) {
                vp->format[format[a]] = a;
            }
//            qDebug() << parts[8];
            //vp->type // TODO

            if (! extrema.contains(vp->chromosome)) {
                extrema[vp->chromosome].qualityMin = 10000000000;
                extrema[vp->chromosome].qualityMax = 0;
                extrema[vp->chromosome].readDepthMin = 10000000000;
                extrema[vp->chromosome].readDepthMax = 0;
            }
            if (extrema[vp->chromosome].qualityMin > vp->quality) { extrema[vp->chromosome].qualityMin = vp->quality; }
            if (extrema[vp->chromosome].qualityMax < vp->quality) { extrema[vp->chromosome].qualityMax = vp->quality; }

            vp->data = new VariationData[parts.size() - 9];
            QRegExp re = QRegExp("[/|]");
            QMap<QString, int>::const_iterator itgt = vp->format.find("GT");
            QMap<QString, int>::const_iterator itdp = vp->format.find("DP");
            QMap<QString, int>::const_iterator itdpa = vp->format.find("DPA");
            QMap<QString, int>::const_iterator itdpc = vp->format.find("DPC");
            QMap<QString, int>::const_iterator itdpg = vp->format.find("DPG");
            QMap<QString, int>::const_iterator itdpt = vp->format.find("DPT");
            int alleles = 0, alleleCount = 0;
            int baseLength = vp->genotypeLengths[0];
            for (int a = 0; a < parts.size() - 9; a++) {
//                qDebug() << a << parts[a+9];
                QStringList data = parts[a + 9].split(':');
                if ("." != parts[a + 9] && itgt != vp->format.end()) {
                    QStringList gts = data[itgt.value()].split(re, QString::SkipEmptyParts);
                    vp->data[a].phased = data[itgt.value()].contains("|");
                    vp->data[a].haplotype1 = gts[0].toLong();
                    vp->data[a].haplotype2 = gts.count() > 1 ? gts[1].toLong() : gts[0].toLong();
                    vp->data[a].deletion = (vp->genotypeLengths[vp->data[a].haplotype1] < baseLength) || (vp->genotypeLengths[vp->data[a].haplotype2] < baseLength);
                    vp->data[a].insertion = (vp->genotypeLengths[vp->data[a].haplotype1] > baseLength) || (vp->genotypeLengths[vp->data[a].haplotype2] > baseLength);
                    if (0 == vp->data[a].haplotype1) alleles++;
                    if (0 == vp->data[a].haplotype2) alleles++;
                    alleleCount += 2;
                } else {
                    vp->data[a].phased = true;
                    vp->data[a].haplotype1 = -1;
                    vp->data[a].haplotype2 = -1;
                    vp->data[a].deletion = false;
                    vp->data[a].insertion = false;
                }
                vp->data[a].coding = ann->isCoding(vp->chromosome, vp->position);;
                vp->data[a].nonSynonymous = false;
                vp->data[a].synonymous = false;
                vp->data[a].readDepth = readDepth;
                phased = phased & vp->data[a].phased;
                if ("." != parts[a + 9] && itdp != vp->format.end()) vp->data[a].readDepth = data[itdp.value()].toLong();
                //  For the synonymous test set the strongest haplotype to the 'most' alternate.
                int genotype = vp->data[a].haplotype1 > vp->data[a].haplotype2 ? vp->data[a].haplotype1 : vp->data[a].haplotype2;
                if (genotype == -1) { genotype = 0; }
                vp->data[a].haplotypeStrong = vp->genotypes[genotype][0];
                if (vp->data[a].haplotype1 != vp->data[a].haplotype2) {
                    int dp1 = 0; int dp2 = 0;
                    if (itdpa != vp->format.end() && vp->genotypes[vp->data[a].haplotype1] == "A") dp1 = data[itdpa.value()].toLong();
                    if (itdpc != vp->format.end() && vp->genotypes[vp->data[a].haplotype1] == "C") dp1 = data[itdpc.value()].toLong();
                    if (itdpg != vp->format.end() && vp->genotypes[vp->data[a].haplotype1] == "G") dp1 = data[itdpg.value()].toLong();
                    if (itdpt != vp->format.end() && vp->genotypes[vp->data[a].haplotype1] == "T") dp1 = data[itdpt.value()].toLong();
                    if (itdpa != vp->format.end() && vp->genotypes[vp->data[a].haplotype2] == "A") dp2 = data[itdpa.value()].toLong();
                    if (itdpc != vp->format.end() && vp->genotypes[vp->data[a].haplotype2] == "C") dp2 = data[itdpc.value()].toLong();
                    if (itdpg != vp->format.end() && vp->genotypes[vp->data[a].haplotype2] == "G") dp2 = data[itdpg.value()].toLong();
                    if (itdpt != vp->format.end() && vp->genotypes[vp->data[a].haplotype2] == "T") dp2 = data[itdpt.value()].toLong();
                    if (dp1 > 0 && dp2 > 0) vp->data[a].haplotypeStrong = vp->genotypes[dp1 > dp2 ? vp->data[a].haplotype1 : vp->data[a].haplotype2][0];
                }
                if (extrema[vp->chromosome].readDepthMin > vp->data[a].readDepth && vp->data[a].readDepth != 0) {
                    extrema[vp->chromosome].readDepthMin = vp->data[a].readDepth;
                }
                if (extrema[vp->chromosome].readDepthMax < vp->data[a].readDepth) {
                    extrema[vp->chromosome].readDepthMax = vp->data[a].readDepth;
                }
            }
            vp->alleleFrequency = 1.0 * alleles / alleleCount;
            data[vp->chromosome].append(vp);
            if (extrema[vp->chromosome].qualityMin == 10000000000) { extrema[vp->chromosome].qualityMin = 0; }
            if (extrema[vp->chromosome].readDepthMin == 10000000000) { extrema[vp->chromosome].readDepthMin = 0; }
            added = true;
        }
        line = in.readLine();
    }
    file.close();
    MainWindow::instance->feedback.update(3,QString::number(linesRead));

    //  If there are no matching data points then let the user know a bad load has occured.
    if (! added) { return false; }

    //  Perform synonymous analysis.
    foreach (QString chr, data.keys()) {
        int len = data[chr].length();
        for (int i = 0; i < len; i++) {
            VariationPosition *vp = data[chr][i];
            int direction = ann->isCoding(chr, vp->position);
            if (0 == direction) continue;
            int codonPosition = ann->getCodonPosition(chr, vp->position);
            if (-1 == codonPosition) continue;
            QString codon = seq->getCodon(chr, codonPosition, direction);
            QString alternate;
            for (int j = 0; j < samples.count(); j++) {
                alternate = codon;
                if ( 1 == direction) alternate.replace(vp->position-codonPosition,1,vp->data[j].haplotypeStrong);
                vp->data[j].synonymous = ann->synonymous(codon, alternate);
                vp->data[j].nonSynonymous = ! vp->data[j].synonymous;
            }
        }
    }

    qDebug() << "Variation::loadVCF end";
    return true;
}

VariationPosition::~VariationPosition() {
    delete[] data;
    format.clear();
    genotypes.clear();
    genotypeLengths.clear();
}

QString VariationPosition::getDescription() {
    QString ret;
    if (!id.isEmpty()) ret += "<h2>" + id + "</h2>";
    ret += "<table width='100%' style='font-size:7pt'>";
    ret += "<tr><th align='left' width='50%'>Position</th><td width='50%'>" + chromosome + ":" + QString::number(position) + "</td></tr>";
    ret += "<tr><th align='left'>Reference</th><td>" + genotypes[0] + "</td></tr>";
    if (genotypes.size() > 1) ret += "<tr><th align='left'>Atlernative(s)</th><td>" + genotypes[1] + "</td></tr>";
    ret += "<tr><th align='left'>Quality</th><td>" + QString::number(quality) + "</td></tr>";
    ret += "<tr><th align='left'>Filter</th><td>" + filter + "</td></tr>";
    ret += "<tr><th align='left'>Info</th><td>" + info + "</td></tr>";
    ret += "</table>";
    return ret;
}

QString VariationPosition::getGenotypeText (QString call) {
    QString ret;
    if (call == "0") ret = genotypes[0] + " (ref)";
    else if (call == ".") ret = "<i>missing</i>";
    else if (call.length() == 1) {
        ret = genotypes[call.toInt()] + " (nonref)";
    } else if (call.length() == 3) {
        QString p = call[1] == '|' ? "phased" : "unphased";
        ret = getGenotypeText(call.left(1)) + " / " + getGenotypeText (call.right(1)) + " [" + p + "]";
    }
    return ret;
}
