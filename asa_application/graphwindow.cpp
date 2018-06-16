#include "graphwindow.h"
#include "ui_graphwindow.h"
#include <QGraphicsScene>
#include "statistics.h"
#include <QList>
#include <QBrush>
#include <QDebug>
#include "parameters.h"
#include <QMutex>
#include <QString>
#include <QScroller>
#include <QScrollerProperties>
QMutex g_mutex;

#define VAL_SEC_SEPARATION (ui->graphicsView->width()/60)
#define VAL_MIN_SEPARATION (ui->graphicsView_2->width()/60)
#define VAL_HOUR_SEPARATION (ui->graphicsView_3->width()/24)


#define VOLT_MAX (500)
#define VOLT_MIN (0)
#define AMP_MAX  (10)
#define AMP_MIN  (0)

enum
{
    TYPE_ELECTRICOS,
    TYPE_FISICOS,
    TYPE_QUIMICOS
};

enum
{
    CARCAMO_MOT_1,
    CARCAMO_MOT_2,
    CARCAMO_MOT_3,
    CARCAMO_MOT_4,
    REACTOR_MOT_1,
    REACTOR_MOT_2,
    REACTOR_MOT_3,
    REACTOR_MOT_4,
};

typedef struct
{
    QString name;
    uint param_state;

    uint param_v_fase_1;
    uint param_v_fase_2;
    uint param_v_fase_3;
    uint param_a_fase_1;
    uint param_a_fase_2;
    uint param_a_fase_3;
}g_elec_settings;

const g_elec_settings electric_graph_settings[] =
{
    /*                  name            state   V1      V2      V3      A1      A2      A6      */
    /* CARCAMO_MOT_1 */{"Carcamo 1",    0x3000, 0x3001, 0x3002, 0x3003, 0x3004, 0x3005, 0x3006,  },
    /* CARCAMO_MOT_2 */{"Carcamo 2",    0x3010, 0x3011, 0x3012, 0x3013, 0x3014, 0x3015, 0x3016,  },
    /* CARCAMO_MOT_3 */{"Carcamo 3",    0x3020, 0x3021, 0x3022, 0x3023, 0x3024, 0x3025, 0x3026,  },
    /* CARCAMO_MOT_4 */{"Carcamo 4",    0x3030, 0x3031, 0x3032, 0x3033, 0x3034, 0x3035, 0x3036,  },
    /* REACTOR_MOT_1 */{"Reactor 1",    0x4000, 0x4001, 0x4002, 0x4003, 0x4004, 0x4005, 0x4006,  },
    /* REACTOR_MOT_2 */{"Reactor 2",    0x4010, 0x4011, 0x4012, 0x4013, 0x4014, 0x4015, 0x4016,  },
    /* REACTOR_MOT_3 */{"Reactor 3",    0x4020, 0x4021, 0x4022, 0x4023, 0x4024, 0x4025, 0x4026,  },
    /* REACTOR_MOT_4 */{"Reactor 4",    0x4030, 0x4031, 0x4032, 0x4033, 0x4034, 0x4035, 0x4036,  },
    /* FILTRO_MOT_1  */{"Motor Giro",    0x9000, 0x9001, 0x9002, 0x9003, 0x9004, 0x9005, 0x9006,  },
    /* FILTRO_MOT_2  */{"Bomba Alim",    0x9010, 0x9011, 0x9012, 0x9013, 0x9014, 0x9015, 0x9016,  },
    /* FILTRO_MOT_3  */{"Bomba Retro",   0x9020, 0x9021, 0x9022, 0x9023, 0x9024, 0x9025, 0x9026,  },
    /* FILTRO_MOT_4  */{"Filtro 4",    0x9030, 0x9031, 0x9032, 0x9033, 0x9034, 0x9035, 0x9036,  },
};

uint graphwindow::g_OD_IN       = OD_IN;
uint graphwindow::g_SST_IN      = SST_IN;
uint graphwindow::g_Turb_IN     = Turb_IN;
uint graphwindow::g_PH_IN       = PH_IN;

uint graphwindow::g_OD_OUT      = OD_OUT;
uint graphwindow::g_SST_OUT     = SST_OUT;
uint graphwindow::g_Turb_OUT    = Turb_OUT;
uint graphwindow::g_PH_OUT      = PH_OUT;

uint graphwindow::g_GASTO_INS   = GASTO_INS;
uint graphwindow::g_GASTO_ACC   = GASTO_ACC;
uint graphwindow::g_NIVEL_REG   = NIVEL_REG;
uint graphwindow::g_NIVEL_CL    = NIVEL_CL ;
uint graphwindow::g_PRES_AIR    = PRES_AIR ;
uint graphwindow::g_PRES_FIL    = PRES_FIL ;

graphwindow::graphwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graphwindow)
{
    ui->setupUi(this);
    parent_window = parent;

    // ELECTRICOS
    this->setStyleSheet("background-color:black;");
    ui->label->setStyleSheet("color:white");
    ui->label_2->setStyleSheet(ui->label->styleSheet());
    ui->label_3->setStyleSheet(ui->label->styleSheet());
    ui->label_4->setStyleSheet(ui->label->styleSheet());
    ui->label_5->setStyleSheet(ui->label->styleSheet());
    ui->label_11->setStyleSheet(ui->label->styleSheet());
    ui->label_12->setStyleSheet(ui->label->styleSheet());
    ui->label_13->setStyleSheet(ui->label->styleSheet());

    ui->volts_1->setStyleSheet("color:white;"
                               "background-color: transparent;"
                               "border: none;"
                               "background-repeat: none;"
                               "background-position: center;");
    ui->volts_2->setStyleSheet(ui->volts_1->styleSheet());
    ui->volts_3->setStyleSheet(ui->volts_1->styleSheet());
    ui->amps_1->setStyleSheet(ui->volts_1->styleSheet());
    ui->amps_2->setStyleSheet(ui->volts_1->styleSheet());
    ui->amps_3->setStyleSheet(ui->volts_1->styleSheet());

    // FISICOS
    ui->label_14->setStyleSheet(ui->label->styleSheet());
    ui->label_15->setStyleSheet(ui->label->styleSheet());
    ui->label_16->setStyleSheet(ui->label->styleSheet());
    ui->label_17->setStyleSheet(ui->label->styleSheet());
    ui->label_18->setStyleSheet(ui->label->styleSheet());
    ui->label_19->setStyleSheet(ui->label->styleSheet());
    ui->label_20->setStyleSheet(ui->label->styleSheet());
    ui->label_21->setStyleSheet(ui->label->styleSheet());
    ui->label_22->setStyleSheet(ui->label->styleSheet());

    ui->pb_gasto_acc->setStyleSheet(ui->volts_1->styleSheet());
    ui->pb_gasto_inst->setStyleSheet(ui->volts_1->styleSheet());
    ui->pb_nivel_clarif->setStyleSheet(ui->volts_1->styleSheet());
    ui->pb_nivel_reg->setStyleSheet(ui->volts_1->styleSheet());
    ui->pb_presion_aire->setStyleSheet(ui->volts_1->styleSheet());
    ui->pb_presion_filt->setStyleSheet(ui->volts_1->styleSheet());

    // QUIMICOS
    ui->label_23->setStyleSheet(ui->label->styleSheet());
    ui->label_24->setStyleSheet(ui->label->styleSheet());
    ui->label_25->setStyleSheet(ui->label->styleSheet());
    ui->label_26->setStyleSheet(ui->label->styleSheet());
    ui->label_27->setStyleSheet(ui->label->styleSheet());
    ui->label_28->setStyleSheet(ui->label->styleSheet());
    ui->label_29->setStyleSheet(ui->label->styleSheet());
    ui->label_30->setStyleSheet(ui->label->styleSheet());
    ui->label_31->setStyleSheet(ui->label->styleSheet());
    ui->label_32->setStyleSheet(ui->label->styleSheet());
    ui->label_33->setStyleSheet(ui->label->styleSheet());

    ui->pb_OD_in->setStyleSheet(ui->volts_1->styleSheet());
    ui->pb_OD_out->setStyleSheet(ui->volts_1->styleSheet());
    ui->pb_pH_in->setStyleSheet(ui->volts_1->styleSheet());
    ui->pb_pH_out->setStyleSheet(ui->volts_1->styleSheet());
    ui->pb_SST_in->setStyleSheet(ui->volts_1->styleSheet());
    ui->pb_SST_out->setStyleSheet(ui->volts_1->styleSheet());
    ui->pb_Turb_in->setStyleSheet(ui->volts_1->styleSheet());
    ui->pb_Turb_out->setStyleSheet(ui->volts_1->styleSheet());


    QLinearGradient gradient(0,0,ui->graphicsView->width(),ui->graphicsView->height());
//    gradient.setColorAt(0, QColor::fromRgbF(0, 0, 0, 127));
    gradient.setColorAt(0, QColor::fromRgb(0, 167, 250,180));
//    gradient.setColorAt(0.7, QColor::fromRgb(0, 167, 250,255));
    gradient.setColorAt(0.8, QColor::fromRgb(255, 255, 255,255));
    gradient.setColorAt(0.9, QColor::fromRgb(255, 255, 255,0));

    QBrush brush(gradient);
//    QBrush brush(Qt::LinearGradientPattern);
    pen.setBrush(brush);
//        QColor line_color;
//        line_color.setRgb(0, 167, 250,150);
//        pen.setColor(line_color);
    pen.setWidth(5);

    ui->min_value->setStyleSheet("color: white;");
    ui->max_value->setStyleSheet("color: white;");
    ui->div_text->setStyleSheet("color: white;");


    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);


}

graphwindow::~graphwindow()
{
    delete ui;
}

void graphwindow::show_graph(uint type)
{
    g_mutex.lock();

    element_type = type;

    ui->comboBox->clear();
    // Init combo box for electric parameters
    uint i = 0;
    for(i = 0; i < (sizeof(electric_graph_settings)/sizeof(g_elec_settings)) ; i++)
    {
        if(3 != getParamValue(electric_graph_settings[i].param_state).toInt())
        {
            ui->comboBox->addItem(electric_graph_settings[i].name, i);
        }

    }
    switch(element_type)
    {
    case TYPE_ELECTRICOS:
        ui->top_bar->setStyleSheet("background-image: url(:/barras/screen800x600/barras/Parametros electricos.png);");
        parameter_to_graph = electric_graph_settings[0].param_v_fase_1;
        ui->label_graph->setText("Voltaje L1-L2");

        break;
    case TYPE_FISICOS:
        ui->top_bar->setStyleSheet("background-image: url(:/barras/screen800x600/barras/Parametros fisicos.png);");
        if("PTAR" == graph_origin)
        {
            parameter_to_graph = g_GASTO_INS;
            ui->label_graph->setText("Gasto Instantáneo");
        }
        else
        {
            parameter_to_graph = g_NIVEL_REG;
            ui->label_graph->setText("Filtro");
        }

        break;
    case TYPE_QUIMICOS:
        ui->top_bar->setStyleSheet("background-image: url(:/barras/screen800x600/barras/Parametros quimicos.png);");
        if("PTAR" == graph_origin)
        {
            parameter_to_graph = g_OD_IN;
            ui->label_graph->setText("OD entrada");
        }
        else
        {
            parameter_to_graph = g_SST_IN;
            ui->label_graph->setText("SST entrada");
        }
        break;

    }
    g_mutex.unlock();
    color_to_label(parameter_to_graph);
    ui->tabWidget->setCurrentIndex(element_type);

    this->move(parent_window->pos());
    this->show();
}

void graphwindow::update_graph()
{
    uint index_motor = index_of_motor();
    switch(ui->tabWidget->currentIndex())
    {
    case TYPE_ELECTRICOS:

        // electricos
        ui->volts_1->setText(get_last_value_from_param(electric_graph_settings[index_motor].param_v_fase_1));
        ui->volts_2->setText(get_last_value_from_param(electric_graph_settings[index_motor].param_v_fase_2));
        ui->volts_3->setText(get_last_value_from_param(electric_graph_settings[index_motor].param_v_fase_3));

        ui->amps_1->setText(get_last_value_from_param(electric_graph_settings[index_motor].param_a_fase_1));
        ui->amps_2->setText(get_last_value_from_param(electric_graph_settings[index_motor].param_a_fase_2));
        ui->amps_3->setText(get_last_value_from_param(electric_graph_settings[index_motor].param_a_fase_3));
        break;
        // fisicos
    case TYPE_FISICOS:
        ui->pb_gasto_inst->setText(get_last_value_from_param(g_GASTO_INS));
        ui->pb_gasto_acc->setText(get_last_value_from_param(g_GASTO_ACC));

        ui->pb_nivel_clarif->setText(get_last_value_from_param(g_NIVEL_CL));
        ui->pb_nivel_reg->setText(get_last_value_from_param(g_NIVEL_REG));

        ui->pb_presion_aire->setText(get_last_value_from_param(g_PRES_AIR));
        ui->pb_presion_filt->setText(get_last_value_from_param(g_PRES_FIL));
        break;
        // quimicos
    case TYPE_QUIMICOS:
        ui->pb_OD_in->setText(get_last_value_from_param(g_OD_IN));
        ui->pb_OD_out->setText(get_last_value_from_param(g_OD_OUT));
        ui->pb_pH_in->setText(get_last_value_from_param(g_PH_IN));
        ui->pb_pH_out->setText(get_last_value_from_param(g_PH_OUT));
        ui->pb_SST_in->setText(get_last_value_from_param(g_SST_IN));
        ui->pb_SST_out->setText(get_last_value_from_param(g_SST_OUT));
        ui->pb_Turb_in->setText(get_last_value_from_param(g_Turb_IN));
        ui->pb_Turb_out->setText(get_last_value_from_param(g_Turb_OUT));
        break;
    }

    update_graph_window(parameter_to_graph);
}

void graphwindow::on_top_menu_3_clicked()
{
    this->close();
}

void graphwindow::on_volts_1_clicked()
{
    g_mutex.lock();
    parameter_to_graph = electric_graph_settings[index_of_motor()].param_v_fase_1;
    g_mutex.unlock();

    ui->label_graph->setText("Voltaje L1-L2");
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_volts_2_clicked()
{
    g_mutex.lock();
    parameter_to_graph = electric_graph_settings[index_of_motor()].param_v_fase_2;
    g_mutex.unlock();

    ui->label_graph->setText("Voltaje L2-L3");
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_volts_3_clicked()
{
    g_mutex.lock();
    parameter_to_graph = electric_graph_settings[index_of_motor()].param_v_fase_3;
    g_mutex.unlock();

    ui->label_graph->setText("Voltaje L3-L1");
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_amps_1_clicked()
{
    g_mutex.lock();
    parameter_to_graph = electric_graph_settings[index_of_motor()].param_a_fase_1;
    g_mutex.unlock();

    ui->label_graph->setText("Amps L1-L2");
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_amps_2_clicked()
{
    g_mutex.lock();
    parameter_to_graph = electric_graph_settings[index_of_motor()].param_a_fase_2;
    g_mutex.unlock();

    ui->label_graph->setText("Amps L2-L1");
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_amps_3_clicked()
{
    g_mutex.lock();
    parameter_to_graph = electric_graph_settings[index_of_motor()].param_a_fase_3;
    g_mutex.unlock();

    ui->label_graph->setText("Amps L3-L1");
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::update_graph_window(uint param)
{
    update_graph_seconds(param);
    update_graph_minutes(param);
    update_graph_hour(param);
}

void graphwindow::update_graph_seconds(uint param)
{
    int i;
    QPolygon pol;
    QPoint point;
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    QList<float>values_60_seconds;


    qDebug() << "parameter_to_graph " << QString("%1").arg(parameter_to_graph, 0, 16);
    g_mutex.lock();
    values_60_seconds = get_list_last_60_sec_from_param(param);
    g_mutex.unlock();

    // 60 SEGUNDOS
    draw_grill(scene);
    // Graph lines
    for(i = 0; i < (values_60_seconds.length()); i++)
    {
        point.setX(i*VAL_SEC_SEPARATION);
        point.setY(adjusted_y_value(values_60_seconds.at(i))*-1);
        pol.append(point);
    }
    QPainterPath path;
    path.addPolygon(pol);
    scene->addPath(path, pen);
    i = i-1;
    draw_end_ball(scene, i*VAL_SEC_SEPARATION, adjusted_y_value(values_60_seconds.at(i)));
    scene->setSceneRect(0,-ui->graphicsView->height(),500,280);

    ui->graphicsView->setScene(scene);

}

void graphwindow::update_graph_minutes(uint param)
{
    int i;
    QPolygon pol;
    QPoint point;
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView_2);
    QList<float>values_60_minutes;


//    qDebug() << "parameter_to_graph " << QString("%1").arg(parameter_to_graph, 0, 16);
    g_mutex.lock();
    values_60_minutes = get_list_last_60_min_from_param(param);
    g_mutex.unlock();

    // 60 SEGUNDOS
    draw_grill(scene);
    // Graph lines
    for(i = 0; i < (values_60_minutes.length()); i++)
    {
        point.setX(i*VAL_MIN_SEPARATION);
        point.setY(adjusted_y_value(values_60_minutes.at(i))*-1);
        pol.append(point);
    }
    QPainterPath path;
    path.addPolygon(pol);
    scene->addPath(path, pen);
    i = i-1;
    draw_end_ball(scene, i*VAL_MIN_SEPARATION, adjusted_y_value(values_60_minutes.at(i)));
    scene->setSceneRect(0,-ui->graphicsView_2->height(),500,280);

    ui->graphicsView_2->setScene(scene);
}

void graphwindow::update_graph_hour(uint param)
{
    int i;
    QPolygon pol;
    QPoint point;
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView_3);
    QList<float>values_24_hours;


//    qDebug() << "parameter_to_graph " << QString("%1").arg(parameter_to_graph, 0, 16);
    g_mutex.lock();
    values_24_hours = get_list_last_24_hour_from_param(param);
    g_mutex.unlock();

    // 60 SEGUNDOS
    draw_grill(scene);
    // Graph lines
    for(i = 0; i < (values_24_hours.length()); i++)
    {
        point.setX(i*VAL_HOUR_SEPARATION);
        point.setY(adjusted_y_value(values_24_hours.at(i))*-1);
        pol.append(point);
    }
    QPainterPath path;
    path.addPolygon(pol);
    scene->addPath(path, pen);
    i = i-1;
    draw_end_ball(scene, i*VAL_HOUR_SEPARATION, adjusted_y_value(values_24_hours.at(i)));
    scene->setSceneRect(0,-ui->graphicsView_3->height(),500,280);

    ui->graphicsView_3->setScene(scene);
}


void graphwindow::on_tabWidget_currentChanged(int index)
{
    switch(index)
    {
    case 0:
        show_graph(TYPE_ELECTRICOS);
        break;
    case 1:
        show_graph(TYPE_FISICOS);
        break;
    case 2:
        show_graph(TYPE_QUIMICOS);
        break;
    }
}

void graphwindow::on_pb_gasto_inst_clicked()
{
    g_mutex.lock();
    parameter_to_graph = g_GASTO_INS;
    g_mutex.unlock();

    if("PTAR" == graph_origin)
    {
        ui->label_graph->setText("Gasto Instantáneo");
    }
    else
    {
        ui->label_graph->setText("");
    }
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_gasto_acc_clicked()
{
    g_mutex.lock();
    parameter_to_graph = g_GASTO_ACC;
    g_mutex.unlock();

    if("PTAR" == graph_origin)
    {
        ui->label_graph->setText("Gasto Accumulado");
    }
    else
    {
        ui->label_graph->setText("");
    }
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_nivel_reg_clicked()
{
    g_mutex.lock();
    parameter_to_graph = g_NIVEL_REG;
    g_mutex.unlock();

    if("PTAR" == graph_origin)
    {
        ui->label_graph->setText("Nivel Regulador");
    }
    else
    {
        ui->label_graph->setText("Filtro");
    }
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_nivel_clarif_clicked()
{
    g_mutex.lock();
    parameter_to_graph = g_NIVEL_CL;
    g_mutex.unlock();

    if("PTAR" == graph_origin)
    {
        ui->label_graph->setText("Nivel Clarificador");
    }
    else
    {
        ui->label_graph->setText("");
    }
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_presion_aire_clicked()
{
    g_mutex.lock();
    parameter_to_graph = g_PRES_AIR;
    g_mutex.unlock();

    if("PTAR" == graph_origin)
    {
        ui->label_graph->setText("Presión Aireador");
    }
    else
    {
        ui->label_graph->setText("");
    }
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_presion_filt_clicked()
{
    g_mutex.lock();
    parameter_to_graph = g_PRES_FIL;
    g_mutex.unlock();

    if("PTAR" == graph_origin)
    {
        ui->label_graph->setText("Presión Filtración");
    }
    else
    {
        ui->label_graph->setText("");
    }
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_OD_in_clicked()
{
    g_mutex.lock();
    parameter_to_graph = g_OD_IN;
    g_mutex.unlock();

    if("PTAR" == graph_origin)
    {
        ui->label_graph->setText("OD entrada");
    }
    else
    {
        ui->label_graph->setText("");
    }
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_pH_in_clicked()
{
    g_mutex.lock();
    parameter_to_graph = g_PH_IN;
    g_mutex.unlock();

    if("PTAR" == graph_origin)
    {
        ui->label_graph->setText("pH entrada");
    }
    else
    {
        ui->label_graph->setText("");
    }
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_SST_in_clicked()
{
    g_mutex.lock();
    parameter_to_graph = g_SST_IN;
    g_mutex.unlock();

    ui->label_graph->setText("SST entrada");
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_Turb_in_clicked()
{
    g_mutex.lock();
    parameter_to_graph = g_Turb_IN;
    g_mutex.unlock();

    ui->label_graph->setText("Turbidez entrada");
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_OD_out_clicked()
{
    g_mutex.lock();
    parameter_to_graph = g_OD_OUT;
    g_mutex.unlock();

    if("PTAR" == graph_origin)
    {
        ui->label_graph->setText("OD salida");
    }
    else
    {
        ui->label_graph->setText("");
    }
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_pH_out_clicked()
{
    g_mutex.lock();
    parameter_to_graph = g_PH_OUT;
    g_mutex.unlock();

    if("PTAR" == graph_origin)
    {
        ui->label_graph->setText("pH salida");
    }
    else
    {
        ui->label_graph->setText("");
    }
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_SST_out_clicked()
{
    g_mutex.lock();
    parameter_to_graph = g_SST_OUT;
    g_mutex.unlock();

    ui->label_graph->setText("SST salida");
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_Turb_out_clicked()
{
    g_mutex.lock();
    parameter_to_graph = g_Turb_OUT;
    g_mutex.unlock();

    ui->label_graph->setText("Turbidez salida");
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::draw_graph_line()
{

}

void graphwindow::draw_end_ball(QGraphicsScene *scene, int x, int y)
{
    qreal size = 30;

    QRadialGradient gradient2(QPointF(x, y *-1),size);

    gradient2.setColorAt(0, QColor::fromRgba(QRgb(0xFFFFFFFF)));
    gradient2.setColorAt(0.5, QColor::fromRgba(QRgb(0x00000000)));

    QBrush brush(gradient2);

    pen2.setColor(Qt::transparent);
    pen2.setWidth(0);

    scene->addEllipse(x - size/2, (y + size/2) *-1,size,size,pen2, QBrush(brush));
}

void graphwindow::draw_grill(QGraphicsScene *scene)
{
    QPen pen;
    int i = 0;
    pen.setColor(QColor(119, 136, 153));
    pen.setWidth(1);

    qreal separation = 0;
    qreal num_of_lines = 10;

    switch(element_type)
    {
    case TYPE_ELECTRICOS:

        // Voltaje, min = 0; max = 480;
        if((parameter_to_graph & 0x07) <= 3)
        {
            min_value = VOLT_MIN;
            max_value = VOLT_MAX;
            num_of_lines = 10;
            ui->div_text->setText("50V/div");
        }
        else
        {
            // Corriente, min = 0; max 80;
            min_value = AMP_MIN;
            max_value = AMP_MAX;
            num_of_lines = 10;
            ui->div_text->setText("1A/div");
        }
        break;
    case TYPE_FISICOS:

        if(parameter_to_graph == g_GASTO_INS || parameter_to_graph == g_GASTO_ACC)
        {
            min_value = 0;
            max_value = 150;
            num_of_lines = 10;
            ui->div_text->setText("15 LPM/div");
        }
        else if(parameter_to_graph == g_NIVEL_REG || parameter_to_graph == g_NIVEL_CL)
        {
            min_value = 0;
            max_value = 10;
            num_of_lines = 10;
            ui->div_text->setText("1 m/div");
        }
        else if(parameter_to_graph == g_PRES_AIR || parameter_to_graph == g_PRES_FIL)
        {
            min_value = 0;
            max_value = 15;
            num_of_lines = 10;
            ui->div_text->setText("1.5 PSI/div");
        }

        break;
        // quimicos
    case TYPE_QUIMICOS:
        if(parameter_to_graph == g_OD_IN || parameter_to_graph == g_OD_OUT)
        {
            min_value = 0;
            max_value = 8;
            num_of_lines = 8;
            ui->div_text->setText("1 ppm/div");
        }
        else if(parameter_to_graph == g_SST_IN || parameter_to_graph == g_SST_OUT)
        {
            min_value = 0;
            max_value = 800;
            num_of_lines = 10;
            ui->div_text->setText("80 mg/l div");
        }
        else if(parameter_to_graph == g_Turb_IN || parameter_to_graph == g_Turb_OUT)
        {
            min_value = 0;
            max_value = 100;
            num_of_lines = 10;
            ui->div_text->setText("10 NTU/div");
        }
        else if(parameter_to_graph == g_PH_IN || parameter_to_graph == g_PH_OUT)
        {
            min_value = 0;
            max_value = 14;
            num_of_lines = 14;
            ui->div_text->setText("1 pH/div");
        }
        break;
    }


    separation = ui->graphicsView->height()/num_of_lines;

    ui->min_value->setText(QString::number(min_value));
    ui->max_value->setText(QString::number(max_value));


    for(i = 0; i < num_of_lines; i++)
    {
        scene->addLine(0, i*separation*-1, ui->graphicsView->width(), i*separation*-1, pen);
    }

    pen.setColor(QColor(25, 25, 25));
    pen.setWidth(1);
    for(i = 0; i < 12; i++)
    {
        if(0 == i%2)
        {
            scene->addLine(i*ui->graphicsView->width()/12, 0, i*ui->graphicsView->width()/12, -1*ui->graphicsView->height(), pen);
        }
        else
        {
            scene->addLine(i*ui->graphicsView->width()/12, 0, i*ui->graphicsView->width()/12, -10, pen);
        }
    }

}



void graphwindow::on_comboBox_currentIndexChanged(int index)
{
    uint i = 0;
    i = ui->comboBox->currentData().toInt();
    //on_volts_1_clicked();

    parameter_to_graph = electric_graph_settings[index_of_motor()].param_v_fase_1;

    ui->label_graph->setText("Voltaje L1-L2");

    qDebug() << "Index is " << i;
}

qreal graphwindow::adjusted_y_value(qreal val)
{
    qreal new_value;
    new_value = val * ui->graphicsView->height();
    new_value = new_value / max_value;

    return  new_value;
}

void graphwindow::color_to_label(uint parameter)
{

    QString inactive = "color:white;"
                     "background-color: transparent;"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;";
    QString active = "color:rgb(0, 167, 250);"
                     "background-color: transparent;"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;";

    //VOLTS_1
    if(parameter == 0x3001 || parameter == 0x3011 || parameter == 0x3021 || parameter == 0x3031 ||
       parameter == 0x4001 || parameter == 0x4011 || parameter == 0x4021 || parameter == 0x4031)
    {ui->volts_1->setStyleSheet(active); }
    else
    {ui->volts_1->setStyleSheet(inactive);}

    //VOLTS_2
    if(parameter == 0x3002 || parameter == 0x3012 || parameter == 0x3022 || parameter == 0x3032 ||
       parameter == 0x4002 || parameter == 0x4012 || parameter == 0x4022 || parameter == 0x4032)
    {ui->volts_2->setStyleSheet(active); }
    else
    {ui->volts_2->setStyleSheet(inactive);}

    //VOLTS_3
    if(parameter == 0x3003 || parameter == 0x3013 || parameter == 0x3023 || parameter == 0x3033 ||
       parameter == 0x4003 || parameter == 0x4013 || parameter == 0x4023 || parameter == 0x4033)
    {ui->volts_3->setStyleSheet(active); }
    else
    {ui->volts_3->setStyleSheet(inactive);}

    //AMPS_1
    if(parameter == 0x3004 || parameter == 0x3014 || parameter == 0x3024 || parameter == 0x3034 ||
       parameter == 0x4004 || parameter == 0x4014 || parameter == 0x4024 || parameter == 0x4034)
    {ui->amps_1->setStyleSheet(active); }
    else
    {ui->amps_1->setStyleSheet(inactive);}

    //AMPS_2
    if(parameter == 0x3005 || parameter == 0x3015 || parameter == 0x3025 || parameter == 0x3035 ||
       parameter == 0x4005 || parameter == 0x4015 || parameter == 0x4025 || parameter == 0x4035)
    {ui->amps_2->setStyleSheet(active); }
    else
    {ui->amps_2->setStyleSheet(inactive);}

    //AMPS_3
    if(parameter == 0x3006 || parameter == 0x3016 || parameter == 0x3026 || parameter == 0x3036 ||
       parameter == 0x4006 || parameter == 0x4016 || parameter == 0x4026 || parameter == 0x4036)
    {ui->amps_3->setStyleSheet(active); }
    else
    {ui->amps_3->setStyleSheet(inactive);}

    //GASTO INS
    if(parameter == g_GASTO_INS)
    {ui->pb_gasto_inst->setStyleSheet(active); }
    else
    {ui->pb_gasto_inst->setStyleSheet(inactive);}
    //GASTO ACC
    if(parameter == g_GASTO_ACC)
    {ui->pb_gasto_acc->setStyleSheet(active); }
    else
    {ui->pb_gasto_acc->setStyleSheet(inactive);}
    //NIVEL REG
    if(parameter == g_NIVEL_REG)
    {ui->pb_nivel_reg->setStyleSheet(active); }
    else
    {ui->pb_nivel_reg->setStyleSheet(inactive);}
    //NIVEL_CL
    if(parameter == g_NIVEL_CL)
    {ui->pb_nivel_clarif->setStyleSheet(active); }
    else
    {ui->pb_nivel_clarif->setStyleSheet(inactive);}
    //PRES_AIR
    if(parameter == g_PRES_AIR)
    {ui->pb_presion_aire->setStyleSheet(active); }
    else
    {ui->pb_presion_aire->setStyleSheet(inactive);}
    //PRES_FIL
    if(parameter == g_PRES_FIL)
    {ui->pb_presion_filt->setStyleSheet(active); }
    else
    {ui->pb_presion_filt->setStyleSheet(inactive);}

    //OD_IN
    if(parameter == g_OD_IN)
    {ui->pb_OD_in->setStyleSheet(active); }
    else
    {ui->pb_OD_in->setStyleSheet(inactive);}
    //OD_OUT
    if(parameter == g_OD_OUT)
    {ui->pb_OD_out->setStyleSheet(active); }
    else
    {ui->pb_OD_out->setStyleSheet(inactive);}
    //OD_OUT
    if(parameter == g_OD_OUT)
    {ui->pb_OD_out->setStyleSheet(active); }
    else
    {ui->pb_OD_out->setStyleSheet(inactive);}
    //SST_IN
    if(parameter == g_SST_IN)
    {ui->pb_SST_in->setStyleSheet(active); }
    else
    {ui->pb_SST_in->setStyleSheet(inactive);}
    //SST_OUT
    if(parameter == g_SST_OUT)
    {ui->pb_SST_out->setStyleSheet(active); }
    else
    {ui->pb_SST_out->setStyleSheet(inactive);}
    //Turb_IN
    if(parameter == g_Turb_IN)
    {ui->pb_Turb_in->setStyleSheet(active); }
    else
    {ui->pb_Turb_in->setStyleSheet(inactive);}
    //Turb_OUT
    if(parameter == g_Turb_OUT)
    {ui->pb_Turb_out->setStyleSheet(active);}
    else
    {ui->pb_Turb_out->setStyleSheet(inactive);}
    //PH_IN
    if(parameter == g_PH_IN)
    {ui->pb_pH_in->setStyleSheet(active);}
    else
    {ui->pb_pH_in->setStyleSheet(inactive);}
    //PH_OUT
    if(parameter == g_PH_OUT)
    {ui->pb_pH_out->setStyleSheet(active);}
    else
    {ui->pb_pH_out->setStyleSheet(inactive);}
}

uint graphwindow::index_of_motor()
{
    uint ret = 0;
    if("Carcamo 1" == ui->comboBox->currentText())
    {
        ret = 0;
    }
    else if("Carcamo 2" == ui->comboBox->currentText())
    {
        ret = 1;
    }
    else if("Carcamo 3" == ui->comboBox->currentText())
    {
        ret = 2;
    }
    else if("Carcamo 4" == ui->comboBox->currentText())
    {
        ret = 3;
    }
    else if("Reactor 1" == ui->comboBox->currentText())
    {
        ret = 4;
    }
    else if("Reactor 2" == ui->comboBox->currentText())
    {
        ret = 5;
    }
    else if("Reactor 3" == ui->comboBox->currentText())
    {
        ret = 6;
    }
    else if("Reactor 4" == ui->comboBox->currentText())
    {
        ret = 7;
    }
    else if("Motor Giro" == ui->comboBox->currentText())
    {
        ret = 8;
    }
    else if("Bomba Alim" == ui->comboBox->currentText())
    {
        ret = 9;
    }
    else if("Bomba Retro" == ui->comboBox->currentText())
    {
        ret = 10;
    }
    else if("Filtro 4" == ui->comboBox->currentText())
    {
        ret = 11;
    }




    return ret;
}

void graphwindow::set_type(QString type)
{
    graph_origin = type;
    if("PTAR" == graph_origin)
    {
        g_OD_IN   =  OD_IN   ;
        g_SST_IN  =  SST_IN  ;
        g_Turb_IN =  Turb_IN ;
        g_PH_IN   =  PH_IN   ;
                              ;
        g_OD_OUT   = OD_OUT   ;
        g_SST_OUT  = SST_OUT  ;
        g_Turb_OUT = Turb_OUT ;
        g_PH_OUT   = PH_OUT   ;
                              ;
        g_GASTO_INS =GASTO_INS;
        g_GASTO_ACC =GASTO_ACC;
        g_NIVEL_REG =NIVEL_REG;
        g_NIVEL_CL  =NIVEL_CL ;
        g_PRES_AIR  =PRES_AIR ;
        g_PRES_FIL  =PRES_FIL ;

        // fisicos
        ui->label_15->setText("Instantáneo");
        ui->label_16->setText("Acumulado");
        ui->label_18->setText("Regulador");
        ui->label_17->setText("Clarificador");
        ui->label_22->setText("Aireador");
        ui->label_20->setText("Filtración");

        // quimicos
        ui->label_30->setText("pH");
        ui->label_28->setText("pH");
        ui->label_23->setText("OD");
        ui->label_24->setText("OD");
    }
    else
    {
        g_OD_IN   =  Filtro_OD_IN   ;
        g_SST_IN  =  Filtro_SST_IN  ;
        g_Turb_IN =  Filtro_Turb_IN ;
        g_PH_IN   =  Filtro_PH_IN   ;
                              ;
        g_OD_OUT   = Filtro_OD_OUT   ;
        g_SST_OUT  = Filtro_SST_OUT  ;
        g_Turb_OUT = Filtro_Turb_OUT ;
        g_PH_OUT   = Filtro_PH_OUT   ;

        g_GASTO_INS =Filtro_GASTO_INS;
        g_GASTO_ACC =Filtro_GASTO_ACC;
        g_NIVEL_REG =Filtro_NIVEL_REG;
        g_NIVEL_CL  =Filtro_NIVEL_CL ;
        g_PRES_AIR  =Filtro_PRES_AIR ;
        g_PRES_FIL  =Filtro_PRES_FIL ;

        // fisicos
        ui->label_15->setText("");
        ui->label_16->setText("");
        ui->label_18->setText("Filtro");
        ui->label_17->setText("");
        ui->label_22->setText("");
        ui->label_20->setText("");

        // quimicos
        ui->label_30->setText("");
        ui->label_28->setText("");
        ui->label_23->setText("");
        ui->label_24->setText("");

    }
}
