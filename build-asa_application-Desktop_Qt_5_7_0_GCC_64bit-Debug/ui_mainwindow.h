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
#include <QtWidgets/QListWidget>
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
    QListWidget *tip_reg_elec;
    QListWidget *tip_reg_phys;
    QListWidget *tip_reac_elec;
    QListWidget *tip_reac_phys;
    QListWidget *tip_reac_chem;

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
""));
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
        modulo_1->setGeometry(QRect(170, 280, 91, 91));
        modulo_1->setFocusPolicy(Qt::NoFocus);
        modulo_1->setStyleSheet(QStringLiteral(""));
        modulo_1->setFlat(true);
        modulo_2 = new QPushButton(centralWidget);
        modulo_2->setObjectName(QStringLiteral("modulo_2"));
        modulo_2->setGeometry(QRect(360, 230, 91, 91));
        modulo_2->setFocusPolicy(Qt::NoFocus);
        modulo_2->setStyleSheet(QStringLiteral(""));
        modulo_2->setFlat(true);
        modulo_3 = new QPushButton(centralWidget);
        modulo_3->setObjectName(QStringLiteral("modulo_3"));
        modulo_3->setGeometry(QRect(550, 180, 91, 91));
        modulo_3->setFocusPolicy(Qt::NoFocus);
        modulo_3->setStyleSheet(QStringLiteral(""));
        modulo_3->setFlat(true);
        modulo_4 = new QPushButton(centralWidget);
        modulo_4->setObjectName(QStringLiteral("modulo_4"));
        modulo_4->setGeometry(QRect(750, 130, 91, 91));
        modulo_4->setFocusPolicy(Qt::NoFocus);
        modulo_4->setStyleSheet(QStringLiteral(""));
        modulo_4->setFlat(true);
        modulo_5 = new QPushButton(centralWidget);
        modulo_5->setObjectName(QStringLiteral("modulo_5"));
        modulo_5->setGeometry(QRect(760, 340, 91, 91));
        modulo_5->setFocusPolicy(Qt::NoFocus);
        modulo_5->setStyleSheet(QStringLiteral(""));
        modulo_5->setFlat(true);
        modulo_6 = new QPushButton(centralWidget);
        modulo_6->setObjectName(QStringLiteral("modulo_6"));
        modulo_6->setGeometry(QRect(470, 420, 91, 91));
        modulo_6->setFocusPolicy(Qt::NoFocus);
        modulo_6->setStyleSheet(QStringLiteral(""));
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
        tip_reg_elec = new QListWidget(centralWidget);
        tip_reg_elec->setObjectName(QStringLiteral("tip_reg_elec"));
        tip_reg_elec->setGeometry(QRect(90, 210, 81, 51));
        tip_reg_phys = new QListWidget(centralWidget);
        tip_reg_phys->setObjectName(QStringLiteral("tip_reg_phys"));
        tip_reg_phys->setGeometry(QRect(70, 340, 81, 51));
        tip_reac_elec = new QListWidget(centralWidget);
        tip_reac_elec->setObjectName(QStringLiteral("tip_reac_elec"));
        tip_reac_elec->setGeometry(QRect(250, 180, 81, 51));
        tip_reac_phys = new QListWidget(centralWidget);
        tip_reac_phys->setObjectName(QStringLiteral("tip_reac_phys"));
        tip_reac_phys->setGeometry(QRect(350, 110, 81, 51));
        tip_reac_chem = new QListWidget(centralWidget);
        tip_reac_chem->setObjectName(QStringLiteral("tip_reac_chem"));
        tip_reac_chem->setGeometry(QRect(440, 120, 91, 91));
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
        tip_reg_elec->raise();
        tip_reg_phys->raise();
        tip_reac_elec->raise();
        tip_reac_phys->raise();
        tip_reac_chem->raise();

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
