/********************************************************************************
** Form generated from reading UI file 'colors.ui'
**
** Created: Wed 10. Oct 09:59:18 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORS_H
#define UI_COLORS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Colors
{
public:
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QComboBox *comboBox_1;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QComboBox *comboBox_5;
    QComboBox *comboBox_6;

    void setupUi(QDialog *Colors)
    {
        if (Colors->objectName().isEmpty())
            Colors->setObjectName(QString::fromUtf8("Colors"));
        Colors->resize(168, 190);
        label_1 = new QLabel(Colors);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(10, 12, 50, 13));
        label_2 = new QLabel(Colors);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 37, 50, 13));
        label_3 = new QLabel(Colors);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 62, 50, 13));
        label_4 = new QLabel(Colors);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 87, 50, 13));
        label_5 = new QLabel(Colors);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 112, 50, 13));
        label_6 = new QLabel(Colors);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 135, 50, 17));
        pushButton = new QPushButton(Colors);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 160, 70, 23));
        comboBox_1 = new QComboBox(Colors);
        comboBox_1->setObjectName(QString::fromUtf8("comboBox_1"));
        comboBox_1->setGeometry(QRect(60, 7, 100, 22));
        comboBox_2 = new QComboBox(Colors);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(60, 32, 100, 22));
        comboBox_3 = new QComboBox(Colors);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(60, 57, 100, 22));
        comboBox_4 = new QComboBox(Colors);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(60, 82, 100, 22));
        comboBox_5 = new QComboBox(Colors);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(60, 107, 100, 22));
        comboBox_6 = new QComboBox(Colors);
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));
        comboBox_6->setGeometry(QRect(60, 132, 100, 22));

        retranslateUi(Colors);

        QMetaObject::connectSlotsByName(Colors);
    } // setupUi

    void retranslateUi(QDialog *Colors)
    {
        Colors->setWindowTitle(QApplication::translate("Colors", "VarB: Colours", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_1->setToolTip(QApplication::translate("Colors", "Choose the colour for the wildtype variants", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_1->setText(QApplication::translate("Colors", "00", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("Colors", "Choose the colour for the hetrozygous variants", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("Colors", "01", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QApplication::translate("Colors", "Choose the colour for the hetrozygous variants", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("Colors", "10", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_4->setToolTip(QApplication::translate("Colors", "Choose the colour for the homozygous variants", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("Colors", "11", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_5->setToolTip(QApplication::translate("Colors", "Choose the colour for the insertions and deletions", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("Colors", "Indel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_6->setToolTip(QApplication::translate("Colors", "Choose the colour for the missing data", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("Colors", "Missing", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Colors", "Ok", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        comboBox_1->setToolTip(QApplication::translate("Colors", "Choose the colour for the wildtype variants", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        comboBox_2->setToolTip(QApplication::translate("Colors", "Choose the colour for the hetrozygous variants", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        comboBox_3->setToolTip(QApplication::translate("Colors", "Choose the colour for the hetrozygous variants", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        comboBox_4->setToolTip(QApplication::translate("Colors", "Choose the colour for the homozygous variants", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        comboBox_5->setToolTip(QApplication::translate("Colors", "Choose the colour for the insertions and deletions", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        comboBox_6->setToolTip(QApplication::translate("Colors", "Choose the colour for the missing data", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class Colors: public Ui_Colors {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORS_H
