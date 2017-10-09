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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStatusBar>
#include <QList>
#include <QWebView>
#include <QCheckBox>
#include <QSignalMapper>
#include <QtGui>
#include "feedback.h"
#include "log.h"
#include "track.h"
#include "tracksequence.h"
#include "trackannotation.h"
#include "trackvariation.h"
#include "trackgraph.h"

class SearchResult;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Ui::MainWindow* getUI () { return ui; }
    void setRange (QString chr, long from, long to, long padding = 0);
    void loadData(QString s, QString a, QString v, QString f);
    void updateCounts(int nonCoding, int nonSynonymous, int synonymous, int indel);
    void updateLegend();

    static MainWindow* instance;
    static void outOfMemory(QString msg);
    void showProps (QString s);
    void stickyProps (bool sticky);
    bool isNonCoding();
    bool isSynonymous();
    bool isNonSynonymous();
    bool isIndel();
    bool isGroup(QString group);
    void addGroup(QString group);
    void keyPressEvent(QKeyEvent *key);
    Feedback feedback;
    QString colors[6];

protected:
    void changeEvent(QEvent *e);
    QList <SearchResult*> results;
    bool adjusting;

private:
    void setMacUp();
    Ui::MainWindow *ui;
    int visible_range;
    QString last_props;
    bool props_are_sticky, loading;
    QMap<QString, QCheckBox*> groups;

private slots:
//    void on_props_linkClicked(const QUrl &);
    void on_chrBox_textChanged(QString);
    void on_chrBox_currentIndexChanged(QString);
    void on_rsdButton_clicked();
    void on_lineTo_returnPressed();
    void on_lineFrom_returnPressed();
    void on_goButton_clicked();
    void on_findResults_currentRowChanged(int currentRow);
    void on_findClearButton_clicked();
    void on_findButton_clicked();
    void on_findQuery_returnPressed();
    void on_zoomSlider_valueChanged(int value);
    void on_positionSlider_valueChanged(int value);
    void on_loadButton_clicked();
    void on_saveButton_clicked();
    void on_settingsButton_clicked();
    void on_qualitySlider_valueChanged(int value);
    void on_readDepthSlider_valueChanged(int value);
    void on_browserSizeSlider_valueChanged(int value);
    void on_indelCheckBox_clicked();
    void on_synonymousCheckBox_clicked();
    void on_nonSynonymousCheckBox_clicked();
    void on_manageGroupsButton_clicked();
    void on_ungroupedCheck_clicked();
    void on_nonCodingCheckBox_clicked();
    void on_lineQuality_editingFinished();
    void on_lineDepth_editingFinished();
    void on_lineSize_editingFinished();
    void on_aboutButton_clicked();
    void on_colorButton_clicked();
    void on_positionLeftButton_clicked();
    void on_positionRightButton_clicked();
    void on_logButton_clicked();
};

#endif // MAINWINDOW_H
