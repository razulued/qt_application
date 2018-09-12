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

configuration_id MainWindow::conf_filtro_elect;
configuration_id MainWindow::conf_filtro_fisic;
configuration_id MainWindow::conf_filtro_quimi;

configuration_id MainWindow::conf_filtro_bomba_elect;
configuration_id MainWindow::conf_filtro_bomba_fisic;
configuration_id MainWindow::conf_filtro_bomba_quimi;

configuration_id MainWindow::reg_outputs;
configuration_id MainWindow::react_outputs;
configuration_id MainWindow::clarif_outputs;
configuration_id MainWindow::clora_outputs;
configuration_id MainWindow::digest_outputs;
configuration_id MainWindow::deshid_outputs;
configuration_id MainWindow::afluente_outputs;
configuration_id MainWindow::efluente_outputs;
configuration_id MainWindow::filtro_outputs;
configuration_id MainWindow::filtro_bomba_outputs;

int MainWindow::reg_op_mode;
int MainWindow::reg_mot_1;
int MainWindow::reg_mot_2;

#if (1 == RELEASE_FOR_RPI)
bool MainWindow::simulation =false;
#else
bool MainWindow::simulation =true;
#endif

QDateTime MainWindow::time;

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

    tool_tip_regulador_electricos = new custom_tooltip(ui->widget, conf_reg_elect.ids, conf_reg_elect.names, reg_outputs.ids, reg_outputs.names, this, ui->modulo_1, TYPE_ELECTRICOS, graph, this->my_name);
    tool_tip_regulador_fisicos = new custom_tooltip(ui->widget_2, conf_reg_fisic.ids, conf_reg_fisic.names, reg_outputs.ids, reg_outputs.names, this, ui->modulo_1, TYPE_FISICOS, graph, this->my_name);
    tool_tip_regulador_quimicos = new custom_tooltip(ui->widget_3, conf_reg_quimic.ids, conf_reg_quimic.names, reg_outputs.ids, reg_outputs.names, this, ui->modulo_1, TYPE_QUIMICOS, graph, this->my_name);

    tool_tip_reactor_electricos = new custom_tooltip(ui->widget_4, conf_react_elect.ids, conf_react_elect.names, react_outputs.ids, react_outputs.names, this, ui->modulo_2, TYPE_ELECTRICOS, graph, this->my_name);
    tool_tip_reactor_fisicos = new custom_tooltip(ui->widget_5, conf_react_fisic.ids, conf_react_fisic.names, react_outputs.ids, react_outputs.names, this, ui->modulo_2, TYPE_FISICOS, graph, this->my_name);
    tool_tip_reactor_quimicos = new custom_tooltip(ui->widget_6, conf_react_quimi.ids, conf_react_quimi.names, react_outputs.ids, react_outputs.names, this, ui->modulo_2, TYPE_QUIMICOS, graph, this->my_name);

    tool_tip_clarificador_electricos = new custom_tooltip(ui->widget_7, conf_clarif_elect.ids, conf_clarif_elect.names, clarif_outputs.ids, clarif_outputs.names, this, ui->modulo_3, TYPE_ELECTRICOS, graph, this->my_name);
    tool_tip_clarificador_fisicos = new custom_tooltip(ui->widget_8, conf_clarif_fisic.ids, conf_clarif_fisic.names, clarif_outputs.ids, clarif_outputs.names, this, ui->modulo_3, TYPE_FISICOS, graph, this->my_name);
    tool_tip_clarificador_quimicos = new custom_tooltip(ui->widget_9, conf_clarif_quimi.ids, conf_clarif_quimi.names, clarif_outputs.ids, clarif_outputs.names, this, ui->modulo_3, TYPE_QUIMICOS, graph, this->my_name);

    tool_tip_clorador_electricos = new custom_tooltip(ui->widget_10, conf_clora_elect.ids, conf_clora_elect.names, clora_outputs.ids, clora_outputs.names, this, ui->modulo_4, TYPE_ELECTRICOS, graph, this->my_name);
    tool_tip_clorador_fisicos = new custom_tooltip(ui->widget_11, conf_clora_fisic.ids, conf_clora_fisic.names, clora_outputs.ids, clora_outputs.names, this, ui->modulo_4, TYPE_FISICOS, graph, this->my_name);
    tool_tip_clorador_quimicos = new custom_tooltip(ui->widget_12, conf_clora_quimi.ids, conf_clora_quimi.names, clora_outputs.ids, clora_outputs.names, this, ui->modulo_4, TYPE_QUIMICOS, graph, this->my_name);

    tool_tip_digestor_electricos = new custom_tooltip(ui->widget_13, conf_digest_elect.ids, conf_digest_elect.names, digest_outputs.ids, digest_outputs.names, this, ui->modulo_5, TYPE_ELECTRICOS, graph, this->my_name);
    tool_tip_digestor_fisicos = new custom_tooltip(ui->widget_14, conf_digest_fisic.ids, conf_digest_fisic.names, digest_outputs.ids, digest_outputs.names, this, ui->modulo_5, TYPE_FISICOS, graph, this->my_name);
    tool_tip_digestor_quimicos = new custom_tooltip(ui->widget_15, conf_digest_quimi.ids, conf_digest_quimi.names, digest_outputs.ids, digest_outputs.names, this, ui->modulo_5, TYPE_QUIMICOS, graph, this->my_name);

    tool_tip_deshidratador_electricos = new custom_tooltip(ui->widget_16, conf_deshid_elect.ids, conf_deshid_elect.names, deshid_outputs.ids, deshid_outputs.names, this, ui->modulo_6, TYPE_ELECTRICOS, graph, this->my_name);
    tool_tip_deshidratador_fisicos = new custom_tooltip(ui->widget_17, conf_deshid_fisic.ids, conf_deshid_fisic.names, deshid_outputs.ids, deshid_outputs.names, this, ui->modulo_6, TYPE_FISICOS, graph, this->my_name);
    tool_tip_deshidratador_quimicos = new custom_tooltip(ui->widget_18, conf_deshid_quimi.ids, conf_deshid_quimi.names, deshid_outputs.ids, deshid_outputs.names, this, ui->modulo_6, TYPE_QUIMICOS, graph, this->my_name);

    tool_tip_afluente_electricos = new custom_tooltip(ui->widget_19, conf_afluente_elect.ids, conf_afluente_elect.names, afluente_outputs.ids, afluente_outputs.names, this, ui->modulo_7, TYPE_ELECTRICOS, graph, this->my_name);
    tool_tip_afluente_fisicos = new custom_tooltip(ui->widget_20, conf_afluente_fisic.ids, conf_afluente_fisic.names, afluente_outputs.ids, afluente_outputs.names, this, ui->modulo_7, TYPE_FISICOS, graph, this->my_name);
    tool_tip_afluente_quimicos = new custom_tooltip(ui->widget_21, conf_afluente_quimi.ids, conf_afluente_quimi.names, afluente_outputs.ids, afluente_outputs.names, this, ui->modulo_7, TYPE_QUIMICOS, graph, this->my_name);

    tool_tip_efluente_electricos = new custom_tooltip(ui->widget_22, conf_efluente_elect.ids, conf_efluente_elect.names, efluente_outputs.ids, efluente_outputs.names, this, ui->modulo_8, TYPE_ELECTRICOS, graph, this->my_name);
    tool_tip_efluente_fisicos = new custom_tooltip(ui->widget_23, conf_efluente_fisic.ids, conf_efluente_fisic.names, efluente_outputs.ids, efluente_outputs.names, this, ui->modulo_8, TYPE_FISICOS, graph, this->my_name);
    tool_tip_efluente_quimicos = new custom_tooltip(ui->widget_24, conf_efluente_quimi.ids, conf_efluente_quimi.names, efluente_outputs.ids, efluente_outputs.names, this, ui->modulo_8, TYPE_QUIMICOS, graph, this->my_name);

//    tool_tip_filtro_electricos = new custom_tooltip(ui->widget_25, conf_filtro_elect.ids, conf_filtro_elect.names, filtro_outputs.ids, filtro_outputs.names, this, ui->modulo_9, TYPE_ELECTRICOS, graph);
//    tool_tip_filtro_fisicos = new custom_tooltip(ui->widget_26, conf_filtro_fisic.ids, conf_filtro_fisic.names, filtro_outputs.ids, filtro_outputs.names, this, ui->modulo_9, TYPE_FISICOS, graph);
//    tool_tip_filtro_quimicos = new custom_tooltip(ui->widget_27, conf_filtro_quimi.ids, conf_filtro_quimi.names, filtro_outputs.ids, filtro_outputs.names, this, ui->modulo_9, TYPE_QUIMICOS, graph);

    init_complete = true;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    my_name = "PTAR";
    graph = new graphwindow(this);
    connect(graph, SIGNAL(forward_bitacora_clicked()),this, SLOT (on_top_menu_2_clicked()));
    connect(graph, SIGNAL(forward_control_clicked()),this, SLOT (on_top_menu_6_clicked()));

    // Init SPI
    dataObj = new DataProccess;
    dataObj->start();

    // Rutinas y DB
    rutinas = new rutinas_mantenimiento("rutinas.db");

//    records *rec_ptr = new records("rutinas.db", 103, 6, this);

    //Get config
    validate_token(false);
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

    config = new configuration("Filtro-Electricos");
    conf_filtro_elect = config->get_config();
    config = new configuration("Filtro-Fisicos");
    conf_filtro_fisic = config->get_config();
    config = new configuration("Filtro-Quimicos");
    conf_filtro_quimi = config->get_config();

    config = new configuration("Filtro-Bomba-Electricos");
    conf_filtro_bomba_elect = config->get_config();
    config = new configuration("Filtro-Bomba-Fisicos");
    conf_filtro_bomba_fisic = config->get_config();
    config = new configuration("Filtro-Bomba-Quimicos");
    conf_filtro_bomba_quimi = config->get_config();

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
    config = new configuration("Filtro-Out");
    filtro_outputs = config->get_config();
    config = new configuration("Filtro-Bomba-Out");
    filtro_bomba_outputs = config->get_config();

    config = new configuration("Product-Config");
    if("1" == config->get_value("Product-Config", "Filtro"))
    {
        filtro_present = true;
    }

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
    connect(ui->modulo_1, SIGNAL (released()),this, SLOT (handleDetailedView_1()));
    connect(ui->modulo_2, SIGNAL (released()),this, SLOT (handleDetailedView_2()));
    connect(ui->modulo_3, SIGNAL (released()),this, SLOT (handleDetailedView_3()));
    connect(ui->modulo_4, SIGNAL (released()),this, SLOT (handleDetailedView_4()));
    connect(ui->modulo_5, SIGNAL (released()),this, SLOT (handleDetailedView_5()));
    connect(ui->modulo_6, SIGNAL (released()),this, SLOT (handleDetailedView_6()));
    connect(ui->modulo_7, SIGNAL (released()),this, SLOT (handleDetailedView_7()));
    connect(ui->modulo_8, SIGNAL (released()),this, SLOT (handleDetailedView_8()));
//    connect(ui->modulo_9, SIGNAL (released()),this, SLOT (handleDetailedView_9()));

    QFont active_parameter_font("Typo Square Bold Demo",16,1);
    ui->active_param_label->setFont(active_parameter_font);

    ui->active_param_label->setStyleSheet("color:black");
    ui->active_param_label->setText("Parametros Eléctricos");

    QFont hora_font("Typo Square Ligth Demo",18,1);
    QFont dia_font("Typo Square Ligth Demo",14,1);

    ui->label_hora->setStyleSheet("color: white");
    ui->label_hora->setFont(hora_font);
    ui->label_dia->setStyleSheet("color: white");
    ui->label_dia->setFont(dia_font);
//    button.setStyleSheet( FormStyleSheetString( "button" ) );
//     button.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
//     button.setIconSize(QSize(200,200));
//     button.show();

    mod_1 = new mod_1_carcamo(ui->gif_modulo_1);
    connect(mod_1, SIGNAL(update_window()), this, SLOT(update_this()));
    mod_2 = new mod_2_reactor(ui->gif_modulo_2);
    connect(mod_2, SIGNAL(update_window()), this, SLOT(update_this()));
    mod_3 = new mod_3_clarificador(ui->gif_modulo_3);
    connect(mod_3, SIGNAL(update_window()), this, SLOT(update_this()));
    mod_4 = new mod_4_clorador(ui->gif_modulo_4);
    connect(mod_4, SIGNAL(update_window()), this, SLOT(update_this()));
    mod_5 = new mod_5_digestor(ui->gif_modulo_5);
    connect(mod_5, SIGNAL(update_window()), this, SLOT(update_this()));
//    mod_6 = new mod_6_lechos(ui->gif_modulo_6);
    mod_afluente = new mod_flechas(AFLUENTE_1, ARRW_AFLUENTE_GIF_STATE_QUIET, ui->gif_modulo_7);
    connect(mod_afluente, SIGNAL(update_window()), this, SLOT(update_this()));
    mod_efluente = new mod_flechas(EFLUENTE_1, ARRW_EFLUENTE_GIF_STATE_QUIET, ui->gif_modulo_8);
    connect(mod_efluente, SIGNAL(update_window()), this, SLOT(update_this()));
    mod_sludge_a = new mod_flechas(SLUDGE_1,  ARRW_SLUDGE_GIF_STATE_QUIET, ui->gif_sludge_a);
    connect(mod_sludge_a, SIGNAL(update_window()), this, SLOT(update_this()));
    mod_sludge_b = new mod_flechas(SLUDGE_1,  ARRW_SLUDGE_GIF_STATE_QUIET, ui->gif_sludge_b);
    connect(mod_sludge_b, SIGNAL(update_window()), this, SLOT(update_this()));
    mod_water_flown_a = new mod_flechas(WATER_FLOWN_1,  ARRW_WATER_FLOWN_GIF_STATE_QUIET, ui->gif_water_flown_a);
    connect(mod_water_flown_a, SIGNAL(update_window()), this, SLOT(update_this()));
    mod_sludge_return = new mod_flechas(SLUDGE_RETURN,  ARRW_SLUDGE_RETURN_GIF_STATE_QUIET, ui->gif_sludge_return_a);
    connect(mod_sludge_return, SIGNAL(update_window()), this, SLOT(update_this()));

    mod_blower_1 = new mod_flechas(BLOWER_1,  3, ui->gif_blower_4);
    connect(mod_blower_1, SIGNAL(update_window()), this, SLOT(update_this()));
    mod_blower_2 = new mod_flechas(BLOWER_2,  3, ui->gif_blower_3);
    connect(mod_blower_2, SIGNAL(update_window()), this, SLOT(update_this()));
    mod_blower_3 = new mod_flechas(BLOWER_3,  3, ui->gif_blower_2);
    connect(mod_blower_3, SIGNAL(update_window()), this, SLOT(update_this()));
    mod_blower_4 = new mod_flechas(BLOWER_4,  3, ui->gif_blower);
    connect(mod_blower_4, SIGNAL(update_window()), this, SLOT(update_this()));

    mod_bomba_1 = new mod_flechas(CARCAMO_MOTOR_1,  3, ui->gif_car_mot_4);
    connect(mod_bomba_1, SIGNAL(update_window()), this, SLOT(update_this()));
    mod_bomba_2 = new mod_flechas(CARCAMO_MOTOR_2,  3, ui->gif_car_mot_3);
    connect(mod_bomba_2, SIGNAL(update_window()), this, SLOT(update_this()));
    mod_bomba_3 = new mod_flechas(CARCAMO_MOTOR_3,  3, ui->gif_car_mot_2);
    connect(mod_bomba_3, SIGNAL(update_window()), this, SLOT(update_this()));
    mod_bomba_4 = new mod_flechas(CARCAMO_MOTOR_4,  3, ui->gif_car_mot);
    connect(mod_bomba_4, SIGNAL(update_window()), this, SLOT(update_this()));
    ASA_protocol_init();

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
    ui->active_param_label->setText("Parametros Eléctricos");
}

void MainWindow::handleParametrosFisicosButton()
{
    InitButtons(ui->pb_electricos, ui->pb_fisicos, ui->pb_quimicos);
    SelectParemeter(PARAM_PHYSHIC);
    ui->active_param_label->setText("Parametros Físicos");
}

void MainWindow::handleParametrosQuimicosButton()
{
    InitButtons(ui->pb_electricos, ui->pb_fisicos, ui->pb_quimicos);
    SelectParemeter(PARAM_CHEMIC);
    ui->active_param_label->setText("Parametros Químicos");
}

void MainWindow::window_closed()
{
    qDebug() << "release lock";
    mutex_detailed.unlock();
}

void MainWindow::handleDetailedView_1()
{
    qDebug() << "handleDetailedView_1";
    if(mutex_detailed.tryLock(0))
    {
        qDebug() << "lock OK";

        if (detail_window != NULL) {
            qDebug() << "delete";
            delete detail_window;
        }
        detail_window = new detailedwindow(ELEMENT_REGULADOR, rutinas, this);
        connect(detail_window, SIGNAL(release_lock()), this, SLOT(window_closed()));
        detail_window->show();
    }
    else
    {
        qDebug() << "lock NOK";
    }
}
void MainWindow::handleDetailedView_2()
{
    if(mutex_detailed.tryLock(0))
    {
        if (detail_window != NULL) {
            delete detail_window;
        }
        detail_window = new detailedwindow(ELEMENT_REACTOR, rutinas, this);
        connect(detail_window, SIGNAL(release_lock()), this, SLOT(window_closed()));
        detail_window->show();
    }
}
void MainWindow::handleDetailedView_3()
{
    if(mutex_detailed.tryLock(0))
    {
        if (detail_window != NULL) {
            delete detail_window;
        }
        detail_window = new detailedwindow(ELEMENT_CLARIFICADOR, rutinas, this);
        connect(detail_window, SIGNAL(release_lock()), this, SLOT(window_closed()));
        detail_window->show();
    }
}
void MainWindow::handleDetailedView_4()
{
    if(mutex_detailed.tryLock(0))
    {
        if (detail_window != NULL) {
            delete detail_window;
        }
        detail_window = new detailedwindow(ELEMENT_CLORADOR, rutinas, this);
        connect(detail_window, SIGNAL(release_lock()), this, SLOT(window_closed()));
        detail_window->show();
    }
}
void MainWindow::handleDetailedView_5()
{
    if(mutex_detailed.tryLock(0))
    {
        if (detail_window != NULL) {
            delete detail_window;
        }
        detail_window = new detailedwindow(ELEMENT_DIGESTOR, rutinas, this);
        connect(detail_window, SIGNAL(release_lock()), this, SLOT(window_closed()));
        detail_window->show();
    }
}
void MainWindow::handleDetailedView_6()
{
    if(mutex_detailed.tryLock(0))
    {
        if (detail_window != NULL) {
            delete detail_window;
        }
        detail_window = new detailedwindow(ELEMENT_DESHIDRATADOR, rutinas, this);
        connect(detail_window, SIGNAL(release_lock()), this, SLOT(window_closed()));
        detail_window->show();
    }
}

void MainWindow::handleDetailedView_7()
{
    if(mutex_detailed.tryLock(0))
    {
        if (detail_window != NULL) {
            delete detail_window;
        }
        detail_window = new detailedwindow(ELEMENT_AFLUENTE, rutinas, this);
        connect(detail_window, SIGNAL(release_lock()), this, SLOT(window_closed()));
        detail_window->show();
    }
}

void MainWindow::handleDetailedView_8()
{
    if(mutex_detailed.tryLock(0))
    {
        if (detail_window != NULL) {
            delete detail_window;
        }
        detail_window = new detailedwindow(ELEMENT_EFLUENTE, rutinas, this);
        connect(detail_window, SIGNAL(release_lock()), this, SLOT(window_closed()));
        detail_window->show();
    }
}

void MainWindow::handleDetailedView_9()
{
    if(mutex_detailed.tryLock(0))
    {
        if (detail_window != NULL) {
            delete detail_window;
        }
        detail_window = new detailedwindow(ELEMENT_FILTRO, rutinas, this);
        connect(detail_window, SIGNAL(release_lock()), this, SLOT(window_closed()));
        detail_window->show();
    }
}

void MainWindow::update_this()
{
    qDebug() << "update this";
    this->update();
}

void MainWindow::update_buttons_from_filter(bool active, parameters_t param)
{
//    display_parameters = !active;
//    handleMenuButton();

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
    static bool goto_filtro = true;

    // Go to filtro for non-PTAR application
    if((true == goto_filtro && count > 5) && (true == filtro_present))
    {
        //TO FILTRO
        on_go_to_filtro_clicked();
        goto_filtro = false;
    }

    check_lock();


    if(0 == (count % 10)) /* 20 ms */
    {
        // Fastest time for smooth transition when moving
        update_tooltips();


        if((NULL != filt_window))
        {
            filt_window->update_tooltips();
        }
    }


    if(0 == (count % 20)) /* 2 segundo */
    {
        update_this();

    }
    if(0 == (count % 10)) /* 2 segundo */
    {
//        update_ASA_string();

#if (1 ==ENABLE_TEST)
        /***** DEMO *****/
        mod_1->check_update_animation();
        mod_2->check_update_animation();
        mod_3->check_update_animation();
        mod_4->check_update_animation();
        mod_5->check_update_animation();

        mod_afluente->check_update_animation();
        mod_efluente->check_update_animation();
        mod_sludge_return->check_update_animation();

        mod_blower_1->check_update_animation();
        mod_blower_2->check_update_animation();
        mod_blower_3->check_update_animation();
        mod_blower_4->check_update_animation();

        mod_bomba_1->check_update_animation();
        mod_bomba_2->check_update_animation();
        mod_bomba_3->check_update_animation();
        mod_bomba_4->check_update_animation();

#endif
    }

    count++;

//    if(NULL == stop_button_window && this->isVisible() && count>10)
//    {
//        stop_button_window = new stop_button(this);
//        stop_button_window->show();
//    }

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

void MainWindow::on_top_menu_5_clicked()
{
    if(true == get_validity_state())
    {
        if(mutex_detailed.tryLock(0))
        {
            if(settingswindow != NULL)
            {
                delete settingswindow;
            }
            settingswindow = new settings(this);
            connect(settingswindow, SIGNAL(release_lock()), this, SLOT(window_closed()));
            settingswindow->show();
        }
    }
}

void MainWindow::on_top_menu_2_clicked()
{
    if(mutex_detailed.tryLock(0))
    {
        if(bitacorawindow !=NULL)
        {
            delete bitacorawindow;
        }
        bitacorawindow = new bitacora(rutinas, this);
        connect(bitacorawindow, SIGNAL(release_lock()), this, SLOT(window_closed()));
        bitacorawindow->show();
    }
}


void MainWindow::update_tooltips(void)
{
    static uint count = 0;
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
//            tool_tip_filtro_electricos->force_show();

            tool_tip_regulador_fisicos->force_hide();
            tool_tip_reactor_fisicos->force_hide();
            tool_tip_clarificador_fisicos->force_hide();
            tool_tip_clorador_fisicos->force_hide();
            tool_tip_digestor_fisicos->force_hide();
            tool_tip_deshidratador_fisicos->force_hide();
            tool_tip_afluente_fisicos->force_hide();
            tool_tip_efluente_fisicos->force_hide();
//            tool_tip_filtro_fisicos->force_hide();

            tool_tip_regulador_quimicos->force_hide();
            tool_tip_reactor_quimicos->force_hide();
            tool_tip_clarificador_quimicos->force_hide();
            tool_tip_clorador_quimicos->force_hide();
            tool_tip_digestor_quimicos->force_hide();
            tool_tip_deshidratador_quimicos->force_hide();
            tool_tip_afluente_quimicos->force_hide();
            tool_tip_efluente_quimicos->force_hide();
//            tool_tip_filtro_quimicos->force_hide();

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
//            tool_tip_filtro_electricos->force_hide();


            tool_tip_regulador_fisicos->force_show();
            tool_tip_reactor_fisicos->force_show();
            tool_tip_clarificador_fisicos->force_show();
            tool_tip_clorador_fisicos->force_show();
            tool_tip_digestor_fisicos->force_show();
            tool_tip_deshidratador_fisicos->force_show();
            tool_tip_afluente_fisicos->force_show();
            tool_tip_efluente_fisicos->force_show();
//            tool_tip_filtro_fisicos->force_show();

            tool_tip_regulador_quimicos->force_hide();
            tool_tip_reactor_quimicos->force_hide();
            tool_tip_clarificador_quimicos->force_hide();
            tool_tip_clorador_quimicos->force_hide();
            tool_tip_digestor_quimicos->force_hide();
            tool_tip_deshidratador_quimicos->force_hide();
            tool_tip_afluente_quimicos->force_hide();
            tool_tip_efluente_quimicos->force_hide();
//            tool_tip_filtro_quimicos->force_hide();


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
//            tool_tip_filtro_electricos->force_hide();

            tool_tip_regulador_fisicos->force_hide();
            tool_tip_reactor_fisicos->force_hide();
            tool_tip_clarificador_fisicos->force_hide();
            tool_tip_clorador_fisicos->force_hide();
            tool_tip_digestor_fisicos->force_hide();
            tool_tip_deshidratador_fisicos->force_hide();
            tool_tip_afluente_fisicos->force_hide();
            tool_tip_efluente_fisicos->force_hide();
//            tool_tip_filtro_fisicos->force_hide();

            tool_tip_regulador_quimicos->force_show();
            tool_tip_reactor_quimicos->force_show();
            tool_tip_clarificador_quimicos->force_show();
            tool_tip_clorador_quimicos->force_show();
            tool_tip_digestor_quimicos->force_show();
            tool_tip_deshidratador_quimicos->force_show();
            tool_tip_afluente_quimicos->force_show();
            tool_tip_efluente_quimicos->force_show();
//            tool_tip_filtro_quimicos->force_show();

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
                tool_tip_regulador_electricos->update_data();
                tool_tip_reactor_electricos->update_data();
                tool_tip_clarificador_electricos->update_data();
                tool_tip_clorador_electricos->update_data();
                tool_tip_digestor_electricos->update_data();
                tool_tip_deshidratador_electricos->update_data();
                tool_tip_afluente_electricos->update_data();
                tool_tip_efluente_electricos->update_data();
    //            tool_tip_filtro_electricos->update_data();
                count++;
            }
            else if(1 == count)
            {
                tool_tip_regulador_fisicos->update_data();
                tool_tip_reactor_fisicos->update_data();
                tool_tip_clarificador_fisicos->update_data();
                tool_tip_clorador_fisicos->update_data();
                tool_tip_digestor_fisicos->update_data();
                tool_tip_deshidratador_fisicos->update_data();
                tool_tip_afluente_fisicos->update_data();
                tool_tip_efluente_fisicos->update_data();
    //            tool_tip_filtro_fisicos->update_data();
                count++;
            }
            else
            {
                tool_tip_regulador_quimicos->update_data();
                tool_tip_reactor_quimicos->update_data();
                tool_tip_clarificador_quimicos->update_data();
                tool_tip_clorador_quimicos->update_data();
                tool_tip_digestor_quimicos->update_data();
                tool_tip_deshidratador_quimicos->update_data();
                tool_tip_afluente_quimicos->update_data();
                tool_tip_efluente_quimicos->update_data();
    //            tool_tip_filtro_quimicos->update_data();
                count = 0;
            }

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

    if((NULL != motrores_window) && motrores_window->isActiveWindow())
    {
        motrores_window->update_motors();
    }

    /* Update filer data if open */
    if(NULL != filt_window && filt_window->isVisible())
    {
        filt_window->update_other(ui->label_dia->text(), ui->label_hora->text(), ui->label_title->text());
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
//        QString display_time = QString::number(time.date().year())+"/"+QString::number(time.date().month())+"/"+QString::number(time.date().day())+" "+time.time().toString();
//        QString display_time = QString::number(time.time().hour())+":"+QString::number(time.time().minute());
        QString display_time = QString::number(time.time().hour())+":"+QString("%1").arg(time.time().minute(), 2, 10, QChar('0'))+":"+QString("%1").arg(time.time().second(), 2, 10, QChar('0'));
        QString display_dia = build_date_string(time);

        ui->label_dia->setText(display_dia);
        ui->label_hora->setText(display_time);

        add_value_to_stats(0x3001, getParamValue(0x3001).toFloat());
        add_value_to_stats(0x3002, getParamValue(0x3002).toFloat());
        add_value_to_stats(0x3003, getParamValue(0x3003).toFloat());
        add_value_to_stats(0x3004, getParamValue(0x3004).toFloat());
        add_value_to_stats(0x3005, getParamValue(0x3005).toFloat());
        add_value_to_stats(0x3006, getParamValue(0x3006).toFloat());

        add_value_to_stats(0x3011, getParamValue(0x3011).toFloat());
        add_value_to_stats(0x3012, getParamValue(0x3012).toFloat());
        add_value_to_stats(0x3013, getParamValue(0x3013).toFloat());
        add_value_to_stats(0x3014, getParamValue(0x3014).toFloat());
        add_value_to_stats(0x3015, getParamValue(0x3015).toFloat());
        add_value_to_stats(0x3016, getParamValue(0x3016).toFloat());

        add_value_to_stats(0x3021, getParamValue(0x3021).toFloat());
        add_value_to_stats(0x3022, getParamValue(0x3022).toFloat());
        add_value_to_stats(0x3023, getParamValue(0x3023).toFloat());
        add_value_to_stats(0x3024, getParamValue(0x3024).toFloat());
        add_value_to_stats(0x3025, getParamValue(0x3025).toFloat());
        add_value_to_stats(0x3026, getParamValue(0x3026).toFloat());

        add_value_to_stats(0x3031, getParamValue(0x3031).toFloat());
        add_value_to_stats(0x3032, getParamValue(0x3032).toFloat());
        add_value_to_stats(0x3033, getParamValue(0x3033).toFloat());
        add_value_to_stats(0x3034, getParamValue(0x3034).toFloat());
        add_value_to_stats(0x3035, getParamValue(0x3035).toFloat());
        add_value_to_stats(0x3036, getParamValue(0x3036).toFloat());

        add_value_to_stats(0x4001, getParamValue(0x4001).toFloat());
        add_value_to_stats(0x4002, getParamValue(0x4002).toFloat());
        add_value_to_stats(0x4003, getParamValue(0x4003).toFloat());
        add_value_to_stats(0x4004, getParamValue(0x4004).toFloat());
        add_value_to_stats(0x4005, getParamValue(0x4005).toFloat());
        add_value_to_stats(0x4006, getParamValue(0x4006).toFloat());

        add_value_to_stats(0x4011, getParamValue(0x4011).toFloat());
        add_value_to_stats(0x4012, getParamValue(0x4012).toFloat());
        add_value_to_stats(0x4013, getParamValue(0x4013).toFloat());
        add_value_to_stats(0x4014, getParamValue(0x4014).toFloat());
        add_value_to_stats(0x4015, getParamValue(0x4015).toFloat());
        add_value_to_stats(0x4016, getParamValue(0x4016).toFloat());

        add_value_to_stats(0x4021, getParamValue(0x4021).toFloat());
        add_value_to_stats(0x4022, getParamValue(0x4022).toFloat());
        add_value_to_stats(0x4023, getParamValue(0x4023).toFloat());
        add_value_to_stats(0x4024, getParamValue(0x4024).toFloat());
        add_value_to_stats(0x4025, getParamValue(0x4025).toFloat());
        add_value_to_stats(0x4026, getParamValue(0x4026).toFloat());

        add_value_to_stats(0x4031, getParamValue(0x4031).toFloat());
        add_value_to_stats(0x4032, getParamValue(0x4032).toFloat());
        add_value_to_stats(0x4033, getParamValue(0x4033).toFloat());
        add_value_to_stats(0x4034, getParamValue(0x4034).toFloat());
        add_value_to_stats(0x4035, getParamValue(0x4035).toFloat());
        add_value_to_stats(0x4036, getParamValue(0x4036).toFloat());

        add_value_to_stats(0x4031, getParamValue(0x4031).toFloat());
        add_value_to_stats(0x4032, getParamValue(0x4032).toFloat());
        add_value_to_stats(0x4033, getParamValue(0x4033).toFloat());
        add_value_to_stats(0x4034, getParamValue(0x4034).toFloat());
        add_value_to_stats(0x4035, getParamValue(0x4035).toFloat());
        add_value_to_stats(0x4036, getParamValue(0x4036).toFloat());

        add_value_to_stats(0x9000, getParamValue(0x9000).toFloat());
        add_value_to_stats(0x9010, getParamValue(0x9010).toFloat());
        add_value_to_stats(0x9020, getParamValue(0x9020).toFloat());
        add_value_to_stats(0x9030, getParamValue(0x9030).toFloat());
        add_value_to_stats(0x9080, getParamValue(0x9080).toFloat());

        add_value_to_stats(0x9001, getParamValue(0x9001).toFloat());
        add_value_to_stats(0x9011, getParamValue(0x9011).toFloat());
        add_value_to_stats(0x9021, getParamValue(0x9021).toFloat());
        add_value_to_stats(0x9031, getParamValue(0x9031).toFloat());
        add_value_to_stats(0x9081, getParamValue(0x9081).toFloat());

        add_value_to_stats(0x9002, getParamValue(0x9002).toFloat());
        add_value_to_stats(0x9012, getParamValue(0x9012).toFloat());
        add_value_to_stats(0x9022, getParamValue(0x9022).toFloat());
        add_value_to_stats(0x9032, getParamValue(0x9032).toFloat());
        add_value_to_stats(0x9082, getParamValue(0x9082).toFloat());

        add_value_to_stats(0x9003, getParamValue(0x9003).toFloat());
        add_value_to_stats(0x9013, getParamValue(0x9013).toFloat());
        add_value_to_stats(0x9023, getParamValue(0x9023).toFloat());
        add_value_to_stats(0x9033, getParamValue(0x9033).toFloat());
        add_value_to_stats(0x9083, getParamValue(0x9083).toFloat());

        add_value_to_stats(0x9004, getParamValue(0x9004).toFloat());
        add_value_to_stats(0x9014, getParamValue(0x9014).toFloat());
        add_value_to_stats(0x9024, getParamValue(0x9024).toFloat());
        add_value_to_stats(0x9034, getParamValue(0x9034).toFloat());
        add_value_to_stats(0x9084, getParamValue(0x9084).toFloat());

        add_value_to_stats(0x9005, getParamValue(0x9005).toFloat());
        add_value_to_stats(0x9015, getParamValue(0x9015).toFloat());
        add_value_to_stats(0x9025, getParamValue(0x9025).toFloat());
        add_value_to_stats(0x9035, getParamValue(0x9035).toFloat());
        add_value_to_stats(0x9085, getParamValue(0x9085).toFloat());

        add_value_to_stats(0x9006, getParamValue(0x9006).toFloat());
        add_value_to_stats(0x9016, getParamValue(0x9016).toFloat());
        add_value_to_stats(0x9026, getParamValue(0x9026).toFloat());
        add_value_to_stats(0x9036, getParamValue(0x9036).toFloat());
        add_value_to_stats(0x9086, getParamValue(0x9086).toFloat());

        //FISICOS
        add_value_to_stats(GASTO_INS, getParamValue(GASTO_INS).toFloat());
        add_value_to_stats(GASTO_ACC, getParamValue(GASTO_ACC).toFloat());
        add_value_to_stats(PRES_AIR, getParamValue(PRES_AIR).toFloat());
        add_value_to_stats(PRES_FIL, getParamValue(PRES_FIL).toFloat());
        add_value_to_stats(NIVEL_CL, getParamValue(NIVEL_CL).toFloat());
        add_value_to_stats(NIVEL_REG, getParamValue(NIVEL_REG).toFloat());

        // QUIMICOS
        add_value_to_stats(OD_IN, getParamValue(OD_IN).toFloat());    //0x4307
        add_value_to_stats(SST_IN, getParamValue(SST_IN).toFloat());  //0x3305
        add_value_to_stats(Turb_IN, getParamValue(Turb_IN).toFloat());//0x3303
        add_value_to_stats(PH_IN, getParamValue(PH_IN).toFloat());    //0x3301

        add_value_to_stats(OD_OUT, getParamValue(OD_OUT).toFloat());
        add_value_to_stats(SST_OUT, getParamValue(SST_OUT).toFloat());
        add_value_to_stats(Turb_OUT, getParamValue(Turb_OUT).toFloat());
        add_value_to_stats(PH_OUT, getParamValue(PH_OUT).toFloat());

        //FISICOS
        add_value_to_stats(Filtro_GASTO_INS, getParamValue(Filtro_GASTO_INS).toFloat());
        add_value_to_stats(Filtro_GASTO_ACC, getParamValue(Filtro_GASTO_ACC).toFloat());
        add_value_to_stats(Filtro_PRES_AIR, getParamValue(Filtro_PRES_AIR).toFloat());
        add_value_to_stats(Filtro_PRES_FIL, getParamValue(Filtro_PRES_FIL).toFloat());
        add_value_to_stats(Filtro_NIVEL_CL, getParamValue(Filtro_NIVEL_CL).toFloat());
        add_value_to_stats(Filtro_NIVEL_REG, getParamValue(Filtro_NIVEL_REG).toFloat());

        // QUIMICOS
        add_value_to_stats(Filtro_OD_IN, getParamValue(Filtro_OD_IN).toFloat());    //0x4307
        add_value_to_stats(Filtro_SST_IN, getParamValue(Filtro_SST_IN).toFloat());  //0x3305
        add_value_to_stats(Filtro_Turb_IN, getParamValue(Filtro_Turb_IN).toFloat());//0x3303
        add_value_to_stats(Filtro_PH_IN, getParamValue(Filtro_PH_IN).toFloat());    //0x3301

        add_value_to_stats(Filtro_OD_OUT, getParamValue(Filtro_OD_OUT).toFloat());
        add_value_to_stats(Filtro_SST_OUT, getParamValue(Filtro_SST_OUT).toFloat());
        add_value_to_stats(Filtro_Turb_OUT, getParamValue(Filtro_Turb_OUT).toFloat());
        add_value_to_stats(Filtro_PH_OUT, getParamValue(Filtro_PH_OUT).toFloat());
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
        dia_semana = "Lunes";
        break;
    case 2:
        dia_semana = "Martes";
        break;
    case 3:
        dia_semana = "Miércoles";
        break;
    case 4:
        dia_semana = "Jueves";
        break;
    case 5:
        dia_semana = "Viernes";
        break;
    case 6:
        dia_semana = "Sábado";
        break;
    case 7:
        dia_semana = "Domingo";
        break;
    }

    switch(time.date().month())
    {
    case 1:
        mes = "Enero";
        break;
    case 2:
        mes = "Febrero";
        break;
    case 3:
        mes = "Marzo";
        break;
    case 4:
        mes = "Abril";
        break;
    case 5:
        mes = "Mayo";
        break;
    case 6:
        mes = "Junio";
        break;
    case 7:
        mes = "Julio";
        break;
    case 8:
        mes = "Agosto";
        break;
    case 9:
        mes = "Septiembre";
        break;
    case 10:
        mes = "Octubre";
        break;
    case 11:
        mes = "Noviembre";
        break;
    case 12:
        mes = "Diciembre";
        break;
    }
//    QString display_time = QString::number(time.date().year())+"/"+QString::number(time.date().month())+"/"+QString::number(time.date().day())+" "+time.time().toString();
    return dia_semana + " " + QString::number(time.date().day()) + " " + mes + " " + QString::number(time.date().year());
}

void MainWindow::on_top_menu_6_clicked()
{
    if(mutex_detailed.tryLock(0))
    {
        if(NULL != motrores_window)
        {
            delete motrores_window;
        }
        motrores_window = new motores(this);

        connect(motrores_window, SIGNAL(release_lock()), this, SLOT(window_closed()));
        motrores_window->show();
    }
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

void MainWindow::on_go_to_filtro_clicked()
{
//    if(mutex_detailed.tryLock(0))
//    {
        if(NULL != filt_window)
        {
            delete filt_window;
        }
        filt_window = new filtrowindow(display_parameters, GetParemeter(),
                                       ui->label_dia->text(), ui->label_hora->text(), ui->label_title->text(),
                                       rutinas,
                                       this);
        connect(filt_window, SIGNAL(forward_param_buttons_state(bool,parameters_t)),this, SLOT (update_buttons_from_filter(bool,parameters_t)));
        connect(filt_window, SIGNAL(forward_prof_pic_clicked()),this, SLOT (on_prof_pic_clicked()));
        connect(filt_window, SIGNAL(forward_bitacora_clicked()),this, SLOT (on_top_menu_2_clicked()));
        connect(filt_window, SIGNAL(forward_control_clicked()),this, SLOT (on_top_menu_6_clicked()));

//        connect(filt_window, SIGNAL(release_lock()), this, SLOT(window_closed()));
        filt_window->show();
//    }

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
