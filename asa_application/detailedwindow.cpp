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

    &MainWindow::conf_reg_elect,

    &MainWindow::conf_reg_fisic,

    &MainWindow::conf_reg_quimic,

    &MainWindow::reg_outputs,
};

detailed_window_elements_t details_2=
{
    "Reactor biológico",

    ":/images/images/detail_reactor_biologico.png",

    "Tratamiento secundario donde se elimina la materia orgánica por procesos de oxidación biológica; es decir, poniendo "
    "en contacto las aguas residuales con una biomasa de microorganismos que la depuran.",

    &MainWindow::conf_react_elect,

    &MainWindow::conf_react_fisic,

    &MainWindow::conf_react_quimi,

    &MainWindow::react_outputs,
};

detailed_window_elements_t details_3=
{
    "Clarificador",
    ":/images/images/detail_clarificador.png",
    "Recibe el afluente del reactor biológico, conformado por agua y lodo biológico. Los lodos biológicos y los sólidos "
    "suspendidos se sedimentan, separandose del agua.",

    &MainWindow::conf_clarif_elect,

    &MainWindow::conf_clarif_fisic,

    &MainWindow::conf_clarif_quimi,

    &MainWindow::clarif_outputs,
};

detailed_window_elements_t details_4=
{
    "Clorador",
    ":/images/images/detail_clorador.png",
    "Proceso de desinfección de hipoclorito de sodio/calcio líquido/sólido. Se eliminan los microorganismos presentes.",

    &MainWindow::conf_clora_elect,

    &MainWindow::conf_clora_fisic,

    &MainWindow::conf_clora_quimi,

    &MainWindow::clora_outputs,
};

detailed_window_elements_t details_5=
{
    "Digestor de lodos",
    ":/images/images/detail_digestor.png",
    "Recibe los lodos biológicos generados en exeso y separados en el clarificador secundario; estos se oxidan biológicamente"
    " hasta obtener una reducción de 40 a 60% en los sólidos volátiles presentes, logrando así una estabilización de lodos.",

    &MainWindow::conf_digest_elect,

    &MainWindow::conf_digest_fisic,

    &MainWindow::conf_digest_quimi,

    &MainWindow::digest_outputs,
};

detailed_window_elements_t details_6=
{
    "Deshidratador de lodos",
    ":/images/images/detail_deshidratador.png",
    "Lechos de secado, filtro horizontal de flujo descendiente empacado con gravas y arena. Sobre este se vierte una cantidad de lodo y "
    "se permite su infiltración, dejando secar los lodos",

    &MainWindow::conf_deshid_elect,

    &MainWindow::conf_deshid_fisic,

    &MainWindow::conf_deshid_quimi,

    &MainWindow::deshid_outputs,
};

detailed_window_elements_t details_7=
{
    "Afluente",
    ":/images/images/afluente.png",
    "Agua residual sanitaria",

    &MainWindow::conf_afluente_elect,

    &MainWindow::conf_afluente_fisic,

    &MainWindow::conf_afluente_quimi,

    &MainWindow::afluente_outputs,
};

detailed_window_elements_t details_8=
{
    "Efluente",
    ":/images/images/efluente.png",
    "Agua tratada",

    &MainWindow::conf_efluente_elect,

    &MainWindow::conf_efluente_fisic,

    &MainWindow::conf_efluente_quimi,

    &MainWindow::efluente_outputs,
};


const detailed_window_elements_t *detailed_elements[]=
{
    &details_1,
    &details_2,
    &details_3,
    &details_4,
    &details_5,
    &details_6,
    &details_7,
    &details_8,
};

detailedwindow::detailedwindow(detailed_elements_t element, rutinas_mantenimiento *rutina, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailedwindow)
{
    ui->setupUi(this);

    rutinas_ptr = rutina;

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
                            "image: url(:/iconos/images/Iconos/Punto_contrasena.png);"
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
    QFont font_4("Typo Square Bold Demo",16,1);


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


    //TODO THIS IS TEMPORAL
    if(detailed_elements[element]->out_config->ids.size() == 0)
    {
        ui->button_control->setStyleSheet("background-image: none;"
                        "border: none;"
                        "background-repeat: none;"
                        "background-position: center;");
    }

    /**** TAB 0 INIT: Parametros ***/
    //List of parameters

    quint32 i, param_id;
    ui->layout_param->setAlignment(Qt::AlignTop);
    qDebug() << "Number of parameters to display is " << detailed_elements[element]->list_elect->ids.size();
    for(i = 0; i < (quint32)detailed_elements[element]->list_elect->ids.size(); i++)
    {
        param_id = detailed_elements[element]->list_elect->ids.at(i);
//        qDebug() << getParamName(param_id) <<" "<< param_id << " " << getParamValue(param_id);

        QLabel *label = new QLabel(detailed_elements[element]->list_elect->names.at(i) + ": " + getParamValue(param_id));
        label->setFont(font_2);
        ui->layout_param->addWidget(label);

    }
    qDebug() << "Number of parameters to display is " << detailed_elements[element]->list_phys->ids.size();
    for(i = 0; i < (quint32)detailed_elements[element]->list_phys->ids.size(); i++)
    {
        param_id = detailed_elements[element]->list_phys->ids.at(i);
//        qDebug() << getParamName(param_id) <<" "<< param_id << " " << getParamValue(param_id);

        QLabel *label = new QLabel(detailed_elements[element]->list_phys->names.at(i) + ": " + getParamValue(param_id));
        label->setFont(font_2);
        ui->layout_param->addWidget(label);

    }
    qDebug() << "Number of parameters to display is " << detailed_elements[element]->list_chem->ids.size();
    for(i = 0; i < (quint32)detailed_elements[element]->list_chem->ids.size(); i++)
    {
        param_id = detailed_elements[element]->list_chem->ids.at(i);
//        qDebug() << getParamName(param_id) <<" "<< param_id << " " << getParamValue(param_id);

        QLabel *label = new QLabel(detailed_elements[element]->list_chem->names.at(i) + ": " + getParamValue(param_id));
        label->setFont(font_2);
        ui->layout_param->addWidget(label);

    }

    /**** TAB 1 INIT: Evento ***/
//    ui->textEdit->setStyleSheet("color: white;"
//                                "border: 1px solid white;");
    ui->label_horas->setFont(font_4);
    ui->label_horas->setAlignment(Qt::AlignRight);


    connect(ui->tableWidget, SIGNAL(itemPressed(QTableWidgetItem*)), this, SLOT(item_selected(QTableWidgetItem*)));

    uint origentype;
    switch(what_element)
    {
    case ELEMENT_REGULADOR:
        origentype = ORIGEN_REGULADOR;
        break;
    case ELEMENT_REACTOR:
        origentype = ORIGEN_REACTOR;
        break;
    case ELEMENT_CLARIFICADOR:
        origentype = ORIGEN_CLARIFICADOR;
        break;
    case ELEMENT_CLORADOR:
        origentype = ORIGEN_CLORADOR;
        break;
        break;
    case ELEMENT_DIGESTOR:
        origentype = ORIGEN_DIGESTOR;
        break;
    case ELEMENT_DESHIDRATADOR:
        origentype = ORIGEN_SECADO;
        break;
    case ELEMENT_AFLUENTE:
        origentype = ORIGEN_AFLUENTE;
        break;
    case ELEMENT_EFLUENTE:
        origentype = ORIGEN_EFLUENTE;
        break;
    default:
        origentype = ORIGEN_GENERAL;
        break;
    }

    uint fila = 0;
    for(i = 0; i < rutinas_ptr->num_of_rutinas ; i++)
    {
        if((origentype == rutinas_ptr->origen(i)) && (0 == rutinas_ptr->ready(i)))
        {
            fila++;
        }
    }


    if(fila > 0)
    {
        QStringList titulos;
        titulos << "ID" << "Rutina"; // Fecha is next

        QFont font1("Typo Square Regular Demo",10,1);
        QFont font2("Typo Square Regular Demo",8,1);

    //    ui->key_OK->setStyleSheet("border: 2px solid rgb(0, 167, 250); color: white");
    //    ui->key_Reschedule->setStyleSheet("border: 2px solid rgb(0, 167, 250); color: white");


        ui->tableWidget->setStyleSheet("color: white;"
                                       "background-color: black;"
                                       "gridline-color: rgb(0, 167, 250);");
        ui->tableWidget->horizontalHeader()->setFont(font1);
        ui->tableWidget->horizontalHeader()->setStyleSheet("border-style: none;"
                                                           "border-bottom: 1px solid #00a7fa;"
                                                           "border-top: 1px solid #00a7fa;"
                                                           "border-left: 1px solid #00a7fa;"
                                                           "border-right: 1px solid #00a7fa;"
                                                           "QHeaderView::section:vertical{"
                                                           "border-left: 1px solid #00a7fa;"
                                                           "}"
                                                           "QHeaderView::section:horizontal{"
                                                           "border-top: 1px solid #00a7fa;"
                                                           "}");
        ui->tableWidget->verticalHeader()->setVisible(false);

        ui->tableWidget->setFont(font2);
        ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
        ui->tableWidget->setWordWrap(true);


        ui->tableWidget->setColumnCount(titulos.size());
        ui->tableWidget->setHorizontalHeaderLabels(titulos);

        fila = 0;
        for(i = 0; i < rutinas_ptr->num_of_rutinas ; i++)
        {
            if((origentype == rutinas_ptr->origen(i)) && (0 == rutinas_ptr->ready(i)))
            {
                // Si la rutina pertenece a este elemento agregar a la tabla
                ui->tableWidget->insertRow(fila);

                ui->tableWidget->setItem(fila,0, new QTableWidgetItem(QString::number(rutinas_ptr->id(i))));

                ui->tableWidget->setItem(fila,1, new QTableWidgetItem(rutinas_ptr->nombre(i)));

                fila++;
            }
        }

        ui->tableWidget->setColumnWidth(0, 30);
    }



    /**** TAB 2 INIT: Descripcion ***/
    //Texto
    ui->description_label->setFont(font_3);
    ui->description_label->setText(detailed_elements[element]->description);
    ui->description_label->setStyleSheet("color: white");
    qDebug() << "END 2";

    /**** TAB 3 INIT ***/
    qDebug() << "INIT 3";
    QSignalMapper *checkboxMapper = new QSignalMapper(this);

    ui->verticalLayout->setAlignment(Qt::AlignTop);

    QCheckBox *box;

    for(i = 0; i < (quint32)detailed_elements[element]->list_elect->ids.size(); i++)
    {
        param_id = detailed_elements[element]->list_elect->ids.at(i);

        box = new QCheckBox(detailed_elements[element]->list_elect->names.at(i));
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

    for(i = 0; i < (quint32)detailed_elements[element]->list_phys->ids.size(); i++)
    {
        param_id = detailed_elements[element]->list_phys->ids.at(i);

        box = new QCheckBox(detailed_elements[element]->list_phys->names.at(i));
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

    for(i = 0; i < (quint32)detailed_elements[element]->list_chem->ids.size(); i++)
    {
        param_id = detailed_elements[element]->list_chem->ids.at(i);

        box = new QCheckBox(detailed_elements[element]->list_chem->names.at(i));
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

    //TAB 5
    QCheckBox *box_motores;
    QSignalMapper *out_checkboxMapper = new QSignalMapper(this);

    for(i = 0; i < (quint32)detailed_elements[element]->out_config->ids.size(); i++)
    {
        box_motores = new QCheckBox(detailed_elements[element]->out_config->names.at(i));

        box_motores->setFont(font_2);
        box_motores->setLayoutDirection(Qt::RightToLeft);
        box_motores->setStyleSheet("QCheckBox{"
                                   "width: 40px;"
                                   "height: 40px;"
                                   "border: none;"
                                   "}"
                                   "QCheckBox::indicator:checked{"
                                   "image: url(:/iconos/images/Iconos/Encendido_blanco.png);"
                                   "border-width: 0px;"
                                   "width: 40px;"
                                   "height: 40px;"
                                   "}"
                                   "QCheckBox::indicator:unchecked{"
                                   "image: url(:/iconos/images/Iconos/Encendido_azul.png);"
                                   "border-width: 0px;"
                                   "width: 40px;"
                                   "height: 40px;"
                                   "}");

        ui->verticalLayout_2->addWidget(box_motores);

        connect(box_motores, SIGNAL(clicked(bool)), out_checkboxMapper, SLOT(map()));
        out_checkboxMapper->setMapping(box_motores, detailed_elements[element]->out_config->ids.at(i));
    }

    // Connect all checkboxes to mapper
    connect(out_checkboxMapper, SIGNAL(mapped(int)), this, SLOT(out_checkBoxStateChanged(int)));

    //Init with elements selected
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

    //TODO THIS IS TEMPORAL
    if(ELEMENT_REGULADOR != what_element)
    {
        ui->button_control->setStyleSheet("background-image: none;"
                        "border: none;"
                        "background-repeat: none;"
                        "background-position: center;");
    }
    else
    {
        ui->button_control->setStyleSheet("background-image: url(:/iconos/images/Iconos/Encendido_azul.png);"
                         "border: none;"
                         "background-repeat: none;"
                         "background-position: center;");
    }
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

    //TODO THIS IS TEMPORAL
    if(ELEMENT_REGULADOR != what_element)
    {
        ui->button_control->setStyleSheet("background-image: none;"
                        "border: none;"
                        "background-repeat: none;"
                        "background-position: center;");
    }
    else
    {
        ui->button_control->setStyleSheet("background-image: url(:/iconos/images/Iconos/Encendido_azul.png);"
                         "border: none;"
                         "background-repeat: none;"
                         "background-position: center;");
    }
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

    //TODO THIS IS TEMPORAL
    if(ELEMENT_REGULADOR != what_element)
    {
        ui->button_control->setStyleSheet("background-image: none;"
                        "border: none;"
                        "background-repeat: none;"
                        "background-position: center;");
    }
    else
    {
        ui->button_control->setStyleSheet("background-image: url(:/iconos/images/Iconos/Encendido_azul.png);"
                         "border: none;"
                         "background-repeat: none;"
                         "background-position: center;");
    }
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

    //TODO THIS IS TEMPORAL
    if(ELEMENT_REGULADOR != what_element)
    {
        ui->button_control->setStyleSheet("background-image: none;"
                        "border: none;"
                        "background-repeat: none;"
                        "background-position: center;");
    }
    else
    {
        ui->button_control->setStyleSheet("background-image: url(:/iconos/images/Iconos/Encendido_azul.png);"
                         "border: none;"
                         "background-repeat: none;"
                         "background-position: center;");
    }

}

void detailedwindow::on_button_control_clicked()
{
    //TODO THIS IS TEMPORAL
    if(ELEMENT_REGULADOR != what_element)
    {
        ui->button_control->setStyleSheet("background-image: none;"
                        "border: none;"
                        "background-repeat: none;"
                        "background-position: center;");
    }
    else
    {
        ui->label->setText("Encendido de Motores");
        ui->tabWidget->setCurrentIndex(4);
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
        ui->button_visualizacion->setStyleSheet("background-image: url(:/iconos/images/Iconos/Ajustes_azul.png);"
                         "border: none;"
                         "background-repeat: none;"
                         "background-position: center;");

        ui->button_control->setStyleSheet("background-image: url(:/iconos/images/Iconos/Encendido_blanco.png);"
                         "border: none;"
                         "background-repeat: none;"
                         "background-position: center;");
    }

}

void detailedwindow::checkBoxStateChanged(int a)
{
    qDebug() << "Toggle active show " << a;
    toggleParamActiveShow(a);
}

void detailedwindow::out_checkBoxStateChanged(int a)
{
    qDebug() << "Toggle output " << a;
    switch(a)
    {
        case 80:
            if(MainWindow::reg_op_mode == 3)
            {
                MainWindow::reg_op_mode = 1;
            }
            else
            {
                MainWindow::reg_op_mode = 3;
            }
            break;
        case 81:
            if(MainWindow::reg_mot_1 == 0)
            {
                MainWindow::reg_mot_1 = 1;
            }
            else
            {
                MainWindow::reg_mot_1 = 0;
            }
            break;
        case 82:
            if(MainWindow::reg_mot_2 == 0)
            {
                MainWindow::reg_mot_2 = 1;
            }
            else
            {
                MainWindow::reg_mot_2 = 0;
            }
            break;
    }
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


void detailedwindow::on_key_0_clicked() {insert_amount("0");}
void detailedwindow::on_key_1_clicked() {insert_amount("1");}
void detailedwindow::on_key_2_clicked() {insert_amount("2");}
void detailedwindow::on_key_3_clicked() {insert_amount("3");}
void detailedwindow::on_key_4_clicked() {insert_amount("4");}
void detailedwindow::on_key_5_clicked() {insert_amount("5");}
void detailedwindow::on_key_6_clicked() {insert_amount("6");}
void detailedwindow::on_key_7_clicked() {insert_amount("7");}
void detailedwindow::on_key_8_clicked() {insert_amount("8");}
void detailedwindow::on_key_9_clicked() {insert_amount("9");}

void detailedwindow::on_key_back_clicked()
{
    posponer_amount.chop(1);
    ui->label_horas->setText(posponer_amount + " " + posponer_amount_units);
}



void detailedwindow::item_selected(QTableWidgetItem* item)
{
    QTableWidget *table = item->tableWidget();
//    ui->label_2->setText(table->item(item->row(), 1)->text());
    selected_id = table->item(item->row(), 0)->text().toInt();

    qDebug() << "ID " << selected_id;
}

void detailedwindow::on_key_Reschedule_clicked()
{
    if(++add_base == BASE_LAST)
    {
        add_base = 0;
    }

    switch(add_base)
    {
    case BASE_SEC:
        posponer_amount_units = "s";
        base_mult = 1;
        break;
    case BASE_MIN:
        posponer_amount_units = "m";
        base_mult = 60;
        break;
    case BASE_HOUR:
        posponer_amount_units = "h";
        base_mult = 3600;
        break;
    case BASE_DAY:
        posponer_amount_units = "d";
        base_mult = 3600 * 24;
        break;
//    case BASE_MON:
//        ui->label_horas->setText("Meses:");
//        base_mult = 3600 * 24 * 30;
//        break;
    }

    ui->label_horas->setText(posponer_amount + " " + posponer_amount_units);
}

void detailedwindow::on_key_OK_clicked()
{
    uint i = 0;
    uint time = 0;

    time = posponer_amount.toInt();

    if(0 != selected_id)
    {
        qDebug() << "Button clicked ID: " << selected_id;
        for(i = 0; i < rutinas_ptr->num_of_rutinas ; i++)
        {
            if(rutinas_ptr->id(i) == selected_id)
            {
                qDebug() << "ID match at: " << i;

                if(time > 0)
                {
                    time = time * base_mult;
                    rutinas_ptr->add_seconds_rutina(i, time);
                }
                else
                {
                    rutinas_ptr->complete_rutina(i);
                }
            }
        }

        for(i = 0; i < ui->tableWidget->rowCount() ; i++)
        {
            if(ui->tableWidget->item(i,0)->text().toInt() == selected_id)
            {
                ui->tableWidget->removeRow(i);
                break;
            }
        }
    }
}

void detailedwindow::insert_amount(QString ins)
{
    posponer_amount += ins;

    ui->label_horas->setText(posponer_amount + " " + posponer_amount_units);
}
