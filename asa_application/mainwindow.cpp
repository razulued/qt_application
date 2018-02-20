#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QFontDatabase>
#include "parameters.h"
#include <QList>
#include "custom_tooltip.h"

custom_tooltip *tool_tip_regulador_electricos;
custom_tooltip *tool_tip_regulador_fisicos;

custom_tooltip *tool_tip_reactor_electricos;
custom_tooltip *tool_tip_reactor_fisicos;
custom_tooltip *tool_tip_reactor_quimicos;

custom_tooltip *tool_tip_clarificador_fisicos;

custom_tooltip *tool_tip_clorador_fisicos;

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
    tool_tip_regulador_electricos = new custom_tooltip(ui->widget, custom_tooltip::create_list() << 45 << 48 << 53);
    tool_tip_regulador_fisicos = new custom_tooltip(ui->widget_2, custom_tooltip::create_list() << 43 << 40);

    tool_tip_reactor_electricos = new custom_tooltip(ui->widget_3, custom_tooltip::create_list() << 93 << 96 << 101);
    tool_tip_reactor_fisicos = new custom_tooltip(ui->widget_4, custom_tooltip::create_list() << 165);
    tool_tip_reactor_quimicos = new custom_tooltip(ui->widget_5, custom_tooltip::create_list() << 90 << 160 << 161 << 163);

    tool_tip_clarificador_fisicos = new custom_tooltip(ui->widget_6, custom_tooltip::create_list() << 145);

    tool_tip_clorador_fisicos = new custom_tooltip(ui->widget_7, custom_tooltip::create_list() << 162);


}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    InitRandomParameters();
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
    QPushButton *button = new QPushButton(this);
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
    static int a = 0;
    if(a++ > 10)
    {
        InitRandomParameters();
        a = 0;
    }

    if(true == display_parameters)
    {
        switch(GetParemeter())
        {
        case PARAM_ELECTRIC:
            tool_tip_regulador_electricos->force_show();
            tool_tip_reactor_electricos->force_show();

            tool_tip_regulador_fisicos->force_hide();
            tool_tip_reactor_fisicos->force_hide();
            tool_tip_clarificador_fisicos->force_hide();
            tool_tip_clorador_fisicos->force_hide();

            tool_tip_reactor_quimicos->force_hide();

            break;
        case PARAM_PHYSHIC:
            tool_tip_regulador_fisicos->force_show();
            tool_tip_reactor_fisicos->force_show();
            tool_tip_clarificador_fisicos->force_show();
            tool_tip_clorador_fisicos->force_show();

            tool_tip_regulador_electricos->force_hide();
            tool_tip_reactor_electricos->force_hide();

            tool_tip_reactor_quimicos->force_hide();
            break;
        case PARAM_CHEMIC:
            tool_tip_reactor_quimicos->force_show();

            tool_tip_regulador_electricos->force_hide();
            tool_tip_reactor_electricos->force_hide();

            tool_tip_regulador_fisicos->force_hide();
            tool_tip_reactor_fisicos->force_hide();
            tool_tip_clarificador_fisicos->force_hide();
            tool_tip_clorador_fisicos->force_hide();
            break;
        }
    }
    else
    {
        tool_tip_reactor_quimicos->update_data();

        tool_tip_regulador_electricos->update_data();
        tool_tip_reactor_electricos->update_data();

        tool_tip_regulador_fisicos->update_data();
        tool_tip_reactor_fisicos->update_data();
        tool_tip_clarificador_fisicos->update_data();
        tool_tip_clorador_fisicos->update_data();
    }
    if(detail_window != NULL)
    {
//        detail_window->update_params();
    }
}
