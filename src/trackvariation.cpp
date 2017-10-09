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
#include "trackvariation.h"
#include "mainwindow.h"
#include "trackcontainer.h"
#include <QDebug>

TrackVariation::TrackVariation(QObject *parent) : Track(parent) {
    label = "Variation";
    title = label;
    sample_height = 20;
}

TrackVariation::~TrackVariation() {
//    qDebug() << "TrackVariation::~TrackVariation";
    clear();
}

void TrackVariation::clear() {
//    qDebug() << "TrackVariation::clear";
}

void TrackVariation::paintLabel(QPainter &painter) {
//    qDebug() << "TrackVariation::paintLabel start";

    if (label_offset <= 0) return;

    int size = sample_height - 2;
    if (sample_height > 8) size = 8;
    painter.setPen(Qt::black);
    painter.setBrush(Qt::NoBrush);
    painter.setFont(QFont("Arial", size));
    int sn = 0;
    foreach (QString gp, variants.groups.keys()) {
        if (! MainWindow::instance->isGroup(gp)) continue;
        for (long gpi = 0; gpi < variants.groups[gp].size(); gpi++) {
            QRect r(2, top+sn*sample_height, label_offset-5, sample_height-1);
            painter.drawText(r, Qt::AlignCenter, variants.samples[variants.groups[gp][gpi]]);
            sn++;
//qDebug() << "Paint sample: " << sn << gp << gpi << variants.groups[gp][gpi] << variants.samples[variants.groups[gp][gpi]];
        }
    }
    if (0 == sn) {
        QRect r(2, top, label_offset-5, sample_height-1);
        painter.drawText(r, Qt::AlignCenter, "No samples");
    }
    painter.setPen(Qt::lightGray);
    QRect r (2,top,label_offset-5,height-1);
    painter.drawRoundedRect(r,5,5);

//    qDebug() << "TrackVariation::paintLabel end";
}

void TrackVariation::paint(QPainter &painter) {
//    qDebug() << "TrackVariation::paint start" << range.chromosome << range.to;

    long w = range.to - range.from + 1;
    int sn = 0, indel = 0, nonCoding = 0, synonymous = 0, nonSynonymous = 0;
    foreach (QString gp, variants.groups.keys()) {
        if (! MainWindow::instance->isGroup(gp)) continue;
        for (long gpi = 0; gpi < variants.groups[gp].size(); gpi++) {
            long st = top + sn * sample_height;
            long last_x = -1;
            double s = 1.0 * width / w;
            last_paint_start = last_paint_end = -1;
            for (long i = 0; i < variants.data[range.chromosome].size(); i++) {
                VariationPosition *v = variants.data[range.chromosome][i];
                VariationData gt = v->data[variants.groups[gp][gpi]];
                v->painted = false;
                if (v->position > range.to) break; // Assuming VCF file was sorted by position...
                if (v->position < range.from) continue;
                if (v->quality < range.quality) continue;
                if (gt.readDepth < range.readDepth) continue;
                if (gt.coding == 0 && ! MainWindow::instance->isNonCoding()) continue;
                if (gt.deletion && ! MainWindow::instance->isIndel()) continue;
                if (gt.insertion && ! MainWindow::instance->isIndel()) continue;
                if (gt.synonymous && ! MainWindow::instance->isSynonymous()) continue;
                if (gt.nonSynonymous && ! MainWindow::instance->isNonSynonymous()) continue;

                long x1 = (v->position - range.from) * s;
                long x2 = (v->position - range.from + 1) * s - 1;
                if (x2 < x1) x2 = x1;
                if (x1 == x2 && x1 == last_x) continue; // Skip instead of overpainting...

                if (last_paint_start == -1) last_paint_start = i;
                last_paint_end = i;
                if (gt.insertion || gt.deletion) {
                    if (paintArea (v, painter, x1, st, x2, 0, 100, QColor(MainWindow::instance->colors[4]))) last_x = x1;
                } else if (-1 == gt.haplotype1 && -1 == gt.haplotype2) {
                    if (paintArea (v, painter, x1, st, x2, 0, 100, QColor(MainWindow::instance->colors[5]))) last_x = x1;
                } else if (0 == gt.haplotype1 && 0 == gt.haplotype2) {
                    if (paintArea (v, painter, x1, st, x2, 0, 100, QColor(MainWindow::instance->colors[0]))) last_x = x1;
                } else if (1 == gt.haplotype1 && 1 == gt.haplotype2) {
                    if (paintArea (v, painter, x1, st, x2, 0, 100, QColor(MainWindow::instance->colors[3]))) last_x = x1;
                } else if (1 == gt.haplotype1 && 0 == gt.haplotype2) {
                    if (paintArea (v, painter, x1, st, x2, 0, 100, QColor(MainWindow::instance->colors[1]))) last_x = x1;
                } else if (0 == gt.haplotype1 && 1 == gt.haplotype2) {
                    if (paintArea (v, painter, x1, st, x2, 0, 100, QColor(MainWindow::instance->colors[2]))) last_x = x1;
                } else { // Dunno
                    if (paintArea (v, painter, x1, st, x2, 0, 100, QColor(MainWindow::instance->colors[4]))) last_x = x1;
                }
                if (gt.insertion || gt.insertion) indel++;
                if (0 == gt.coding) nonCoding++;
                if (gt.synonymous) synonymous++;
                if (gt.nonSynonymous) nonSynonymous++;
            }
            if (sn > 0) {
                painter.setPen(Qt::lightGray);
                painter.drawLine(label_offset,st,label_offset+width,st);
            }
//  Work this out
//qDebug() << "Paint variants: " << sn << gp << gpi << variants.groups[gp][gpi] << variants.samples[variants.groups[gp][gpi]];
            variants.sample_r[variants.groups[gp][gpi]] = QRect(label_offset, st, width, sample_height);
            sn++;
        }
    }

    painter.setPen(Qt::lightGray);
    painter.setBrush(Qt::NoBrush);
    painter.drawRoundedRect(QRect(label_offset,top,width-1,height-1),5,5);

    MainWindow::instance->updateCounts(nonCoding, nonSynonymous, synonymous, indel);

//    qDebug() << "TrackVariation::paint end";
}

bool TrackVariation::paintArea (VariationPosition *v, QPainter &painter, long x1, long y, long x2, int f, int t, const QColor &color) {
    bool ret = false;
    painter.setPen(color);
    painter.setBrush(color);
    int w = x2 - x1;
    if (w < 0) w = 0;
    QRect r(label_offset + x1, y + f*sample_height/100, w, (t-f)*sample_height/100 - 1);
    if (w == 0) {
        painter.drawLine(r.topLeft(),r.bottomLeft());
        ret = true;
    } else {
        painter.drawRect(r);
    }
    v->painted = true;
    v->r = r;

    return ret;
}

void TrackVariation::recalculateLayout() {
//    qDebug() << "TrackVariation::recalculateLayout";
    int g = 0;
    foreach (QString gp, variants.groups.keys()) {
        if (! MainWindow::instance->isGroup(gp)) continue;
        g += variants.groups[gp].size();
    }
    if (0 == g) g = 1;
    height = g * sample_height;
}

void TrackVariation::mouseEvent(QMouseEvent *event,QString region,bool doubleclick) {
    Q_UNUSED(doubleclick)
//    qDebug() << "TrackVariation::mouseEvent start";
    QString html;
    bool nosticky = false;
    if (region == "content") {
        QString html_sample, html_var;

        // Find sample
        int sn = -1, sni = 0;
        for (QMap <int,QRect>::iterator s = variants.sample_r.begin(); s != variants.sample_r.end(); s++, sni++) {
            if (!s.value().contains(event->pos())) continue;
            sn = sni;
            html_sample = "<h2>" + variants.samples[sni] + "</h2>";
            break;
        }
        // Find variation
        for (long i = last_paint_start; i >= 0 && i <= last_paint_end; i++) {
            VariationPosition *v = variants.data[range.chromosome][i];
            if (!v->painted) continue;
            QRect r = v->r;
            int x = event->pos().x();
            if (x < r.left() || x > r.right()+1) continue;

            html_var = v->getDescription();
            if (sn >= 0) {
                html_sample += "<table width='100%' style='font-size:7pt'><tr><th align='left' width='50%'>Call</th><td width='50%'>";
                if (-1 == v->data[sn].haplotype1) {
                    html_sample += "Missing";
                } else {
                    html_sample += QString::number(v->data[sn].haplotype1);
                    html_sample += v->data[sn].phased ? "|" : "/";
                    html_sample += QString::number(v->data[sn].haplotype2);
                    html_sample += "</td></tr></table>";
                }
            }

            break;
        }

        if (html_var.isEmpty()) html = html_sample;
        else if (html_sample.isEmpty()) html = html_var;
        else html = html_sample + "<hr/>" + html_var;

        doTheDrag (event);
        if (area->dragging && html_var.isEmpty()) nosticky = true;
    }

    if (Qt::LeftButton == event->button()) MainWindow::instance->stickyProps(false);
    MainWindow::instance->showProps(html);
    if (Qt::LeftButton == event->button() && !nosticky) MainWindow::instance->stickyProps(true);
//    qDebug() << "TrackVariation::mouseEvent end";
}
