#ifndef CALENDARIO_FILTRO_H
#define CALENDARIO_FILTRO_H

#include <QDialog>
#include "calendar.h"

namespace Ui {
class calendario_filtro;
}

class calendario_filtro : public QDialog
{
    Q_OBJECT

public:
    explicit calendario_filtro(QWidget *parent = 0);
    ~calendario_filtro();

private slots:
    void on_close_clicked();

    void background_clicked();
    void on_fecha_inicio_btn_clicked();

    void on_fecha_fin_btn_clicked();

    void registros_filter_init_date(uint hora, QDate date);
    void registros_filter_end_date(uint hora, QDate date);
    void on_ok_button_clicked();

private:
    Ui::calendario_filtro *ui;

    calendar * calendar_window = NULL;
    uint filtro_fecha_inicio = 0;
    uint filtro_fecha_fin = 0;
signals:
    void send_fechas(uint ini, uint end);
};

#endif // CALENDARIO_FILTRO_H
