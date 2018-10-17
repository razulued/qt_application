#include "earm_update.h"
#include "ui_earm_update.h"
#include "clickeablelabel.h"
#include "parameters.h"
earm_update::earm_update(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::earm_update)
{
    ui->setupUi(this);

    this->setObjectName("Earm_update");
    this->setStyleSheet("#Earm_update{background-color: black;"
                        "border: none;}");

    clickeablelabel *alphabackground = new clickeablelabel(this);
    alphabackground->setGeometry(this->geometry());
    alphabackground->setStyleSheet("background-color: rgb(0,0,0,120);");
    alphabackground->lower();
    connect(alphabackground,SIGNAL(clicked()),this,SLOT(background_clicked()));

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint | Qt::WindowStaysOnTopHint);

    this->setAttribute(Qt::WA_TranslucentBackground);
    this->move(parent->pos());
}

earm_update::~earm_update()
{
    delete ui;
}

void earm_update::update_data()
{
      ui->label_2->setText(tr("Calidad de señal: ") + QString::number(getParamValue(0x0100).toInt())+tr("%"));
      ui->label_3->setText(tr("Tiempo de conexión: ") + QString::number(getParamValue(0x0200).toInt()/10)+tr(" segundos"));
      ui->label_5->setText(tr("Numero de serie: ") + getParamValue(0x0002));

      uint value = 0;
      if(0 != getParamValue(0x0601).toInt())
      {
          value = getParamValue(0x0303).toInt() * 100 / getParamValue(0x0601).toInt();
      }
      ui->progressBar->setValue(value);

      if(1 == getParamValue(0x0B01).toInt())
      {
          ui->label_4->setText(tr("Error en transferencia"));
      }

}

void earm_update::background_clicked()
{
    release_lock();
//    this->close();
}
