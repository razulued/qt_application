#ifndef BITACORA_H
#define BITACORA_H

#include <QDialog>
#include <QtCore>
#include <QTableWidgetItem>
#include "rutinas_mantenimiento.h"
#include "calendar.h"
#include "calendario_filtro.h"
#include "record_chart.h"

namespace Ui {
class bitacora;
}

class bitacora : public QDialog
{
    Q_OBJECT

public:
    explicit bitacora(rutinas_mantenimiento *rutina, QWidget *parent = 0);
    ~bitacora();

    void update_table(void);

private slots:
    void on_top_menu_3_clicked();

    void item_selected(QTableWidgetItem *item);
    void item_selected_all(QTableWidgetItem *item);
    void item_selected_registros(QTableWidgetItem *item);

    void on_key_Reschedule_clicked();

    void on_key_OK_clicked();

    void on_top_menu_2_clicked();

    void receive_date(uint hora, QDate date);
    void update_datetime(QDateTime datetime);

    void on_key_Reschedule_2_clicked();

    void on_log_button_clicked();

    void on_clear_filters_clicked();

    void on_filtro_fecha_clicked();

    void filtro_fecha_received(uint ini, uint end);
    void on_filtro_record_clicked();

    void on_graph_button_clicked();

private:
    Ui::bitacora *ui;
    void init_tables(void);
    void init_full_table(void);
    void update_full_table(void);
    void init_registros_table();
    void update_registros_table();
    void init_active_table(void);
    void update_active_table(void);
    void add_row_rutina(uint row, uint rutina, QTableWidget *table);
    void delete_row(uint row, QTableWidget *table);


    uint selected_id = 0;
    uint selected_record = 0;

    bool init_completed = false;

    rutinas_mantenimiento *rutina_ptr;

    enum
    {
        ID, NOMBRE, PERIODO, LAST, NEXT, ORIGEN,
    };

    enum
    {
        BASE_SEC, BASE_MIN, BASE_HOUR, BASE_DAY, BASE_LAST
    };


    calendar * calendar_window = NULL;
    uint reschedule_time;

    void add_row_registro(QString sql_query, QTableWidget *table);
    uint filtro_fecha_inicio = 0;
    uint filtro_fecha_fin = 0;

    calendario_filtro * calendario_window = NULL;
    record_chart * chart_window = NULL;
signals:
    void release_lock();

};

#endif // BITACORA_H
