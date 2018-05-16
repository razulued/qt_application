#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDialog>
#include <QPen>
#include <QGraphicsEllipseItem>

namespace Ui {
class graphwindow;
}

class graphwindow : public QDialog
{
    Q_OBJECT

public:
    explicit graphwindow(QWidget *parent = 0);
    ~graphwindow();

    void show_graph(uint type);
    void update_graph();


private slots:
    void on_top_menu_3_clicked();

    void on_volts_1_clicked();
    void on_volts_2_clicked();
    void on_volts_3_clicked();
    void on_amps_1_clicked();
    void on_amps_2_clicked();
    void on_amps_3_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pb_gasto_inst_clicked();

    void on_pb_gasto_acc_clicked();

    void on_pb_nivel_reg_clicked();

    void on_pb_nivel_clarif_clicked();

    void on_pb_presion_aire_clicked();

    void on_pb_presion_filt_clicked();

    void on_pb_OD_in_clicked();

    void on_pb_pH_in_clicked();

    void on_pb_SST_in_clicked();

    void on_pb_Turb_in_clicked();

    void on_pb_OD_out_clicked();

    void on_pb_pH_out_clicked();

    void on_pb_SST_out_clicked();

    void on_pb_Turb_out_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::graphwindow *ui;
    QPen pen;
    QPen pen2;
    QWidget *parent_window;
    uint parameter_to_graph;
    void draw_graph_line();
    void draw_end_ball(QGraphicsScene *scene, int x, int y);
    void draw_grill(QGraphicsScene *scene);
    void update_graph_window(uint param);
    qreal adjusted_y_value(qreal val);

    uint element_type = 0;
    qreal min_value = 0;
    qreal max_value = 0;
};

#endif // GRAPHWINDOW_H
