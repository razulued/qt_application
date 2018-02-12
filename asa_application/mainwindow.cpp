#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QFontDatabase>
#include "parameters.h"
#include <QList>

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

void MainWindow::updateTooltips()
{
    //TODO make this dynamic later
    int regulador_elec[] = {45, 48, 53};
    int regulador_phys[] = {43, 40};
    int reac_elect[] = {93, 96, 101};
    int reac_phys[] = {165};
    int reac_chem[] = {90, 160, 161, 163};

    int i;
    QFont font("Typo Square Ligth Demo",10,1);

    // Nombre Del elemento
    ui->tip_reg_elec->setFont(font);
    ui->tip_reg_elec->clear();
    ui->tip_reg_elec->setStyleSheet("background: transparent;"
                                  "color: rgb(0, 167, 250);"
                                    "border-color: rgb(0, 167, 250)");
    ui->tip_reg_elec->setFont(font);


    for(i = 0; i < 3; i++)
    {
        if(true == getParamActiveShow(regulador_elec[i]))
        {
            ui->tip_reg_elec->addItem(getParamName(regulador_elec[i]) + ": " + getParamValue(regulador_elec[i]));
        }
    }

    ui->tip_reg_phys->setFont(font);
    ui->tip_reg_phys->clear();
    ui->tip_reg_phys->setStyleSheet("background: transparent;"
                                  "color: rgb(0, 167, 250);");
    ui->tip_reg_phys->setFont(font);
    for(i = 0; i < 2; i++)
    {
        if(true == getParamActiveShow(regulador_phys[i]))
        {
            ui->tip_reg_phys->addItem(getParamName(regulador_phys[i]) + ": " + getParamValue(regulador_phys[i]));
        }
    }

    ui->tip_reac_elec->setFont(font);
    ui->tip_reac_elec->clear();
    ui->tip_reac_elec->setStyleSheet("background: transparent;"
                                  "color: rgb(0, 167, 250);");
    ui->tip_reac_elec->setFont(font);
    for(i = 0; i < 3; i++)
    {
        if(true == getParamActiveShow(reac_elect[i]))
        {
            ui->tip_reac_elec->addItem(getParamName(reac_elect[i]) + ": " + getParamValue(reac_elect[i]));
        }
    }

    ui->tip_reac_phys->setFont(font);
    ui->tip_reac_phys->clear();
    ui->tip_reac_phys->setStyleSheet("background: transparent;"
                                  "color: rgb(0, 167, 250);");
    ui->tip_reac_phys->setFont(font);
    for(i = 0; i < 1; i++)
    {
        if(true == getParamActiveShow(reac_phys[i]))
        {
            ui->tip_reac_phys->addItem(getParamName(reac_phys[i]) + ": " + getParamValue(reac_phys[i]));
        }
    }

    ui->tip_reac_chem->setFont(font);
    ui->tip_reac_chem->clear();
    ui->tip_reac_chem->setStyleSheet("background: transparent;"
                                  "color: rgb(0, 167, 250);");
    ui->tip_reac_chem->setFont(font);
    for(i = 0; i < 4; i++)
    {
        if(true == getParamActiveShow(reac_chem[i]))
        {
            ui->tip_reac_chem->addItem(getParamName(reac_chem[i]) + ": " + getParamValue(reac_chem[i]));
        }
    }


//    quint32 i, param_id;
//    ui->layout_param->setAlignment(Qt::AlignTop);
//    qDebug() << "Number of parameters to display is " << detailed_elements[element]->list_elect.size();
//    for(i = 0; i < (quint32)detailed_elements[element]->list_elect.size(); i++)
//    {
//        param_id = detailed_elements[element]->list_elect[i];
//        qDebug() << getParamName(param_id) <<" "<< param_id << " " << getParamValue(param_id);

//        label = new QLabel(getParamName(param_id) + ": " + getParamValue(param_id));
//        label->setFont(font_2);
//        ui->layout_param->addWidget(label);

//    }
//    qDebug(

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
    updateTooltips();

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
}

void MainWindow::handleParametrosFisicosButton()
{
    SelectParemeter(PARAM_PHYSHIC);
}

void MainWindow::handleParametrosQuimicosButton()
{
    SelectParemeter(PARAM_CHEMIC);
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


void MainWindow::on_asa_logo_clicked()
{
    this->close();
}

void MainWindow::dataTimerSlot()
{
    this->updateTooltips();
}
