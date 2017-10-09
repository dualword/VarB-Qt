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
#include "groupmanager.h"
#include "ui_groupmanager.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringListModel>
#include <QDebug>

GroupManager::GroupManager(QWidget *parent) : QDialog(parent), ui(new Ui::GroupManager) {
    qDebug() << "GroupManager::GroupManager";
    ui->setupUi(this);
    group = "";
    area = ((MainWindow*)parent)->getUI()->tracks;
    var = area->getVariation();
    updateLists();
    setWindowTitle("Manage groups");
    setTabOrder(ui->newGroupLine,ui->addGroupButton);
    setTabOrder(ui->addGroupButton,ui->groupCombo);
}

GroupManager::~GroupManager() {
    delete ui;
}

void GroupManager::updateLists() {
    qDebug() << "GroupManager::updateLists";
    bool isGroups = true;
    if (var && 0 == ui->groupCombo->count()) {
        foreach (QString gp, var->groups.keys()) {
            if ("Ungrouped" != gp) ui->groupCombo->addItem(gp);
            if (group == gp) ui->groupCombo->setCurrentIndex(ui->groupCombo->count() - 1);
        }
    }
    isGroups = (0 != ui->groupCombo->count());
    ui->groupCombo->setEnabled(isGroups);
    ui->groupList->setEnabled(isGroups);
    ui->addSelectedButton->setEnabled(isGroups);
    ui->removeSelectedButton->setEnabled(isGroups);
    ui->removeAllButton->setEnabled(isGroups);
    ui->groupList->clear();
    ui->ungroupedList->clear();
    if (var) {
        if (var->groups.contains(group)) {
            foreach (int i, var->groups[group]) {
                ui->groupList->addItem(var->samples[i]);
            }
        }
        foreach (int i, var->groups["Ungrouped"]) {
            ui->ungroupedList->addItem(var->samples[i]);
        }
    }
}

void GroupManager::on_addGroupButton_clicked() {
    qDebug() << "GroupManager::on_addGroupButton_clicked";
    QString gp = ui->newGroupLine->text();
    qDebug() << gp << " " << group;
    if (var && ! var->groups.contains(gp)) {
        group = gp;
        var->groups[group];
        ui->groupCombo->addItem(group);
        ui->groupCombo->setCurrentIndex(ui->groupCombo->count() - 1);
        MainWindow::instance->addGroup(group);
    }
}

void GroupManager::on_groupCombo_currentIndexChanged(const QString &g) {
    qDebug() << "GroupManager::on_groupCombo_currentIndexChanged " << group << " " << g;
    if ("" != g && group != g) group = g;
    updateLists();
}

void GroupManager::on_removeSelectedButton_clicked() {
    qDebug() << "GroupManager::on_removeSelectedButton_clicked";
    QList<QListWidgetItem*> selected = ui->groupList->selectedItems();
    if (var && var->groups.contains(group)) {
        foreach (QListWidgetItem* i, selected) {
            int index = var->samples.indexOf(i->text());
            if (-1 != index) {
               var->groups["Ungrouped"].append(index);
               var->groups[group].removeOne(index);
            }
        }
        updateLists();
    }
}

void GroupManager::on_removeAllButton_clicked() {
    qDebug() << "GroupManager::on_removeAllButton_clicked";
    if (var && var->groups.contains(group)) {
        QListWidgetItem* i = ui->groupList->takeItem(0);
        while (0 != i) {
            int index = var->samples.indexOf(i->text());
            if (-1 != index) {
               var->groups["Ungrouped"].append(index);
               var->groups[group].removeOne(index);
            }
            i = ui->groupList->takeItem(0);
        }
        updateLists();
    }
}

void GroupManager::on_addSelectedButton_clicked() {
    qDebug() << "GroupManager::on_addSelectedButton_clicked";
    QList<QListWidgetItem*> selected = ui->ungroupedList->selectedItems();
    if (var && var->groups.contains(group)) {
        foreach (QListWidgetItem* i, selected) {
            int index = var->samples.indexOf(i->text());
            if (-1 != index) {
               var->groups["Ungrouped"].removeOne(index);
               var->groups[group].append(index);
            }
        }
        updateLists();
    }
}

void GroupManager::on_doneButton_clicked() {
    qDebug() << "GroupManager::on_doneButton_clicked";
    area->changeGroups();
    close();
}
