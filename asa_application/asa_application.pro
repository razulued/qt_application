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
    rutinas_mantenimiento.cpp \
    mod_1_carcamo.cpp \
    mod_2_reactor.cpp \
    mod_3_clarificador.cpp \
    mod_4_clorador.cpp \
    mod_5_digestor.cpp \
    mod_flechas.cpp \
    mod_6_lechos.cpp \
    asa_protocol.cpp \
    asa_conversions.cpp \
    clickeablelabel.cpp

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
    rutinas_mantenimiento.h \
    mod_1_carcamo.h \
    mod_2_reactor.h \
    mod_3_clarificador.h \
    mod_4_clorador.h \
    mod_5_digestor.h \
    mod_flechas.h \
    mod_6_lechos.h \
    asa_protocol.h \
    asa_conversions.h \
    clickeablelabel.h

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
