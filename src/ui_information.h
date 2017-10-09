/********************************************************************************
** Form generated from reading UI file 'information.ui'
**
** Created: Mon 8. Oct 09:20:03 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATION_H
#define UI_INFORMATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_information
{
public:

    void setupUi(QDialog *information)
    {
        if (information->objectName().isEmpty())
            information->setObjectName(QString::fromUtf8("information"));
        information->resize(400, 300);

        retranslateUi(information);

        QMetaObject::connectSlotsByName(information);
    } // setupUi

    void retranslateUi(QDialog *information)
    {
        information->setWindowTitle(QApplication::translate("information", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class information: public Ui_information {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMATION_H
