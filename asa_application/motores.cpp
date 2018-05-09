#include "motores.h"
#include "ui_motores.h"
#include <QCheckBox>
#include <QSignalMapper>
#include <QDebug>
#include "asa_conf_string.h"
#include "token_auth.h"
#include "mainwindow.h"
#include "clickeablelabel.h"

motores::motores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::motores)
{
    ui->setupUi(this);

    synch_output_state();

    //Check token
    if(true == get_validity_state())
    {
        output_token_transfer(true);
    }
    else
    {
        output_token_transfer(false);
    }


    //Hide window bars and buttons
    module_init( &MainWindow::reg_outputs, ui->verticalLayout);
    module_init( &MainWindow::react_outputs, ui->verticalLayout_2);

    this->setObjectName("MyMotors");
    this->setStyleSheet("#MyMotors{background-color: black;"
                        "border: none;"
                        "color: white}");
//    ui->frame->setStyleSheet("background-color: black;"
//                             "color: white;"
//                             "border-style: solid;"
//                             "border-width:1px;"
//                             "border-color: rgb(0, 167, 250);"
//                             "border-radius: 10px;");
//    ui->frame_2->setStyleSheet(ui->frame->styleSheet());

    clickeablelabel *alphabackground = new clickeablelabel(this);
    alphabackground->setGeometry(this->geometry());
    alphabackground->setStyleSheet("background-color: rgb(0,0,0,180);");
    alphabackground->lower();
    connect(alphabackground,SIGNAL(clicked()),this,SLOT(background_clicked()));

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    this->move(parent->pos());
    this->show();
}

motores::~motores()
{
    delete ui;
}

void motores::on_asa_logo_clicked()
{
    output_token_transfer(false);
    this->close();
}

void motores::module_init(configuration_id *conf, QVBoxLayout *layout)
{
    uint i = 0;
    QFont font_2("Typo Square Ligth Demo",12,1);
    QCheckBox *box_motores;
    QSignalMapper *out_checkboxMapper = new QSignalMapper(this);


    for(i = 0; i < (quint32)conf->ids.size(); i++)
    {
        box_motores = new QCheckBox(conf->names.at(i));

        box_motores->setFont(font_2);
        box_motores->setLayoutDirection(Qt::RightToLeft);
        box_motores->setStyleSheet("QCheckBox{"
                                   "color:white;"
                                   "width: 40px;"
                                   "height: 40px;"
                                   "border: none;"
                                   "}"
                                   "QCheckBox::indicator:checked{"
                                   "image: url(:/iconos/screen800x600/iconos/Encendido verde.png);"
                                   "border-width: 0px;"
                                   "width: 40px;"
                                   "height: 40px;"
                                   "}"
                                   "QCheckBox::indicator:unchecked{"
                                   "image: url(:/iconos/screen800x600/iconos/Encendido azul.png);"
                                   "border-width: 0px;"
                                   "width: 40px;"
                                   "height: 40px;"
                                   "}"
                                   "QCheckBox::indicator:disabled{"
                                   "image: url(:/iconos/screen800x600/iconos/Encendido gris.png);"
                                   "border-width: 0px;"
                                   "width: 40px;"
                                   "height: 40px;"
                                   "}"
                                   );
        if(true == get_validity_state())
        {
            box_motores->setEnabled(true);

            qDebug() << "HEEEEEEEEEYYYY " << i << ":" << conf->ids.at(i) << ":" << get_id_state(conf->ids.at(i)).toInt();
            if(1 == get_id_state(conf->ids.at(i)).toInt())
            {
                box_motores->setChecked(true);
            }
        }
        else
        {
            box_motores->setEnabled(false);
        }

        layout->addWidget(box_motores);

        connect(box_motores, SIGNAL(clicked(bool)), out_checkboxMapper, SLOT(map()));
        out_checkboxMapper->setMapping(box_motores, conf->ids.at(i));
    }


    // Connect all checkboxes to mapper
    connect(out_checkboxMapper, SIGNAL(mapped(int)), this, SLOT(out_checkBoxStateChanged(int)));
}

void motores::out_checkBoxStateChanged(int a)
{
    qDebug() << "Toggle output " << a;
    output_control_toggle(a);
}

void motores::background_clicked()
{
    output_token_transfer(false);
    this->close();
}
