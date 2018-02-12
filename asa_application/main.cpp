#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setObjectName("MyMainWindow");
//    w.setStyleSheet("MainWindow#MyMainWindow{background-image:url(:/images/images/main_window_background.jpg)}");
    w.setStyleSheet("MainWindow#MyMainWindow{background-color:black}");
    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
    //w.showFullScreen();
    w.show();



    return a.exec();
}
