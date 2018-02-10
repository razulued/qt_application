#include "detailedwindow.h"
#include "ui_detailedwindow.h"
#include <QListView>
typedef struct
{
    QString name;
    QString image;
}detailed_window_elements_t;

typedef struct
{
    QString name;
}detailed_parameters_t;

detailed_parameters_t details_regulador[]=
{
    "ND",
    "pH",
    "SST",
    "Turbidez",
    "Vp",
    "Ap",
    "F.P"
};


const detailed_window_elements_t detailed_elements[]=
{
    {"Regulador",               ":/images/images/detail_regulador.png"},
    {"Reactor biológico",       ":/images/images/detail_reactor_biologico.png"},
    {"Clarificador",            ":/images/images/detail_clarificador.png"},
    {"Clorador",                ":/images/images/detail_clorador.png"},
    {"Digestor de lodos",       ":/images/images/detail_digestor.png"},
    {"Deshidratador de lodos",  ":/images/images/detail_deshidratador.png"},
};

detailedwindow::detailedwindow(detailed_elements_t element, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailedwindow)
{
    ui->setupUi(this);

    ui->label->setStyleSheet("color: white");
    ui->nombre->setStyleSheet("color: white");
    ui->nombre->setText(detailed_elements[element].name);
//    ui->nombre->setStyleSheet("color: blue; background-color: yellow");
    ui->imagen->setStyleSheet("border-image: url("+detailed_elements[element].image+");");


    //This is a hack to hide tabs from tab widget
    ui->tabWidget->setTabText(0,"");
    ui->tabWidget->setTabText(1,"");
    ui->tabWidget->setTabText(2,"");
    ui->tabWidget->setTabText(3,"");
    ui->tabWidget->setTabText(4,"");
    ui->tab_1->setStyleSheet("background:black");
    ui->tab_2->setStyleSheet("background:black");
    ui->tab_3->setStyleSheet("background:black");
    ui->tab_4->setStyleSheet("background:black");
    ui->tab_5->setStyleSheet("background:black");


    this->setObjectName("DetailedWindow");
    this->setStyleSheet("detailedwindow#DetailedWindow{"
                        "background-color:black;"
                        "border-style: solid;"
                        "border-width: 6px;"
                        "border-radius: 6px;"
                        "border-color: gray;"
                        "}");

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
    this->show();
}

detailedwindow::~detailedwindow()
{
    delete ui;
}

void detailedwindow::on_closeButton_clicked()
{
    this->close();
}

void detailedwindow::on_button_parametros_clicked()
{
    ui->label->setText("Parámetros");
    ui->tabWidget->setCurrentIndex(0);
}

void detailedwindow::on_button_evento_clicked()
{
    ui->label->setText("Evento");
    ui->tabWidget->setCurrentIndex(1);
}

void detailedwindow::on_button_descripcion_clicked()
{
    ui->label->setText("Descripción");
    ui->tabWidget->setCurrentIndex(2);
}

void detailedwindow::on_button_visualizacion_clicked()
{
    ui->label->setText("Visualización de Parámetros");
    ui->tabWidget->setCurrentIndex(3);
}
