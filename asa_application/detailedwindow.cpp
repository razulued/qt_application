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

    "Amortigua los picos de flujo y carga, de manera que la planta de tratamiento reciba de manera constante un flujo "
    "igual al de diseño y su eficiencia no se vea afectada. Tiene volumen suficiente para poder almacenar el flujo"
    "generado durante las horas pico",

    create_list() << 45 << 48 << 53,

    create_list() << 43 << 40,

    create_list(),
};

detailed_window_elements_t details_2=
{
    "Reactor biológico",

    ":/images/images/detail_reactor_biologico.png",

    "Tratamiento secundario donde se elimina la materia orgánica por procesos de oxidación biológica; es decir, poniendo "
    "en contacto las aguas residuales con una biomasa de microorganismos que la depuran.",

    create_list() << 93 << 96 << 101,

    create_list() << 165,

    create_list() << 90 << 160 << 161 << 163,

};

detailed_window_elements_t details_3=
{
    "Clarificador",
    ":/images/images/detail_clarificador.png",
    "Recibe el afluente del reactor biológico, conformado por agua y lodo biológico. Los lodos biológicos y los sólidos "
    "suspendidos se sedimentan, separandose del agua.",

    create_list(),

    create_list() << 145,

    create_list(),
};

detailed_window_elements_t details_4=
{
    "Clorador",
    ":/images/images/detail_clorador.png",
    "Proceso de desinfección de hipoclorito de sodio/calcio líquido/sólido. Se eliminan los microorganismos presentes.",

    create_list(),

    create_list() << 162,

    create_list(),
};

detailed_window_elements_t details_5=
{
    "Digestor de lodos",
    ":/images/images/detail_digestor.png",
    "Recibe los lodos biológicos generados en exeso y separados en el clarificador secundario; estos se oxidan biológicamente"
    " hasta obtener una reducción de 40 a 60% en los sólidos volátiles presentes, logrando así una estabilización de lodos.",

    create_list(),

    create_list(),

    create_list(),
};

detailed_window_elements_t details_6=
{
    "Deshidratador de lodos",
    ":/images/images/detail_deshidratador.png",
    "Lechos de secado, filtro horizontal de flujo descendiente empacado con gravas y arena. Sobre este se vierte una cantidad de lodo y "
    "se permite su infiltración, dejando secar los lodos",

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
    QFont font_3("Typo Square Ligth Demo",12,1);

    // Nombre Del elemento
    ui->nombre->setFont(font);
//    ui->nombre->setStyleSheet("color: white");
    ui->nombre->setText(detailed_elements[element]->name);

    ui->imagen->setStyleSheet("border-image: url("+detailed_elements[element]->image+");");

    // Nombre del detalle
    ui->label->setFont(font);
    ui->label->setStyleSheet("color: white");

    what_element = element;

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
    ui->description_label->setFont(font_3);
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

    ui->button_parametros->setStyleSheet("background-image: url(:/iconos/images/Iconos/Visualizar_blanco.png);"
                    "border: none;"
                    "background-repeat: none;"
                    "background-position: center;");

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
    ui->button_parametros->setStyleSheet("background-image: url(:/iconos/images/Iconos/Visualizar_blanco.png);"
                    "border: none;"
                    "background-repeat: none;"
                    "background-position: center;");
    ui->button_evento->setStyleSheet("background-image: url(:/iconos/images/Iconos/Bitacora_azul.png);;"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
    ui->button_descripcion->setStyleSheet("background-image: url(:/iconos/images/Iconos/Info_azul.png);"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
    ui->button_visualizacion->setStyleSheet("background-image: url(:/iconos/images/Iconos/Ajustes_azul.png);"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
}

void detailedwindow::on_button_evento_clicked()
{
    ui->label->setText("Evento");
    ui->tabWidget->setCurrentIndex(1);
    ui->button_parametros->setStyleSheet("background-image: url(:/iconos/images/Iconos/Visualizar_azul.png);"
                    "border: none;"
                    "background-repeat: none;"
                    "background-position: center;");
    ui->button_evento->setStyleSheet("background-image: url(:/iconos/images/Iconos/Bitacora_blanco.png);;"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
    ui->button_descripcion->setStyleSheet("background-image: url(:/iconos/images/Iconos/Info_azul.png);"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
    ui->button_visualizacion->setStyleSheet("background-image: url(:/iconos/images/Iconos/Ajustes_azul.png);"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
}

void detailedwindow::on_button_descripcion_clicked()
{
    ui->label->setText("Descripción");
    ui->tabWidget->setCurrentIndex(2);
    ui->button_parametros->setStyleSheet("background-image: url(:/iconos/images/Iconos/Visualizar_azul.png);"
                    "border: none;"
                    "background-repeat: none;"
                    "background-position: center;");
    ui->button_evento->setStyleSheet("background-image: url(:/iconos/images/Iconos/Bitacora_azul.png);;"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
    ui->button_descripcion->setStyleSheet("background-image: url(:/iconos/images/Iconos/Info_blanco.png);"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
    ui->button_visualizacion->setStyleSheet("background-image: url(:/iconos/images/Iconos/Ajustes_azul.png);"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
}

void detailedwindow::on_button_visualizacion_clicked()
{
    ui->label->setText("Visualización de Parámetros");
    ui->tabWidget->setCurrentIndex(3);
    ui->button_parametros->setStyleSheet("background-image: url(:/iconos/images/Iconos/Visualizar_azul.png);"
                    "border: none;"
                    "background-repeat: none;"
                    "background-position: center;");
    ui->button_evento->setStyleSheet("background-image: url(:/iconos/images/Iconos/Bitacora_azul.png);;"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
    ui->button_descripcion->setStyleSheet("background-image: url(:/iconos/images/Iconos/Info_azul.png);"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
    ui->button_visualizacion->setStyleSheet("background-image: url(:/iconos/images/Iconos/Ajustes_blanco.png);"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");

}

void detailedwindow::checkBoxStateChanged(int a)
{
    qDebug() << "Toggle active show " << a;
    toggleParamActiveShow(a);
}

void detailedwindow::update_params()
{
//    quint32 i, param_id;
//    ui->layout_param->setAlignment(Qt::AlignTop);

//    QFont font_2("Typo Square Ligth Demo",14,1);


//    qDebug() << "Number of parameters to display is " << detailed_elements[what_element]->list_elect.size();
//    for(i = 0; i < (quint32)detailed_elements[what_element]->list_elect.size(); i++)
//    {
//        param_id = detailed_elements[what_element]->list_elect[i];

//        QLabel *label = new QLabel(getParamName(param_id) + ": " + getParamValue(param_id));
//        ui->layout_param->update();
//        label->setFont(font_2);
//        ui->layout_param->addWidget(label);

//    }
//    qDebug() << "Number of parameters to display is " << detailed_elements[what_element]->list_phys.size();
//    for(i = 0; i < (quint32)detailed_elements[what_element]->list_phys.size(); i++)
//    {
//        param_id = detailed_elements[what_element]->list_phys[i];

//        QLabel *label = new QLabel(getParamName(param_id) + ": " + getParamValue(param_id));
//        label->setFont(font_2);
//        ui->layout_param->addWidget(label);

//    }
//    qDebug() << "Number of parameters to display is " << detailed_elements[what_element]->list_chem.size();
//    for(i = 0; i < (quint32)detailed_elements[what_element]->list_chem.size(); i++)
//    {
//        param_id = detailed_elements[what_element]->list_chem[i];

//        QLabel *label = new QLabel(getParamName(param_id) + ": " + getParamValue(param_id));
//        label->setFont(font_2);
//        ui->layout_param->addWidget(label);

//    }
}
