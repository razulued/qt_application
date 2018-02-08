#-------------------------------------------------
#
# Project created by QtCreator 2018-02-02T22:44:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = asa_application
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    detailedwindow.cpp \
    multistatebutton.cpp \
    demo.cpp

HEADERS  += mainwindow.h \
    detailedwindow.h \
    multistatebutton.h \
    demo.h

FORMS    += mainwindow.ui \
    detailedwindow.ui

RESOURCES += \
    images.qrc \
    fonts.qrc
