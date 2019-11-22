#include "analisis_graph.h"
#include "ui_analisis_graph.h"
#include "asa_conf_string.h"
#include "parameters.h"
#include <QTimer>
#include <QDebug>
#include <QSettings>
#include <QDir>

#define STEP_INCREMENT  (10)

#define DATA1_ID    (getParamValue(0x3203).toFloat())   /* Caudal */
#define DATA2_ID    (getParamValue(0x4205).toFloat())   /* Presion */

#define DATA4_ID    (getParamValue(0x3001).toFloat())   /* Voltage */
#define DATA5_ID    (getParamValue(0x3002).toFloat())   /* Voltage */
#define DATA6_ID    (getParamValue(0x3003).toFloat())   /* Voltage */
#define DATA3_ID    ((DATA4_ID+DATA5_ID+DATA6_ID)/3)   /* Voltage AVG*/

#define DATA8_ID    (getParamValue(0x3004).toFloat())   /* Amps */
#define DATA9_ID    (getParamValue(0x3005).toFloat())   /* Amps */
#define DATA10_ID   (getParamValue(0x3006).toFloat())   /* Amps */
#define DATA7_ID    ((DATA8_ID+DATA9_ID+DATA10_ID)/3)   /* Amps AVG */

#define DATA11_ID   (getParamValue(0x3009).toFloat())   /* FP */
#define DATA12_ID   (getParamValue(0x3008).toFloat())   /* Coseno */
#define DATA13_ID   (getParamValue(0x3007).toFloat())   /* Frecuencia*/

QList<float> step_series;
QList<float> data1;
QList<float> data2;
QList<float> data3;
QList<float> data4;
QList<float> data5;
QList<float> data6;
QList<float> data7;
QList<float> data8;
QList<float> data9;
QList<float> data10;
QList<float> data11;
QList<float> data12;
QList<float> data13;

#define STEP_DELAY (25000)
//const int hard_coded_percent[10] = {0,30,31,32,35,37,38,45,90,100};
const int hard_coded_percent[10] = {0,10,20,30,40,50,60,70,90,100};

QList<uint> DAC_counts;
QList<uint> Time_wait;


analisis_graph::analisis_graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::analisis_graph)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
    this->move(parent->pos());

    //Clear all data Lists
    clear_data_lists();

    this->setFocusPolicy(Qt::NoFocus);
    ui->graph_button->setFocusPolicy(Qt::NoFocus);
    ui->start_test->setFocusPolicy(Qt::NoFocus);

    ui->tableWidget->setStyleSheet("color: rgb(159,208,186);"
                                   "background-color: transparent;"
                                   "border-radius: 10px;"
                                   "gridline-color: rgb(159,208,186);"
                                   "QHeaderView::section:vertical{"
                                   "border-left: none;"
                                   "}"
                                   "QHeaderView::section:horizontal{"
                                   "border-top: none;"
                                   "}"
                                   );
    ui->tableWidget->setRowCount(3);
    ui->tableWidget->setColumnWidth(0, 49);
    ui->tableWidget->setColumnWidth(1, 49);
    ui->tableWidget->setColumnWidth(2, 49);
    ui->tableWidget->setColumnWidth(3, 49);
    ui->tableWidget->setColumnWidth(4, 49);
    ui->tableWidget->setColumnWidth(5, 49);
    ui->tableWidget->setColumnWidth(6, 49);
    ui->tableWidget->setColumnWidth(7, 49);
    ui->tableWidget->setColumnWidth(8, 49);
    ui->tableWidget->setColumnWidth(9, 49);
    ui->tableWidget->setColumnWidth(10, 49);

    curve = new curve_chart(ui->widget);
    date_wid = new date_widget(ui->datewidget);
    connect(this,SIGNAL(send_datetime(QDateTime)),date_wid,SLOT(update_hour(QDateTime)));
    ui->datewidget->setStyleSheet("background-color: rgb(18,18,49);"
                        "border: none;"
                        "border-radius: 10px;"
                        "color: rgb(161,206,174);");

    //Get step settings
    QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);

    conf.sync();
    conf.beginGroup("Pump-profile-steps");
    DAC_counts << conf.value("DAC_step0").toInt();
    DAC_counts << conf.value("DAC_step1").toInt();
    DAC_counts << conf.value("DAC_step2").toInt();
    DAC_counts << conf.value("DAC_step3").toInt();
    DAC_counts << conf.value("DAC_step4").toInt();
    DAC_counts << conf.value("DAC_step5").toInt();
    DAC_counts << conf.value("DAC_step6").toInt();
    DAC_counts << conf.value("DAC_step7").toInt();
    DAC_counts << conf.value("DAC_step8").toInt();
    DAC_counts << conf.value("DAC_step9").toInt();
    DAC_counts << conf.value("DAC_step10").toInt();
    conf.endGroup();

    conf.sync();
    conf.beginGroup("Pump-profile-time");
    Time_wait << conf.value("time_step0").toInt();
    Time_wait << conf.value("time_step1").toInt();
    Time_wait << conf.value("time_step2").toInt();
    Time_wait << conf.value("time_step3").toInt();
    Time_wait << conf.value("time_step4").toInt();
    Time_wait << conf.value("time_step5").toInt();
    Time_wait << conf.value("time_step6").toInt();
    Time_wait << conf.value("time_step7").toInt();
    Time_wait << conf.value("time_step8").toInt();
    Time_wait << conf.value("time_step9").toInt();
    Time_wait << conf.value("time_step10").toInt();
    conf.endGroup();

    for(int i=0; i< DAC_counts.length(); i++)
    {
        qDebug() << DAC_counts.at(i) << "waits: " << Time_wait.at(i);
    }

    this->show();
}

analisis_graph::~analisis_graph()
{
    delete ui;
}

void analisis_graph::start_analysis()
{
    static en_analysis_state previous_state = AN_IDLE;
    if(analysis_state == AN_IDLE)
    {
        analysis_state = AN_IN_PROGRESS;
        QTimer::singleShot(1000, this, SLOT(analysis_sm()));
        ui->start_test->setStyleSheet("background-color: transparent;"
                                        "background-image: url(:/demo/images/Demo/Pause.png);"
                                        "background-repeat: none;"
                                        "background-position: center;"
                                        "border: none;");
    }
    else if(analysis_state == AN_PAUSE)
    {
        analysis_state = previous_state;
        QTimer::singleShot(100, this, SLOT(analysis_sm()));
        ui->start_test->setStyleSheet("background-color: transparent;"
                                        "background-image: url(:/demo/images/Demo/Pause.png);"
                                        "background-repeat: none;"
                                        "background-position: center;"
                                        "border: none;");
    }
    else if(analysis_state >= AN_ENTER_MANUAL_MODE)
    {
        // PAUSE ANALYSIS
        previous_state = analysis_state;
        analysis_state = AN_PAUSE;
        ui->start_test->setStyleSheet("background-color: transparent;"
                                        "background-image: url(:/demo/images/Demo/Play.png);"
                                        "background-repeat: none;"
                                        "background-position: center;"
                                        "border: none;");
    }

}

void analisis_graph::on_start_test_clicked()
{
}

void analisis_graph::analysis_sm()
{
    static int valve_state = 0;
    static int current_round = 0;

    switch (analysis_state) {
    case AN_IN_PROGRESS:
        valve_state = 0;
        current_round = 0;
        clear_data_lists();
        qDebug() << "Starting Analysis";
        QTimer::singleShot(500, this, SLOT(analysis_sm()));
        analysis_state = AN_STOP_ALL_MODULES;
        break;
    case AN_STOP_ALL_MODULES:
        qDebug() << "Stopping All modules";
        analysis_sm_stop_all();
        QTimer::singleShot(500, this, SLOT(analysis_sm()));
        analysis_state = AN_ENTER_MANUAL_MODE;
        break;
    case AN_ENTER_MANUAL_MODE:
        qDebug() << "Entering Manual Mode";
        analysis_sm_enter_manual();
        QTimer::singleShot(500, this, SLOT(analysis_sm()));
        analysis_state = AN_TURN_ON_PUMP;
        break;
    case AN_TURN_ON_PUMP:
        qDebug() << "Turning ON Pump";
        analysis_sm_toggle_pump();
        qDebug() << "Close valve and wait";
        demo_set_percentaje((int)valve_state);
        QTimer::singleShot(500, this, SLOT(analysis_sm()));
        analysis_state = AN_MOVE_VALVE;
        break;
    case AN_MOVE_VALVE:
        qDebug() << "-------Valve at "<< valve_state << "%";
        // SEND VALVE % HERE
        demo_set_percentaje((int)valve_state);
        step_series.append(valve_state);
        ui->progressBar->setValue(valve_state);
//        QTimer::singleShot(STEP_DELAY, this, SLOT(analysis_sm()));
        QTimer::singleShot(Time_wait.at(current_round), this, SLOT(analysis_sm()));
        analysis_state = AN_TAKE_READING;
        break;
    case AN_TAKE_READING:
//        valve_state += STEP_INCREMENT;
//        valve_state = hard_coded_percent[current_round];
        valve_state = hard_coded_percent[DAC_counts.at(current_round)];
        if(valve_state <= 100)
        {
            qDebug() << "Taking Reads at "<< valve_state << "%";
            capture_data(current_round);
            select_data_and_graph();
            current_round++;
            QTimer::singleShot(100, this, SLOT(analysis_sm()));
            analysis_state = AN_MOVE_VALVE;
        }
        else
        {
            QTimer::singleShot(500, this, SLOT(analysis_sm()));
            analysis_state = AN_TURN_OFF_PUMP;
        }
        break;
    case AN_TURN_OFF_PUMP:
        qDebug() << "Turn OFF Pump";
        analysis_sm_toggle_pump();
        QTimer::singleShot(50, this, SLOT(analysis_sm()));
        analysis_state = AN_COMPLETE;
        break;
    case AN_COMPLETE:
        qDebug() << "Test Complete";
        analysis_state = AN_IDLE;
        ui->start_test->setStyleSheet("background-color: transparent;"
                                        "background-image: url(:/demo/images/Demo/Play.png);"
                                        "background-repeat: none;"
                                        "background-position: center;"
                                        "border: none;");

        qDebug() << data1;
        qDebug() << data2;
        qDebug() << data3;
        qDebug() << data4;
        qDebug() << data5;
        qDebug() << data6;
        qDebug() << data7;
        qDebug() << data8;
        qDebug() << data9;
        qDebug() << data10;
        qDebug() << data11;
        qDebug() << data12;
        qDebug() << data13;

        // Draw Chart
        select_data_and_graph();
        break;
    default:
        break;
    }
}

void analisis_graph::capture_data(int round)
{
    //Appen data to Lists
    data1.append(DATA1_ID);
    data2.append(DATA2_ID);
    data3.append(DATA3_ID);
    data4.append(DATA4_ID);
    data5.append(DATA5_ID);
    data6.append(DATA6_ID);
    data7.append(DATA7_ID);
    data8.append(DATA8_ID);
    data9.append(DATA9_ID);
    data10.append(DATA10_ID);
    data11.append(DATA11_ID);
    data12.append(DATA12_ID);
    data13.append(DATA13_ID);

//    ui->tableWidget->setItem(0,round,new QTableWidgetItem(QString::number(index_to_data_list(ui->comboBox->currentIndex()).last(),'f',2)));
//    ui->tableWidget->setItem(1,round,new QTableWidgetItem(QString::number(index_to_data_list(ui->comboBox_2->currentIndex()).last(),'f',2)));
//    ui->tableWidget->setItem(2,round,new QTableWidgetItem(QString::number(index_to_data_list(ui->comboBox_3->currentIndex()).last(),'f',2)));
//    ui->tableWidget->setItem(3,round,new QTableWidgetItem(QString::number(DATA4_ID,'f',2)));
//    ui->tableWidget->setItem(4,round,new QTableWidgetItem(QString::number(DATA5_ID,'f',2)));
//    ui->tableWidget->setItem(5,round,new QTableWidgetItem(QString::number(DATA6_ID,'f',2)));
//    ui->tableWidget->setItem(6,round,new QTableWidgetItem(QString::number(DATA7_ID,'f',2)));
//    ui->tableWidget->setItem(7,round,new QTableWidgetItem(QString::number(DATA8_ID,'f',2)));
//    ui->tableWidget->setItem(8,round,new QTableWidgetItem(QString::number(DATA9_ID,'f',2)));
//    ui->tableWidget->setItem(9,round,new QTableWidgetItem(QString::number(DATA10_ID,'f',2)));
//    ui->tableWidget->setItem(10,round,new QTableWidgetItem(QString::number(DATA11_ID,'f',2)));;
//    ui->tableWidget->setItem(11,round,new QTableWidgetItem(QString::number(DATA12_ID,'f',2)));;
//    ui->tableWidget->setItem(12,round,new QTableWidgetItem(QString::number(DATA13_ID,'f',2)));;

}

void analisis_graph::clear_data_lists()
{
    data1.clear();
    data2.clear();
    data3.clear();
    data4.clear();
    data5.clear();
    data6.clear();
    data7.clear();
    data8.clear();
    data9.clear();
    data10.clear();
    data11.clear();
    data12.clear();
    data13.clear();

    step_series.clear();
    master_data.clear();
    ui->progressBar->setValue(0);

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setRowCount(3);

}

void analisis_graph::select_data_and_graph()
{
    master_data.clear();

    master_data << data1 << data2 << data3 << data4 << data5 << data6
                << data7 << data8 << data9 << data10 << data11 << data12 << data13 << step_series;

    if(!master_data.isEmpty())
    {
        curve->draw_chart(master_data.at(ui->comboBox->currentIndex()),
                      master_data.at(ui->comboBox_2->currentIndex()),
                          ui->comboBox->currentText(),
                          ui->comboBox_2->currentText(),
                          ui->checkBox->isChecked());

        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setRowCount(3);
        for(int i = 0; i < master_data.at(0).length(); i++)
        {
//            qDebug() << "Item debug: " << QString::number(index_to_data_list(ui->comboBox_3->currentIndex()).at(i));
            ui->tableWidget->setItem(0,i,new QTableWidgetItem(QString::number(master_data.at(ui->comboBox->currentIndex())
                                                                              .at(i),'f',2)));
            ui->tableWidget->setItem(1,i,new QTableWidgetItem(QString::number(master_data.at(ui->comboBox_2->currentIndex())
                                                                              .at(i),'f',2)));
            ui->tableWidget->setItem(2,i,new QTableWidgetItem(QString::number(master_data.at(ui->comboBox_3->currentIndex())
                                                                              .at(i),'f',2)));
        }
    //
    }
}

QList<float> analisis_graph::index_to_data_list(int index)
{
    switch(index)
    {
    case 0:
        return data1;
        break;
    case 1:
        return data2;
        break;
    case 2:
        return data3;
        break;
    case 3:
        return data4;
        break;
    case 4:
        return data5;
        break;
    case 5:
        return data6;
        break;
    case 6:
        return data7;
        break;
    case 7:
        return data8;
        break;
    case 8:
        return data9;
        break;
    case 9:
        return data10;
        break;
    case 10:
        return data11;
        break;
    case 11:
        return data12;
        break;
    case 12:
        return data13;
        break;
    case 13:
    default:
        return step_series;
        break;
    }
}

void analisis_graph::analysis_sm_stop_all()
{
    QString str;
    str = "04";
//    str = "03";
    output_op_mode("3E00", str); /* Antes 3600 */
    output_op_mode("4600", str);
    output_op_mode("5600", str);
    output_op_mode("9600", str);
    output_op_mode("9700", str);
    output_op_mode("3600", str);
}

void analisis_graph::analysis_sm_enter_manual()
{
    QString str;
    str = "03";
    output_op_mode("3E00", str); /* Antes 3600 */
    output_op_mode("4600", str);
//    output_op_mode("5600", str);
//    output_op_mode("9600", str);
//    output_op_mode("9700", str);
//    output_op_mode("3600", str);
}

void analisis_graph::analysis_sm_toggle_pump()
{
    // Numero de salida en DECIMAL!
    output_control_toggle(13826); // 3602
}

void analisis_graph::on_graph_button_clicked()
{
    this->close();
}

void analisis_graph::update_time(QDateTime datetime)
{
    send_datetime(datetime);
}

void analisis_graph::on_comboBox_currentIndexChanged(int index)
{
    select_data_and_graph();
}

void analisis_graph::on_comboBox_2_currentIndexChanged(int index)
{
    select_data_and_graph();
}

void analisis_graph::on_comboBox_3_currentIndexChanged(int index)
{
    select_data_and_graph();
}

void analisis_graph::on_checkBox_toggled(bool checked)
{
    select_data_and_graph();
}

void analisis_graph::on_start_test_released()
{
    start_analysis();
}
