#include "screens/mainwindow.h"
#include <QApplication>
#include "build_settings.h"
#include "QTranslator"
#include "QSettings"
#include "screen_saver.h"
#include "protocol/asa_protocol.h"

#include "configuration/configuration.h"
#include "socket_client.h"
#include "ptar_main_window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Load configuration
    configuration *global_conf = new configuration("holo");

    //Create screen saver
    screen_saver *saver = new screen_saver();

    //Load language
    QTranslator T;

    // Create socket for communication
    socket_client *socket = new socket_client();
    // Connect socket with parameter handler

    ASA_protocol_init();


    QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
    conf.sync();
    conf.beginGroup("Lang");
    if(0 == conf.value("App_text").toInt())
    {
        //Load nothing default is spanish
    }
    else if(1 == conf.value("App_text").toInt())
    {
        T.load(":/languages/english.qm");
        a.installTranslator(&T);
    }
    conf.endGroup();

    a.setApplicationName("asa_application");
    a.setApplicationVersion("1.0");
    a.setOrganizationName("HGM - Luis Ramirez");
    a.setOrganizationDomain("none");

    ptar_main_window *main_menu = new ptar_main_window(socket);


//    MainWindow w;
//    w.setObjectName("MyMainWindow");
//    w.setStyleSheet("MainWindow#MyMainWindow{background-color:black}");
//    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
//    w.show();

    //Qt::WindowStaysOnTopHint
#if (1 == RELEASE_FOR_RPI)
    QApplication::setOverrideCursor(Qt::BlankCursor);
#endif

//    QObject::connect(&w, SIGNAL(send_date_hour(QDateTime)), saver, SLOT(receive_date_hour(QDateTime)));
//    QObject::connect(&w,SIGNAL(send_num_activities(uint)),saver, SLOT(pending_activities(uint)));
//    w.showFullScreen();



    a.installEventFilter(saver);
    return a.exec();
}
