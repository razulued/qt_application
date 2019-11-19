#include "date_widget.h"
#include "ui_date_widget.h"
#include <QDebug>
date_widget::date_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::date_widget)
{
    ui->setupUi(this);
//    this->setStyleSheet("background-color: rgb(18,18,49);"
//                        "border: none;"
//                        "border-radius: 10px;"
//                        "color:red;");
}

date_widget::~date_widget()
{
    delete ui;
}

void date_widget::update_hour(QDateTime datetime)
{
    QString hour = QString::number(datetime.time().hour())+":"+QString("%1").arg(datetime.time().minute(), 2, 10, QChar('0'));
    ui->label_hour->setText(hour);
    if(datetime.time().hour()>=12)
    {
        ui->label_ampm->setText("PM");
    }
    else
    {
        ui->label_ampm->setText("AM");
    }
    ui->label_day->setText(QString::number(datetime.date().day()));
    ui->label_month->setText(get_month_string(datetime));
    ui->label_year->setText(QString::number(datetime.date().year()));

}

QString date_widget::get_month_string(QDateTime time)
{
    QString mes;
    switch(time.date().month())
    {
    case 1:
        mes = tr("ENE");
        break;
    case 2:
        mes = tr("FEB");
        break;
    case 3:
        mes = tr("MAR");
        break;
    case 4:
        mes = tr("ABR");
        break;
    case 5:
        mes = tr("MAY");
        break;
    case 6:
        mes = tr("JUN");
        break;
    case 7:
        mes = tr("JUL");
        break;
    case 8:
        mes = tr("AGO");
        break;
    case 9:
        mes = tr("SEP");
        break;
    case 10:
        mes = tr("OCT");
        break;
    case 11:
        mes = tr("NOV");
        break;
    case 12:
        mes = tr("DIC");
        break;
    }

    return mes;
}
