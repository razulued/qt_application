#include "detailedwindow.h"
#include "ui_detailedwindow.h"
#include <QListView>
#include <QFontDatabase>
#include <QCheckBox>
#include <QTableWidget>
#include "parameters.h"
#include <QDebug>
#include "mainwindow.h"
#include <QScrollBar>
#include <QScrollArea>
#include <QScroller>
#include <QScrollerProperties>
#include "clickeablelabel.h"

#define BUILD_FOR_RPI (0)

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
    "Deshidratador",
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

    clickeablelabel *alphabackground = new clickeablelabel(this);
    alphabackground->setGeometry(this->geometry());
    alphabackground->setStyleSheet("background-color: rgb(0,0,0,120);");
    alphabackground->lower();
    connect(alphabackground,SIGNAL(clicked()),this,SLOT(background_clicked()));

    rutinas_ptr = rutina;

    this->setObjectName("DetailedWindow");
    this->setStyleSheet("detailedwindow#DetailedWindow{"
                        "background-color:transparent;"
                        "}"
                        "QCheckBox{color:white}"
                        "QCheckBox::indicator:checked{"
                            "border-width: 3px;"
                            "border-style: solid;"
                            "border-color: rgb(0, 167, 250);"
                            "border-radius: 5px;"
                            "width: 24px;"
                            "height: 24px;"
                            "image: url(:/iconos/images/Iconos/Punto_contrasena.png);"
                        "}"
                        "QCheckBox::indicator:unchecked{"
                        "border-width: 3px;"
                        "border-style: solid;"
                        "border-color: gray;"
                        "border-radius: 5px;"
                        "width: 24px;"
                        "height: 24px;"
                         "}"
                        "QLabel{color:white}"
                        );
    // Fonts
    QFont font("Typo Square Italic Demo",16,1);
    QFont font_2("Typo Square Bold Italic Demo",18,1);

//    ui->frame->setObjectName("DetailFrame");
//    ui->frame->setStyleSheet("detailedwindow#DetailFrame{"
//                             "background-color:black;"
//                             "border-style: solid;"
//                             "border-width: 6px;"
//                             "border-radius: 6px;"
//                             "border-color: gray;"
//                             "}");

    // Nombre Del elemento
    ui->nombre->setFont(font_2);
    ui->nombre->setStyleSheet("color: black");
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
    ui->tabWidget->setTabText(5,"");

    ui->tab_1->setStyleSheet("background:black");
    ui->tab_2->setStyleSheet("background:black");
    ui->tab_3->setStyleSheet("background:black");
    ui->tab_4->setStyleSheet("background:black");
    ui->tab_5->setStyleSheet("background:black");
    ui->tab_6->setStyleSheet("background:black");


    //TODO THIS IS TEMPORAL
    if(detailed_elements[element]->out_config->ids.size() == 0)
    {
        ui->button_control->setStyleSheet("background-image: none;"
                        "border: none;"
                        "background-repeat: none;"
                        "background-position: center;");
    }

    tab_1_init();
    tab_2_init();
    tab_3_init();
    tab_4_init();
    tab_5_init();

    init_completed = true;
//    if(NULL != blur_window)
//    {
//        delete blur_window;
//    }

//    blur_window = new blur();

    //Hide window bars and buttons
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
    this->setAttribute(Qt::WA_TranslucentBackground);


    ui->textEdit->setVisible(false);
    ui->key_frame->setVisible(false);
    ui->frame->setGeometry(ui->frame->pos().x(),200,ui->frame->width(),ui->frame->height());
    this->show();
}

detailedwindow::~detailedwindow()
{
    delete ui;
}

void detailedwindow::on_closeButton_clicked()
{
//    blur_window->close();
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

    /* Hide keyboard and text edit */
    ui->textEdit->setVisible(false);
    ui->key_frame->setVisible(false);
    ui->frame->setGeometry(ui->frame->pos().x(),200,ui->frame->width(),ui->frame->height());
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

    /* Hide keyboard and text edit */
    ui->textEdit->setVisible(false);
    ui->key_frame->setVisible(false);
    ui->frame->setGeometry(ui->frame->pos().x(),200,ui->frame->width(),ui->frame->height());
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

    /* Hide keyboard and text edit */
    ui->textEdit->setVisible(false);
    ui->key_frame->setVisible(false);
    ui->frame->setGeometry(ui->frame->pos().x(),200,ui->frame->width(),ui->frame->height());
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

    /* Hide keyboard and text edit */
    ui->textEdit->setVisible(false);
    ui->key_frame->setVisible(false);
    ui->frame->setGeometry(ui->frame->pos().x(),200,ui->frame->width(),ui->frame->height());
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

    /* Hide keyboard and text edit */
    ui->textEdit->setVisible(false);
    ui->key_frame->setVisible(false);
    ui->frame->setGeometry(ui->frame->pos().x(),200,ui->frame->width(),ui->frame->height());
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
#if BUILD_FOR_RPI
                system("echo 1 >/sys/class/gpio/gpio17/value");
#endif
            }
            else
            {
                MainWindow::reg_mot_1 = 0;
#if BUILD_FOR_RPI
                system("echo 0 >/sys/class/gpio/gpio17/value");
#endif
            }
            break;
        case 82:
            if(MainWindow::reg_mot_2 == 0)
            {
                MainWindow::reg_mot_2 = 1;
#if BUILD_FOR_RPI
                system("echo 1 >/sys/class/gpio/gpio27/value");
#endif
            }
            else
            {
                MainWindow::reg_mot_2 = 0;
#if BUILD_FOR_RPI
                system("echo 0 >/sys/class/gpio/gpio27/value");
#endif
            }
            break;
    }
}

void detailedwindow::update_params()
{
    if(true == init_completed)
    {
        tab_1_update();
        tab_2_update();
    }
}


void detailedwindow::on_key_0_clicked() {if(true == ui->key_Reschedule->isChecked()){insert_amount("0");}else{ui->textEdit->insertPlainText("0");}}
void detailedwindow::on_key_1_clicked() {if(true == ui->key_Reschedule->isChecked()){insert_amount("1");}else{ui->textEdit->insertPlainText("1");}}
void detailedwindow::on_key_2_clicked() {if(true == ui->key_Reschedule->isChecked()){insert_amount("2");}else{ui->textEdit->insertPlainText("2");}}
void detailedwindow::on_key_3_clicked() {if(true == ui->key_Reschedule->isChecked()){insert_amount("3");}else{ui->textEdit->insertPlainText("3");}}
void detailedwindow::on_key_4_clicked() {if(true == ui->key_Reschedule->isChecked()){insert_amount("4");}else{ui->textEdit->insertPlainText("4");}}
void detailedwindow::on_key_5_clicked() {if(true == ui->key_Reschedule->isChecked()){insert_amount("5");}else{ui->textEdit->insertPlainText("5");}}
void detailedwindow::on_key_6_clicked() {if(true == ui->key_Reschedule->isChecked()){insert_amount("6");}else{ui->textEdit->insertPlainText("6");}}
void detailedwindow::on_key_7_clicked() {if(true == ui->key_Reschedule->isChecked()){insert_amount("7");}else{ui->textEdit->insertPlainText("7");}}
void detailedwindow::on_key_8_clicked() {if(true == ui->key_Reschedule->isChecked()){insert_amount("8");}else{ui->textEdit->insertPlainText("8");}}
void detailedwindow::on_key_9_clicked() {if(true == ui->key_Reschedule->isChecked()){insert_amount("9");}else{ui->textEdit->insertPlainText("9");}}

void detailedwindow::on_key_back_clicked()
{
    if(true == ui->key_Reschedule->isChecked())
    {
        posponer_amount.chop(1);
        ui->label_horas->setText(posponer_amount + " " + posponer_amount_units);
    }
    else
    {
        ui->textEdit->textCursor().deletePreviousChar();
    }
}



void detailedwindow::item_selected(QTableWidgetItem* item)
{
    uint i = 0;
    QTableWidget *table = item->tableWidget();
//    ui->label_2->setText(table->item(item->row(), 1)->text());
    selected_id = table->item(item->row(), 0)->text().toInt();

    ui->tableWidget_2->setRowCount(0);

    for(i = 0; i < rutinas_ptr->num_of_rutinas ; i++)
    {
        if(rutinas_ptr->id(i) == selected_id)
        {
            ui->explicacion->setText(rutinas_ptr->explicacion(i));
            // Si la rutina pertenece a este elemento agregar a la tabla
            ui->tableWidget_2->insertRow(0);
            ui->tableWidget_2->setItem(0,0, new QTableWidgetItem(QString::number(rutinas_ptr->id(i))));
            ui->tableWidget_2->setItem(0,1, new QTableWidgetItem(rutinas_ptr->nombre(i)));
            break;
        }
    }

    ui->tableWidget_2->resizeRowsToContents();
    ui->tableWidget_2->setColumnWidth(0, 40);
    ui->tableWidget_2->setWordWrap(true);

    //Change to special tab
    ui->tabWidget->setCurrentIndex(5);
    qDebug() << "ID " << selected_id;
}

void detailedwindow::on_key_Reschedule_clicked()
{

    if(false == ui->key_frame->isVisible())
    {
        uint i = 0;

        /* Show keyboard and text edit */
        ui->textEdit->setVisible(true);
        ui->key_frame->setVisible(true);
        ui->frame->setGeometry(ui->frame->pos().x(),10,ui->frame->width(),ui->frame->height());

        ui->textEdit->clear();

        for(i = 0; i < rutinas_ptr->num_of_rutinas ; i++)
        {
            if(rutinas_ptr->id(i) == selected_id)
            {
                ui->textEdit->setText(rutinas_ptr->texto_ayuda(i));
                break;
            }
        }
    }

    ui->key_Reschedule->setChecked(true);

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
                break;
            }
        }

//        for(i = 0; i < (uint)ui->tableWidget->rowCount() ; i++)
//        {
//            if((uint)ui->tableWidget->item(i,0)->text().toInt() == selected_id)
//            {
//                ui->tableWidget->removeRow(i);
//                break;
//            }
//        }
    }

    ui->textEdit->setVisible(false);
    ui->key_frame->setVisible(false);
    ui->frame->setGeometry(ui->frame->pos().x(),200,ui->frame->width(),ui->frame->height());
    ui->tabWidget->setCurrentIndex(1);
}

void detailedwindow::insert_amount(QString ins)
{
    posponer_amount += ins;

    ui->label_horas->setText(posponer_amount + " " + posponer_amount_units);
}

void detailedwindow::tab_1_init()
{
    QFont font_2("Typo Square Ligth Demo",14,1);

    uint i, param_id;
    uint fila = 0;

    //Add 2 columns
    ui->tableWidget_tab_1->setColumnCount(2);
    ui->tableWidget_tab_1->setFont(font_2);
    ui->tableWidget_tab_1->setStyleSheet("color: white;"
                                   "background-color: black;"
                                   "gridline-color: black;");
    ui->tableWidget_tab_1->verticalHeader()->setVisible(false);
    ui->tableWidget_tab_1->horizontalHeader()->setVisible(false);

//    qDebug() << "Number of parameters to display is " << detailed_elements[element]->list_elect->ids.size();
    for(i = 0; i < (quint32)detailed_elements[what_element]->list_elect->ids.size(); i++)
    {
        param_id = detailed_elements[what_element]->list_elect->ids.at(i);
//        qDebug() << getParamName(param_id) <<" "<< param_id << " " << getParamValue(param_id);
        ui->tableWidget_tab_1->insertRow(fila);
        ui->tableWidget_tab_1->setItem(fila,0, new QTableWidgetItem(detailed_elements[what_element]->list_elect->names.at(i) + ":"));
        ui->tableWidget_tab_1->setItem(fila,1, new QTableWidgetItem(getParamValue(param_id)));
        fila++;
    }
//    qDebug() << "Number of parameters to display is " << detailed_elements[element]->list_phys->ids.size();
    for(i = 0; i < (quint32)detailed_elements[what_element]->list_phys->ids.size(); i++)
    {
        param_id = detailed_elements[what_element]->list_phys->ids.at(i);
//        qDebug() << getParamName(param_id) <<" "<< param_id << " " << getParamValue(param_id);
        ui->tableWidget_tab_1->insertRow(fila);
        ui->tableWidget_tab_1->setItem(fila,0, new QTableWidgetItem(detailed_elements[what_element]->list_phys->names.at(i) + ":"));
        ui->tableWidget_tab_1->setItem(fila,1, new QTableWidgetItem(getParamValue(param_id)));
        fila++;
    }
//    qDebug() << "Number of parameters to display is " << detailed_elements[element]->list_chem->ids.size();
    for(i = 0; i < (quint32)detailed_elements[what_element]->list_chem->ids.size(); i++)
    {
        param_id = detailed_elements[what_element]->list_chem->ids.at(i);
//        qDebug() << getParamName(param_id) <<" "<< param_id << " " << getParamValue(param_id);
        ui->tableWidget_tab_1->insertRow(fila);
        ui->tableWidget_tab_1->setItem(fila,0, new QTableWidgetItem(detailed_elements[what_element]->list_chem->names.at(i) + ":"));
        ui->tableWidget_tab_1->setItem(fila,1, new QTableWidgetItem(getParamValue(param_id)));
        fila++;
    }

    ui->tableWidget_tab_1->setColumnWidth(0,150);

    //Scroll
    QScroller *scroller = QScroller::scroller(ui->tableWidget_tab_1);
    ui->tableWidget_tab_1->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->tableWidget_tab_1->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

    QScrollerProperties properties = QScroller::scroller(scroller)->scrollerProperties();
    QVariant overshootPolicy = QVariant::fromValue<QScrollerProperties::OvershootPolicy>(QScrollerProperties::OvershootAlwaysOff);
    properties.setScrollMetric(QScrollerProperties::VerticalOvershootPolicy, overshootPolicy);
    scroller->setScrollerProperties(properties);
    properties.setScrollMetric(QScrollerProperties::HorizontalOvershootPolicy, overshootPolicy);
    scroller->setScrollerProperties(properties);
    //Scrolling Gesture
    scroller->grabGesture(ui->tableWidget_tab_1,QScroller::LeftMouseButtonGesture);
}

void detailedwindow::tab_2_init()
{
    uint i = 0;
    QFont font("Typo Square Bold Demo",14,1);
    QStringList titulos;
    titulos << "ID" << "Rutina"; // Fecha is next

    QFont font1("Typo Square Italic Demo",14,1);

    QFont font2("Typo Square Italic Demo",12,1);
    QFont font3("Typo Square Regular Demo",10,1);
    QFont font4("Typo Square Regular Demo",12,1);


//    ui->key_OK->setStyleSheet("border: 2px solid rgb(0, 167, 250); color: white");
//    ui->key_Reschedule->setStyleSheet("border: 2px solid rgb(0, 167, 250); color: white");

    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setFont(font2);

    ui->tableWidget->setStyleSheet("color: rgb(0, 167, 250);;"
                                   "alternate-background-color: rgb(50, 50, 50);"
                                   "background-color: black;"
                                   "gridline-color: none;"
                                   "border-style: none;"
                                   "QHeaderView::section:vertical{"
                                   "border-left: none;"
                                   "}"
                                   "QHeaderView::section:horizontal{"
                                   "border-top: none;"
                                   "}"
                                   );
    ui->tableWidget->horizontalHeader()->setFont(font1);
//    ui->tableWidget->horizontalHeader()->setStyleSheet("border-style: none;"
//                                                       "border-bottom: 1px solid #00a7fa;"
//                                                       "border-top: 1px solid #00a7fa;"
//                                                       "border-left: 1px solid #00a7fa;"
//                                                       "border-right: 1px solid #00a7fa;"
//                                                       "QHeaderView::section:horizontal{"
//                                                       "border-top: 1px solid #00a7fa;"
//                                                       "}");
    ui->tableWidget->verticalHeader()->setVisible(false);


    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section:horizontal{"
                                                     "background-color: rgb(50, 50, 50);"
                                                     "}");
    ui->tableWidget->verticalScrollBar()->setStyleSheet("width: 20px");
    ui->tableWidget->setWordWrap(true);


    ui->tableWidget->setColumnCount(titulos.size());
    ui->tableWidget->setHorizontalHeaderLabels(titulos);


    /* Init style sheet for special tab */
    ui->tableWidget_2->setAlternatingRowColors(true);
    ui->tableWidget_2->setStyleSheet(ui->tableWidget->styleSheet());
    ui->tableWidget_2->setFont(ui->tableWidget->font());
    ui->tableWidget_2->horizontalHeader()->setFont(font1);
    ui->tableWidget_2->verticalHeader()->setVisible(false);
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_2->horizontalHeader()->setStyleSheet(ui->tableWidget->horizontalHeader()->styleSheet());
    ui->tableWidget_2->setColumnCount(titulos.size());
    ui->tableWidget_2->setHorizontalHeaderLabels(titulos);

    ui->explicacion->setWordWrap(true);
    ui->explicacion->setFont(font3);
    ui->textEdit->setFont(font4);

    ui->label_horas->setFont(font);
    ui->label_horas->setAlignment(Qt::AlignRight);


    connect(ui->tableWidget, SIGNAL(itemPressed(QTableWidgetItem*)), this, SLOT(item_selected(QTableWidgetItem*)));

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

        ui->tableWidget->setColumnWidth(0, 40);
        ui->tableWidget_2->setColumnWidth(0, 40);
    }

}

void detailedwindow::tab_3_init()
{
    QFont font("Typo Square Ligth Demo",12,1);

    ui->description_label->setFont(font);
    ui->description_label->setText(detailed_elements[what_element]->description);
    ui->description_label->setStyleSheet("color: white");
}

void detailedwindow::tab_4_init()
{
    uint i = 0;
    uint param_id;
    QFont font_2("Typo Square Ligth Demo",14,1);

    QSignalMapper *checkboxMapper = new QSignalMapper(this);

//    QScrollArea* scrollArea = new QScrollArea;
//    scrollArea->setHorizontalScrollBarPolicy (Qt::ScrollBarAlwaysOff);
//    scrollArea->setVerticalScrollBarPolicy (Qt::ScrollBarAsNeeded);
//    scrollArea->setWidget(ui->tab_4);
//    scrollArea->setWidgetResizable (true);

//    QVBoxLayout *layout = new QVBoxLayout(ui->tab_4);
    QVBoxLayout *layout = new QVBoxLayout;
    ui->scrollArea->widget()->setLayout(layout);
    ui->scrollArea->setWidgetResizable(true);
    layout->setAlignment(Qt::AlignTop);


    QCheckBox *box;

    for(i = 0; i < (quint32)detailed_elements[what_element]->list_elect->ids.size(); i++)
    {
        param_id = detailed_elements[what_element]->list_elect->ids.at(i);

        box = new QCheckBox(detailed_elements[what_element]->list_elect->names.at(i));
        if(true == getParamActiveShow(param_id))
        {
            box->setChecked(true);
        }
        box->setFont(font_2);
//        box->setLayoutDirection(Qt::RightToLeft);
        layout->addWidget(box);


        //Connect checkbox to parameter active show
        connect(box, SIGNAL(clicked(bool)), checkboxMapper, SLOT(map()));
        checkboxMapper->setMapping(box, param_id);
    }

    for(i = 0; i < (quint32)detailed_elements[what_element]->list_phys->ids.size(); i++)
    {
        param_id = detailed_elements[what_element]->list_phys->ids.at(i);

        box = new QCheckBox(detailed_elements[what_element]->list_phys->names.at(i));
        if(true == getParamActiveShow(param_id))
        {
            box->setChecked(true);
        }
        box->setFont(font_2);
//        box->setLayoutDirection(Qt::RightToLeft);
        layout->addWidget(box);
        //Connect checkbox to parameter active show
        connect(box, SIGNAL(clicked(bool)), checkboxMapper, SLOT(map()));
        checkboxMapper->setMapping(box, param_id);
    }

    for(i = 0; i < (quint32)detailed_elements[what_element]->list_chem->ids.size(); i++)
    {
        param_id = detailed_elements[what_element]->list_chem->ids.at(i);

        box = new QCheckBox(detailed_elements[what_element]->list_chem->names.at(i));
        if(true == getParamActiveShow(param_id))
        {
            box->setChecked(true);
        }
        box->setFont(font_2);
//        box->setLayoutDirection(Qt::RightToLeft);
        layout->addWidget(box);

        //Connect checkbox to parameter active show
        connect(box, SIGNAL(clicked(bool)), checkboxMapper, SLOT(map()));
        checkboxMapper->setMapping(box, param_id);
    }

    // Connect all checkboxes to mapper
    connect(checkboxMapper, SIGNAL(mapped(int)), this, SLOT(checkBoxStateChanged(int)));

    //Scroll
//    QScroller::grabGesture(ui->scrollArea, QScroller::LeftMouseButtonGesture);
    QScroller *scroller = QScroller::scroller(ui->scrollArea);
    QScrollerProperties properties = QScroller::scroller(scroller)->scrollerProperties();
    QVariant overshootPolicy = QVariant::fromValue<QScrollerProperties::OvershootPolicy>(QScrollerProperties::OvershootAlwaysOff);
    properties.setScrollMetric(QScrollerProperties::VerticalOvershootPolicy, overshootPolicy);
    scroller->setScrollerProperties(properties);
    //Scrolling Gesture
    scroller->grabGesture(ui->scrollArea,QScroller::LeftMouseButtonGesture);
}

void detailedwindow::tab_5_init()
{
    uint i = 0;
    QFont font_2("Typo Square Ligth Demo",14,1);

    QCheckBox *box_motores;
    QSignalMapper *out_checkboxMapper = new QSignalMapper(this);

    for(i = 0; i < (quint32)detailed_elements[what_element]->out_config->ids.size(); i++)
    {
        box_motores = new QCheckBox(detailed_elements[what_element]->out_config->names.at(i));

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

        if(0 == i)
        {
            if(1 ==MainWindow::reg_mot_1)
            {
                box_motores->setChecked(true);
            }
        }
        else if(1 == i)
        {
            if(1 ==MainWindow::reg_mot_2)
            {
                box_motores->setChecked(true);
            }
        }

        ui->verticalLayout_2->addWidget(box_motores);

        connect(box_motores, SIGNAL(clicked(bool)), out_checkboxMapper, SLOT(map()));
        out_checkboxMapper->setMapping(box_motores, detailed_elements[what_element]->out_config->ids.at(i));
    }

    // Connect all checkboxes to mapper
    connect(out_checkboxMapper, SIGNAL(mapped(int)), this, SLOT(out_checkBoxStateChanged(int)));

    //Init with elements selected
    ui->button_parametros->setStyleSheet("background-image: url(:/iconos/images/Iconos/Visualizar_blanco.png);"
                    "border: none;"
                    "background-repeat: none;"
                    "background-position: center;");

}

void detailedwindow::tab_1_update()
{
    uint i, param_id;
    uint fila = 0;

//    qDebug() << "Number of parameters to display is " << detailed_elements[element]->list_elect->ids.size();
    for(i = 0; i < (quint32)detailed_elements[what_element]->list_elect->ids.size(); i++)
    {
        param_id = detailed_elements[what_element]->list_elect->ids.at(i);
        ui->tableWidget_tab_1->setItem(fila,1, new QTableWidgetItem(getParamValue(param_id)));
        fila++;
    }
//    qDebug() << "Number of parameters to display is " << detailed_elements[element]->list_phys->ids.size();
    for(i = 0; i < (quint32)detailed_elements[what_element]->list_phys->ids.size(); i++)
    {
        param_id = detailed_elements[what_element]->list_phys->ids.at(i);
        ui->tableWidget_tab_1->setItem(fila,1, new QTableWidgetItem(getParamValue(param_id)));
        fila++;
    }
//    qDebug() << "Number of parameters to display is " << detailed_elements[element]->list_chem->ids.size();
    for(i = 0; i < (quint32)detailed_elements[what_element]->list_chem->ids.size(); i++)
    {
        param_id = detailed_elements[what_element]->list_chem->ids.at(i);
        ui->tableWidget_tab_1->setItem(fila,1, new QTableWidgetItem(getParamValue(param_id)));
        fila++;
    }
}

void detailedwindow::tab_2_update()
{
    uint i = 0, row = 0;
    bool item_found = false;

    //Add new elements to the table
    for(i = 0; i < rutinas_ptr->num_of_rutinas; i++)
    {
        if((origentype == rutinas_ptr->origen(i)) && (0 == rutinas_ptr->ready(i)))
        {
            for(row = 0; row < ui->tableWidget->rowCount() ; row++)
            {
                if(ui->tableWidget->item(row,0)->text().toInt() == rutinas_ptr->id(i))
                {
                    item_found = true;
                    break;
                }
            }
            if(!item_found)
            {
                add_row_rutina(ui->tableWidget->rowCount(), i, ui->tableWidget);
            }
        }
        item_found = false;
    }


    // Remove elelents
    for(i = 0; i < rutinas_ptr->num_of_rutinas; i++)
    {
        if((origentype == rutinas_ptr->origen(i)) && (1 == rutinas_ptr->ready(i)))
        {
            for(row = 0; row < ui->tableWidget->rowCount() ; row++)
            {
                if(ui->tableWidget->item(row,0)->text().toInt() == rutinas_ptr->id(i))
                {
                    item_found = true;
                    break;
                }
            }

            if(item_found)
            {
                delete_row(row, ui->tableWidget);
            }
        }
        item_found = false;
    }

    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->setColumnWidth(0, 40);
    ui->tableWidget->setWordWrap(true);

}

void detailedwindow::tab_3_update()
{

}

void detailedwindow::tab_4_update()
{
}

void detailedwindow::tab_5_update()
{

}


void detailedwindow::add_row_rutina(uint row, uint rutina, QTableWidget *table)
{
    table->insertRow(row);

    table->setItem(row,0, new QTableWidgetItem(QString::number(rutinas_ptr->id(rutina))));

    table->setItem(row,1, new QTableWidgetItem(rutinas_ptr->nombre(rutina)));
}

void detailedwindow::delete_row(uint row, QTableWidget *table)
{
    table->removeRow(row);
}

void detailedwindow::on_ayuda_btn_clicked()
{
    uint i = 0;

    /* Show keyboard and text edit */
    ui->textEdit->setVisible(true);
    ui->key_frame->setVisible(true);
    ui->frame->setGeometry(ui->frame->pos().x(),10,ui->frame->width(),ui->frame->height());

    ui->textEdit->clear();

    for(i = 0; i < rutinas_ptr->num_of_rutinas ; i++)
    {
        if(rutinas_ptr->id(i) == selected_id)
        {
            ui->textEdit->setText(rutinas_ptr->texto_ayuda(i));
            break;
        }
    }
}

void detailedwindow::on_key_Q_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("Q");}else{ui->textEdit->insertPlainText("q");}}
void detailedwindow::on_key_W_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("W");}else{ui->textEdit->insertPlainText("w");}}
void detailedwindow::on_key_E_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("E");}else{ui->textEdit->insertPlainText("e");}}
void detailedwindow::on_key_R_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("R");}else{ui->textEdit->insertPlainText("r");}}
void detailedwindow::on_key_T_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("T");}else{ui->textEdit->insertPlainText("t");}}
void detailedwindow::on_key_Y_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("Y");}else{ui->textEdit->insertPlainText("y");}}
void detailedwindow::on_key_U_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("U");}else{ui->textEdit->insertPlainText("u");}}
void detailedwindow::on_key_I_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("I");}else{ui->textEdit->insertPlainText("i");}}
void detailedwindow::on_key_O_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("O");}else{ui->textEdit->insertPlainText("o");}}
void detailedwindow::on_key_P_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("P");}else{ui->textEdit->insertPlainText("p");}}
void detailedwindow::on_key_A_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("A");}else{ui->textEdit->insertPlainText("a");}}
void detailedwindow::on_key_S_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("S");}else{ui->textEdit->insertPlainText("s");}}
void detailedwindow::on_key_D_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("D");}else{ui->textEdit->insertPlainText("d");}}
void detailedwindow::on_key_F_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("F");}else{ui->textEdit->insertPlainText("f");}}
void detailedwindow::on_key_G_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("G");}else{ui->textEdit->insertPlainText("g");}}
void detailedwindow::on_key_H_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("H");}else{ui->textEdit->insertPlainText("h");}}
void detailedwindow::on_key_J_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("J");}else{ui->textEdit->insertPlainText("j");}}
void detailedwindow::on_key_K_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("K");}else{ui->textEdit->insertPlainText("k");}}
void detailedwindow::on_key_L_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("L");}else{ui->textEdit->insertPlainText("l");}}
void detailedwindow::on_key_Z_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("Z");}else{ui->textEdit->insertPlainText("z");}}
void detailedwindow::on_key_X_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("X");}else{ui->textEdit->insertPlainText("x");}}
void detailedwindow::on_key_C_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("C");}else{ui->textEdit->insertPlainText("c");}}
void detailedwindow::on_key_V_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("V");}else{ui->textEdit->insertPlainText("v");}}
void detailedwindow::on_key_B_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("B");}else{ui->textEdit->insertPlainText("b");}}
void detailedwindow::on_key_N_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("N");}else{ui->textEdit->insertPlainText("n");}}
void detailedwindow::on_key_M_clicked(){if(ui->key_mayus->isChecked()){ui->textEdit->insertPlainText("M");}else{ui->textEdit->insertPlainText("m");}}
void detailedwindow::on_key_comma_clicked(){ui->textEdit->insertPlainText(",");}
void detailedwindow::on_key_space_clicked(){ui->textEdit->insertPlainText(" ");}
void detailedwindow::on_key_enter_clicked(){ui->textEdit->insertPlainText("\n");}
void detailedwindow::on_key_dot_clicked(){ui->textEdit->insertPlainText(".");}
void detailedwindow::on_key_plus_clicked(){ui->textEdit->insertPlainText("+");}
void detailedwindow::on_key_minus_clicked(){ui->textEdit->insertPlainText("-");}
void detailedwindow::on_key_slash_clicked(){ui->textEdit->insertPlainText("/");}

void detailedwindow::background_clicked()
{
    this->close();
}

void detailedwindow::on_textEdit_selectionChanged()
{
    ui->key_Reschedule->setChecked(false);
}
