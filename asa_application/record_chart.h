#ifndef RECORD_CHART_H
#define RECORD_CHART_H

#include <QDialog>
#include "calendario_filtro.h"

namespace Ui {
class record_chart;
}

class record_chart : public QDialog
{
    Q_OBJECT

public:
    explicit record_chart(uint record_id, uint inicio, uint final, QWidget *parent = 0);
    ~record_chart();

private:
    Ui::record_chart *ui;
    void update_pie_chart(uint id, uint fecha_inicio, uint fecha_fin);
    void update_bar_chart(uint id, uint fecha_inicio, uint fecha_fin);

    uint rec_id;
    QString type;
    QString choice_field_1_text;
    QString choice_field_2_text;
    QString choice_field_3_text;
    QString number_field_1_text;
    uint last_inicio;
    uint last_final;

    calendario_filtro * calendario_window = NULL;
private slots:
    void background_clicked();
    void on_filtro_fecha_clicked();
    void filtro_fecha_received(uint ini, uint end);
    void on_radioButton_toggled(bool checked);
};

#endif // RECORD_CHART_H
