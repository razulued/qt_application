#-------------------------------------------------
#
# Project created by QtCreator 2018-02-02T22:44:54
#
#-------------------------------------------------

QT       += core gui sql charts

LIBS += -lQt5Charts

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
    mod_1_carcamo.cpp \
    mod_2_reactor.cpp \
    mod_3_clarificador.cpp \
    mod_4_clorador.cpp \
    mod_5_digestor.cpp \
    mod_flechas.cpp \
    mod_6_lechos.cpp \
    asa_protocol.cpp \
    asa_conversions.cpp \
    clickeablelabel.cpp \
    login_dialog.cpp \
    token_auth.cpp \
    asa_conf_string.cpp \
    statistics.cpp \
    arrowkeys.cpp \
    simulation_input.cpp \
    change_text.cpp \
    calendar.cpp \
    contacto.cpp \
    earm_update.cpp \
    stop_button.cpp \
    records.cpp \
    calendario_filtro.cpp \
    record_chart.cpp \
    chart.cpp \
    screen_saver.cpp \
    build_settings.cpp \
    mod_1_regulador.cpp \
    date_widget.cpp \
    pid.cpp

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
    mod_1_carcamo.h \
    mod_2_reactor.h \
    mod_3_clarificador.h \
    mod_4_clorador.h \
    mod_5_digestor.h \
    mod_flechas.h \
    mod_6_lechos.h \
    asa_protocol.h \
    asa_conversions.h \
    clickeablelabel.h \
    login_dialog.h \
    token_auth.h \
    asa_conf_string.h \
    statistics.h \
    arrowkeys.h \
    simulation_input.h \
    change_text.h \
    calendar.h \
    contacto.h \
    build_settings.h \
    earm_update.h \
    stop_button.h \
    records.h \
    calendario_filtro.h \
    record_chart.h \
    chart.h \
    screen_saver.h \
    mod_1_regulador.h \
    date_widget.h \
    pid.h

FORMS    += mainwindow.ui \
    detailedwindow.ui \
    settings.ui \
    login_dialog.ui \
    arrowkeys.ui \
    simulation_input.ui \
    change_text.ui \
    calendar.ui \
    contacto.ui \
    earm_update.ui \
    stop_button.ui \
    records.ui \
    calendario_filtro.ui \
    record_chart.ui \
    screen_saver.ui \
    date_widget.ui

RESOURCES += \
    fonts.qrc \
    screen800x600.qrc \
    images.qrc \
    languages.qrc

INSTALLS = target

target.files = asa_application
target.path = /home/pi
