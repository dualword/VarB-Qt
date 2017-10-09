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
#include "sequence.h"
#include "mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QByteArray>
#include <QProgressDialog>

void Sequence::clear() {
    chromosomes.clear();
}

void Sequence::info(SourcesDialog *dialog, QString filename) {
    QFile file(filename);
    if (! file.exists()) {
        QMessageBox msgBox;
        msgBox.setText("No sequence file: " + filename);
        msgBox.exec();
        return;
    }
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull()) {
        if (line.startsWith(">")) {
            QString chromosome = line.split(QRegExp("\\s+"))[0];
            chromosome.remove(0,1);
            dialog->update("sequence", chromosome, 1);
        }
        line = in.readLine();
    }
    file.close();
}

bool Sequence::loadFASTA (QString filename, QString filter) {
    qDebug() << "Sequence::loadFASTA " << filename;
    bool added = false;
    seqRead = 0;
    source_file = filename;
    QByteArray data;
    QFile f(filename);
    if (! f.exists()) return false;
    f.open(QIODevice::ReadOnly);
    data = f.readAll();
    f.close();
    if (data.isEmpty() || !data.startsWith('>')) return false;

    QString name = "", sequence = " ";  // Make offsets from 1 not 0 into the sequence.
    int mode = 0;
    for (int a = 0; a < data.size(); a++) {
        if (data[a] == '>') {
            name.remove(QRegExp("\\s+"));
            sequence = sequence.toUpper();
            added = added | addSimpleSequence(name, sequence, filter);
            sequence = " ";  // Make offsets from 1 not 0 into the sequence.
            name.clear();
            mode = 1;
            continue;
        }
        if (mode == 1) {
            if ((char)data[a] > 13) name += data[a];
            else mode = 0;
        } else {
            if ((char)data[a] > 13) sequence += data[a];
        }
    }
    added = added | addSimpleSequence(name, sequence, filter);
    return added;
}

bool Sequence::addSimpleSequence(QString name, QString sequence, QString filter) {
    if (name.isEmpty() || sequence.isEmpty() || 0 == sequence.length()) return false;
    if (filter != "" && name != filter) return false;
    chromosomes[name] = sequence.toUpper();
    seqRead++;
    MainWindow::instance->feedback.update(1,QString::number(seqRead));
    qDebug() << "Sequence::addSimpleSequence " << name << " " << sequence.length();
    return true;
}

QString Sequence::getCodon(QString chr, int position, int direction) {
    if (position > 0 && chromosomes.contains(chr) && chromosomes[chr].length() > position + 2) {
        QString codon = QString(chromosomes[chr][position]) + QString(chromosomes[chr][position+1]) + QString(chromosomes[chr][position+2]);
        if ( 1 == direction) return codon;
        if (-1 == direction) return reverse(codon);
    }
    return "XXX";
}

QString Sequence::reverse(QString codon) {
    return QString(reverse(codon[2])) + QString(reverse(codon[1])) + QString(reverse(codon[0]));
}

QChar Sequence::reverse(QChar snp) {
    if (snp == 'A') return 'T';
    if (snp == 'C') return 'G';
    if (snp == 'G') return 'C';
    if (snp == 'T') return 'A';
    return 'X';
}
