#include "motores.h"
#include "ui_motores.h"
#include <QCheckBox>
#include <QSignalMapper>
#include <QDebug>
#include "protocol/asa_conf_string.h"
#include "token_auth.h"
#include "mainwindow.h"
#include "configuration/configuration.h"
#include "clickeablelabel.h"
#include "QMovie"

#define MAX_INACTIVITY_TIMEOUT (300 * 1000)

motores::motores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::motores)
{
    ui->setupUi(this);

    // HIDE STOP BUTTON
//    ui->frame_3->hide();

    ui->pushButton->setCheckable(true);
    if(get_id_state("0902").toInt() == 1)
    {
        ui->pushButton->setChecked(true);
        stop_pressed = true;
        wating_timer = false;

        stop_button_animation(true);
    }
    else
    {
        stop_button_animation(false);
    }

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

    number_of_motors = 0;
    module_init( &configuration::reg_outputs, ui->gridLayout);
    module_init( &configuration::react_outputs, ui->gridLayout_2);
    module_init( &configuration::filtro_outputs, ui->gridLayout_3);
    module_init( &configuration::filtro_bomba_outputs, ui->gridLayout_4);
    module_init( &configuration::car_outputs, ui->gridLayout_5);

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

    has_activity = false;
    QTimer::singleShot(MAX_INACTIVITY_TIMEOUT, this, SLOT(checkActivity()));

    //Hide window bars and buttons
    if(false == get_validity_state())
    {
        if(NULL != login_d)
        {
            delete login_d;
        }
        login_d = new login_dialog(this);
    }

    ui->comboBox->setStyleSheet("background-color: black;"
                                "color: white;");
    ui->comboBox_2->setStyleSheet("background-color: black;"
                                "color: white;");
    ui->comboBox_3->setStyleSheet("background-color: black;"
                                "color: white;");
    ui->comboBox_4->setStyleSheet("background-color: black;"
                                "color: white;");
    ui->comboBox_5->setStyleSheet("background-color: black;"
                                "color: white;");

    mode_4600 = load_parameter("mode4600.bin");
    read_op_mode();
    set_op_mode(ui->comboBox->currentIndex(), ELEMENT_REGULADOR);
    set_op_mode(ui->comboBox_2->currentIndex(), ELEMENT_REACTOR);
    set_op_mode(ui->comboBox_3->currentIndex(), ELEMENT_FILTRO);
    set_op_mode(ui->comboBox_4->currentIndex(), ELEMENT_FILTRO_BOMBA);

    this->move(parent->pos());
//    this->show();
}

motores::~motores()
{
    delete ui;
}

void motores::update_motors()
{
    module_update(&configuration::reg_outputs);
    module_update(&configuration::react_outputs);
    module_update(&configuration::filtro_outputs);
    module_update(&configuration::filtro_bomba_outputs);
    module_update(&configuration::car_outputs);
    motor_index = 0;
}

void motores::on_asa_logo_clicked()
{
    output_token_transfer(false);
    release_lock();
    this->close();
}

void motores::module_init(configuration_id *conf, QGridLayout *layout)
{
    uint row, column;
    row = 0;
    column = 0;

    uint i = 0;
    QFont font_2("Typo Square Ligth Demo",10,1);
    QCheckBox *box_motores;
    QSignalMapper *out_checkboxMapper = new QSignalMapper(this);

    for(i = 0; i < (quint32)conf->ids.size(); i++)
    {
        box_motores = new QCheckBox(conf->names.at(i));
        controls_ptr[number_of_motors++] = box_motores;

        box_motores->setFont(font_2);
        box_motores->setLayoutDirection(Qt::RightToLeft);

        if(true == get_validity_state())
        {
            box_motores->setEnabled(true);


            if(motor_state(conf->ids_string.at(i)) !=
                    get_id_state(conf->ids_string.at(i)).toInt())
            {
                box_motores->setStyleSheet("QCheckBox{"
                                           "color:white;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "border: none;"
                                           "}"
                                           "QCheckBox::indicator{"
                                           "image: url(:/iconos/screen800x600/iconos/Encendido blanco.png);"
                                           "border-width: 0px;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "}");
            }
            else if(1 == motor_state(conf->ids_string.at(i)))
            {
                box_motores->setStyleSheet("QCheckBox{"
                                           "color:white;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "border: none;"
                                           "}"
                                           "QCheckBox::indicator{"
                                           "image: url(:/iconos/screen800x600/iconos/Encendido verde.png);"
                                           "border-width: 0px;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "}");
            }
            else
            {
                box_motores->setStyleSheet("QCheckBox{"
                                           "color:white;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "border: none;"
                                           "}"
                                           "QCheckBox::indicator{"
                                           "image: url(:/iconos/screen800x600/iconos/Encendido azul.png);"
                                           "border-width: 0px;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "}");
            }
        }
        else
        {
            box_motores->setEnabled(false);
            box_motores->setStyleSheet("QCheckBox{"
                                       "color:white;"
                                       "width: 30px;"
                                       "height: 30px;"
                                       "border: none;"
                                       "}"
                                       "QCheckBox::indicator{"
                                       "image: url(:/iconos/screen800x600/iconos/Encendido gris.png);"
                                       "border-width: 0px;"
                                       "width: 30px;"
                                       "height: 30px;"
                                       "}");
        }

        layout->addWidget(box_motores, row, column);
        row++;
        if(row >= 3)
        {
            row = 0;
            column++;
        }

        connect(box_motores, SIGNAL(clicked(bool)), out_checkboxMapper, SLOT(map()));
        out_checkboxMapper->setMapping(box_motores, conf->ids.at(i));
    }


    // Connect all checkboxes to mapper
    connect(out_checkboxMapper, SIGNAL(mapped(int)), this, SLOT(out_checkBoxStateChanged(int)));
}

void motores::module_update(configuration_id *conf)
{
//    check_lock();
    uint i = 0;
    QCheckBox *box_motores;

    for(i = 0; i < (quint32)conf->ids.size(); i++)
    {
        box_motores = controls_ptr[motor_index++];
        if(true == get_validity_state())
        {
            box_motores->setEnabled(true);


            if(motor_state(conf->ids_string.at(i)) !=
                    get_id_state(conf->ids_string.at(i)).toInt())
            {
                box_motores->setStyleSheet("QCheckBox{"
                                           "color:white;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "border: none;"
                                           "}"
                                           "QCheckBox::indicator{"
                                           "image: url(:/iconos/screen800x600/iconos/Encendido blanco.png);"
                                           "border-width: 0px;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "}");
            }
            else if(1 == motor_state(conf->ids_string.at(i)))
            {
                box_motores->setStyleSheet("QCheckBox{"
                                           "color:white;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "border: none;"
                                           "}"
                                           "QCheckBox::indicator{"
                                           "image: url(:/iconos/screen800x600/iconos/Encendido verde.png);"
                                           "border-width: 0px;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "}");
            }
            else
            {
                box_motores->setStyleSheet("QCheckBox{"
                                           "color:white;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "border: none;"
                                           "}"
                                           "QCheckBox::indicator{"
                                           "image: url(:/iconos/screen800x600/iconos/Encendido azul.png);"
                                           "border-width: 0px;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "}");
            }
        }
        else
        {
            box_motores->setEnabled(false);
            box_motores->setStyleSheet("QCheckBox{"
                                       "color:white;"
                                       "width: 30px;"
                                       "height: 30px;"
                                       "border: none;"
                                       "}"
                                       "QCheckBox::indicator{"
                                       "image: url(:/iconos/screen800x600/iconos/Encendido gris.png);"
                                       "border-width: 0px;"
                                       "width: 30px;"
                                       "height: 30px;"
                                       "}");
        }
    }
}

void motores::out_checkBoxStateChanged(int a)
{
    // Skip if control is not manual
    // I don't recall why these numbers are not hex
    uint module_prefix = a / 100;
    qDebug() << "prefix " << module_prefix;
    if(module_prefix == 36)
    {
        // carcamo
        if(ui->comboBox->currentIndex() == CONTROL_AUTOMATICO)
        {
            return;
        }
    }
    else if(module_prefix == 46)
    {
        // reactor
        if(ui->comboBox_2->currentIndex() == CONTROL_AUTOMATICO)
        {
            return;
        }
    }
    else if(module_prefix == 96)
    {
        if(ui->comboBox_3->currentIndex() == CONTROL_AUTOMATICO)
        {
            return;
        }
    }
    else if(module_prefix == 97)
    {
        if(ui->comboBox_4->currentIndex() == CONTROL_AUTOMATICO)
        {
            return;
        }
    }

    qDebug() << "Toggle output " << a;
    has_activity = true;
//    synch_output_state();
    output_control_toggle(a);
}

void motores::background_clicked()
{
    output_token_transfer(false);
    release_lock();
    this->close();
}

void motores::checkActivity()
{
    if(true == has_activity)
    {
        // Hay actividad, rearmar timer
        has_activity = false;
        QTimer::singleShot(MAX_INACTIVITY_TIMEOUT, this, SLOT(checkActivity()));
    }
    else
    {
        output_token_transfer(false);
        release_lock();
        this->close();
    }
}


void motores::on_pushButton_clicked()
{
}

void motores::checkStop()
{
    if(true == ui->pushButton->isDown())
    {
        if(!stop_pressed)
        {
            emergency_stop(true);
            ui->pushButton->setChecked(true);
            stop_pressed = true;

            stop_button_animation(true);
        }
        else
        {
            emergency_stop(false);
            ui->pushButton->setChecked(false);

            stop_pressed = false;
            stop_button_animation(false);
        }
    }
    wating_timer = false;
}

void motores::on_pushButton_pressed()
{
    if(wating_timer == false)
    {
        if(get_id_state("0902").toInt() == 0)
        {
            QTimer::singleShot(2500, this, SLOT(checkStop()));
            stop_button_animation(true);
        }
        else
        {
            QTimer::singleShot(2500, this, SLOT(checkStop()));
            ui->pushButton->setChecked(false);
        }
        wating_timer = true;
    }
}

void motores::on_pushButton_released()
{
    if(stop_pressed == true)
    {
        ui->pushButton->setChecked(true);
        stop_button_animation(true);
    }
    else
    {
        ui->pushButton->setChecked(false);
        stop_button_animation(false);
    }
}

void motores::read_op_mode()
{
    QString str;

    str = getParamValue(0x3E00); /* Antes 3600 */
    if(("04" == str) || ("4" == str))
    {
        ui->comboBox->setCurrentIndex(CONTROL_STOP);
    }
    else if(("03" == str) || ("3" == str))
    {
        ui->comboBox->setCurrentIndex(CONTROL_MANUAL);
    }
    else
    {
        ui->comboBox->setCurrentIndex(CONTROL_AUTOMATICO);
    }

    str = getParamValue(0x4600);
    if(("04" == str) || ("4" == str))
    {
        ui->comboBox_2->setCurrentIndex(CONTROL_STOP);
    }
    else if(("03" == str) || ("3" == str))
    {
        ui->comboBox_2->setCurrentIndex(CONTROL_MANUAL);
    }
    else
    {
        ui->comboBox_2->setCurrentIndex(CONTROL_AUTOMATICO);
    }

    str = getParamValue(0x9600);
    if(("04" == str) || ("4" == str))
    {
        ui->comboBox_3->setCurrentIndex(CONTROL_STOP);
    }
    else if(("03" == str) || ("3" == str))
    {
        ui->comboBox_3->setCurrentIndex(CONTROL_MANUAL);
    }
    else
    {
        ui->comboBox_3->setCurrentIndex(CONTROL_AUTOMATICO);
    }

    str = getParamValue(0x9700);
    if(("04" == str) || ("4" == str))
    {
        ui->comboBox_4->setCurrentIndex(CONTROL_STOP);
    }
    else if(("03" == str) || ("3" == str))
    {
        ui->comboBox_4->setCurrentIndex(CONTROL_MANUAL);
    }
    else
    {
        ui->comboBox_4->setCurrentIndex(CONTROL_AUTOMATICO);
    }

    str = getParamValue(0x3600);
    if(("04" == str) || ("4" == str))
    {
        ui->comboBox_5->setCurrentIndex(CONTROL_STOP);
    }
    else if(("03" == str) || ("3" == str))
    {
        ui->comboBox_5->setCurrentIndex(CONTROL_MANUAL);
    }
    else
    {
        ui->comboBox_5->setCurrentIndex(CONTROL_AUTOMATICO);
    }
}

void motores::set_op_mode(uint mode, uint what_element)
{
    QString str;
    if(CONTROL_STOP == mode)
    {
        str = "04";
    }
    else if(CONTROL_MANUAL == mode)
    {
        str = "03";
    }
    else
    {
        // CONTROL_AUTOMATICO
        if((2 == mode_4600) && (ELEMENT_REACTOR == what_element))
        {
            str = "02";
        }
        else
        {
            str = "01";
        }
    }

    switch(what_element)
    {
    case ELEMENT_REGULADOR:
        output_op_mode("3E00", str); /* Antes 3600 */
        break;
    case ELEMENT_REACTOR:
        output_op_mode("4600", str);
        break;
    case ELEMENT_CLARIFICADOR:
        output_op_mode("5600", str);
        break;
    case ELEMENT_FILTRO:
        output_op_mode("9600", str);
        break;
    case ELEMENT_FILTRO_BOMBA:
        output_op_mode("9700", str);
        break;
    case ELEMENT_CARCAMO:
        output_op_mode("3600", str);
        break;
    default:
        break;
    }
}

void motores::on_comboBox_currentIndexChanged(int index)
{
    set_op_mode(index, ELEMENT_REGULADOR);
}

void motores::on_comboBox_2_currentIndexChanged(int index)
{
    set_op_mode(index, ELEMENT_REACTOR);
}

void motores::on_comboBox_3_currentIndexChanged(int index)
{
    set_op_mode(index, ELEMENT_FILTRO);
}

void motores::on_comboBox_4_currentIndexChanged(int index)
{
    set_op_mode(index, ELEMENT_FILTRO_BOMBA);
}

void motores::stop_button_animation(bool state)
{
    if(true == state)
    {
        QMovie *mv;
        mv = new QMovie(":/iconos/screen800x600/iconos/Stop-Boton-Activo.gif");
        ui->stop_button_image->setAttribute(Qt::WA_NoSystemBackground);
        mv->setCacheMode(QMovie::CacheAll);
        mv->start();
        ui->stop_button_image->setMovie(mv);

        ui->pushButton->setStyleSheet("background-color:transparent;"
                                             "background-image: url(:/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/none.png);"
                                             "background-position: center;"
                                             "background-repeat:none;"
                                             "border:none;");
        this->update();
    }
    else
    {
        ui->stop_button_image->setMovie(NULL);
        ui->pushButton->setStyleSheet("background-color:transparent;"
                                             "background-image: url(:/iconos/screen800x600/iconos/BOTON.png);"
                                             "background-position: center;"
                                             "background-repeat:none;"
                                             "border:none;");

        this->update();
    }
}
