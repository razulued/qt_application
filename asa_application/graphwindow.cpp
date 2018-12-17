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
#include "asa_protocol.h"

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
    REGULADOR_MOT_1,
    REGULADOR_MOT_2,
    REGULADOR_MOT_3,
    REGULADOR_MOT_4,
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
    /*                  name                         state   V1      V2      V3      A1      A2      A6      */
    /* CARCAMO_MOT_1 */{QObject::tr("Carcamo 1"),    0x3000, 0x3001, 0x3002, 0x3003, 0x3004, 0x3005, 0x3006,  },
    /* CARCAMO_MOT_2 */{QObject::tr("Carcamo 2"),    0x3010, 0x3011, 0x3012, 0x3013, 0x3014, 0x3015, 0x3016,  },
    /* CARCAMO_MOT_3 */{QObject::tr("Carcamo 3"),    0x3020, 0x3021, 0x3022, 0x3023, 0x3024, 0x3025, 0x3026,  },
    /* CARCAMO_MOT_4 */{QObject::tr("Carcamo 4"),    0x3030, 0x3031, 0x3032, 0x3033, 0x3034, 0x3035, 0x3036,  },

    /* REGULADOR_MOT_1 */{QObject::tr("Regulador 1"),    0x3800, 0x3801, 0x3802, 0x3803, 0x3804, 0x3805, 0x3806,  },
    /* REGULADOR_MOT_2 */{QObject::tr("Regulador 2"),    0x3810, 0x3811, 0x3812, 0x3813, 0x3814, 0x3815, 0x3816,  },
    /* REGULADOR_MOT_3 */{QObject::tr("Regulador 3"),    0x3820, 0x3821, 0x3822, 0x3823, 0x3824, 0x3825, 0x3826,  },
    /* REGULADOR_MOT_4 */{QObject::tr("Regulador 4"),    0x3830, 0x3831, 0x3832, 0x3833, 0x3834, 0x3835, 0x3836,  },

    /* REACTOR_MOT_1 */{QObject::tr("Reactor 1"),    0x4000, 0x4001, 0x4002, 0x4003, 0x4004, 0x4005, 0x4006,  },
    /* REACTOR_MOT_2 */{QObject::tr("Reactor 2"),    0x4010, 0x4011, 0x4012, 0x4013, 0x4014, 0x4015, 0x4016,  },
    /* REACTOR_MOT_3 */{QObject::tr("Reactor 3"),    0x4020, 0x4021, 0x4022, 0x4023, 0x4024, 0x4025, 0x4026,  },
    /* REACTOR_MOT_4 */{QObject::tr("Reactor 4"),    0x4030, 0x4031, 0x4032, 0x4033, 0x4034, 0x4035, 0x4036,  },
    /* FILTRO_MOT_1  */{QObject::tr("Motor Giro"),    0x9000, 0x9001, 0x9002, 0x9003, 0x9004, 0x9005, 0x9006,  },
    /* FILTRO_MOT_2  */{QObject::tr("Bomba Retro 1"), 0x9010, 0x9011, 0x9012, 0x9013, 0x9014, 0x9015, 0x9016,  },
    /* FILTRO_MOT_3  */{QObject::tr("Bomba Retro 2"), 0x9020, 0x9021, 0x9022, 0x9023, 0x9024, 0x9025, 0x9026,  },
    /* FILTRO_MOT_4  */{QObject::tr("Bomba Alim"),    0x9080, 0x9081, 0x9082, 0x9083, 0x9084, 0x9085, 0x9086,  },
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
uint graphwindow::g_NIVEL_CAR   = NIVEL_CAR ;
uint graphwindow::g_NIVEL_REG   = NIVEL_REG;
uint graphwindow::g_PRES_AIR    = PRES_AIR ;
uint graphwindow::g_PRES_FIL    = PRES_FIL ;

graphwindow::graphwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graphwindow)
{
    ui->setupUi(this);
    parent_window = parent;

    ui->splineGraph_1->hide();
    ui->splineGraph_2->hide();
    show_or_hide_graph(false);

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
    ui->pb_nivel_car->setStyleSheet(ui->volts_1->styleSheet());
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


    QFont label_title_font("Typo Square Bold Demo",17,1);

    ui->label_title->setFont(label_title_font);
    ui->label_title->setStyleSheet("Text-align:left;"
                                   "border:none;"
                                   "color:black;"
                                   "background-color:transparent;");

//    QLinearGradient gradient(0,0,ui->graphicsView_2->width(),ui->graphicsView_2->height());
////    gradient.setColorAt(0, QColor::fromRgbF(0, 0, 0, 127));
//    gradient.setColorAt(0, QColor::fromRgb(0, 167, 250,180));
////    gradient.setColorAt(0.7, QColor::fromRgb(0, 167, 250,255));
//    gradient.setColorAt(0.8, QColor::fromRgb(255, 255, 255,255));
//    gradient.setColorAt(0.9, QColor::fromRgb(255, 255, 255,0));

//    QBrush brush(gradient);
//    QBrush brush(Qt::LinearGradientPattern);
//    pen.setBrush(brush);
//        QColor line_color;
//        line_color.setRgb(0, 167, 250,150);
//        pen.setColor(line_color);
//    pen.setWidth(5);

//    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    ui->graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    ui->graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    ui->graphicsView_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    ui->graphicsView_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);


}

graphwindow::~graphwindow()
{
    delete ui;
}

void graphwindow::show_graph(uint type)
{
    g_mutex.lock();

    //SET UNITS
    ui->label_14->setText(tr("Gasto") + " " + "(" + get_units_caudal() + ")");
    ui->label_19->setText(tr("Nivel") + " " + "(" +get_units_longitud() + ")");
    ui->label_21->setText(tr("Presión") + " " + "(" + get_units_presion() + ")");

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
        ui->label_graph->setText(tr("Voltaje L1-L2"));
        ui->label_title->setText(tr("Parámetros Eléctricos"));
        break;
    case TYPE_FISICOS:
        ui->top_bar->setStyleSheet("background-image: url(:/barras/screen800x600/barras/Parametros fisicos.png);");
        if("PTAR" == graph_origin)
        {
            parameter_to_graph = g_GASTO_INS;
            ui->label_graph->setText(tr("Gasto Instantáneo"));
        }
        else
        {
            parameter_to_graph = g_NIVEL_REG;
            ui->label_graph->setText(tr("Filtro"));
        }
        ui->label_title->setText(tr("Parámetros Físicos"));

        break;
    case TYPE_QUIMICOS:
        ui->top_bar->setStyleSheet("background-image: url(:/barras/screen800x600/barras/Parametros quimicos.png);");
        if("PTAR" == graph_origin)
        {
            parameter_to_graph = g_OD_IN;
            ui->label_graph->setText(tr("OD entrada"));
        }
        else
        {
            parameter_to_graph = g_SST_IN;
            ui->label_graph->setText(tr("SST entrada"));
        }
        ui->label_title->setText(tr("Parámetros Químicos"));

        break;

    }
    g_mutex.unlock();
    color_to_label(parameter_to_graph);
    ui->tabWidget->setCurrentIndex(element_type);

    this->move(parent_window->pos());

    init_graph(parameter_to_graph);

    this->show();
}

void graphwindow::update_graph()
{
    uint index_motor = index_of_motor();
    switch(ui->tabWidget->currentIndex())
    {
    case TYPE_ELECTRICOS:

        // electricos
        ui->volts_1->setText(get_last_string_value_from_param(electric_graph_settings[index_motor].param_v_fase_1));
        ui->volts_2->setText(get_last_string_value_from_param(electric_graph_settings[index_motor].param_v_fase_2));
        ui->volts_3->setText(get_last_string_value_from_param(electric_graph_settings[index_motor].param_v_fase_3));

        ui->amps_1->setText(get_last_string_value_from_param(electric_graph_settings[index_motor].param_a_fase_1));
        ui->amps_2->setText(get_last_string_value_from_param(electric_graph_settings[index_motor].param_a_fase_2));
        ui->amps_3->setText(get_last_string_value_from_param(electric_graph_settings[index_motor].param_a_fase_3));
        break;
        // fisicos
    case TYPE_FISICOS:
        ui->pb_gasto_inst->setText(get_last_string_value_from_param(g_GASTO_INS));
        ui->pb_gasto_acc->setText(get_last_string_value_from_param(g_GASTO_ACC));

        ui->pb_nivel_car->setText(get_last_string_value_from_param(g_NIVEL_CAR));
        ui->pb_nivel_reg->setText(get_last_string_value_from_param(g_NIVEL_REG));

        ui->pb_presion_aire->setText(get_last_string_value_from_param(g_PRES_AIR));
        ui->pb_presion_filt->setText(get_last_string_value_from_param(g_PRES_FIL));
        break;
        // quimicos
    case TYPE_QUIMICOS:
        ui->pb_OD_in->setText(get_last_string_value_from_param(g_OD_IN));
        ui->pb_OD_out->setText(get_last_string_value_from_param(g_OD_OUT));
        ui->pb_pH_in->setText(get_last_string_value_from_param(g_PH_IN));
        ui->pb_pH_out->setText(get_last_string_value_from_param(g_PH_OUT));
        ui->pb_SST_in->setText(get_last_string_value_from_param(g_SST_IN));
        ui->pb_SST_out->setText(get_last_string_value_from_param(g_SST_OUT));
        ui->pb_Turb_in->setText(get_last_string_value_from_param(g_Turb_IN));
        ui->pb_Turb_out->setText(get_last_string_value_from_param(g_Turb_OUT));
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

    ui->label_graph->setText(tr("Voltaje L1-L2"));
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_volts_2_clicked()
{
    g_mutex.lock();
    parameter_to_graph = electric_graph_settings[index_of_motor()].param_v_fase_2;
    g_mutex.unlock();

    ui->label_graph->setText(tr("Voltaje L2-L3"));
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_volts_3_clicked()
{
    g_mutex.lock();
    parameter_to_graph = electric_graph_settings[index_of_motor()].param_v_fase_3;
    g_mutex.unlock();

    ui->label_graph->setText(tr("Voltaje L3-L1"));
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_amps_1_clicked()
{
    g_mutex.lock();
    parameter_to_graph = electric_graph_settings[index_of_motor()].param_a_fase_1;
    g_mutex.unlock();

    ui->label_graph->setText(tr("Amps L1-L2"));
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_amps_2_clicked()
{
    g_mutex.lock();
    parameter_to_graph = electric_graph_settings[index_of_motor()].param_a_fase_2;
    g_mutex.unlock();

    ui->label_graph->setText(tr("Amps L2-L1"));
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_amps_3_clicked()
{
    g_mutex.lock();
    parameter_to_graph = electric_graph_settings[index_of_motor()].param_a_fase_3;
    g_mutex.unlock();

    ui->label_graph->setText(tr("Amps L3-L1"));
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::update_graph_window(uint param)
{
    update_graphs(param);
}

void graphwindow::init_graph(uint param)
{
    QList<float>list_of_values;

    qDebug() << "parameter_to_graph " << QString("%1").arg(parameter_to_graph, 0, 16);
    g_mutex.lock();
    list_of_values = get_list(param);
    g_mutex.unlock();
//    qDebug() << "values_60_seconds " << values_60_seconds;
    char_left = new Chart(list_of_values, graph_divisions,ui->splineGraph_1);
//    chart->setTitle("Dynamic spline chart");
    char_left->legend()->hide();
    ui->splineGraph_1->setChart(char_left);
//    ui->splineGraph_1->show();

    g_mutex.lock();
    list_of_values = get_list(parameter_to_graph_righside);
    g_mutex.unlock();
//    qDebug() << "values_60_seconds " << values_60_seconds;
    char_rigth = new Chart(list_of_values, graph_divisions,ui->splineGraph_1);
//    chart->setTitle("Dynamic spline chart");
    char_rigth->legend()->hide();
    ui->splineGraph_2->setChart(char_rigth);
//    ui->splineGraph_2->show();

}
void graphwindow::update_graphs(uint param)
{
    QList<float>list_of_values;

    qDebug() << "parameter_to_graph " << QString("%1").arg(parameter_to_graph, 0, 16);
    g_mutex.lock();
    list_of_values = get_list(param);
    g_mutex.unlock();

    char_left->append_to_end(list_of_values);
//    ui->splineGraph_1->setChart(chart);
    ui->splineGraph_1->show();

    if(show_both_graph == true)
    {
        g_mutex.lock();
        list_of_values = get_list(parameter_to_graph_righside);
        g_mutex.unlock();
        char_rigth->append_to_end(list_of_values);
    //    qDebug() << "values_60_seconds " << values_60_seconds;
//        Chart *chart2 = new Chart(value, graph_divisions,ui->splineGraph_1);
    //    chart->setTitle("Dynamic spline chart");
//        chart2->legend()->hide();
//        ui->splineGraph_2->setChart(chart2);
        ui->splineGraph_2->show();
    }
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
        ui->label_graph->setText(tr("Gasto Instantáneo"));
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
        ui->label_graph->setText(tr("Gasto Accumulado"));
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
        ui->label_graph->setText(tr("Nivel Regulador"));
    }
    else
    {
        ui->label_graph->setText(tr("Filtro"));
    }
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_nivel_car_clicked()
{
    g_mutex.lock();
    parameter_to_graph = g_NIVEL_CAR;
    g_mutex.unlock();

    if("PTAR" == graph_origin)
    {
        ui->label_graph->setText(tr("Nivel Cárcamo"));
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
        ui->label_graph->setText(tr("Presión Aireador"));
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
        ui->label_graph->setText(tr("Presión Filtración"));
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
        ui->label_graph->setText(tr("OD entrada"));
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
        ui->label_graph->setText(tr("pH entrada"));
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

    ui->label_graph->setText(tr("SST entrada"));
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_Turb_in_clicked()
{
    g_mutex.lock();
    parameter_to_graph = g_Turb_IN;
    g_mutex.unlock();

    ui->label_graph->setText(tr("Turbidez entrada"));
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
        ui->label_graph->setText(tr("OD salida"));
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
        ui->label_graph->setText(tr("pH salida"));
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

    ui->label_graph->setText(tr("SST salida"));
    color_to_label(parameter_to_graph);
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_Turb_out_clicked()
{
    g_mutex.lock();
    parameter_to_graph = g_Turb_OUT;
    g_mutex.unlock();

    ui->label_graph->setText(tr("Turbidez salida"));
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


void graphwindow::on_comboBox_currentIndexChanged(int index)
{
    uint i = 0;
    i = ui->comboBox->currentData().toInt();
    //on_volts_1_clicked();

    parameter_to_graph = electric_graph_settings[index_of_motor()].param_v_fase_1;

    ui->label_graph->setText(tr("Voltaje L1-L2"));

    qDebug() << "Index is " << i;
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
       parameter == 0x4001 || parameter == 0x4011 || parameter == 0x4021 || parameter == 0x4031 ||
       parameter == 0x9001 || parameter == 0x9011 || parameter == 0x9021 || parameter == 0x9031 || parameter == 0x9081 )
    {ui->volts_1->setStyleSheet(active); }
    else
    {ui->volts_1->setStyleSheet(inactive);}

    //VOLTS_2
    if(parameter == 0x3002 || parameter == 0x3012 || parameter == 0x3022 || parameter == 0x3032 ||
       parameter == 0x4002 || parameter == 0x4012 || parameter == 0x4022 || parameter == 0x4032 ||
       parameter == 0x9002 || parameter == 0x9012 || parameter == 0x9022 || parameter == 0x9032 || parameter == 0x9082)
    {ui->volts_2->setStyleSheet(active); }
    else
    {ui->volts_2->setStyleSheet(inactive);}

    //VOLTS_3
    if(parameter == 0x3003 || parameter == 0x3013 || parameter == 0x3023 || parameter == 0x3033 ||
       parameter == 0x4003 || parameter == 0x4013 || parameter == 0x4023 || parameter == 0x4033 ||
       parameter == 0x9003 || parameter == 0x9013 || parameter == 0x9023 || parameter == 0x9033 || parameter == 0x9083)
    {ui->volts_3->setStyleSheet(active); }
    else
    {ui->volts_3->setStyleSheet(inactive);}

    //AMPS_1
    if(parameter == 0x3004 || parameter == 0x3014 || parameter == 0x3024 || parameter == 0x3034 ||
       parameter == 0x4004 || parameter == 0x4014 || parameter == 0x4024 || parameter == 0x4034 ||
       parameter == 0x9004 || parameter == 0x9014 || parameter == 0x9024 || parameter == 0x9034 || parameter == 0x9084)
    {ui->amps_1->setStyleSheet(active); }
    else
    {ui->amps_1->setStyleSheet(inactive);}

    //AMPS_2
    if(parameter == 0x3005 || parameter == 0x3015 || parameter == 0x3025 || parameter == 0x3035 ||
       parameter == 0x4005 || parameter == 0x4015 || parameter == 0x4025 || parameter == 0x4035 ||
       parameter == 0x9005 || parameter == 0x9015 || parameter == 0x9025 || parameter == 0x9035|| parameter == 0x9085)
    {ui->amps_2->setStyleSheet(active); }
    else
    {ui->amps_2->setStyleSheet(inactive);}

    //AMPS_3
    if(parameter == 0x3006 || parameter == 0x3016 || parameter == 0x3026 || parameter == 0x3036 ||
       parameter == 0x4006 || parameter == 0x4016 || parameter == 0x4026 || parameter == 0x4036 ||
       parameter == 0x9006 || parameter == 0x9016 || parameter == 0x9026 || parameter == 0x9036 || parameter == 0x9086)
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
    if(parameter == g_NIVEL_CAR)
    {ui->pb_nivel_car->setStyleSheet(active); }
    else
    {ui->pb_nivel_car->setStyleSheet(inactive);}
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
    if(tr("Carcamo 1") == ui->comboBox->currentText())
    {
        ret = 0;
    }
    else if(tr("Carcamo 2") == ui->comboBox->currentText())
    {
        ret = 1;
    }
    else if(tr("Carcamo 3") == ui->comboBox->currentText())
    {
        ret = 2;
    }
    else if(tr("Carcamo 4") == ui->comboBox->currentText())
    {
        ret = 3;
    }
    if(tr("Regulador 1") == ui->comboBox->currentText())
    {
        ret = 4;
    }
    else if(tr("Regulador 2") == ui->comboBox->currentText())
    {
        ret = 5;
    }
    else if(tr("Regulador 3") == ui->comboBox->currentText())
    {
        ret = 6;
    }
    else if(tr("Regulador 4") == ui->comboBox->currentText())
    {
        ret = 7;
    }
    else if(tr("Reactor 1") == ui->comboBox->currentText())
    {
        ret = 8;
    }
    else if(tr("Reactor 2") == ui->comboBox->currentText())
    {
        ret = 9;
    }
    else if(tr("Reactor 3") == ui->comboBox->currentText())
    {
        ret = 10;
    }
    else if(tr("Reactor 4") == ui->comboBox->currentText())
    {
        ret = 11;
    }
    else if(tr("Motor Giro") == ui->comboBox->currentText())
    {
        ret = 12;
    }
    else if(tr("Bomba Retro 1") == ui->comboBox->currentText())
    {
        ret = 13;
    }
    else if(tr("Bomba Retro 2") == ui->comboBox->currentText())
    {
        ret = 14;
    }
    else if(tr("Bomba Alim") == ui->comboBox->currentText())
    {
        ret = 15;
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
        g_NIVEL_CAR  =NIVEL_CAR ;
        g_PRES_AIR  =PRES_AIR ;
        g_PRES_FIL  =PRES_FIL ;

        // fisicos
        ui->label_15->setText(tr("Instantáneo"));
        ui->label_16->setText(tr("Acumulado"));
        ui->label_18->setText(tr("Cárcamo"));
        ui->label_17->setText(tr("Regulador"));
        ui->label_22->setText(tr("Aireador"));
        ui->label_20->setText(tr("Filtración"));

        // quimicos
        ui->label_30->setText(tr("pH"));
        ui->label_28->setText(tr("pH"));
        ui->label_23->setText(tr("OD"));
        ui->label_24->setText(tr("OD"));
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
        g_NIVEL_CAR =Filtro_NIVEL_CL ;
        g_PRES_AIR  =Filtro_PRES_AIR ;
        g_PRES_FIL  =Filtro_PRES_FIL ;

        // fisicos
        ui->label_15->setText(tr("Caudal"));
        ui->label_16->setText("");
        ui->label_18->setText(tr("Filtro"));
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

void graphwindow::on_top_menu_6_clicked()
{
    // control
    forward_control_clicked();
}

void graphwindow::on_top_menu_2_clicked()
{
    forward_bitacora_clicked();
    // bitacora
}

void graphwindow::show_or_hide_graph(bool both_graph)
{
    if(both_graph == false)
    {
        ui->splineGraph_1->setGeometry(ui->splineGraph_1->x(), ui->splineGraph_1->y(), 800, ui->splineGraph_1->height());
        ui->splineGraph_2->hide();
        ui->label_graph_2->hide();
        ui->barra_grafica_2->hide();
    }
    else
    {
        ui->splineGraph_1->setGeometry(ui->splineGraph_1->x(), ui->splineGraph_1->y(), 400, ui->splineGraph_1->height());
        ui->splineGraph_2->show();
        ui->label_graph_2->show();
        ui->barra_grafica_2->show();
        update_graph_window(parameter_to_graph);
    }
}

void graphwindow::on_label_graph_clicked()
{
    if(show_both_graph == false)
    {
        // Display both graph
        show_both_graph = true;
        ui->label_graph_2->setText(ui->label_graph->text());
        show_or_hide_graph(show_both_graph);
        parameter_to_graph_righside = parameter_to_graph;
    }
    else
    {
        // Display only left graph
        show_both_graph = false;
        show_or_hide_graph(show_both_graph);
    }
}

void graphwindow::set_graph_span(uint span)
{
    if(span == 0)
    {
        ui->radioButton->setChecked(true);
    }

    graph_span = span;
}

void graphwindow::on_radioButton_toggled(bool checked)
{
    if(checked == true)
    {
        graph_span = 0;
        update_graph_window(parameter_to_graph);
    }
}

void graphwindow::on_radioButton_2_toggled(bool checked)
{
    if(checked == true)
    {
        graph_span = 1;
        update_graph_window(parameter_to_graph);
    }
}

void graphwindow::on_radioButton_3_toggled(bool checked)
{
    if(checked == true)
    {
        graph_span = 2;
        update_graph_window(parameter_to_graph);
    }
}

QList<float> graphwindow::get_list(uint param)
{
    if(graph_span == 0)
    {
        graph_divisions = 60;
        return get_list_last_60_sec_from_param(param);
    }
    else if(graph_span == 1)
    {
        graph_divisions = 60;
        return get_list_last_60_min_from_param(param);
    }
    else if(graph_span == 2)
    {
        graph_divisions = 24;
        return get_list_last_24_hour_from_param(param);
    }
}

float graphwindow::get_last_param_from_list(uint param)
{
    if(graph_span == 0)
    {
        graph_divisions = 60;
        return get_list_last_60_sec_from_param(param).last();
    }
    else if(graph_span == 1)
    {
        graph_divisions = 60;
        return get_list_last_60_min_from_param(param).last();
    }
    else if(graph_span == 2)
    {
        graph_divisions = 24;
        return get_list_last_24_hour_from_param(param).last();
    }
}

