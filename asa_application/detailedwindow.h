#ifndef DETAILEDWINDOW_H
#define DETAILEDWINDOW_H

#include <QDialog>
#include <QtCore>
#include "configuration.h"
#include "rutinas_mantenimiento.h"
#include <QTableWidgetItem>
#include "login_dialog.h"
#include <QCheckBox>
#include "calendar.h"
#include <QMutex>

typedef enum
{
    ELEMENT_REGULADOR,
    ELEMENT_REACTOR,
    ELEMENT_CLARIFICADOR,
    ELEMENT_CLORADOR,
    ELEMENT_DIGESTOR,
    ELEMENT_DESHIDRATADOR,
    ELEMENT_AFLUENTE,
    ELEMENT_EFLUENTE,
    ELEMENT_FILTRO,
    ELEMENT_FILTRO_BOMBA,
    ELEMENT_CARCAMO,
}detailed_elements_t;

typedef struct
{
    QString name;
    QString image;
    QString description;
    configuration_id *list_elect;
    configuration_id *list_phys;
    configuration_id *list_chem;
    configuration_id *out_config;

}detailed_window_elements_t;

namespace Ui {
class detailedwindow;
}

class detailedwindow : public QDialog
{
    Q_OBJECT

public:
    explicit detailedwindow(detailed_elements_t element, rutinas_mantenimiento *rutina, QWidget *parent = 0);
    ~detailedwindow();
    void update_params();
    static bool user_lock;
    bool init_completed = false;
    QMutex mutex;

private slots:
    void on_closeButton_clicked();

    void on_button_parametros_clicked();

    void on_button_evento_clicked();

    void on_button_descripcion_clicked();

    void on_button_visualizacion_clicked();

    void checkBoxStateChanged(int);

    void out_checkBoxStateChanged(int);

    void on_button_control_clicked();

    void on_key_0_clicked();
    void on_key_1_clicked();
    void on_key_2_clicked();
    void on_key_3_clicked();
    void on_key_4_clicked();
    void on_key_5_clicked();
    void on_key_6_clicked();
    void on_key_7_clicked();
    void on_key_8_clicked();
    void on_key_9_clicked();
    void on_key_back_clicked();

    void on_key_Reschedule_clicked();
    void item_selected(QTableWidgetItem*);

    void on_key_OK_clicked();

    void on_ayuda_btn_clicked();

    void on_key_Q_clicked();
    void on_key_W_clicked();
    void on_key_E_clicked();
    void on_key_R_clicked();
    void on_key_T_clicked();
    void on_key_Y_clicked();
    void on_key_U_clicked();
    void on_key_I_clicked();
    void on_key_O_clicked();
    void on_key_P_clicked();
    void on_key_A_clicked();
    void on_key_S_clicked();
    void on_key_D_clicked();
    void on_key_F_clicked();
    void on_key_G_clicked();
    void on_key_H_clicked();
    void on_key_J_clicked();
    void on_key_K_clicked();
    void on_key_L_clicked();
    void on_key_Z_clicked();
    void on_key_X_clicked();
    void on_key_C_clicked();
    void on_key_V_clicked();
    void on_key_B_clicked();
    void on_key_N_clicked();
    void on_key_M_clicked();


    void on_key_comma_clicked();

    void on_key_space_clicked();

    void on_key_enter_clicked();

    void on_textEdit_selectionChanged();


    void on_key_dot_clicked();

    void on_key_plus_clicked();

    void on_key_minus_clicked();

    void on_key_slash_clicked();

    void background_clicked();

    void on_filtro_fisicos_clicked();

    void on_filtro_quimicos_clicked();

    void on_filtro_electricos_clicked();

    void checkActivity();

    void receive_date(uint hora, QDate date, QDateTime datetime);

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_pressed();

    void on_pushButton_released();

    void checkStop();
    void checkStop_modulo();

    void on_pushButton_modulo_pressed();

    void on_pushButton_modulo_released();

    void on_pushButton_modulo_clicked();

private:
    Ui::detailedwindow *ui;
    detailed_elements_t what_element;
    uint selected_id;
    rutinas_mantenimiento *rutinas_ptr;

    uint reschedule_time;


    uint origentype;

    void tab_1_init(uint selected_type);
    uint type_to_update;

    void tab_2_init();
    void tab_3_init();
    void tab_4_init();
    void tab_5_init();

    void tab_1_update();
    void tab_2_update();
    void tab_3_update();
    void tab_4_update();
    void tab_5_update();

    void delete_row(uint row, QTableWidget *table);
    void add_row_rutina(uint row, uint rutina, QTableWidget *table);

    login_dialog *login_d = NULL;
    void check_lock();

    bool has_output_control = false;

    bool has_activity = false;
    QCheckBox* controls_ptr[10];

    calendar *calendar_window = NULL;

    void set_op_mode(uint mode);
    void read_op_mode();

    uint mode_4600 = 0;

    bool wating_timer = false;
    bool stop_pressed = false;
    void stop_button_animation(bool state);

    bool wating_timer_modulo = false;
    bool stop_pressed_modulo = false;
    void stop_button_animation_module(bool state);
    bool stop_op_mode();

    void save_stop_status(uint mode);

    enum
    {
        CONTROL_STOP = 0,
        CONTROL_AUTOMATICO = 1,
        CONTROL_MANUAL = 2
    };
signals:
    void release_lock();

protected slots:
    void activity_is_completed(uint id);
};

#endif // DETAILEDWINDOW_H
