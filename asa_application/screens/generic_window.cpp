#include "generic_window.h"
#include "ui_generic_window.h"
#include "configuration/configuration.h"
#include <QFont>
#include <QDir>
#include <QTextStream>
#include <QDebug>
#include"custom_tooltip.h"

#include "multistatebutton.h" //TODO: HACER CLASE
generic_window::generic_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::generic_window)
{
    ui->setupUi(this);
    main_menu = parent;

    // Set window position
    this->move(parent->pos());

    // SET WINDOW PROPERTIES
    this->setObjectName("GenericWindow");
    this->setStyleSheet("#GenericWindow{background-color: black;"
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

//    this->InitToolTips();
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

void generic_window::InitToolTips(QList<configuration_id> parameter_list)
{
    QWidget *widget;
    custom_tooltip *tool_tip;
    foreach (configuration_id parameter, parameter_list)
    {
        widget = new QWidget(this);
        tool_tip = new custom_tooltip(widget, parameter, this, TYPE_FISICOS);
        connect(this, SIGNAL(update_tooltips()), tool_tip, SLOT(update_tooltip()));
    }

}

void generic_window::new_data_comming()
{
    // Update elements when new data is comming

    // Update tooltips
    this->update_tooltips();
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
}

void generic_window::handleParametrosElectricosButton()
{
    InitButtons(ui->pb_electricos, ui->pb_fisicos, ui->pb_quimicos);
    SelectParemeter(PARAM_ELECTRIC);
    ui->active_param_label->setText(tr("Parametros Eléctricos"));
}

void generic_window::handleParametrosFisicosButton()
{
    InitButtons(ui->pb_electricos, ui->pb_fisicos, ui->pb_quimicos);
    SelectParemeter(PARAM_PHYSHIC);
    ui->active_param_label->setText(tr("Parametros Físicos"));
}

void generic_window::handleParametrosQuimicosButton()
{
    InitButtons(ui->pb_electricos, ui->pb_fisicos, ui->pb_quimicos);
    SelectParemeter(PARAM_CHEMIC);
    ui->active_param_label->setText(tr("Parametros Químicos"));
}

void generic_window::on_top_main_menu_clicked()
{
    main_menu->show();
    this->close();
}
