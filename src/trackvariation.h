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
#ifndef TRACKVARIATION_H
#define TRACKVARIATION_H

#include "track.h"
#include "variation.h"

class TrackVariation : public Track {
    Q_OBJECT
public:
    explicit TrackVariation(QObject *parent = 0);
    ~TrackVariation();
    virtual void clear();

    virtual void paintLabel(QPainter &painter);
    virtual void paint(QPainter &painter);
    virtual void recalculateLayout();
    virtual QString whatsthis() { return "variation"; }
    virtual void mouseEvent(QMouseEvent *event,QString region,bool doubleclick);

    Variation variants;
    long sample_height;
    int last_paint_start, last_paint_end;

protected:
    bool paintArea (VariationPosition *v, QPainter &painter, long x1, long y, long x2, int f, int t, const QColor &color);
};

#endif // TRACKVARIATION_H
