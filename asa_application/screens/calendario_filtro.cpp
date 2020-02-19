#include "calendario_filtro.h"
#include "ui_calendario_filtro.h"
#include "clickeablelabel.h"
#include <QDateTime>
#include "configuration/configuration.h"

calendario_filtro::calendario_filtro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calendario_filtro)
{
    ui->setupUi(this);

    this->setObjectName("Calendar");
    this->setStyleSheet("#Calendar{background-color: black;"
                        "border: none;}");

    clickeablelabel *alphabackground = new clickeablelabel(this);
    alphabackground->setGeometry(this->geometry());
    alphabackground->setStyleSheet("background-color: rgb(0,0,0,120);");
    alphabackground->lower();
    connect(alphabackground,SIGNAL(clicked()),this,SLOT(background_clicked()));

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    QFont font5("Typo Square Bold Demo",8,1);
    QFont font("Typo Square Bold Demo",16,1);

    ui->fecha_inicio_text->setFont(font5);
    ui->fecha_inicio_text->setStyleSheet("background-color: transparent;"
                                         "color: black;");
    ui->fecha_fin_text->setFont(font5);
    ui->fecha_fin_text->setStyleSheet("background-color: transparent;"
                                         "color: black;");

    ui->label->setFont(font);
    ui->label->setStyleSheet("background-color: transparent;"
                                         "color: rgb(0, 167, 250);");
    this->move(parent->pos());
    this->show();
}

calendario_filtro::~calendario_filtro()
{
    delete ui;
}

void calendario_filtro::on_close_clicked()
{
    this->close();
}

void calendario_filtro::background_clicked()
{
    this->close();
}


void calendario_filtro::on_fecha_inicio_btn_clicked()
{
    if(NULL != calendar_window)
    {
        delete calendar_window;
    }

    calendar_window = new calendar(configuration::time, 0, this);
    connect(calendar_window, SIGNAL(send_calendar_date(uint,QDate)),
            this, SLOT(registros_filter_init_date(uint,QDate)));
}

void calendario_filtro::on_fecha_fin_btn_clicked()
{
    if(NULL != calendar_window)
    {
        delete calendar_window;
    }

    calendar_window = new calendar(configuration::time, 0, this);
    connect(calendar_window, SIGNAL(send_calendar_date(uint,QDate)),
            this, SLOT(registros_filter_end_date(uint,QDate)));
}

void calendario_filtro::registros_filter_init_date(uint hora, QDate date)
{
    QDateTime *temp = new QDateTime(date);
    ui->fecha_inicio_text->setText(date.toString("yy-MM-dd"));

    *temp = temp->addSecs(60 * 60 * hora);
    filtro_fecha_inicio = temp->toTime_t();
    delete temp;
}
void calendario_filtro::registros_filter_end_date(uint hora, QDate date)
{
    QDateTime *temp = new QDateTime(date);
    ui->fecha_fin_text->setText(date.toString("yy-MM-dd"));

    *temp = temp->addSecs(60 * 60 * hora);
    filtro_fecha_fin = temp->toTime_t();
    delete temp;
}

void calendario_filtro::on_ok_button_clicked()
{
    if(0 != filtro_fecha_inicio &&
            0 != filtro_fecha_fin &&
            filtro_fecha_inicio < filtro_fecha_fin)
    {
        send_fechas(filtro_fecha_inicio, filtro_fecha_fin);
        this->close();
    }
}
