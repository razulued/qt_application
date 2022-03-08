#include "detailedwindow.h"
#include "ui_detailedwindow.h"
#include <QListView>
#include <QFontDatabase>
#include <QCheckBox>
#include <QTableWidget>
#include "parameters.h"
#include <QDebug>
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
#include "records.h"
#include "mainwindow.h"

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

detailed_window_elements_t details_11=
{
    QObject::tr("Carcamo"),

    ":/images/images/detail_regulador.png",

    QObject::tr("Dado el nivel de arrastre de la línea de drenaje es necesario "
    "instalar un cárcamo de bombeo que permita elevar las aguas residuales desde "
    "el nivel del drenaje hasta el tanque regulador."),

    &MainWindow::conf_car_elect,

    &MainWindow::conf_car_fisic,

    &MainWindow::conf_car_quimic,

    &MainWindow::car_outputs,
};



detailed_window_elements_t *detailed_elements[]=
{
    &details_11,
};

detailedwindow::detailedwindow(detailed_elements_t element, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailedwindow)
{
    ui->setupUi(this);

    what_element = element;

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

    QString nombres[] = {
        tr("Regulador"),
        tr("Reactor Biológico"),
        tr("Clarificador"),
        tr("Clorador"),
        tr("Digestor de lodos"),
        tr("Deshidratador"),
        tr("Afluente"),
        tr("Efluente"),
        tr("Filtro"),
        tr("Bomba Alimentación"),
        tr("Cárcamo"),
    };

    // Nombre Del elemento
    ui->nombre->setFont(font_2);
    ui->nombre->setStyleSheet("color: black;"
                              "background-color: transparent;");
//    ui->nombre->setText(detailed_elements[element]->name);
    ui->nombre->setText(nombres[element]);


    ui->imagen->setStyleSheet("border-image: url("+detailed_elements[element]->image+");"
                            "background-color: transparent;");

    // Nombre del detalle
    ui->label->setFont(font);
    ui->label->setStyleSheet("color: white;"
                             "background-color: transparent;");


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

    ui->textEdit->setVisible(false);
    ui->key_frame->setVisible(false);
    ui->frame->setGeometry(ui->frame->pos().x(),150,ui->frame->width(),ui->frame->height());

    // Start timer
    QTimer::singleShot(MAX_INACTIVITY_TIMEOUT, this, SLOT(checkActivity()));


    //Hide window bars and buttons
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
//    this->setAttribute(Qt::WA_DeleteOnClose);

    this->move(parent->pos());

    reschedule_time = 0;
    init_completed = true;
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
    ui->label->setText(tr("Parámetros"));
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
    ui->label->setText(tr("Evento"));
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
    ui->label->setText(tr("Descripción"));
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
    ui->label->setText(tr("Visualización de Parámetros"));
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

        ui->label->setText(tr("Encendido de Motores"));
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
    if(ui->comboBox->currentIndex()!= CONTROL_AUTOMATICO)
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

}

void detailedwindow::on_key_OK_clicked()
{

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
    ui->tableWidget_tab_1->setFocusPolicy(Qt::NoFocus);
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
    titulos << tr("ID") << tr("Rutina"); // Fecha is next

    QFont font1("Typo Square Italic Demo",12,1);

    QFont font2("Typo Square Italic Demo",10,1);
    QFont font3("Typo Square Regular Demo",8,1);
    QFont font4("Typo Square Regular Demo",10,1);

    QFont ok_font("Typo Square Bold Demo",10,1);
    ui->key_OK->setFont(ok_font);

    QFont paro_font("Typo Square Bold Demo",14,1);
    ui->label_paro_general->setFont(paro_font);

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
}

void detailedwindow::tab_3_init()
{
    QFont font("Typo Square Ligth Demo",10,1);
    QString description[] = {
        /*Regulador*/
        tr("Amortigua los picos de flujo y carga, de manera que la planta de tratamiento reciba de manera constante un flujo "
            "igual al de diseño y su eficiencia no se vea afectada. Tiene volumen suficiente para poder almacenar el flujo"
            "generado durante las horas pico"),
        /*Reactor*/
        tr("Tratamiento secundario donde se elimina la materia orgánica por procesos de oxidación biológica; es decir, poniendo "
            "en contacto las aguas residuales con una biomasa de microorganismos que la depuran."),
        /*Clarificador*/
        tr("Recibe el afluente del reactor biológico, conformado por agua y lodo biológico. Los lodos biológicos y los sólidos "
            "suspendidos se sedimentan, separandose del agua."),
        /*Clorador*/
        tr("Proceso de desinfección de hipoclorito de sodio/calcio líquido/sólido. Se eliminan los microorganismos presentes."),
        /*Digestor de lodos*/
        tr("Recibe los lodos biológicos generados en exeso y separados en el clarificador secundario; estos se oxidan biológicamente"
            " hasta obtener una reducción de 40 a 60% en los sólidos volátiles presentes, logrando así una estabilización de lodos."),
        /*Deshidratador*/
        tr("Lechos de secado, filtro horizontal de flujo descendiente empacado con gravas y arena. Sobre este se vierte una cantidad de lodo y "
            "se permite su infiltración, dejando secar los lodos"),
        /*Afluente*/
        tr("Agua residual sanitaria"),
        /*Efluente*/
        tr("Agua tratada"),
        /*Filtro*/
        tr("Equipo de filtración terciaria. Utilizando una tela especializada como medio fijo filtrante logra la remoción "
            "adicional de sólidos así como el color ámbar característico de las aguas tratadas. "
            "Dadas las características de la tela filtrante, no se requiere la acumulación de material ni la formación de "
            "una manta filtrante a fin de lograr el pulimento deseado."),
        /* Bomba de alimentacion */
        tr("Agregar descripción"),
        tr("Dado el nivel de arrastre de la línea de drenaje es necesario "
        "instalar un cárcamo de bombeo que permita elevar las aguas residuales desde "
        "el nivel del drenaje hasta el tanque regulador."),
    };

    ui->description_label->setFont(font);
    ui->description_label->setText(description[what_element]);
    ui->description_label->setStyleSheet("color: white;"
                                         "background-color: transparent;");
}

void detailedwindow::tab_4_init()
{
    uint i = 0;
    uint param_id;
    QFont font_2("Typo Square Ligth Demo",10,1);

    QSignalMapper *checkboxMapper = new QSignalMapper(this);

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
        box_motores->setFocusPolicy(Qt::NoFocus);

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

}

void detailedwindow::delete_row(uint row, QTableWidget *table)
{
    table->removeRow(row);
}

void detailedwindow::on_ayuda_btn_clicked()
{

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

void detailedwindow::receive_date(uint hora, QDate date, QDateTime datetime)
{
//    QDateTime *temp = new QDateTime(date);
//    ui->label_horas->setText(date.toString("yyyy-MM-dd") + " " + QString::number(hora) + ":00");

//    *temp = temp->addSecs(60 * 60 * hora);
//    reschedule_time = temp->toTime_t();
//    delete temp;


    QDateTime *temp = new QDateTime(date);
    ui->label_horas->setText(date.toString("yyyy-MM-dd") + " " + QString::number(hora) + ":00");

    const QTimeZone zone("UTC-06:00");
    datetime.setTimeZone(zone);

    *temp = temp->addSecs(60 * 60 * hora);
    reschedule_time = datetime.toTime_t();

    if(reschedule_time < MainWindow::time.toTime_t())
    {
        ui->label_horas->setText("");
        ui->key_OK->setText(tr("Completado"));
        selected_id = 0;
        reschedule_time = 0;
    }
    else
    {
        ui->key_OK->setText(tr("Reagendar"));
    }
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

void detailedwindow::save_stop_status(uint mode)
{
    if((ELEMENT_REACTOR == what_element))
    {
        write_parameter("mot_stat/m4600_stop.bin", mode);
    }
}

void detailedwindow::set_op_mode(uint mode)
{
    QString str;

    if(CONTROL_STOP == mode)
    {
        // PARO
        str = "04";
    }
    else if(CONTROL_AUTOMATICO == mode)
    {
        // AUTOMATICO
        if((2 == mode_4600) && (ELEMENT_REACTOR == what_element))
        {
            str = "02";
        }
        else
        {
            str = "01";
        }

        // Make sure STOP button is not active
        ui->pushButton_modulo->setChecked(false);
        stop_pressed_modulo = false;
        stop_button_animation_module(false);
        wating_timer_modulo = false;
    }
    else if(CONTROL_MANUAL == mode)
    {
        // MANUAL OVERRIDE
        str = "03";

        // Make sure STOP button is not active
        ui->pushButton_modulo->setChecked(false);
        stop_pressed_modulo = false;
        stop_button_animation_module(false);
        wating_timer_modulo = false;
    }

    switch(what_element)
    {
    case ELEMENT_REGULADOR:
        output_op_mode("3E00", str);/* Antes 3600 */
        break;
    case ELEMENT_REACTOR:
        output_op_mode("4600", str);
        break;
    case ELEMENT_CLARIFICADOR:
        output_op_mode("5600", str);
        break;
    case ELEMENT_CLORADOR:
        break;
    case ELEMENT_FILTRO:
        output_op_mode("9600", str);
        break;
    case ELEMENT_FILTRO_BOMBA:
        output_op_mode("9700", str);
        break;
    case ELEMENT_CARCAMO:
        output_op_mode("3600", str);
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
        str = getParamValue(0x3E00);  /* Antes 3600*/
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
    case ELEMENT_CARCAMO:
        str = getParamValue(0x3600);
        break;
    default:
        break;
    }

    if("03" == str | "3" == str)
    {
        ui->comboBox->setCurrentIndex(CONTROL_MANUAL);
    }
    else if("02" == str | "2" == str |
       "01" == str | "1" == str)
    {
        ui->comboBox->setCurrentIndex(CONTROL_AUTOMATICO);
    }
    else if("04" == str | "4" == str)
    {
        ui->comboBox->setCurrentIndex(CONTROL_STOP);
    }
    else
    {
        // Unknown, set stop
        ui->comboBox->setCurrentIndex(CONTROL_STOP);
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
            set_op_mode(CONTROL_STOP);
            ui->pushButton_modulo->setChecked(true);
            stop_pressed_modulo = true;
            stop_button_animation_module(true);
            ui->comboBox->setCurrentIndex(CONTROL_STOP);
        }
        else
        {
            // Will stay the same stop state
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
            QTimer::singleShot(2000, this, SLOT(checkStop_modulo()));
            stop_button_animation_module(true);
        }
        else
        {
            QTimer::singleShot(2000, this, SLOT(checkStop_modulo()));
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
        str = get_id_state("3E00"); /* Antes 3600 */
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
    case ELEMENT_CARCAMO:
        str = get_id_state("3600");
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

void detailedwindow::activity_is_completed(uint id)
{

}

void detailedwindow::on_pushButton_modulo_clicked()
{

}
