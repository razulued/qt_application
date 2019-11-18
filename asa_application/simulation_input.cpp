#include "simulation_input.h"
#include "ui_simulation_input.h"
#include "asa_protocol.h"
#include "dataproccess.h"
#include "asa_conf_string.h"

//#define USE_SIM (1)
QDateTime simulation_input::simDateTime;

simulation_input::simulation_input(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::simulation_input)
{
    ui->setupUi(this);

    simDateTime = QDateTime::currentDateTime();

    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    time_running = true;
    QTimer::singleShot(1000, this, SLOT(add_seconds()));

#if USE_SIM
    // not show
#else
    this->show();
#endif
}

simulation_input::~simulation_input()
{
    delete ui;
}

void simulation_input::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked())
    {
        store_value_by_ID((0x3000), "1");
    }
    else
    {
        store_value_by_ID((0x3000), "0");
    }
}
void simulation_input::on_checkBox_4_clicked()
{
    if(ui->checkBox_4->isChecked())
    {
        store_value_by_ID((0x3010), "1");
    }
    else
    {
        store_value_by_ID((0x3010), "0");
    }
}
void simulation_input::on_checkBox_5_clicked()
{
    if(ui->checkBox_5->isChecked())
    {
        store_value_by_ID((0x3020), "1");
    }
    else
    {
        store_value_by_ID((0x3020), "0");
    }
}
void simulation_input::on_checkBox_6_clicked()
{
    if(ui->checkBox_6->isChecked())
    {
        store_value_by_ID((0x3030), "1");
    }
    else
    {
        store_value_by_ID((0x3030), "0");
    }
}

void simulation_input::on_horizontalScrollBar_actionTriggered(int action)
{
    store_value_by_ID((0x3201), QString::number(ui->horizontalScrollBar->value()));
    ui->lineEdit->setText(QString::number(ui->horizontalScrollBar->value()));
}

void simulation_input::on_lineEdit_editingFinished()
{
    store_value_by_ID((0x3201), ui->lineEdit->text());
    ui->horizontalScrollBar->setValue(ui->lineEdit->text().toInt());
}

void simulation_input::on_checkBox_2_clicked()
{
    if(ui->checkBox_2->isChecked())
    {
        store_value_by_ID((0x4000), "1");
    }
    else
    {
        store_value_by_ID((0x4000), "0");
    }
}

void simulation_input::on_checkBox_3_clicked()
{
    if(ui->checkBox_3->isChecked())
    {
        store_value_by_ID((0x4010), "1");
    }
    else
    {
        store_value_by_ID((0x4010), "0");
    }
}

void simulation_input::on_checkBox_7_clicked()
{
    if(ui->checkBox_7->isChecked())
    {
        store_value_by_ID((0x4020), "1");
    }
    else
    {
        store_value_by_ID((0x4020), "0");
    }
}

void simulation_input::on_checkBox_8_clicked()
{
    if(ui->checkBox_8->isChecked())
    {
        store_value_by_ID((0x4030), "1");
    }
    else
    {
        store_value_by_ID((0x4030), "0");
    }
}

void simulation_input::on_horizontalScrollBar_2_actionTriggered(int action)
{
    store_value_by_ID((0x3203), QString::number(ui->horizontalScrollBar_2->value()));
    ui->lineEdit_2->setText(QString::number(ui->horizontalScrollBar_2->value()));
}

void simulation_input::on_horizontalScrollBar_3_actionTriggered(int action)
{
    store_value_by_ID((0x6203), QString::number(ui->horizontalScrollBar_3->value()));
    ui->lineEdit_3->setText(QString::number(ui->horizontalScrollBar_3->value()));
}

void simulation_input::on_horizontalScrollBar_4_actionTriggered(int action)
{
    store_value_by_ID((0x5201), QString::number(ui->horizontalScrollBar_4->value()));
    ui->lineEdit_4->setText(QString::number(ui->horizontalScrollBar_4->value()));
}

void simulation_input::on_horizontalScrollBar_5_actionTriggered(int action)
{
    store_value_by_ID((0x3204), QString::number(ui->horizontalScrollBar_5->value()));
    ui->lineEdit_11->setText(QString::number(ui->horizontalScrollBar_5->value()));
}

void simulation_input::on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    simDateTime = dateTime;
}

void simulation_input::on_pushButton_clicked()
{
    simDateTime = simDateTime.addSecs(60*60);
    ui->dateTimeEdit->setDateTime(simDateTime);
}

void simulation_input::on_pushButton_2_clicked()
{
    simDateTime = simDateTime.addSecs(1);
    ui->dateTimeEdit->setDateTime(simDateTime);
}

void simulation_input::on_pushButton_3_clicked()
{
    time_running = true;
    QTimer::singleShot(1000, this, SLOT(add_seconds()));

}

void simulation_input::add_seconds()
{
    simDateTime = simDateTime.addSecs(1);
    ui->dateTimeEdit->setDateTime(simDateTime);

    if(true == time_running)
    {
        QTimer::singleShot(1000, this, SLOT(add_seconds()));

    }

#if USE_SIM
    uint val;
    static uint count = 0;
    static uint count_2 = 0;
    if(count_2 > 10)
    {
        store_value_by_ID((0x3000), "1");
        count_2++;
        if(count_2 > 20)
        {
            count_2 = 0;
        }
    }
    else
    {
        store_value_by_ID((0x3000), "0");
        count_2++;
    }

    static uint count_3 = 0;
    if(count_3 > 20)
    {
        store_value_by_ID((0x4000), "1");
        count_3++;
        if(count_3 > 30)
        {
            count_3 = 0;
        }
    }
    else
    {
        store_value_by_ID((0x4000), "0");
        count_3++;
    }

    if(count++ > 4)
    {
        count = 0;
        // PH 6-8
        val = qrand() % 200 + 600;
        store_value_by_ID((0x3301), QString("%1").arg(val, 0, 16));

        // SST 250-350
        val = qrand() % 10000 + 25000;
        store_value_by_ID((0x3305), QString("%1").arg(val, 0, 16));

        // ND  1-3
        val = qrand() % 200 + 100;
        store_value_by_ID((0x3201), QString("%1").arg(val, 0, 16));

        // Q  5-10
        val = qrand() % 131 + 438;
        store_value_by_ID((0x3203), QString("%1").arg(val, 0, 16));

        // A L1
        val = qrand() % 2000 + 3000;
        store_value_by_ID((0x3004), QString("%1").arg(val, 0, 16));
        val = qrand() % 2000 + 3000;
        store_value_by_ID((0x3005), QString("%1").arg(val, 0, 16));
        val = qrand() % 2000 + 3000;
        store_value_by_ID((0x3006), QString("%1").arg(val, 0, 16));

        // REACTOR
        // OD  1.5-2.5
        val = qrand() % 100 + 150;
        store_value_by_ID((0x4307), QString("%1").arg(val, 0, 16));

        // P  5.5-6
        val = qrand() % 19 + 660;
        store_value_by_ID((0x4205), QString("%1").arg(val, 0, 16));

        // A L1
        val = qrand() % 2000 + 6500;
        store_value_by_ID((0x4004), QString("%1").arg(val, 0, 16));
        val = qrand() % 2000 + 6500;
        store_value_by_ID((0x4005), QString("%1").arg(val, 0, 16));
        val = qrand() % 2000 + 6500;
        store_value_by_ID((0x4006), QString("%1").arg(val, 0, 16));

        // Cloracion
        // turbidez
        val = qrand() % 130 + 30;
        store_value_by_ID((0x6303), QString("%1").arg(val, 0, 16));

        // turbidez
        val = qrand() % 600 + 500;
        store_value_by_ID((0x6305), QString("%1").arg(val, 0, 16));

    }
#endif
}

void simulation_input::on_pushButton_4_clicked()
{
    time_running = false;
}

void simulation_input::on_lineEdit_5_editingFinished()
{
    store_value_by_ID((0x0201), ui->lineEdit_5->text());
}

void simulation_input::on_lineEdit_6_editingFinished()
{
    store_value_by_ID((0x0100), ui->lineEdit_6->text());

}

void simulation_input::on_lineEdit_7_editingFinished()
{
    store_value_by_ID((0x0601), ui->lineEdit_7->text());
}

void simulation_input::on_lineEdit_8_editingFinished()
{
    store_value_by_ID((0x0303), ui->lineEdit_8->text());
}

void simulation_input::on_lineEdit_9_editingFinished()
{
    store_value_by_ID((0x0B01), ui->lineEdit_9->text());
}

void simulation_input::on_pushButton_6_clicked()
{
    ui->lineEdit_10->setText("|1800|");
}

void simulation_input::on_pushButton_7_clicked()
{
    ui->lineEdit_10->setText("|1801|");
}

void simulation_input::on_pushButton_8_clicked()
{
    ui->lineEdit_10->setText("|1802:N|");
}

void simulation_input::on_pushButton_9_clicked()
{
    ui->lineEdit_10->setText("|1880:Name,IDProceso,Periodo,Epoch,[Descripcion],[RegID,RegID,...]|");
}

void simulation_input::on_pushButton_10_clicked()
{
    ui->lineEdit_10->setText("|1881:Descripcion,Tipo,Unit1,Unit2,Unit3|");
}

int simulation_input::intString2Int(QString inputString)
{
    int temp;
    bool ok;
//    temp = inputString.toInt(); //Casting from String to Int (Hexadecimal representation)
    temp = inputString.toInt(&ok,16); //Casting from String to Int (Hexadecimal representation)

    if(false == ok)
    {
        temp = 0;
    }
    return temp;
}

void simulation_input::on_pushButton_5_clicked()
{
    //Send Command..
    QString cmd = ui->lineEdit_10->text();
    qDebug() << "Sending String: "<< cmd;

    QStringList ID_Parameters = cmd.split("|");
    QStringList realParameters ;


    for(int i = 0; i < ID_Parameters.length() ; i++)
    {
        realParameters = ID_Parameters[i].split(":");

        if(realParameters.length() > 1)
        {
//            qDebug() << "+++++++" << realParameters[0] << realParameters[1];
            store_value_by_ID(intString2Int(realParameters[0]) , realParameters[1]);
        }
        else
        {
            // only one part was found, this could be a zero lengh ID
//            qDebug() << "++++(Z)" << realParameters[0];
            store_value_by_ID(intString2Int(realParameters[0]) , "");
        }
    }
}

void simulation_input::on_pushButton_11_clicked()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText(get_config_string());
}
