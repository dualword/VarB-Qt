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
#ifndef VARIATION_H
#define VARIATION_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QList>
#include <QRect>
#include <QStringList>
#include "annotation.h"
#include "sequence.h"
#include "sourcesdialog.h"

typedef struct {
    double  qualityMin;
    double  qualityMax;
    qint64  readDepthMin;
    qint64  readDepthMax;
} Extrema;

typedef struct {
    QChar   haplotypeStrong;  //  The haplotype with the biggest read depth.
    long    haplotype1;
    long    haplotype2;
    long    readDepth;
    bool    insertion;
    bool    deletion;
    int     coding;  //  -1 = neg strand, +1 = pos strand, 0 = non-coding
    bool    synonymous;
    bool    nonSynonymous;
    bool    phased;
} VariationData;

class VariationPosition : public QObject {
    Q_OBJECT
public:
    ~VariationPosition();
    QString getDescription();
    QString getGenotypeText (QString call);

    QString chromosome, id, filter, info; //, type;
    long position;
    double quality, alleleFrequency;
    VariationData *data;

    QMap <QString,int> format;
    QList <QString> genotypes;
    QList <long> genotypeLengths;
    QRect r;
    bool painted;
};

class Variation : public QObject {
    Q_OBJECT
public:
    explicit Variation(QObject *parent = 0);
    ~Variation() { clear(); }
    void clear();
    static void info (SourcesDialog* dialog, QString filename);
    bool loadVCF (QString filename, Sequence *seq, Annotation *ann, QString f);

    QString source_file;
    QString filter;
    QList<QString> samples; // Sample list
    QMap<int,QRect> sample_r; // Sample row display area for mouseevent
    QMap<QString,QList<VariationPosition*> > data;
    QMap<QString,Extrema> extrema;
    QMap<QString,QList<int> > groups;
    bool phased;
};

#endif // VARIATION_H
