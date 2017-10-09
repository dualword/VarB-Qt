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
#ifndef TRACKGRAPH_H
#define TRACKGRAPH_H

#include "track.h"

typedef struct {
    qint64  position;
    double  data;
} GraphData;

class TrackGraph : public Track {
    Q_OBJECT
public:
    TrackGraph(QObject* parent, QString _label, QString _title);
    ~TrackGraph();
    void paint(QPainter &painter);
    QString whatsthis() { return label; }
    virtual void calculateData() = 0;
    virtual void calculateData(QString& chr) = 0;
    virtual void clear();
    QMap<QString, int> size;
    QMap<QString, GraphData*> data;
protected:
    virtual void paintRect(QPainter &painter, int x1, int h, int w);
    virtual void paintLine(QPainter &painter, int last_x, int h);
    virtual void paintLines(QPainter &painter) { Q_UNUSED(painter) }
    virtual void changeChromosome();
    virtual void changePosition();
    virtual void changeFilter();
    virtual void changeGroups();
    int window;
    Range paintedRange;
//    QList<int> paintedDataX;
//    QList<int> paintedDataH;
};

#endif // TRACKGRAPH_H
