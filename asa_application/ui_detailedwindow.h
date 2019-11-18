/********************************************************************************
** Form generated from reading UI file 'detailedwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILEDWINDOW_H
#define UI_DETAILEDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_detailedwindow
{
public:
    QFrame *frame;
    QLabel *label;
    QPushButton *button_parametros;
    QPushButton *button_evento;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QTableWidget *tableWidget_tab_1;
    QPushButton *filtro_fisicos;
    QPushButton *filtro_quimicos;
    QPushButton *filtro_electricos;
    QWidget *tab_2;
    QTableWidget *tableWidget;
    QWidget *tab_3;
    QLabel *description_label;
    QWidget *tab_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *tab_5;
    QComboBox *comboBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_modulo;
    QLabel *stop_button_image_modulo;
    QWidget *tab_6;
    QTableWidget *tableWidget_2;
    QLabel *evento_gif;
    QLabel *explicacion;
    QPushButton *key_OK;
    QPushButton *key_Reschedule;
    QLabel *label_horas;
    QPushButton *ayuda_btn;
    QPushButton *button_visualizacion;
    QPushButton *closeButton;
    QPushButton *button_control;
    QLabel *nombre;
    QLabel *imagen;
    QPushButton *button_descripcion;
    QFrame *key_frame;
    QPushButton *key_0;
    QPushButton *key_4;
    QPushButton *key_5;
    QPushButton *key_7;
    QPushButton *key_8;
    QPushButton *key_1;
    QPushButton *key_6;
    QPushButton *key_back;
    QPushButton *key_3;
    QPushButton *key_9;
    QPushButton *key_2;
    QPushButton *key_Q;
    QPushButton *key_W;
    QPushButton *key_E;
    QPushButton *key_R;
    QPushButton *key_T;
    QPushButton *key_Y;
    QPushButton *key_U;
    QPushButton *key_I;
    QPushButton *key_P;
    QPushButton *key_O;
    QPushButton *key_A;
    QPushButton *key_L;
    QPushButton *key_H;
    QPushButton *key_G;
    QPushButton *key_F;
    QPushButton *key_S;
    QPushButton *key_D;
    QPushButton *key_J;
    QPushButton *key_K;
    QPushButton *key_dot;
    QPushButton *key_slash;
    QPushButton *key_plus;
    QPushButton *key_minus;
    QPushButton *key_X;
    QPushButton *key_Z;
    QPushButton *key_M;
    QPushButton *key_C;
    QPushButton *key_V;
    QPushButton *key_B;
    QPushButton *key_N;
    QPushButton *key_comma;
    QPushButton *key_space;
    QPushButton *key_enter;
    QPushButton *key_mayus;
    QTextEdit *textEdit;
    QLabel *stop_button_image;
    QPushButton *pushButton;
    QLabel *label_paro_general;

    void setupUi(QDialog *detailedwindow)
    {
        if (detailedwindow->objectName().isEmpty())
            detailedwindow->setObjectName(QStringLiteral("detailedwindow"));
        detailedwindow->resize(800, 600);
        detailedwindow->setMinimumSize(QSize(800, 600));
        detailedwindow->setMaximumSize(QSize(800, 600));
        detailedwindow->setStyleSheet(QLatin1String("QCheckBox{\n"
"color:white;\n"
"}\n"
""));
        frame = new QFrame(detailedwindow);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(150, 70, 521, 261));
        frame->setStyleSheet(QLatin1String("#frame{\n"
"background-image: url(:/iconos/screen800x600/iconos/Cuadro pantalla.png);\n"
"background-repeat: none;\n"
"border: none;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 20, 281, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QStringLiteral("color:white"));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        button_parametros = new QPushButton(frame);
        button_parametros->setObjectName(QStringLiteral("button_parametros"));
        button_parametros->setGeometry(QRect(20, 200, 31, 45));
        button_parametros->setFocusPolicy(Qt::NoFocus);
        button_parametros->setStyleSheet(QLatin1String("#button_parametros{\n"
"background-image: url(:/iconos/screen800x600/iconos/Visualizar azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        button_parametros->setCheckable(false);
        button_evento = new QPushButton(frame);
        button_evento->setObjectName(QStringLiteral("button_evento"));
        button_evento->setGeometry(QRect(59, 200, 31, 45));
        button_evento->setFocusPolicy(Qt::NoFocus);
        button_evento->setStyleSheet(QLatin1String("#button_evento{\n"
"background-image: url(:/iconos/screen800x600/iconos/Bitacora azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        button_evento->setCheckable(false);
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(200, 40, 305, 208));
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QLatin1String("#tabWidget { \n"
"background-color: transparent;\n"
"border-image: none;\n"
"background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
" } \n"
"\n"
"QTabBar::tab {\n"
"background-color: transparent;\n"
"border: none;\n"
"}"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setTabBarAutoHide(false);
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        tableWidget_tab_1 = new QTableWidget(tab_1);
        tableWidget_tab_1->setObjectName(QStringLiteral("tableWidget_tab_1"));
        tableWidget_tab_1->setGeometry(QRect(10, 30, 281, 161));
        filtro_fisicos = new QPushButton(tab_1);
        filtro_fisicos->setObjectName(QStringLiteral("filtro_fisicos"));
        filtro_fisicos->setGeometry(QRect(180, 0, 31, 31));
        filtro_fisicos->setFocusPolicy(Qt::NoFocus);
        filtro_fisicos->setStyleSheet(QLatin1String("#filtro_fisicos{\n"
"background-image: url(:/iconos/screen800x600/iconos/Medidor azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        filtro_fisicos->setCheckable(false);
        filtro_quimicos = new QPushButton(tab_1);
        filtro_quimicos->setObjectName(QStringLiteral("filtro_quimicos"));
        filtro_quimicos->setGeometry(QRect(220, 0, 31, 31));
        filtro_quimicos->setFocusPolicy(Qt::NoFocus);
        filtro_quimicos->setStyleSheet(QLatin1String("#filtro_quimicos{\n"
"background-image: url(:/iconos/screen800x600/iconos/Matraz azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        filtro_quimicos->setCheckable(false);
        filtro_electricos = new QPushButton(tab_1);
        filtro_electricos->setObjectName(QStringLiteral("filtro_electricos"));
        filtro_electricos->setGeometry(QRect(260, 0, 31, 31));
        filtro_electricos->setFocusPolicy(Qt::NoFocus);
        filtro_electricos->setStyleSheet(QLatin1String("#filtro_electricos{\n"
"background-image: url(:/iconos/screen800x600/iconos/Clavija azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        filtro_electricos->setCheckable(false);
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableWidget = new QTableWidget(tab_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 301, 191));
        tableWidget->setGridStyle(Qt::SolidLine);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        description_label = new QLabel(tab_3);
        description_label->setObjectName(QStringLiteral("description_label"));
        description_label->setGeometry(QRect(10, 10, 291, 171));
        description_label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        description_label->setWordWrap(true);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        scrollArea = new QScrollArea(tab_4);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 301, 191));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 297, 187));
        scrollArea->setWidget(scrollAreaWidgetContents);
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        comboBox = new QComboBox(tab_5);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(8, 10, 161, 22));
        comboBox->setFocusPolicy(Qt::NoFocus);
        gridLayoutWidget = new QWidget(tab_5);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 40, 291, 151));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_modulo = new QPushButton(tab_5);
        pushButton_modulo->setObjectName(QStringLiteral("pushButton_modulo"));
        pushButton_modulo->setGeometry(QRect(260, 0, 40, 40));
        pushButton_modulo->setFocusPolicy(Qt::NoFocus);
        pushButton_modulo->setStyleSheet(QLatin1String("#pushButton_modulo\n"
"{\n"
"background-color:transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/BOTON_small.png);\n"
"background-position: center;\n"
"background-repeat: none;\n"
"border: none;\n"
"}\n"
"/*#pushButton::pressed\n"
"{\n"
"background-color:transparent;\n"
"border-image: url(:/iconos/screen800x600/iconos/BOTON 2.png);\n"
"background-position: center;\n"
"background-repeat:none;\n"
"}\n"
"#pushButton::checked\n"
"{\n"
"background-color:transparent;\n"
"border-image: url(:/iconos/screen800x600/iconos/BOTON 2.png);\n"
"background-position: center;\n"
"background-repeat:none;\n"
"}*/"));
        pushButton_modulo->setCheckable(true);
        pushButton_modulo->setChecked(false);
        stop_button_image_modulo = new QLabel(tab_5);
        stop_button_image_modulo->setObjectName(QStringLiteral("stop_button_image_modulo"));
        stop_button_image_modulo->setGeometry(QRect(260, 0, 40, 40));
        tabWidget->addTab(tab_5, QString());
        stop_button_image_modulo->raise();
        comboBox->raise();
        gridLayoutWidget->raise();
        pushButton_modulo->raise();
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tableWidget_2 = new QTableWidget(tab_6);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(0, 0, 301, 51));
        evento_gif = new QLabel(tab_6);
        evento_gif->setObjectName(QStringLiteral("evento_gif"));
        evento_gif->setGeometry(QRect(70, 107, 161, 61));
        evento_gif->setStyleSheet(QLatin1String("#evento_gif\n"
"{\n"
"background-image: url(:/iconos/screen800x600/iconos/Play azul.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"border-style: solid;\n"
"border-color: gray;\n"
"border-width: 1px;\n"
"}\n"
"\n"
"#evento_gif::pressed\n"
"{\n"
"background-image: url(:/iconos/screen800x600/iconos/Play blanco.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        explicacion = new QLabel(tab_6);
        explicacion->setObjectName(QStringLiteral("explicacion"));
        explicacion->setGeometry(QRect(4, 53, 271, 51));
        explicacion->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        key_OK = new QPushButton(tab_6);
        key_OK->setObjectName(QStringLiteral("key_OK"));
        key_OK->setGeometry(QRect(200, 166, 81, 31));
        key_OK->setFocusPolicy(Qt::NoFocus);
        key_OK->setStyleSheet(QLatin1String("#key_OK{ \n"
"background-image: url(:/iconos/screen800x600/iconos/Listo azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_OK::pressed{ \n"
"background-image: url(:/iconos/screen800x600/iconos/Listo blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_OK->setCheckable(false);
        key_Reschedule = new QPushButton(tab_6);
        key_Reschedule->setObjectName(QStringLiteral("key_Reschedule"));
        key_Reschedule->setGeometry(QRect(10, 166, 151, 31));
        key_Reschedule->setFocusPolicy(Qt::NoFocus);
        key_Reschedule->setStyleSheet(QLatin1String("#key_Reschedule{ \n"
"background-image: url(:/iconos/screen800x600/iconos/Posponer azul largo.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_Reschedule::checked{ \n"
"background-image: url(:/iconos/screen800x600/iconos/Posponer blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_Reschedule->setCheckable(false);
        key_Reschedule->setChecked(false);
        label_horas = new QLabel(tab_6);
        label_horas->setObjectName(QStringLiteral("label_horas"));
        label_horas->setGeometry(QRect(14, 172, 118, 18));
        ayuda_btn = new QPushButton(tab_6);
        ayuda_btn->setObjectName(QStringLiteral("ayuda_btn"));
        ayuda_btn->setGeometry(QRect(270, 73, 31, 31));
        ayuda_btn->setStyleSheet(QLatin1String("#ayuda_btn{ \n"
"background-image: url(:/iconos/screen800x600/iconos/Ayuda azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#ayuda_btn::pressed{ \n"
"background-image: url(:/iconos/screen800x600/iconos/Ayuda blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        tabWidget->addTab(tab_6, QString());
        button_visualizacion = new QPushButton(frame);
        button_visualizacion->setObjectName(QStringLiteral("button_visualizacion"));
        button_visualizacion->setGeometry(QRect(134, 200, 31, 45));
        button_visualizacion->setFocusPolicy(Qt::NoFocus);
        button_visualizacion->setStyleSheet(QLatin1String("#button_visualizacion{\n"
"background-image: url(:/iconos/screen800x600/iconos/Ajustes azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        button_visualizacion->setCheckable(false);
        closeButton = new QPushButton(frame);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(470, 10, 41, 31));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        closeButton->setFont(font1);
        closeButton->setFocusPolicy(Qt::NoFocus);
        closeButton->setStyleSheet(QLatin1String("#closeButton { \n"
"background-color: transparent;\n"
"/*border-image: url(:/iconos/images/Iconos/close-x.png);*/\n"
"background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
"margin:5px;\n"
" } \n"
""));
        closeButton->setCheckable(false);
        closeButton->setAutoDefault(false);
        closeButton->setFlat(false);
        button_control = new QPushButton(frame);
        button_control->setObjectName(QStringLiteral("button_control"));
        button_control->setGeometry(QRect(168, 200, 31, 45));
        button_control->setFocusPolicy(Qt::NoFocus);
        button_control->setStyleSheet(QLatin1String("#button_control{ \n"
"background-image: url(:/iconos/screen800x600/iconos/Encendido azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        button_control->setCheckable(false);
        nombre = new QLabel(frame);
        nombre->setObjectName(QStringLiteral("nombre"));
        nombre->setGeometry(QRect(21, -3, 261, 31));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        nombre->setFont(font2);
        nombre->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        nombre->setWordWrap(true);
        imagen = new QLabel(frame);
        imagen->setObjectName(QStringLiteral("imagen"));
        imagen->setEnabled(false);
        imagen->setGeometry(QRect(15, 50, 181, 161));
        imagen->setStyleSheet(QLatin1String("#imagen { \n"
"background-color: transparent;\n"
"border-image: url(:/images/images/detail_deshidratador.png);\n"
"background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        button_descripcion = new QPushButton(frame);
        button_descripcion->setObjectName(QStringLiteral("button_descripcion"));
        button_descripcion->setGeometry(QRect(97, 200, 31, 45));
        button_descripcion->setFocusPolicy(Qt::NoFocus);
        button_descripcion->setStyleSheet(QLatin1String("#button_descripcion{\n"
"background-image: url(:/iconos/screen800x600/iconos/Info azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        button_descripcion->setCheckable(false);
        key_frame = new QFrame(detailedwindow);
        key_frame->setObjectName(QStringLiteral("key_frame"));
        key_frame->setGeometry(QRect(60, 420, 691, 181));
        key_frame->setStyleSheet(QLatin1String("#key_frame\n"
"{\n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/fondo teclado.png);\n"
"background-repeat:none;\n"
"/*background-color: black;*/\n"
"border:none;\n"
"}"));
        key_frame->setFrameShape(QFrame::StyledPanel);
        key_frame->setFrameShadow(QFrame::Raised);
        key_0 = new QPushButton(key_frame);
        key_0->setObjectName(QStringLiteral("key_0"));
        key_0->setGeometry(QRect(556, 132, 41, 41));
        key_0->setFocusPolicy(Qt::NoFocus);
        key_0->setStyleSheet(QLatin1String("#key_0{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/0 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_0::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/0 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_0->setCheckable(false);
        key_4 = new QPushButton(key_frame);
        key_4->setObjectName(QStringLiteral("key_4"));
        key_4->setGeometry(QRect(511, 49, 41, 41));
        key_4->setFocusPolicy(Qt::NoFocus);
        key_4->setStyleSheet(QLatin1String("#key_4{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/4 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_4::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/4 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_4->setCheckable(false);
        key_5 = new QPushButton(key_frame);
        key_5->setObjectName(QStringLiteral("key_5"));
        key_5->setGeometry(QRect(554, 49, 41, 41));
        key_5->setFocusPolicy(Qt::NoFocus);
        key_5->setStyleSheet(QLatin1String("#key_5{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/5 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_5::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/5 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_5->setCheckable(false);
        key_7 = new QPushButton(key_frame);
        key_7->setObjectName(QStringLiteral("key_7"));
        key_7->setGeometry(QRect(511, 8, 41, 41));
        key_7->setFocusPolicy(Qt::NoFocus);
        key_7->setStyleSheet(QLatin1String("#key_7{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/7 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_7::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/7 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_7->setCheckable(false);
        key_8 = new QPushButton(key_frame);
        key_8->setObjectName(QStringLiteral("key_8"));
        key_8->setGeometry(QRect(555, 8, 41, 41));
        key_8->setFocusPolicy(Qt::NoFocus);
        key_8->setStyleSheet(QLatin1String("#key_8{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/8 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_8::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/8 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_8->setCheckable(false);
        key_1 = new QPushButton(key_frame);
        key_1->setObjectName(QStringLiteral("key_1"));
        key_1->setGeometry(QRect(512, 90, 41, 41));
        key_1->setFocusPolicy(Qt::NoFocus);
        key_1->setStyleSheet(QLatin1String("#key_1{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/1 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_1::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/1 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_1->setCheckable(false);
        key_6 = new QPushButton(key_frame);
        key_6->setObjectName(QStringLiteral("key_6"));
        key_6->setGeometry(QRect(599, 49, 41, 41));
        key_6->setFocusPolicy(Qt::NoFocus);
        key_6->setStyleSheet(QLatin1String("#key_6{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/6 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_6::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/6 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_6->setCheckable(false);
        key_back = new QPushButton(key_frame);
        key_back->setObjectName(QStringLiteral("key_back"));
        key_back->setGeometry(QRect(443, 7, 61, 41));
        key_back->setFocusPolicy(Qt::NoFocus);
        key_back->setStyleSheet(QLatin1String("#key_back{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Backspace azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"\n"
"}\n"
"\n"
"#key_back::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Backspace blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_back->setCheckable(false);
        key_3 = new QPushButton(key_frame);
        key_3->setObjectName(QStringLiteral("key_3"));
        key_3->setGeometry(QRect(598, 91, 41, 41));
        key_3->setFocusPolicy(Qt::NoFocus);
        key_3->setStyleSheet(QLatin1String("#key_3{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/3 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_3::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/3 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_3->setCheckable(false);
        key_9 = new QPushButton(key_frame);
        key_9->setObjectName(QStringLiteral("key_9"));
        key_9->setGeometry(QRect(598, 6, 41, 41));
        key_9->setFocusPolicy(Qt::NoFocus);
        key_9->setStyleSheet(QLatin1String("#key_9{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/9 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_9::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/9 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_9->setCheckable(false);
        key_2 = new QPushButton(key_frame);
        key_2->setObjectName(QStringLiteral("key_2"));
        key_2->setGeometry(QRect(556, 91, 41, 41));
        key_2->setFocusPolicy(Qt::NoFocus);
        key_2->setStyleSheet(QLatin1String("#key_2{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/2 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_2::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/2 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_2->setCheckable(false);
        key_Q = new QPushButton(key_frame);
        key_Q->setObjectName(QStringLiteral("key_Q"));
        key_Q->setGeometry(QRect(8, 8, 41, 41));
        key_Q->setFocusPolicy(Qt::NoFocus);
        key_Q->setStyleSheet(QLatin1String("#key_Q{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Q azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_Q::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Q blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_Q->setCheckable(false);
        key_W = new QPushButton(key_frame);
        key_W->setObjectName(QStringLiteral("key_W"));
        key_W->setGeometry(QRect(52, 7, 41, 41));
        key_W->setFocusPolicy(Qt::NoFocus);
        key_W->setStyleSheet(QLatin1String("#key_W{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/W azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_W::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/W blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_W->setCheckable(false);
        key_E = new QPushButton(key_frame);
        key_E->setObjectName(QStringLiteral("key_E"));
        key_E->setGeometry(QRect(95, 7, 41, 41));
        key_E->setFocusPolicy(Qt::NoFocus);
        key_E->setStyleSheet(QLatin1String("#key_E{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/E azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_E::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/E blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_E->setCheckable(false);
        key_R = new QPushButton(key_frame);
        key_R->setObjectName(QStringLiteral("key_R"));
        key_R->setGeometry(QRect(140, 8, 41, 41));
        key_R->setFocusPolicy(Qt::NoFocus);
        key_R->setStyleSheet(QLatin1String("#key_R{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/R azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_R::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/R blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_R->setCheckable(false);
        key_T = new QPushButton(key_frame);
        key_T->setObjectName(QStringLiteral("key_T"));
        key_T->setGeometry(QRect(183, 8, 41, 41));
        key_T->setFocusPolicy(Qt::NoFocus);
        key_T->setStyleSheet(QLatin1String("#key_T{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/T azul.png);\n"
"border:none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_T::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/T blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_T->setCheckable(false);
        key_Y = new QPushButton(key_frame);
        key_Y->setObjectName(QStringLiteral("key_Y"));
        key_Y->setGeometry(QRect(226, 7, 41, 41));
        key_Y->setFocusPolicy(Qt::NoFocus);
        key_Y->setStyleSheet(QLatin1String("#key_Y{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Y azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_Y::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Y blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_Y->setCheckable(false);
        key_U = new QPushButton(key_frame);
        key_U->setObjectName(QStringLiteral("key_U"));
        key_U->setGeometry(QRect(270, 7, 41, 41));
        key_U->setFocusPolicy(Qt::NoFocus);
        key_U->setStyleSheet(QLatin1String("#key_U{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/U azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_U::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/U blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_U->setCheckable(false);
        key_I = new QPushButton(key_frame);
        key_I->setObjectName(QStringLiteral("key_I"));
        key_I->setGeometry(QRect(313, 7, 41, 41));
        key_I->setFocusPolicy(Qt::NoFocus);
        key_I->setStyleSheet(QLatin1String("#key_I{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/I azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_I::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/I blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_I->setCheckable(false);
        key_P = new QPushButton(key_frame);
        key_P->setObjectName(QStringLiteral("key_P"));
        key_P->setGeometry(QRect(400, 8, 41, 41));
        key_P->setFocusPolicy(Qt::NoFocus);
        key_P->setStyleSheet(QLatin1String("#key_P{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/P azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_P::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/P blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_P->setCheckable(false);
        key_O = new QPushButton(key_frame);
        key_O->setObjectName(QStringLiteral("key_O"));
        key_O->setGeometry(QRect(357, 8, 41, 41));
        key_O->setFocusPolicy(Qt::NoFocus);
        key_O->setStyleSheet(QLatin1String("#key_O{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/O azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_O::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/O blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_O->setCheckable(false);
        key_A = new QPushButton(key_frame);
        key_A->setObjectName(QStringLiteral("key_A"));
        key_A->setGeometry(QRect(34, 49, 41, 41));
        key_A->setFocusPolicy(Qt::NoFocus);
        key_A->setStyleSheet(QLatin1String("#key_A{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/A azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_A::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/A blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_A->setCheckable(false);
        key_L = new QPushButton(key_frame);
        key_L->setObjectName(QStringLiteral("key_L"));
        key_L->setGeometry(QRect(382, 48, 41, 41));
        key_L->setFocusPolicy(Qt::NoFocus);
        key_L->setStyleSheet(QLatin1String("#key_L{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/L azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_L::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/L blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_L->setCheckable(false);
        key_H = new QPushButton(key_frame);
        key_H->setObjectName(QStringLiteral("key_H"));
        key_H->setGeometry(QRect(251, 49, 41, 41));
        key_H->setFocusPolicy(Qt::NoFocus);
        key_H->setStyleSheet(QLatin1String("#key_H{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/H azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_H::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/H blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_H->setCheckable(false);
        key_G = new QPushButton(key_frame);
        key_G->setObjectName(QStringLiteral("key_G"));
        key_G->setGeometry(QRect(207, 49, 41, 41));
        key_G->setFocusPolicy(Qt::NoFocus);
        key_G->setStyleSheet(QLatin1String("#key_G{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/G azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_G::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/G blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_G->setCheckable(false);
        key_F = new QPushButton(key_frame);
        key_F->setObjectName(QStringLiteral("key_F"));
        key_F->setGeometry(QRect(165, 49, 41, 41));
        key_F->setFocusPolicy(Qt::NoFocus);
        key_F->setStyleSheet(QLatin1String("#key_F{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/F azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_F::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/F blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_F->setCheckable(false);
        key_S = new QPushButton(key_frame);
        key_S->setObjectName(QStringLiteral("key_S"));
        key_S->setGeometry(QRect(78, 49, 41, 41));
        key_S->setFocusPolicy(Qt::NoFocus);
        key_S->setStyleSheet(QLatin1String("#key_S{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/S azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_S::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/S blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_S->setCheckable(false);
        key_D = new QPushButton(key_frame);
        key_D->setObjectName(QStringLiteral("key_D"));
        key_D->setGeometry(QRect(121, 50, 41, 41));
        key_D->setFocusPolicy(Qt::NoFocus);
        key_D->setStyleSheet(QLatin1String("#key_D{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/D azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_D::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/D blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_D->setCheckable(false);
        key_J = new QPushButton(key_frame);
        key_J->setObjectName(QStringLiteral("key_J"));
        key_J->setGeometry(QRect(294, 49, 41, 41));
        key_J->setFocusPolicy(Qt::NoFocus);
        key_J->setStyleSheet(QLatin1String("#key_J{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/J azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_J::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/J blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_J->setCheckable(false);
        key_K = new QPushButton(key_frame);
        key_K->setObjectName(QStringLiteral("key_K"));
        key_K->setGeometry(QRect(339, 49, 41, 41));
        key_K->setFocusPolicy(Qt::NoFocus);
        key_K->setStyleSheet(QLatin1String("#key_K{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/K azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_K::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/K blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_K->setCheckable(false);
        key_dot = new QPushButton(key_frame);
        key_dot->setObjectName(QStringLiteral("key_dot"));
        key_dot->setGeometry(QRect(599, 132, 41, 41));
        key_dot->setFocusPolicy(Qt::NoFocus);
        key_dot->setStyleSheet(QLatin1String("#key_dot{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Punto azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_dot::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Punto blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_dot->setCheckable(false);
        key_slash = new QPushButton(key_frame);
        key_slash->setObjectName(QStringLiteral("key_slash"));
        key_slash->setGeometry(QRect(642, 7, 41, 41));
        key_slash->setFocusPolicy(Qt::NoFocus);
        key_slash->setStyleSheet(QLatin1String("#key_slash{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/slash azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_slash::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/slash blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_slash->setCheckable(false);
        key_plus = new QPushButton(key_frame);
        key_plus->setObjectName(QStringLiteral("key_plus"));
        key_plus->setGeometry(QRect(642, 90, 41, 41));
        key_plus->setFocusPolicy(Qt::NoFocus);
        key_plus->setStyleSheet(QLatin1String("#key_plus{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/plus_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_plus::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/plus_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_plus->setCheckable(false);
        key_minus = new QPushButton(key_frame);
        key_minus->setObjectName(QStringLiteral("key_minus"));
        key_minus->setGeometry(QRect(642, 49, 41, 41));
        key_minus->setFocusPolicy(Qt::NoFocus);
        key_minus->setStyleSheet(QLatin1String("#key_minus{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/minus_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_minus::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/minus_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_minus->setCheckable(false);
        key_X = new QPushButton(key_frame);
        key_X->setObjectName(QStringLiteral("key_X"));
        key_X->setGeometry(QRect(95, 91, 41, 41));
        key_X->setFocusPolicy(Qt::NoFocus);
        key_X->setStyleSheet(QLatin1String("#key_X{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/X azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_X::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/X blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_X->setCheckable(false);
        key_Z = new QPushButton(key_frame);
        key_Z->setObjectName(QStringLiteral("key_Z"));
        key_Z->setGeometry(QRect(52, 91, 41, 41));
        key_Z->setFocusPolicy(Qt::NoFocus);
        key_Z->setStyleSheet(QLatin1String("#key_Z{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Z azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_Z::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Z blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_Z->setCheckable(false);
        key_M = new QPushButton(key_frame);
        key_M->setObjectName(QStringLiteral("key_M"));
        key_M->setGeometry(QRect(313, 90, 41, 41));
        key_M->setFocusPolicy(Qt::NoFocus);
        key_M->setStyleSheet(QLatin1String("#key_M{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/M azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_M::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/M blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_M->setCheckable(false);
        key_C = new QPushButton(key_frame);
        key_C->setObjectName(QStringLiteral("key_C"));
        key_C->setGeometry(QRect(139, 90, 41, 41));
        key_C->setFocusPolicy(Qt::NoFocus);
        key_C->setStyleSheet(QLatin1String("#key_C{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/C azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_C::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/C blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_C->setCheckable(false);
        key_V = new QPushButton(key_frame);
        key_V->setObjectName(QStringLiteral("key_V"));
        key_V->setGeometry(QRect(183, 90, 41, 41));
        key_V->setFocusPolicy(Qt::NoFocus);
        key_V->setStyleSheet(QLatin1String("#key_V{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/V azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_V::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/V blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_V->setCheckable(false);
        key_B = new QPushButton(key_frame);
        key_B->setObjectName(QStringLiteral("key_B"));
        key_B->setGeometry(QRect(226, 90, 41, 41));
        key_B->setFocusPolicy(Qt::NoFocus);
        key_B->setStyleSheet(QLatin1String("#key_B{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/B azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_B::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/B blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_B->setCheckable(false);
        key_N = new QPushButton(key_frame);
        key_N->setObjectName(QStringLiteral("key_N"));
        key_N->setGeometry(QRect(270, 90, 41, 41));
        key_N->setFocusPolicy(Qt::NoFocus);
        key_N->setStyleSheet(QLatin1String("#key_N{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/N azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_N::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/N blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_N->setCheckable(false);
        key_comma = new QPushButton(key_frame);
        key_comma->setObjectName(QStringLiteral("key_comma"));
        key_comma->setGeometry(QRect(357, 91, 41, 41));
        key_comma->setFocusPolicy(Qt::NoFocus);
        key_comma->setStyleSheet(QLatin1String("#key_comma{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/coma azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_comma::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/coma blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_comma->setCheckable(false);
        key_space = new QPushButton(key_frame);
        key_space->setObjectName(QStringLiteral("key_space"));
        key_space->setGeometry(QRect(161, 128, 281, 50));
        key_space->setFocusPolicy(Qt::NoFocus);
        key_space->setStyleSheet(QLatin1String("#key_space{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Espacio azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_space::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Espacio blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_space->setCheckable(false);
        key_enter = new QPushButton(key_frame);
        key_enter->setObjectName(QStringLiteral("key_enter"));
        key_enter->setGeometry(QRect(427, 49, 81, 41));
        key_enter->setFocusPolicy(Qt::NoFocus);
        key_enter->setStyleSheet(QLatin1String("#key_enter{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Enter azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_enter::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Enter blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_enter->setCheckable(false);
        key_mayus = new QPushButton(key_frame);
        key_mayus->setObjectName(QStringLiteral("key_mayus"));
        key_mayus->setGeometry(QRect(13, 134, 111, 41));
        key_mayus->setFocusPolicy(Qt::NoFocus);
        key_mayus->setStyleSheet(QLatin1String("#key_mayus{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Mayus azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_mayus::checked{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Mayus bco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_mayus->setCheckable(true);
        key_mayus->setChecked(false);
        textEdit = new QTextEdit(detailedwindow);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(60, 340, 691, 71));
        textEdit->setStyleSheet(QLatin1String("#textEdit\n"
"{\n"
"color: white;\n"
"background-color:black;\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 167, 250);;\n"
"}"));
        stop_button_image = new QLabel(detailedwindow);
        stop_button_image->setObjectName(QStringLiteral("stop_button_image"));
        stop_button_image->setGeometry(QRect(30, 30, 82, 82));
        stop_button_image->setStyleSheet(QLatin1String("#stop_button_image\n"
"{\n"
"/*background-image: url(:/iconos/screen800x600/iconos/Stop-Boton-Activo.gif);*/\n"
"background-position:center;\n"
"}"));
        pushButton = new QPushButton(detailedwindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 30, 82, 82));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QLatin1String("#pushButton\n"
"{\n"
"background-color:transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/BOTON.png);\n"
"background-position: center;\n"
"background-repeat:none;\n"
"border:none;\n"
"}\n"
"\n"
"/*#pushButton::pressed\n"
"{\n"
"background-color:transparent;\n"
"background-image:  url(:/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/none.png);\n"
"background-position: center;\n"
"background-repeat:none;\n"
"border:none;\n"
"}\n"
"#pushButton::checked\n"
"{\n"
"background-color:transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/BOTON 2.png);\n"
"background-image:  url(:/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/none.png);\n"
"background-position: center;\n"
"background-repeat:none;\n"
"border:none;\n"
"}*/"));
        pushButton->setCheckable(true);
        pushButton->setChecked(false);
        label_paro_general = new QLabel(detailedwindow);
        label_paro_general->setObjectName(QStringLiteral("label_paro_general"));
        label_paro_general->setGeometry(QRect(111, 63, 151, 16));
        QFont font3;
        font3.setPointSize(12);
        label_paro_general->setFont(font3);
        label_paro_general->setStyleSheet(QLatin1String("#label_paro_general\n"
"{\n"
"color: white;\n"
"background-color:transparent;\n"
"border:none;\n"
"}"));
        label_paro_general->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        stop_button_image->raise();
        frame->raise();
        key_frame->raise();
        textEdit->raise();
        pushButton->raise();
        label_paro_general->raise();

        retranslateUi(detailedwindow);

        tabWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(detailedwindow);
    } // setupUi

    void retranslateUi(QDialog *detailedwindow)
    {
        detailedwindow->setWindowTitle(QApplication::translate("detailedwindow", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("detailedwindow", "Par\303\241metros", Q_NULLPTR));
        button_parametros->setText(QString());
        button_evento->setText(QString());
        filtro_fisicos->setText(QString());
        filtro_quimicos->setText(QString());
        filtro_electricos->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("detailedwindow", "Tab 1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("detailedwindow", "Tab 2", Q_NULLPTR));
        description_label->setText(QApplication::translate("detailedwindow", "Descripcion", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("detailedwindow", "Tab 3", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("detailedwindow", "Tab 4", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("detailedwindow", "Paro", Q_NULLPTR)
         << QApplication::translate("detailedwindow", "Automatico", Q_NULLPTR)
         << QApplication::translate("detailedwindow", "Manual", Q_NULLPTR)
        );
        pushButton_modulo->setText(QString());
        stop_button_image_modulo->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("detailedwindow", "Tab 5", Q_NULLPTR));
        evento_gif->setText(QString());
        explicacion->setText(QApplication::translate("detailedwindow", "TextLabel", Q_NULLPTR));
        key_OK->setText(QApplication::translate("detailedwindow", "Completado", Q_NULLPTR));
        key_Reschedule->setText(QString());
        label_horas->setText(QString());
        ayuda_btn->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("detailedwindow", "tab_6", Q_NULLPTR));
        button_visualizacion->setText(QString());
        closeButton->setText(QString());
        button_control->setText(QString());
        nombre->setText(QApplication::translate("detailedwindow", "Nombre", Q_NULLPTR));
        imagen->setText(QString());
        button_descripcion->setText(QString());
        key_0->setText(QString());
        key_4->setText(QString());
        key_5->setText(QString());
        key_7->setText(QString());
        key_8->setText(QString());
        key_1->setText(QString());
        key_6->setText(QString());
        key_back->setText(QString());
        key_3->setText(QString());
        key_9->setText(QString());
        key_2->setText(QString());
        key_Q->setText(QString());
        key_W->setText(QString());
        key_E->setText(QString());
        key_R->setText(QString());
        key_T->setText(QString());
        key_Y->setText(QString());
        key_U->setText(QString());
        key_I->setText(QString());
        key_P->setText(QString());
        key_O->setText(QString());
        key_A->setText(QString());
        key_L->setText(QString());
        key_H->setText(QString());
        key_G->setText(QString());
        key_F->setText(QString());
        key_S->setText(QString());
        key_D->setText(QString());
        key_J->setText(QString());
        key_K->setText(QString());
        key_dot->setText(QString());
        key_slash->setText(QString());
        key_plus->setText(QString());
        key_minus->setText(QString());
        key_X->setText(QString());
        key_Z->setText(QString());
        key_M->setText(QString());
        key_C->setText(QString());
        key_V->setText(QString());
        key_B->setText(QString());
        key_N->setText(QString());
        key_comma->setText(QString());
        key_space->setText(QString());
        key_enter->setText(QString());
        key_mayus->setText(QString());
        stop_button_image->setText(QString());
        pushButton->setText(QString());
        label_paro_general->setText(QApplication::translate("detailedwindow", "Paro General", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class detailedwindow: public Ui_detailedwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILEDWINDOW_H
