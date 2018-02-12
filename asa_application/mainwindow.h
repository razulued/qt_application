#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "detailedwindow.h"
#include "multistatebutton.h"
#include "parameters.h"


namespace Ui {
class MainWindow;
}

typedef enum
{
    PARAMETER_NORMAL,
    PARAMETER_NORMAL_SELECTED,
    PARAMETER_WARNING,
    PARAMETER_FAILED
}parameter_state_t;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateTooltips();

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

private slots:
    void on_asa_logo_clicked();
    void dataTimerSlot();

private:
    QTimer dataTimer;

    Ui::MainWindow *ui;
    bool display_parameters;
    detailedwindow *detail_window;
    void HideButtons(bool show);
    parameter_state_t electric_state;
    parameter_state_t chemic_state;
    parameter_state_t physic_state;
};

#endif // MAINWINDOW_H
