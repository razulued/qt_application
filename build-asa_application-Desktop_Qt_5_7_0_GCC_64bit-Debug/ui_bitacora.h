/********************************************************************************
** Form generated from reading UI file 'bitacora.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BITACORA_H
#define UI_BITACORA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bitacora
{
public:
    QPushButton *top_menu_4;
    QPushButton *top_menu_3;
    QPushButton *top_menu_1;
    QPushButton *top_menu_2;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *tableWidget_2;
    QLabel *label_2;
    QPushButton *key_6;
    QPushButton *key_0;
    QLabel *label_horas;
    QPushButton *key_2;
    QPushButton *key_3;
    QPushButton *key_9;
    QPushButton *key_Reschedule;
    QPushButton *key_7;
    QPushButton *key_4;
    QPushButton *key_5;
    QPushButton *key_OK;
    QPushButton *key_8;
    QPushButton *key_1;
    QPushButton *key_back;
    QWidget *tab_2;
    QTableWidget *tableWidget;

    void setupUi(QDialog *bitacora)
    {
        if (bitacora->objectName().isEmpty())
            bitacora->setObjectName(QStringLiteral("bitacora"));
        bitacora->resize(1024, 768);
        bitacora->setMinimumSize(QSize(1024, 768));
        bitacora->setMaximumSize(QSize(1024, 768));
        bitacora->setStyleSheet(QStringLiteral(""));
        top_menu_4 = new QPushButton(bitacora);
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
        top_menu_3 = new QPushButton(bitacora);
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
        top_menu_1 = new QPushButton(bitacora);
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
        top_menu_2 = new QPushButton(bitacora);
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
        label = new QLabel(bitacora);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(270, 10, 341, 41));
        tabWidget = new QTabWidget(bitacora);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 9, 1021, 761));
        tabWidget->setStyleSheet(QLatin1String("QTabWidget::tab-bar{\n"
"alignment: right;\n"
"}\n"
"\n"
"QTabBar::tab { min-width:200px; }\n"
"\n"
"QTabBar::tab:!selected{\n"
"background-color: #000000;\n"
"color:#ffffff;font-size:8pt;\n"
"height: 50px;\n"
"}\n"
"QTabBar::tab:selected{\n"
"background-color: #000000;\n"
"color:#ffffff;\n"
"font-size:12pt;\n"
"height: 50px;\n"
"}"));
        tabWidget->setTabPosition(QTabWidget::North);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tableWidget_2 = new QTableWidget(tab);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(3, 0, 1011, 571));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 640, 401, 51));
        label_2->setWordWrap(true);
        key_6 = new QPushButton(tab);
        key_6->setObjectName(QStringLiteral("key_6"));
        key_6->setGeometry(QRect(848, 617, 40, 40));
        key_6->setFocusPolicy(Qt::NoFocus);
        key_6->setStyleSheet(QLatin1String("#key_6{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/6_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_6::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/6_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_6->setCheckable(false);
        key_0 = new QPushButton(tab);
        key_0->setObjectName(QStringLiteral("key_0"));
        key_0->setGeometry(QRect(752, 660, 40, 40));
        key_0->setFocusPolicy(Qt::NoFocus);
        key_0->setStyleSheet(QLatin1String("#key_0{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/0_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_0::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/0_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_0->setCheckable(false);
        label_horas = new QLabel(tab);
        label_horas->setObjectName(QStringLiteral("label_horas"));
        label_horas->setGeometry(QRect(608, 578, 91, 31));
        key_2 = new QPushButton(tab);
        key_2->setObjectName(QStringLiteral("key_2"));
        key_2->setGeometry(QRect(654, 617, 40, 40));
        key_2->setFocusPolicy(Qt::NoFocus);
        key_2->setStyleSheet(QLatin1String("#key_2{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/2_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_2::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/2_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_2->setCheckable(false);
        key_3 = new QPushButton(tab);
        key_3->setObjectName(QStringLiteral("key_3"));
        key_3->setGeometry(QRect(703, 617, 40, 40));
        key_3->setFocusPolicy(Qt::NoFocus);
        key_3->setStyleSheet(QLatin1String("#key_3{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/3_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_3::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/3_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_3->setCheckable(false);
        key_9 = new QPushButton(tab);
        key_9->setObjectName(QStringLiteral("key_9"));
        key_9->setGeometry(QRect(703, 660, 40, 40));
        key_9->setFocusPolicy(Qt::NoFocus);
        key_9->setStyleSheet(QLatin1String("#key_9{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/9_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_9::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/9_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_9->setCheckable(false);
        key_Reschedule = new QPushButton(tab);
        key_Reschedule->setObjectName(QStringLiteral("key_Reschedule"));
        key_Reschedule->setGeometry(QRect(698, 569, 41, 41));
        key_Reschedule->setFocusPolicy(Qt::NoFocus);
        key_Reschedule->setStyleSheet(QLatin1String("#key_Reschedule{ \n"
"background-image: url(:/iconos/images/Iconos/Posponer_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_Reschedule::pressed{ \n"
"background-image: url(:/iconos/images/Iconos/Posponer_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_Reschedule->setCheckable(false);
        key_7 = new QPushButton(tab);
        key_7->setObjectName(QStringLiteral("key_7"));
        key_7->setGeometry(QRect(604, 660, 40, 40));
        key_7->setFocusPolicy(Qt::NoFocus);
        key_7->setStyleSheet(QLatin1String("#key_7{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/7_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_7::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/7_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_7->setCheckable(false);
        key_4 = new QPushButton(tab);
        key_4->setObjectName(QStringLiteral("key_4"));
        key_4->setGeometry(QRect(752, 617, 40, 40));
        key_4->setFocusPolicy(Qt::NoFocus);
        key_4->setStyleSheet(QLatin1String("#key_4{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/4_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_4::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/4_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_4->setCheckable(false);
        key_5 = new QPushButton(tab);
        key_5->setObjectName(QStringLiteral("key_5"));
        key_5->setGeometry(QRect(800, 617, 40, 40));
        key_5->setFocusPolicy(Qt::NoFocus);
        key_5->setStyleSheet(QLatin1String("#key_5{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/5_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_5::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/5_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_5->setCheckable(false);
        key_OK = new QPushButton(tab);
        key_OK->setObjectName(QStringLiteral("key_OK"));
        key_OK->setGeometry(QRect(809, 571, 81, 41));
        key_OK->setFocusPolicy(Qt::NoFocus);
        key_OK->setStyleSheet(QLatin1String("#key_OK{ \n"
"background-image: url(:/iconos/images/Iconos/Ok_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_OK::pressed{ \n"
"background-image: url(:/iconos/images/Iconos/Ok_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_OK->setCheckable(false);
        key_8 = new QPushButton(tab);
        key_8->setObjectName(QStringLiteral("key_8"));
        key_8->setGeometry(QRect(654, 660, 40, 40));
        key_8->setFocusPolicy(Qt::NoFocus);
        key_8->setStyleSheet(QLatin1String("#key_8{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/8_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_8::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/8_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_8->setCheckable(false);
        key_1 = new QPushButton(tab);
        key_1->setObjectName(QStringLiteral("key_1"));
        key_1->setGeometry(QRect(604, 617, 40, 40));
        key_1->setFocusPolicy(Qt::NoFocus);
        key_1->setStyleSheet(QLatin1String("#key_1{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/1_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_1::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/1_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_1->setCheckable(false);
        key_back = new QPushButton(tab);
        key_back->setObjectName(QStringLiteral("key_back"));
        key_back->setGeometry(QRect(800, 660, 88, 40));
        key_back->setFocusPolicy(Qt::NoFocus);
        key_back->setStyleSheet(QLatin1String("#key_back{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/Backspace_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_back::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/Backspace_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_back->setCheckable(false);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableWidget = new QTableWidget(tab_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(3, 0, 1011, 591));
        tabWidget->addTab(tab_2, QString());
        tabWidget->raise();
        label->raise();
        top_menu_4->raise();
        top_menu_1->raise();
        top_menu_2->raise();
        top_menu_3->raise();

        retranslateUi(bitacora);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(bitacora);
    } // setupUi

    void retranslateUi(QDialog *bitacora)
    {
        bitacora->setWindowTitle(QApplication::translate("bitacora", "Dialog", 0));
        top_menu_4->setText(QString());
        top_menu_3->setText(QString());
        top_menu_1->setText(QString());
        top_menu_2->setText(QString());
        label->setText(QApplication::translate("bitacora", "Bit\303\241cora", 0));
        label_2->setText(QApplication::translate("bitacora", "SELECIONAR UNA RUTINA DE LA LISTA", 0));
        key_6->setText(QString());
        key_0->setText(QString());
        label_horas->setText(QString());
        key_2->setText(QString());
        key_3->setText(QString());
        key_9->setText(QString());
        key_Reschedule->setText(QString());
        key_7->setText(QString());
        key_4->setText(QString());
        key_5->setText(QString());
        key_OK->setText(QString());
        key_8->setText(QString());
        key_1->setText(QString());
        key_back->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("bitacora", "Mantenimientos", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("bitacora", "Todas las rutinas", 0));
    } // retranslateUi

};

namespace Ui {
    class bitacora: public Ui_bitacora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BITACORA_H
