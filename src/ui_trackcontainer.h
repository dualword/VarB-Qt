/********************************************************************************
** Form generated from reading UI file 'trackcontainer.ui'
**
** Created: Wed 10. Oct 09:59:17 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACKCONTAINER_H
#define UI_TRACKCONTAINER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrackContainer
{
public:

    void setupUi(QWidget *TrackContainer)
    {
        if (TrackContainer->objectName().isEmpty())
            TrackContainer->setObjectName(QString::fromUtf8("TrackContainer"));
        TrackContainer->resize(400, 300);
        QFont font;
        font.setPointSize(9);
        TrackContainer->setFont(font);

        retranslateUi(TrackContainer);

        QMetaObject::connectSlotsByName(TrackContainer);
    } // setupUi

    void retranslateUi(QWidget *TrackContainer)
    {
        TrackContainer->setWindowTitle(QApplication::translate("TrackContainer", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TrackContainer: public Ui_TrackContainer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACKCONTAINER_H
