#include "graphwindow.h"
#include "ui_graphwindow.h"
#include <QGraphicsScene>
#include "statistics.h"
#include <QList>
#include <QBrush>
#include <QDebug>
#include "parameters.h"
#include <QMutex>

QMutex g_mutex;

#define VAL_SEPARATION (ui->graphicsView->width()/10)

enum
{
    TYPE_ELECTRICOS,
    TYPE_FISICOS,
    TYPE_QUIMICOS
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
    gradient.setColorAt(1, QColor::fromRgb(255, 255, 255,255));
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



    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
}

graphwindow::~graphwindow()
{
    delete ui;
}

void graphwindow::show_graph(uint element_type)
{
    g_mutex.lock();
    switch(element_type)
    {
    case TYPE_ELECTRICOS:
        ui->top_bar->setStyleSheet("background-image: url(:/barras/screen800x600/barras/PE_bar.png);");
        parameter_to_graph = 0x3001;
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
        ui->volts_1->setText(get_last_value_from_param(0x3001));
        ui->volts_2->setText(get_last_value_from_param(0x3002));
        ui->volts_3->setText(get_last_value_from_param(0x3003));

        ui->amps_1->setText(get_last_value_from_param(0x3004));
        ui->amps_2->setText(get_last_value_from_param(0x3005));
        ui->amps_3->setText(get_last_value_from_param(0x3006));
        break;
        // fisicos
    case TYPE_FISICOS:
        ui->pb_gasto_inst->setText(get_last_value_from_param(0x3203));
        ui->pb_gasto_acc->setText(get_last_value_from_param(0x4203));

        ui->pb_nivel_clarif->setText(get_last_value_from_param(0x5201));
        ui->pb_nivel_reg->setText(get_last_value_from_param(0x3201));

        ui->pb_presion_aire->setText(get_last_value_from_param(0x4204));
        ui->pb_presion_filt->setText(get_last_value_from_param(0x8204));
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
    parameter_to_graph = 0x3001;
    g_mutex.unlock();

    ui->label_graph->setText("Voltaje L1-L2");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_volts_2_clicked()
{
    g_mutex.lock();
    parameter_to_graph = 0x3002;
    g_mutex.unlock();

    ui->label_graph->setText("Voltaje L2-L3");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_volts_3_clicked()
{
    g_mutex.lock();
    parameter_to_graph = 0x3003;
    g_mutex.unlock();

    ui->label_graph->setText("Voltaje L3-L1");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_amps_1_clicked()
{
    g_mutex.lock();
    parameter_to_graph = 0x3004;
    g_mutex.unlock();

    ui->label_graph->setText("Amps L1-L2");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_amps_2_clicked()
{
    g_mutex.lock();
    parameter_to_graph = 0x3005;
    g_mutex.unlock();

    ui->label_graph->setText("Amps L2-L1");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_amps_3_clicked()
{
    g_mutex.lock();
    parameter_to_graph = 0x3006;
    g_mutex.unlock();

    ui->label_graph->setText("Amps L3-L1");
    update_graph_window(parameter_to_graph);
}

void graphwindow::update_graph_window(uint param)
{
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
//    scene->setSceneRect(0,0,100,100);
    QList<int>values;
    int i;
    QPolygon pol;
    QPoint point;

    g_mutex.lock();
    values = get_list_from_param(param);
    g_mutex.unlock();

    for(i = 0; i < (values.length()); i++)
    {
//        scene->addLine(i*VAL_SEPARATION(num_of_values), values.at(i),(i+1)*VAL_SEPARATION(num_of_values), values.at(i+1), pen);
        point.setX(i*VAL_SEPARATION);
        point.setY(values.at(i)*-1);
        pol.append(point);
    }

//    QRadialGradient gradient2(center,10,center);
    QRadialGradient gradient2(QPointF((i-1)*VAL_SEPARATION,values.at(i-1)*-1),20);
//    QBrush brush(Qt::LinearGradientPattern);
    gradient2.setColorAt(0, QColor::fromRgb(255, 255, 255,255));
    gradient2.setColorAt(1, QColor::fromRgb(0, 0, 0,0));
    QBrush brush(gradient2);
    pen2.setBrush(brush);

    pen2.setWidth(10);

    QPainterPath path;
    path.addPolygon(pol);
    scene->addPath(path, pen);
    scene->addEllipse((i-1)*VAL_SEPARATION,(values.at(i-1)+5)*-1,10, 10,pen2);
    scene->setSceneRect(0,-240,500,280);

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
    parameter_to_graph = 0x4204;
    g_mutex.unlock();

    ui->label_graph->setText("Presión Aireador");
    update_graph_window(parameter_to_graph);
}

void graphwindow::on_pb_presion_filt_clicked()
{
    g_mutex.lock();
    parameter_to_graph = 0x8204;
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
