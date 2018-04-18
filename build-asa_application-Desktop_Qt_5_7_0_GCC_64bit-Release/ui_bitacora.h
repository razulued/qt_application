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
#include <QtWidgets/QFrame>
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
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *tableWidget_2;
    QLabel *label_2;
    QLabel *label_horas;
    QPushButton *key_Reschedule;
    QPushButton *key_OK;
    QFrame *frame;
    QPushButton *key_1;
    QPushButton *key_2;
    QPushButton *key_3;
    QPushButton *key_4;
    QPushButton *key_5;
    QPushButton *key_7;
    QPushButton *key_8;
    QPushButton *key_9;
    QPushButton *key_0;
    QPushButton *key_6;
    QPushButton *key_back;
    QWidget *tab_2;
    QTableWidget *tableWidget;
    QPushButton *top_menu_1;
    QPushButton *top_menu_3;
    QPushButton *top_menu_5;
    QPushButton *top_menu_2;

    void setupUi(QDialog *bitacora)
    {
        if (bitacora->objectName().isEmpty())
            bitacora->setObjectName(QStringLiteral("bitacora"));
        bitacora->resize(800, 600);
        bitacora->setMinimumSize(QSize(800, 600));
        bitacora->setMaximumSize(QSize(1024, 768));
        bitacora->setStyleSheet(QStringLiteral(""));
        label = new QLabel(bitacora);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 10, 181, 41));
        tabWidget = new QTabWidget(bitacora);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 9, 801, 591));
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
        tableWidget_2->setGeometry(QRect(0, 0, 791, 441));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 460, 291, 51));
        label_2->setWordWrap(true);
        label_horas = new QLabel(tab);
        label_horas->setObjectName(QStringLiteral("label_horas"));
        label_horas->setGeometry(QRect(456, 492, 48, 18));
        key_Reschedule = new QPushButton(tab);
        key_Reschedule->setObjectName(QStringLiteral("key_Reschedule"));
        key_Reschedule->setGeometry(QRect(450, 482, 81, 41));
        key_Reschedule->setFocusPolicy(Qt::NoFocus);
        key_Reschedule->setStyleSheet(QLatin1String("#key_Reschedule{ \n"
"background-image: url(:/iconos/screen800x600/iconos/Posponer azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_Reschedule::pressed{ \n"
"background-image: url(:/iconos/screen800x600/iconos/Posponer blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_Reschedule->setCheckable(false);
        key_OK = new QPushButton(tab);
        key_OK->setObjectName(QStringLiteral("key_OK"));
        key_OK->setGeometry(QRect(450, 440, 81, 41));
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
        frame = new QFrame(tab);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(540, 440, 241, 91));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        key_1 = new QPushButton(frame);
        key_1->setObjectName(QStringLiteral("key_1"));
        key_1->setGeometry(QRect(40, 0, 41, 41));
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
        key_2 = new QPushButton(frame);
        key_2->setObjectName(QStringLiteral("key_2"));
        key_2->setGeometry(QRect(80, 0, 41, 41));
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
        key_3 = new QPushButton(frame);
        key_3->setObjectName(QStringLiteral("key_3"));
        key_3->setGeometry(QRect(120, 0, 41, 41));
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
        key_4 = new QPushButton(frame);
        key_4->setObjectName(QStringLiteral("key_4"));
        key_4->setGeometry(QRect(160, 0, 41, 41));
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
        key_5 = new QPushButton(frame);
        key_5->setObjectName(QStringLiteral("key_5"));
        key_5->setGeometry(QRect(200, 0, 41, 41));
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
        key_7 = new QPushButton(frame);
        key_7->setObjectName(QStringLiteral("key_7"));
        key_7->setGeometry(QRect(40, 40, 41, 41));
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
        key_8 = new QPushButton(frame);
        key_8->setObjectName(QStringLiteral("key_8"));
        key_8->setGeometry(QRect(80, 40, 41, 41));
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
        key_9 = new QPushButton(frame);
        key_9->setObjectName(QStringLiteral("key_9"));
        key_9->setGeometry(QRect(120, 40, 41, 41));
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
        key_0 = new QPushButton(frame);
        key_0->setObjectName(QStringLiteral("key_0"));
        key_0->setGeometry(QRect(0, 0, 41, 41));
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
        key_6 = new QPushButton(frame);
        key_6->setObjectName(QStringLiteral("key_6"));
        key_6->setGeometry(QRect(0, 40, 41, 41));
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
        key_back = new QPushButton(frame);
        key_back->setObjectName(QStringLiteral("key_back"));
        key_back->setGeometry(QRect(180, 40, 61, 41));
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
        tabWidget->addTab(tab, QString());
        tableWidget_2->raise();
        label_2->raise();
        key_Reschedule->raise();
        key_OK->raise();
        label_horas->raise();
        frame->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableWidget = new QTableWidget(tab_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 791, 541));
        tabWidget->addTab(tab_2, QString());
        top_menu_1 = new QPushButton(bitacora);
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
        top_menu_3 = new QPushButton(bitacora);
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
        top_menu_5 = new QPushButton(bitacora);
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
        top_menu_2 = new QPushButton(bitacora);
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
        tabWidget->raise();
        label->raise();
        top_menu_1->raise();
        top_menu_3->raise();
        top_menu_5->raise();
        top_menu_2->raise();

        retranslateUi(bitacora);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(bitacora);
    } // setupUi

    void retranslateUi(QDialog *bitacora)
    {
        bitacora->setWindowTitle(QApplication::translate("bitacora", "Dialog", 0));
        label->setText(QApplication::translate("bitacora", "Bit\303\241cora", 0));
        label_2->setText(QApplication::translate("bitacora", "SELECIONAR UNA RUTINA DE LA LISTA", 0));
        label_horas->setText(QString());
        key_Reschedule->setText(QString());
        key_OK->setText(QString());
        key_1->setText(QString());
        key_2->setText(QString());
        key_3->setText(QString());
        key_4->setText(QString());
        key_5->setText(QString());
        key_7->setText(QString());
        key_8->setText(QString());
        key_9->setText(QString());
        key_0->setText(QString());
        key_6->setText(QString());
        key_back->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("bitacora", "Mantenimientos", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("bitacora", "Todas las rutinas", 0));
        top_menu_1->setText(QString());
        top_menu_3->setText(QString());
        top_menu_5->setText(QString());
        top_menu_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class bitacora: public Ui_bitacora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BITACORA_H
