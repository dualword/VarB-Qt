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
#ifndef TRACKCONTAINER_H
#define TRACKCONTAINER_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPinchGesture>
#include "track.h"
#include "annotation.h"
#include "sequence.h"
#include "variation.h"

namespace Ui {
    class TrackContainer;
}

class TrackContainer : public QWidget {
    Q_OBJECT

public:
    explicit TrackContainer(QWidget *parent = 0);
    ~TrackContainer();

    virtual void setRange (QString chr, long from, long to);
    virtual void setQuality (long quality);
    virtual void setReadDepth (long readDepth);
    void changeChromosome();
    void changePosition();
    void changeFilter();
    void changeGroups();
    void recalculateLayout();
    void checkAndPaint();
    int posPerWidth();
    Track* getTrack(QString name);
    Annotation* getAnnotation();
    Sequence* getSequence();
    Variation* getVariation();

    void startDrag (QPoint p);
    void moveDrag (QPoint p);
    void stopDrag ();
    bool dragging;

    Range range;
    int label_offset;

    QList <Track*> tracklist;
    bool changed;
    bool delayPaint;
    QPoint drag_origin;

protected:
    virtual void changeEvent(QEvent *e);
    virtual void paintEvent(QPaintEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void mouseEvent(QMouseEvent *event,bool doublecklick=false);
    virtual void resizeEvent(QResizeEvent * event);
    virtual void wheelEvent(QWheelEvent * event);
    virtual bool gestureEvent(QGestureEvent *event);
    virtual bool event(QEvent * event);

private:
    Ui::TrackContainer *ui;
};

#endif // TRACKCONTAINER_H
