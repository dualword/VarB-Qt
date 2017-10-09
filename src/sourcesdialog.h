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
#ifndef SOURCESDIALOG_H
#define SOURCESDIALOG_H

#include <QDialog>

namespace Ui {
    class SourcesDialog;
}

class SourcesDialog : public QDialog {
    Q_OBJECT

public:
    explicit SourcesDialog(QWidget *parent = 0);
    ~SourcesDialog();
    void initialise(QString seq, QString anno, QString var, QString filter);
    void update(QString psFileType, QMap<QString,int>& paCounts);
    void update(QString psFileType, QString psType, int piCount);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::SourcesDialog *ui;

private slots:
    void on_varButton_clicked();
    void on_annoButton_clicked();
    void on_infoButton_clicked();
    void on_referenceButton_clicked();
    void on_okButton_clicked();
    void on_cancelButton_clicked();
};

#endif // SOURCESDIALOG_H
