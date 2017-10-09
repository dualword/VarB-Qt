/********************************************************************************
** Form generated from reading UI file 'groupmanager.ui'
**
** Created: Wed 10. Oct 09:59:18 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPMANAGER_H
#define UI_GROUPMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GroupManager
{
public:
    QListWidget *groupList;
    QListWidget *ungroupedList;
    QPushButton *removeSelectedButton;
    QPushButton *addSelectedButton;
    QPushButton *removeAllButton;
    QPushButton *doneButton;
    QLabel *Ungrouped;
    QLineEdit *newGroupLine;
    QComboBox *groupCombo;
    QPushButton *addGroupButton;

    void setupUi(QDialog *GroupManager)
    {
        if (GroupManager->objectName().isEmpty())
            GroupManager->setObjectName(QString::fromUtf8("GroupManager"));
        GroupManager->resize(270, 326);
        groupList = new QListWidget(GroupManager);
        groupList->setObjectName(QString::fromUtf8("groupList"));
        groupList->setGeometry(QRect(10, 60, 120, 200));
        QFont font;
        font.setPointSize(9);
        groupList->setFont(font);
        groupList->setSelectionMode(QAbstractItemView::MultiSelection);
        ungroupedList = new QListWidget(GroupManager);
        ungroupedList->setObjectName(QString::fromUtf8("ungroupedList"));
        ungroupedList->setGeometry(QRect(140, 60, 120, 200));
        ungroupedList->setFont(font);
        ungroupedList->setSelectionMode(QAbstractItemView::MultiSelection);
        removeSelectedButton = new QPushButton(GroupManager);
        removeSelectedButton->setObjectName(QString::fromUtf8("removeSelectedButton"));
        removeSelectedButton->setGeometry(QRect(10, 270, 120, 23));
        removeSelectedButton->setMinimumSize(QSize(120, 23));
        removeSelectedButton->setMaximumSize(QSize(120, 23));
        removeSelectedButton->setFont(font);
        addSelectedButton = new QPushButton(GroupManager);
        addSelectedButton->setObjectName(QString::fromUtf8("addSelectedButton"));
        addSelectedButton->setGeometry(QRect(140, 270, 120, 23));
        addSelectedButton->setMinimumSize(QSize(120, 23));
        addSelectedButton->setMaximumSize(QSize(120, 23));
        addSelectedButton->setFont(font);
        removeAllButton = new QPushButton(GroupManager);
        removeAllButton->setObjectName(QString::fromUtf8("removeAllButton"));
        removeAllButton->setGeometry(QRect(10, 293, 120, 23));
        removeAllButton->setMinimumSize(QSize(120, 23));
        removeAllButton->setMaximumSize(QSize(120, 23));
        removeAllButton->setFont(font);
        doneButton = new QPushButton(GroupManager);
        doneButton->setObjectName(QString::fromUtf8("doneButton"));
        doneButton->setGeometry(QRect(140, 293, 120, 23));
        doneButton->setMinimumSize(QSize(120, 23));
        doneButton->setMaximumSize(QSize(120, 23));
        doneButton->setFont(font);
        Ungrouped = new QLabel(GroupManager);
        Ungrouped->setObjectName(QString::fromUtf8("Ungrouped"));
        Ungrouped->setGeometry(QRect(140, 35, 120, 20));
        Ungrouped->setFont(font);
        Ungrouped->setAlignment(Qt::AlignCenter);
        newGroupLine = new QLineEdit(GroupManager);
        newGroupLine->setObjectName(QString::fromUtf8("newGroupLine"));
        newGroupLine->setGeometry(QRect(10, 5, 120, 20));
        groupCombo = new QComboBox(GroupManager);
        groupCombo->setObjectName(QString::fromUtf8("groupCombo"));
        groupCombo->setGeometry(QRect(10, 32, 120, 22));
        addGroupButton = new QPushButton(GroupManager);
        addGroupButton->setObjectName(QString::fromUtf8("addGroupButton"));
        addGroupButton->setGeometry(QRect(140, 5, 50, 23));
        addGroupButton->setMaximumSize(QSize(50, 16777215));
        addGroupButton->setFont(font);
        QWidget::setTabOrder(doneButton, newGroupLine);
        QWidget::setTabOrder(newGroupLine, addGroupButton);
        QWidget::setTabOrder(addGroupButton, groupCombo);
        QWidget::setTabOrder(groupCombo, groupList);
        QWidget::setTabOrder(groupList, ungroupedList);
        QWidget::setTabOrder(ungroupedList, removeSelectedButton);
        QWidget::setTabOrder(removeSelectedButton, removeAllButton);
        QWidget::setTabOrder(removeAllButton, addSelectedButton);

        retranslateUi(GroupManager);

        QMetaObject::connectSlotsByName(GroupManager);
    } // setupUi

    void retranslateUi(QDialog *GroupManager)
    {
        GroupManager->setWindowTitle(QApplication::translate("GroupManager", "VarB: Groups", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupList->setToolTip(QApplication::translate("GroupManager", "Isloates in the selected group", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        ungroupedList->setToolTip(QApplication::translate("GroupManager", "Select isolates not in any group to add to the selected grroup", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        removeSelectedButton->setToolTip(QApplication::translate("GroupManager", "Remove the selected isolates from this group", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        removeSelectedButton->setText(QApplication::translate("GroupManager", "Remove Selected", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        addSelectedButton->setToolTip(QApplication::translate("GroupManager", "Add the selected ungrouped isolates to the group", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addSelectedButton->setText(QApplication::translate("GroupManager", "Add Selected", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        removeAllButton->setToolTip(QApplication::translate("GroupManager", "Remove all of the isloates from this group", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        removeAllButton->setText(QApplication::translate("GroupManager", "Remove All", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        doneButton->setToolTip(QApplication::translate("GroupManager", "Finish and return to the main application", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        doneButton->setText(QApplication::translate("GroupManager", "Done", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Ungrouped->setToolTip(QApplication::translate("GroupManager", "Isolates not in any group", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        Ungrouped->setText(QApplication::translate("GroupManager", "Ungrouped", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        newGroupLine->setToolTip(QApplication::translate("GroupManager", "New group name", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        groupCombo->setToolTip(QApplication::translate("GroupManager", "Select a group", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        addGroupButton->setToolTip(QApplication::translate("GroupManager", "Add this group to the list", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addGroupButton->setText(QApplication::translate("GroupManager", "Add", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GroupManager: public Ui_GroupManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPMANAGER_H
