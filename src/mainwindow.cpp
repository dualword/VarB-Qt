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
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "searchresult.h"
#include "annotation.h"
#include "colors.h"
#include "groupmanager.h"
#include "save.h"
#include "sourcesdialog.h"
#include "trackgraph.h"
#include "trackgraphgc.h"
#include "trackgraphvd.h"
#include "trackgraphfst.h"
#include "trackgraphtd.h"
#include <QDebug>
#include <QMessageBox>
#include <QCheckBox>
#include <QDir>
#include <QList>
#include <QTextStream>

QPointer<Log> logBrowser;

void logOutput(QtMsgType type, const char *msg) {
    if (logBrowser) logBrowser->outputMessage(type, msg);
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    logBrowser = new Log;
    qInstallMsgHandler(logOutput);

    visible_range = 200;
    props_are_sticky = false;
    adjusting = false;
    instance = this;
    ui->setupUi(this);
    ui->findResults->hide();
    ui->rsdButton->hide();
    ui->zoomSlider->setRange(1,1);
    ui->lineSize->setText("20");
    ui->browserBox->setEnabled(false);
    groups["Ungrouped"] = ui->ungroupedCheck;
    showMaximized();
    setMacUp();
//    connect(ui->props,SIGNAL(linkClicked(const QUrl&)),this,SLOT(on_props_linkClicked(const QUrl&)),Qt::DirectConnection);
    QFile file("colors.pv");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream fin(&file);
        colors[0] = fin.readLine();
        colors[1] = fin.readLine();
        colors[2] = fin.readLine();
        colors[3] = fin.readLine();
        colors[4] = fin.readLine();
        colors[5] = fin.readLine();
        file.close();
    } else {
        colors[0] = "darkblue";
        colors[1] = "green";
        colors[2] = "yellow";
        colors[3] = "red";
        colors[4] = "black";
        colors[5] = "lightgray";
    }
    updateLegend();
    updateCounts(0,0,0,0);
}

MainWindow::~MainWindow() {
    delete ui;
}
void MainWindow::setMacUp() {
    ui->aboutButton->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->loadButton->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->saveButton->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->manageGroupsButton->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->colorButton->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->findButton->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->findClearButton->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->rsdButton->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->settingsButton->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->positionRightButton->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->positionLeftButton->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->goButton->setAttribute(Qt::WA_LayoutUsesWidgetRect);

    ui->nonCodingCheckBox->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->synonymousCheckBox->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->nonSynonymousCheckBox->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->indelCheckBox->setAttribute(Qt::WA_LayoutUsesWidgetRect);

    ui->chrBox->setAttribute(Qt::WA_LayoutUsesWidgetRect);

    ui->lineFrom->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->lineTo->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->lineSize->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->lineQuality->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->lineDepth->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->findQuery->setAttribute(Qt::WA_LayoutUsesWidgetRect);

    ui->positionSlider->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->browserSizeSlider->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->qualitySlider->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->readDepthSlider->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    ui->zoomSlider->setAttribute(Qt::WA_LayoutUsesWidgetRect);

    ui->readDepthLabel->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    /*
    QFrame *groupsWidget;
    QCheckBox *ungroupedCheck;
    QListWidget *findResults;
    QWebView *props;
    QStatusBar *statusBar;
    QListWidget *findResults;

    QLabel *label_4;
    QLabel *label;
    QLabel *linkLabel;
    QLabel *positionLabel;
    QLabel *zoomLabel;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *labelLegend;
    QLabel *label_6;
    QLabel *browserSizelabel;
    QLabel *qualityLabel;
    QLabel *readDepthLabel;
    QLabel *label_3;
    QLabel *nonCodingLabel;
    QLabel *synonymousLabel;
    QLabel *nonSynonymousLabel;
    QLabel *indelLabel;
    QLabel *label_2;
    */
}

void MainWindow::keyPressEvent(QKeyEvent* key) {
    if (Qt::ControlModifier == key->modifiers()) {
        switch (key->key()) {
        case Qt::Key_C: on_colorButton_clicked(); break;
        case Qt::Key_G: on_manageGroupsButton_clicked(); break;
        case Qt::Key_H: on_aboutButton_clicked(); break;
        case Qt::Key_L: on_loadButton_clicked(); break;
        case Qt::Key_S: on_saveButton_clicked(); break;
        }
    }
}

void MainWindow::outOfMemory(QString msg) {
    QMessageBox msgBox;
    msgBox.setText("Out of memory - program exiting: " + msg);
    msgBox.exec();
    exit(-1);
}

bool MainWindow::isNonCoding() {
    return ui->nonCodingCheckBox->isChecked();
}

bool MainWindow::isSynonymous() {
    return ui->synonymousCheckBox->isChecked();
}

bool MainWindow::isNonSynonymous() {
    return ui->nonSynonymousCheckBox->isChecked();
}

bool MainWindow::isIndel() {
    return ui->indelCheckBox->isChecked();
}

bool MainWindow::isGroup(QString group) {
    if (groups.contains(group)) return groups[group]->isChecked();
    return false;
}

void MainWindow::updateCounts(int nonCoding, int nonSynonymous, int synonymous, int indel) {
    ui->nonCodingLabel->setText(QString::number(nonCoding));
    ui->nonSynonymousLabel->setText(QString::number(nonSynonymous));
    ui->synonymousLabel->setText(QString::number(synonymous));
    ui->indelLabel->setText(QString::number(indel));
}

void MainWindow::updateLegend() {
    ui->labelLegend->setText("<font color='" + colors[0] + "'>00</font> - <font color='" + colors[1] + "'>10</font> - <font color='" + colors[2] + "'>01</font> - <font color='" + colors[3] + "'>11</font> - <font color='" + colors[4] + "'>Indel</font> - <font color='" + colors[5] + "'>Missing</font>");
}

void MainWindow::on_loadButton_clicked() {
    SourcesDialog sd(this);
    QString seq = "", anno = "", var = "", filter = "";
    QFile file("last.pv");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream fin(&file);
        seq = fin.readLine();
        anno = fin.readLine();
        var = fin.readLine();
        filter = fin.readLine();
        file.close();
    }

    for (int a = 0; a < ui->tracks->tracklist.size(); a++) {
        Track *t = ui->tracks->tracklist[a];
        if (t->whatsthis() == "sequence") seq = ((TrackSequence*)t)->seq.source_file;
        if (t->whatsthis() == "annotation") anno = ((TrackAnnotation*)t)->data.source_file;
        if (t->whatsthis() == "variation") var = ((TrackVariation*)t)->variants.source_file;
        if (t->whatsthis() == "variation") filter = ((TrackVariation*)t)->variants.filter;
    }

    sd.initialise(seq,anno,var,filter);
    sd.setModal(true);
    sd.exec();
}

void MainWindow::loadData(QString s, QString a, QString v, QString f) {
//    qDebug() << "MainWindow::loadData start";
    ui->statusBar->showMessage("Loading data...");
    loading = true;
    feedback.initialise(0);
    ui->settingsBox->setEnabled(false);
    ui->browserBox->setEnabled(false);

    groups.clear();
    groups["Ungrouped"] = ui->ungroupedCheck;
    ui->groupsWidget->setMinimumHeight(21 * groups.count());
    ui->tracks->tracklist.clear();

    TrackSequence *seq = new TrackSequence(this);
    TrackAnnotation *ann = new TrackAnnotation(this);
    TrackVariation *var = new TrackVariation(this);
    TrackGraphGC *gcGraph = new TrackGraphGC(this);
    TrackGraphVD *vdGraph = new TrackGraphVD(this);
    TrackGraphFST *fstGraph = new TrackGraphFST(this);
    TrackGraphTD *tdGraph = new TrackGraphTD(this);

    ui->statusBar->showMessage("Loading sequence data...");
    if (! seq->seq.loadFASTA(s, f)) {
        QMessageBox msgBox;
        msgBox.setText("No data after filtering on " + f + "\n" + "or\n" + "Bad sequence file: " + s);
        msgBox.exec();
//        loading = false;
//        ui->statusBar->clearMessage();
//        ui->settingsBox->setEnabled(true);
//        feedback.clear();
//        return;
    }

    ui->statusBar->showMessage("Loading annotation data...");
    if (! ann->data.loadGFF3(a, &seq->seq, f)) {
        QMessageBox msgBox;
        msgBox.setText("Missing annotation file: " + a);
        msgBox.exec();
//        loading = false;
//        ui->statusBar->clearMessage();
//        ui->settingsBox->setEnabled(true);
//        feedback.clear();
//        return;
    }

    ui->statusBar->showMessage("Loading variation data...");
    if (! var->variants.loadVCF(v, &seq->seq, &ann->data, f)) {
        QMessageBox msgBox;
        msgBox.setText("Missing or badly formatted variant file: " + v);
        msgBox.exec();
//        loading = false;
//        ui->statusBar->clearMessage();
//        ui->settingsBox->setEnabled(true);
//        feedback.clear();
//        return;
    }

    feedback.update(4);
    ui->tracks->tracklist.append(seq);
    ui->tracks->tracklist.append(ann);
    ui->tracks->tracklist.append(var);
    ui->tracks->tracklist.append(gcGraph);
    ui->tracks->tracklist.append(vdGraph);
    ui->tracks->tracklist.append(fstGraph);
    ui->tracks->tracklist.append(tdGraph);

    ui->statusBar->showMessage("Calculating GC density metric...");
    gcGraph->calculateData();

    ui->statusBar->showMessage("Calculating relative variant density metric...");
    vdGraph->calculateData();

    ui->statusBar->showMessage("Calculating Fst metric...");
    fstGraph->calculateData();

    ui->statusBar->showMessage("Calculating Tajima's D metric...");
    tdGraph->calculateData();

    QFile file("last.pv");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream fout(&file);
        fout << s << endl << a << endl << v << endl << f << endl;
        file.close();
    }

    ui->statusBar->showMessage("Updating UI...");
    QList <QString> chrlist;
    chrlist = seq->seq.chromosomes.keys();
    ui->chrBox->clear();
    ui->chrBox->addItems(chrlist);

    loading = false;

//    qDebug() << "MainWindow::loadData " << chrlist[0];

    on_chrBox_currentIndexChanged(chrlist[0]);
    ui->browserSizeSlider->setValue(ui->browserSizeSlider->value());
    on_findClearButton_clicked();
    stickyProps(false);
    ui->statusBar->clearMessage();
    ui->settingsBox->setEnabled(true);
    ui->browserBox->setEnabled(true);

    feedback.clear();

//    qDebug() << "MainWindow::loadData end";
}

void MainWindow::changeEvent(QEvent *e) {
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_findQuery_returnPressed() {
    on_findButton_clicked();
}

void MainWindow::on_findButton_clicked() {
    on_findClearButton_clicked();

    QString query = ui->findQuery->text();
    if (query.isEmpty()) return;

    for (int a = 0; a < ui->tracks->tracklist.size(); a++) {
        ui->tracks->tracklist[a]->runSearch(query,results);
    }

    for (int a = 0; a < results.size(); a++) {
        ui->findResults->addItem(results[a]->displayname);
    }

    ui->findResults->show();
}

void MainWindow::on_findClearButton_clicked() {
    for (int a = 0; a < results.size(); a++) delete results[a];
    results.clear();
    ui->findResults->clear();
    ui->findResults->hide();
}

void MainWindow::on_findResults_currentRowChanged(int currentRow) {
    if (currentRow == -1) return;
    SearchResult *sr = results[currentRow];
    long w = sr->to - sr->from;
    setRange(sr->chr, sr->from - w/20, sr->to + w/20);
    if (sr->annotation_item) showProps (sr->annotation_item->getDescription());
}

void MainWindow::showProps (QString s) {
    if (props_are_sticky) return;
    if (last_props == s) return;
    last_props = s;

    s.replace("<h2>","<div style='padding:1px;font-size:11pt;font-weight:bold;background-color:#A5DBEB'>");
    s.replace("</h2>","</div>");
    s = "<html><body style='font-size:11pt; font:Arial'>" + s + "</body></html>";
    ui->props->setHtml(s);
}

void MainWindow::stickyProps (bool sticky) {
    if (last_props == "") sticky = false;
    if (props_are_sticky == sticky) return; // Nothing to do
    if (sticky) {
        showProps (last_props);
        ui->rsdButton->show();
        props_are_sticky = sticky;
    } else {
        props_are_sticky = sticky;
        showProps ("");
        ui->rsdButton->hide();
    }
}

void MainWindow::on_rsdButton_clicked() {
    stickyProps(false);
}

void MainWindow::setRange (QString chr, long from, long to, long padding) {
//    qDebug() << "MainWindow::setRange start";
    adjusting = true;

    // Chromosome change, if any
    if (chr != ui->tracks->range.chromosome) {
        int idx = ui->chrBox->findText(chr,Qt::MatchExactly);
        if (idx < 0) return;
        ui->chrBox->setCurrentIndex(idx);
    }

    // Position change
    from -= padding;
    to += padding;
    if (from < 1) {
        to += -from;
        from = 1;
    }
    if (to < ui->tracks->posPerWidth()) to = ui->tracks->posPerWidth();

    Sequence *seq = ui->tracks->getSequence();
    if (seq && to > seq->chromosomes[chr].length()) to = seq->chromosomes[chr].length();

    ui->tracks->setRange(chr, from, to);
    ui->zoomSlider->setValue(to-from);
    ui->positionSlider->setValue(from);
    ui->lineFrom->setText(QString::number(from));
    ui->lineTo->setText(QString::number(to));
    ui->tracks->changeChromosome();
    ui->tracks->checkAndPaint();
    adjusting = false;
//    qDebug() << "MainWindow::setRange end";
}

void MainWindow::on_chrBox_textChanged(QString currentText) {
//    qDebug() << "MainWindow::on_chrBox_textChanged start";
    on_chrBox_currentIndexChanged(currentText);
//    qDebug() << "MainWindow::on_chrBox_textChanged start";
}

void MainWindow::on_chrBox_currentIndexChanged(QString currentText) {
//    qDebug() << "MainWindow::on_chrBox_currentIndexChanged start";
    Sequence *seq = ui->tracks->getSequence();
    Variation *var = ui->tracks->getVariation();

    if (loading) return;
    if (!seq) return;
    if (!var) return;

    adjusting = true;
    ui->tracks->delayPaint = true;
    ui->statusBar->showMessage("Changing chromosome...");

    long chrlen = seq->chromosomes[currentText].length();
    Extrema extrema = var->extrema[currentText];
    visible_range = chrlen;

    ui->tracks->setRange(currentText, 1, chrlen);
    ui->lineFrom->setText(QString::number(1));
    ui->lineTo->setText(QString::number(chrlen));
    ui->zoomSlider->setRange(100, chrlen);
    ui->zoomSlider->setValue(std::min((long)1000,chrlen));
//    ui->positionSlider->setRange(1,1);
    ui->qualitySlider->setRange(extrema.qualityMin, extrema.qualityMin < extrema.qualityMax ? extrema.qualityMax : extrema.qualityMin);
    ui->qualitySlider->setValue(extrema.qualityMin);
    ui->qualitySlider->setEnabled(ui->qualitySlider->maximum() - ui->qualitySlider->minimum() > 0);
    ui->lineQuality->setText(QString::number(ui->qualitySlider->minimum()));
    ui->lineQuality->setEnabled(ui->qualitySlider->maximum() - ui->qualitySlider->minimum() > 0);

    ui->readDepthSlider->setRange(extrema.readDepthMin, extrema.readDepthMin < extrema.readDepthMax ? extrema.readDepthMax : extrema.readDepthMin);
    ui->readDepthSlider->setValue(extrema.readDepthMin);
    ui->readDepthSlider->setEnabled(ui->readDepthSlider->maximum() - ui->readDepthSlider->minimum() > 0);
    ui->lineDepth->setText(QString::number(ui->readDepthSlider->minimum()));
    ui->lineDepth->setEnabled(ui->readDepthSlider->maximum() - ui->readDepthSlider->minimum() > 0);

    on_positionSlider_valueChanged(1);

    ui->tracks->delayPaint = false;
    ui->tracks->changeChromosome();
    ui->tracks->checkAndPaint();
    adjusting = false;

    ui->statusBar->clearMessage();

//    qDebug() << "MainWindow::on_chrBox_currentIndexChanged end";
}

void MainWindow::on_lineFrom_returnPressed() {
    on_goButton_clicked();
}

void MainWindow::on_lineTo_returnPressed() {
    on_goButton_clicked();
}

void MainWindow::on_goButton_clicked() {
    setRange(ui->tracks->range.chromosome, ui->lineFrom->text().toLong(), ui->lineTo->text().toLong());
}

void MainWindow::on_qualitySlider_valueChanged(int value) {
//    qDebug() << "MainWindow::on_qualitySlider_valueChanged";
    ui->lineQuality->setText(QString::number(value));
    ui->tracks->setQuality(value);
    ui->tracks->changeFilter();
    if (adjusting) return;
    ui->tracks->checkAndPaint();
}

void MainWindow::on_readDepthSlider_valueChanged(int value) {
//    qDebug() << "MainWindow::on_readDepthSlider_valueChanged";
    ui->lineDepth->setText(QString::number(value));
    ui->tracks->setReadDepth(value);
    ui->tracks->changeFilter();
    if (adjusting) return;
    ui->tracks->checkAndPaint();
}

void MainWindow::on_settingsButton_clicked() {
    if ("<" == ui->settingsButton->text()) {
        ui->settingsBox->hide();
        ui->settingsButton->setText(">");
        ui->settingsButton->setToolTip("Show settings");
        ui->tracks->recalculateLayout();
        ui->tracks->checkAndPaint();
    } else {
        ui->settingsBox->show();
        ui->settingsButton->setText("<");
        ui->settingsButton->setToolTip("Hide settings");
        ui->tracks->recalculateLayout();
        ui->tracks->checkAndPaint();
    }
}

void MainWindow::on_positionSlider_valueChanged(int value) {
//    qDebug() << "MainWindow::on_positionSlider_valueChanged start " << value << " " << ui->zoomSlider->value();
    ui->tracks->setRange(ui->tracks->range.chromosome, value, value + ui->zoomSlider->value() - 1);
    ui->lineFrom->setText(QString::number(value));
    ui->lineTo->setText(QString::number(value + ui->zoomSlider->value()));
    ui->tracks->changePosition();
//    qDebug() << "MainWindow::on_positionSlider_valueChanged adjusting " << adjusting;
    if (adjusting) return;
    ui->tracks->checkAndPaint();
//    qDebug() << "MainWindow::on_positionSlider_valueChanged end";
}

void MainWindow::on_zoomSlider_valueChanged(int value) {
//    qDebug() << "MainWindow::on_zoomSlider_valueChanged start";
    Q_UNUSED(value)
    Sequence *seq = ui->tracks->getSequence();
    if (!seq) return;
    visible_range = ui->zoomSlider->value();
    int max = seq->chromosomes[ui->tracks->range.chromosome].length() - visible_range + 1 ;
    ui->positionSlider->setRange(1,max);
    on_positionSlider_valueChanged(ui->positionSlider->value());
//    qDebug() << "MainWindow::on_zoomSlider_valueChanged end";
}

void MainWindow::on_browserSizeSlider_valueChanged(int value) {
//    qDebug() << "MainWindow::on_browserSlider_valueChanged";
    TrackVariation *var = (TrackVariation*) ui->tracks->getTrack("variation");
    if (var) {
        ui->lineSize->setText(QString::number(value));
        var->sample_height = value;
        ui->tracks->recalculateLayout();
        ui->tracks->checkAndPaint();
    }
}

void MainWindow::on_nonCodingCheckBox_clicked() {
    ui->tracks->changeFilter();
    ui->tracks->update();
}

void MainWindow::on_synonymousCheckBox_clicked() {
    ui->tracks->changeFilter();
    ui->tracks->update();
}

void MainWindow::on_nonSynonymousCheckBox_clicked() {
    ui->tracks->changeFilter();
    ui->tracks->update();
}

void MainWindow::on_indelCheckBox_clicked() {
    ui->tracks->changeFilter();
    ui->tracks->update();
}

void MainWindow::on_ungroupedCheck_clicked() {
    ui->tracks->recalculateLayout();
    ui->tracks->changeGroups();
    ui->tracks->update();
}

void MainWindow::on_manageGroupsButton_clicked() {
    GroupManager gm(this);
    gm.setModal(true);
    gm.exec();
}

void MainWindow::addGroup(QString group) {
    QString name = group;
    name.replace(" ", "");

    QFont font;
    font.setPointSize(9);

    QCheckBox *newCheck = new QCheckBox(ui->groupsWidget);
    newCheck->setObjectName("group" + name + "Check");
    newCheck->setGeometry(0, 21 * groups.count(), 120, 21);
    newCheck->setFont(font);
    newCheck->setText(group);
    newCheck->setChecked(true);
    newCheck->show();

    groups[group] = newCheck;
    connect(newCheck, SIGNAL(clicked()), this, SLOT(on_ungroupedCheck_clicked()));

    ui->groupsWidget->setMinimumHeight(21 * groups.count());
}

void MainWindow::on_lineQuality_editingFinished() {
    bool ok;
    int value = ui->lineQuality->text().toInt(&ok);
    if (ok) {
        ui->qualitySlider->setValue(value);
    } else {
        ui->lineQuality->setText(QString::number(ui->qualitySlider->value()));
    }
}

void MainWindow::on_lineDepth_editingFinished() {
    bool ok;
    int value = ui->lineDepth->text().toInt(&ok);
    if (ok) {
        ui->readDepthSlider->setValue(value);
    } else {
        ui->lineDepth->setText(QString::number(ui->readDepthSlider->value()));
    }
}

void MainWindow::on_lineSize_editingFinished() {
    bool ok;
    int value = ui->lineSize->text().toInt(&ok);
    if (ok) {
        ui->browserSizeSlider->setValue(value);
    } else {
        ui->lineSize->setText(QString::number(ui->browserSizeSlider->value()));
    }
}

void MainWindow::on_aboutButton_clicked() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("About Variation Browser");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText(QString("<font size='+2'>Variation Browser v1.4</font><br/><br/>") +
                   "Developed by Mark D Preston<br/>" +
                   "Created by H Magnus Manske and Mark D Preston, (c) 2012 Onwards<br/>" +
                   "Licence: GPL<br/><br/>" +
                   "Reference:<br/>" +
                   "Preston MD, Manske HM, Horner N, Assefa S, Campino S, Auburn S, Zongo I, Oudraogo JB, Nosten F, Anderson T, Clark T<br/>" +
                   "VarB: A Variation Browsing tool for polymorphisms derived from next-generation sequence data<br/>" +
                   "Bioinformatics first published online September 13, 2012 doi:10.1093/bioinformatics/bts557<br/><br/>" +
                   "Websites:<br/>" +
                   "<a href='http://www.pathogenseq.org'>pathogenseq.org</a><br/>" +
                   "<a href='http://software.markdpreston.com'>software.markdpreston.com</a><br/>" +
                   "<a href='http://code.google.com/p/varb'>code.google.com/p/varb</a><br/><br/>" +
                   "<font size='+1'>Help</font><br/>" +
                   "<a href='http://software.markdpreston.com/varb/help'>software.markdpreston.com/varb/help</a>");
    msgBox.exec();
}

void MainWindow::on_colorButton_clicked() {
    Colors c(this);
    c.setModal(true);
    c.exec();
}

void MainWindow::on_saveButton_clicked() {
    Save s(this);
    s.setModal(true);
    s.exec();
}

void MainWindow::on_positionLeftButton_clicked() {
    long from, to;
    from = ui->lineFrom->text().toLong();
    to = ui->lineTo->text().toLong();
    ui->positionSlider->setValue(2*from - to);
}

void MainWindow::on_positionRightButton_clicked() {
    ui->positionSlider->setValue(ui->lineTo->text().toLong() + 1);
}

void MainWindow::on_logButton_clicked() {
    logBrowser->show();;
}
