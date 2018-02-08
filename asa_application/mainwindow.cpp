#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QFontDatabase>

void MainWindow::InitButtons()
{
    physical_param_button = (MultiStateButton *)ui->pb_fisicos;
    physical_param_button->setParam(PARAM_PHYSHIC);
    physical_param_button->setState(STATE_NORMAL);

    chemical_param_button = (MultiStateButton *)ui->pb_quimicos;
    chemical_param_button->setParam(PARAM_CHEMIC);
    chemical_param_button->setState(STATE_NORMAL);

    electrical_param_button = (MultiStateButton *)ui->pb_electricos;
    electrical_param_button->setParam(PARAM_ELECTRIC);
    electrical_param_button->setState(STATE_PRESSED);

    //Electric Paramenters are show by default
    selected_parameter = E_PARAMETROS_ELECTRICOS;


    //Hide parameters
//    HandleParameterChange(E_PARAMETROS_ELECTRICOS);

    display_parameters = false;
    HideButtons(true);
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

void MainWindow::HandleParameterChange(t_parameters param)
{
    switch(param)
    {
    case E_PARAMETROS_ELECTRICOS:
        physical_param_button->setState(STATE_NORMAL);
        chemical_param_button->setState(STATE_NORMAL);
        electrical_param_button->setState(STATE_PRESSED);
        ui->active_param_label->setText("Parámetros Eléctricos");
        break;
    case E_PARAMETROS_FISICOS:
        physical_param_button->setState(STATE_PRESSED);
        chemical_param_button->setState(STATE_NORMAL);
        electrical_param_button->setState(STATE_NORMAL);
        ui->active_param_label->setText("Parámetros Físicos");
        break;
    case E_PARAMETROS_QUIMICOS:
        physical_param_button->setState(STATE_NORMAL);
        chemical_param_button->setState(STATE_PRESSED);
        electrical_param_button->setState(STATE_NORMAL);
        ui->active_param_label->setText("Parámetros Químicos");
        break;
    }
    selected_parameter = param;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Setup Buttons and link to images
    InitButtons();

    //Set mainwindows buttons properties
    button_main_menu = ui->pushButton;
    connect(button_main_menu, SIGNAL (released()),this, SLOT (handleMenuButton()));
    button_main_menu->show();

    ui->pb_electricos->setChecked(true);
    connect(ui->pb_electricos, SIGNAL (released()),this, SLOT (handleParametrosElectricosButton()));

    ui->pb_fisicos->setChecked(false);
    connect(ui->pb_fisicos, SIGNAL (released()),this, SLOT (handleParametrosFisicosButton()));

    ui->pb_quimicos->setChecked(false);
    connect(ui->pb_quimicos, SIGNAL (released()),this, SLOT (handleParametrosQuimicosButton()));

    //Connect slot to signal
    detail_window = NULL;
    connect(ui->modulo_1, SIGNAL (released()),this, SLOT (handleDetailedView_1()));
    connect(ui->modulo_2, SIGNAL (released()),this, SLOT (handleDetailedView_2()));
    connect(ui->modulo_3, SIGNAL (released()),this, SLOT (handleDetailedView_3()));
    connect(ui->modulo_4, SIGNAL (released()),this, SLOT (handleDetailedView_4()));
    connect(ui->modulo_5, SIGNAL (released()),this, SLOT (handleDetailedView_5()));
    connect(ui->modulo_6, SIGNAL (released()),this, SLOT (handleDetailedView_6()));


    QFontDatabase::addApplicationFont(":/fonts/fonts/Typo_Square_Bold Demo.otf");
    QFont active_parameter_font("Typo Square Bold Demo",20,1);
    ui->active_param_label->setStyleSheet("color:black");
    ui->active_param_label->setFont(active_parameter_font);



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
    HandleParameterChange(E_PARAMETROS_ELECTRICOS);
}

void MainWindow::handleParametrosFisicosButton()
{
    HandleParameterChange(E_PARAMETROS_FISICOS);
}

void MainWindow::handleParametrosQuimicosButton()
{
    HandleParameterChange(E_PARAMETROS_QUIMICOS);
}

void MainWindow::handleDetailedView_1()
{
    if (detail_window != NULL) {
        delete detail_window;
    }
    detail_window = new detailedwindow(ELEMENT_REGULADOR);
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

