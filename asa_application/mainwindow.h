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
#include "bitacora.h"
#include "rutinas_mantenimiento.h"

#include "mod_1_carcamo.h"
#include "mod_2_reactor.h"
#include "mod_3_clarificador.h"
#include "mod_4_clorador.h"
#include "mod_5_digestor.h"
#include "mod_6_lechos.h"
#include "mod_flechas.h"
#include "dataproccess.h"
#include "graphwindow.h"
#include "login_dialog.h"
#include "simulation_input.h"
#include "motores.h"
#include "filtrowindow.h"
#include "change_text.h"
#include "contacto.h"
#include "earm_update.h"

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

    static configuration_id conf_afluente_elect;
    static configuration_id conf_afluente_fisic;
    static configuration_id conf_afluente_quimi;

    static configuration_id conf_efluente_elect;
    static configuration_id conf_efluente_fisic;
    static configuration_id conf_efluente_quimi;

    static configuration_id conf_filtro_elect;
    static configuration_id conf_filtro_fisic;
    static configuration_id conf_filtro_quimi;

    static configuration_id conf_filtro_bomba_elect;
    static configuration_id conf_filtro_bomba_fisic;
    static configuration_id conf_filtro_bomba_quimi;

    static configuration_id reg_outputs;
    static configuration_id react_outputs;
    static configuration_id clarif_outputs;
    static configuration_id clora_outputs;
    static configuration_id digest_outputs;
    static configuration_id deshid_outputs;
    static configuration_id afluente_outputs;
    static configuration_id efluente_outputs;
    static configuration_id filtro_outputs;
    static configuration_id filtro_bomba_outputs;

    static int reg_op_mode;
    static int reg_mot_1;
    static int reg_mot_2;

    static QString ASA_conf_only_string;
    static QString ASA_conf_string;

    rutinas_mantenimiento *rutinas;

    DataProccess *dataObj;
    graphwindow *graph = NULL;

    static bool simulation;
    static QDateTime time;

    bool filtro_present = false;

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
    void handleDetailedView_7();
    void handleDetailedView_8();
    void handleDetailedView_9();

    void update_this();

private slots:
    void on_asa_logo_clicked();
    void dataTimerSlot();

    void on_top_menu_5_clicked();


    void on_top_menu_2_clicked();

    void new_spi_data();

//    void on_pb_simulacion_clicked();

    void on_top_menu_6_clicked();

    void on_prof_pic_clicked();

    void on_go_to_filtro_clicked();
    void update_buttons_from_filter(bool active, parameters_t param);
    void update_title(QString text);

    void on_label_title_clicked();
    void check_title_click();

    void window_closed();
private:
    QTimer dataTimer;
    uint title_click_count = 0;

    Ui::MainWindow *ui;
    bool display_parameters;

    /* Windows */
    detailedwindow *detail_window = NULL;
    settings    *settingswindow = NULL;
    bitacora    *bitacorawindow = NULL;
    login_dialog *login_d = NULL;

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
    QString my_name;

    custom_tooltip *tool_tip_clarificador_electricos;
    custom_tooltip *tool_tip_clarificador_fisicos;
    custom_tooltip *tool_tip_clarificador_quimicos;


    custom_tooltip *tool_tip_clorador_electricos;
    custom_tooltip *tool_tip_clorador_fisicos;
    custom_tooltip *tool_tip_clorador_quimicos;

    custom_tooltip *tool_tip_digestor_electricos;
    custom_tooltip *tool_tip_digestor_fisicos;
    custom_tooltip *tool_tip_digestor_quimicos;

    custom_tooltip *tool_tip_deshidratador_electricos;
    custom_tooltip *tool_tip_deshidratador_fisicos;
    custom_tooltip *tool_tip_deshidratador_quimicos;

    custom_tooltip *tool_tip_afluente_electricos;
    custom_tooltip *tool_tip_afluente_fisicos;
    custom_tooltip *tool_tip_afluente_quimicos;

    custom_tooltip *tool_tip_efluente_electricos;
    custom_tooltip *tool_tip_efluente_fisicos;
    custom_tooltip *tool_tip_efluente_quimicos;

//    custom_tooltip *tool_tip_filtro_electricos;
//    custom_tooltip *tool_tip_filtro_fisicos;
//    custom_tooltip *tool_tip_filtro_quimicos;

//    void get_ASA_string(void);
//    void update_ASA_string(void);
    void update_tooltips(void);

    void trace_lines(QWidget *tooltip, QPushButton *module, QPainter &painter);

    mod_1_carcamo *mod_1;
    mod_2_reactor *mod_2;
    mod_3_clarificador *mod_3;
    mod_4_clorador *mod_4;
    mod_5_digestor *mod_5;
    mod_6_lechos *mod_6;
    mod_flechas *mod_afluente;
    mod_flechas *mod_efluente;
    mod_flechas *mod_sludge_a;
    mod_flechas *mod_sludge_b;
    mod_flechas *mod_water_flown_a;
    mod_flechas *mod_sludge_return;

    mod_flechas *mod_blower_1;
    mod_flechas *mod_blower_2;
    mod_flechas *mod_blower_3;
    mod_flechas *mod_blower_4;

    mod_flechas *mod_bomba_1;
    mod_flechas *mod_bomba_2;
    mod_flechas *mod_bomba_3;
    mod_flechas *mod_bomba_4;

    void update_system_time();

    void check_lock();
    QString build_date_string(QDateTime);

    simulation_input *sim_window = NULL;
    motores *motrores_window = NULL;
    filtrowindow *filt_window = NULL;
    change_text *change_text_window = NULL;

    contacto *contacto_window = NULL;

    QMutex mutex_detailed;
    uint timer_count = 0;
    uint element_detail = 0;

    earm_update *update_window = NULL;
    bool update_in_progress = false;
protected:
    void paintEvent(QPaintEvent *);
};


#endif // MAINWINDOW_H
