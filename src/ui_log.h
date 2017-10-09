/********************************************************************************
** Form generated from reading UI file 'log.ui'
**
** Created: Thu 11. Oct 11:30:54 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_H
#define UI_LOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Log
{
public:
    QTextBrowser *logBrowser;

    void setupUi(QDialog *Log)
    {
        if (Log->objectName().isEmpty())
            Log->setObjectName(QString::fromUtf8("Log"));
        Log->resize(400, 300);
        logBrowser = new QTextBrowser(Log);
        logBrowser->setObjectName(QString::fromUtf8("logBrowser"));
        logBrowser->setGeometry(QRect(10, 10, 381, 281));

        retranslateUi(Log);

        QMetaObject::connectSlotsByName(Log);
    } // setupUi

    void retranslateUi(QDialog *Log)
    {
        Log->setWindowTitle(QApplication::translate("Log", "VarB Log Messages", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Log: public Ui_Log {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_H
