#ifndef DETAILEDWINDOW_H
#define DETAILEDWINDOW_H

#include <QDialog>
#include <QtCore>
#include "configuration.h"
#include "rutinas_mantenimiento.h"
#include <QTableWidgetItem>

typedef enum
{
    ELEMENT_REGULADOR,
    ELEMENT_REACTOR,
    ELEMENT_CLARIFICADOR,
    ELEMENT_CLORADOR,
    ELEMENT_DIGESTOR,
    ELEMENT_DESHIDRATADOR,
    ELEMENT_AFLUENTE,
    ELEMENT_EFLUENTE
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

    void on_key_dot_clicked();

private:
    Ui::detailedwindow *ui;
    detailed_elements_t what_element;
    uint selected_id;
    rutinas_mantenimiento *rutinas_ptr;

    enum
    {
        BASE_SEC, BASE_MIN, BASE_HOUR, BASE_DAY, BASE_MON, BASE_LAST
    };

    uint add_base = BASE_HOUR;
    uint base_mult = 3600;
};

#endif // DETAILEDWINDOW_H
