/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 11. Oct 11:39:50 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>
#include <trackcontainer.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionData_sources;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *settingsBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *aboutButton;
    QPushButton *manageGroupsButton;
    QPushButton *colorButton;
    QPushButton *loadButton;
    QPushButton *saveButton;
    QPushButton *logButton;
    QLabel *label_5;
    QLabel *labelLegend;
    QLabel *label_6;
    QHBoxLayout *browserSizeHorizontal;
    QLabel *browserSizelabel;
    QLineEdit *lineSize;
    QSlider *browserSizeSlider;
    QHBoxLayout *qualityHorizontal;
    QLabel *qualityLabel;
    QLineEdit *lineQuality;
    QSlider *qualitySlider;
    QHBoxLayout *readDepthHorizontal;
    QLabel *readDepthLabel;
    QLineEdit *lineDepth;
    QSlider *readDepthSlider;
    QLabel *label_3;
    QHBoxLayout *nonCodingHorizontalLayout;
    QCheckBox *nonCodingCheckBox;
    QLabel *nonCodingLabel;
    QHBoxLayout *synonymousHorizontalLayout;
    QCheckBox *synonymousCheckBox;
    QLabel *synonymousLabel;
    QHBoxLayout *nonSynonymousHorizontalLayout;
    QCheckBox *nonSynonymousCheckBox;
    QLabel *nonSynonymousLabel;
    QHBoxLayout *indelHorizontalLayout;
    QCheckBox *indelCheckBox;
    QLabel *indelLabel;
    QLabel *label_2;
    QFrame *groupsWidget;
    QCheckBox *ungroupedCheck;
    QLabel *label;
    QFrame *frame;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *findQuery;
    QPushButton *findButton;
    QPushButton *findClearButton;
    QListWidget *findResults;
    QLabel *label_4;
    QFrame *line_5;
    QWebView *props;
    QPushButton *rsdButton;
    QSpacerItem *verticalSpacer;
    QWidget *browserBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *browserHorizontal;
    QPushButton *settingsButton;
    QComboBox *chrBox;
    QLineEdit *lineFrom;
    QLabel *linkLabel;
    QLineEdit *lineTo;
    QPushButton *goButton;
    QLabel *positionLabel;
    QPushButton *positionLeftButton;
    QSlider *positionSlider;
    QPushButton *positionRightButton;
    QLabel *zoomLabel;
    QSlider *zoomSlider;
    QScrollArea *paintArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    TrackContainer *tracks;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(787, 837);
        actionData_sources = new QAction(MainWindow);
        actionData_sources->setObjectName(QString::fromUtf8("actionData_sources"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        settingsBox = new QWidget(centralWidget);
        settingsBox->setObjectName(QString::fromUtf8("settingsBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(settingsBox->sizePolicy().hasHeightForWidth());
        settingsBox->setSizePolicy(sizePolicy);
        settingsBox->setMaximumSize(QSize(200, 16777215));
        QFont font;
        font.setPointSize(9);
        settingsBox->setFont(font);
        verticalLayout = new QVBoxLayout(settingsBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 0, -1, -1);
        aboutButton = new QPushButton(settingsBox);
        aboutButton->setObjectName(QString::fromUtf8("aboutButton"));
        aboutButton->setMinimumSize(QSize(48, 24));
        aboutButton->setFont(font);

        gridLayout->addWidget(aboutButton, 2, 3, 1, 1);

        manageGroupsButton = new QPushButton(settingsBox);
        manageGroupsButton->setObjectName(QString::fromUtf8("manageGroupsButton"));
        manageGroupsButton->setMinimumSize(QSize(48, 24));
        manageGroupsButton->setMaximumSize(QSize(16777215, 16777215));
        manageGroupsButton->setFont(font);

        gridLayout->addWidget(manageGroupsButton, 2, 0, 1, 1);

        colorButton = new QPushButton(settingsBox);
        colorButton->setObjectName(QString::fromUtf8("colorButton"));
        colorButton->setMinimumSize(QSize(48, 24));
        colorButton->setFont(font);

        gridLayout->addWidget(colorButton, 2, 1, 1, 1);

        loadButton = new QPushButton(settingsBox);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        loadButton->setMinimumSize(QSize(48, 24));
        loadButton->setFont(font);

        gridLayout->addWidget(loadButton, 0, 0, 1, 1);

        saveButton = new QPushButton(settingsBox);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setMinimumSize(QSize(48, 24));
        saveButton->setFont(font);

        gridLayout->addWidget(saveButton, 0, 1, 1, 1);

        logButton = new QPushButton(settingsBox);
        logButton->setObjectName(QString::fromUtf8("logButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(66);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(logButton->sizePolicy().hasHeightForWidth());
        logButton->setSizePolicy(sizePolicy1);
        logButton->setMaximumSize(QSize(66, 16777215));
        logButton->setCheckable(false);

        gridLayout->addWidget(logButton, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        label_5 = new QLabel(settingsBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 10));
        label_5->setMaximumSize(QSize(16777215, 10));
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        labelLegend = new QLabel(settingsBox);
        labelLegend->setObjectName(QString::fromUtf8("labelLegend"));
        labelLegend->setMinimumSize(QSize(0, 20));
        labelLegend->setMaximumSize(QSize(16777215, 20));
        labelLegend->setFont(font);
        labelLegend->setStyleSheet(QString::fromUtf8("background-color : white;"));
        labelLegend->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelLegend);

        label_6 = new QLabel(settingsBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 10));
        label_6->setMaximumSize(QSize(16777215, 10));
        label_6->setFont(font);

        verticalLayout->addWidget(label_6);

        browserSizeHorizontal = new QHBoxLayout();
        browserSizeHorizontal->setSpacing(0);
        browserSizeHorizontal->setObjectName(QString::fromUtf8("browserSizeHorizontal"));
        browserSizeHorizontal->setContentsMargins(0, 0, -1, 0);
        browserSizelabel = new QLabel(settingsBox);
        browserSizelabel->setObjectName(QString::fromUtf8("browserSizelabel"));
        browserSizelabel->setMinimumSize(QSize(40, 0));
        browserSizelabel->setMaximumSize(QSize(40, 16777215));
        browserSizelabel->setFont(font);

        browserSizeHorizontal->addWidget(browserSizelabel);

        lineSize = new QLineEdit(settingsBox);
        lineSize->setObjectName(QString::fromUtf8("lineSize"));
        lineSize->setMinimumSize(QSize(40, 0));
        lineSize->setMaximumSize(QSize(40, 16777215));

        browserSizeHorizontal->addWidget(lineSize);

        browserSizeSlider = new QSlider(settingsBox);
        browserSizeSlider->setObjectName(QString::fromUtf8("browserSizeSlider"));
        browserSizeSlider->setFont(font);
        browserSizeSlider->setMinimum(5);
        browserSizeSlider->setMaximum(20);
        browserSizeSlider->setValue(20);
        browserSizeSlider->setOrientation(Qt::Horizontal);

        browserSizeHorizontal->addWidget(browserSizeSlider);


        verticalLayout->addLayout(browserSizeHorizontal);

        qualityHorizontal = new QHBoxLayout();
        qualityHorizontal->setSpacing(0);
        qualityHorizontal->setObjectName(QString::fromUtf8("qualityHorizontal"));
        qualityHorizontal->setContentsMargins(0, -1, 0, 0);
        qualityLabel = new QLabel(settingsBox);
        qualityLabel->setObjectName(QString::fromUtf8("qualityLabel"));
        qualityLabel->setMinimumSize(QSize(40, 0));
        qualityLabel->setMaximumSize(QSize(40, 16777215));
        qualityLabel->setFont(font);

        qualityHorizontal->addWidget(qualityLabel);

        lineQuality = new QLineEdit(settingsBox);
        lineQuality->setObjectName(QString::fromUtf8("lineQuality"));
        lineQuality->setMinimumSize(QSize(40, 0));
        lineQuality->setMaximumSize(QSize(40, 16777215));

        qualityHorizontal->addWidget(lineQuality);

        qualitySlider = new QSlider(settingsBox);
        qualitySlider->setObjectName(QString::fromUtf8("qualitySlider"));
        qualitySlider->setFont(font);
        qualitySlider->setMaximum(0);
        qualitySlider->setOrientation(Qt::Horizontal);

        qualityHorizontal->addWidget(qualitySlider);


        verticalLayout->addLayout(qualityHorizontal);

        readDepthHorizontal = new QHBoxLayout();
        readDepthHorizontal->setSpacing(0);
        readDepthHorizontal->setObjectName(QString::fromUtf8("readDepthHorizontal"));
        readDepthHorizontal->setContentsMargins(0, -1, -1, 0);
        readDepthLabel = new QLabel(settingsBox);
        readDepthLabel->setObjectName(QString::fromUtf8("readDepthLabel"));
        readDepthLabel->setMinimumSize(QSize(40, 0));
        readDepthLabel->setMaximumSize(QSize(40, 16777215));
        readDepthLabel->setFont(font);

        readDepthHorizontal->addWidget(readDepthLabel);

        lineDepth = new QLineEdit(settingsBox);
        lineDepth->setObjectName(QString::fromUtf8("lineDepth"));
        lineDepth->setMinimumSize(QSize(40, 0));
        lineDepth->setMaximumSize(QSize(40, 16777215));

        readDepthHorizontal->addWidget(lineDepth);

        readDepthSlider = new QSlider(settingsBox);
        readDepthSlider->setObjectName(QString::fromUtf8("readDepthSlider"));
        readDepthSlider->setFont(font);
        readDepthSlider->setMaximum(0);
        readDepthSlider->setOrientation(Qt::Horizontal);

        readDepthHorizontal->addWidget(readDepthSlider);


        verticalLayout->addLayout(readDepthHorizontal);

        label_3 = new QLabel(settingsBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 10));
        label_3->setMaximumSize(QSize(16777215, 10));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        nonCodingHorizontalLayout = new QHBoxLayout();
        nonCodingHorizontalLayout->setSpacing(6);
        nonCodingHorizontalLayout->setObjectName(QString::fromUtf8("nonCodingHorizontalLayout"));
        nonCodingHorizontalLayout->setContentsMargins(0, 0, 2, -1);
        nonCodingCheckBox = new QCheckBox(settingsBox);
        nonCodingCheckBox->setObjectName(QString::fromUtf8("nonCodingCheckBox"));
        nonCodingCheckBox->setChecked(true);

        nonCodingHorizontalLayout->addWidget(nonCodingCheckBox);

        nonCodingLabel = new QLabel(settingsBox);
        nonCodingLabel->setObjectName(QString::fromUtf8("nonCodingLabel"));
        nonCodingLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        nonCodingHorizontalLayout->addWidget(nonCodingLabel);


        verticalLayout->addLayout(nonCodingHorizontalLayout);

        synonymousHorizontalLayout = new QHBoxLayout();
        synonymousHorizontalLayout->setSpacing(0);
        synonymousHorizontalLayout->setObjectName(QString::fromUtf8("synonymousHorizontalLayout"));
        synonymousHorizontalLayout->setContentsMargins(-1, 0, 2, -1);
        synonymousCheckBox = new QCheckBox(settingsBox);
        synonymousCheckBox->setObjectName(QString::fromUtf8("synonymousCheckBox"));
        synonymousCheckBox->setFont(font);
        synonymousCheckBox->setChecked(true);

        synonymousHorizontalLayout->addWidget(synonymousCheckBox);

        synonymousLabel = new QLabel(settingsBox);
        synonymousLabel->setObjectName(QString::fromUtf8("synonymousLabel"));
        synonymousLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        synonymousHorizontalLayout->addWidget(synonymousLabel);


        verticalLayout->addLayout(synonymousHorizontalLayout);

        nonSynonymousHorizontalLayout = new QHBoxLayout();
        nonSynonymousHorizontalLayout->setSpacing(6);
        nonSynonymousHorizontalLayout->setObjectName(QString::fromUtf8("nonSynonymousHorizontalLayout"));
        nonSynonymousHorizontalLayout->setContentsMargins(-1, 0, 2, -1);
        nonSynonymousCheckBox = new QCheckBox(settingsBox);
        nonSynonymousCheckBox->setObjectName(QString::fromUtf8("nonSynonymousCheckBox"));
        nonSynonymousCheckBox->setFont(font);
        nonSynonymousCheckBox->setChecked(true);

        nonSynonymousHorizontalLayout->addWidget(nonSynonymousCheckBox);

        nonSynonymousLabel = new QLabel(settingsBox);
        nonSynonymousLabel->setObjectName(QString::fromUtf8("nonSynonymousLabel"));
        nonSynonymousLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        nonSynonymousHorizontalLayout->addWidget(nonSynonymousLabel);


        verticalLayout->addLayout(nonSynonymousHorizontalLayout);

        indelHorizontalLayout = new QHBoxLayout();
        indelHorizontalLayout->setSpacing(6);
        indelHorizontalLayout->setObjectName(QString::fromUtf8("indelHorizontalLayout"));
        indelHorizontalLayout->setContentsMargins(-1, 0, 2, -1);
        indelCheckBox = new QCheckBox(settingsBox);
        indelCheckBox->setObjectName(QString::fromUtf8("indelCheckBox"));
        indelCheckBox->setFont(font);
        indelCheckBox->setChecked(true);

        indelHorizontalLayout->addWidget(indelCheckBox);

        indelLabel = new QLabel(settingsBox);
        indelLabel->setObjectName(QString::fromUtf8("indelLabel"));
        indelLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        indelHorizontalLayout->addWidget(indelLabel);


        verticalLayout->addLayout(indelHorizontalLayout);

        label_2 = new QLabel(settingsBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 10));
        label_2->setMaximumSize(QSize(16777215, 10));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        groupsWidget = new QFrame(settingsBox);
        groupsWidget->setObjectName(QString::fromUtf8("groupsWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupsWidget->sizePolicy().hasHeightForWidth());
        groupsWidget->setSizePolicy(sizePolicy2);
        groupsWidget->setMinimumSize(QSize(200, 23));
        groupsWidget->setMaximumSize(QSize(200, 16777215));
        groupsWidget->setFont(font);
        ungroupedCheck = new QCheckBox(groupsWidget);
        ungroupedCheck->setObjectName(QString::fromUtf8("ungroupedCheck"));
        ungroupedCheck->setGeometry(QRect(0, 0, 150, 18));
        ungroupedCheck->setFont(font);
        ungroupedCheck->setChecked(true);

        verticalLayout->addWidget(groupsWidget);

        label = new QLabel(settingsBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 10));
        label->setMaximumSize(QSize(16777215, 10));
        label->setFont(font);

        verticalLayout->addWidget(label);

        frame = new QFrame(settingsBox);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy3);
        frame->setFont(font);
        verticalLayout_4 = new QVBoxLayout(frame);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        findQuery = new QLineEdit(frame);
        findQuery->setObjectName(QString::fromUtf8("findQuery"));
        findQuery->setFont(font);

        horizontalLayout_2->addWidget(findQuery);

        findButton = new QPushButton(frame);
        findButton->setObjectName(QString::fromUtf8("findButton"));
        findButton->setMaximumSize(QSize(50, 16777215));
        findButton->setFont(font);

        horizontalLayout_2->addWidget(findButton);

        findClearButton = new QPushButton(frame);
        findClearButton->setObjectName(QString::fromUtf8("findClearButton"));
        findClearButton->setMaximumSize(QSize(50, 16777215));
        findClearButton->setFont(font);

        horizontalLayout_2->addWidget(findClearButton);


        verticalLayout_4->addLayout(horizontalLayout_2);

        findResults = new QListWidget(frame);
        findResults->setObjectName(QString::fromUtf8("findResults"));
        findResults->setFont(font);

        verticalLayout_4->addWidget(findResults);


        verticalLayout->addWidget(frame);

        label_4 = new QLabel(settingsBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 10));
        label_4->setMaximumSize(QSize(16777215, 10));
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        line_5 = new QFrame(settingsBox);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFont(font);
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_5);

        props = new QWebView(settingsBox);
        props->setObjectName(QString::fromUtf8("props"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(props->sizePolicy().hasHeightForWidth());
        props->setSizePolicy(sizePolicy4);
        props->setMaximumSize(QSize(16777215, 200));
        props->setSizeIncrement(QSize(0, 0));
        props->setFont(font);
        props->setUrl(QUrl("about:blank"));

        verticalLayout->addWidget(props);

        rsdButton = new QPushButton(settingsBox);
        rsdButton->setObjectName(QString::fromUtf8("rsdButton"));
        rsdButton->setFont(font);
        rsdButton->setFlat(false);

        verticalLayout->addWidget(rsdButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(settingsBox);

        browserBox = new QWidget(centralWidget);
        browserBox->setObjectName(QString::fromUtf8("browserBox"));
        browserBox->setFont(font);
        verticalLayout_3 = new QVBoxLayout(browserBox);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        browserHorizontal = new QHBoxLayout();
        browserHorizontal->setSpacing(2);
        browserHorizontal->setObjectName(QString::fromUtf8("browserHorizontal"));
        browserHorizontal->setContentsMargins(-1, -1, -1, 0);
        settingsButton = new QPushButton(browserBox);
        settingsButton->setObjectName(QString::fromUtf8("settingsButton"));
        settingsButton->setMinimumSize(QSize(20, 20));
        settingsButton->setMaximumSize(QSize(20, 20));
        settingsButton->setFont(font);

        browserHorizontal->addWidget(settingsButton);

        chrBox = new QComboBox(browserBox);
        chrBox->setObjectName(QString::fromUtf8("chrBox"));
        sizePolicy4.setHeightForWidth(chrBox->sizePolicy().hasHeightForWidth());
        chrBox->setSizePolicy(sizePolicy4);
        chrBox->setFont(font);

        browserHorizontal->addWidget(chrBox);

        lineFrom = new QLineEdit(browserBox);
        lineFrom->setObjectName(QString::fromUtf8("lineFrom"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lineFrom->sizePolicy().hasHeightForWidth());
        lineFrom->setSizePolicy(sizePolicy5);
        lineFrom->setMinimumSize(QSize(60, 0));
        lineFrom->setMaximumSize(QSize(60, 16777215));
        lineFrom->setFont(font);
        lineFrom->setInputMethodHints(Qt::ImhNone);

        browserHorizontal->addWidget(lineFrom);

        linkLabel = new QLabel(browserBox);
        linkLabel->setObjectName(QString::fromUtf8("linkLabel"));
        linkLabel->setMinimumSize(QSize(10, 0));
        linkLabel->setMaximumSize(QSize(10, 16777215));
        linkLabel->setFont(font);

        browserHorizontal->addWidget(linkLabel);

        lineTo = new QLineEdit(browserBox);
        lineTo->setObjectName(QString::fromUtf8("lineTo"));
        sizePolicy5.setHeightForWidth(lineTo->sizePolicy().hasHeightForWidth());
        lineTo->setSizePolicy(sizePolicy5);
        lineTo->setMinimumSize(QSize(60, 0));
        lineTo->setMaximumSize(QSize(60, 16777215));
        lineTo->setFont(font);
        lineTo->setInputMethodHints(Qt::ImhNone);

        browserHorizontal->addWidget(lineTo);

        goButton = new QPushButton(browserBox);
        goButton->setObjectName(QString::fromUtf8("goButton"));
        goButton->setEnabled(true);
        goButton->setMinimumSize(QSize(40, 20));
        goButton->setMaximumSize(QSize(40, 20));
        goButton->setFont(font);

        browserHorizontal->addWidget(goButton);

        positionLabel = new QLabel(browserBox);
        positionLabel->setObjectName(QString::fromUtf8("positionLabel"));
        sizePolicy5.setHeightForWidth(positionLabel->sizePolicy().hasHeightForWidth());
        positionLabel->setSizePolicy(sizePolicy5);
        positionLabel->setMinimumSize(QSize(60, 25));
        positionLabel->setMaximumSize(QSize(60, 25));
        positionLabel->setFont(font);

        browserHorizontal->addWidget(positionLabel);

        positionLeftButton = new QPushButton(browserBox);
        positionLeftButton->setObjectName(QString::fromUtf8("positionLeftButton"));
        positionLeftButton->setMinimumSize(QSize(16, 24));
        positionLeftButton->setMaximumSize(QSize(16, 24));

        browserHorizontal->addWidget(positionLeftButton);

        positionSlider = new QSlider(browserBox);
        positionSlider->setObjectName(QString::fromUtf8("positionSlider"));
        positionSlider->setMinimumSize(QSize(16, 24));
        positionSlider->setMaximumSize(QSize(16777215, 24));
        positionSlider->setFont(font);
        positionSlider->setOrientation(Qt::Horizontal);

        browserHorizontal->addWidget(positionSlider);

        positionRightButton = new QPushButton(browserBox);
        positionRightButton->setObjectName(QString::fromUtf8("positionRightButton"));
        positionRightButton->setMinimumSize(QSize(16, 24));
        positionRightButton->setMaximumSize(QSize(16, 24));

        browserHorizontal->addWidget(positionRightButton);

        zoomLabel = new QLabel(browserBox);
        zoomLabel->setObjectName(QString::fromUtf8("zoomLabel"));
        zoomLabel->setMaximumSize(QSize(16777215, 25));
        zoomLabel->setFont(font);

        browserHorizontal->addWidget(zoomLabel);

        zoomSlider = new QSlider(browserBox);
        zoomSlider->setObjectName(QString::fromUtf8("zoomSlider"));
        zoomSlider->setFont(font);
        zoomSlider->setOrientation(Qt::Horizontal);

        browserHorizontal->addWidget(zoomSlider);


        verticalLayout_3->addLayout(browserHorizontal);

        paintArea = new QScrollArea(browserBox);
        paintArea->setObjectName(QString::fromUtf8("paintArea"));
        paintArea->setFont(font);
        paintArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        paintArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        paintArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 567, 788));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tracks = new TrackContainer(scrollAreaWidgetContents);
        tracks->setObjectName(QString::fromUtf8("tracks"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(tracks->sizePolicy().hasHeightForWidth());
        tracks->setSizePolicy(sizePolicy6);
        tracks->setMinimumSize(QSize(0, 0));
        tracks->setFont(font);

        verticalLayout_2->addWidget(tracks);

        paintArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(paintArea);


        horizontalLayout->addWidget(browserBox);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(settingsButton, lineTo);
        QWidget::setTabOrder(lineTo, goButton);
        QWidget::setTabOrder(goButton, positionSlider);
        QWidget::setTabOrder(positionSlider, zoomSlider);
        QWidget::setTabOrder(zoomSlider, paintArea);
        QWidget::setTabOrder(paintArea, lineSize);
        QWidget::setTabOrder(lineSize, browserSizeSlider);
        QWidget::setTabOrder(browserSizeSlider, lineQuality);
        QWidget::setTabOrder(lineQuality, qualitySlider);
        QWidget::setTabOrder(qualitySlider, lineDepth);
        QWidget::setTabOrder(lineDepth, readDepthSlider);
        QWidget::setTabOrder(readDepthSlider, nonCodingCheckBox);
        QWidget::setTabOrder(nonCodingCheckBox, synonymousCheckBox);
        QWidget::setTabOrder(synonymousCheckBox, nonSynonymousCheckBox);
        QWidget::setTabOrder(nonSynonymousCheckBox, indelCheckBox);
        QWidget::setTabOrder(indelCheckBox, ungroupedCheck);
        QWidget::setTabOrder(ungroupedCheck, findQuery);
        QWidget::setTabOrder(findQuery, findButton);
        QWidget::setTabOrder(findButton, findClearButton);
        QWidget::setTabOrder(findClearButton, findResults);
        QWidget::setTabOrder(findResults, props);
        QWidget::setTabOrder(props, rsdButton);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "VARiation Browser", 0, QApplication::UnicodeUTF8));
        actionData_sources->setText(QApplication::translate("MainWindow", "Data sources", 0, QApplication::UnicodeUTF8));
        aboutButton->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        manageGroupsButton->setText(QApplication::translate("MainWindow", "Groups", 0, QApplication::UnicodeUTF8));
        colorButton->setText(QApplication::translate("MainWindow", "Colours", 0, QApplication::UnicodeUTF8));
        loadButton->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        logButton->setText(QApplication::translate("MainWindow", "Log", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
#ifndef QT_NO_TOOLTIP
        labelLegend->setToolTip(QApplication::translate("MainWindow", "Colour legend", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        labelLegend->setText(QString());
        label_6->setText(QString());
#ifndef QT_NO_TOOLTIP
        browserSizelabel->setToolTip(QApplication::translate("MainWindow", "Change the hieght that the isolates are rendered at", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        browserSizelabel->setText(QApplication::translate("MainWindow", "Size", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineSize->setToolTip(QApplication::translate("MainWindow", "Change the hieght that the isolates are rendered at", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        browserSizeSlider->setToolTip(QApplication::translate("MainWindow", "Change the hieght that the isolates are rendered at", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        qualityLabel->setToolTip(QApplication::translate("MainWindow", "Filter on the quality of the call", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        qualityLabel->setText(QApplication::translate("MainWindow", "Quality", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineQuality->setToolTip(QApplication::translate("MainWindow", "Filter on the quality of the call", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        qualitySlider->setToolTip(QApplication::translate("MainWindow", "Filter on the quality of the call", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        readDepthLabel->setToolTip(QApplication::translate("MainWindow", "Filter on the read depth", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        readDepthLabel->setText(QApplication::translate("MainWindow", "Depth", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineDepth->setToolTip(QApplication::translate("MainWindow", "Filter on the read depth", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        readDepthSlider->setToolTip(QApplication::translate("MainWindow", "Filter on the read depth", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_3->setText(QString());
#ifndef QT_NO_TOOLTIP
        nonCodingCheckBox->setToolTip(QApplication::translate("MainWindow", "Filter non-coding SNPs", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        nonCodingCheckBox->setText(QApplication::translate("MainWindow", "Non-coding SNPs", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        nonCodingLabel->setToolTip(QApplication::translate("MainWindow", "Filter non-coding SNPs", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        nonCodingLabel->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        synonymousCheckBox->setToolTip(QApplication::translate("MainWindow", "Filter synonymous SNPs", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        synonymousCheckBox->setText(QApplication::translate("MainWindow", "Synonymous SNPs", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        synonymousLabel->setToolTip(QApplication::translate("MainWindow", "Filter synonymous SNPs", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        synonymousLabel->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        nonSynonymousCheckBox->setToolTip(QApplication::translate("MainWindow", "Filter non-synonymous SNPs", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        nonSynonymousCheckBox->setText(QApplication::translate("MainWindow", "Non-synonymous SNPs", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        nonSynonymousLabel->setToolTip(QApplication::translate("MainWindow", "Filter non-synonymous SNPs", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        nonSynonymousLabel->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        indelCheckBox->setToolTip(QApplication::translate("MainWindow", "Filter insertions and deletions", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        indelCheckBox->setText(QApplication::translate("MainWindow", "Indels", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        indelLabel->setToolTip(QApplication::translate("MainWindow", "Filter insertions and deletions", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        indelLabel->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        ungroupedCheck->setText(QApplication::translate("MainWindow", "Ungrouped", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
#ifndef QT_NO_TOOLTIP
        findQuery->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Search for genes containing this pattern</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        findQuery->setText(QString());
        findQuery->setPlaceholderText(QString());
#ifndef QT_NO_TOOLTIP
        findButton->setToolTip(QApplication::translate("MainWindow", "Search for genes with containing this pattern", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        findButton->setText(QApplication::translate("MainWindow", "Find", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        findClearButton->setToolTip(QApplication::translate("MainWindow", "Clear the gene description", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        findClearButton->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
#ifndef QT_NO_TOOLTIP
        props->setToolTip(QApplication::translate("MainWindow", "Description of the position and variant under the mouse", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        rsdButton->setText(QApplication::translate("MainWindow", "Clear sticky description", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        settingsButton->setToolTip(QApplication::translate("MainWindow", "Hide settings", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        settingsButton->setText(QApplication::translate("MainWindow", "<", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        chrBox->setToolTip(QApplication::translate("MainWindow", "Select chromosome", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        lineFrom->setToolTip(QApplication::translate("MainWindow", "Lower bound", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        linkLabel->setText(QApplication::translate("MainWindow", " - ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineTo->setToolTip(QApplication::translate("MainWindow", "Upper bound", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        goButton->setText(QApplication::translate("MainWindow", "Go", 0, QApplication::UnicodeUTF8));
        positionLabel->setText(QApplication::translate("MainWindow", "  Position ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        positionLeftButton->setToolTip(QApplication::translate("MainWindow", "Step left", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        positionLeftButton->setText(QApplication::translate("MainWindow", "<", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        positionSlider->setToolTip(QApplication::translate("MainWindow", "Move view left/right", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        positionRightButton->setToolTip(QApplication::translate("MainWindow", "Step right", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        positionRightButton->setText(QApplication::translate("MainWindow", ">", 0, QApplication::UnicodeUTF8));
        zoomLabel->setText(QApplication::translate("MainWindow", "  Zoom ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        zoomSlider->setToolTip(QApplication::translate("MainWindow", "Zoom in/out", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
