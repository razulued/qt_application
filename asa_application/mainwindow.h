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

#include "mod_1_carcamo.h"
#include "mod_1_regulador.h"
#include "mod_2_reactor.h"
#include "mod_3_clarificador.h"
#include "mod_4_clorador.h"
#include "mod_5_digestor.h"
#include "mod_6_lechos.h"
#include "mod_flechas.h"
#include "dataproccess.h"
#include "login_dialog.h"
#include "simulation_input.h"
#include "change_text.h"
#include "contacto.h"
#include "earm_update.h"
#include "stop_button.h"
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

    static configuration_id conf_press_elect;
    static configuration_id conf_press_fisic;
    static configuration_id conf_press_quimic;

    static configuration_id car_outputs;


    static QString ASA_conf_only_string;
    static QString ASA_conf_string;

    static bool demo_mode_enabled;

    DataProccess *dataObj;

    static bool simulation;
    static QDateTime time;


    static uint num_of_pending_act;

public slots:
    void handleMenuButton();
    void handleParametrosElectricosButton();
    void handleParametrosFisicosButton();
    void handleParametrosQuimicosButton();
    void handleDetailedView_9();

    void update_this();

private slots:
    void on_asa_logo_clicked();
    void dataTimerSlot();




    void new_spi_data();

//    void on_pb_simulacion_clicked();

    void on_prof_pic_clicked();

    void update_title(QString text);

    void on_label_title_clicked();
    void check_title_click();

    void window_closed();
    void update_demo_mode();


private:
    QTimer dataTimer;
    uint title_click_count = 0;

    Ui::MainWindow *ui;
    bool display_parameters;

    /* Windows */
    detailedwindow *detail_window = NULL;
    settings    *settingswindow = NULL;
    login_dialog *login_d = NULL;

    void HideButtons(bool show);
    parameter_state_t electric_state;
    parameter_state_t chemic_state;
    parameter_state_t physic_state;
    bool init_complete = false;

    custom_tooltip *tool_tip_carcamo_electricos;
    custom_tooltip *tool_tip_carcamo_fisicos;
    custom_tooltip *tool_tip_carcamo_quimicos;

    QString my_name;


    void update_tooltips(void);

    void trace_lines(QWidget *tooltip, QPushButton *module, QPainter &painter);

    void update_system_time();

    void check_lock();
    QString build_date_string(QDateTime);

    simulation_input *sim_window = NULL;
    change_text *change_text_window = NULL;

    contacto *contacto_window = NULL;

    QMutex mutex_detailed;
    uint timer_count = 0;
    uint element_detail = 0;

    earm_update *update_window = NULL;
    bool update_in_progress = false;

    stop_button *stop_button_window = NULL;

    QRect level_label_size;
protected:
    void paintEvent(QPaintEvent *);

signals:
    void send_date_hour(QDateTime date_time);
    void send_num_activities(uint act);
};


#endif // MAINWINDOW_H
