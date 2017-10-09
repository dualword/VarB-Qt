/********************************************************************************
** Form generated from reading UI file 'sourcesdialog.ui'
**
** Created: Wed 10. Oct 09:59:17 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOURCESDIALOG_H
#define UI_SOURCESDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_SourcesDialog
{
public:
    QPushButton *referenceButton;
    QPushButton *annoButton;
    QPushButton *varButton;
    QLabel *titleLabel;
    QLineEdit *referenceLine;
    QLineEdit *annoLine;
    QLineEdit *varLine;
    QLabel *referenceLabel;
    QLabel *annoLabel;
    QLabel *varLabel;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *filterLabel;
    QLineEdit *filterLine;
    QTableWidget *chromosomeData;
    QPushButton *infoButton;

    void setupUi(QDialog *SourcesDialog)
    {
        if (SourcesDialog->objectName().isEmpty())
            SourcesDialog->setObjectName(QString::fromUtf8("SourcesDialog"));
        SourcesDialog->resize(500, 356);
        referenceButton = new QPushButton(SourcesDialog);
        referenceButton->setObjectName(QString::fromUtf8("referenceButton"));
        referenceButton->setGeometry(QRect(430, 30, 60, 23));
        QFont font;
        font.setPointSize(9);
        referenceButton->setFont(font);
        annoButton = new QPushButton(SourcesDialog);
        annoButton->setObjectName(QString::fromUtf8("annoButton"));
        annoButton->setGeometry(QRect(430, 53, 60, 23));
        annoButton->setFont(font);
        varButton = new QPushButton(SourcesDialog);
        varButton->setObjectName(QString::fromUtf8("varButton"));
        varButton->setGeometry(QRect(430, 76, 60, 23));
        varButton->setFont(font);
        titleLabel = new QLabel(SourcesDialog);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(0, 5, 500, 20));
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);
        referenceLine = new QLineEdit(SourcesDialog);
        referenceLine->setObjectName(QString::fromUtf8("referenceLine"));
        referenceLine->setGeometry(QRect(120, 30, 300, 20));
        referenceLine->setFont(font);
        annoLine = new QLineEdit(SourcesDialog);
        annoLine->setObjectName(QString::fromUtf8("annoLine"));
        annoLine->setGeometry(QRect(120, 53, 300, 20));
        annoLine->setFont(font);
        varLine = new QLineEdit(SourcesDialog);
        varLine->setObjectName(QString::fromUtf8("varLine"));
        varLine->setGeometry(QRect(120, 76, 300, 20));
        varLine->setFont(font);
        referenceLabel = new QLabel(SourcesDialog);
        referenceLabel->setObjectName(QString::fromUtf8("referenceLabel"));
        referenceLabel->setGeometry(QRect(10, 30, 100, 20));
        referenceLabel->setFont(font);
        annoLabel = new QLabel(SourcesDialog);
        annoLabel->setObjectName(QString::fromUtf8("annoLabel"));
        annoLabel->setGeometry(QRect(10, 53, 100, 20));
        annoLabel->setFont(font);
        varLabel = new QLabel(SourcesDialog);
        varLabel->setObjectName(QString::fromUtf8("varLabel"));
        varLabel->setGeometry(QRect(10, 76, 100, 20));
        varLabel->setFont(font);
        okButton = new QPushButton(SourcesDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(370, 100, 60, 23));
        okButton->setFont(font);
        cancelButton = new QPushButton(SourcesDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(430, 100, 60, 23));
        cancelButton->setFont(font);
        filterLabel = new QLabel(SourcesDialog);
        filterLabel->setObjectName(QString::fromUtf8("filterLabel"));
        filterLabel->setGeometry(QRect(10, 99, 105, 20));
        filterLabel->setFont(font);
        filterLine = new QLineEdit(SourcesDialog);
        filterLine->setObjectName(QString::fromUtf8("filterLine"));
        filterLine->setGeometry(QRect(120, 99, 100, 20));
        filterLine->setFont(font);
        chromosomeData = new QTableWidget(SourcesDialog);
        chromosomeData->setObjectName(QString::fromUtf8("chromosomeData"));
        chromosomeData->setGeometry(QRect(10, 129, 480, 217));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chromosomeData->sizePolicy().hasHeightForWidth());
        chromosomeData->setSizePolicy(sizePolicy);
        chromosomeData->setBaseSize(QSize(120, 20));
        chromosomeData->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        chromosomeData->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        chromosomeData->setCornerButtonEnabled(false);
        chromosomeData->horizontalHeader()->setVisible(false);
        chromosomeData->verticalHeader()->setVisible(false);
        infoButton = new QPushButton(SourcesDialog);
        infoButton->setObjectName(QString::fromUtf8("infoButton"));
        infoButton->setGeometry(QRect(310, 100, 60, 23));
        infoButton->setFont(font);
        referenceButton->raise();
        annoButton->raise();
        varButton->raise();
        titleLabel->raise();
        referenceLine->raise();
        annoLine->raise();
        varLine->raise();
        referenceLabel->raise();
        annoLabel->raise();
        varLabel->raise();
        cancelButton->raise();
        okButton->raise();
        filterLabel->raise();
        filterLine->raise();
        chromosomeData->raise();
        infoButton->raise();
        QWidget::setTabOrder(referenceLine, referenceButton);
        QWidget::setTabOrder(referenceButton, annoLine);
        QWidget::setTabOrder(annoLine, annoButton);
        QWidget::setTabOrder(annoButton, varLine);
        QWidget::setTabOrder(varLine, varButton);
        QWidget::setTabOrder(varButton, filterLine);
        QWidget::setTabOrder(filterLine, infoButton);
        QWidget::setTabOrder(infoButton, okButton);
        QWidget::setTabOrder(okButton, cancelButton);
        QWidget::setTabOrder(cancelButton, chromosomeData);

        retranslateUi(SourcesDialog);

        QMetaObject::connectSlotsByName(SourcesDialog);
    } // setupUi

    void retranslateUi(QDialog *SourcesDialog)
    {
        SourcesDialog->setWindowTitle(QApplication::translate("SourcesDialog", "VarB: Load", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        referenceButton->setToolTip(QApplication::translate("SourcesDialog", "Select a FASTA file to load", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        referenceButton->setText(QApplication::translate("SourcesDialog", "Local file", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        annoButton->setToolTip(QApplication::translate("SourcesDialog", "Select a GFF file to load", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        annoButton->setText(QApplication::translate("SourcesDialog", "Local file", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        varButton->setToolTip(QApplication::translate("SourcesDialog", "Select a VCF file to load", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        varButton->setText(QApplication::translate("SourcesDialog", "Local file", 0, QApplication::UnicodeUTF8));
        titleLabel->setText(QApplication::translate("SourcesDialog", "Give a local file or an URL", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        referenceLine->setToolTip(QApplication::translate("SourcesDialog", "Select a FASTA file to load", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        annoLine->setToolTip(QApplication::translate("SourcesDialog", "Select a GFF file to load", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        varLine->setToolTip(QApplication::translate("SourcesDialog", "Select a VCF file to load", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        referenceLabel->setToolTip(QApplication::translate("SourcesDialog", "Select a FASTA file to load", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        referenceLabel->setText(QApplication::translate("SourcesDialog", "Reference (fasta)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        annoLabel->setToolTip(QApplication::translate("SourcesDialog", "Select a GFF file to load", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        annoLabel->setText(QApplication::translate("SourcesDialog", "Annotation (gff)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        varLabel->setToolTip(QApplication::translate("SourcesDialog", "Select a VCF file to load", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        varLabel->setText(QApplication::translate("SourcesDialog", "Variation (vcf)", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("SourcesDialog", "Load", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("SourcesDialog", "Cancel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        filterLabel->setToolTip(QApplication::translate("SourcesDialog", "Filter the input files by chromosome for speed", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        filterLabel->setText(QApplication::translate("SourcesDialog", "Chromosome Filter", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        filterLine->setToolTip(QApplication::translate("SourcesDialog", "Filter the input files by chromosome for speed", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        infoButton->setText(QApplication::translate("SourcesDialog", "Check", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SourcesDialog: public Ui_SourcesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOURCESDIALOG_H
