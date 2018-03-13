#-------------------------------------------------
#
# Project created by QtCreator 2018-02-02T22:44:54
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = asa_application
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    detailedwindow.cpp \
    multistatebutton.cpp \
    bcm2835.c \
    parameters.cpp \
    spicomm.cpp \
    my_crc_api.cpp \
    dataproccess.cpp \
    custom_tooltip.cpp \
    settings.cpp \
    configuration.cpp \
    bitacora.cpp \
    rutinas_mantenimiento.cpp

HEADERS  += mainwindow.h \
    detailedwindow.h \
    multistatebutton.h \
    parameters.h \
    bcm2835.h \
    spicomm.h \
    my_crc_api.h \
    dataproccess.h \
    custom_tooltip.h \
    settings.h \
    configuration.h \
    bitacora.h \
    rutinas_mantenimiento.h

FORMS    += mainwindow.ui \
    detailedwindow.ui \
    settings.ui \
    bitacora.ui

RESOURCES += \
    images.qrc \
    fonts.qrc

INSTALLS = target

target.files = asa_application
target.path = /home/pi
