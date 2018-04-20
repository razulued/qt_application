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

#define ENABLE_TEST (1)

configuration_id MainWindow::conf_reg_elect;
configuration_id MainWindow::conf_reg_fisic;
configuration_id MainWindow::conf_reg_quimic;

configuration_id MainWindow::conf_react_elect;
configuration_id MainWindow::conf_react_fisic;
configuration_id MainWindow::conf_react_quimi;

configuration_id MainWindow::conf_clarif_elect;
configuration_id MainWindow::conf_clarif_fisic;
configuration_id MainWindow::conf_clarif_quimi;

configuration_id MainWindow::conf_clora_elect;
configuration_id MainWindow::conf_clora_fisic;
configuration_id MainWindow::conf_clora_quimi;

configuration_id MainWindow::conf_digest_elect;
configuration_id MainWindow::conf_digest_fisic;
configuration_id MainWindow::conf_digest_quimi;

configuration_id MainWindow::conf_deshid_elect;
configuration_id MainWindow::conf_deshid_fisic;
configuration_id MainWindow::conf_deshid_quimi;

configuration_id MainWindow::conf_afluente_elect;
configuration_id MainWindow::conf_afluente_fisic;
configuration_id MainWindow::conf_afluente_quimi;

configuration_id MainWindow::conf_efluente_elect;
configuration_id MainWindow::conf_efluente_fisic;
configuration_id MainWindow::conf_efluente_quimi;

configuration_id MainWindow::reg_outputs;
configuration_id MainWindow::react_outputs;
configuration_id MainWindow::clarif_outputs;
configuration_id MainWindow::clora_outputs;
configuration_id MainWindow::digest_outputs;
configuration_id MainWindow::deshid_outputs;
configuration_id MainWindow::afluente_outputs;
configuration_id MainWindow::efluente_outputs;

int MainWindow::reg_op_mode;
int MainWindow::reg_mot_1;
int MainWindow::reg_mot_2;

bool MainWindow::simulation = true;
//QString MainWindow::ASA_conf_string;
//QString MainWindow::ASA_conf_only_string;


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

    tool_tip_regulador_electricos = new custom_tooltip(ui->widget, conf_reg_elect.ids, conf_reg_elect.names, reg_outputs.ids, reg_outputs.names, this, ui->modulo_1, TYPE_ELECTRICOS, graph);
    tool_tip_regulador_fisicos = new custom_tooltip(ui->widget_2, conf_reg_fisic.ids, conf_reg_fisic.names, reg_outputs.ids, reg_outputs.names, this, ui->modulo_1, TYPE_FISICOS, graph);
    tool_tip_regulador_quimicos = new custom_tooltip(ui->widget_3, conf_reg_quimic.ids, conf_reg_quimic.names, reg_outputs.ids, reg_outputs.names, this, ui->modulo_1, TYPE_QUIMICOS, graph);

    tool_tip_reactor_electricos = new custom_tooltip(ui->widget_4, conf_react_elect.ids, conf_react_elect.names, react_outputs.ids, react_outputs.names, this, ui->modulo_2, TYPE_ELECTRICOS, graph);
    tool_tip_reactor_fisicos = new custom_tooltip(ui->widget_5, conf_react_fisic.ids, conf_react_fisic.names, react_outputs.ids, react_outputs.names, this, ui->modulo_2, TYPE_FISICOS, graph);
    tool_tip_reactor_quimicos = new custom_tooltip(ui->widget_6, conf_react_quimi.ids, conf_react_quimi.names, react_outputs.ids, react_outputs.names, this, ui->modulo_2, TYPE_QUIMICOS, graph);

    tool_tip_clarificador_electricos = new custom_tooltip(ui->widget_7, conf_clarif_elect.ids, conf_clarif_elect.names, clarif_outputs.ids, clarif_outputs.names, this, ui->modulo_3, TYPE_ELECTRICOS, graph);
    tool_tip_clarificador_fisicos = new custom_tooltip(ui->widget_8, conf_clarif_fisic.ids, conf_clarif_fisic.names, clarif_outputs.ids, clarif_outputs.names, this, ui->modulo_3, TYPE_FISICOS, graph);
    tool_tip_clarificador_quimicos = new custom_tooltip(ui->widget_9, conf_clarif_quimi.ids, conf_clarif_quimi.names, clarif_outputs.ids, clarif_outputs.names, this, ui->modulo_3, TYPE_QUIMICOS, graph);

    tool_tip_clorador_electricos = new custom_tooltip(ui->widget_10, conf_clora_elect.ids, conf_clora_elect.names, clora_outputs.ids, clora_outputs.names, this, ui->modulo_4, TYPE_ELECTRICOS, graph);
    tool_tip_clorador_fisicos = new custom_tooltip(ui->widget_11, conf_clora_fisic.ids, conf_clora_fisic.names, clora_outputs.ids, clora_outputs.names, this, ui->modulo_4, TYPE_FISICOS, graph);
    tool_tip_clorador_quimicos = new custom_tooltip(ui->widget_12, conf_clora_quimi.ids, conf_clora_quimi.names, clora_outputs.ids, clora_outputs.names, this, ui->modulo_4, TYPE_QUIMICOS, graph);

    tool_tip_digestor_electricos = new custom_tooltip(ui->widget_13, conf_digest_elect.ids, conf_digest_elect.names, digest_outputs.ids, digest_outputs.names, this, ui->modulo_5, TYPE_ELECTRICOS, graph);
    tool_tip_digestor_fisicos = new custom_tooltip(ui->widget_14, conf_digest_fisic.ids, conf_digest_fisic.names, digest_outputs.ids, digest_outputs.names, this, ui->modulo_5, TYPE_FISICOS, graph);
    tool_tip_digestor_quimicos = new custom_tooltip(ui->widget_15, conf_digest_quimi.ids, conf_digest_quimi.names, digest_outputs.ids, digest_outputs.names, this, ui->modulo_5, TYPE_QUIMICOS, graph);

    tool_tip_deshidratador_electricos = new custom_tooltip(ui->widget_16, conf_deshid_elect.ids, conf_deshid_elect.names, deshid_outputs.ids, deshid_outputs.names, this, ui->modulo_6, TYPE_ELECTRICOS, graph);
    tool_tip_deshidratador_fisicos = new custom_tooltip(ui->widget_17, conf_deshid_fisic.ids, conf_deshid_fisic.names, deshid_outputs.ids, deshid_outputs.names, this, ui->modulo_6, TYPE_FISICOS, graph);
    tool_tip_deshidratador_quimicos = new custom_tooltip(ui->widget_18, conf_deshid_quimi.ids, conf_deshid_quimi.names, deshid_outputs.ids, deshid_outputs.names, this, ui->modulo_6, TYPE_QUIMICOS, graph);

    tool_tip_afluente_electricos = new custom_tooltip(ui->widget_19, conf_afluente_elect.ids, conf_afluente_elect.names, afluente_outputs.ids, afluente_outputs.names, this, ui->modulo_7, TYPE_ELECTRICOS, graph);
    tool_tip_afluente_fisicos = new custom_tooltip(ui->widget_20, conf_afluente_fisic.ids, conf_afluente_fisic.names, afluente_outputs.ids, afluente_outputs.names, this, ui->modulo_7, TYPE_FISICOS, graph);
    tool_tip_afluente_quimicos = new custom_tooltip(ui->widget_21, conf_afluente_quimi.ids, conf_afluente_quimi.names, afluente_outputs.ids, afluente_outputs.names, this, ui->modulo_7, TYPE_QUIMICOS, graph);

    tool_tip_efluente_electricos = new custom_tooltip(ui->widget_22, conf_efluente_elect.ids, conf_efluente_elect.names, efluente_outputs.ids, efluente_outputs.names, this, ui->modulo_8, TYPE_ELECTRICOS, graph);
    tool_tip_efluente_fisicos = new custom_tooltip(ui->widget_23, conf_efluente_fisic.ids, conf_efluente_fisic.names, efluente_outputs.ids, efluente_outputs.names, this, ui->modulo_8, TYPE_FISICOS, graph);
    tool_tip_efluente_quimicos = new custom_tooltip(ui->widget_24, conf_efluente_quimi.ids, conf_efluente_quimi.names, efluente_outputs.ids, efluente_outputs.names, this, ui->modulo_8, TYPE_QUIMICOS, graph);

    init_complete = true;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pb_simulacion->setStyleSheet("color: green;"
                                     "border: 1px solid green;");
//    settingswindow = NULL;

    graph = new graphwindow(this);

    // Init SPI
    dataObj = new DataProccess;
    dataObj->start();

    // Rutinas y DB
    rutinas = new rutinas_mantenimiento("rutinas.db");

    //Get config
    init_plat_config();
//    get_ASA_string();

    configuration *config;

    config = new configuration("Regulador-Electricos");
    conf_reg_elect = config->get_config();
    config = new configuration("Regulador-Fisicos");
    conf_reg_fisic = config->get_config();
    config = new configuration("Regulador-Quimicos");
    conf_reg_quimic = config->get_config();

    config = new configuration("Reactor-Electricos");
    conf_react_elect = config->get_config();
    config = new configuration("Reactor-Fisicos");
    conf_react_fisic = config->get_config();
    config = new configuration("Reactor-Quimicos");
    conf_react_quimi = config->get_config();

    config = new configuration("Clarificador-Electricos");
    conf_clarif_elect = config->get_config();
    config = new configuration("Clarificador-Fisicos");
    conf_clarif_fisic = config->get_config();
    config = new configuration("Clarificador-Quimicos");
    conf_clarif_quimi = config->get_config();

    config = new configuration("Clorador-Electricos");
    conf_clora_elect = config->get_config();
    config = new configuration("Clorador-Fisicos");
    conf_clora_fisic = config->get_config();
    config = new configuration("Clorador-Quimicos");
    conf_clora_quimi = config->get_config();

    config = new configuration("Digestor-Electricos");
    conf_digest_elect = config->get_config();
    config = new configuration("Digestor-Fisicos");
    conf_digest_fisic = config->get_config();
    config = new configuration("Digestor-Quimicos");
    conf_digest_quimi = config->get_config();

    config = new configuration("Deshidratador-Electricos");
    conf_deshid_elect = config->get_config();
    config = new configuration("Deshidratador-Fisicos");
    conf_deshid_fisic = config->get_config();
    config = new configuration("Deshidratador-Quimicos");
    conf_deshid_quimi = config->get_config();

    config = new configuration("Afluente-Electricos");
    conf_afluente_elect = config->get_config();
    config = new configuration("Afluente-Fisicos");
    conf_afluente_fisic = config->get_config();
    config = new configuration("Afluente-Quimicos");
    conf_afluente_quimi = config->get_config();

    config = new configuration("Efluente-Electricos");
    conf_efluente_elect = config->get_config();
    config = new configuration("Efluente-Fisicos");
    conf_efluente_fisic = config->get_config();
    config = new configuration("Efluente-Quimicos");
    conf_efluente_quimi = config->get_config();

    //Get outputs
    config = new configuration("Regulador-Out");
    reg_outputs = config->get_config();
    config = new configuration("Reactor-Out");
    react_outputs = config->get_config();
    config = new configuration("Clarificador-Out");
    clarif_outputs = config->get_config();
    config = new configuration("Clorador-Out");
    clora_outputs = config->get_config();
    config = new configuration("Digestor-Out");
    digest_outputs = config->get_config();
    config = new configuration("Deshidratador-Out");
    deshid_outputs = config->get_config();
    config = new configuration("Afluente-Out");
    afluente_outputs = config->get_config();
    config = new configuration("Efluente-Out");
    efluente_outputs = config->get_config();

    //Setup Timer
    dataTimer.setInterval(10);
    connect(&dataTimer, SIGNAL(timeout()),this,SLOT(dataTimerSlot()));
    dataTimer.start();

    connect(dataObj, SIGNAL(spi_read_completed()), this, SLOT(new_spi_data()));
//    new_spi_data

    //Add fonts
    QFontDatabase::addApplicationFont(":/fonts/fonts/Typo_Square_Bold Demo.otf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/Typo_Square_Ligth Demo.otf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/Typo_Square_Italic Demo.otf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/Typo_Square_Bold_Italic Demo.otf");

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
    connect(ui->modulo_1, SIGNAL (released()),this, SLOT (handleDetailedView_1()));
    connect(ui->modulo_2, SIGNAL (released()),this, SLOT (handleDetailedView_2()));
    connect(ui->modulo_3, SIGNAL (released()),this, SLOT (handleDetailedView_3()));
    connect(ui->modulo_4, SIGNAL (released()),this, SLOT (handleDetailedView_4()));
    connect(ui->modulo_5, SIGNAL (released()),this, SLOT (handleDetailedView_5()));
    connect(ui->modulo_6, SIGNAL (released()),this, SLOT (handleDetailedView_6()));
    connect(ui->modulo_7, SIGNAL (released()),this, SLOT (handleDetailedView_7()));
    connect(ui->modulo_8, SIGNAL (released()),this, SLOT (handleDetailedView_8()));

    QFont active_parameter_font("Typo Square Bold Demo",16,1);
    ui->active_param_label->setFont(active_parameter_font);

    ui->active_param_label->setStyleSheet("color:black");
    ui->active_param_label->setText("Parametros Eléctricos");

    QFont hora_font("Typo Square Regular Demo",15,1);
    ui->label_hora->setStyleSheet("color: white");
    ui->label_hora->setFont(hora_font);
//    button.setStyleSheet( FormStyleSheetString( "button" ) );
//     button.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
//     button.setIconSize(QSize(200,200));
//     button.show();

//    mod_1 = new mod_1_carcamo(ui->gif_modulo_1);
//    mod_2 = new mod_2_reactor(ui->gif_modulo_2);
//    mod_3 = new mod_3_clarificador(ui->gif_modulo_3);
//    mod_4 = new mod_4_clorador(ui->gif_modulo_4);
//    mod_5 = new mod_5_digestor(ui->gif_modulo_5);
//    mod_6 = new mod_6_lechos(ui->gif_modulo_6);
//    mod_afluente = new mod_flechas(AFLUENTE_1, ARRW_AFLUENTE_GIF_STATE_QUIET, ui->gif_modulo_7);
//    mod_efluente = new mod_flechas(EFLUENTE_1, ARRW_EFLUENTE_GIF_STATE_QUIET, ui->gif_modulo_8);
//    mod_sludge_a = new mod_flechas(SLUDGE_1,  ARRW_SLUDGE_GIF_STATE_QUIET, ui->gif_sludge_a);
//    mod_sludge_b = new mod_flechas(SLUDGE_1,  ARRW_SLUDGE_GIF_STATE_QUIET, ui->gif_sludge_b);
//    mod_water_flown_a = new mod_flechas(WATER_FLOWN_1,  ARRW_WATER_FLOWN_GIF_STATE_QUIET, ui->gif_water_flown_a);
//    mod_sludge_return = new mod_flechas(SLUDGE_RETURN,  ARRW_SLUDGE_RETURN_GIF_STATE_QUIET, ui->gif_sludge_return_a);
//    mod_blower = new mod_flechas(BLOWER,  ARRW_SLUDGE_RETURN_GIF_STATE_QUIET, ui->gif_blower);
//    mod_bomba = new mod_flechas(CARCAMO_MOTOR,  0, ui->gif_car_mot);

    ASA_protocol_init();
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
    SelectParemeter(PARAM_ELECTRIC);
    ui->active_param_label->setText("Parametros Eléctricos");
}

void MainWindow::handleParametrosFisicosButton()
{
    SelectParemeter(PARAM_PHYSHIC);
    ui->active_param_label->setText("Parametros Físicos");
}

void MainWindow::handleParametrosQuimicosButton()
{
    SelectParemeter(PARAM_CHEMIC);
    ui->active_param_label->setText("Parametros Químicos");
}

void MainWindow::handleDetailedView_1()
{
    if (detail_window != NULL) {
        delete detail_window;
    }
    detail_window = new detailedwindow(ELEMENT_REGULADOR, rutinas, this);
}
void MainWindow::handleDetailedView_2()
{
    if (detail_window != NULL) {
        delete detail_window;
    }
    detail_window = new detailedwindow(ELEMENT_REACTOR, rutinas, this);
}
void MainWindow::handleDetailedView_3()
{
    if (detail_window != NULL) {
        delete detail_window;
    }
    detail_window = new detailedwindow(ELEMENT_CLARIFICADOR, rutinas, this);
}
void MainWindow::handleDetailedView_4()
{
    if (detail_window != NULL) {
        delete detail_window;
    }
    detail_window = new detailedwindow(ELEMENT_CLORADOR, rutinas, this);
}
void MainWindow::handleDetailedView_5()
{
    if (detail_window != NULL) {
        delete detail_window;
    }
    detail_window = new detailedwindow(ELEMENT_DIGESTOR, rutinas, this);
}
void MainWindow::handleDetailedView_6()
{
    if (detail_window != NULL) {
        delete detail_window;
    }
    detail_window = new detailedwindow(ELEMENT_DESHIDRATADOR, rutinas, this);
}

void MainWindow::handleDetailedView_7()
{
    if (detail_window != NULL) {
        delete detail_window;
    }
    detail_window = new detailedwindow(ELEMENT_AFLUENTE, rutinas, this);
}

void MainWindow::handleDetailedView_8()
{
    if (detail_window != NULL) {
        delete detail_window;
    }
    detail_window = new detailedwindow(ELEMENT_EFLUENTE, rutinas, this);
}

void MainWindow::on_asa_logo_clicked()
{
    this->close();
}

void MainWindow::dataTimerSlot()
{
    static uint count = 0;

    check_lock();

#if (1 == ENABLE_TEST)
    if(0 == (count % 10)) /* 1 segundo */
    {
        run_simulation();
    }
#endif


    if(0 == (count % 2)) /* 20 ms */
    {
        // Fastest time for smooth transition when moving
        update_tooltips();
    }


    if(0 == (count % 10)) /* 2 segundo */
    {
//        update_ASA_string();

#if (1 ==ENABLE_TEST)
        /***** DEMO *****/
//        mod_1->check_update_animation();
//        mod_2->check_update_animation();
//        mod_3->check_update_animation();
//        mod_4->check_update_animation();
//        mod_5->check_update_animation();

//        mod_afluente->check_update_animation();
//        mod_efluente->check_update_animation();
//        mod_sludge_return->check_update_animation();
//        mod_blower->check_update_animation();
//        mod_bomba->check_update_animation();
#endif
    }

    count++;

}


//void MainWindow::get_ASA_string()
//{
//    MainWindow::ASA_conf_only_string = get_config_string();
//    qDebug() << ASA_conf_only_string;
//}

//void MainWindow::update_ASA_string(void)
//{
//    QString out_data;

//    out_data += "|";
//    out_data += "80:";
//    out_data += QString("%1").arg(reg_op_mode,2,16, QChar('0'));
//    out_data += "|";
//    out_data += "81:";
//    out_data += QString("%1").arg(reg_mot_1,2,16, QChar('0'));
//    out_data += "|";
//    out_data += "82:";
//    out_data += QString("%1").arg(reg_mot_2,2,16, QChar('0'));

//    ASA_conf_string = ASA_conf_only_string + out_data;
//    qDebug() << ASA_conf_string;
//}

void MainWindow::trace_lines(QWidget * tooltip, QPushButton *module, QPainter &painter)
{
    static uint i = 0;
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
//    this->update();
//     QPainter painter(this);

//     QColor line_color;
//     line_color.setRgb(0, 167, 250,150);

//     QPen pen;
//     pen.setColor(line_color);
//     pen.setCapStyle(Qt::RoundCap);
//     pen.setWidth(3);
//     painter.setPen(pen);

//     trace_lines(ui->widget, ui->modulo_1, painter);
//     trace_lines(ui->widget_2, ui->modulo_1, painter);
//     trace_lines(ui->widget_3, ui->modulo_1, painter);

//     trace_lines(ui->widget_4, ui->modulo_2, painter);
//     trace_lines(ui->widget_5, ui->modulo_2, painter);
//     trace_lines(ui->widget_6, ui->modulo_2, painter);

//     trace_lines(ui->widget_7, ui->modulo_3, painter);
//     trace_lines(ui->widget_8, ui->modulo_3, painter);
//     trace_lines(ui->widget_9, ui->modulo_3, painter);

//     trace_lines(ui->widget_10, ui->modulo_4, painter);
//     trace_lines(ui->widget_11, ui->modulo_4, painter);
//     trace_lines(ui->widget_12, ui->modulo_4, painter);
}

/* WINDOWS */
void MainWindow::on_top_menu_4_clicked()
{

}

void MainWindow::on_top_menu_5_clicked()
{
    if(settingswindow != NULL)
    {
        delete settingswindow;
    }

    settingswindow = new settings(this);

}

void MainWindow::on_top_menu_2_clicked()
{
    if(bitacorawindow !=NULL)
    {
        delete bitacorawindow;
    }
    bitacorawindow = new bitacora(rutinas, this);

//    if(detail_window !=NULL)
//    {
//        delete detail_window;
//    }

}


void MainWindow::update_tooltips(void)
{
    if(true == display_parameters)
    {
        switch(GetParemeter())
        {
        case PARAM_ELECTRIC:
            tool_tip_regulador_electricos->force_show();
            tool_tip_reactor_electricos->force_show();
            tool_tip_clarificador_electricos->force_show();
            tool_tip_clorador_electricos->force_show();
            tool_tip_digestor_electricos->force_show();
            tool_tip_deshidratador_electricos->force_show();
            tool_tip_afluente_electricos->force_show();
            tool_tip_efluente_electricos->force_show();

            tool_tip_regulador_fisicos->force_hide();
            tool_tip_reactor_fisicos->force_hide();
            tool_tip_clarificador_fisicos->force_hide();
            tool_tip_clorador_fisicos->force_hide();
            tool_tip_digestor_fisicos->force_hide();
            tool_tip_deshidratador_fisicos->force_hide();
            tool_tip_afluente_fisicos->force_hide();
            tool_tip_efluente_fisicos->force_hide();

            tool_tip_regulador_quimicos->force_hide();
            tool_tip_reactor_quimicos->force_hide();
            tool_tip_clarificador_quimicos->force_hide();
            tool_tip_clorador_quimicos->force_hide();
            tool_tip_digestor_quimicos->force_hide();
            tool_tip_deshidratador_quimicos->force_hide();
            tool_tip_afluente_quimicos->force_hide();
            tool_tip_efluente_quimicos->force_hide();

            break;
        case PARAM_PHYSHIC:
            tool_tip_regulador_electricos->force_hide();
            tool_tip_reactor_electricos->force_hide();
            tool_tip_clarificador_electricos->force_hide();
            tool_tip_clorador_electricos->force_hide();
            tool_tip_digestor_electricos->force_hide();
            tool_tip_deshidratador_electricos->force_hide();
            tool_tip_afluente_electricos->force_hide();
            tool_tip_efluente_electricos->force_hide();

            tool_tip_regulador_fisicos->force_show();
            tool_tip_reactor_fisicos->force_show();
            tool_tip_clarificador_fisicos->force_show();
            tool_tip_clorador_fisicos->force_show();
            tool_tip_digestor_fisicos->force_show();
            tool_tip_deshidratador_fisicos->force_show();
            tool_tip_afluente_fisicos->force_show();
            tool_tip_efluente_fisicos->force_show();

            tool_tip_regulador_quimicos->force_hide();
            tool_tip_reactor_quimicos->force_hide();
            tool_tip_clarificador_quimicos->force_hide();
            tool_tip_clorador_quimicos->force_hide();
            tool_tip_digestor_quimicos->force_hide();
            tool_tip_deshidratador_quimicos->force_hide();
            tool_tip_afluente_quimicos->force_hide();
            tool_tip_efluente_quimicos->force_hide();

            break;
        case PARAM_CHEMIC:
            tool_tip_regulador_electricos->force_hide();
            tool_tip_reactor_electricos->force_hide();
            tool_tip_clarificador_electricos->force_hide();
            tool_tip_clorador_electricos->force_hide();
            tool_tip_digestor_electricos->force_hide();
            tool_tip_deshidratador_electricos->force_hide();
            tool_tip_afluente_electricos->force_hide();
            tool_tip_efluente_electricos->force_hide();

            tool_tip_regulador_fisicos->force_hide();
            tool_tip_reactor_fisicos->force_hide();
            tool_tip_clarificador_fisicos->force_hide();
            tool_tip_clorador_fisicos->force_hide();
            tool_tip_digestor_fisicos->force_hide();
            tool_tip_deshidratador_fisicos->force_hide();
            tool_tip_afluente_fisicos->force_hide();
            tool_tip_efluente_fisicos->force_hide();

            tool_tip_regulador_quimicos->force_show();
            tool_tip_reactor_quimicos->force_show();
            tool_tip_clarificador_quimicos->force_show();
            tool_tip_clorador_quimicos->force_show();
            tool_tip_digestor_quimicos->force_show();
            tool_tip_deshidratador_quimicos->force_show();
            tool_tip_afluente_quimicos->force_show();
            tool_tip_efluente_quimicos->force_show();

            break;
        default:
            break;
        }
    }
    else
    {
        if(init_complete)
        {
            tool_tip_regulador_electricos->update_data();
            tool_tip_reactor_electricos->update_data();
            tool_tip_clarificador_electricos->update_data();
            tool_tip_clorador_electricos->update_data();
            tool_tip_digestor_electricos->update_data();
            tool_tip_deshidratador_electricos->update_data();
            tool_tip_afluente_electricos->update_data();
            tool_tip_efluente_electricos->update_data();

            tool_tip_regulador_fisicos->update_data();
            tool_tip_reactor_fisicos->update_data();
            tool_tip_clarificador_fisicos->update_data();
            tool_tip_clorador_fisicos->update_data();
            tool_tip_digestor_fisicos->update_data();
            tool_tip_deshidratador_fisicos->update_data();
            tool_tip_afluente_fisicos->update_data();
            tool_tip_efluente_fisicos->update_data();

            tool_tip_regulador_quimicos->update_data();
            tool_tip_reactor_quimicos->update_data();
            tool_tip_clarificador_quimicos->update_data();
            tool_tip_clorador_quimicos->update_data();
            tool_tip_digestor_quimicos->update_data();
            tool_tip_deshidratador_quimicos->update_data();
            tool_tip_afluente_quimicos->update_data();
            tool_tip_efluente_quimicos->update_data();

        }

    }
}

void MainWindow::new_spi_data()
{
    /* Update data in detailed window (if open) */
    if((NULL != detail_window) && detail_window->isActiveWindow())
    {
        detail_window->update_params();
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
        time = QDateTime::currentDateTime();
    }
    else
    {
        time = QDateTime::fromString(hora, time_format);
    }

    if(temp_time.toTime_t() != time.toTime_t())
    {
        temp_time = time;

        //Update bitacora and rutinas
        /* Check rutinas (new events have occurred?) */
        if(NULL != rutinas)
        {

            rutinas->set_time(time);
            rutinas->check_rutinas();
        }

        /* Check update values in bitacora window (if open) */
        if((NULL != bitacorawindow) && bitacorawindow->isActiveWindow())
        {
            bitacorawindow->update_table();
        }

        //Update text on screen
        QString display_time = QString::number(time.date().year())+"/"+QString::number(time.date().month())+"/"+QString::number(time.date().day())+" "+time.time().toString();
        ui->label_hora->setText(display_time);

        add_value_to_stats(0x3001, getParamValue(0x3001).toInt());
        add_value_to_stats(0x3002, getParamValue(0x3002).toInt());
        add_value_to_stats(0x3003, getParamValue(0x3003).toInt());
        add_value_to_stats(0x3004, getParamValue(0x3004).toInt());
        add_value_to_stats(0x3005, getParamValue(0x3005).toInt());
        add_value_to_stats(0x3006, getParamValue(0x3006).toInt());

        add_value_to_stats(0x3203, getParamValue(0x3203).toInt());
        add_value_to_stats(0x4203, getParamValue(0x4203).toInt());
        add_value_to_stats(0x5201, getParamValue(0x5201).toInt());
        add_value_to_stats(0x3201, getParamValue(0x3201).toInt());
        add_value_to_stats(0x4204, getParamValue(0x4204).toInt());
        add_value_to_stats(0x8204, getParamValue(0x8204).toInt());


        add_value_to_stats(0x3307, getParamValue(0x3307).toInt());
        add_value_to_stats(0x3305, getParamValue(0x3305).toInt());
        add_value_to_stats(0x3303, getParamValue(0x3303).toInt());
        add_value_to_stats(0x3301, getParamValue(0x3301).toInt());

        add_value_to_stats(0x5307, getParamValue(0x5307).toInt());
        add_value_to_stats(0x5305, getParamValue(0x5305).toInt());
        add_value_to_stats(0x5303, getParamValue(0x5303).toInt());
        add_value_to_stats(0x5301, getParamValue(0x5301).toInt());

        // Update graph if open
        if(false == graph->isHidden())
        {
            graph->update_graph();
        }

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
            ui->lock_button->setStyleSheet("border-image: url(:/iconos/screen800x600/iconos/unlocked.png);"
                                           "border: none;"
                                           "background-repeat: none;"
                                           "background-position: center;");
        }
        else
        {
            ui->lock_button->setStyleSheet("border-image: url(:/iconos/screen800x600/iconos/locked.png);"
                                           "border: none;"
                                           "background-repeat: none;"
                                           "background-position: center;");
        }
    }

    last_validity_state = state;
}

void MainWindow::on_lock_button_clicked()
{
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

void MainWindow::on_pb_simulacion_clicked()
{
    if(simulation)
    {
        simulation = false;
        ui->pb_simulacion->setText("Simulacion OFF");
        ui->pb_simulacion->setStyleSheet("color: red;"
                                         "border: 1px solid red;");
    }
    else
    {
        simulation = true;
        ui->pb_simulacion->setText("Simulacion ON");
        ui->pb_simulacion->setStyleSheet("color: green;"
                                        "border: 1px solid green;");
    }
}
