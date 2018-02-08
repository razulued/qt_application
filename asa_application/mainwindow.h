#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "detailedwindow.h"
#include "multistatebutton.h"


namespace Ui {
class MainWindow;
}

typedef enum
{
    E_PARAMETROS_ELECTRICOS,
    E_PARAMETROS_FISICOS,
    E_PARAMETROS_QUIMICOS
}t_parameters;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void HandleParameterChange(t_parameters param);
    t_parameters selected_parameter;;

    /* Parameter buttons */
    MultiStateButton *physical_param_button;
    MultiStateButton *chemical_param_button;
    MultiStateButton *electrical_param_button;

    QPushButton *button_main_menu;

public slots:
    void handleMenuButton();
    void handleParametrosElectricosButton();
    void handleParametrosFisicosButton();
    void handleParametrosQuimicosButton();
    void handleDetailedView_1();
    void handleDetailedView_2();
    void handleDetailedView_3();
    void handleDetailedView_4();
    void handleDetailedView_5();
    void handleDetailedView_6();

private:
    Ui::MainWindow *ui;
    bool display_parameters;
    detailedwindow *detail_window;
    void HideButtons(bool show);
    void InitButtons();
};

#endif // MAINWINDOW_H
