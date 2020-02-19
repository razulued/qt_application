#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QMutex>
#include <QPointer>

#include "socket_client.h"
#include "screens/detailedwindow.h"

#include "rutinas_mantenimiento.h" //TODO remove this


namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(socket_client *socket, QWidget *parent = 0);
    ~MainMenu();

private slots:
    void on_launch_view1_clicked();

    void on_launch_view2_clicked();

    void on_launch_view3_clicked();

    void on_launch_view4_clicked();

    void detailed_closed();

    void create_detailed_window(int element);
private:
    Ui::MainMenu *ui;

    void main_view_init();
    void filtro_view_init();

    socket_client *socket;

    QMutex mutex_detailed;

    detailedwindow *detail_window = NULL;

    rutinas_mantenimiento *rutinas;

    void graph_demo_init();

};

#endif // MAINMENU_H
