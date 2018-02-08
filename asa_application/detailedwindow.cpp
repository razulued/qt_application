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

    this->setObjectName("DetailedWindow");
    this->setStyleSheet("detailedwindow#DetailedWindow{background-color:rgb(35, 35, 26)}");
    this->show();
}

detailedwindow::~detailedwindow()
{
    delete ui;
}
