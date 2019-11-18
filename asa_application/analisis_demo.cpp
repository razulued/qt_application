#include "analisis_demo.h"
#include "ui_analisis_demo.h"
#include "donut_chart.h"
#include "parameters.h"
#include <QDebug>

#define L1_VoltID   (0x3011)
#define L2_VoltID   (0x3012)
#define L3_VoltID   (0x3013)
#define L1_AmpsID   (0x3014)
#define L2_AmpsID   (0x3015)
#define L3_AmpsID   (0x3016)

#define L1_VALUE    (getParamValue(0x1234))
#define DONUT1_VALUE (getParamValue(0x1234).toFloat())

analisis_demo::analisis_demo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::analisis_demo)
{
    ui->setupUi(this);

    this->move(parent->pos());

    this->setStyleSheet("background-color:rgb(45,43,83);"
                        "color:white"
                        );
    //Hide window bars and buttons
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);

    // Center donut graphs
    ui->frame->move(this->rect().center() - ui->frame->rect().center());
    ui->frame->setStyleSheet("background-color:rgb(45,43,83);"
                             "border: none;");
    //Position aletas
//    ui->aleta1->move(ui->widget->x() - 70, ui->widget->y());

    // DONUTS
    donut_chart *donut_1 = new donut_chart(DONUT1_VALUE, 120, ui->widget);
    connect(this, SIGNAL(update_donut_1(float)), donut_1, SLOT(update_data(float)));

    donut_chart *donut_2 = new donut_chart(DONUT1_VALUE, 120, ui->widget_2);
    connect(this, SIGNAL(update_donut_1(float)), donut_2, SLOT(update_data(float)));

    donut_chart *donut_3 = new donut_chart(DONUT1_VALUE, 120, ui->widget_3);
    connect(this, SIGNAL(update_donut_1(float)), donut_3, SLOT(update_data(float)));

    donut_chart *donut_4 = new donut_chart(DONUT1_VALUE, 120, ui->widget_4);
    connect(this, SIGNAL(update_donut_1(float)), donut_4, SLOT(update_data(float)));

    // ALETAS
    ui->aleta1->hide();
    ui->aleta2->hide();
    ui->aleta3->hide();
    ui->aleta4->hide();

    QList<uint> volt_list;
    volt_list << L1_VoltID << L2_VoltID << L3_VoltID;
    QList<QString> fase_names;
    fase_names << "L1" << "L2" << "L3";
    aleta_1 = new aleta_widget(volt_list, fase_names, ui->aleta3);
    connect(donut_3, SIGNAL(clicked()), aleta_1, SLOT(toogle_hide_show()));

    QList<uint> amp_list;
    amp_list << L1_AmpsID << L2_AmpsID << L3_AmpsID;
    aleta_2 = new aleta_widget(amp_list, fase_names, ui->aleta4);
    connect(donut_4, SIGNAL(clicked()), aleta_2, SLOT(toogle_hide_show()));
}

analisis_demo::~analisis_demo()
{
    delete ui;
}

void analisis_demo::update_data()
{
    update_donut_1(DONUT1_VALUE);

    if(NULL != aleta_1)
    {
        aleta_1->update_data();
    }
    if(NULL != aleta_2)
    {
        aleta_2->update_data();
    }
}

void analisis_demo::on_pushButton_clicked()
{
    this->accept();
}

aleta_widget::aleta_widget(QList<uint> id_list, QList<QString> names, QWidget *parent):
    QWidget(parent)
{
//    parent->setStyleSheet("background-color: transparent;"
//                          "background-image: url(:/demo/images/Demo/Aleta-izq.png);"
//                          "background-repeat: none;"
//                          "background-position: center;"
//                          "border: none;");

    parent_widget = parent;
    layout = new QVBoxLayout(parent);

    list_widget = new QListWidget();
    list_widget->setFocusPolicy(Qt::NoFocus);
    list_widget->clear();
    list_widget->setStyleSheet("background: transparent;"
                               "color: rgb(146,205,186);"
                               "border: none;"
                               "border-image: none;"
                               "font-weight: bold;"
                               "font-size: 17px;");
    QFont font("Liberation Mono Bold",15,1);
    list_widget->setFont(font);

    IDS = id_list;
    NAMES = names;


    for(int i=0; i < IDS.length(); i++)
    {
        list_widget->addItem(NAMES.at(i)+": "+
                             getParamValue_and_units(IDS.at(i)));
        list_widget->item(i)->setTextAlignment(Qt::AlignCenter);
    }
    layout->addWidget(list_widget);
    parent->setLayout(layout);
}

aleta_widget::~aleta_widget()
{
}

void aleta_widget::update_data()
{
    list_widget->clear();
    for(int i=0; i < IDS.length(); i++)
    {
        list_widget->addItem(NAMES.at(i)+": "+
                             getParamValue_and_units(IDS.at(i)));
        list_widget->item(i)->setTextAlignment(Qt::AlignCenter);
    }
    layout->addWidget(list_widget);
}

void aleta_widget::toogle_hide_show()
{
    if(show_aleta == false)
    {
        show_aleta = true;
        parent_widget->show();
    }
    else
    {
        show_aleta = false;
        parent_widget->hide();
    }
}
