#-------------------------------------------------
#
# Project created by QtCreator 2016-07-07T09:30:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mydialog.cpp \
    helloworld.cpp \
    dialog.cpp \
    helloqlist.cpp \
    messageboxbox.cpp \
    myThread.cpp

HEADERS  += mainwindow.h \
    mydialog.h \
    helloworld.h \
    dialog.h \
    helloqlist.h \
    myThread.h \
    messageboxbox.h

FORMS    += mainwindow.ui \
    mydialog.ui \
    helloworld.ui \
    dialog.ui \
    helloqlist.ui \
    messageboxbox.ui

RESOURCES += \
    myresources.qrc
