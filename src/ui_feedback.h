/********************************************************************************
** Form generated from reading UI file 'feedback.ui'
**
** Created: Wed 10. Oct 09:59:18 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEEDBACK_H
#define UI_FEEDBACK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Feedback
{
public:
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QDialog *Feedback)
    {
        if (Feedback->objectName().isEmpty())
            Feedback->setObjectName(QString::fromUtf8("Feedback"));
        Feedback->setWindowModality(Qt::ApplicationModal);
        Feedback->resize(240, 100);
        Feedback->setContextMenuPolicy(Qt::NoContextMenu);
        Feedback->setModal(true);
        label_1 = new QLabel(Feedback);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(20, 10, 70, 13));
        QFont font;
        font.setPointSize(9);
        label_1->setFont(font);
        label_2 = new QLabel(Feedback);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 30, 70, 13));
        label_2->setFont(font);
        label_3 = new QLabel(Feedback);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 50, 70, 13));
        label_3->setFont(font);
        label_4 = new QLabel(Feedback);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 70, 70, 13));
        label_4->setFont(font);
        label_5 = new QLabel(Feedback);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 10, 120, 13));
        label_5->setFont(font);
        label_6 = new QLabel(Feedback);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(100, 30, 120, 13));
        label_6->setFont(font);
        label_7 = new QLabel(Feedback);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(100, 50, 120, 13));
        label_7->setFont(font);
        label_8 = new QLabel(Feedback);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(100, 70, 120, 13));
        label_8->setFont(font);

        retranslateUi(Feedback);

        QMetaObject::connectSlotsByName(Feedback);
    } // setupUi

    void retranslateUi(QDialog *Feedback)
    {
        Feedback->setWindowTitle(QApplication::translate("Feedback", "Varb: Loading Data...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_1->setToolTip(QApplication::translate("Feedback", "The number of sequences/chromosomes processed", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_1->setText(QApplication::translate("Feedback", "Sequence", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("Feedback", "The number of annotations/genes/coding regions processed", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("Feedback", "Annotation", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QApplication::translate("Feedback", "The number of variants/genotype records processed", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("Feedback", "Variation", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_4->setToolTip(QApplication::translate("Feedback", "The number of statistics processed", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("Feedback", "Statistics", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_5->setToolTip(QApplication::translate("Feedback", "The number of sequences/chromosomes processed", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_5->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_6->setToolTip(QApplication::translate("Feedback", "The number of annotations/genes/coding regions processed", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_6->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_7->setToolTip(QApplication::translate("Feedback", "The number of variants/genotype records processed", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_7->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_8->setToolTip(QApplication::translate("Feedback", "The number of statistics processed", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Feedback: public Ui_Feedback {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEEDBACK_H
