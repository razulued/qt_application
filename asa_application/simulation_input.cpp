#include "simulation_input.h"
#include "ui_simulation_input.h"
#include "asa_protocol.h"

QDateTime simulation_input::simDateTime;

simulation_input::simulation_input(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::simulation_input)
{
    ui->setupUi(this);

    simDateTime = QDateTime::currentDateTime();

    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    this->show();
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
}

void simulation_input::on_pushButton_4_clicked()
{
    time_running = false;
}
