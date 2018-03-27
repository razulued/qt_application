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
    QPushButton *top_menu_2;
    QPushButton *top_menu_3;
    QPushButton *top_menu_4;
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
    QLabel *bck_modulo_1;
    QLabel *bck_modulo_2;
    QLabel *bck_modulo_3;
    QLabel *bck_modulo_4;
    QLabel *bck_modulo_5;
    QLabel *bck_modulo_6;
    QLabel *gif_modulo_6;
    QLabel *gif_modulo_7;
    QLabel *gif_modulo_8;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 768);
        MainWindow->setMinimumSize(QSize(1024, 768));
        MainWindow->setMaximumSize(QSize(1024, 768));
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
        pushButton->setGeometry(QRect(10, 680, 90, 86));
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
        bottom_bar->setGeometry(QRect(0, 680, 974, 87));
        bottom_bar->setAutoFillBackground(false);
        bottom_bar->setStyleSheet(QLatin1String("#bottom_bar { \n"
"background-color: transparent;\n"
"border-image: url(:/barras/images/Barras/Parametros_azul.png); background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pb_fisicos = new QPushButton(centralWidget);
        pb_fisicos->setObjectName(QStringLiteral("pb_fisicos"));
        pb_fisicos->setGeometry(QRect(580, 716, 91, 51));
        pb_fisicos->setFocusPolicy(Qt::NoFocus);
        pb_fisicos->setStyleSheet(QLatin1String("#pb_fisicos { \n"
"background-image: url(:/iconos/images/Iconos/Medidor_azul.png);\n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        pb_fisicos->setCheckable(true);
        pb_quimicos = new QPushButton(centralWidget);
        pb_quimicos->setObjectName(QStringLiteral("pb_quimicos"));
        pb_quimicos->setGeometry(QRect(710, 716, 71, 51));
        pb_quimicos->setFocusPolicy(Qt::NoFocus);
        pb_quimicos->setStyleSheet(QLatin1String("#pb_quimicos { \n"
"background-image: url(:/iconos/images/Iconos/Matraz_azul.png);\n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        pb_quimicos->setCheckable(true);
        pb_electricos = new QPushButton(centralWidget);
        pb_electricos->setObjectName(QStringLiteral("pb_electricos"));
        pb_electricos->setGeometry(QRect(810, 716, 91, 51));
        pb_electricos->setFocusPolicy(Qt::NoFocus);
        pb_electricos->setStyleSheet(QLatin1String("#pb_electricos { \n"
"background-image: url(:/iconos/images/Iconos/Clavija_azul.png);\n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        pb_electricos->setCheckable(true);
        active_param_label = new QLabel(centralWidget);
        active_param_label->setObjectName(QStringLiteral("active_param_label"));
        active_param_label->setEnabled(true);
        active_param_label->setGeometry(QRect(106, 747, 341, 20));
        QFont font;
        font.setFamily(QStringLiteral("Phetsarath OT"));
        font.setPointSize(18);
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
        modulo_1->setGeometry(QRect(200, 370, 101, 71));
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
        modulo_2->setGeometry(QRect(348, 335, 101, 71));
        modulo_2->setFocusPolicy(Qt::NoFocus);
        modulo_2->setStyleSheet(QLatin1String("#modulo_2{ \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_2->setFlat(true);
        modulo_3 = new QPushButton(centralWidget);
        modulo_3->setObjectName(QStringLiteral("modulo_3"));
        modulo_3->setGeometry(QRect(509, 296, 91, 71));
        modulo_3->setFocusPolicy(Qt::NoFocus);
        modulo_3->setStyleSheet(QLatin1String("#modulo_3 { \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_3->setFlat(true);
        modulo_4 = new QPushButton(centralWidget);
        modulo_4->setObjectName(QStringLiteral("modulo_4"));
        modulo_4->setGeometry(QRect(650, 260, 110, 71));
        modulo_4->setFocusPolicy(Qt::NoFocus);
        modulo_4->setStyleSheet(QLatin1String("#modulo_4 { \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_4->setFlat(true);
        modulo_5 = new QPushButton(centralWidget);
        modulo_5->setObjectName(QStringLiteral("modulo_5"));
        modulo_5->setGeometry(QRect(630, 430, 100, 71));
        modulo_5->setFocusPolicy(Qt::NoFocus);
        modulo_5->setStyleSheet(QLatin1String("#modulo_5 { \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_5->setFlat(true);
        modulo_6 = new QPushButton(centralWidget);
        modulo_6->setObjectName(QStringLiteral("modulo_6"));
        modulo_6->setGeometry(QRect(400, 510, 121, 61));
        modulo_6->setFocusPolicy(Qt::NoFocus);
        modulo_6->setStyleSheet(QLatin1String("#modulo_6{ \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_6->setFlat(true);
        top_bar = new QLabel(centralWidget);
        top_bar->setObjectName(QStringLiteral("top_bar"));
        top_bar->setGeometry(QRect(0, 0, 974, 35));
        top_bar->setAutoFillBackground(false);
        top_bar->setStyleSheet(QLatin1String("#top_bar { \n"
"background-color: transparent;\n"
"border-image: url(:/barras/images/Barras/Indice_diagrama.png); background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_1 = new QPushButton(centralWidget);
        top_menu_1->setObjectName(QStringLiteral("top_menu_1"));
        top_menu_1->setGeometry(QRect(20, 15, 23, 28));
        top_menu_1->setFocusPolicy(Qt::NoFocus);
        top_menu_1->setStyleSheet(QLatin1String("#top_menu_1 { \n"
"background-color: transparent;\n"
"border-image: url(:/iconos/images/Iconos/Campana.png);\n"
"background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_1->setCheckable(true);
        top_menu_2 = new QPushButton(centralWidget);
        top_menu_2->setObjectName(QStringLiteral("top_menu_2"));
        top_menu_2->setGeometry(QRect(70, 15, 35, 28));
        top_menu_2->setFocusPolicy(Qt::NoFocus);
        top_menu_2->setStyleSheet(QLatin1String("#top_menu_2 { \n"
"background-color: transparent;\n"
"border-image: url(:/iconos/images/Iconos/Libro.png);\n"
"background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_2->setCheckable(true);
        top_menu_3 = new QPushButton(centralWidget);
        top_menu_3->setObjectName(QStringLiteral("top_menu_3"));
        top_menu_3->setGeometry(QRect(130, 10, 37, 43));
        top_menu_3->setFocusPolicy(Qt::NoFocus);
        top_menu_3->setStyleSheet(QLatin1String("#top_menu_3 { \n"
"background-color: transparent;\n"
"border-image: url(:/iconos/images/Iconos/Diagrama.png);\n"
"background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_3->setCheckable(true);
        top_menu_4 = new QPushButton(centralWidget);
        top_menu_4->setObjectName(QStringLiteral("top_menu_4"));
        top_menu_4->setGeometry(QRect(10, 60, 41, 31));
        top_menu_4->setFocusPolicy(Qt::NoFocus);
        top_menu_4->setStyleSheet(QLatin1String("#top_menu_4 { \n"
"background-color: transparent;\n"
"border-image: none;\n"
"background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_4->setCheckable(true);
        asa_logo = new QPushButton(centralWidget);
        asa_logo->setObjectName(QStringLiteral("asa_logo"));
        asa_logo->setGeometry(QRect(930, 700, 91, 71));
        asa_logo->setFocusPolicy(Qt::NoFocus);
        asa_logo->setStyleSheet(QLatin1String("#asa_logo{ \n"
"background-image: url(:/iconos/images/Iconos/ASA_logo.png);\n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        asa_logo->setCheckable(true);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 260, 41, 31));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(90, 180, 41, 31));
        widget_2->setStyleSheet(QStringLiteral(""));
        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(170, 180, 41, 31));
        widget_4 = new QWidget(centralWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(290, 540, 41, 31));
        widget_6 = new QWidget(centralWidget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(380, 120, 41, 31));
        widget_7 = new QWidget(centralWidget);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setGeometry(QRect(480, 120, 41, 31));
        widget_8 = new QWidget(centralWidget);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setGeometry(QRect(560, 120, 41, 31));
        widget_9 = new QWidget(centralWidget);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setGeometry(QRect(545, 460, 41, 31));
        widget_9->setStyleSheet(QStringLiteral(""));
        widget_10 = new QWidget(centralWidget);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        widget_10->setGeometry(QRect(670, 120, 41, 31));
        widget_11 = new QWidget(centralWidget);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        widget_11->setGeometry(QRect(770, 120, 41, 31));
        widget_12 = new QWidget(centralWidget);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        widget_12->setGeometry(QRect(860, 120, 41, 31));
        widget_5 = new QWidget(centralWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(300, 120, 41, 31));
        top_menu_5 = new QPushButton(centralWidget);
        top_menu_5->setObjectName(QStringLiteral("top_menu_5"));
        top_menu_5->setGeometry(QRect(190, 15, 34, 30));
        top_menu_5->setFocusPolicy(Qt::NoFocus);
        top_menu_5->setStyleSheet(QLatin1String("#top_menu_5 { \n"
"background-color: transparent;\n"
"border-image: url(:/iconos/images/Iconos/Ajustes_azul.png);\n"
"background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_5->setCheckable(true);
        modulo_7 = new QPushButton(centralWidget);
        modulo_7->setObjectName(QStringLiteral("modulo_7"));
        modulo_7->setGeometry(QRect(100, 390, 101, 51));
        modulo_7->setFocusPolicy(Qt::NoFocus);
        modulo_7->setStyleSheet(QLatin1String("#modulo_7{ \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_7->setFlat(true);
        modulo_8 = new QPushButton(centralWidget);
        modulo_8->setObjectName(QStringLiteral("modulo_8"));
        modulo_8->setGeometry(QRect(770, 230, 91, 61));
        modulo_8->setFocusPolicy(Qt::NoFocus);
        modulo_8->setStyleSheet(QLatin1String("#modulo_8{ \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_8->setFlat(true);
        label_hora = new QLabel(centralWidget);
        label_hora->setObjectName(QStringLiteral("label_hora"));
        label_hora->setGeometry(QRect(770, 10, 251, 31));
        widget_13 = new QWidget(centralWidget);
        widget_13->setObjectName(QStringLiteral("widget_13"));
        widget_13->setGeometry(QRect(860, 500, 41, 31));
        widget_14 = new QWidget(centralWidget);
        widget_14->setObjectName(QStringLiteral("widget_14"));
        widget_14->setGeometry(QRect(860, 550, 41, 31));
        widget_15 = new QWidget(centralWidget);
        widget_15->setObjectName(QStringLiteral("widget_15"));
        widget_15->setGeometry(QRect(790, 590, 41, 31));
        widget_16 = new QWidget(centralWidget);
        widget_16->setObjectName(QStringLiteral("widget_16"));
        widget_16->setGeometry(QRect(550, 620, 41, 31));
        widget_17 = new QWidget(centralWidget);
        widget_17->setObjectName(QStringLiteral("widget_17"));
        widget_17->setGeometry(QRect(470, 620, 41, 31));
        widget_18 = new QWidget(centralWidget);
        widget_18->setObjectName(QStringLiteral("widget_18"));
        widget_18->setGeometry(QRect(400, 620, 41, 31));
        widget_19 = new QWidget(centralWidget);
        widget_19->setObjectName(QStringLiteral("widget_19"));
        widget_19->setGeometry(QRect(40, 500, 41, 31));
        widget_20 = new QWidget(centralWidget);
        widget_20->setObjectName(QStringLiteral("widget_20"));
        widget_20->setGeometry(QRect(40, 550, 41, 31));
        widget_21 = new QWidget(centralWidget);
        widget_21->setObjectName(QStringLiteral("widget_21"));
        widget_21->setGeometry(QRect(40, 600, 41, 31));
        widget_22 = new QWidget(centralWidget);
        widget_22->setObjectName(QStringLiteral("widget_22"));
        widget_22->setGeometry(QRect(920, 220, 41, 31));
        widget_23 = new QWidget(centralWidget);
        widget_23->setObjectName(QStringLiteral("widget_23"));
        widget_23->setGeometry(QRect(920, 290, 41, 31));
        widget_24 = new QWidget(centralWidget);
        widget_24->setObjectName(QStringLiteral("widget_24"));
        widget_24->setGeometry(QRect(920, 360, 41, 31));
        gif_modulo_1 = new QLabel(centralWidget);
        gif_modulo_1->setObjectName(QStringLiteral("gif_modulo_1"));
        gif_modulo_1->setGeometry(QRect(154, 318, 180, 180));
        gif_modulo_1->setStyleSheet(QStringLiteral(""));
        gif_modulo_2 = new QLabel(centralWidget);
        gif_modulo_2->setObjectName(QStringLiteral("gif_modulo_2"));
        gif_modulo_2->setGeometry(QRect(308, 276, 180, 180));
        gif_modulo_2->setStyleSheet(QLatin1String("#gif_modulo_2{\n"
"\n"
"/* x = 321 y = 276 */\n"
"/*background-image: url(:/reactor/images/2_Reactor/reactor.png);*/\n"
"\n"
"/*x= 331 y = 279:  x+10, y+3 */\n"
"/*background-image: url(:/reactor/images/2_Reactor/reac_hi_mov_water.gif);*/\n"
"\n"
"/* x= 319 Y = 275: x-2, y-1*/\n"
"/*background-image: url(:/reactor/images/2_Reactor/reac_hi_quiet_water.png);*/\n"
"\n"
"/*x = 328 y = 291; x+7, y+15*/\n"
"/*background-image: url(:/reactor/images/2_Reactor/reac_med_mov_water_02.gif);*/\n"
"\n"
"/*x=321 y = 296: y+20*/\n"
"/*background-image: url(:/reactor/images/2_Reactor/reac_low_mov_water_01.gif);*/\n"
"}"));
        gif_modulo_3 = new QLabel(centralWidget);
        gif_modulo_3->setObjectName(QStringLiteral("gif_modulo_3"));
        gif_modulo_3->setGeometry(QRect(464, 241, 180, 180));
        gif_modulo_3->setStyleSheet(QLatin1String("#gif_modulo_3{\n"
"\n"
"/* x = 500 y = 238 */\n"
"/*background-image: url(:/clarificador/images/3_Clarificador/clarifier.png);*/\n"
"\n"
"/*x= 331 y = 279:  x+10, y+3 */\n"
"/*background-image: url(:/reactor/images/2_Reactor/reac_hi_mov_water.gif);*/\n"
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
        gif_modulo_4 = new QLabel(centralWidget);
        gif_modulo_4->setObjectName(QStringLiteral("gif_modulo_4"));
        gif_modulo_4->setGeometry(QRect(617, 203, 180, 180));
        gif_modulo_4->setStyleSheet(QLatin1String("#gif_modulo_4{\n"
"\n"
"/* x = 665 y = 196 */\n"
"/*background-image: url(:/clorador/images/4_Clorador/chlorination_empty.png);*/\n"
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
        gif_modulo_5 = new QLabel(centralWidget);
        gif_modulo_5->setObjectName(QStringLiteral("gif_modulo_5"));
        gif_modulo_5->setGeometry(QRect(590, 380, 180, 180));
        gif_modulo_5->setStyleSheet(QLatin1String("#gif_modulo_5{\n"
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
        gif_sludge_a = new QLabel(centralWidget);
        gif_sludge_a->setObjectName(QStringLiteral("gif_sludge_a"));
        gif_sludge_a->setGeometry(QRect(274, 330, 100, 100));
        gif_sludge_a->setStyleSheet(QLatin1String("#gif_sludge_a{\n"
"\n"
"/* x = 639 y = 373 */\n"
"background-image: url(:/flechas/images/0_Flechas_de_flujo/sludge_flow_01_mov.gif);\n"
"background-repeat: none;\n"
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
        gif_sludge_b = new QLabel(centralWidget);
        gif_sludge_b->setObjectName(QStringLiteral("gif_sludge_b"));
        gif_sludge_b->setGeometry(QRect(427, 293, 100, 100));
        gif_sludge_b->setStyleSheet(QLatin1String("#gif_sludge_b{\n"
"\n"
"/* x = 639 y = 373 */\n"
"background-image: url(:/flechas/images/0_Flechas_de_flujo/sludge_flow_01_mov.gif);\n"
"background-repeat: none;\n"
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
        gif_water_flown_a = new QLabel(centralWidget);
        gif_water_flown_a->setObjectName(QStringLiteral("gif_water_flown_a"));
        gif_water_flown_a->setGeometry(QRect(584, 258, 100, 100));
        gif_water_flown_a->setStyleSheet(QLatin1String("#gif_water_flown_a{\n"
"\n"
"/* x = 639 y = 373 */\n"
"	border-image: url(:/flechas/images/0_Flechas_de_flujo/water_flow_01_mov.gif);\n"
"background-repeat: none;\n"
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
        gif_sludge_return_a = new QLabel(centralWidget);
        gif_sludge_return_a->setObjectName(QStringLiteral("gif_sludge_return_a"));
        gif_sludge_return_a->setGeometry(QRect(375, 355, 220, 90));
        gif_sludge_return_a->setStyleSheet(QLatin1String("#gif_sludge_return_a{\n"
"\n"
"/* x = 639 y = 373 */\n"
"	background-image: url(:/flechas/images/0_Flechas_de_flujo/sludge_return_mov.gif);\n"
"	background-repeat: none;\n"
"}"));
        bck_modulo_1 = new QLabel(centralWidget);
        bck_modulo_1->setObjectName(QStringLiteral("bck_modulo_1"));
        bck_modulo_1->setGeometry(QRect(154, 318, 180, 180));
        bck_modulo_1->setStyleSheet(QLatin1String("#bck_modulo_1\n"
"{\n"
"background-image: url(:/carcamo/images/1_Carcamo/carcamo_vacio.png);\n"
"}"));
        bck_modulo_2 = new QLabel(centralWidget);
        bck_modulo_2->setObjectName(QStringLiteral("bck_modulo_2"));
        bck_modulo_2->setGeometry(QRect(308, 276, 180, 180));
        bck_modulo_2->setStyleSheet(QLatin1String("#bck_modulo_2\n"
"{\n"
"background-image: url(:/reactor/images/2_Reactor/reactor.png);\n"
"}"));
        bck_modulo_3 = new QLabel(centralWidget);
        bck_modulo_3->setObjectName(QStringLiteral("bck_modulo_3"));
        bck_modulo_3->setGeometry(QRect(464, 241, 180, 180));
        bck_modulo_3->setStyleSheet(QLatin1String("#bck_modulo_3\n"
"{\n"
"background-image: url(:/clarificador/images/3_Clarificador/clarifier.png);\n"
"}"));
        bck_modulo_4 = new QLabel(centralWidget);
        bck_modulo_4->setObjectName(QStringLiteral("bck_modulo_4"));
        bck_modulo_4->setGeometry(QRect(617, 203, 180, 180));
        bck_modulo_4->setStyleSheet(QLatin1String("#bck_modulo_4\n"
"{\n"
"background-image: url(:/clorador/images/4_Clorador/chlorination_empty.png);\n"
"}"));
        bck_modulo_5 = new QLabel(centralWidget);
        bck_modulo_5->setObjectName(QStringLiteral("bck_modulo_5"));
        bck_modulo_5->setGeometry(QRect(590, 380, 180, 180));
        bck_modulo_5->setStyleSheet(QLatin1String("#bck_modulo_5\n"
"{\n"
"background-image: url(:/digestor/images/5_Digestor/digester_empty.png);\n"
"}"));
        bck_modulo_6 = new QLabel(centralWidget);
        bck_modulo_6->setObjectName(QStringLiteral("bck_modulo_6"));
        bck_modulo_6->setGeometry(QRect(380, 490, 160, 100));
        bck_modulo_6->setStyleSheet(QLatin1String("#bck_modulo_6\n"
"{\n"
"background-image: url(:/lechos/images/6_Lechos/sand_bed_01.png);\n"
"}"));
        gif_modulo_6 = new QLabel(centralWidget);
        gif_modulo_6->setObjectName(QStringLiteral("gif_modulo_6"));
        gif_modulo_6->setGeometry(QRect(380, 490, 160, 100));
        gif_modulo_6->setStyleSheet(QLatin1String("#gif_modulo_5{\n"
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
        gif_modulo_7 = new QLabel(centralWidget);
        gif_modulo_7->setObjectName(QStringLiteral("gif_modulo_7"));
        gif_modulo_7->setGeometry(QRect(100, 360, 110, 110));
        gif_modulo_7->setStyleSheet(QLatin1String("#gif_modulo_5{\n"
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
        gif_modulo_8 = new QLabel(centralWidget);
        gif_modulo_8->setObjectName(QStringLiteral("gif_modulo_8"));
        gif_modulo_8->setGeometry(QRect(750, 210, 110, 110));
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
        MainWindow->setCentralWidget(centralWidget);
        gif_modulo_8->raise();
        bck_modulo_6->raise();
        bck_modulo_5->raise();
        bck_modulo_3->raise();
        bck_modulo_4->raise();
        bottom_bar->raise();
        pushButton->raise();
        pb_fisicos->raise();
        pb_quimicos->raise();
        pb_electricos->raise();
        active_param_label->raise();
        top_bar->raise();
        top_menu_1->raise();
        top_menu_2->raise();
        top_menu_3->raise();
        top_menu_4->raise();
        asa_logo->raise();
        widget->raise();
        widget_2->raise();
        widget_3->raise();
        widget_4->raise();
        widget_6->raise();
        widget_7->raise();
        widget_8->raise();
        widget_9->raise();
        widget_10->raise();
        widget_11->raise();
        widget_12->raise();
        widget_5->raise();
        top_menu_5->raise();
        label_hora->raise();
        widget_13->raise();
        widget_14->raise();
        widget_15->raise();
        widget_16->raise();
        widget_17->raise();
        widget_18->raise();
        widget_19->raise();
        widget_20->raise();
        widget_21->raise();
        widget_22->raise();
        widget_23->raise();
        widget_24->raise();
        gif_water_flown_a->raise();
        gif_sludge_b->raise();
        bck_modulo_2->raise();
        gif_sludge_return_a->raise();
        gif_sludge_a->raise();
        bck_modulo_1->raise();
        gif_modulo_7->raise();
        gif_modulo_1->raise();
        gif_modulo_5->raise();
        gif_modulo_6->raise();
        gif_modulo_3->raise();
        gif_modulo_4->raise();
        gif_modulo_2->raise();
        modulo_4->raise();
        modulo_1->raise();
        modulo_3->raise();
        modulo_6->raise();
        modulo_8->raise();
        modulo_7->raise();
        modulo_5->raise();
        modulo_2->raise();

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
        top_menu_2->setText(QString());
        top_menu_3->setText(QString());
        top_menu_4->setText(QString());
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
        bck_modulo_1->setText(QString());
        bck_modulo_2->setText(QString());
        bck_modulo_3->setText(QString());
        bck_modulo_4->setText(QString());
        bck_modulo_5->setText(QString());
        bck_modulo_6->setText(QString());
        gif_modulo_6->setText(QString());
        gif_modulo_7->setText(QString());
        gif_modulo_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
