/********************************************************************************
** Form generated from reading UI file 'graphwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHWINDOW_H
#define UI_GRAPHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_graphwindow
{
public:
    QGraphicsView *graphicsView;
    QPushButton *top_menu_3;
    QPushButton *top_menu_1;
    QLabel *top_bar;
    QPushButton *top_menu_5;
    QPushButton *top_menu_2;
    QLabel *barra_grafica;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *base_electricos;
    QLabel *label;
    QLabel *base_electricos_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *volts_1;
    QPushButton *volts_2;
    QPushButton *volts_3;
    QPushButton *amps_1;
    QPushButton *amps_2;
    QPushButton *amps_3;
    QWidget *tab_2;
    QPushButton *pb_gasto_acc;
    QLabel *base_fisicos;
    QPushButton *pb_gasto_inst;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QPushButton *pb_nivel_clarif;
    QPushButton *pb_nivel_reg;
    QLabel *label_19;
    QLabel *base_fisicos_2;
    QLabel *label_20;
    QPushButton *pb_presion_aire;
    QLabel *label_21;
    QLabel *base_fisicos_3;
    QPushButton *pb_presion_filt;
    QLabel *label_22;
    QWidget *tab_3;
    QLabel *base_quimicos;
    QPushButton *pb_SST_in;
    QLabel *base_quimicos_2;
    QPushButton *pb_OD_in;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QPushButton *pb_pH_out;
    QPushButton *pb_pH_in;
    QLabel *label_26;
    QLabel *label_27;
    QPushButton *pb_SST_out;
    QLabel *label_28;
    QLabel *label_29;
    QPushButton *pb_OD_out;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QPushButton *pb_Turb_in;
    QPushButton *pb_Turb_out;
    QLabel *label_graph;
    QLabel *dummy;

    void setupUi(QDialog *graphwindow)
    {
        if (graphwindow->objectName().isEmpty())
            graphwindow->setObjectName(QStringLiteral("graphwindow"));
        graphwindow->resize(800, 600);
        graphicsView = new QGraphicsView(graphwindow);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(30, 240, 500, 280));
        graphicsView->setStyleSheet(QLatin1String("#graphicsView\n"
"{\n"
"border-top: none;\n"
"border-left : 1px solid gray;\n"
"border-right : 1px solid gray;\n"
"border-bottom : 1px solid gray;\n"
"}"));
        top_menu_3 = new QPushButton(graphwindow);
        top_menu_3->setObjectName(QStringLiteral("top_menu_3"));
        top_menu_3->setGeometry(QRect(100, 2, 41, 41));
        top_menu_3->setFocusPolicy(Qt::NoFocus);
        top_menu_3->setStyleSheet(QLatin1String("#top_menu_3 { \n"
"background-color: transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/Diagrama.png);\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_3->setCheckable(true);
        top_menu_1 = new QPushButton(graphwindow);
        top_menu_1->setObjectName(QStringLiteral("top_menu_1"));
        top_menu_1->setGeometry(QRect(10, 0, 31, 41));
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
        top_bar = new QLabel(graphwindow);
        top_bar->setObjectName(QStringLiteral("top_bar"));
        top_bar->setGeometry(QRect(0, 0, 759, 27));
        top_bar->setAutoFillBackground(false);
        top_bar->setStyleSheet(QLatin1String("#top_bar { \n"
"background-color: transparent;\n"
"background-image: url(:/barras/screen800x600/barras/PE_bar.png);\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_5 = new QPushButton(graphwindow);
        top_menu_5->setObjectName(QStringLiteral("top_menu_5"));
        top_menu_5->setGeometry(QRect(148, 0, 34, 41));
        top_menu_5->setFocusPolicy(Qt::NoFocus);
        top_menu_5->setStyleSheet(QLatin1String("#top_menu_5 { \n"
"background-color: transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/Ajustes azul.png);\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_5->setCheckable(true);
        top_menu_2 = new QPushButton(graphwindow);
        top_menu_2->setObjectName(QStringLiteral("top_menu_2"));
        top_menu_2->setGeometry(QRect(50, 0, 41, 41));
        top_menu_2->setFocusPolicy(Qt::NoFocus);
        top_menu_2->setStyleSheet(QLatin1String("#top_menu_2 { \n"
"background-color: transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/Bitacora azul.png);\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_2->setCheckable(true);
        barra_grafica = new QLabel(graphwindow);
        barra_grafica->setObjectName(QStringLiteral("barra_grafica"));
        barra_grafica->setGeometry(QRect(30, 220, 461, 31));
        barra_grafica->setStyleSheet(QLatin1String("#barra_grafica { \n"
"background-color: transparent;\n"
"background-image: url(:/barras/screen800x600/barras/barra_grafica.png);\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        tabWidget = new QTabWidget(graphwindow);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 49, 781, 171));
        tabWidget->setStyleSheet(QLatin1String("QTabWidget{\n"
"border:none;\n"
"}\n"
"QTabWidget::tab-bar{\n"
"alignment: right;\n"
"}\n"
"\n"
"QTabBar::tab { min-width:200px; }\n"
"\n"
"QTabBar::tab:!selected{\n"
"background-color: #000000;\n"
"color: rgb(100, 100, 100);\n"
"font-size:12pt;\n"
"height: 50px;\n"
"}\n"
"QTabBar::tab:selected{\n"
"background-color: #000000;\n"
"color:#ffffff;\n"
"/*color: rgb(161, 161, 161)*/\n"
"font-size:12pt;\n"
"height: 50px;\n"
"}"));
        tabWidget->setTabPosition(QTabWidget::North);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        base_electricos = new QLabel(tab);
        base_electricos->setObjectName(QStringLiteral("base_electricos"));
        base_electricos->setGeometry(QRect(40, 40, 181, 41));
        base_electricos->setStyleSheet(QLatin1String("#base_electricos { \n"
"background-color: transparent;\n"
"background-image: url(:/barras/screen800x600/barras/Base 2 azul.png);\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 181, 31));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        base_electricos_2 = new QLabel(tab);
        base_electricos_2->setObjectName(QStringLiteral("base_electricos_2"));
        base_electricos_2->setGeometry(QRect(480, 40, 181, 41));
        base_electricos_2->setStyleSheet(QLatin1String("#base_electricos_2 { \n"
"background-color: transparent;\n"
"background-image: url(:/barras/screen800x600/barras/Base 2 azul.png);\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(480, 10, 181, 31));
        label_2->setFont(font);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 40, 41, 21));
        QFont font1;
        font1.setPointSize(10);
        label_3->setFont(font1);
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 40, 41, 21));
        label_4->setFont(font1);
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(170, 40, 41, 21));
        label_5->setFont(font1);
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(490, 40, 41, 21));
        label_11->setFont(font1);
        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(610, 40, 41, 21));
        label_12->setFont(font1);
        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(550, 40, 41, 21));
        label_13->setFont(font1);
        volts_1 = new QPushButton(tab);
        volts_1->setObjectName(QStringLiteral("volts_1"));
        volts_1->setGeometry(QRect(50, 50, 41, 41));
        QFont font2;
        font2.setPointSize(14);
        volts_1->setFont(font2);
        volts_1->setFocusPolicy(Qt::NoFocus);
        volts_1->setStyleSheet(QLatin1String("#volts_1 { \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        volts_1->setFlat(true);
        volts_2 = new QPushButton(tab);
        volts_2->setObjectName(QStringLiteral("volts_2"));
        volts_2->setGeometry(QRect(110, 50, 41, 41));
        volts_2->setFont(font2);
        volts_2->setFocusPolicy(Qt::NoFocus);
        volts_2->setStyleSheet(QLatin1String("#volts_2 { \n"
"background-color: transparent;\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        volts_2->setFlat(true);
        volts_3 = new QPushButton(tab);
        volts_3->setObjectName(QStringLiteral("volts_3"));
        volts_3->setGeometry(QRect(170, 50, 41, 41));
        volts_3->setFont(font2);
        volts_3->setFocusPolicy(Qt::NoFocus);
        volts_3->setStyleSheet(QLatin1String("#volts_3 { \n"
"background-color: transparent;\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        volts_3->setFlat(true);
        amps_1 = new QPushButton(tab);
        amps_1->setObjectName(QStringLiteral("amps_1"));
        amps_1->setGeometry(QRect(490, 50, 41, 41));
        amps_1->setFont(font2);
        amps_1->setFocusPolicy(Qt::NoFocus);
        amps_1->setStyleSheet(QLatin1String("#amps_1 { \n"
"background-color: transparent;\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        amps_1->setFlat(true);
        amps_2 = new QPushButton(tab);
        amps_2->setObjectName(QStringLiteral("amps_2"));
        amps_2->setGeometry(QRect(550, 50, 41, 41));
        amps_2->setFont(font2);
        amps_2->setFocusPolicy(Qt::NoFocus);
        amps_2->setStyleSheet(QLatin1String("#amps_2 { \n"
"background-color: transparent;\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        amps_2->setFlat(true);
        amps_3 = new QPushButton(tab);
        amps_3->setObjectName(QStringLiteral("amps_3"));
        amps_3->setGeometry(QRect(610, 50, 41, 41));
        amps_3->setFont(font2);
        amps_3->setFocusPolicy(Qt::NoFocus);
        amps_3->setStyleSheet(QLatin1String("#amps_3 { \n"
"background-color: transparent;\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        amps_3->setFlat(true);
        tabWidget->addTab(tab, QString());
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_11->raise();
        label_12->raise();
        label_13->raise();
        base_electricos_2->raise();
        base_electricos->raise();
        volts_3->raise();
        volts_1->raise();
        amps_2->raise();
        volts_2->raise();
        amps_3->raise();
        amps_1->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        pb_gasto_acc = new QPushButton(tab_2);
        pb_gasto_acc->setObjectName(QStringLiteral("pb_gasto_acc"));
        pb_gasto_acc->setGeometry(QRect(150, 50, 41, 41));
        pb_gasto_acc->setFont(font2);
        pb_gasto_acc->setFocusPolicy(Qt::NoFocus);
        pb_gasto_acc->setStyleSheet(QLatin1String("#volts_3 { \n"
"background-color: transparent;\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pb_gasto_acc->setFlat(true);
        base_fisicos = new QLabel(tab_2);
        base_fisicos->setObjectName(QStringLiteral("base_fisicos"));
        base_fisicos->setGeometry(QRect(40, 40, 181, 41));
        base_fisicos->setStyleSheet(QLatin1String("#base_fisicos { \n"
"background-color: transparent;\n"
"background-image: url(:/barras/screen800x600/barras/Base 1 azul.png);\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pb_gasto_inst = new QPushButton(tab_2);
        pb_gasto_inst->setObjectName(QStringLiteral("pb_gasto_inst"));
        pb_gasto_inst->setGeometry(QRect(60, 50, 41, 41));
        pb_gasto_inst->setFont(font2);
        pb_gasto_inst->setFocusPolicy(Qt::NoFocus);
        pb_gasto_inst->setStyleSheet(QLatin1String("#volts_2 { \n"
"background-color: transparent;\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pb_gasto_inst->setFlat(true);
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(40, 10, 181, 31));
        label_14->setFont(font);
        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(40, 40, 81, 21));
        label_15->setFont(font1);
        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(130, 40, 91, 21));
        label_16->setFont(font1);
        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(380, 40, 91, 21));
        label_17->setFont(font1);
        label_18 = new QLabel(tab_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(290, 40, 81, 21));
        label_18->setFont(font1);
        pb_nivel_clarif = new QPushButton(tab_2);
        pb_nivel_clarif->setObjectName(QStringLiteral("pb_nivel_clarif"));
        pb_nivel_clarif->setGeometry(QRect(400, 50, 41, 41));
        pb_nivel_clarif->setFont(font2);
        pb_nivel_clarif->setFocusPolicy(Qt::NoFocus);
        pb_nivel_clarif->setStyleSheet(QLatin1String("#volts_3 { \n"
"background-color: transparent;\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pb_nivel_clarif->setFlat(true);
        pb_nivel_reg = new QPushButton(tab_2);
        pb_nivel_reg->setObjectName(QStringLiteral("pb_nivel_reg"));
        pb_nivel_reg->setGeometry(QRect(310, 50, 41, 41));
        pb_nivel_reg->setFont(font2);
        pb_nivel_reg->setFocusPolicy(Qt::NoFocus);
        pb_nivel_reg->setStyleSheet(QLatin1String("#volts_2 { \n"
"background-color: transparent;\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pb_nivel_reg->setFlat(true);
        label_19 = new QLabel(tab_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(290, 10, 181, 31));
        label_19->setFont(font);
        base_fisicos_2 = new QLabel(tab_2);
        base_fisicos_2->setObjectName(QStringLiteral("base_fisicos_2"));
        base_fisicos_2->setGeometry(QRect(290, 40, 181, 41));
        base_fisicos_2->setStyleSheet(QLatin1String("#base_fisicos_2 { \n"
"background-color: transparent;\n"
"background-image: url(:/barras/screen800x600/barras/Base 1 azul.png);\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        label_20 = new QLabel(tab_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(630, 40, 91, 21));
        label_20->setFont(font1);
        pb_presion_aire = new QPushButton(tab_2);
        pb_presion_aire->setObjectName(QStringLiteral("pb_presion_aire"));
        pb_presion_aire->setGeometry(QRect(560, 50, 41, 41));
        pb_presion_aire->setFont(font2);
        pb_presion_aire->setFocusPolicy(Qt::NoFocus);
        pb_presion_aire->setStyleSheet(QLatin1String("#volts_2 { \n"
"background-color: transparent;\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pb_presion_aire->setFlat(true);
        label_21 = new QLabel(tab_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(540, 10, 181, 31));
        label_21->setFont(font);
        base_fisicos_3 = new QLabel(tab_2);
        base_fisicos_3->setObjectName(QStringLiteral("base_fisicos_3"));
        base_fisicos_3->setGeometry(QRect(540, 40, 181, 41));
        base_fisicos_3->setStyleSheet(QLatin1String("#base_fisicos_3 { \n"
"background-color: transparent;\n"
"background-image: url(:/barras/screen800x600/barras/Base 1 azul.png);\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pb_presion_filt = new QPushButton(tab_2);
        pb_presion_filt->setObjectName(QStringLiteral("pb_presion_filt"));
        pb_presion_filt->setGeometry(QRect(650, 50, 41, 41));
        pb_presion_filt->setFont(font2);
        pb_presion_filt->setFocusPolicy(Qt::NoFocus);
        pb_presion_filt->setStyleSheet(QLatin1String("#volts_3 { \n"
"background-color: transparent;\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pb_presion_filt->setFlat(true);
        label_22 = new QLabel(tab_2);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(540, 40, 81, 21));
        label_22->setFont(font1);
        tabWidget->addTab(tab_2, QString());
        label_14->raise();
        label_15->raise();
        label_16->raise();
        label_17->raise();
        label_18->raise();
        label_19->raise();
        label_21->raise();
        label_22->raise();
        label_20->raise();
        base_fisicos_3->raise();
        base_fisicos->raise();
        base_fisicos_2->raise();
        pb_gasto_acc->raise();
        pb_nivel_reg->raise();
        pb_presion_aire->raise();
        pb_presion_filt->raise();
        pb_gasto_inst->raise();
        pb_nivel_clarif->raise();
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        base_quimicos = new QLabel(tab_3);
        base_quimicos->setObjectName(QStringLiteral("base_quimicos"));
        base_quimicos->setGeometry(QRect(480, 40, 271, 41));
        base_quimicos->setStyleSheet(QLatin1String("#base_quimicos { \n"
"background-color: transparent;\n"
"background-image: url(:/barras/screen800x600/barras/Base 2 azul.png);\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pb_SST_in = new QPushButton(tab_3);
        pb_SST_in->setObjectName(QStringLiteral("pb_SST_in"));
        pb_SST_in->setGeometry(QRect(170, 50, 41, 41));
        pb_SST_in->setFont(font2);
        pb_SST_in->setFocusPolicy(Qt::NoFocus);
        pb_SST_in->setStyleSheet(QLatin1String("#volts_3 { \n"
"background-color: transparent;\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pb_SST_in->setFlat(true);
        base_quimicos_2 = new QLabel(tab_3);
        base_quimicos_2->setObjectName(QStringLiteral("base_quimicos_2"));
        base_quimicos_2->setGeometry(QRect(40, 40, 271, 41));
        base_quimicos_2->setStyleSheet(QLatin1String("#base_quimicos_2 { \n"
"background-color: transparent;\n"
"background-image: url(:/barras/screen800x600/barras/Base 2 azul.png);\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pb_OD_in = new QPushButton(tab_3);
        pb_OD_in->setObjectName(QStringLiteral("pb_OD_in"));
        pb_OD_in->setGeometry(QRect(50, 50, 41, 41));
        pb_OD_in->setFont(font2);
        pb_OD_in->setFocusPolicy(Qt::NoFocus);
        pb_OD_in->setStyleSheet(QLatin1String("#volts_1 { \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        pb_OD_in->setFlat(true);
        label_23 = new QLabel(tab_3);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(490, 40, 41, 21));
        label_23->setFont(font1);
        label_24 = new QLabel(tab_3);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(50, 40, 41, 21));
        label_24->setFont(font1);
        label_25 = new QLabel(tab_3);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(480, 10, 181, 31));
        label_25->setFont(font);
        pb_pH_out = new QPushButton(tab_3);
        pb_pH_out->setObjectName(QStringLiteral("pb_pH_out"));
        pb_pH_out->setGeometry(QRect(550, 50, 41, 41));
        pb_pH_out->setFont(font2);
        pb_pH_out->setFocusPolicy(Qt::NoFocus);
        pb_pH_out->setStyleSheet(QLatin1String("#amps_2 { \n"
"background-color: transparent;\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pb_pH_out->setFlat(true);
        pb_pH_in = new QPushButton(tab_3);
        pb_pH_in->setObjectName(QStringLiteral("pb_pH_in"));
        pb_pH_in->setGeometry(QRect(110, 50, 41, 41));
        pb_pH_in->setFont(font2);
        pb_pH_in->setFocusPolicy(Qt::NoFocus);
        pb_pH_in->setStyleSheet(QLatin1String("#volts_2 { \n"
"background-color: transparent;\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pb_pH_in->setFlat(true);
        label_26 = new QLabel(tab_3);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(610, 40, 41, 21));
        label_26->setFont(font1);
        label_27 = new QLabel(tab_3);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(170, 40, 41, 21));
        label_27->setFont(font1);
        pb_SST_out = new QPushButton(tab_3);
        pb_SST_out->setObjectName(QStringLiteral("pb_SST_out"));
        pb_SST_out->setGeometry(QRect(610, 50, 41, 41));
        pb_SST_out->setFont(font2);
        pb_SST_out->setFocusPolicy(Qt::NoFocus);
        pb_SST_out->setStyleSheet(QLatin1String("#amps_3 { \n"
"background-color: transparent;\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pb_SST_out->setFlat(true);
        label_28 = new QLabel(tab_3);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(550, 40, 41, 21));
        label_28->setFont(font1);
        label_29 = new QLabel(tab_3);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(40, 10, 181, 31));
        label_29->setFont(font);
        pb_OD_out = new QPushButton(tab_3);
        pb_OD_out->setObjectName(QStringLiteral("pb_OD_out"));
        pb_OD_out->setGeometry(QRect(490, 50, 41, 41));
        pb_OD_out->setFont(font2);
        pb_OD_out->setFocusPolicy(Qt::NoFocus);
        pb_OD_out->setStyleSheet(QLatin1String("#amps_1 { \n"
"background-color: transparent;\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pb_OD_out->setFlat(true);
        label_30 = new QLabel(tab_3);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(110, 40, 41, 21));
        label_30->setFont(font1);
        label_31 = new QLabel(tab_3);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(240, 40, 61, 21));
        label_31->setFont(font1);
        label_32 = new QLabel(tab_3);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(680, 40, 61, 21));
        label_32->setFont(font1);
        pb_Turb_in = new QPushButton(tab_3);
        pb_Turb_in->setObjectName(QStringLiteral("pb_Turb_in"));
        pb_Turb_in->setGeometry(QRect(250, 50, 41, 41));
        pb_Turb_in->setFont(font2);
        pb_Turb_in->setFocusPolicy(Qt::NoFocus);
        pb_Turb_in->setStyleSheet(QLatin1String("#volts_3 { \n"
"background-color: transparent;\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pb_Turb_in->setFlat(true);
        pb_Turb_out = new QPushButton(tab_3);
        pb_Turb_out->setObjectName(QStringLiteral("pb_Turb_out"));
        pb_Turb_out->setGeometry(QRect(690, 50, 41, 41));
        pb_Turb_out->setFont(font2);
        pb_Turb_out->setFocusPolicy(Qt::NoFocus);
        pb_Turb_out->setStyleSheet(QLatin1String("#volts_3 { \n"
"background-color: transparent;\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pb_Turb_out->setFlat(true);
        tabWidget->addTab(tab_3, QString());
        label_23->raise();
        label_24->raise();
        label_25->raise();
        label_26->raise();
        label_27->raise();
        label_28->raise();
        label_29->raise();
        label_30->raise();
        label_31->raise();
        label_32->raise();
        base_quimicos_2->raise();
        base_quimicos->raise();
        pb_Turb_in->raise();
        pb_Turb_out->raise();
        pb_SST_out->raise();
        pb_OD_in->raise();
        pb_SST_in->raise();
        pb_pH_in->raise();
        pb_OD_out->raise();
        pb_pH_out->raise();
        label_graph = new QLabel(graphwindow);
        label_graph->setObjectName(QStringLiteral("label_graph"));
        label_graph->setGeometry(QRect(36, 221, 171, 21));
        QFont font3;
        font3.setPointSize(12);
        label_graph->setFont(font3);
        label_graph->setStyleSheet(QLatin1String("#label_graph\n"
"{\n"
"background-color: transparent;\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
"}"));
        dummy = new QLabel(graphwindow);
        dummy->setObjectName(QStringLiteral("dummy"));
        dummy->setGeometry(QRect(0, 360, 881, 261));
        dummy->setStyleSheet(QLatin1String("#dummy { \n"
"background-color: transparent;\n"
"background-image: url(:/diagrama/screen800x600/diagrama/PE.png);\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        dummy->raise();
        graphicsView->raise();
        barra_grafica->raise();
        top_bar->raise();
        top_menu_3->raise();
        top_menu_1->raise();
        top_menu_5->raise();
        top_menu_2->raise();
        tabWidget->raise();
        label_graph->raise();

        retranslateUi(graphwindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(graphwindow);
    } // setupUi

    void retranslateUi(QDialog *graphwindow)
    {
        graphwindow->setWindowTitle(QApplication::translate("graphwindow", "Dialog", 0));
        top_menu_3->setText(QString());
        top_menu_1->setText(QString());
        top_bar->setText(QString());
        top_menu_5->setText(QString());
        top_menu_2->setText(QString());
        barra_grafica->setText(QString());
        base_electricos->setText(QString());
        label->setText(QApplication::translate("graphwindow", "Voltaje", 0));
        base_electricos_2->setText(QString());
        label_2->setText(QApplication::translate("graphwindow", "Amperaje", 0));
        label_3->setText(QApplication::translate("graphwindow", "L1-L2", 0));
        label_4->setText(QApplication::translate("graphwindow", "L2-L3", 0));
        label_5->setText(QApplication::translate("graphwindow", "L3-L1", 0));
        label_11->setText(QApplication::translate("graphwindow", "L1-L2", 0));
        label_12->setText(QApplication::translate("graphwindow", "L3-L1", 0));
        label_13->setText(QApplication::translate("graphwindow", "L2-L3", 0));
        volts_1->setText(QString());
        volts_2->setText(QString());
        volts_3->setText(QString());
        amps_1->setText(QString());
        amps_2->setText(QString());
        amps_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("graphwindow", "Electricos", 0));
        pb_gasto_acc->setText(QString());
        base_fisicos->setText(QString());
        pb_gasto_inst->setText(QString());
        label_14->setText(QApplication::translate("graphwindow", "Gasto", 0));
        label_15->setText(QApplication::translate("graphwindow", "Instant\303\241neo", 0));
        label_16->setText(QApplication::translate("graphwindow", "Acumulado", 0));
        label_17->setText(QApplication::translate("graphwindow", "Clarificador", 0));
        label_18->setText(QApplication::translate("graphwindow", "Regulador", 0));
        pb_nivel_clarif->setText(QString());
        pb_nivel_reg->setText(QString());
        label_19->setText(QApplication::translate("graphwindow", "Nivel", 0));
        base_fisicos_2->setText(QString());
        label_20->setText(QApplication::translate("graphwindow", "Filtraci\303\263n", 0));
        pb_presion_aire->setText(QString());
        label_21->setText(QApplication::translate("graphwindow", "Presion", 0));
        base_fisicos_3->setText(QString());
        pb_presion_filt->setText(QString());
        label_22->setText(QApplication::translate("graphwindow", "Aireador", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("graphwindow", "Fisicos", 0));
        base_quimicos->setText(QString());
        pb_SST_in->setText(QString());
        base_quimicos_2->setText(QString());
        pb_OD_in->setText(QString());
        label_23->setText(QApplication::translate("graphwindow", "OD", 0));
        label_24->setText(QApplication::translate("graphwindow", "OD", 0));
        label_25->setText(QApplication::translate("graphwindow", "Salida", 0));
        pb_pH_out->setText(QString());
        pb_pH_in->setText(QString());
        label_26->setText(QApplication::translate("graphwindow", "SST", 0));
        label_27->setText(QApplication::translate("graphwindow", "SST", 0));
        pb_SST_out->setText(QString());
        label_28->setText(QApplication::translate("graphwindow", "pH", 0));
        label_29->setText(QApplication::translate("graphwindow", "Entrada", 0));
        pb_OD_out->setText(QString());
        label_30->setText(QApplication::translate("graphwindow", "pH", 0));
        label_31->setText(QApplication::translate("graphwindow", "Turbidez", 0));
        label_32->setText(QApplication::translate("graphwindow", "Turbidez", 0));
        pb_Turb_in->setText(QString());
        pb_Turb_out->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("graphwindow", "Quimicos", 0));
        label_graph->setText(QApplication::translate("graphwindow", "Voltaje", 0));
        dummy->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class graphwindow: public Ui_graphwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHWINDOW_H
