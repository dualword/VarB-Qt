/********************************************************************************
** Form generated from reading UI file 'save.ui'
**
** Created: Wed 10. Oct 09:59:18 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVE_H
#define UI_SAVE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Save
{
public:
    QPushButton *cancelButton;
    QPushButton *saveDataButton;
    QPushButton *saveImagesButton;
    QLabel *dataFileLabel;
    QLineEdit *dataFileLine;
    QLineEdit *imagesFileLine;
    QLabel *imagesFileLabel;

    void setupUi(QDialog *Save)
    {
        if (Save->objectName().isEmpty())
            Save->setObjectName(QString::fromUtf8("Save"));
        Save->resize(430, 100);
        cancelButton = new QPushButton(Save);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(340, 70, 80, 23));
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        cancelButton->setFont(font);
        saveDataButton = new QPushButton(Save);
        saveDataButton->setObjectName(QString::fromUtf8("saveDataButton"));
        saveDataButton->setGeometry(QRect(340, 10, 80, 23));
        saveDataButton->setFont(font);
        saveImagesButton = new QPushButton(Save);
        saveImagesButton->setObjectName(QString::fromUtf8("saveImagesButton"));
        saveImagesButton->setGeometry(QRect(340, 40, 80, 23));
        saveImagesButton->setFont(font);
        dataFileLabel = new QLabel(Save);
        dataFileLabel->setObjectName(QString::fromUtf8("dataFileLabel"));
        dataFileLabel->setGeometry(QRect(10, 10, 51, 20));
        dataFileLabel->setFont(font);
        dataFileLine = new QLineEdit(Save);
        dataFileLine->setObjectName(QString::fromUtf8("dataFileLine"));
        dataFileLine->setGeometry(QRect(60, 10, 270, 20));
        dataFileLine->setFont(font);
        imagesFileLine = new QLineEdit(Save);
        imagesFileLine->setObjectName(QString::fromUtf8("imagesFileLine"));
        imagesFileLine->setGeometry(QRect(60, 40, 270, 20));
        imagesFileLine->setFont(font);
        imagesFileLabel = new QLabel(Save);
        imagesFileLabel->setObjectName(QString::fromUtf8("imagesFileLabel"));
        imagesFileLabel->setGeometry(QRect(10, 40, 51, 20));
        imagesFileLabel->setFont(font);
        QWidget::setTabOrder(saveDataButton, saveImagesButton);
        QWidget::setTabOrder(saveImagesButton, cancelButton);
        QWidget::setTabOrder(cancelButton, dataFileLine);
        QWidget::setTabOrder(dataFileLine, imagesFileLine);

        retranslateUi(Save);

        QMetaObject::connectSlotsByName(Save);
    } // setupUi

    void retranslateUi(QDialog *Save)
    {
        Save->setWindowTitle(QApplication::translate("Save", "VarB: Save", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("Save", "Close", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveDataButton->setToolTip(QApplication::translate("Save", "Select a file to save the statistical data to", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveDataButton->setText(QApplication::translate("Save", "Save Data", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveImagesButton->setToolTip(QApplication::translate("Save", "Select a file to save the graphics to", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveImagesButton->setText(QApplication::translate("Save", "Save Image", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        dataFileLabel->setToolTip(QApplication::translate("Save", "Select a file to save the statistical data to", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        dataFileLabel->setText(QApplication::translate("Save", "Data", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        dataFileLine->setToolTip(QApplication::translate("Save", "Select a file to save the statistical data to", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        imagesFileLine->setToolTip(QApplication::translate("Save", "Select a file to save the graphics to", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        imagesFileLabel->setToolTip(QApplication::translate("Save", "Select a file to save the graphics to", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        imagesFileLabel->setText(QApplication::translate("Save", "Image", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Save: public Ui_Save {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVE_H
