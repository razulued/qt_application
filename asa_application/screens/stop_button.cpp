#include "stop_button.h"
#include "ui_stop_button.h"
#include "protocol/asa_conf_string.h"
#include "QTimer"
stop_button::stop_button(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stop_button)
{
    ui->setupUi(this);

    ui->pushButton->setCheckable(true);
    if(get_id_state("0902").toInt() == 1)
    {
        ui->pushButton->setChecked(true);
    }



    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint | Qt::WindowStaysOnTopHint);

    this->move(parent->geometry().width() + 15, parent->pos().y());
//    this->move(parent->pos());
    this->setAttribute(Qt::WA_TranslucentBackground);
}

stop_button::~stop_button()
{
    delete ui;
}

void stop_button::on_pushButton_pressed()
{
    if(get_id_state("0902").toInt() == 0)
    {
        QTimer::singleShot(2500, this, SLOT(checkStop()));
    }
    else
    {
        QTimer::singleShot(2500, this, SLOT(checkStop()));
        ui->pushButton->setChecked(false);
    }
}

void stop_button::on_pushButton_released()
{
    if(stop_pressed == true)
    {
        ui->pushButton->setChecked(true);
    }
    else
    {
        ui->pushButton->setChecked(false);
    }
}


void stop_button::checkStop()
{
    if(true == ui->pushButton->isDown())
    {
        if(!stop_pressed)
        {
            emergency_stop(true);
            ui->pushButton->setChecked(true);
            stop_pressed = true;
        }
        else
        {
            emergency_stop(false);
            ui->pushButton->setChecked(false);
            stop_pressed = false;
        }
    }
}
