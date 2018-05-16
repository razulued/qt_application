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

#define VAL_SEPARATION (ui->graphicsView->width()/10)

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
};


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


//    QColor line_color;
//    line_color.setRgb(0, 167, 250,150);

//    pen.setColor(line_color);
//    pen.setCapStyle(Qt::RoundCap);
//    pen.setWidth(3);

    /* Init combo box */
    ui->comboBox->setStyleSheet("color: white;");
    ui->min_value->setStyleSheet("color: white;");
    ui->max_value->setStyleSheet("color: white;");
    ui->div_text->setStyleSheet("color: white;");


    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
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
        ui->top_bar->setStyleSheet("background-image: url(:/barras/screen800x600/barras/PE_bar.png);");
        parameter_to_graph = electric_graph_settings[0].param_v_fase_1;
        ui->label_graph->setText("Voltaje L1-L2");

        break;
    case TYPE_FISICOS:
        ui->top_bar->setStyleSheet("background-image: url(:/barras/screen800x600/barras/PF_bar.png);");
        parameter_to_graph = 0x3203;
        ui->label_graph->setText("Gasto Instantáneo");

        break;
    case TYPE_QUIMICOS:
        ui->top_bar->setStyleSheet("background-image: url(:/barras/screen800x600/barras/PQ_bar.png);");
        parameter_to_graph = 0x3307;
        ui->label_graph->setText("OD entrada");
        break;

    }
    g_mutex.unlock();
    ui->tabWidget->setCurrentIndex(element_type);

    this->move(parent_window->pos());
    this->show();
}

void graphwindow::update_graph()
{
    switch(ui->tabWidget->currentIndex())
    {
    case TYPE_ELECTRICOS:

        // electricos
        ui->volts_1->setText(get_last_value_from_param(electric_graph_settings[ui->comboBox->currentIndex()].param_v_fase_1));
        ui->volts_2->setText(get_last_value_from_param(electric_graph_settings[ui->comboBox->currentIndex()].param_v_fase_2));
        ui->volts_3->setText(get_last_value_from_param(electric_graph_settings[ui->comboBox->currentIndex()].param_v_fase_3));

        ui->amps_1->setText(get_last_value_from_param(electric_graph_settings[ui->comboBox->currentIndex()].param_a_fase_1));
        ui->amps_2->setText(get_last_value_from_param(electric_graph_settings[ui->comboBox->currentIndex()].param_a_fase_2));
        ui->amps_3->setText(get_last_value_from_param(electric_graph_settings[ui->comboBox->currentIndex()].param_a_fase_3));
        break;
        // fisicos
    case TYPE_FISICOS:
        ui->pb_gasto_inst->setText(get_last_value_from_param(0x3203));
        ui->pb_gasto_acc->setText(get_last_value_from_param(0x4203));

        ui->pb_nivel_clarif->setText(get_last_value_from_param(0x5201));
        ui->pb_nivel_reg->setText(get_last_value_from_param(0x3201));

        ui->pb_presion_aire->setText(get_last_value_from_param(0x4205));
        ui->pb_presion_filt->setText(get_last_value_from_param(0x8205));
        break;
        // quimicos
    case TYPE_QUIMICOS:
        ui->pb_OD_in->setText(get_last_value_from_param(0x3307));
        ui->pb_OD_out->setText(get_last_value_from_param(0x5307));
        ui->pb_pH_in->setText(get_last_value_from_param(0x3305));
        ui->pb_pH_out->setText(get_last_value_from_param(0x5305));
        ui->pb_SST_in->setText(get_last_value_from_param(0x3303));
        ui->pb_SST_out->setText(get_last_value_from_param(0x5303));
        ui->pb_Turb_in->setText(get_last_value_from_param(0x3301));
        ui->pb_Turb_out->setText(get_last_value_from_param(0x5301));
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
    parameter_to_graph = electric_graph_settings[ui->comboBox->currentIndex()].param_v_fase_1;
    g_mutex.unlock();

    ui->label_graph->setText("Voltaje L1-L2");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_volts_2_clicked()
{
    g_mutex.lock();
    parameter_to_graph = electric_graph_settings[ui->comboBox->currentIndex()].param_v_fase_2;
    g_mutex.unlock();

    ui->label_graph->setText("Voltaje L2-L3");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_volts_3_clicked()
{
    g_mutex.lock();
    parameter_to_graph = electric_graph_settings[ui->comboBox->currentIndex()].param_v_fase_3;
    g_mutex.unlock();

    ui->label_graph->setText("Voltaje L3-L1");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_amps_1_clicked()
{
    g_mutex.lock();
    parameter_to_graph = electric_graph_settings[ui->comboBox->currentIndex()].param_a_fase_1;
    g_mutex.unlock();

    ui->label_graph->setText("Amps L1-L2");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_amps_2_clicked()
{
    g_mutex.lock();
    parameter_to_graph = electric_graph_settings[ui->comboBox->currentIndex()].param_a_fase_2;
    g_mutex.unlock();

    ui->label_graph->setText("Amps L2-L1");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_amps_3_clicked()
{
    g_mutex.lock();
    parameter_to_graph = electric_graph_settings[ui->comboBox->currentIndex()].param_a_fase_3;
    g_mutex.unlock();

    ui->label_graph->setText("Amps L3-L1");
    update_graph_window(parameter_to_graph);
}

void graphwindow::update_graph_window(uint param)
{
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
//    scene->setSceneRect(0,0,100,100);
    QList<float>values;
    int i;
    QPolygon pol;
    QPoint point;

    qDebug() << "parameter_to_graph " << QString("%1").arg(parameter_to_graph, 0, 16);
    g_mutex.lock();
    values = get_list_from_param(param);
    g_mutex.unlock();

    draw_grill(scene);
    //GET GRAPH LINES
    for(i = 0; i < (values.length()); i++)
    {
//        scene->addLine(i*VAL_SEPARATION(num_of_values), values.at(i),(i+1)*VAL_SEPARATION(num_of_values), values.at(i+1), pen);
        point.setX(i*VAL_SEPARATION);
//        point.setY(values.at(i)*-1);
       point.setY(adjusted_y_value(values.at(i))*-1);
       pol.append(point);
    }
    QPainterPath path;
    path.addPolygon(pol);
    scene->addPath(path, pen);

    i = i-1;
    draw_end_ball(scene, i*VAL_SEPARATION, adjusted_y_value(values.at(i)));

    scene->setSceneRect(0,-ui->graphicsView->height(),500,280);

    ui->graphicsView->setScene(scene);

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
    parameter_to_graph = 0x3203;
    g_mutex.unlock();

    ui->label_graph->setText("Gasto Instantáneo");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_gasto_acc_clicked()
{
    g_mutex.lock();
    parameter_to_graph = 0x4203;
    g_mutex.unlock();

    ui->label_graph->setText("Gasto Accumulado");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_nivel_reg_clicked()
{
    g_mutex.lock();
    parameter_to_graph = 0x3201;
    g_mutex.unlock();

    ui->label_graph->setText("Nivel Regulador");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_nivel_clarif_clicked()
{
    g_mutex.lock();
    parameter_to_graph = 0x5201;
    g_mutex.unlock();

    ui->label_graph->setText("Nivel Clarificador");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_presion_aire_clicked()
{
    g_mutex.lock();
    parameter_to_graph = 0x4205;
    g_mutex.unlock();

    ui->label_graph->setText("Presión Aireador");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_presion_filt_clicked()
{
    g_mutex.lock();
    parameter_to_graph = 0x8205;
    g_mutex.unlock();

    ui->label_graph->setText("Presión Filtración");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_OD_in_clicked()
{
    g_mutex.lock();
    parameter_to_graph = 0x3307;
    g_mutex.unlock();

    ui->label_graph->setText("OD entrada");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_pH_in_clicked()
{
    g_mutex.lock();
    parameter_to_graph = 0x3305;
    g_mutex.unlock();

    ui->label_graph->setText("pH entrada");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_SST_in_clicked()
{
    g_mutex.lock();
    parameter_to_graph = 0x3303;
    g_mutex.unlock();

    ui->label_graph->setText("SST entrada");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_Turb_in_clicked()
{
    g_mutex.lock();
    parameter_to_graph = 0x3301;
    g_mutex.unlock();

    ui->label_graph->setText("Turbidez entrada");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_OD_out_clicked()
{
    g_mutex.lock();
    parameter_to_graph = 0x5307;
    g_mutex.unlock();

    ui->label_graph->setText("OD salida");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_pH_out_clicked()
{
    g_mutex.lock();
    parameter_to_graph = 0x5305;
    g_mutex.unlock();

    ui->label_graph->setText("pH salida");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_SST_out_clicked()
{
    g_mutex.lock();
    parameter_to_graph = 0x5303;
    g_mutex.unlock();

    ui->label_graph->setText("SST salida");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_Turb_out_clicked()
{
    g_mutex.lock();
    parameter_to_graph = 0x5301;
    g_mutex.unlock();

    ui->label_graph->setText("Turbidez salida");
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

        if(parameter_to_graph == 0x3203 || parameter_to_graph == 0x4203)
        {
            min_value = 0;
            max_value = 400;
            num_of_lines = 40;
            ui->div_text->setText("10 LPM/div");
        }
        else if(parameter_to_graph == 0x5201 || parameter_to_graph == 0x3201)
        {
            min_value = 0;
            max_value = 10;
            num_of_lines = 20;
            ui->div_text->setText("0.5 m/div");
        }
        else if(parameter_to_graph == 0x4205 || parameter_to_graph == 0x8205)
        {
            min_value = 0;
            max_value = 100;
            num_of_lines = 10;
            ui->div_text->setText("10 PSI/div");
        }

        break;
        // quimicos
    case TYPE_QUIMICOS:
        if(parameter_to_graph == 0x3307 || parameter_to_graph == 0x5307)
        {
            min_value = 0;
            max_value = 40;
            num_of_lines = 40;
            ui->div_text->setText("1 ppm/div");
        }
        else if(parameter_to_graph == 0x3305 || parameter_to_graph == 0x5305)
        {
            min_value = 0;
            max_value = 1000;
            num_of_lines = 20;
            ui->div_text->setText("50 mg/l div");
        }
        else if(parameter_to_graph == 0x3303 || parameter_to_graph == 0x5303)
        {
            min_value = 0;
            max_value = 100;
            num_of_lines = 10;
            ui->div_text->setText("10 NTU/div");
        }
        else if(parameter_to_graph == 0x3301 || parameter_to_graph == 0x5301)
        {
            min_value = 0;
            max_value = 10;
            num_of_lines = 10;
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

}



void graphwindow::on_comboBox_currentIndexChanged(int index)
{
    uint i = 0;
    i = ui->comboBox->currentData().toInt();
    //on_volts_1_clicked();

    parameter_to_graph = electric_graph_settings[ui->comboBox->currentIndex()].param_v_fase_1;

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
