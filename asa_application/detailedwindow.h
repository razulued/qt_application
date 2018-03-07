#ifndef DETAILEDWINDOW_H
#define DETAILEDWINDOW_H

#include <QDialog>
#include <QtCore>
#include "configuration.h"

typedef enum
{
    ELEMENT_REGULADOR,
    ELEMENT_REACTOR,
    ELEMENT_CLARIFICADOR,
    ELEMENT_CLORADOR,
    ELEMENT_DIGESTOR,
    ELEMENT_DESHIDRATADOR
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
    explicit detailedwindow(detailed_elements_t element, QWidget *parent = 0);
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

private:
    Ui::detailedwindow *ui;
    detailed_elements_t what_element;
};

#endif // DETAILEDWINDOW_H
