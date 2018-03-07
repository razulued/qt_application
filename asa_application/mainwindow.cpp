#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QFontDatabase>
#include "parameters.h"
#include <QList>
#include <QPainter>
#include <QColor>

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

configuration_id MainWindow::reg_outputs;
configuration_id MainWindow::react_outputs;
configuration_id MainWindow::clarif_outputs;
configuration_id MainWindow::clora_outputs;
configuration_id MainWindow::digest_outputs;
configuration_id MainWindow::deshid_outputs;

int MainWindow::reg_op_mode;
int MainWindow::reg_mot_1;
int MainWindow::reg_mot_2;

QString MainWindow::ASA_conf_string;
QString MainWindow::ASA_conf_only_string;

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

    tool_tip_regulador_electricos = new custom_tooltip(ui->widget, conf_reg_elect.ids, conf_reg_elect.names, reg_outputs.ids, reg_outputs.names, this, ui->modulo_1);
    tool_tip_regulador_fisicos = new custom_tooltip(ui->widget_2, conf_reg_fisic.ids, conf_reg_fisic.names, reg_outputs.ids, reg_outputs.names, this, ui->modulo_1);
    tool_tip_regulador_quimicos = new custom_tooltip(ui->widget_3, conf_reg_quimic.ids, conf_reg_quimic.names, reg_outputs.ids, reg_outputs.names, this, ui->modulo_1);

    tool_tip_reactor_electricos = new custom_tooltip(ui->widget_4, conf_react_elect.ids, conf_react_elect.names, react_outputs.ids, react_outputs.names, this, ui->modulo_2);
    tool_tip_reactor_fisicos = new custom_tooltip(ui->widget_5, conf_react_fisic.ids, conf_react_fisic.names, react_outputs.ids, react_outputs.names, this, ui->modulo_2);
    tool_tip_reactor_quimicos = new custom_tooltip(ui->widget_6, conf_react_quimi.ids, conf_react_quimi.names, react_outputs.ids, react_outputs.names, this, ui->modulo_2);

    tool_tip_clarificador_electricos = new custom_tooltip(ui->widget_7, conf_clarif_elect.ids, conf_clarif_elect.names, clarif_outputs.ids, clarif_outputs.names, this, ui->modulo_3);
    tool_tip_clarificador_fisicos = new custom_tooltip(ui->widget_8, conf_clarif_fisic.ids, conf_clarif_fisic.names, clarif_outputs.ids, clarif_outputs.names, this, ui->modulo_3);
    tool_tip_clarificador_quimicos = new custom_tooltip(ui->widget_9, conf_clarif_quimi.ids, conf_clarif_quimi.names, clarif_outputs.ids, clarif_outputs.names, this, ui->modulo_3);

    tool_tip_clorador_electricos = new custom_tooltip(ui->widget_10, conf_clora_elect.ids, conf_clora_elect.names, clora_outputs.ids, clora_outputs.names, this, ui->modulo_4);
    tool_tip_clorador_fisicos = new custom_tooltip(ui->widget_11, conf_clora_fisic.ids, conf_clora_fisic.names, clora_outputs.ids, clora_outputs.names, this, ui->modulo_4);
    tool_tip_clorador_quimicos = new custom_tooltip(ui->widget_12, conf_clora_quimi.ids, conf_clora_quimi.names, clora_outputs.ids, clora_outputs.names, this, ui->modulo_4);

    init_complete = true;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    settingswindow = NULL;

    //Get config
    get_ASA_string();

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

    //Get outputs
    config = new configuration("Regulador-Out");
    reg_outputs = config->get_config();
    config = new configuration("Reactor-Out");
    react_outputs = config->get_config();
    config = new configuration("Clarificador-Out");
    clarif_outputs = config->get_config();
    config = new configuration("Clorador-Out");
    clora_outputs = config->get_config();

    //Setup Timer
    dataTimer.setInterval(200);
    connect(&dataTimer, SIGNAL(timeout()),this,SLOT(dataTimerSlot()));
    dataTimer.start();

    //Add fonts
    QFontDatabase::addApplicationFont(":/fonts/fonts/Typo_Square_Bold Demo.otf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/Typo_Square_Ligth Demo.otf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/Typo_Square_Italic Demo.otf");

    //Setup Buttons and link to images
    InitButtons(ui->pb_electricos, ui->pb_fisicos, ui->pb_quimicos);
    display_parameters = false;
    HideButtons(true);
//    InitRandomParameters();

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

    QFont active_parameter_font("Typo Square Bold Demo",20,1);
    ui->active_param_label->setFont(active_parameter_font);

    ui->active_param_label->setStyleSheet("color:black");
    ui->active_param_label->setText("Parametros Eléctricos");



//    button.setStyleSheet( FormStyleSheetString( "button" ) );
//     button.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
//     button.setIconSize(QSize(200,200));
//     button.show();
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
    detail_window = new detailedwindow(ELEMENT_REGULADOR, this);
}
void MainWindow::handleDetailedView_2()
{
    if (detail_window != NULL) {
        delete detail_window;
    }
    detail_window = new detailedwindow(ELEMENT_REACTOR);
}
void MainWindow::handleDetailedView_3()
{
    if (detail_window != NULL) {
        delete detail_window;
    }
    detail_window = new detailedwindow(ELEMENT_CLARIFICADOR);
}
void MainWindow::handleDetailedView_4()
{
    if (detail_window != NULL) {
        delete detail_window;
    }
    detail_window = new detailedwindow(ELEMENT_CLORADOR);
}
void MainWindow::handleDetailedView_5()
{
    if (detail_window != NULL) {
        delete detail_window;
    }
    detail_window = new detailedwindow(ELEMENT_DIGESTOR);
}
void MainWindow::handleDetailedView_6()
{
    if (detail_window != NULL) {
        delete detail_window;
    }
    detail_window = new detailedwindow(ELEMENT_DESHIDRATADOR);
}


void MainWindow::on_asa_logo_clicked()
{
    this->close();
}

void MainWindow::dataTimerSlot()
{
//    static int a = 0;
//    if(a++ > 10)
//    {
//        InitRandomParameters();
//        a = 0;
//    }

    update_ASA_string();

    if(true == display_parameters)
    {
        switch(GetParemeter())
        {
        case PARAM_ELECTRIC:
            tool_tip_regulador_electricos->force_show();
            tool_tip_reactor_electricos->force_show();
            tool_tip_clarificador_electricos->force_show();
            tool_tip_clorador_electricos->force_show();

            tool_tip_regulador_fisicos->force_hide();
            tool_tip_reactor_fisicos->force_hide();
            tool_tip_clarificador_fisicos->force_hide();
            tool_tip_clorador_fisicos->force_hide();

            tool_tip_regulador_quimicos->force_hide();
            tool_tip_reactor_quimicos->force_hide();
            tool_tip_clarificador_quimicos->force_hide();
            tool_tip_clorador_quimicos->force_hide();

            break;
        case PARAM_PHYSHIC:
            tool_tip_regulador_electricos->force_hide();
            tool_tip_reactor_electricos->force_hide();
            tool_tip_clarificador_electricos->force_hide();
            tool_tip_clorador_electricos->force_hide();

            tool_tip_regulador_fisicos->force_show();
            tool_tip_reactor_fisicos->force_show();
            tool_tip_clarificador_fisicos->force_show();
            tool_tip_clorador_fisicos->force_show();

            tool_tip_regulador_quimicos->force_hide();
            tool_tip_reactor_quimicos->force_hide();
            tool_tip_clarificador_quimicos->force_hide();
            tool_tip_clorador_quimicos->force_hide();
            break;
        case PARAM_CHEMIC:
            tool_tip_regulador_electricos->force_hide();
            tool_tip_reactor_electricos->force_hide();
            tool_tip_clarificador_electricos->force_hide();
            tool_tip_clorador_electricos->force_hide();

            tool_tip_regulador_fisicos->force_hide();
            tool_tip_reactor_fisicos->force_hide();
            tool_tip_clarificador_fisicos->force_hide();
            tool_tip_clorador_fisicos->force_hide();

            tool_tip_regulador_quimicos->force_show();
            tool_tip_reactor_quimicos->force_show();
            tool_tip_clarificador_quimicos->force_show();
            tool_tip_clorador_quimicos->force_show();
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

            tool_tip_regulador_fisicos->update_data();
            tool_tip_reactor_fisicos->update_data();
            tool_tip_clarificador_fisicos->update_data();
            tool_tip_clorador_fisicos->update_data();

            tool_tip_regulador_quimicos->update_data();
            tool_tip_reactor_quimicos->update_data();
            tool_tip_clarificador_quimicos->update_data();
            tool_tip_clorador_quimicos->update_data();
        }

    }
}

void MainWindow::on_top_menu_4_clicked()
{
    if(settingswindow != NULL)
    {
        delete settingswindow;
    }

    settingswindow = new settings(this);

}

void MainWindow::get_ASA_string()
{
    QString config_data;

    config_data += "200:";
    config_data += QString("%1").arg(load_ASA_conf("out","cfg_out_rel_1_MSB"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("out","cfg_out_rel_1_LSB"),2,16, QChar('0'));
    config_data += "|";
    config_data += "201:";
    config_data += QString("%1").arg(load_ASA_conf("out","cfg_out_rel_2_MSB"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("out","cfg_out_rel_2_LSB"),2,16, QChar('0'));
    config_data += "|";
    config_data += "202:";
    config_data += QString("%1").arg(load_ASA_conf("out","cfg_out_rel_3_MSB"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("out","cfg_out_rel_3_LSB"),2,16, QChar('0'));
    config_data += "|";
    config_data += "203:";
    config_data += QString("%1").arg(load_ASA_conf("out","cfg_out_rel_4_MSB"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("out","cfg_out_rel_4_LSB"),2,16, QChar('0'));

    config_data += "|";
    config_data += "210:";
    config_data += QString("%1").arg(load_ASA_conf("out","cfg_out_led_1_MSB"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("out","cfg_out_led_1_LSB"),2,16, QChar('0'));
    config_data += "|";
    config_data += "211:";
    config_data += QString("%1").arg(load_ASA_conf("out","cfg_out_led_2_MSB"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("out","cfg_out_led_2_LSB"),2,16, QChar('0'));
    config_data += "|";
    config_data += "212:";
    config_data += QString("%1").arg(load_ASA_conf("out","cfg_out_led_3_MSB"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("out","cfg_out_led_3_LSB"),2,16, QChar('0'));
    config_data += "|";
    config_data += "213:";
    config_data += QString("%1").arg(load_ASA_conf("out","cfg_out_led_4_MSB"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("out","cfg_out_led_4_LSB"),2,16, QChar('0'));


    config_data += "|";
    config_data += "220:";
    config_data += QString("%1").arg(load_ASA_conf("in","cfg_ana_1_MSB"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("in","cfg_ana_1_LSB"),2,16, QChar('0'));
    config_data += "|";
    config_data += "221:";
    config_data += QString("%1").arg(load_ASA_conf("in","cfg_ana_2_MSB"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("in","cfg_ana_2_LSB"),2,16, QChar('0'));
    config_data += "|";
    config_data += "222:";
    config_data += QString("%1").arg(load_ASA_conf("in","cfg_ana_3_MSB"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("in","cfg_ana_3_LSB"),2,16, QChar('0'));
    config_data += "|";
    config_data += "223:";
    config_data += QString("%1").arg(load_ASA_conf("in","cfg_ana_4_MSB"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("in","cfg_ana_4_LSB"),2,16, QChar('0'));
    config_data += "|";
    config_data += "224:";
    config_data += QString("%1").arg(load_ASA_conf("in","cfg_ana_5_MSB"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("in","cfg_ana_5_LSB"),2,16, QChar('0'));
    config_data += "|";
    config_data += "225:";
    config_data += QString("%1").arg(load_ASA_conf("in","cfg_ana_6_MSB"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("in","cfg_ana_6_LSB"),2,16, QChar('0'));
    config_data += "|";
    config_data += "226:";
    config_data += QString("%1").arg(load_ASA_conf("in","cfg_ana_7_MSB"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("in","cfg_ana_7_LSB"),2,16, QChar('0'));
    config_data += "|";
    config_data += "227:";
    config_data += QString("%1").arg(load_ASA_conf("in","cfg_ana_8_MSB"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("in","cfg_ana_8_LSB"),2,16, QChar('0'));
    config_data += "|";
    config_data += "228:";
    config_data += QString("%1").arg(load_ASA_conf("in","cfg_ana_9_MSB"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("in","cfg_ana_9_LSB"),2,16, QChar('0'));


    config_data += "|";
    config_data += "240:";
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_MSB_0"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_LSB_0"),2,16, QChar('0'));
    config_data += "|";
    config_data += "241:";
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_MSB_1"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_LSB_1"),2,16, QChar('0'));
    config_data += "|";
    config_data += "242:";
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_MSB_2"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_LSB_2"),2,16, QChar('0'));
    config_data += "|";
    config_data += "243:";
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_MSB_3"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_LSB_3"),2,16, QChar('0'));
    config_data += "|";
    config_data += "244:";
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_MSB_4"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_LSB_4"),2,16, QChar('0'));
    config_data += "|";
    config_data += "245:";
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_MSB_5"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_LSB_5"),2,16, QChar('0'));
    config_data += "|";
    config_data += "246:";
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_MSB_6"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_LSB_6"),2,16, QChar('0'));
    config_data += "|";
    config_data += "247:";
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_MSB_7"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_LSB_7"),2,16, QChar('0'));
    config_data += "|";
    config_data += "248:";
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_MSB_8"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_LSB_8"),2,16, QChar('0'));
    config_data += "|";
    config_data += "249:";
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_MSB_9"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_LSB_9"),2,16, QChar('0'));
    config_data += "|";
    config_data += "250:";
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_MSB_10"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_LSB_10"),2,16, QChar('0'));
    config_data += "|";
    config_data += "251:";
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_MSB_11"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_LSB_11"),2,16, QChar('0'));
    config_data += "|";
    config_data += "252:";
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_MSB_12"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_LSB_12"),2,16, QChar('0'));
    config_data += "|";
    config_data += "253:";
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_MSB_13"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_LSB_13"),2,16, QChar('0'));
    config_data += "|";
    config_data += "254:";
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_MSB_14"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_LSB_14"),2,16, QChar('0'));
    config_data += "|";
    config_data += "255:";
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_MSB_15"),2,16, QChar('0'));
    config_data += QString("%1").arg(load_ASA_conf("modbus1","cfg_modbus_LSB_15"),2,16, QChar('0'));

    config_data += "|";
    config_data += "260:";
    config_data += QString("%1").arg(load_ASA_conf("modbus2","cfg_modbus_2_byte_addr_0_ch_0"),2,16, QChar('0'));
    config_data += "|";
    config_data += "261:";
    config_data += QString("%1").arg(load_ASA_conf("modbus2","cfg_modbus_2_byte_addr_0_ch_1"),2,16, QChar('0'));
    config_data += "|";
    config_data += "262:";
    config_data += QString("%1").arg(load_ASA_conf("modbus2","cfg_modbus_2_byte_addr_0_ch_2"),2,16, QChar('0'));
    config_data += "|";
    config_data += "263:";
    config_data += QString("%1").arg(load_ASA_conf("modbus2","cfg_modbus_2_byte_addr_0_ch_3"),2,16, QChar('0'));
    config_data += "|";
    config_data += "264:";
    config_data += QString("%1").arg(load_ASA_conf("modbus2","cfg_modbus_2_byte_addr_1_ch_0"),2,16, QChar('0'));
    config_data += "|";
    config_data += "265:";
    config_data += QString("%1").arg(load_ASA_conf("modbus2","cfg_modbus_2_byte_addr_1_ch_1"),2,16, QChar('0'));
    config_data += "|";
    config_data += "266:";
    config_data += QString("%1").arg(load_ASA_conf("modbus2","cfg_modbus_2_byte_addr_1_ch_2"),2,16, QChar('0'));
    config_data += "|";
    config_data += "267:";
    config_data += QString("%1").arg(load_ASA_conf("modbus2","cfg_modbus_2_byte_addr_1_ch_3"),2,16, QChar('0'));

    MainWindow::ASA_conf_only_string = config_data;
    qDebug() << ASA_conf_only_string;

}

void MainWindow::update_ASA_string(void)
{
    QString out_data;

    out_data += "|";
    out_data += "80:";
    out_data += QString("%1").arg(reg_op_mode,2,16, QChar('0'));
    out_data += "|";
    out_data += "81:";
    out_data += QString("%1").arg(reg_mot_1,2,16, QChar('0'));
    out_data += "|";
    out_data += "82:";
    out_data += QString("%1").arg(reg_mot_2,2,16, QChar('0'));

    ASA_conf_string = ASA_conf_only_string + out_data;
//    qDebug() << ASA_conf_string;
}

void MainWindow::trace_lines(QWidget * tooltip, QPushButton *module, QPainter &painter)
{
    if(false == tooltip->isHidden())
    {
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
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
     QPainter painter(this);

     QColor line_color;
     line_color.setRgb(0, 167, 250,150);

     QPen pen;
     pen.setColor(line_color);
     pen.setCapStyle(Qt::RoundCap);
     pen.setWidth(3);
     painter.setPen(pen);

     this->update();
     trace_lines(ui->widget, ui->modulo_1, painter);
     trace_lines(ui->widget_2, ui->modulo_1, painter);
     trace_lines(ui->widget_3, ui->modulo_1, painter);

     trace_lines(ui->widget_4, ui->modulo_2, painter);
     trace_lines(ui->widget_5, ui->modulo_2, painter);
     trace_lines(ui->widget_6, ui->modulo_2, painter);

     trace_lines(ui->widget_7, ui->modulo_3, painter);
     trace_lines(ui->widget_8, ui->modulo_3, painter);
     trace_lines(ui->widget_9, ui->modulo_3, painter);

     trace_lines(ui->widget_10, ui->modulo_4, painter);
     trace_lines(ui->widget_11, ui->modulo_4, painter);
     trace_lines(ui->widget_12, ui->modulo_4, painter);

}
