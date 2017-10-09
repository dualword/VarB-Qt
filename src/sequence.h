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
#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <QObject>
#include <QMap>
#include "sourcesdialog.h"

class Sequence : public QObject {
    Q_OBJECT
public:
    explicit Sequence(QObject *parent = 0) : QObject(parent) { }
    ~Sequence() { clear(); }
    void clear();
    static void info (SourcesDialog* dialog, QString filename);
    bool loadFASTA (QString filename, QString filter);
    QString getCodon(QString chr, int position, int direction);
    QString reverse(QString codon);
    QChar reverse(QChar snp);

    QMap <QString,QString> chromosomes;
    QString source_file;

private:
    bool addSimpleSequence (QString name, QString sequence, QString filter);
    int seqRead;
};

#endif // SEQUENCE_H
