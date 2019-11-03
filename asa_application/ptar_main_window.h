#ifndef PTAR_MAIN_WINDOW_H
#define PTAR_MAIN_WINDOW_H

#include <QDialog>
#include <QMutex>
#include <QPointer>

#include "socket_client.h"
#include "screens/detailedwindow.h"

#include "rutinas_mantenimiento.h" //TODO remove this

namespace Ui {
class ptar_main_window;
}

class ptar_main_window : public QDialog
{
    Q_OBJECT

public:
    explicit ptar_main_window(socket_client *socket, QWidget *parent = 0);
    ~ptar_main_window();

private slots:
    void on_launch_view1_clicked();

    void on_launch_view2_clicked();

    void on_launch_view3_clicked();

    void on_launch_view4_clicked();

    void detailed_closed();

    void detailed_window_carcamo();
    void create_detailed_window(int element);
private:
    Ui::ptar_main_window *ui;

    void main_view_init();

    socket_client *socket;

    QMutex mutex_detailed;

    detailedwindow *detail_window = NULL;

    rutinas_mantenimiento *rutinas;

};

#endif // PTAR_MAIN_WINDOW_H
