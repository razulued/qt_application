#include "contacto.h"
#include "ui_contacto.h"
#include "clickeablelabel.h"
#include <QProcess>
#include "token_auth.h"

contacto::contacto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contacto)
{
    ui->setupUi(this);
    ui->top_menu_5->hide();
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
    this->move(parent->pos());
    this->show();
}

contacto::~contacto()
{
    delete ui;
}

void contacto::background_clicked()
{
    release_lock();
    this->close();
}

void contacto::on_push_cancelar_clicked()
{
    if(sequence == 0)
    {
        sequence = 1;
    }
    else if(3 == sequence)
    {
        close_app();
    }
    else
    {
        sequence = 1;
    }
}

void contacto::on_push_cancelar_2_clicked()
{
    if(1 == sequence)
    {
        sequence = 2;
    }
    else
    {
        sequence = 0;
    }

}

void contacto::on_push_cancelar_3_clicked()
{
    if(2 == sequence)
    {
        sequence = 3;
    }
    else
    {
        sequence = 0;
    }
}

void contacto::on_push_cancelar_4_clicked()
{

    sequence = 0;

}

void contacto::on_close_clicked()
{
    release_lock();
    this->close();
}

void contacto::on_top_menu_5_clicked()
{
    if(true == get_validity_state())
    {
//        if(mutex_detailed.tryLock(0))
        {
            if(settingswindow != NULL)
            {
                delete settingswindow;
            }
            settingswindow = new settings(get_super_user(), this);
//            connect(settingswindow, SIGNAL(release_lock()), this, SLOT(window_closed()));
            settingswindow->show();
        }
    }
}
