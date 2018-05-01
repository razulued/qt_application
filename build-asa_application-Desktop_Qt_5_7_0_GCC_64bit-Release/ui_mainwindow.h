/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *bottom_bar;
    QPushButton *pb_fisicos;
    QPushButton *pb_quimicos;
    QPushButton *pb_electricos;
    QLabel *active_param_label;
    QPushButton *modulo_1;
    QPushButton *modulo_2;
    QPushButton *modulo_3;
    QPushButton *modulo_4;
    QPushButton *modulo_5;
    QPushButton *modulo_6;
    QLabel *top_bar;
    QPushButton *top_menu_1;
    QPushButton *asa_logo;
    QWidget *widget;
    QWidget *widget_2;
    QWidget *widget_3;
    QWidget *widget_4;
    QWidget *widget_6;
    QWidget *widget_7;
    QWidget *widget_8;
    QWidget *widget_9;
    QWidget *widget_10;
    QWidget *widget_11;
    QWidget *widget_12;
    QWidget *widget_5;
    QPushButton *top_menu_5;
    QPushButton *modulo_7;
    QPushButton *modulo_8;
    QLabel *label_hora;
    QWidget *widget_13;
    QWidget *widget_14;
    QWidget *widget_15;
    QWidget *widget_16;
    QWidget *widget_17;
    QWidget *widget_18;
    QWidget *widget_19;
    QWidget *widget_20;
    QWidget *widget_21;
    QWidget *widget_22;
    QWidget *widget_23;
    QWidget *widget_24;
    QLabel *gif_modulo_1;
    QLabel *gif_modulo_2;
    QLabel *gif_modulo_3;
    QLabel *gif_modulo_4;
    QLabel *gif_modulo_5;
    QLabel *gif_sludge_a;
    QLabel *gif_sludge_b;
    QLabel *gif_water_flown_a;
    QLabel *gif_sludge_return_a;
    QLabel *gif_modulo_6;
    QLabel *gif_modulo_7;
    QLabel *gif_modulo_8;
    QPushButton *top_menu_2;
    QPushButton *top_menu_3;
    QLabel *bck_modulo_7;
    QLabel *bck_modulo_8;
    QLabel *bck_retorno_1;
    QLabel *bck_retorno_2;
    QLabel *bck_retorno_3;
    QLabel *bck_retorno_4;
    QLabel *gif_blower;
    QLabel *gif_car_mot;
    QPushButton *lock_button;
    QLabel *label_dia;
    QPushButton *prof_pic;
    QLabel *prof_label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QLatin1String("#modulo_1{  \n"
"background-color: transparent;\n"
"border: none;\n"
"background-repeat: none;\n"
" } \n"
"#modulo_1:pressed{  \n"
"background-color: red;\n"
"border: none;\n"
"background-repeat: none;\n"
" } \n"
"#modulo_2{  \n"
"background-color: transparent;\n"
"border: none;\n"
"background-repeat: none;\n"
" } \n"
"#modulo_3{  \n"
"background-color: transparent;\n"
"border: none;\n"
"background-repeat: none;\n"
" } \n"
"#modulo_4{  \n"
"background-color: transparent;\n"
"border: none;\n"
"background-repeat: none;\n"
" } \n"
"#modulo_5{  \n"
"background-color: transparent;\n"
"border: none;\n"
"background-repeat: none;\n"
" } \n"
"#modulo_6{  \n"
"background-color: transparent;\n"
"border: none;\n"
"background-repeat: none;\n"
" } \n"
"\n"
"QWidget{\n"
"border-style: solid;\n"
"border-color:  black;\n"
"border-width: 1px;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(7, 530, 70, 67));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QLatin1String("#pushButton { \n"
"background-color: transparent;\n"
"border-image: url(:/iconos/images/Iconos/Menu_azul.png); \n"
"background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
" } \n"
"#pushButton:pressed {\n"
"border-image: url(:/iconos/images/Iconos/Menu_azul.png); \n"
" }\n"
"#pushButton:checked{\n"
" border-image: none;\n"
" }"));
        pushButton->setCheckable(true);
        pushButton->setChecked(false);
        pushButton->setFlat(false);
        bottom_bar = new QLabel(centralWidget);
        bottom_bar->setObjectName(QStringLiteral("bottom_bar"));
        bottom_bar->setGeometry(QRect(0, 529, 766, 70));
        bottom_bar->setAutoFillBackground(false);
        bottom_bar->setStyleSheet(QLatin1String("#bottom_bar { \n"
"background-color: transparent;\n"
"border-image: url(:/barras/images/Barras/Parametros_azul.png); background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pb_fisicos = new QPushButton(centralWidget);
        pb_fisicos->setObjectName(QStringLiteral("pb_fisicos"));
        pb_fisicos->setGeometry(QRect(450, 560, 51, 41));
        pb_fisicos->setFocusPolicy(Qt::NoFocus);
        pb_fisicos->setStyleSheet(QLatin1String("#pb_fisicos { \n"
"background-image: url(:/iconos/screen800x600/iconos/Medidor azul.png);\n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        pb_fisicos->setCheckable(true);
        pb_quimicos = new QPushButton(centralWidget);
        pb_quimicos->setObjectName(QStringLiteral("pb_quimicos"));
        pb_quimicos->setGeometry(QRect(530, 560, 71, 41));
        pb_quimicos->setFocusPolicy(Qt::NoFocus);
        pb_quimicos->setStyleSheet(QLatin1String("#pb_quimicos { \n"
"background-image: url(:/iconos/screen800x600/iconos/Matraz azul.png);\n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        pb_quimicos->setCheckable(true);
        pb_electricos = new QPushButton(centralWidget);
        pb_electricos->setObjectName(QStringLiteral("pb_electricos"));
        pb_electricos->setGeometry(QRect(610, 560, 81, 41));
        pb_electricos->setFocusPolicy(Qt::NoFocus);
        pb_electricos->setStyleSheet(QLatin1String("#pb_electricos { \n"
"background-image: url(:/iconos/screen800x600/iconos/Clavija azul.png);\n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        pb_electricos->setCheckable(true);
        active_param_label = new QLabel(centralWidget);
        active_param_label->setObjectName(QStringLiteral("active_param_label"));
        active_param_label->setEnabled(true);
        active_param_label->setGeometry(QRect(82, 580, 341, 20));
        QFont font;
        font.setFamily(QStringLiteral("Phetsarath OT"));
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        active_param_label->setFont(font);
        active_param_label->setAutoFillBackground(false);
        active_param_label->setStyleSheet(QLatin1String("#active_param_label { \n"
"background-color: transparent;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        active_param_label->setTextFormat(Qt::PlainText);
        modulo_1 = new QPushButton(centralWidget);
        modulo_1->setObjectName(QStringLiteral("modulo_1"));
        modulo_1->setGeometry(QRect(110, 230, 111, 91));
        modulo_1->setFocusPolicy(Qt::NoFocus);
        modulo_1->setAutoFillBackground(false);
        modulo_1->setStyleSheet(QLatin1String("#modulo_1 { \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_1->setFlat(true);
        modulo_2 = new QPushButton(centralWidget);
        modulo_2->setObjectName(QStringLiteral("modulo_2"));
        modulo_2->setGeometry(QRect(250, 190, 111, 91));
        modulo_2->setFocusPolicy(Qt::NoFocus);
        modulo_2->setStyleSheet(QLatin1String("#modulo_2{ \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_2->setFlat(true);
        modulo_3 = new QPushButton(centralWidget);
        modulo_3->setObjectName(QStringLiteral("modulo_3"));
        modulo_3->setGeometry(QRect(407, 152, 111, 91));
        modulo_3->setFocusPolicy(Qt::NoFocus);
        modulo_3->setStyleSheet(QLatin1String("#modulo_3 { \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_3->setFlat(true);
        modulo_4 = new QPushButton(centralWidget);
        modulo_4->setObjectName(QStringLiteral("modulo_4"));
        modulo_4->setGeometry(QRect(550, 120, 101, 101));
        modulo_4->setFocusPolicy(Qt::NoFocus);
        modulo_4->setStyleSheet(QLatin1String("#modulo_4 { \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_4->setFlat(true);
        modulo_5 = new QPushButton(centralWidget);
        modulo_5->setObjectName(QStringLiteral("modulo_5"));
        modulo_5->setGeometry(QRect(580, 270, 100, 91));
        modulo_5->setFocusPolicy(Qt::NoFocus);
        modulo_5->setStyleSheet(QLatin1String("#modulo_5 { \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_5->setFlat(true);
        modulo_6 = new QPushButton(centralWidget);
        modulo_6->setObjectName(QStringLiteral("modulo_6"));
        modulo_6->setGeometry(QRect(320, 380, 131, 91));
        modulo_6->setFocusPolicy(Qt::NoFocus);
        modulo_6->setStyleSheet(QLatin1String("#modulo_6{ \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_6->setFlat(true);
        top_bar = new QLabel(centralWidget);
        top_bar->setObjectName(QStringLiteral("top_bar"));
        top_bar->setGeometry(QRect(0, 2, 759, 27));
        top_bar->setAutoFillBackground(false);
        top_bar->setStyleSheet(QLatin1String("#top_bar { \n"
"background-color: transparent;\n"
"background-image: url(:/barras/screen800x600/barras/Indice diagrama.png);\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_1 = new QPushButton(centralWidget);
        top_menu_1->setObjectName(QStringLiteral("top_menu_1"));
        top_menu_1->setGeometry(QRect(0, 0, 31, 41));
        top_menu_1->setFocusPolicy(Qt::NoFocus);
        top_menu_1->setStyleSheet(QLatin1String("#top_menu_1 { \n"
"background-color: transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/Campana.png);\n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"\n"
" } "));
        top_menu_1->setCheckable(true);
        asa_logo = new QPushButton(centralWidget);
        asa_logo->setObjectName(QStringLiteral("asa_logo"));
        asa_logo->setGeometry(QRect(740, 550, 51, 51));
        asa_logo->setFocusPolicy(Qt::NoFocus);
        asa_logo->setStyleSheet(QLatin1String("#asa_logo{ \n"
"background-image: url(:/iconos/screen800x600/iconos/ASA logo.png);\n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        asa_logo->setCheckable(true);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 90, 41, 31));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(70, 90, 41, 31));
        widget_2->setStyleSheet(QStringLiteral(""));
        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(119, 90, 41, 31));
        widget_4 = new QWidget(centralWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(240, 100, 41, 31));
        widget_6 = new QWidget(centralWidget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(340, 100, 41, 31));
        widget_7 = new QWidget(centralWidget);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setGeometry(QRect(450, 80, 41, 31));
        widget_8 = new QWidget(centralWidget);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setGeometry(QRect(500, 80, 41, 31));
        widget_9 = new QWidget(centralWidget);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setGeometry(QRect(550, 80, 41, 31));
        widget_9->setStyleSheet(QStringLiteral(""));
        widget_10 = new QWidget(centralWidget);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        widget_10->setGeometry(QRect(640, 50, 41, 31));
        widget_11 = new QWidget(centralWidget);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        widget_11->setGeometry(QRect(690, 50, 41, 31));
        widget_12 = new QWidget(centralWidget);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        widget_12->setGeometry(QRect(740, 50, 41, 31));
        widget_5 = new QWidget(centralWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(290, 100, 41, 31));
        top_menu_5 = new QPushButton(centralWidget);
        top_menu_5->setObjectName(QStringLiteral("top_menu_5"));
        top_menu_5->setGeometry(QRect(130, 1, 34, 41));
        top_menu_5->setFocusPolicy(Qt::NoFocus);
        top_menu_5->setStyleSheet(QLatin1String("#top_menu_5 { \n"
"background-color: transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/Ajustes azul.png);\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_5->setCheckable(true);
        modulo_7 = new QPushButton(centralWidget);
        modulo_7->setObjectName(QStringLiteral("modulo_7"));
        modulo_7->setGeometry(QRect(19, 248, 91, 50));
        modulo_7->setFocusPolicy(Qt::NoFocus);
        modulo_7->setStyleSheet(QLatin1String("#modulo_7{ \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_7->setFlat(true);
        modulo_8 = new QPushButton(centralWidget);
        modulo_8->setObjectName(QStringLiteral("modulo_8"));
        modulo_8->setGeometry(QRect(670, 200, 71, 51));
        modulo_8->setFocusPolicy(Qt::NoFocus);
        modulo_8->setStyleSheet(QLatin1String("#modulo_8{ \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_8->setFlat(true);
        label_hora = new QLabel(centralWidget);
        label_hora->setObjectName(QStringLiteral("label_hora"));
        label_hora->setGeometry(QRect(350, 50, 81, 31));
        label_hora->setAlignment(Qt::AlignCenter);
        widget_13 = new QWidget(centralWidget);
        widget_13->setObjectName(QStringLiteral("widget_13"));
        widget_13->setGeometry(QRect(600, 390, 41, 31));
        widget_14 = new QWidget(centralWidget);
        widget_14->setObjectName(QStringLiteral("widget_14"));
        widget_14->setGeometry(QRect(550, 390, 41, 31));
        widget_15 = new QWidget(centralWidget);
        widget_15->setObjectName(QStringLiteral("widget_15"));
        widget_15->setGeometry(QRect(500, 390, 41, 31));
        widget_16 = new QWidget(centralWidget);
        widget_16->setObjectName(QStringLiteral("widget_16"));
        widget_16->setGeometry(QRect(240, 430, 41, 31));
        widget_17 = new QWidget(centralWidget);
        widget_17->setObjectName(QStringLiteral("widget_17"));
        widget_17->setGeometry(QRect(189, 430, 41, 31));
        widget_18 = new QWidget(centralWidget);
        widget_18->setObjectName(QStringLiteral("widget_18"));
        widget_18->setGeometry(QRect(140, 430, 41, 31));
        widget_19 = new QWidget(centralWidget);
        widget_19->setObjectName(QStringLiteral("widget_19"));
        widget_19->setGeometry(QRect(10, 340, 41, 31));
        widget_20 = new QWidget(centralWidget);
        widget_20->setObjectName(QStringLiteral("widget_20"));
        widget_20->setGeometry(QRect(10, 380, 41, 31));
        widget_21 = new QWidget(centralWidget);
        widget_21->setObjectName(QStringLiteral("widget_21"));
        widget_21->setGeometry(QRect(10, 430, 41, 31));
        widget_22 = new QWidget(centralWidget);
        widget_22->setObjectName(QStringLiteral("widget_22"));
        widget_22->setGeometry(QRect(730, 250, 41, 31));
        widget_23 = new QWidget(centralWidget);
        widget_23->setObjectName(QStringLiteral("widget_23"));
        widget_23->setGeometry(QRect(730, 290, 41, 31));
        widget_24 = new QWidget(centralWidget);
        widget_24->setObjectName(QStringLiteral("widget_24"));
        widget_24->setGeometry(QRect(730, 330, 41, 31));
        gif_modulo_1 = new QLabel(centralWidget);
        gif_modulo_1->setObjectName(QStringLiteral("gif_modulo_1"));
        gif_modulo_1->setGeometry(QRect(69, 177, 180, 180));
        gif_modulo_1->setStyleSheet(QLatin1String("#gif_modulo_1\n"
"{\n"
"background-image: url(:/gifs/1 Carcamo y Regulador/screen800x600/gifs/1 Carcamo y Regulador/regul hi quiet water 03.png);\n"
"background-repeat: none;\n"
"background-position:center;\n"
"border:none;\n"
"}"));
        gif_modulo_2 = new QLabel(centralWidget);
        gif_modulo_2->setObjectName(QStringLiteral("gif_modulo_2"));
        gif_modulo_2->setGeometry(QRect(220, 140, 180, 180));
        gif_modulo_2->setStyleSheet(QLatin1String("#gif_modulo_2\n"
"{\n"
"background-image: url(:/gifs/2 Reactor/screen800x600/gifs/2 Reactor/reac hi quiet water 03.png);\n"
"background-repeat: none;\n"
"background-position:center;\n"
"border:none;\n"
"}"));
        gif_modulo_3 = new QLabel(centralWidget);
        gif_modulo_3->setObjectName(QStringLiteral("gif_modulo_3"));
        gif_modulo_3->setGeometry(QRect(372, 108, 180, 180));
        gif_modulo_3->setStyleSheet(QLatin1String("#gif_modulo_3\n"
"{\n"
"background-image: url(:/gifs/3 Clarificador/screen800x600/gifs/3 Clarificador/clarifier vacio.png);\n"
"background-repeat: none;\n"
"background-position:center;\n"
"border:none;\n"
"}"));
        gif_modulo_4 = new QLabel(centralWidget);
        gif_modulo_4->setObjectName(QStringLiteral("gif_modulo_4"));
        gif_modulo_4->setGeometry(QRect(510, 80, 180, 180));
        gif_modulo_4->setStyleSheet(QLatin1String("#gif_modulo_4\n"
"{\n"
"background-image: url(:/gifs/4 Clorador/screen800x600/gifs/4 Clorador/chlorination quiet.png);\n"
"background-repeat: none;\n"
"background-position:center;\n"
"border:none;\n"
"}"));
        gif_modulo_5 = new QLabel(centralWidget);
        gif_modulo_5->setObjectName(QStringLiteral("gif_modulo_5"));
        gif_modulo_5->setGeometry(QRect(574, 264, 111, 111));
        gif_modulo_5->setStyleSheet(QLatin1String("#gif_modulo_5\n"
"{\n"
"background-image: url(:/gifs/5 Digestor/screen800x600/gifs/5 Digestor/digester empty.png);\n"
"background-repeat: none;\n"
"background-position:center;\n"
"border:none;\n"
"}"));
        gif_sludge_a = new QLabel(centralWidget);
        gif_sludge_a->setObjectName(QStringLiteral("gif_sludge_a"));
        gif_sludge_a->setGeometry(QRect(190, 180, 100, 100));
        gif_sludge_a->setStyleSheet(QLatin1String("#gif_sludge_a{\n"
"background-image: url(:/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/sludge flow 01 quiet.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"border:none;\n"
"}"));
        gif_sludge_b = new QLabel(centralWidget);
        gif_sludge_b->setObjectName(QStringLiteral("gif_sludge_b"));
        gif_sludge_b->setGeometry(QRect(340, 150, 100, 100));
        gif_sludge_b->setStyleSheet(QLatin1String("#gif_sludge_b{\n"
"background-image: url(:/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/sludge flow 01 quiet.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"border:none;\n"
"}"));
        gif_water_flown_a = new QLabel(centralWidget);
        gif_water_flown_a->setObjectName(QStringLiteral("gif_water_flown_a"));
        gif_water_flown_a->setGeometry(QRect(480, 118, 100, 100));
        gif_water_flown_a->setStyleSheet(QLatin1String("#gif_water_flown_a{\n"
"background-image: url(:/flechas/images/0_Flechas_de_flujo/water_flow_01_quiet.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"border:none;\n"
"}"));
        gif_sludge_return_a = new QLabel(centralWidget);
        gif_sludge_return_a->setObjectName(QStringLiteral("gif_sludge_return_a"));
        gif_sludge_return_a->setGeometry(QRect(280, 232, 231, 81));
        gif_sludge_return_a->setStyleSheet(QLatin1String("#gif_sludge_return_a{\n"
"background-image: url(:/flechas/images/0_Flechas_de_flujo/sludge_return.png);\n"
"border: none;\n"
"background-position:center;\n"
"background-repeat: none;\n"
"}"));
        gif_modulo_6 = new QLabel(centralWidget);
        gif_modulo_6->setObjectName(QStringLiteral("gif_modulo_6"));
        gif_modulo_6->setGeometry(QRect(313, 381, 151, 101));
        gif_modulo_6->setStyleSheet(QLatin1String("#gif_modulo_6\n"
"{\n"
"background-image: url(:/gifs/6 Lechos/screen800x600/gifs/6 Lechos/sand bed 01.png);\n"
"background-repeat: none;\n"
"background-position:center;\n"
"border:none;\n"
"}"));
        gif_modulo_7 = new QLabel(centralWidget);
        gif_modulo_7->setObjectName(QStringLiteral("gif_modulo_7"));
        gif_modulo_7->setGeometry(QRect(30, 190, 55, 55));
        gif_modulo_7->setStyleSheet(QLatin1String("#gif_modulo_7\n"
"{\n"
"/*background-image: url(:/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/water flow effluent 01 quiet.png);\n"
"background-repeat: none;\n"
"background-position:center;\n"
"border:none;*/\n"
"}"));
        gif_modulo_8 = new QLabel(centralWidget);
        gif_modulo_8->setObjectName(QStringLiteral("gif_modulo_8"));
        gif_modulo_8->setGeometry(QRect(700, 150, 55, 55));
        gif_modulo_8->setStyleSheet(QLatin1String("#gif_modulo_5{\n"
"\n"
"/* x = 639 y = 373 */\n"
"/*background-image: url(:/digestor/images/5_Digestor/digester_empty.png);*/\n"
"\n"
"/*x= 663 y = 195:  x-2, y-1 */\n"
"/*background-image: url(:/clorador/images/4_Clorador/chlorination_mov.gif);*/\n"
"\n"
"/* x= 493 Y = 236: x-7, y-2*/\n"
"/*background-image: url(:/clarificador/images/3_Clarificador/clarifier_full_quiet.png);*/\n"
"\n"
"/*x = 328 y = 291; x+7, y+15*/\n"
"/*background-image: url(:/reactor/images/2_Reactor/reac_med_mov_water_02.gif);*/\n"
"\n"
"/*x=321 y = 296: y+20*/\n"
"/*background-image: url(:/reactor/images/2_Reactor/reac_low_mov_water_01.gif);*/\n"
"}"));
        top_menu_2 = new QPushButton(centralWidget);
        top_menu_2->setObjectName(QStringLiteral("top_menu_2"));
        top_menu_2->setGeometry(QRect(40, 0, 31, 41));
        top_menu_2->setFocusPolicy(Qt::NoFocus);
        top_menu_2->setStyleSheet(QLatin1String("#top_menu_2 { \n"
"background-color: transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/Bitacora azul.png);\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_2->setCheckable(true);
        top_menu_3 = new QPushButton(centralWidget);
        top_menu_3->setObjectName(QStringLiteral("top_menu_3"));
        top_menu_3->setGeometry(QRect(90, 2, 31, 41));
        top_menu_3->setFocusPolicy(Qt::NoFocus);
        top_menu_3->setStyleSheet(QLatin1String("#top_menu_3 { \n"
"background-color: transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/Diagrama.png);\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_3->setCheckable(true);
        bck_modulo_7 = new QLabel(centralWidget);
        bck_modulo_7->setObjectName(QStringLiteral("bck_modulo_7"));
        bck_modulo_7->setGeometry(QRect(30, 250, 90, 50));
        bck_modulo_7->setStyleSheet(QLatin1String("#bck_modulo_7\n"
"{\n"
"/*border-image: url(:/images/images/afluente.png);*/\n"
"border-image: url(:/diagrama/screen800x600/diagrama/Afluente.png);\n"
"background-position: center;\n"
"background-repeat: none;\n"
"\n"
"}"));
        bck_modulo_8 = new QLabel(centralWidget);
        bck_modulo_8->setObjectName(QStringLiteral("bck_modulo_8"));
        bck_modulo_8->setGeometry(QRect(630, 150, 111, 100));
        bck_modulo_8->setStyleSheet(QLatin1String("#bck_modulo_8\n"
"{\n"
"border-image: url(:/images/images/efluente_2.png);\n"
"}"));
        bck_retorno_1 = new QLabel(centralWidget);
        bck_retorno_1->setObjectName(QStringLiteral("bck_retorno_1"));
        bck_retorno_1->setGeometry(QRect(479, 216, 161, 81));
        bck_retorno_1->setStyleSheet(QLatin1String("#bck_retorno_1\n"
"{\n"
"border-image: url(:/images/images/retorno_1.png);\n"
"background-repeat: none;\n"
"\n"
"}"));
        bck_retorno_2 = new QLabel(centralWidget);
        bck_retorno_2->setObjectName(QStringLiteral("bck_retorno_2"));
        bck_retorno_2->setGeometry(QRect(120, 426, 241, 101));
        bck_retorno_2->setStyleSheet(QLatin1String("#bck_retorno_2\n"
"{\n"
"background-image: url(:/images/images/retorno_2.png);\n"
"background-repeat: none;\n"
"border:none;\n"
"}"));
        bck_retorno_3 = new QLabel(centralWidget);
        bck_retorno_3->setObjectName(QStringLiteral("bck_retorno_3"));
        bck_retorno_3->setGeometry(QRect(229, 232, 121, 221));
        bck_retorno_3->setStyleSheet(QLatin1String("#bck_retorno_3\n"
"{\n"
"background-image: url(:/images/images/retorno_3.png);\n"
"background-repeat: none;\n"
"border:none;\n"
"}"));
        bck_retorno_4 = new QLabel(centralWidget);
        bck_retorno_4->setObjectName(QStringLiteral("bck_retorno_4"));
        bck_retorno_4->setGeometry(QRect(343, 297, 251, 121));
        bck_retorno_4->setStyleSheet(QLatin1String("#bck_retorno_4\n"
"{\n"
"border-image: url(:/images/images/retorno_4.png);\n"
"background-repeat: none;\n"
"border:none;\n"
"}"));
        gif_blower = new QLabel(centralWidget);
        gif_blower->setObjectName(QStringLiteral("gif_blower"));
        gif_blower->setGeometry(QRect(250, 140, 110, 110));
        gif_blower->setStyleSheet(QLatin1String("#gif_blower\n"
"{\n"
"background-image: url(:/gifs/0 Equipos/screen800x600/gifs/0 Equipos/Blower Jet off.png);\n"
"background-repeat: none;\n"
"background-position:center;\n"
"border:none;\n"
"}"));
        gif_car_mot = new QLabel(centralWidget);
        gif_car_mot->setObjectName(QStringLiteral("gif_car_mot"));
        gif_car_mot->setGeometry(QRect(126, 233, 110, 110));
        gif_car_mot->setStyleSheet(QLatin1String("#gif_car_mot{\n"
"background-image: url(:/gifs/0 Equipos/screen800x600/gifs/0 Equipos/pump off.png);\n"
"background-repeat: none;\n"
"background-position:center;\n"
"border:none;\n"
"}"));
        lock_button = new QPushButton(centralWidget);
        lock_button->setObjectName(QStringLiteral("lock_button"));
        lock_button->setGeometry(QRect(170, 0, 31, 41));
        lock_button->setFocusPolicy(Qt::NoFocus);
        lock_button->setStyleSheet(QLatin1String("#lock_button { \n"
"background-image: url(:/iconos/screen800x600/iconos/Candado azul.png);\n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        label_dia = new QLabel(centralWidget);
        label_dia->setObjectName(QStringLiteral("label_dia"));
        label_dia->setGeometry(QRect(275, 28, 231, 21));
        label_dia->setAlignment(Qt::AlignCenter);
        prof_pic = new QPushButton(centralWidget);
        prof_pic->setObjectName(QStringLiteral("prof_pic"));
        prof_pic->setGeometry(QRect(540, 10, 41, 41));
        prof_pic->setFocusPolicy(Qt::NoFocus);
        prof_pic->setStyleSheet(QLatin1String("#prof_pic { \n"
"background-image: url(:/iconos/screen800x600/iconos/Prof pic azul.png);\n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        prof_label = new QLabel(centralWidget);
        prof_label->setObjectName(QStringLiteral("prof_label"));
        prof_label->setGeometry(QRect(580, 20, 151, 21));
        MainWindow->setCentralWidget(centralWidget);
        top_bar->raise();
        gif_modulo_4->raise();
        gif_water_flown_a->raise();
        gif_modulo_3->raise();
        gif_sludge_b->raise();
        gif_modulo_2->raise();
        gif_sludge_return_a->raise();
        lock_button->raise();
        bottom_bar->raise();
        pushButton->raise();
        pb_fisicos->raise();
        pb_quimicos->raise();
        pb_electricos->raise();
        active_param_label->raise();
        top_menu_1->raise();
        asa_logo->raise();
        top_menu_5->raise();
        label_hora->raise();
        gif_sludge_a->raise();
        top_menu_2->raise();
        top_menu_3->raise();
        bck_modulo_8->raise();
        bck_retorno_1->raise();
        bck_retorno_3->raise();
        gif_modulo_7->raise();
        gif_modulo_5->raise();
        gif_modulo_6->raise();
        gif_modulo_8->raise();
        gif_modulo_1->raise();
        bck_modulo_7->raise();
        gif_blower->raise();
        gif_car_mot->raise();
        bck_retorno_4->raise();
        bck_retorno_2->raise();
        modulo_4->raise();
        modulo_7->raise();
        modulo_1->raise();
        modulo_2->raise();
        modulo_6->raise();
        modulo_5->raise();
        modulo_8->raise();
        modulo_3->raise();
        widget->raise();
        widget_14->raise();
        widget_20->raise();
        widget_24->raise();
        widget_22->raise();
        widget_21->raise();
        widget_17->raise();
        widget_18->raise();
        widget_3->raise();
        widget_7->raise();
        widget_15->raise();
        widget_23->raise();
        widget_10->raise();
        widget_6->raise();
        widget_11->raise();
        widget_16->raise();
        widget_13->raise();
        widget_2->raise();
        widget_8->raise();
        widget_5->raise();
        widget_9->raise();
        widget_19->raise();
        widget_4->raise();
        widget_12->raise();
        label_dia->raise();
        prof_pic->raise();
        prof_label->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
#ifndef QT_NO_ACCESSIBILITY
        MainWindow->setAccessibleName(QApplication::translate("MainWindow", "mainWindow", 0));
#endif // QT_NO_ACCESSIBILITY
        pushButton->setText(QString());
        bottom_bar->setText(QString());
        pb_fisicos->setText(QString());
        pb_quimicos->setText(QString());
        pb_electricos->setText(QString());
        active_param_label->setText(QApplication::translate("MainWindow", "Par\303\241metros", 0));
        modulo_1->setText(QString());
        modulo_2->setText(QString());
        modulo_3->setText(QString());
        modulo_4->setText(QString());
        modulo_5->setText(QString());
        modulo_6->setText(QString());
        top_bar->setText(QString());
        top_menu_1->setText(QString());
        asa_logo->setText(QString());
        top_menu_5->setText(QString());
        modulo_7->setText(QString());
        modulo_8->setText(QString());
        label_hora->setText(QApplication::translate("MainWindow", "Hora", 0));
        gif_modulo_1->setText(QString());
        gif_modulo_2->setText(QString());
        gif_modulo_3->setText(QString());
        gif_modulo_4->setText(QString());
        gif_modulo_5->setText(QString());
        gif_sludge_a->setText(QString());
        gif_sludge_b->setText(QString());
        gif_water_flown_a->setText(QString());
        gif_sludge_return_a->setText(QString());
        gif_modulo_6->setText(QString());
        gif_modulo_7->setText(QString());
        gif_modulo_8->setText(QString());
        top_menu_2->setText(QString());
        top_menu_3->setText(QString());
        bck_modulo_7->setText(QString());
        bck_modulo_8->setText(QString());
        bck_retorno_1->setText(QString());
        bck_retorno_2->setText(QString());
        bck_retorno_3->setText(QString());
        bck_retorno_4->setText(QString());
        gif_blower->setText(QString());
        gif_car_mot->setText(QString());
        lock_button->setText(QString());
        label_dia->setText(QApplication::translate("MainWindow", "Dia", 0));
        prof_pic->setText(QString());
        prof_label->setText(QApplication::translate("MainWindow", "Sin usuario", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
