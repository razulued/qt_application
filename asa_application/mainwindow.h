#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "detailedwindow.h"
#include "multistatebutton.h"
#include "parameters.h"
#include "settings.h"
#include "custom_tooltip.h"
#include "configuration.h"

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
    void InitTooltips();

    static configuration_id conf_reg_elect;
    static configuration_id conf_reg_fisic;
    static configuration_id conf_reg_quimic;

    static configuration_id conf_react_elect;
    static configuration_id conf_react_fisic;
    static configuration_id conf_react_quimi;

    static configuration_id conf_clarif_elect;
    static configuration_id conf_clarif_fisic;
    static configuration_id conf_clarif_quimi;

    static configuration_id conf_clora_elect;
    static configuration_id conf_clora_fisic;
    static configuration_id conf_clora_quimi;

    static configuration_id conf_digest_elect;
    static configuration_id conf_digest_fisic;
    static configuration_id conf_digest_quimi;

    static configuration_id conf_deshid_elect;
    static configuration_id conf_deshid_fisic;
    static configuration_id conf_deshid_quimi;

    static configuration_id reg_outputs;
    static configuration_id react_outputs;
    static configuration_id clarif_outputs;
    static configuration_id clora_outputs;
    static configuration_id digest_outputs;
    static configuration_id deshid_outputs;

    static int reg_op_mode;
    static int reg_mot_1;
    static int reg_mot_2;

    static QString ASA_conf_only_string;
    static QString ASA_conf_string;

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

    void on_top_menu_4_clicked();

private:
    QTimer dataTimer;

    Ui::MainWindow *ui;
    bool display_parameters;
    detailedwindow *detail_window;
    settings    *settingswindow;
    void HideButtons(bool show);
    parameter_state_t electric_state;
    parameter_state_t chemic_state;
    parameter_state_t physic_state;
    bool init_complete = false;


    custom_tooltip *tool_tip_regulador_electricos;
    custom_tooltip *tool_tip_regulador_fisicos;
    custom_tooltip *tool_tip_regulador_quimicos;

    custom_tooltip *tool_tip_reactor_electricos;
    custom_tooltip *tool_tip_reactor_fisicos;
    custom_tooltip *tool_tip_reactor_quimicos;


    custom_tooltip *tool_tip_clarificador_electricos;
    custom_tooltip *tool_tip_clarificador_fisicos;
    custom_tooltip *tool_tip_clarificador_quimicos;


    custom_tooltip *tool_tip_clorador_electricos;
    custom_tooltip *tool_tip_clorador_fisicos;
    custom_tooltip *tool_tip_clorador_quimicos;

    void get_ASA_string(void);
    void update_ASA_string(void);

    void trace_lines(QWidget *tooltip, QPushButton *module, QPainter &painter);


protected:
    void paintEvent(QPaintEvent *);

};


#endif // MAINWINDOW_H
