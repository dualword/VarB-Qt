#-------------------------------------------------
#
# Project created by QtCreator 2011-02-11T20:40:53
#
#-------------------------------------------------

QT += core gui webkit

CONFIG += static

TARGET = varb
TEMPLATE = app

SOURCES += main.cpp\
    mainwindow.cpp \
    track.cpp \
    trackcontainer.cpp \
    tracksequence.cpp \
    annotation.cpp \
    trackannotation.cpp \
    variation.cpp \
    trackvariation.cpp \
    searchresult.cpp \
    sourcesdialog.cpp \
    trackgraph.cpp \
    groupmanager.cpp \
    sequence.cpp \
    colors.cpp \
    save.cpp \
    feedback.cpp \
    log.cpp

HEADERS  += mainwindow.h \
    track.h \
    trackcontainer.h \
    tracksequence.h \
    annotation.h \
    trackannotation.h \
    variation.h \
    trackvariation.h \
    searchresult.h \
    sourcesdialog.h \
    trackgraph.h \
    groupmanager.h \
    trackgraphgc.h \
    trackgraphvd.h \
    sequence.h \
    trackgraphfst.h \
    trackgraphtd.h \
    colors.h \
    save.h \
    feedback.h \
    log.h

FORMS    += mainwindow.ui \
    trackcontainer.ui \
    sourcesdialog.ui \
    groupmanager.ui \
    colors.ui \
    save.ui \
    feedback.ui \
    log.ui
