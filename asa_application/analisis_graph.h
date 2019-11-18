#ifndef ANALISIS_GRAPH_H
#define ANALISIS_GRAPH_H

#include <QDialog>

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

private slots:
    void on_start_test_clicked();
    void analysis_sm(void);
private:
    Ui::analisis_graph *ui;
    en_analysis_state analysis_state = AN_IDLE;
    void capture_data(int round);
    void clear_data_lists();
};

#endif // ANALISIS_GRAPH_H
