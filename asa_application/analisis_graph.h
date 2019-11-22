#ifndef ANALISIS_GRAPH_H
#define ANALISIS_GRAPH_H

#include <QDialog>
#include "curve_chart.h"
#include "date_widget.h"
#include <QDateTime>
typedef enum
{
    AN_IDLE,
    AN_PAUSE,
    AN_IN_PROGRESS,
    AN_STOP_ALL_MODULES,
    AN_ENTER_MANUAL_MODE,
    AN_TURN_ON_PUMP,
    AN_MOVE_VALVE,
    AN_TAKE_READING,
    AN_TURN_OFF_PUMP,
    AN_COMPLETE
}en_analysis_state;
namespace Ui {
class analisis_graph;
}

class analisis_graph : public QDialog
{
    Q_OBJECT

public:
    explicit analisis_graph(QWidget *parent = 0);
    ~analisis_graph();
    void start_analysis(void);

signals:
    void send_datetime(QDateTime datetime);

private slots:
    void on_start_test_clicked();
    void analysis_sm(void);
    void on_graph_button_clicked();
    void update_time(QDateTime datetime);
    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_checkBox_toggled(bool checked);

    void on_start_test_released();

private:
    Ui::analisis_graph *ui;
    en_analysis_state analysis_state = AN_IDLE;
    void capture_data(int round);
    void clear_data_lists();
    void select_data_and_graph();
    curve_chart *curve = NULL;
    date_widget *date_wid = NULL;
    QList<QList<float>> master_data;
    QList<float> index_to_data_list(int index);
    void analysis_sm_stop_all();
    void analysis_sm_enter_manual();
    void analysis_sm_toggle_pump();
};

#endif // ANALISIS_GRAPH_H
