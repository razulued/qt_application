#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDialog>
#include <QPen>
#include <QGraphicsEllipseItem>
#include <QLabel>

#define OD_IN   (0x4307)
#define SST_IN  (0x3305)
#define Turb_IN (0x3303)
#define PH_IN   (0x3301)

#define OD_OUT   (0x6307)
#define SST_OUT  (0x6305)
#define Turb_OUT (0x6303)
#define PH_OUT   (0x6301)

#define GASTO_INS  (0x3203)
#define GASTO_ACC  (0x4203)
#define NIVEL_REG  (0x3201)
#define NIVEL_CL   (0x5201)
#define PRES_AIR   (0x4205)
#define PRES_FIL   (0x8205)

#define Filtro_OD_IN   (0xFFFF)
#define Filtro_SST_IN  (0x9305)
#define Filtro_Turb_IN (0x9303)
#define Filtro_PH_IN   (0xFFFF)

#define Filtro_OD_OUT   (0xFFFF)
#define Filtro_SST_OUT  (0x9315)
#define Filtro_Turb_OUT (0x9313)
#define Filtro_PH_OUT   (0xFFFF)

#define Filtro_GASTO_INS  (0xFFFF)
#define Filtro_GASTO_ACC  (0xFFFF)
#define Filtro_NIVEL_REG  (0x9201)
#define Filtro_NIVEL_CL   (0xFFFF)
#define Filtro_PRES_AIR   (0xFFFF)
#define Filtro_PRES_FIL   (0xFFFF)

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
    void set_type(QString type);

    static uint g_OD_IN;
    static uint g_SST_IN;
    static uint g_Turb_IN;
    static uint g_PH_IN;

    static uint g_OD_OUT;
    static uint g_SST_OUT;
    static uint g_Turb_OUT;
    static uint g_PH_OUT;

    static uint g_GASTO_INS;
    static uint g_GASTO_ACC;
    static uint g_NIVEL_REG;
    static uint g_NIVEL_CL;
    static uint g_PRES_AIR;
    static uint g_PRES_FIL;
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
    void update_graph_seconds(uint param);
    void update_graph_minutes(uint param);
    void update_graph_hour(uint param);

    qreal adjusted_y_value(qreal val);

    uint element_type = 0;
    qreal min_value = 0;
    qreal max_value = 0;

    void color_to_label(uint parameter);

    uint index_of_motor();
    QString graph_origin;
};

#endif // GRAPHWINDOW_H
