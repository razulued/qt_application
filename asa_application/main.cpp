#include "mainwindow.h"
#include <QApplication>
#include "build_settings.h"
#include "QTranslator"
#include "QSettings"
#include "screen_saver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    screen_saver *saver = new screen_saver();

    //Load language
    QTranslator T;

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
    MainWindow w;

    w.setObjectName("MyMainWindow");
    w.setStyleSheet("MainWindow#MyMainWindow{background-image:url(:/images/images/P FF.png)}");
//    w.setStyleSheet("MainWindow#MyMainWindow{background-color:black}");
    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);

    //Qt::WindowStaysOnTopHint
#if (1 == RELEASE_FOR_RPI)
    QApplication::setOverrideCursor(Qt::BlankCursor);
#endif

    a.installEventFilter(saver);
    QObject::connect(&w, SIGNAL(send_date_hour(QDateTime)), saver, SLOT(receive_date_hour(QDateTime)));
    QObject::connect(&w,SIGNAL(send_num_activities(uint)),saver, SLOT(pending_activities(uint)));
//    w.showFullScreen();
    w.show();



    return a.exec();
}
