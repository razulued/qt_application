#include "generic_window.h"
#include "ui_generic_window.h"
#include "configuration/configuration.h"
#include <QFont>
#include <QDir>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>
#include "custom_tooltip.h"

// Subwindows
#include "contacto.h"
#include "parameters.h"
#include "login_dialog.h"

#include "multistatebutton.h" //TODO: HACER CLASE
generic_window::generic_window(QString name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::generic_window)
{
    ui->setupUi(this);
    main_menu = parent;

    // Set window position
    this->move(parent->pos());

    // SET WINDOW PROPERTIES
    this->setObjectName(name);
    this->setStyleSheet("#"+name+"{background-color: black;"
                        "border: none;}");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);

    // SET FONTS AND COLORS
    // Top Icons
//    ui->top_menu_1->setStyleSheet("background-color: transparent;"
//                                  "background-image: url(:/iconos/screen800x600/iconos/Campana.png);"
//                                  "border: none;"
//                                  "background-repeat: none;"
//                                  "background-position: center;"
//                                  );
    // Botom Bar
    QFont active_parameter_font("Typo Square Bold Demo",16,1);
    ui->active_param_label->setFont(active_parameter_font);
    ui->active_param_label->setStyleSheet("color:black");
    ui->active_param_label->setText(tr("Parametros Eléctricos"));
    // Date and Hour
    QFont hora_font("Typo Square Ligth Demo",18,1);
    QFont dia_font("Typo Square Ligth Demo",14,1);
    ui->label_hora->setStyleSheet("color: white");
    ui->label_hora->setFont(hora_font);
    ui->label_dia->setStyleSheet("color: white");
    ui->label_dia->setFont(dia_font);
    this->update_time_date();

    // Win title
    QString title_name = configuration::window_title;
    QFont label_title_font("Typo Square Bold Demo",17,1);
    ui->label_title->setFont(label_title_font);
    ui->label_title->setStyleSheet("Text-align:left;"
                                   "border:none;"
                                   "color:black;"
                                   "background-color:transparent;");
    ui->label_title->setText(title_name);
    // Profile label
    ui->prof_label->setStyleSheet("color:white;");

    //Setup Buttons and link to images
    InitButtons(ui->pb_electricos, ui->pb_fisicos, ui->pb_quimicos);
    display_parameters = false;
    HideButtons(true);
    //Set connect buttons to signals
    connect(ui->pushButton, SIGNAL (released()),this, SLOT (handleMenuButton()));
    connect(ui->pb_electricos, SIGNAL (released()),this, SLOT (handleParametrosElectricosButton()));
    connect(ui->pb_fisicos, SIGNAL (released()),this, SLOT (handleParametrosFisicosButton()));
    connect(ui->pb_quimicos, SIGNAL (released()),this, SLOT (handleParametrosQuimicosButton()));
}

generic_window::~generic_window()
{
    delete ui;
}

void generic_window::add_image(QString image_path, QSize size, QPoint pos, bool fit_to_geometry = false)
{
    QLabel *image = new QLabel(this);
    //image->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    //image->setText("first line\nsecond line");
    image->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    //Here is how to change position:
    if(fit_to_geometry)
    {
        image->setStyleSheet("border-image: url("+ image_path +");"
                             "background-position:center;");
    }
    else
    {
        image->setStyleSheet("background-image: url("+ image_path +");"
                             "background-repeat: none;"
                             "background-position:center;"
                             "border:none;");
    }
    image->setGeometry(pos.x(), pos.y(), size.width(), size.height());
}

void generic_window::add_images_from_config(QString module)
{
    QStringList values;
    QString image_mapping;

    enum
    {
        MODULE_NAME, IMAGE_PATH, XPOS, YPOS, WIDTH, HEIGHT, FIT

    };

    if(QDir().cd("img"))
    {
        image_mapping = "./img/image_mapping.csv";
        QFile file(image_mapping);
        if(file.open(QFile::ReadOnly))
        {
            QTextStream stream(&file);
            // Discard First Line
            stream.readLine();
            while(!stream.atEnd())
            {
                values = stream.readLine().split(",");

                //Only append items from the same type
                qDebug() << "module" << module;
                if(module == values.at(MODULE_NAME) ) /* Get first character */
                {
                    qDebug() << values.at(IMAGE_PATH);
                    qDebug() << "Add " << values.at(WIDTH).toInt() << values.at(HEIGHT).toInt() << values.at(XPOS).toInt() << values.at(YPOS).toInt();

                    add_image(values.at(IMAGE_PATH),
                              QSize(values.at(WIDTH).toInt(), values.at(HEIGHT).toInt()),
                              QPoint(values.at(XPOS).toInt(), values.at(YPOS).toInt()),
                              values.at(FIT) == "0" ? false : true);
                }
            }
        }
        file.close();
    }
}

QPushButton* generic_window::add_clickeable_module(QSize size, QPoint pos, QString text = NULL, QString color = NULL)
{
    QPushButton *button = new QPushButton(text,this);
    if(text != NULL)
    {
        button->setText(text);
    }
    button->setGeometry(pos.x(), pos.y(), size.width(), size.height());

    if(color != NULL)
    {
        button->setStyleSheet("background-color: transparent;"
                              "border-color: "+color+";"
                              "border-width: 2px;"
                              "border-style: solid;"
                              "color: white;");
    }
    else
    {
        button->setStyleSheet("background-color: transparent;"
                              "border: none;"
                              "color: white;");
    }
    button->show();
    return button;
}

void generic_window::HideButtons(bool hide)
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

void generic_window::update_time_date()
{
    QString dos_mil = "20";
    QString time_format = "yyyy/MM/dd,HH.mm.ss";
    QString hora =  dos_mil+ getParamValue(0x0402);
    QDateTime time = QDateTime::fromString(hora, time_format);
    QString display_time = QString::number(time.time().hour())+":"+QString("%1").arg(time.time().minute(), 2, 10, QChar('0'))+":"+QString("%1").arg(time.time().second(), 2, 10, QChar('0'));
    QString display_dia = build_date_string(time);

    ui->label_dia->setText(display_dia);
    ui->label_hora->setText(display_time);
}

void generic_window::update_user()
{
    ui->prof_label->setText(configuration::username);
    if(configuration::token_state)
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
}

QString generic_window::build_date_string(QDateTime time)
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

void generic_window::InitToolTips(QList<configuration_id> parameter_list)
{
    QWidget *widget;
    custom_tooltip *tool_tip;
    foreach (configuration_id parameter, parameter_list)
    {
        widget = new QWidget(this);
        tool_tip = new custom_tooltip(widget, parameter, this);
        connect(this, SIGNAL(update_tooltips()), tool_tip, SLOT(update_tooltip()));
        connect(this, SIGNAL(force_tooltips(bool)), tool_tip, SLOT(force_show(bool)));
    }

}

void generic_window::new_data_comming()
{
    // Update elements when new data is comming

    // Update tooltips
    this->update_tooltips();

    // Update time date
    this->update_time_date();

    // Update user
//    this->update_user();

    qDebug() << "configuration::token_state" << configuration::token_state;
}

void generic_window::subwindow_closed()
{
    qDebug() << "Subwindow Closed";
    subwindow_mutex.unlock();
}

void generic_window::handleMenuButton()
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
    force_tooltips(display_parameters);
}

void generic_window::handleParametrosElectricosButton()
{
    InitButtons(ui->pb_electricos, ui->pb_fisicos, ui->pb_quimicos);
    SelectToolbarParameter(PARAM_ELECTRIC);
    ui->active_param_label->setText(tr("Parametros Eléctricos"));
    force_tooltips(true);
}

void generic_window::handleParametrosFisicosButton()
{
    InitButtons(ui->pb_electricos, ui->pb_fisicos, ui->pb_quimicos);
    SelectToolbarParameter(PARAM_PHYSHIC);
    ui->active_param_label->setText(tr("Parametros Físicos"));
    force_tooltips(true);
}

void generic_window::handleParametrosQuimicosButton()
{
    InitButtons(ui->pb_electricos, ui->pb_fisicos, ui->pb_quimicos);
    SelectToolbarParameter(PARAM_CHEMIC);
    ui->active_param_label->setText(tr("Parametros Químicos"));
    force_tooltips(true);
}

void generic_window::on_top_main_menu_clicked()
{
    main_menu->show();
    this->close();
}

void generic_window::on_top_menu_1_clicked()
{
    // Return to main menu
    main_menu->show();
    this->close();
}

void generic_window::on_top_menu_2_clicked()
{
//    // Motores View
//    if(subwindow_mutex.tryLock(0))
//    {
//        motores *motrores_window = new motores(this);

//        connect(motrores_window, SIGNAL(release_lock()), this, SLOT(subwindow_closed()));
//        motrores_window->show();
//    }
}

void generic_window::on_top_menu_3_clicked()
{

}

void generic_window::on_top_menu_4_clicked()
{

}

void generic_window::on_asa_logo_clicked()
{
    if(subwindow_mutex.tryLock(0))
    {
        contacto * contacto_window = new contacto(this);
//        connect(contacto_window, SIGNAL(close_app()), this, SLOT(close()));
        connect(contacto_window, SIGNAL(release_lock()), this, SLOT(subwindow_closed()));
        contacto_window->show();
    }
}

void generic_window::on_prof_pic_clicked()
{
    if(configuration::token_state == false)
    {
        if(subwindow_mutex.tryLock(0))
        {
            login_dialog * login_window = new login_dialog(this);
            connect(login_window, SIGNAL(release_lock()), this, SLOT(update_user()));
            connect(login_window, SIGNAL(release_lock()), this, SLOT(subwindow_closed()));
        }
    }
    else
    {
        configuration::validate_token(false);
        this->update_user();
    }
}

void generic_window::add_graph()
{
    line_chart *caudal = new line_chart();
}
