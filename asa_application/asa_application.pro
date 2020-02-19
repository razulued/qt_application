#-------------------------------------------------
#
# Project created by QtCreator 2018-02-02T22:44:54
#
#-------------------------------------------------

QT       += core gui sql network charts

LIBS += -lQt5Charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = asa_application
TEMPLATE = app


SOURCES += main.cpp\
    multistatebutton.cpp \
    spicomm.cpp \
    my_crc_api.cpp \
    dataproccess.cpp \
    custom_tooltip.cpp \
    rutinas_mantenimiento.cpp \
    clickeablelabel.cpp \
    token_auth.cpp \
    statistics.cpp \
    sql_cmd_manager.cpp \
    build_settings.cpp \
    spi_lib/bcm2835.c \
    protocol/asa_conf_string.cpp \
    protocol/asa_conversions.cpp \
    protocol/asa_protocol.cpp \
    animated/mod_1_carcamo.cpp \
    animated/mod_1_regulador.cpp \
    animated/mod_2_reactor.cpp \
    animated/mod_3_clarificador.cpp \
    animated/mod_4_clorador.cpp \
    animated/mod_5_digestor.cpp \
    animated/mod_6_lechos.cpp \
    animated/mod_flechas.cpp \
    protocol/parameters.cpp \
    configuration/configuration.cpp \
    screens/graphwindow.cpp \
    screens/detailedwindow.cpp \
    screens/arrowkeys.cpp \
    screens/bitacora.cpp \
    screens/calendar.cpp \
    screens/calendario_filtro.cpp \
    screens/change_text.cpp \
    screens/contacto.cpp \
    screens/record_chart.cpp \
    screens/records.cpp \
    screens/screen_saver.cpp \
    screens/settings.cpp \
    screens/stop_button.cpp \
    screens/login_dialog.cpp \
    screens/earm_update.cpp \
    socket_client.cpp \
    screens/confsetup.cpp \
    screens/confentry.cpp \
    screens/generic_window.cpp \
    ptar_main_window.cpp \
    mainmenu.cpp \
    line_chart.cpp \
    view.cpp \
    callout.cpp \
    protocol/configuration.cpp

HEADERS  += \
    multistatebutton.h \
    parameters.h \
    spicomm.h \
    my_crc_api.h \
    dataproccess.h \
    custom_tooltip.h \
    settings.h \
    bitacora.h \
    rutinas_mantenimiento.h \
    clickeablelabel.h \
    login_dialog.h \
    token_auth.h \
    statistics.h \
    arrowkeys.h \
    change_text.h \
    calendar.h \
    contacto.h \
    build_settings.h \
    earm_update.h \
    stop_button.h \
    records.h \
    calendario_filtro.h \
    record_chart.h \
    sql_cmd_manager.h \
    screen_saver.h \
    spi_lib/bcm2835.h \
    protocol/asa_conf_string.h \
    protocol/asa_conversions.h \
    protocol/asa_protocol.h \
    animated/mod_1_carcamo.h \
    animated/mod_1_regulador.h \
    animated/mod_2_reactor.h \
    animated/mod_3_clarificador.h \
    animated/mod_4_clorador.h \
    animated/mod_5_digestor.h \
    animated/mod_6_lechos.h \
    animated/mod_flechas.h \
    configuration/configuration.h \
    screens/detailedwindow.h \
    screens/graphwindow.h \
    socket_client.h \
    screens/confsetup.h \
    screens/confentry.h \
    screens/generic_window.h \
    ptar_main_window.h \
    mainmenu.h \
    line_chart.h \
    view.h \
    callout.h \
    protocol/configuration.h

FORMS    += \
    detailedwindow.ui \
    settings.ui \
    bitacora.ui \
    login_dialog.ui \
    graphwindow.ui \
    arrowkeys.ui \
    change_text.ui \
    calendar.ui \
    contacto.ui \
    earm_update.ui \
    stop_button.ui \
    records.ui \
    calendario_filtro.ui \
    record_chart.ui \
    screen_saver.ui \
    confsetup.ui \
    confentry.ui \
    screens/generic_window.ui \
    ptar_main_window.ui \
    mainmenu.ui

RESOURCES += \
    fonts.qrc \
    screen800x600.qrc \
    images.qrc \
    languages.qrc

INSTALLS = target

target.files = asa_application
target.path = /home/pi

DISTFILES += \
    ptar_client/Nuevo documento de texto.txt
