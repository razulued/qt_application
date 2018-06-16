#include "mainwindow.h"
#include <QApplication>
#include "build_settings.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("asa_application");
    a.setApplicationVersion("1.0");
    a.setOrganizationName("HGM - Luis Ramirez");
    a.setOrganizationDomain("none");
    MainWindow w;

    w.setObjectName("MyMainWindow");
//    w.setStyleSheet("MainWindow#MyMainWindow{background-image:url(:/images/images/main_window_background.jpg)}");
    w.setStyleSheet("MainWindow#MyMainWindow{background-color:black}");
    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);

#if (1 == RELEASE_FOR_RPI)
    QApplication::setOverrideCursor(Qt::BlankCursor);
#endif

    w.showFullScreen();
//    w.show();



    return a.exec();
}
