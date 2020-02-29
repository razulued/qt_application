#include "analisis_demo.h"
#include "ui_analisis_demo.h"
#include "donut_chart.h"
#include "parameters.h"
#include "asa_conf_string.h"
#include "pid.h"
#include <QTimer>
#include <QDebug>

#define L1_VoltID   (0x3001)
#define L2_VoltID   (0x3002)
#define L3_VoltID   (0x3003)
#define L1_AmpsID   (0x3004)
#define L2_AmpsID   (0x3005)
#define L3_AmpsID   (0x3006)

#define DONUT1_CAUDAL    (getParamValue(0x3203).toFloat())
#define DONUT1_MAX      (100)
#define DONUT2_PRESION   (get_presion())
//#define DONUT2_PRESION   (getParamValue(0xFF05).toFloat())
#define DONUT2_MAX      (100)
#define DONUT3_VOLT     ((getParamValue(L1_VoltID).toFloat()+\
                        getParamValue(L2_VoltID).toFloat()+\
                        (getParamValue(L3_VoltID).toFloat()))/3)
#define DONUT3_MAX      (440)
#define DONUT4_AMP      ((getParamValue(L1_AmpsID).toFloat()+\
                        getParamValue(L2_AmpsID).toFloat()+\
                        (getParamValue(L3_AmpsID).toFloat()))/3)
#define DONUT4_MAX      (10)


float get_presion()
{
    bool ok;
    static float presion_array[3];
    static int presion_index = 0;
    float presion_acc = 0;
    static float presion_avg;

    presion_array[presion_index++] = getParamValue(0x4205).toFloat();
    if( presion_index >= 3) presion_index = 0;
    for(int i = 0; i < 3; i++)
    {
        presion_acc += presion_array[i];
    }
    presion_avg = presion_acc / 3;
    QString presion_string = QString::number(presion_avg, 'f', 0);
//    QString presion_string = QString::number(getParamValue(0x4205).toFloat(), 'f', 0);
    return presion_string.toInt(&ok);
}

analisis_demo::analisis_demo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::analisis_demo)
{
    ui->setupUi(this);

    this->move(parent->pos());

    ui->left_menu->hide();
    this->setStyleSheet("background-color:rgb(45,43,83);"
                        "color:white"
                        );
    this->setFocusPolicy(Qt::NoFocus);
    ui->close_menu->setFocusPolicy(Qt::NoFocus);
    ui->graph_button->setFocusPolicy(Qt::NoFocus);
    ui->left_menu->setFocusPolicy(Qt::NoFocus);
    ui->pushButton->setFocusPolicy(Qt::NoFocus);
    ui->show_menu->setFocusPolicy(Qt::NoFocus);

    //Hide window bars and buttons
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);

    date_wid = new date_widget(ui->datewidget);
    connect(this,SIGNAL(send_datetime(QDateTime)),date_wid,SLOT(update_hour(QDateTime)));
    ui->datewidget->setStyleSheet("background-color: rgb(18,18,49);"
                        "border: none;"
                        "border-radius: 10px;"
                        "color: rgb(161,206,174);");

    // Center donut graphs
    ui->frame->move(this->rect().center() - ui->frame->rect().center());
    ui->frame->setStyleSheet("background-color:rgb(45,43,83);"
                             "border: none;");
    //Position aletas
//    ui->aleta1->move(ui->widget->x() - 70, ui->widget->y());

    // DONUTS
    donut_chart *donut_1 = new donut_chart("Caudal",DONUT1_CAUDAL, DONUT1_MAX, ui->widget);
    connect(this, SIGNAL(update_donut_1(float)), donut_1, SLOT(update_data(float)));

    donut_chart *donut_2 = new donut_chart("Presión",DONUT2_PRESION, DONUT2_MAX, ui->widget_2);
    connect(this, SIGNAL(update_donut_2(float)), donut_2, SLOT(update_data(float)));

    donut_chart *donut_3 = new donut_chart("Voltaje AVG",DONUT3_VOLT, DONUT3_MAX, ui->widget_3);
    connect(this, SIGNAL(update_donut_3(float)), donut_3, SLOT(update_data(float)));

    donut_chart *donut_4 = new donut_chart("Amperaje AVG",DONUT4_AMP, DONUT4_MAX, ui->widget_4);
    connect(this, SIGNAL(update_donut_4(float)), donut_4, SLOT(update_data(float)));

    // ALETAS
    ui->aleta1->hide();
    ui->aleta2->hide();
    ui->aleta3->hide();
    ui->aleta4->hide();

    QList<uint> volt_list;
    volt_list << L1_VoltID << L2_VoltID << L3_VoltID;
    QList<QString> fase_names;
    fase_names << "L1" << "L2" << "L3";
    aleta_1 = new aleta_widget(volt_list, fase_names, ui->aleta3);
    connect(donut_3, SIGNAL(clicked()), aleta_1, SLOT(toogle_hide_show()));

    QList<uint> amp_list;
    amp_list << L1_AmpsID << L2_AmpsID << L3_AmpsID;
    aleta_2 = new aleta_widget(amp_list, fase_names, ui->aleta4);
    connect(donut_4, SIGNAL(clicked()), aleta_2, SLOT(toogle_hide_show()));

    // Disable A000 control
    ui->control_A000->setEnabled(false);
    ui->control_A000->setValue(0);
    ui->setpoint_presion->setEnabled(false);
}

analisis_demo::~analisis_demo()
{
    delete ui;
}

void analisis_demo::update_data()
{
    update_donut_1(DONUT1_CAUDAL);
    update_donut_2(DONUT2_PRESION);
    update_donut_3(DONUT3_VOLT);
    update_donut_4(DONUT4_AMP);

    if(NULL != aleta_1)
    {
        aleta_1->update_data();
    }
    if(NULL != aleta_2)
    {
        aleta_2->update_data();
    }
}

void analisis_demo::update_datetime(QDateTime datetime)
{
    time = datetime;
    send_datetime(time);
}

void analisis_demo::on_pushButton_clicked()
{
    this->accept();
}

aleta_widget::aleta_widget(QList<uint> id_list, QList<QString> names, QWidget *parent):
    QWidget(parent)
{
    parent_widget = parent;
    layout = new QVBoxLayout(parent);

    list_widget = new QListWidget();
    list_widget->setFocusPolicy(Qt::NoFocus);
    list_widget->clear();
    list_widget->setStyleSheet("background: transparent;"
                               "color: rgb(146,205,186);"
                               "border: none;"
                               "border-image: none;"
                               "font-weight: bold;"
                               "font-size: 15px;");
    QFont font("Liberation Mono Bold",15,1);
    list_widget->setFont(font);

    IDS = id_list;
    NAMES = names;


    for(int i=0; i < IDS.length(); i++)
    {
        list_widget->addItem(NAMES.at(i)+": "+
                             getParamValue_and_units(IDS.at(i)));
        list_widget->item(i)->setTextAlignment(Qt::AlignCenter);
    }
    layout->addWidget(list_widget);
    parent->setLayout(layout);
}

aleta_widget::~aleta_widget()
{
}

void aleta_widget::update_data()
{
    list_widget->clear();
    for(int i=0; i < IDS.length(); i++)
    {
        list_widget->addItem(NAMES.at(i)+": "+
                             getParamValue_and_units(IDS.at(i)));
        list_widget->item(i)->setTextAlignment(Qt::AlignCenter);
    }
    layout->addWidget(list_widget);
}

void aleta_widget::toogle_hide_show()
{
    if(show_aleta == false)
    {
        show_aleta = true;
        parent_widget->show();
    }
    else
    {
        show_aleta = false;
        parent_widget->hide();
    }
}

void analisis_demo::on_close_menu_clicked()
{
    ui->left_menu->hide();
}

void analisis_demo::on_show_menu_clicked()
{
    ui->left_menu->show();
}

void analisis_demo::on_graph_button_clicked()
{
    if(graph != NULL)
    {
        delete graph;
    }
    graph = new analisis_graph(this);
    connect(this,SIGNAL(send_datetime(QDateTime)),graph,SLOT(update_time(QDateTime)));
    send_datetime(time);
}

void analisis_demo::on_control_A000_valueChanged(double arg1)
{
    demo_set_percentaje(arg1);

    float mA_val = arg1 * (-0.16) + 20;
    QString mA_String = QString::number(mA_val, 'f', 2);

    ui->valv_ma->setText(mA_String + " mA");
}

void analisis_demo::on_radioButton_2_toggled(bool checked)
{
    if(checked)
    {
        ui->control_A000->setEnabled(true);
        demo_set_percentaje(ui->control_A000->value());
    }
    else
    {
        ui->control_A000->setEnabled(false);
    }
}

pid_ctrl_t pid;
float valve_control = 0;

void analisis_demo::on_radioButton_toggled(bool checked)
{
    if(checked)
    {
        ui->setpoint_presion->setEnabled(true);
        pid_init(&pid);

        /* PD controller. */
        pid_set_gains(&pid, 5., 0, 1.);

        QTimer::singleShot(10, this, SLOT(PID_main_func()));
    }
    else
    {
        ui->setpoint_presion->setEnabled(false);
    }
}


void analisis_demo::PID_main_func()
{
    qDebug() << "PID Main";
    if(ui->setpoint_presion->isEnabled())
    {
        float error = DONUT2_PRESION - ui->setpoint_presion->value();
        float valve_action;
        valve_action = pid_process(&pid, error);
        qDebug() << "error: " << error;
        qDebug() << "valve action: " << valve_action;
//        ui->control_A000->setValue(valve_percent);

        if(valve_action > 0)
        {
            qDebug() << "Cerrar Valvula";
            if(valve_action > 50)
            {
                qDebug() << "Cerrar Valvula 5%";
                ui->control_A000->setValue(ui->control_A000->value() - 1);
                QTimer::singleShot(2000, this, SLOT(PID_main_func()));
            }
            else if(valve_action > 20)
            {
                qDebug() << "Cerrar Valvula 5%";
                ui->control_A000->setValue(ui->control_A000->value() - 1);
                QTimer::singleShot(5000, this, SLOT(PID_main_func()));
            }
            else
            {
                qDebug() << "Cerrar Valvula 1%";
                ui->control_A000->setValue(ui->control_A000->value() - 1);
                QTimer::singleShot(15000, this, SLOT(PID_main_func()));
            }
        }
        else if(valve_action < 0)
        {
            qDebug() << "Abrir Valvula";
            qDebug() << "Cerrar Valvula";
            if(valve_action < -50)
            {
                qDebug() << "Abrir Valvula 5%";
                ui->control_A000->setValue(ui->control_A000->value() + 1);
                QTimer::singleShot(2000, this, SLOT(PID_main_func()));
            }
            else if(valve_action < -20)
            {
                qDebug() << "Abrir Valvula 5%";
                ui->control_A000->setValue(ui->control_A000->value() + 1);
                QTimer::singleShot(5000, this, SLOT(PID_main_func()));
            }
            else
            {
                qDebug() << "Abrir Valvula 1%";
                ui->control_A000->setValue(ui->control_A000->value() + 1);
                QTimer::singleShot(15000, this, SLOT(PID_main_func()));
            }
        }
        else
        {
            qDebug() << "No control needed Valvula 1%";
        }

    }
    else
    {
        qDebug() << "PID Stop";
    }
}
