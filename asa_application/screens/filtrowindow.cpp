#include "filtrowindow.h"
#include "ui_filtrowindow.h"
#include "mainwindow.h"
#include <QFont>
#include <QDebug>
#include "token_auth.h"
void filtrowindow::HideButtons(bool hide)
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

filtrowindow::filtrowindow(bool active_params, parameters_t param, QString dia, QString hora, QString user, rutinas_mantenimiento *rutinas, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::filtrowindow)
{
    ui->setupUi(this);

    my_name = "Filtro";

    rutinas_ptr = rutinas;
    this->setStyleSheet("background-color:black;"
                        "color:white"
                        );

    QFont hora_font("Typo Square Ligth Demo",18,1);
    QFont dia_font("Typo Square Ligth Demo",14,1);

    ui->label_hora->setStyleSheet("color: white");
    ui->label_hora->setFont(hora_font);
    ui->label_dia->setStyleSheet("color: white");
    ui->label_dia->setFont(dia_font);
    ui->prof_label->setStyleSheet("color:white;");

    ui->label_dia->setText(dia);
    ui->label_hora->setText(hora);
    ui->label_title->setText(user);

    if(NULL != graph)
    {
        delete graph;
    }
//    graph = new graphwindow(this);
//    connect(graph, SIGNAL(forward_bitacora_clicked()),this, SLOT (on_top_menu_2_clicked()));
//    connect(graph, SIGNAL(forward_control_clicked()),this, SLOT (on_top_menu_6_clicked()));

    //Setup Buttons and link to images
    InitButtons(ui->pb_electricos, ui->pb_fisicos, ui->pb_quimicos);
    switch(param)
    {
    case PARAM_ELECTRIC:
        handleParametrosElectricosButton();
        break;
    case PARAM_PHYSHIC:
        handleParametrosFisicosButton();
        break;
    case PARAM_CHEMIC:
        handleParametrosQuimicosButton();
        break;
    default:
        break;
    }

    display_parameters = active_params;

    if(false == display_parameters)
    {
        HideButtons(true);
        ui->pushButton->setChecked(false);
    }
    else
    {
        ui->pushButton->setChecked(true);
    }

    InitTooltips();

    //Set connect buttons to signals
    connect(ui->pushButton, SIGNAL (released()),this, SLOT (handleMenuButton()));
    connect(ui->pb_electricos, SIGNAL (released()),this, SLOT (handleParametrosElectricosButton()));
    connect(ui->pb_fisicos, SIGNAL (released()),this, SLOT (handleParametrosFisicosButton()));
    connect(ui->pb_quimicos, SIGNAL (released()),this, SLOT (handleParametrosQuimicosButton()));

    QFont active_parameter_font("Typo Square Bold Demo",16,1);
    ui->active_param_label->setFont(active_parameter_font);

    ui->active_param_label->setStyleSheet("color:black;"
                                          "background-color:transparent;");

    //Hide window bars and buttons
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);

    last_validity_state = false;

    QFont label_title_font("Typo Square Bold Demo",17,1);

    ui->label_title->setFont(label_title_font);
    ui->label_title->setStyleSheet("Text-align:left;"
                                   "border:none;"
                                   "color:black;"
                                   "background-color:transparent;");

    this->move(parent->pos());
//    this->show();
}

filtrowindow::~filtrowindow()
{
    delete ui;
}

void filtrowindow::on_go_to_main_clicked()
{
    forward_param_buttons_state(display_parameters, GetParemeter());
    release_lock();
    this->close();
}

void filtrowindow::handleMenuButton()
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
void filtrowindow::handleParametrosElectricosButton()
{
    SelectParemeter(PARAM_ELECTRIC);
    ui->active_param_label->setText(tr("Parametros Eléctricos"));
}

void filtrowindow::handleParametrosFisicosButton()
{
    SelectParemeter(PARAM_PHYSHIC);
    ui->active_param_label->setText(tr("Parametros Físicos"));
}

void filtrowindow::handleParametrosQuimicosButton()
{
    SelectParemeter(PARAM_CHEMIC);
    ui->active_param_label->setText(tr("Parametros Químicos"));
}

void filtrowindow::InitTooltips()
{
//    tool_tip_filtro_electricos  = new custom_tooltip(ui->widget,   configuration::conf_filtro_elect, this, ui->modulo_1, TYPE_ELECTRICOS, graph, this->my_name);
//    tool_tip_filtro_fisicos     = new custom_tooltip(ui->widget_2, configuration::conf_filtro_fisic, this, ui->modulo_1, TYPE_FISICOS, graph, this->my_name);
//    tool_tip_filtro_quimicos    = new custom_tooltip(ui->widget_3, configuration::conf_filtro_quimi, this, ui->modulo_1, TYPE_QUIMICOS, graph,  this->my_name);

//    tool_tip_filtro_bomba_electricos = new custom_tooltip(ui->widget_4, configuration::conf_filtro_bomba_elect, this, ui->modulo_2, TYPE_ELECTRICOS, graph, this->my_name);
//    tool_tip_filtro_bomba_fisicos    = new custom_tooltip(ui->widget_5, configuration::conf_filtro_bomba_fisic, this, ui->modulo_2, TYPE_FISICOS, graph, this->my_name);
//    tool_tip_filtro_bomba_quimicos   = new custom_tooltip(ui->widget_6, configuration::conf_filtro_bomba_quimi, this, ui->modulo_2, TYPE_QUIMICOS, graph,  this->my_name);

    init_complete = true;
}

void filtrowindow::on_asa_logo_clicked()
{
    forward_param_buttons_state(display_parameters, GetParemeter());
    release_lock();
    this->close();
}

void filtrowindow::update_tooltips(void)
{
    if(true == display_parameters)
    {
        switch(GetParemeter())
        {
        case PARAM_ELECTRIC:

            tool_tip_filtro_electricos->force_show();
            tool_tip_filtro_fisicos->force_hide();
            tool_tip_filtro_quimicos->force_hide();

            tool_tip_filtro_bomba_electricos->force_show();
            tool_tip_filtro_bomba_fisicos->force_hide();
            tool_tip_filtro_bomba_quimicos->force_hide();

            break;
        case PARAM_PHYSHIC:
            tool_tip_filtro_electricos->force_hide();
            tool_tip_filtro_fisicos->force_show();
            tool_tip_filtro_quimicos->force_hide();

            tool_tip_filtro_bomba_electricos->force_hide();
            tool_tip_filtro_bomba_fisicos->force_show();
            tool_tip_filtro_bomba_quimicos->force_hide();

            break;
        case PARAM_CHEMIC:
            tool_tip_filtro_electricos->force_hide();
            tool_tip_filtro_fisicos->force_hide();
            tool_tip_filtro_quimicos->force_show();

            tool_tip_filtro_bomba_electricos->force_hide();
            tool_tip_filtro_bomba_fisicos->force_hide();
            tool_tip_filtro_bomba_quimicos->force_show();
            break;
        default:
            break;
        }
    }
    else
    {
        if(init_complete)
        {
            tool_tip_filtro_electricos->update_tooltip();
            tool_tip_filtro_fisicos->update_tooltip();
            tool_tip_filtro_quimicos->update_tooltip();

            tool_tip_filtro_bomba_electricos->update_tooltip();
            tool_tip_filtro_bomba_fisicos->update_tooltip();
            tool_tip_filtro_bomba_quimicos->update_tooltip();
        }

    }
}

void filtrowindow::check_lock()
{
    bool state = get_validity_state();

    if(last_validity_state != state)
    {
        if(true == state)
        {
            ui->prof_pic->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Prof pic blanco.png);"
                                           "border: none;"
                                           "background-repeat: none;"
                                           "background-position: center;"
                                           "background-color: transparent;");
        }
        else
        {
            ui->prof_pic->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Prof pic azul.png);"
                                           "border: none;"
                                           "background-repeat: none;"
                                           "background-position: center;"
                                        "background-color: transparent;");
        }

        ui->prof_label->setText(get_user_name());
    }

    last_validity_state = state;
}

void filtrowindow::update_other(QString dia, QString hora, QString user)
{
    ui->label_dia->setText(dia);
    ui->label_hora->setText(hora);
    ui->label_title->setText(user);
    check_lock();

    /* Update data in detailed window (if open) */
    if((NULL != detail_window) && detail_window->isActiveWindow())
    {
        detail_window->update_params();
    }

    // Update graph if open
//    if(false == graph->isHidden())
//    {
//        graph->update_graph();
//    }
}

void filtrowindow::on_modulo_1_clicked()
{
    if(mutex_detailed.tryLock(0))
    {
        if (detail_window != NULL) {
            delete detail_window;
        }
        detail_window = new detailedwindow(ELEMENT_FILTRO, rutinas_ptr, this);
        connect(detail_window, SIGNAL(release_lock()), this, SLOT(detailed_window_closed()));
        detail_window->show();
    }
}

void filtrowindow::on_prof_pic_clicked()
{
    forward_prof_pic_clicked();
}

void filtrowindow::on_top_menu_6_clicked()
{
    forward_control_clicked();
}

void filtrowindow::on_top_menu_2_clicked()
{
    forward_bitacora_clicked();
}

void filtrowindow::on_modulo_2_clicked()
{
    if(mutex_detailed.tryLock(0))
    {
        if (detail_window != NULL) {
            delete detail_window;
        }
        detail_window = new detailedwindow(ELEMENT_FILTRO_BOMBA, rutinas_ptr, this);
        connect(detail_window, SIGNAL(release_lock()), this, SLOT(detailed_window_closed()));
        detail_window->show();
    }
}

void filtrowindow::detailed_window_closed()
{
    mutex_detailed.unlock();
}

void filtrowindow::on_top_menu_1_clicked()
{
    forward_bitacora_clicked();
}
