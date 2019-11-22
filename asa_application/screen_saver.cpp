#include "screen_saver.h"
#include "ui_screen_saver.h"
#include <QDebug>
#include <QMovie>
#include <QFont>
#include <token_auth.h>
#define TIMEOUT (300)

bool screen_saver::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
//        qDebug() << "HERE: " << event;
        inactivity_counter = 0;
        if(true == screen_saver_active)
        {
            screen_saver_active = false;
            run_back_ground_gif(false);
            this->hide();
        }
    }
    return QObject::eventFilter(obj, event);
}

screen_saver::screen_saver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::screen_saver)
{
    ui->setupUi(this);

    screen_saver_active = false;
    inactivity_counter = 0;

//    QFont font("Typo Square Bold Demo");
    QFont font_day("Typo Square Bold Demo",72,1);
    QFont font_moth("Typo Square Bold Demo",26,1);
    QFont font_hour("Typo Square Bold Demo",36,1);
    QFont font_ampm("Typo Square Bold Demo",12,1);
    QFont font_sec("Typo Square Bold Demo",18,1);
    QFont font_not("Typo Square Bold Demo",14,1);

    ui->label_day->setFont(font_day);
    ui->label_month->setFont(font_moth);
    ui->label_hour->setFont(font_hour);
    ui->label_am_pm->setFont(font_ampm);
    ui->label_seconds->setFont(font_sec);
    ui->notification->setFont(font_not);


    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
//    this->setAttribute(Qt::WA_TranslucentBackground);

    InactivityTimer.setInterval(1000);
    connect(&InactivityTimer, SIGNAL(timeout()),this,SLOT(TimerSlot()));
    InactivityTimer.start();
}

screen_saver::~screen_saver()
{
    delete ui;
}

void screen_saver::TimerSlot()
{
    if((inactivity_counter >= TIMEOUT) && (false == screen_saver_active))
    {
        qDebug() << "TIMEOUT RUN SCREEN SAVER";
        validate_token(false);
        screen_saver_active = true;
        run_back_ground_gif(true);
        this->show();
    }
    else
    {
        inactivity_counter++;
    }
}

void screen_saver::receive_date_hour(QDateTime time)
{   
    int hour;

    if(time.time().hour() >= 12)
    {
        hour = time.time().hour() - 12;
        ui->label_am_pm->setText(tr("PM"));
    }
    else
    {
        if(time.time().hour() < 1)
        {
            hour = 12;
        }
        else
        {
            hour = time.time().hour();
        }
        ui->label_am_pm->setText(tr("AM"));
    }
    // Hour and minutes
    ui->label_hour->setText(QString::number(hour)+":"+QString("%1").arg(time.time().minute(), 2, 10, QChar('0')));
    // seconds
    ui->label_seconds->setText(QString("%1").arg(time.time().second(), 2, 10, QChar('0')));

    // Day
    ui->label_day->setText(QString::number(time.date().day()));

    // Month
    ui->label_month->setText(get_moth(time));

}

void screen_saver::pending_activities(uint act)
{
    uint static last_num = -1;
    QMovie *mv;

    if(last_num != act)
    {
        if(act > 0)
        {
            ui->notification->setText(QString::number(act));
//            ui->notification->setText(QString::number(act));
            ui->bell->setAttribute(Qt::WA_NoSystemBackground);
            mv = new QMovie(":/iconos/screen800x600/iconos/Bell_2.png");
            mv->setCacheMode(QMovie::CacheAll);
            mv->start();
            ui->bell->setMovie(mv);
        }
        else
        {
            ui->notification->setText("");
            ui->bell->setAttribute(Qt::WA_NoSystemBackground);
            mv = new QMovie(":/iconos/screen800x600/gifs/OK.gif");
            mv->setCacheMode(QMovie::CacheAll);
            mv->start();
            ui->bell->setMovie(mv);
        }
        last_num = act;
    }
}

void screen_saver::run_back_ground_gif(bool state)
{
    QMovie *mv_1;
    if(true == state)
    {
        ui->background->setAttribute(Qt::WA_NoSystemBackground);
        mv_1 = new QMovie(":/iconos/screen800x600/gifs/PTAR-VAB.gif");
        mv_1->setCacheMode(QMovie::CacheAll);
        mv_1->start();
        ui->background->setMovie(mv_1);
    }
    else
    {
        ui->background->setAttribute(Qt::WA_NoSystemBackground);
        mv_1 = new QMovie(":/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/none.png");
        mv_1->setCacheMode(QMovie::CacheAll);
        mv_1->start();
        ui->background->setMovie(mv_1);
    }
}

QString screen_saver::get_moth(QDateTime time)
{
    QString mes;
    switch(time.date().month())
    {
    case 1:
        mes = tr("Enero");
        break;
    case 2:
        mes = tr("Febrero");
        break;
    case 3:
        mes = tr("Marzo");
        break;
    case 4:
        mes = tr("Abril");
        break;
    case 5:
        mes = tr("Mayo");
        break;
    case 6:
        mes = tr("Junio");
        break;
    case 7:
        mes = tr("Julio");
        break;
    case 8:
        mes = tr("Agosto");
        break;
    case 9:
        mes = tr("Septiembre");
        break;
    case 10:
        mes = tr("Octubre");
        break;
    case 11:
        mes = tr("Noviembre");
        break;
    case 12:
        mes = tr("Diciembre");
        break;
    }
    return mes;
}
