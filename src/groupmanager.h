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
#ifndef GROUPMANAGER_H
#define GROUPMANAGER_H

#include <QDialog>
#include "trackcontainer.h"
#include "variation.h"

namespace Ui {
    class GroupManager;
}

class GroupManager : public QDialog {
    Q_OBJECT
    
public:
    explicit GroupManager(QWidget *parent = 0);
    ~GroupManager();
    
private slots:
    void on_addGroupButton_clicked();
    void on_groupCombo_currentIndexChanged(const QString &arg1);
    void on_removeSelectedButton_clicked();
    void on_removeAllButton_clicked();
    void on_addSelectedButton_clicked();
    void on_doneButton_clicked();

//    void on_groupCombo_currentIndexChanged(int index);

private:
    Ui::GroupManager *ui;
    TrackContainer *area;
    Variation *var;
    QString group;

    void updateLists();
};

#endif // GROUPMANAGER_H
