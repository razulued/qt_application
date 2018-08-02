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
#include "asa_conf_string.h"
#include "token_auth.h"
#include <QMutex>
#include "login_dialog.h"
#include "QMovie"

#define BUILD_FOR_RPI (1)

#define MAX_INACTIVITY_TIMEOUT (300 * 1000)

QMutex parametros_mutex;
bool detailedwindow::user_lock;

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

detailed_window_elements_t details_9=
{
    "Filtro",
    ":/diagrama/screen800x600/diagrama/Filtro 5SDF portátil_ small.png",
    "Equipo de filtración terciaria. Utilizando una tela especializada como medio fijo filtrante logra la remoción "
    "adicional de sólidos así como el color ámbar característico de las aguas tratadas. "
    "Dadas las características de la tela filtrante, no se requiere la acumulación de material ni la formación de "
    "una manta filtrante a fin de lograr el pulimento deseado.",


    &MainWindow::conf_filtro_elect,

    &MainWindow::conf_filtro_fisic,

    &MainWindow::conf_filtro_quimi,

    &MainWindow::filtro_outputs,
};

detailed_window_elements_t details_10=
{
    "Bomba Alimentación",
    ":/diagrama/screen800x600/diagrama/motor_filtro_small.png",
    "Agregar descripción",


    &MainWindow::conf_filtro_bomba_elect,

    &MainWindow::conf_filtro_bomba_fisic,

    &MainWindow::conf_filtro_bomba_quimi,

    &MainWindow::filtro_bomba_outputs,
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
    &details_9,
    &details_10,
};

detailedwindow::detailedwindow(detailed_elements_t element, rutinas_mantenimiento *rutina, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailedwindow)
{
    ui->setupUi(this);

    init_completed = false;

    clickeablelabel *alphabackground = new clickeablelabel(this);
    alphabackground->setGeometry(this->geometry());
    alphabackground->setStyleSheet("background-color: rgb(0,0,0,180);");
    alphabackground->lower();
    connect(alphabackground,SIGNAL(clicked()),this,SLOT(background_clicked()));


    ui->pushButton->setCheckable(true);
    if(get_id_state("0902").toInt() == 1)
    {
        ui->pushButton->setChecked(true);
        stop_pressed = true;
        wating_timer = false;
        stop_button_animation(true);
    }
    else
    {
        stop_button_animation(false);
    }

    ui->pushButton->setCheckable(true);

    if(true == stop_op_mode())
    {
        ui->pushButton_modulo->setChecked(true);
        stop_pressed_modulo = true;
        wating_timer_modulo = false;
        stop_button_animation_module(true);
    }
    else
    {
        stop_button_animation_module(false);
    }

    synch_output_state();


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
                            "width: 18px;"
                            "height: 18px;"
                            "image: url(:/iconos/screen800x600/iconos/Punto contrasena.png);"
                        "}"
                        "QCheckBox::indicator:unchecked{"
                        "border-width: 3px;"
                        "border-style: solid;"
                        "border-color: gray;"
                        "border-radius: 5px;"
                        "width: 18px;"
                        "height: 18px;"
                         "}"
                        "QLabel{color:white}"
                        );
    // Fonts
    QFont font("Typo Square Italic Demo",12,1);
    QFont font_2("Typo Square Bold Italic Demo",14,1);

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
    ui->nombre->setStyleSheet("color: black;"
                              "background-color: transparent;");
    ui->nombre->setText(detailed_elements[element]->name);

    ui->imagen->setStyleSheet("border-image: url("+detailed_elements[element]->image+");"
                            "background-color: transparent;");

    // Nombre del detalle
    ui->label->setFont(font);
    ui->label->setStyleSheet("color: white;"
                             "background-color: transparent;");

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

        has_output_control = false;
    }
    else
    {
        has_output_control = true;
    }

    //Check token
    if(true == get_validity_state())
    {
        output_token_transfer(true);
    }
    else
    {
        output_token_transfer(false);
    }

    mode_4600 = load_parameter("mode4600.bin");
    read_op_mode();


    tab_1_init(0);
    tab_2_init();
    tab_3_init();
    tab_4_init();
    tab_5_init();


//    if(NULL != blur_window)
//    {
//        delete blur_window;
//    }

//    blur_window = new blur();

    ui->textEdit->setVisible(false);
    ui->key_frame->setVisible(false);
    ui->frame->setGeometry(ui->frame->pos().x(),150,ui->frame->width(),ui->frame->height());

    // Start timer
    QTimer::singleShot(MAX_INACTIVITY_TIMEOUT, this, SLOT(checkActivity()));


    //Hide window bars and buttons
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    this->move(parent->pos());

    init_completed = true;

//    this->show();

}

detailedwindow::~detailedwindow()
{
    delete ui;
}

void detailedwindow::on_closeButton_clicked()
{
//    blur_window->close()
//    validate_token(false);
    //Check token
    output_token_transfer(false);
    release_lock();
    this->close();
}

void detailedwindow::on_button_parametros_clicked()
{
    ui->label->setText("Parámetros");
    ui->tabWidget->setCurrentIndex(0);
    ui->button_parametros->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Visualizar blanco.png);"
                    "border: none;"
                    "background-repeat: none;"
                    "background-position: center;");
    ui->button_evento->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Bitacora azul.png);;"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
    ui->button_descripcion->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Info azul.png);"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
    ui->button_visualizacion->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Ajustes azul.png);"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");

    if(false == has_output_control)
    {
        ui->button_control->setStyleSheet("background-image: none;"
                        "border: none;"
                        "background-repeat: none;"
                        "background-position: center;");
    }
    else
    {
        ui->button_control->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Encendido azul.png);"
                         "border: none;"
                         "background-repeat: none;"
                         "background-position: center;");
    }

    /* Hide keyboard and text edit */
    ui->textEdit->setVisible(false);
    ui->key_frame->setVisible(false);
    ui->frame->setGeometry(ui->frame->pos().x(),150,ui->frame->width(),ui->frame->height());
    has_activity = true;
}

void detailedwindow::on_button_evento_clicked()
{
    ui->label->setText("Evento");
    ui->tabWidget->setCurrentIndex(1);
    ui->button_parametros->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Visualizar azul.png);"
                    "border: none;"
                    "background-repeat: none;"
                    "background-position: center;");
    ui->button_evento->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Bitacora blanco.png);;"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
    ui->button_descripcion->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Info azul.png);"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
    ui->button_visualizacion->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Ajustes azul.png);"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");

    if(false == has_output_control)
    {
        ui->button_control->setStyleSheet("background-image: none;"
                        "border: none;"
                        "background-repeat: none;"
                        "background-position: center;");
    }
    else
    {
        ui->button_control->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Encendido azul.png);"
                         "border: none;"
                         "background-repeat: none;"
                         "background-position: center;");
    }

    /* Hide keyboard and text edit */
    ui->textEdit->setVisible(false);
    ui->key_frame->setVisible(false);
    ui->frame->setGeometry(ui->frame->pos().x(),150,ui->frame->width(),ui->frame->height());
    has_activity = true;
}

void detailedwindow::on_button_descripcion_clicked()
{
    ui->label->setText("Descripción");
    ui->tabWidget->setCurrentIndex(2);
    ui->button_parametros->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Visualizar azul.png);"
                    "border: none;"
                    "background-repeat: none;"
                    "background-position: center;");
    ui->button_evento->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Bitacora azul.png);;"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
    ui->button_descripcion->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Info blanco.png);"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
    ui->button_visualizacion->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Ajustes azul.png);"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");

    if(false == has_output_control)
    {
        ui->button_control->setStyleSheet("background-image: none;"
                        "border: none;"
                        "background-repeat: none;"
                        "background-position: center;");
    }
    else
    {
        ui->button_control->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Encendido azul.png);"
                         "border: none;"
                         "background-repeat: none;"
                         "background-position: center;");
    }

    /* Hide keyboard and text edit */
    ui->textEdit->setVisible(false);
    ui->key_frame->setVisible(false);
    ui->frame->setGeometry(ui->frame->pos().x(),150,ui->frame->width(),ui->frame->height());
    has_activity = true;
}

void detailedwindow::on_button_visualizacion_clicked()
{
    ui->label->setText("Visualización de Parámetros");
    ui->tabWidget->setCurrentIndex(3);
    ui->button_parametros->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Visualizar azul.png);"
                    "border: none;"
                    "background-repeat: none;"
                    "background-position: center;");
    ui->button_evento->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Bitacora azul.png);;"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
    ui->button_descripcion->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Info azul.png);"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
    ui->button_visualizacion->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Ajustes blanco.png);"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");


    if(false == has_output_control)
    {
        ui->button_control->setStyleSheet("background-image: none;"
                        "border: none;"
                        "background-repeat: none;"
                        "background-position: center;");
    }
    else
    {
        ui->button_control->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Encendido azul.png);"
                         "border: none;"
                         "background-repeat: none;"
                         "background-position: center;");
    }

    /* Hide keyboard and text edit */
    ui->textEdit->setVisible(false);
    ui->key_frame->setVisible(false);
    ui->frame->setGeometry(ui->frame->pos().x(),150,ui->frame->width(),ui->frame->height());
    has_activity = true;
}

void detailedwindow::on_button_control_clicked()
{
    if(false == has_output_control)
    {
        return;
    }

    set_op_mode(ui->comboBox->currentIndex());

    ui->button_parametros->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Visualizar azul.png);"
                    "border: none;"
                    "background-repeat: none;"
                    "background-position: center;");
    ui->button_evento->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Bitacora azul.png);;"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
    ui->button_descripcion->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Info azul.png);"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");
    ui->button_visualizacion->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Ajustes azul.png);"
                     "border: none;"
                     "background-repeat: none;"
                     "background-position: center;");

    if(false == has_output_control)
    {
        ui->button_control->setStyleSheet("background-image: none;"
                        "border: none;"
                        "background-repeat: none;"
                        "background-position: center;");
    }
    else
    {
        ui->button_control->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Encendido blanco.png);"
                         "border: none;"
                         "background-repeat: none;"
                         "background-position: center;");

        ui->label->setText("Encendido de Motores");
        ui->tabWidget->setCurrentIndex(4);

        //Check token validity
        synch_output_state();

        if(false == get_validity_state())
        {
            if(NULL != login_d)
            {
                delete login_d;
            }
            login_d = new login_dialog(this);
        }
    }

    /* Hide keyboard and text edit */
    ui->textEdit->setVisible(false);
    ui->key_frame->setVisible(false);
    ui->frame->setGeometry(ui->frame->pos().x(),150,ui->frame->width(),ui->frame->height());
    has_activity = true;
}

void detailedwindow::checkBoxStateChanged(int a)
{
    qDebug() << "Toggle active show " << a;
    toggleParamActiveShow(a);
    has_activity = true;
}

void detailedwindow::out_checkBoxStateChanged(int a)
{
    if(ui->comboBox->currentIndex() == 0)
    {
        qDebug() << "Toggle output " << a;
        output_control_toggle(a);
    }
    has_activity = true;
}

void detailedwindow::update_params()
{
    if(true == init_completed)
    {
        tab_1_update();
        tab_2_update();
        tab_5_update();
    }
}


void detailedwindow::on_key_0_clicked() {ui->textEdit->insertPlainText("0");}
void detailedwindow::on_key_1_clicked() {ui->textEdit->insertPlainText("1");}
void detailedwindow::on_key_2_clicked() {ui->textEdit->insertPlainText("2");}
void detailedwindow::on_key_3_clicked() {ui->textEdit->insertPlainText("3");}
void detailedwindow::on_key_4_clicked() {ui->textEdit->insertPlainText("4");}
void detailedwindow::on_key_5_clicked() {ui->textEdit->insertPlainText("5");}
void detailedwindow::on_key_6_clicked() {ui->textEdit->insertPlainText("6");}
void detailedwindow::on_key_7_clicked() {ui->textEdit->insertPlainText("7");}
void detailedwindow::on_key_8_clicked() {ui->textEdit->insertPlainText("8");}
void detailedwindow::on_key_9_clicked() {ui->textEdit->insertPlainText("9");}

void detailedwindow::on_key_back_clicked()
{
    ui->textEdit->textCursor().deletePreviousChar();
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
    has_activity = true;
}

void detailedwindow::on_key_Reschedule_clicked()
{
    uint i;
    uint periodo;
    if(false == ui->key_frame->isVisible())
    {
        /* Show keyboard and text edit */
        ui->textEdit->setVisible(true);
        ui->key_frame->setVisible(true);
        ui->frame->setGeometry(ui->frame->pos().x(),70,ui->frame->width(),ui->frame->height());

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

    if(NULL != calendar_window)
    {
        delete calendar_window;
    }
    for(i = 0; i < rutinas_ptr->num_of_rutinas ; i++)
    {
        if(rutinas_ptr->id(i) == selected_id)
        {
            periodo = rutinas_ptr->periodo(i);
            break;
        }
    }
    calendar_window = new calendar(MainWindow::time, periodo, this);
    connect(calendar_window, SIGNAL(send_calendar_date(uint,QDate)), this, SLOT(receive_date(uint,QDate)));


    has_activity = true;
}

void detailedwindow::on_key_OK_clicked()
{
    uint i = 0;

    if(0 != selected_id)
    {
        qDebug() << "Button clicked ID: " << selected_id;
        for(i = 0; i < rutinas_ptr->num_of_rutinas ; i++)
        {
            if(rutinas_ptr->id(i) == selected_id)
            {
                qDebug() << "ID match at: " << i;

                if(reschedule_time > 0)
                {
                    rutinas_ptr->reschedule_rutina(i, reschedule_time);
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
    ui->frame->setGeometry(ui->frame->pos().x(),150,ui->frame->width(),ui->frame->height());
    ui->tabWidget->setCurrentIndex(1);
    has_activity = true;

}

void detailedwindow::tab_1_init(uint selected_type)
{
    parametros_mutex.lock();
    type_to_update = selected_type;

    QFont font_2("Typo Square Ligth Demo",10,1);

    uint i, param_id;
    uint fila = 0;

    //Add 2 columns
    ui->tableWidget_tab_1->clear();
    ui->tableWidget_tab_1->setRowCount(0);
    ui->tableWidget_tab_1->setColumnCount(2);
    ui->tableWidget_tab_1->setFont(font_2);
    ui->tableWidget_tab_1->setStyleSheet("color: white;"
                                   "background-color: black;"
                                   "gridline-color: black;");
    ui->tableWidget_tab_1->verticalHeader()->setVisible(false);
    ui->tableWidget_tab_1->horizontalHeader()->setVisible(false);

    switch(selected_type)
    {
    case 0:
        ui->filtro_fisicos->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Medidor azul.png);"
                                          "border: none;"
                                          "background-repeat: none;"
                                          "background-position: center;");
        ui->filtro_quimicos->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Matraz azul.png);"
                                          "border: none;"
                                          "background-repeat: none;"
                                          "background-position: center;");
        ui->filtro_electricos->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Clavija blanco.png);"
                                          "border: none;"
                                          "background-repeat: none;"
                                          "background-position: center;");

        for(i = 0; i < (quint32)detailed_elements[what_element]->list_elect->ids.size(); i++)
        {
            param_id = detailed_elements[what_element]->list_elect->ids.at(i);
    //        qDebug() << getParamName(param_id) <<" "<< param_id << " " << getParamValue(param_id);
            ui->tableWidget_tab_1->insertRow(fila);
            ui->tableWidget_tab_1->setItem(fila,0, new QTableWidgetItem(detailed_elements[what_element]->list_elect->names.at(i) + ":"));
            ui->tableWidget_tab_1->setItem(fila,1, new QTableWidgetItem(getParamValue_and_units(param_id)));
            fila++;
        }
        break;
    case 1:

        ui->filtro_fisicos->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Medidor blanco.png);"
                                          "border: none;"
                                          "background-repeat: none;"
                                          "background-position: center;");
        ui->filtro_quimicos->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Matraz azul.png);"
                                          "border: none;"
                                          "background-repeat: none;"
                                          "background-position: center;");
        ui->filtro_electricos->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Clavija azul.png);"
                                          "border: none;"
                                          "background-repeat: none;"
                                          "background-position: center;");

        for(i = 0; i < (quint32)detailed_elements[what_element]->list_phys->ids.size(); i++)
        {
            param_id = detailed_elements[what_element]->list_phys->ids.at(i);
    //        qDebug() << getParamName(param_id) <<" "<< param_id << " " << getParamValue(param_id);
            ui->tableWidget_tab_1->insertRow(fila);
            ui->tableWidget_tab_1->setItem(fila,0, new QTableWidgetItem(detailed_elements[what_element]->list_phys->names.at(i) + ":"));
            ui->tableWidget_tab_1->setItem(fila,1, new QTableWidgetItem(getParamValue_and_units(param_id)));
            fila++;
        }
        break;
    case 2:

        ui->filtro_fisicos->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Medidor azul.png);"
                                          "border: none;"
                                          "background-repeat: none;"
                                          "background-position: center;");
        ui->filtro_quimicos->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Matraz blanco.png);"
                                          "border: none;"
                                          "background-repeat: none;"
                                          "background-position: center;");
        ui->filtro_electricos->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Clavija azul.png);"
                                          "border: none;"
                                          "background-repeat: none;"
                                          "background-position: center;");

        for(i = 0; i < (quint32)detailed_elements[what_element]->list_chem->ids.size(); i++)
        {
            param_id = detailed_elements[what_element]->list_chem->ids.at(i);
    //        qDebug() << getParamName(param_id) <<" "<< param_id << " " << getParamValue(param_id);
            ui->tableWidget_tab_1->insertRow(fila);
            ui->tableWidget_tab_1->setItem(fila,0, new QTableWidgetItem(detailed_elements[what_element]->list_chem->names.at(i) + ":"));
            ui->tableWidget_tab_1->setItem(fila,1, new QTableWidgetItem(getParamValue_and_units(param_id)));
            fila++;
        }
        break;
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
    parametros_mutex.unlock();
}

void detailedwindow::tab_2_init()
{
    uint i = 0;
    QFont font("Typo Square Bold Demo",10,1);
    QStringList titulos;
    titulos << "ID" << "Rutina"; // Fecha is next

    QFont font1("Typo Square Italic Demo",12,1);

    QFont font2("Typo Square Italic Demo",10,1);
    QFont font3("Typo Square Regular Demo",8,1);
    QFont font4("Typo Square Regular Demo",10,1);


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
    ui->label_horas->setStyleSheet("color:white;");


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
    case ELEMENT_FILTRO:
        origentype = ORIGEN_FILTRO;
        break;
    case ELEMENT_FILTRO_BOMBA:
        origentype = ORIGEN_FILTRO_BOMBA;
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
    QFont font("Typo Square Ligth Demo",10,1);

    ui->description_label->setFont(font);
    ui->description_label->setText(detailed_elements[what_element]->description);
    ui->description_label->setStyleSheet("color: white;"
                                         "background-color: transparent;");
}

void detailedwindow::tab_4_init()
{
    uint i = 0;
    uint param_id;
    QFont font_2("Typo Square Ligth Demo",10,1);

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
    uint row, column;
    row = 0;
    column = 0;

    QFont font_2("Typo Square Ligth Demo",12,1);

    ui->comboBox->setStyleSheet("color: white;");

    check_lock();

    QCheckBox *box_motores;
    QSignalMapper *out_checkboxMapper = new QSignalMapper(this);
    for(i = 0; i < (quint32)detailed_elements[what_element]->out_config->ids.size(); i++)
    {
        box_motores = new QCheckBox(detailed_elements[what_element]->out_config->names.at(i));
        controls_ptr[i] = box_motores;
        box_motores->setFont(font_2);
        box_motores->setLayoutDirection(Qt::RightToLeft);

        if(true == get_validity_state())
        {
            box_motores->setEnabled(true);

//            if(1 == get_id_state(detailed_elements[what_element]->out_config->ids.at(i)).toInt())
            if(motor_state(detailed_elements[what_element]->out_config->ids_string.at(i)) !=
                    get_id_state(detailed_elements[what_element]->out_config->ids_string.at(i)).toInt())
            {
                box_motores->setStyleSheet("QCheckBox{"
                                           "color:white;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "border: none;"
                                           "}"
                                           "QCheckBox::indicator{"
                                           "image: url(:/iconos/screen800x600/iconos/Encendido blanco.png);"
                                           "border-width: 0px;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "}");
            }
            else if(1 == motor_state(detailed_elements[what_element]->out_config->ids_string.at(i)))
            {
//                box_motores->setChecked(true);
                box_motores->setStyleSheet("QCheckBox{"
                                           "color:white;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "border: none;"
                                           "}"
                                           "QCheckBox::indicator{"
                                           "image: url(:/iconos/screen800x600/iconos/Encendido verde.png);"
                                           "border-width: 0px;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "}");
            }
            else
            {
                box_motores->setStyleSheet("QCheckBox{"
                                           "color:white;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "border: none;"
                                           "}"
                                           "QCheckBox::indicator{"
                                           "image: url(:/iconos/screen800x600/iconos/Encendido azul.png);"
                                           "border-width: 0px;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "}");
            }
        }
        else
        {
            box_motores->setEnabled(false);
            box_motores->setStyleSheet("QCheckBox{"
                                       "color:white;"
                                       "width: 30px;"
                                       "height: 30px;"
                                       "border: none;"
                                       "}"
                                       "QCheckBox::indicator{"
                                       "image: url(:/iconos/screen800x600/iconos/Encendido gris.png);"
                                       "border-width: 0px;"
                                       "width: 30px;"
                                       "height: 30px;"
                                       "}");
        }

//        ui->verticalLayout_2->addWidget(box_motores);

        ui->gridLayout->addWidget(box_motores, row, column);
        row++;
        if(row >= 3)
        {
            row = 0;
            column++;
        }

        connect(box_motores, SIGNAL(clicked(bool)), out_checkboxMapper, SLOT(map()));
        out_checkboxMapper->setMapping(box_motores, detailed_elements[what_element]->out_config->ids.at(i));
    }


    // Connect all checkboxes to mapper
    connect(out_checkboxMapper, SIGNAL(mapped(int)), this, SLOT(out_checkBoxStateChanged(int)));

    //Init with elements selected
    ui->button_parametros->setStyleSheet("background-image: url(:/iconos/screen800x600/iconos/Visualizar blanco.png);"
                    "border: none;"
                    "background-repeat: none;"
                    "background-position: center;");

}

void detailedwindow::tab_1_update()
{
    parametros_mutex.lock();
    uint i, param_id;
    uint fila = 0;

    switch (type_to_update) {
    case 0:
        for(i = 0; i < (quint32)detailed_elements[what_element]->list_elect->ids.size(); i++)
        {
            param_id = detailed_elements[what_element]->list_elect->ids.at(i);
            ui->tableWidget_tab_1->setItem(fila,1, new QTableWidgetItem(getParamValue_and_units(param_id)));
            fila++;
        }
        break;
    case 1:
        for(i = 0; i < (quint32)detailed_elements[what_element]->list_phys->ids.size(); i++)
        {
            param_id = detailed_elements[what_element]->list_phys->ids.at(i);
            ui->tableWidget_tab_1->setItem(fila,1, new QTableWidgetItem(getParamValue_and_units(param_id)));
            fila++;
        }
        break;
    case 2:
        for(i = 0; i < (quint32)detailed_elements[what_element]->list_chem->ids.size(); i++)
        {
            param_id = detailed_elements[what_element]->list_chem->ids.at(i);
            ui->tableWidget_tab_1->setItem(fila,1, new QTableWidgetItem(getParamValue_and_units(param_id)));
            fila++;
        }
        break;
    default:
        break;
    }
    parametros_mutex.unlock();
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
//    check_lock();
    uint i = 0;
    QCheckBox *box_motores;
    for(i = 0; i < (quint32)detailed_elements[what_element]->out_config->ids.size(); i++)
    {
        box_motores = controls_ptr[i];
        if(true == get_validity_state())
        {
            box_motores->setEnabled(true);

//            qDebug() << "Value of " << detailed_elements[what_element]->out_config->ids_string.at(i) << " " << get_id_state(detailed_elements[what_element]->out_config->ids_string.at(i));
            if(motor_state(detailed_elements[what_element]->out_config->ids_string.at(i)) !=
                    get_id_state(detailed_elements[what_element]->out_config->ids_string.at(i)).toInt())
            {
                box_motores->setStyleSheet("QCheckBox{"
                                           "color:white;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "border: none;"
                                           "}"
                                           "QCheckBox::indicator{"
                                           "image: url(:/iconos/screen800x600/iconos/Encendido blanco.png);"
                                           "border-width: 0px;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "}");
            }
            else if(1 == motor_state(detailed_elements[what_element]->out_config->ids_string.at(i)))
            {
//                box_motores->setChecked(true);
                box_motores->setStyleSheet("QCheckBox{"
                                           "color:white;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "border: none;"
                                           "}"
                                           "QCheckBox::indicator{"
                                           "image: url(:/iconos/screen800x600/iconos/Encendido verde.png);"
                                           "border-width: 0px;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "}");
            }
            else
            {
                box_motores->setStyleSheet("QCheckBox{"
                                           "color:white;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "border: none;"
                                           "}"
                                           "QCheckBox::indicator{"
                                           "image: url(:/iconos/screen800x600/iconos/Encendido azul.png);"
                                           "border-width: 0px;"
                                           "width: 30px;"
                                           "height: 30px;"
                                           "}");
            }
        }
        else
        {
            box_motores->setEnabled(false);
            box_motores->setStyleSheet("QCheckBox{"
                                       "color:white;"
                                       "width: 30px;"
                                       "height: 30px;"
                                       "border: none;"
                                       "}"
                                       "QCheckBox::indicator{"
                                       "image: url(:/iconos/screen800x600/iconos/Encendido gris.png);"
                                       "border-width: 0px;"
                                       "width: 30px;"
                                       "height: 30px;"
                                       "}");

        }
    }

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
    ui->frame->setGeometry(ui->frame->pos().x(),70,ui->frame->width(),ui->frame->height());

    ui->textEdit->clear();

    for(i = 0; i < rutinas_ptr->num_of_rutinas ; i++)
    {
        if(rutinas_ptr->id(i) == selected_id)
        {
            ui->textEdit->setText(rutinas_ptr->texto_ayuda(i));
            break;
        }
    }
    has_activity = true;

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
//    validate_token(false);
    output_token_transfer(false);
    release_lock();
    this->close();
}

void detailedwindow::on_textEdit_selectionChanged()
{
    ui->key_Reschedule->setChecked(false);
    has_activity = true;

}


void detailedwindow::on_filtro_fisicos_clicked()
{
    this->tab_1_init(1);
}

void detailedwindow::on_filtro_quimicos_clicked()
{
    this->tab_1_init(2);
}

void detailedwindow::on_filtro_electricos_clicked()
{
    this->tab_1_init(0);
}

void detailedwindow::checkActivity()
{
    if(true == has_activity)
    {
        // Hay actividad, rearmar timer
        has_activity = false;
        QTimer::singleShot(MAX_INACTIVITY_TIMEOUT, this, SLOT(checkActivity()));
    }
    else
    {
        output_token_transfer(false);
        release_lock();
        this->close();
    }
}

void detailedwindow::receive_date(uint hora, QDate date)
{
    QDateTime *temp = new QDateTime(date);
    ui->label_horas->setText(date.toString("yyyy-MM-dd") + " " + QString::number(hora) + ":00");

    *temp = temp->addSecs(60 * 60 * hora);
    reschedule_time = temp->toTime_t();
    delete temp;
}


void detailedwindow::check_lock()
{
//    static bool last_validity_state = false;
//    bool state = get_validity_state();
//    if(last_validity_state != state)
//    {
//        if(true == state)
//        {
//            ui->button_candado->setStyleSheet("border-image: url(:/iconos/screen800x600/iconos/unlocked.png);"
//                                           "border: none;"
//                                           "background-repeat: none;"
//                                           "background-position: center;");
//        }
//        else
//        {
//            ui->button_candado->setStyleSheet("border-image: url(:/iconos/screen800x600/iconos/locked.png);"
//                                           "border: none;"
//                                           "background-repeat: none;"
//                                           "background-position: center;");
//        }
//    }


    //    last_validity_state = state;
}

void detailedwindow::set_op_mode(uint mode)
{
    QString str;
    if(0xFF == mode)
    {
        str = "04";
    }
    else if(0 == mode)
    {
        str = "03";
    }
    else
    {
        if((2 == mode_4600) && (ELEMENT_REACTOR == what_element))
        {
            str = "02";
        }
        else
        {
            str = "01";
        }
    }

    switch(what_element)
    {
    case ELEMENT_REGULADOR:
        output_op_mode(3600, str);
        break;
    case ELEMENT_REACTOR:
        output_op_mode(4600, str);
        break;
    case ELEMENT_CLARIFICADOR:
        output_op_mode(5600, str);
        break;
    case ELEMENT_CLORADOR:
        break;
    case ELEMENT_FILTRO:
        output_op_mode(9600, str);
        break;
    case ELEMENT_FILTRO_BOMBA:
        output_op_mode(9700, str);
        break;
    default:
        break;
    }
}

void detailedwindow::read_op_mode()
{
    QString str;
    switch(what_element)
    {
    case ELEMENT_REGULADOR:
        str = getParamValue(0x3600);
        break;
    case ELEMENT_REACTOR:
        str = getParamValue(0x4600);
        break;
    case ELEMENT_CLARIFICADOR:
        str = getParamValue(0x5600);
        break;
    case ELEMENT_CLORADOR:
        break;
    case ELEMENT_FILTRO:
        str = getParamValue(0x9600);
        break;
    case ELEMENT_FILTRO_BOMBA:
        str = getParamValue(0x9700);
        break;
    default:
        break;
    }

    if("03" == str | "3" == str)
    {
        ui->comboBox->setCurrentIndex(0);
    }
    else
    {
        ui->comboBox->setCurrentIndex(1);
    }

}

void detailedwindow::on_comboBox_currentIndexChanged(int index)
{
    set_op_mode(index);
}

void detailedwindow::checkStop()
{
    if(true == ui->pushButton->isDown())
    {
        if(!stop_pressed)
        {
            emergency_stop(true);
            ui->pushButton->setChecked(true);
            stop_pressed = true;

            stop_button_animation(true);
        }
        else
        {
            emergency_stop(false);
            ui->pushButton->setChecked(false);

            stop_pressed = false;
            stop_button_animation(false);
        }
    }
    wating_timer = false;
}

void detailedwindow::on_pushButton_pressed()
{
    if(wating_timer == false)
    {
        if(get_id_state("0902").toInt() == 0)
        {
            QTimer::singleShot(2500, this, SLOT(checkStop()));
            stop_button_animation(true);
        }
        else
        {
            QTimer::singleShot(2500, this, SLOT(checkStop()));
            ui->pushButton->setChecked(false);
        }
        wating_timer = true;
    }
}

void detailedwindow::on_pushButton_released()
{
    if(stop_pressed == true)
    {
        ui->pushButton->setChecked(true);
        stop_button_animation(true);
    }
    else
    {
        ui->pushButton->setChecked(false);
        stop_button_animation(false);
    }
}

void detailedwindow::stop_button_animation(bool state)
{
    if(true == state)
    {
        QMovie *mv;
        mv = new QMovie(":/iconos/screen800x600/iconos/Stop-Boton-Activo.gif");
        ui->stop_button_image->setAttribute(Qt::WA_NoSystemBackground);
        mv->start();
        ui->stop_button_image->setMovie(mv);

        ui->pushButton->setStyleSheet("background-color:transparent;"
                                             "background-image: url(:/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/none.png);"
                                             "background-position: center;"
                                             "background-repeat:none;"
                                             "border:none;");
        this->update();
    }
    else
    {
        ui->stop_button_image->setMovie(NULL);
        ui->pushButton->setStyleSheet("background-color:transparent;"
                                             "background-image: url(:/iconos/screen800x600/iconos/BOTON.png);"
                                             "background-position: center;"
                                             "background-repeat:none;"
                                             "border:none;");

        this->update();
    }
}

void detailedwindow::stop_button_animation_module(bool state)
{
    if(true == state)
    {
        QMovie *mv;
        mv = new QMovie(":/iconos/screen800x600/iconos/Stop-Boton-Activo-Small.gif");
        ui->stop_button_image_modulo->setAttribute(Qt::WA_NoSystemBackground);
        mv->start();
        ui->stop_button_image_modulo->setMovie(mv);

        ui->pushButton_modulo->setStyleSheet("background-color:transparent;"
                                             "background-image: url(:/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/none.png);"
                                             "background-position: center;"
                                             "background-repeat:none;"
                                             "border:none;");
        this->update();
    }
    else
    {
        ui->stop_button_image_modulo->setMovie(NULL);
        ui->pushButton_modulo->setStyleSheet("background-color:transparent;"
                                             "background-image: url(:/iconos/screen800x600/iconos/BOTON_small.png);"
                                             "background-position: center;"
                                             "background-repeat:none;"
                                             "border:none;");

        this->update();
    }
}

void detailedwindow::checkStop_modulo()
{
    if(true == ui->pushButton_modulo->isDown())
    {
        if(!stop_pressed_modulo)
        {
//            emergency_stop(true);
            set_op_mode(0xFF);
            ui->pushButton_modulo->setChecked(true);
            stop_pressed_modulo = true;

            stop_button_animation_module(true);
        }
        else
        {
//            emergency_stop(false);
            set_op_mode(ui->comboBox->currentIndex());
            ui->pushButton_modulo->setChecked(false);

            stop_pressed_modulo = false;
            stop_button_animation_module(false);
        }
    }
    wating_timer_modulo = false;
}

void detailedwindow::on_pushButton_modulo_pressed()
{
    if(wating_timer_modulo == false)
    {
        if(false == stop_op_mode())
        {
            QTimer::singleShot(2500, this, SLOT(checkStop_modulo()));
            stop_button_animation_module(true);
        }
        else
        {
            QTimer::singleShot(2500, this, SLOT(checkStop_modulo()));
            ui->pushButton_modulo->setChecked(false);
        }
        wating_timer_modulo = true;
    }
}

void detailedwindow::on_pushButton_modulo_released()
{
    if(stop_pressed_modulo == true)
    {
        ui->pushButton_modulo->setChecked(true);
        stop_button_animation_module(true);
    }
    else
    {
        ui->pushButton_modulo->setChecked(false);
        stop_button_animation_module(false);
    }
}

bool detailedwindow::stop_op_mode()
{
    bool ret = false;
    QString str;
    switch(what_element)
    {
    case ELEMENT_REGULADOR:
        str = get_id_state("3600");
        break;
    case ELEMENT_REACTOR:
        str = get_id_state("4600");
        break;
    case ELEMENT_CLARIFICADOR:
        str = get_id_state("5600");
        break;
    case ELEMENT_CLORADOR:
        break;
    case ELEMENT_FILTRO:
        str = get_id_state("9600");
        break;
    case ELEMENT_FILTRO_BOMBA:
        str = get_id_state("9700");
        break;
    default:
        break;
    }

    if(str == "4" || str == "04")
    {
        ret = true;
    }

    return ret;
}
