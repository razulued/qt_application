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
    QLabel *plant_image;
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
    QWidget *widget_5;
    QWidget *widget_6;
    QWidget *widget_7;
    QWidget *widget_8;
    QWidget *widget_9;
    QWidget *widget_10;
    QWidget *widget_11;
    QWidget *widget_12;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 768);
        MainWindow->setMinimumSize(QSize(1024, 768));
        MainWindow->setMaximumSize(QSize(1024, 769));
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
        plant_image = new QLabel(centralWidget);
        plant_image->setObjectName(QStringLiteral("plant_image"));
        plant_image->setGeometry(QRect(50, 80, 921, 501));
        plant_image->setStyleSheet(QLatin1String("#plant_image{ \n"
"background-color: transparent;\n"
"border-image: url(:/images/images/planta.png); \n"
"background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        modulo_1 = new QPushButton(centralWidget);
        modulo_1->setObjectName(QStringLiteral("modulo_1"));
        modulo_1->setGeometry(QRect(140, 240, 131, 121));
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
        modulo_2->setGeometry(QRect(340, 200, 131, 111));
        modulo_2->setFocusPolicy(Qt::NoFocus);
        modulo_2->setStyleSheet(QLatin1String("#modulo_2{ \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_2->setFlat(true);
        modulo_3 = new QPushButton(centralWidget);
        modulo_3->setObjectName(QStringLiteral("modulo_3"));
        modulo_3->setGeometry(QRect(550, 150, 131, 121));
        modulo_3->setFocusPolicy(Qt::NoFocus);
        modulo_3->setStyleSheet(QLatin1String("#modulo_3 { \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_3->setFlat(true);
        modulo_4 = new QPushButton(centralWidget);
        modulo_4->setObjectName(QStringLiteral("modulo_4"));
        modulo_4->setGeometry(QRect(750, 90, 121, 121));
        modulo_4->setFocusPolicy(Qt::NoFocus);
        modulo_4->setStyleSheet(QLatin1String("#modulo_4 { \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_4->setFlat(true);
        modulo_5 = new QPushButton(centralWidget);
        modulo_5->setObjectName(QStringLiteral("modulo_5"));
        modulo_5->setGeometry(QRect(760, 300, 121, 111));
        modulo_5->setFocusPolicy(Qt::NoFocus);
        modulo_5->setStyleSheet(QLatin1String("#modulo_5 { \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_5->setFlat(true);
        modulo_6 = new QPushButton(centralWidget);
        modulo_6->setObjectName(QStringLiteral("modulo_6"));
        modulo_6->setGeometry(QRect(430, 420, 191, 111));
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
        top_menu_4->setGeometry(QRect(190, 14, 41, 31));
        top_menu_4->setFocusPolicy(Qt::NoFocus);
        top_menu_4->setStyleSheet(QLatin1String("#top_menu_4 { \n"
"background-color: transparent;\n"
"border-image: url(:/iconos/images/Iconos/compu_logo.png);\n"
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
        widget->setGeometry(QRect(40, 330, 81, 61));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(50, 170, 81, 61));
        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(160, 160, 81, 61));
        widget_4 = new QWidget(centralWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(270, 140, 81, 61));
        widget_5 = new QWidget(centralWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(330, 60, 81, 61));
        widget_6 = new QWidget(centralWidget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(420, 120, 81, 61));
        widget_7 = new QWidget(centralWidget);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setGeometry(QRect(520, 80, 81, 61));
        widget_8 = new QWidget(centralWidget);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setGeometry(QRect(610, 40, 81, 61));
        widget_9 = new QWidget(centralWidget);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setGeometry(QRect(670, 160, 81, 61));
        widget_10 = new QWidget(centralWidget);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        widget_10->setGeometry(QRect(720, 30, 81, 61));
        widget_11 = new QWidget(centralWidget);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        widget_11->setGeometry(QRect(860, 20, 81, 61));
        widget_12 = new QWidget(centralWidget);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        widget_12->setGeometry(QRect(890, 100, 81, 61));
        MainWindow->setCentralWidget(centralWidget);
        bottom_bar->raise();
        pushButton->raise();
        pb_fisicos->raise();
        pb_quimicos->raise();
        pb_electricos->raise();
        active_param_label->raise();
        plant_image->raise();
        modulo_1->raise();
        modulo_2->raise();
        modulo_3->raise();
        modulo_4->raise();
        modulo_5->raise();
        modulo_6->raise();
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
        widget_5->raise();
        widget_6->raise();
        widget_7->raise();
        widget_8->raise();
        widget_9->raise();
        widget_10->raise();
        widget_11->raise();
        widget_12->raise();

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
        plant_image->setText(QString());
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
