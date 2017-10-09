/********************************************************************************
** Form generated from reading UI file 'groupcontainer.ui'
**
** Created: Thu Dec 22 17:01:03 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPCONTAINER_H
#define UI_GROUPCONTAINER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupContainer
{
public:

    void setupUi(QWidget *GroupContainer)
    {
        if (GroupContainer->objectName().isEmpty())
            GroupContainer->setObjectName(QString::fromUtf8("GroupContainer"));
        GroupContainer->resize(196, 46);

        retranslateUi(GroupContainer);

        QMetaObject::connectSlotsByName(GroupContainer);
    } // setupUi

    void retranslateUi(QWidget *GroupContainer)
    {
        GroupContainer->setWindowTitle(QApplication::translate("GroupContainer", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GroupContainer: public Ui_GroupContainer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPCONTAINER_H
