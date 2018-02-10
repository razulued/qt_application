#include "detailedwindow.h"
#include "ui_detailedwindow.h"
#include <QListView>
#include <QFontDatabase>

typedef struct
{
    QString name;
    QString image;
    QString description;
}detailed_window_elements_t;

typedef struct
{
    QString name;
}detailed_parameters_t;

detailed_window_elements_t details_1[]=
{
    "Regulador",

    ":/images/images/detail_regulador.png",

    "texto 1",
};

detailed_window_elements_t details_2[]=
{
    "Reactor biológico",

    ":/images/images/detail_reactor_biologico.png",

    "Texto 2",
};

detailed_window_elements_t details_3[]=
{
    "Clarificador",
    ":/images/images/detail_clarificador.png",
    "Texto 3",
};

detailed_window_elements_t details_4[]=
{
    "Clorador",
    ":/images/images/detail_clorador.png",
    "Texto 4",
};

detailed_window_elements_t details_5[]=
{
    "Digestor de lodos",
    ":/images/images/detail_digestor.png",
    "Texto 5"
};

detailed_window_elements_t details_6[]=
{
    "Deshidratador de lodos",
    ":/images/images/detail_deshidratador.png",
    "Texto 6"
};

const detailed_window_elements_t *detailed_elements[]=
{
    details_1,
    details_2,
    details_3,
    details_4,
    details_5,
    details_6,
};

detailedwindow::detailedwindow(detailed_elements_t element, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailedwindow)
{
    ui->setupUi(this);
    this->setObjectName("DetailedWindow");
    this->setStyleSheet("detailedwindow#DetailedWindow{"
                        "background-color:black;"
                        "border-style: solid;"
                        "border-width: 6px;"
                        "border-radius: 6px;"
                        "border-color: gray;"
                        "}");

    QFontDatabase::addApplicationFont(":/fonts/fonts/Typo_Square_Bold Demo.otf");
    QFont font("Typo Square Bold Demo",20,1);
    QFont font_2("Typo Square Bold Demo",14,1);


    // Nombre
    ui->nombre->setFont(font);
    ui->nombre->setStyleSheet("color: white");
    ui->nombre->setText(detailed_elements[element]->name);

    // Nombre del detalle
    ui->label->setFont(font);
    ui->label->setStyleSheet("color: white");


    ui->imagen->setStyleSheet("border-image: url("+detailed_elements[element]->image+");");

    ui->description_label->setFont(font_2);
    ui->description_label->setText(detailed_elements[element]->description);
    ui->description_label->setStyleSheet("color: white");


    //This is a hack to hide tabs from tab widget
    ui->tabWidget->setCurrentIndex(0);
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


    //Hide window bars and buttons
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
