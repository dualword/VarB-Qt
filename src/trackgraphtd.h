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
#ifndef TRACKGRAPHTD_H
#define TRACKGRAPHTD_H

#include "trackgraph.h"

class TrackGraphTD : public TrackGraph {
    Q_OBJECT
public:
    TrackGraphTD(QObject* parent) : TrackGraph(parent, "Tajima's D\nBarriers: -2, +2", "TajimasD") { }
    virtual void calculateData();
    virtual void calculateData(QString& chr);
protected:
    virtual void paintRect(QPainter &painter, int x1, int h, int w);
    virtual void paintLine(QPainter &painter, int last_x, int h);
    virtual void paintLines(QPainter &painter);
};

#endif // TRACKGRAPHTD_H
