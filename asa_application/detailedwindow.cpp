#include "detailedwindow.h"
#include "ui_detailedwindow.h"
#include <QListView>
#include <QFontDatabase>
#include <QCheckBox>
#include <QTableWidget>
#include "parameters.h"
#include <QDebug>
#include "mainwindow.h"

typedef struct
{
    QString name;
}detailed_parameters_t;

QList<int> create_list()
{
    QList<int> list;
    return list;
}

detailed_window_elements_t details_1=
{
    "Regulador",

    ":/images/images/detail_regulador.png",

    "texto 1",

    create_list() << 45 << 48 << 53,

    create_list() << 43 << 40,

    create_list(),
};

detailed_window_elements_t details_2=
{
    "Reactor biológico",

    ":/images/images/detail_reactor_biologico.png",

    "Texto 2",

    create_list() << 93 << 96 << 101,

    create_list() << 165,

    create_list() << 90 << 160 << 161 << 163,

};

detailed_window_elements_t details_3=
{
    "Clarificador",
    ":/images/images/detail_clarificador.png",
    "Texto 3",

    create_list(),

    create_list() << 145,

    create_list(),
};

detailed_window_elements_t details_4=
{
    "Clorador",
    ":/images/images/detail_clorador.png",
    "Texto 4",

    create_list(),

    create_list() << 162,

    create_list(),
};

detailed_window_elements_t details_5=
{
    "Digestor de lodos",
    ":/images/images/detail_digestor.png",
    "Texto 5",

    create_list(),

    create_list(),

    create_list(),
};

detailed_window_elements_t details_6=
{
    "Deshidratador de lodos",
    ":/images/images/detail_deshidratador.png",
    "Texto 6",

    create_list(),

    create_list(),

    create_list(),
};

const detailed_window_elements_t *detailed_elements[]=
{
    &details_1,
    &details_2,
    &details_3,
    &details_4,
    &details_5,
    &details_6,
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
                        "}"
                        "QCheckBox{color:white}"
                        "QCheckBox::indicator:checked{"
                            "border-width: 3px;"
                            "border-style: solid;"
                            "border-color: rgb(0, 167, 250);"
                            "border-radius: 5px;"
                            "width: 20px;"
                            "height: 20px;"
                        "}"
                        "QCheckBox::indicator:unchecked{"
                        "border-width: 3px;"
                        "border-style: solid;"
                        "border-color: gray;"
                        "border-radius: 5px;"
                        "width: 20px;"
                        "height: 20px;"
                         "}"
                        "QLabel{color:white}"
                        );
    // Fonts
    QFont font("Typo Square Italic Demo",20,1);
    QFont font_2("Typo Square Ligth Demo",14,1);

    // Nombre Del elemento
    ui->nombre->setFont(font);
//    ui->nombre->setStyleSheet("color: white");
    ui->nombre->setText(detailed_elements[element]->name);

    ui->imagen->setStyleSheet("border-image: url("+detailed_elements[element]->image+");");

    // Nombre del detalle
    ui->label->setFont(font);
    ui->label->setStyleSheet("color: white");


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

    /**** TAB 0 INIT: Parametros ***/
    //List of parameters

    /**** TAB 1 INIT: Evento ***/
    quint32 i, param_id;
    ui->layout_param->setAlignment(Qt::AlignTop);
    qDebug() << "Number of parameters to display is " << detailed_elements[element]->list_elect.size();
    for(i = 0; i < (quint32)detailed_elements[element]->list_elect.size(); i++)
    {
        param_id = detailed_elements[element]->list_elect[i];
        qDebug() << getParamName(param_id) <<" "<< param_id << " " << getParamValue(param_id);

        QLabel *label = new QLabel(getParamName(param_id) + ": " + getParamValue(param_id));
        label->setFont(font_2);
        ui->layout_param->addWidget(label);

    }
    qDebug() << "Number of parameters to display is " << detailed_elements[element]->list_phys.size();
    for(i = 0; i < (quint32)detailed_elements[element]->list_phys.size(); i++)
    {
        param_id = detailed_elements[element]->list_phys[i];
        qDebug() << getParamName(param_id) <<" "<< param_id << " " << getParamValue(param_id);

        QLabel *label = new QLabel(getParamName(param_id) + ": " + getParamValue(param_id));
        label->setFont(font_2);
        ui->layout_param->addWidget(label);

    }
    qDebug() << "Number of parameters to display is " << detailed_elements[element]->list_chem.size();
    for(i = 0; i < (quint32)detailed_elements[element]->list_chem.size(); i++)
    {
        param_id = detailed_elements[element]->list_chem[i];
        qDebug() << getParamName(param_id) <<" "<< param_id << " " << getParamValue(param_id);

        QLabel *label = new QLabel(getParamName(param_id) + ": " + getParamValue(param_id));
        label->setFont(font_2);
        ui->layout_param->addWidget(label);

    }

//    QLabel *label = new QLabel("hello");
//    label->setFont(font_2);
//    ui->layout_param->addWidget(label);

    /**** TAB 2 INIT: Descripcion ***/
    //Texto
    ui->description_label->setFont(font_2);
    ui->description_label->setText(detailed_elements[element]->description);
    ui->description_label->setStyleSheet("color: white");

    /**** TAB 3 INIT ***/
    QSignalMapper *checkboxMapper = new QSignalMapper(this);

    ui->verticalLayout->setAlignment(Qt::AlignTop);

    QCheckBox *box;

    for(i = 0; i < (quint32)detailed_elements[element]->list_elect.size(); i++)
    {
        param_id = detailed_elements[element]->list_elect[i];

        box = new QCheckBox(getParamName(param_id));
        if(true == getParamActiveShow(param_id))
        {
            box->setChecked(true);
        }
        box->setFont(font_2);
//        box->setLayoutDirection(Qt::RightToLeft);
        ui->verticalLayout->addWidget(box);


        //Connect checkbox to parameter active show
        connect(box, SIGNAL(clicked(bool)), checkboxMapper, SLOT(map()));
        checkboxMapper->setMapping(box, param_id);
    }

    for(i = 0; i < (quint32)detailed_elements[element]->list_phys.size(); i++)
    {
        param_id = detailed_elements[element]->list_phys[i];

        box = new QCheckBox(getParamName(param_id));
        if(true == getParamActiveShow(param_id))
        {
            box->setChecked(true);
        }
        box->setFont(font_2);
//        box->setLayoutDirection(Qt::RightToLeft);
        ui->verticalLayout->addWidget(box);
        //Connect checkbox to parameter active show
        connect(box, SIGNAL(clicked(bool)), checkboxMapper, SLOT(map()));
        checkboxMapper->setMapping(box, param_id);
    }

    for(i = 0; i < (quint32)detailed_elements[element]->list_chem.size(); i++)
    {
        param_id = detailed_elements[element]->list_chem[i];

        box = new QCheckBox(getParamName(param_id));
        if(true == getParamActiveShow(param_id))
        {
            box->setChecked(true);
        }
        box->setFont(font_2);
//        box->setLayoutDirection(Qt::RightToLeft);
        ui->verticalLayout->addWidget(box);
        //Connect checkbox to parameter active show
        connect(box, SIGNAL(clicked(bool)), checkboxMapper, SLOT(map()));
        checkboxMapper->setMapping(box, param_id);
    }

    // Connect all checkboxes to mapper
    connect(checkboxMapper, SIGNAL(mapped(int)), this, SLOT(checkBoxStateChanged(int)));


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

void detailedwindow::checkBoxStateChanged(int a)
{
    qDebug() << "Toggle active show " << a;
    toggleParamActiveShow(a);
}
