#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QFontDatabase>
#include "parameters.h"
#include <QList>
#include <QPainter>
#include <QColor>
#include "asa_protocol.h"
#include "asa_conf_string.h"
#include "statistics.h"
#include "token_auth.h"
#include "build_settings.h"
#include "records.h"
#include <QMouseEvent>

#define ENABLE_TEST (1)

configuration_id MainWindow::conf_press_elect;
configuration_id MainWindow::conf_press_fisic;
configuration_id MainWindow::conf_press_quimic;

configuration_id MainWindow::car_outputs;

#if (1 == RELEASE_FOR_RPI)
bool MainWindow::simulation =false;
#else
bool MainWindow::simulation =true;
#endif

QDateTime MainWindow::time;

bool MainWindow::demo_mode_enabled = false;

//QString MainWindow::ASA_conf_string;
//QString MainWindow::ASA_conf_only_string;

uint MainWindow::num_of_pending_act = 0;
void get_number_of_pending_activities (uint a)
{
    MainWindow::num_of_pending_act = a;
}

void MainWindow::HideButtons(bool hide)
{
    if(false == hide)
    {
       ui->pb_electricos->show();
       ui->pb_fisicos->show();
       ui->pb_quimicos->show();
       ui->bottom_bar->show();
       ui->active_param_label->show();
    }
    else
    {
        ui->pb_electricos->hide();
        ui->pb_fisicos->hide();
        ui->pb_quimicos->hide();
        ui->bottom_bar->hide();
        ui->active_param_label->hide();
    }
}

void MainWindow::InitTooltips()
{
    ASA_load_active_parameters();

    tool_tip_carcamo_electricos = new custom_tooltip(ui->widget_25, conf_press_elect.ids, conf_press_elect.names, car_outputs.ids, car_outputs.names, this, ui->modulo_9, TYPE_ELECTRICOS);
    tool_tip_carcamo_fisicos = new custom_tooltip(ui->widget_26, conf_press_fisic.ids, conf_press_fisic.names, car_outputs.ids, car_outputs.names, this, ui->modulo_9, TYPE_FISICOS);
    tool_tip_carcamo_quimicos = new custom_tooltip(ui->widget_27, conf_press_quimic.ids, conf_press_quimic.names, car_outputs.ids, car_outputs.names, this, ui->modulo_9, TYPE_QUIMICOS);
    init_complete = true;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    my_name = "PTAR";

    // Init SPI
    dataObj = new DataProccess;
    dataObj->start();

    output_op_mode("1FFF", "0");

    //Get config
    validate_token(false);
//    init_plat_config();
//    get_ASA_string();

    configuration *config;

    ASA_protocol_init();
    conf_press_elect = ASA_get_module_sensors("Presurizador", "Electrico");
    conf_press_fisic = ASA_get_module_sensors("Presurizador", "Fisico");
    conf_press_quimic = ASA_get_module_sensors("Presurizador", "Quimico");

    //Setup Timer
    dataTimer.setInterval(100);
    connect(&dataTimer, SIGNAL(timeout()),this,SLOT(dataTimerSlot()));
    dataTimer.start();

    connect(dataObj, SIGNAL(spi_read_completed()), this, SLOT(new_spi_data()));
//    new_spi_data

    //Add fonts
    QFontDatabase::addApplicationFont(":/fonts/fonts/Typo_Square_Bold Demo.otf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/Typo_Square_Ligth Demo.otf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/Typo_Square_Italic Demo.otf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/Typo_Square_Bold_Italic Demo.otf");

    QFontDatabase::addApplicationFont(":/fonts/fonts/SQRS711L.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/sqrs711m.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/square721 bt-italic.ttf");

    //Setup Buttons and link to images
    InitButtons(ui->pb_electricos, ui->pb_fisicos, ui->pb_quimicos);
    display_parameters = false;
    HideButtons(true);

    InitTooltips();

    //Set connect buttons to signals
    connect(ui->pushButton, SIGNAL (released()),this, SLOT (handleMenuButton()));
    connect(ui->pb_electricos, SIGNAL (released()),this, SLOT (handleParametrosElectricosButton()));
    connect(ui->pb_fisicos, SIGNAL (released()),this, SLOT (handleParametrosFisicosButton()));
    connect(ui->pb_quimicos, SIGNAL (released()),this, SLOT (handleParametrosQuimicosButton()));
    //Connect slot to signal
    detail_window = NULL;
    connect(ui->modulo_9, SIGNAL (released()),this, SLOT (handleDetailedView_9()));

    QFont active_parameter_font("Typo Square Bold Demo",16,1);
    ui->active_param_label->setFont(active_parameter_font);

    ui->active_param_label->setStyleSheet("color:black");
    ui->active_param_label->setText(tr("Parametros Eléctricos"));

    QFont hora_font("Typo Square Ligth Demo",18,1);
    QFont dia_font("Typo Square Ligth Demo",14,1);

    ui->label_hora->setStyleSheet("color: white");
    ui->label_hora->setFont(hora_font);
    ui->label_dia->setStyleSheet("color: white");
    ui->label_dia->setFont(dia_font);



    if((NULL == sim_window) && simulation)
    {
        sim_window = new simulation_input(this);
    }

    ui->prof_label->setStyleSheet("color:white;");

    QString title_name;
    config = new configuration("Titulos");
    title_name = config->get_value("Titulos", "Diagrama");

    QFont label_title_font("Typo Square Bold Demo",17,1);

    ui->label_title->setFont(label_title_font);
    ui->label_title->setStyleSheet("Text-align:left;"
                                   "border:none;"
                                   "color:black;"
                                   "background-color:transparent;");
    ui->label_title->setText(title_name);

    level_label_size  = ui->water_level->geometry();
    update_demo_mode();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleMenuButton()
{
    if(false == display_parameters)
    {
        HideButtons(false);
        display_parameters = true;
    }
    else
    {
        HideButtons(true);
        display_parameters = false;
    }
}

void MainWindow::handleParametrosElectricosButton()
{
    InitButtons(ui->pb_electricos, ui->pb_fisicos, ui->pb_quimicos);
    SelectParemeter(PARAM_ELECTRIC);
    ui->active_param_label->setText(tr("Parametros Eléctricos"));
}

void MainWindow::handleParametrosFisicosButton()
{
    InitButtons(ui->pb_electricos, ui->pb_fisicos, ui->pb_quimicos);
    SelectParemeter(PARAM_PHYSHIC);
    ui->active_param_label->setText(tr("Parametros Físicos"));
}

void MainWindow::handleParametrosQuimicosButton()
{
    InitButtons(ui->pb_electricos, ui->pb_fisicos, ui->pb_quimicos);
    SelectParemeter(PARAM_CHEMIC);
    ui->active_param_label->setText(tr("Parametros Químicos"));
}

void MainWindow::window_closed()
{
    qDebug() << "release lock";
    mutex_detailed.unlock();
}

void MainWindow::update_demo_mode()
{
    // Check demo mode
    QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
    conf.sync();
    // Read Demo mode
    conf.sync();
    conf.beginGroup("Demo");
    if(0 == conf.value("demo_mode").toInt())
    {
        demo_mode_enabled = false;
    }
    else
    {
        demo_mode_enabled = true;
    }
    conf.endGroup();
}

void MainWindow::handleDetailedView_9()
{
    if(mutex_detailed.tryLock(0))
    {
        if (detail_window != NULL) {
            qDebug() << "delete";
            delete detail_window;
        }
        detail_window = new detailedwindow(ELEMENT_CARCAMO, this);
        connect(detail_window, SIGNAL(release_lock()), this, SLOT(window_closed()));
        detail_window->show();
    }
}

void MainWindow::update_this()
{
//    qDebug() << "update this";
    this->update();
}

void MainWindow::update_title(QString text)
{
    ui->label_title->setText(text);

    configuration *config;
    config = new configuration("Titulos");
    config->saveSettings("Titulos", "Diagrama", text);
}

void MainWindow::on_asa_logo_clicked()
{
    if(mutex_detailed.tryLock(0))
    {
        if(NULL != contacto_window)
        {
            delete contacto_window;
        }
        contacto_window = new contacto(this);
        connect(contacto_window, SIGNAL(close_app()), this, SLOT(close()));

        connect(contacto_window, SIGNAL(release_lock()), this, SLOT(window_closed()));
        contacto_window->show();
    }
}

void MainWindow::dataTimerSlot()
{
    static uint count = 0;

    check_lock();

    if(0 == (count % 10)) /* 20 ms */
    {
        // Fastest time for smooth transition when moving
        update_tooltips();
    }


    if(0 == (count % 20)) /* 2 segundo */
    {
        update_this();

        float level = getParamValue(0x3201).toFloat();
        float percent =float(level / getParamMaxValue(0x3201));
        int percent_image = int(level_label_size.height() * percent);
//        qDebug() << level << getParamMaxValue(0x3201) << percent << percent_image;

        ui->water_level->setGeometry(level_label_size.x() ,
                                     level_label_size.y() + level_label_size.height() - percent_image,
                                     level_label_size.width(),
                                     percent_image);


    }
    if(0 == (count % 10)) /* 2 segundo */
    {
//        update_ASA_string();

#if (1 ==ENABLE_TEST)
        /***** DEMO *****/

#endif
    }

    count++;

//    if(NULL == stop_button_window && this->isVisible() && count>10)
//    {
//        stop_button_window = new stop_button(this);
//        stop_button_window->show();
//    }

}


void MainWindow::trace_lines(QWidget * tooltip, QPushButton *module, QPainter &painter)
{
    static QPoint last_position;

    if(true == tooltip->isVisible() && (last_position != tooltip->pos()))
    {
//        this->update();

        if((tooltip->geometry().bottom() + 50) <  module->geometry().top())
        {
            //Hacia abajo
            painter.drawLine((tooltip->geometry().x() + tooltip->geometry().width()/2), tooltip->geometry().bottom(),
                             (tooltip->geometry().x() + tooltip->geometry().width()/2), tooltip->geometry().bottom()+20);
           // Hacia el modulo
            painter.drawLine((tooltip->geometry().x() + tooltip->geometry().width()/2), tooltip->geometry().bottom()+20,
                             (module->geometry().x() + module->geometry().width()/2), module->geometry().bottom());
                //         painter.drawLine((start->x() + start->width()/2), start->bottom(), end->x(), end->y());
        }
        else if((tooltip->geometry().top() - 50) >  module->geometry().bottom())
        {
            //Hacia arriba desde la esquina
            painter.drawLine((tooltip->geometry().x() + tooltip->geometry().width()*0.9), tooltip->geometry().top(),
                             (tooltip->geometry().x() + tooltip->geometry().width()*0.9), tooltip->geometry().top()-20);
           // Hacia el modulo
            painter.drawLine((tooltip->geometry().x() + tooltip->geometry().width()*0.9), tooltip->geometry().top()-20,
                             (module->geometry().x() + module->geometry().width()/2), module->geometry().bottom());
        }
        else
        {
            //Widget is too close in vertical. Check horizontal
            if((tooltip->geometry().x() - 70) > (module->geometry().x() + module->geometry().width()) )
            {
                painter.drawLine(tooltip->geometry().x() , tooltip->geometry().top(),
                                  module->geometry().center().x() , module->geometry().center().y());
            }
            else if((tooltip->geometry().x() + tooltip->geometry().width() + 30) < (module->geometry().x()) )
            {
                painter.drawLine((tooltip->geometry().x() + tooltip->geometry().width()*0.9), tooltip->geometry().top(),
                                 (module->geometry().x() + module->geometry().width()/2), module->geometry().bottom());
            }
        }

        last_position = tooltip->pos();
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{

}

void MainWindow::update_tooltips(void)
{
    static uint count = 0;
    if(true == display_parameters)
    {
        switch(GetParemeter())
        {
        case PARAM_ELECTRIC:
            tool_tip_carcamo_electricos->force_show();
            tool_tip_carcamo_fisicos->force_hide();
            tool_tip_carcamo_quimicos->force_hide();

            break;
        case PARAM_PHYSHIC:
            tool_tip_carcamo_electricos->force_hide();
            tool_tip_carcamo_fisicos->force_show();
            tool_tip_carcamo_quimicos->force_hide();
            break;
        case PARAM_CHEMIC:
            tool_tip_carcamo_electricos->force_hide();
            tool_tip_carcamo_fisicos->force_hide();
            tool_tip_carcamo_quimicos->force_show();
            break;
        default:
            break;
        }
    }
    else
    {
        if(init_complete)
        {
            if(0 == count)
            {
                tool_tip_carcamo_electricos->update_data();
                count++;
            }
            else if(1 == count)
            {
                tool_tip_carcamo_fisicos->update_data();
                count++;
            }
            else
            {
                tool_tip_carcamo_quimicos->update_data();
                count = 0;
            }
        }

    }
}

void MainWindow::new_spi_data()
{
    if((NULL != detail_window) && detail_window->isActiveWindow())
    {
        detail_window->update_params();
        qDebug() << "Update param";
    }

    if(0xBB11 == getParamValue(0x0201).toInt())
    {
        if(false == update_in_progress)
        {
            update_in_progress = true;

            // Update in progress
            if( NULL != update_window )
            {
                delete update_window;
            }
            update_window = new earm_update(this);
            update_window->show();
        }
        else
        {
            if(NULL != update_window)
            {
                update_window->update_data();
            }
        }
    }
    else
    {
        if(NULL != update_window)
        {
            if(update_window->isVisible())
            {
                update_window->close();
                update_in_progress = false;
            }
        }
    }
    update_system_time();
}

void MainWindow::update_system_time()
{
    /* Update Hora */
    //"18/03/06,13:34:55"
    /* Update reloj */
    QString dos_mil = "20";
    QString time_format = "yyyy/MM/dd,HH.mm.ss";

    QString hora =  dos_mil+ getParamValue(0x0402);
    static QDateTime temp_time;
//    temp_time.setTime_t(1);
    if(true == simulation)
    {
        time = simulation_input::simDateTime;
    }
    else
    {
        time = QDateTime::fromString(hora, time_format);
    }

    if(temp_time.toTime_t() != time.toTime_t())
    {
        temp_time = time;

        //Update text on screen
//        QString display_time = QString::number(time.date().year())+"/"+QString::number(time.date().month())+"/"+QString::number(time.date().day())+" "+time.time().toString();
//        QString display_time = QString::number(time.time().hour())+":"+QString::number(time.time().minute());
        QString display_time = QString::number(time.time().hour())+":"+QString("%1").arg(time.time().minute(), 2, 10, QChar('0'))+":"+QString("%1").arg(time.time().second(), 2, 10, QChar('0'));
        QString display_dia = build_date_string(time);

        ui->label_dia->setText(display_dia);
        ui->label_hora->setText(display_time);
        send_date_hour(time);

    }

}

void MainWindow::check_lock()
{
    static bool last_validity_state = false;
    bool state = get_validity_state();
    if(last_validity_state != state)
    {
        if(true == state)
        {
            ui->prof_pic->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Prof pic blanco.png);"
                                           "border: none;"
                                           "background-repeat: none;"
                                           "background-position: center;");
        }
        else
        {
            ui->prof_pic->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Prof pic azul.png);"
                                           "border: none;"
                                           "background-repeat: none;"
                                           "background-position: center;");
        }

        ui->prof_label->setText(get_user_name());
    }

    last_validity_state = state;
}

QString MainWindow::build_date_string(QDateTime time)
{
    QString dia_semana;
    QString mes;
    switch(time.date().dayOfWeek())
    {
    case 1:
        dia_semana = tr("Lunes");
        break;
    case 2:
        dia_semana = tr("Martes");
        break;
    case 3:
        dia_semana = tr("Miércoles");
        break;
    case 4:
        dia_semana = tr("Jueves");
        break;
    case 5:
        dia_semana = tr("Viernes");
        break;
    case 6:
        dia_semana = tr("Sábado");
        break;
    case 7:
        dia_semana = tr("Domingo");
        break;
    }

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
//    QString display_time = QString::number(time.date().year())+"/"+QString::number(time.date().month())+"/"+QString::number(time.date().day())+" "+time.time().toString();
    return dia_semana + " " + QString::number(time.date().day()) + " " + mes + " " + QString::number(time.date().year());
}

void MainWindow::on_prof_pic_clicked()
{
    synch_output_state();

    if(false == get_validity_state())
    {
        if(NULL != login_d)
        {
            delete login_d;
        }
        login_d = new login_dialog(this);
    }
    else
    {
        validate_token(false);
    }
}


void MainWindow::on_label_title_clicked()
{
    if(true == get_validity_state())
    {
        title_click_count++;
        QTimer::singleShot(500, this, SLOT(check_title_click()));
    }
}

void MainWindow::check_title_click()
{
    if(title_click_count >= 2)
    {
        title_click_count = 0;
        if(NULL != change_text_window)
        {
            delete change_text_window;
        }
        change_text_window = new change_text(ui->label_title->text(), this);
        connect(change_text_window, SIGNAL(update_text(QString)), this, SLOT(update_title(QString)));
    }
    else
    {
        title_click_count = 0;
    }
}

