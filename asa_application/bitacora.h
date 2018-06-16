#ifndef BITACORA_H
#define BITACORA_H

#include <QDialog>
#include <QtCore>
#include <QTableWidgetItem>
#include "rutinas_mantenimiento.h"
#include "calendar.h"

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

    void on_key_Reschedule_clicked();

    void on_key_OK_clicked();

    void on_top_menu_2_clicked();

    void receive_date(uint hora, QDate date);

private:
    Ui::bitacora *ui;
    void init_tables(void);
    void init_full_table(void);
    void update_full_table(void);
    void init_active_table(void);
    void update_active_table(void);
    void add_row_rutina(uint row, uint rutina, QTableWidget *table);
    void delete_row(uint row, QTableWidget *table);


    uint selected_id;
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


};

#endif // BITACORA_H
