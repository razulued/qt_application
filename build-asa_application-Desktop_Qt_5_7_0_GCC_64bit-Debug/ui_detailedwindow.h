/********************************************************************************
** Form generated from reading UI file 'detailedwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILEDWINDOW_H
#define UI_DETAILEDWINDOW_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_detailedwindow
{
public:
    QLabel *nombre;
    QLabel *imagen;
    QLabel *label;
    QPushButton *closeButton;
    QPushButton *button_parametros;
    QPushButton *button_evento;
    QPushButton *button_descripcion;
    QPushButton *button_visualizacion;
    QPushButton *button_control;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *layout_param;
    QWidget *tab_2;
    QPushButton *key_0;
    QPushButton *key_1;
    QPushButton *key_2;
    QPushButton *key_3;
    QPushButton *key_4;
    QPushButton *key_5;
    QPushButton *key_6;
    QPushButton *key_7;
    QPushButton *key_8;
    QPushButton *key_9;
    QPushButton *key_back;
    QPushButton *key_OK;
    QPushButton *key_Reschedule;
    QTableWidget *tableWidget;
    QLabel *label_horas;
    QWidget *tab_3;
    QLabel *description_label;
    QWidget *tab_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *tab_5;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QDialog *detailedwindow)
    {
        if (detailedwindow->objectName().isEmpty())
            detailedwindow->setObjectName(QStringLiteral("detailedwindow"));
        detailedwindow->resize(614, 367);
        detailedwindow->setMinimumSize(QSize(614, 328));
        detailedwindow->setMaximumSize(QSize(614, 16777215));
        detailedwindow->setStyleSheet(QLatin1String("QCheckBox{\n"
"color:white;\n"
"}\n"
""));
        nombre = new QLabel(detailedwindow);
        nombre->setObjectName(QStringLiteral("nombre"));
        nombre->setGeometry(QRect(30, 10, 201, 51));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        nombre->setFont(font);
        nombre->setWordWrap(true);
        imagen = new QLabel(detailedwindow);
        imagen->setObjectName(QStringLiteral("imagen"));
        imagen->setEnabled(false);
        imagen->setGeometry(QRect(30, 80, 211, 181));
        imagen->setStyleSheet(QLatin1String("#imagen { \n"
"background-color: transparent;\n"
"border-image: url(:/images/images/detail_deshidratador.png);\n"
"background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        label = new QLabel(detailedwindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 5, 281, 61));
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        closeButton = new QPushButton(detailedwindow);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(572, 0, 41, 41));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        closeButton->setFont(font1);
        closeButton->setFocusPolicy(Qt::NoFocus);
        closeButton->setStyleSheet(QLatin1String("#closeButton { \n"
"background-color: transparent;\n"
"border-image: url(:/iconos/images/Iconos/close-x.png);\n"
"background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
"margin:5px;\n"
" } \n"
""));
        closeButton->setCheckable(false);
        closeButton->setAutoDefault(false);
        closeButton->setFlat(false);
        button_parametros = new QPushButton(detailedwindow);
        button_parametros->setObjectName(QStringLiteral("button_parametros"));
        button_parametros->setGeometry(QRect(20, 270, 40, 60));
        button_parametros->setFocusPolicy(Qt::NoFocus);
        button_parametros->setStyleSheet(QLatin1String("#button_parametros{\n"
"background-image: url(:/iconos/images/Iconos/Visualizar_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        button_parametros->setCheckable(false);
        button_evento = new QPushButton(detailedwindow);
        button_evento->setObjectName(QStringLiteral("button_evento"));
        button_evento->setGeometry(QRect(70, 270, 40, 60));
        button_evento->setFocusPolicy(Qt::NoFocus);
        button_evento->setStyleSheet(QLatin1String("#button_evento{\n"
"background-image: url(:/iconos/images/Iconos/Bitacora_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        button_evento->setCheckable(false);
        button_descripcion = new QPushButton(detailedwindow);
        button_descripcion->setObjectName(QStringLiteral("button_descripcion"));
        button_descripcion->setGeometry(QRect(120, 270, 40, 60));
        button_descripcion->setFocusPolicy(Qt::NoFocus);
        button_descripcion->setStyleSheet(QLatin1String("#button_descripcion{\n"
"background-image: url(:/iconos/images/Iconos/Info_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        button_descripcion->setCheckable(false);
        button_visualizacion = new QPushButton(detailedwindow);
        button_visualizacion->setObjectName(QStringLiteral("button_visualizacion"));
        button_visualizacion->setGeometry(QRect(170, 270, 40, 60));
        button_visualizacion->setFocusPolicy(Qt::NoFocus);
        button_visualizacion->setStyleSheet(QLatin1String("#button_visualizacion{\n"
"background-image: url(:/iconos/images/Iconos/Ajustes_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        button_visualizacion->setCheckable(false);
        button_control = new QPushButton(detailedwindow);
        button_control->setObjectName(QStringLiteral("button_control"));
        button_control->setGeometry(QRect(220, 270, 40, 60));
        button_control->setFocusPolicy(Qt::NoFocus);
        button_control->setStyleSheet(QLatin1String("#button_control{ \n"
"background-image: url(:/iconos/images/Iconos/Encendido_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        button_control->setCheckable(false);
        tabWidget = new QTabWidget(detailedwindow);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(290, 60, 291, 301));
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
        verticalLayoutWidget_2 = new QWidget(tab_1);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 261, 201));
        layout_param = new QVBoxLayout(verticalLayoutWidget_2);
        layout_param->setObjectName(QStringLiteral("layout_param"));
        layout_param->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        key_0 = new QPushButton(tab_2);
        key_0->setObjectName(QStringLiteral("key_0"));
        key_0->setGeometry(QRect(154, 235, 40, 40));
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
        key_1 = new QPushButton(tab_2);
        key_1->setObjectName(QStringLiteral("key_1"));
        key_1->setGeometry(QRect(6, 192, 40, 40));
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
        key_2 = new QPushButton(tab_2);
        key_2->setObjectName(QStringLiteral("key_2"));
        key_2->setGeometry(QRect(56, 192, 40, 40));
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
        key_3 = new QPushButton(tab_2);
        key_3->setObjectName(QStringLiteral("key_3"));
        key_3->setGeometry(QRect(105, 192, 40, 40));
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
        key_4 = new QPushButton(tab_2);
        key_4->setObjectName(QStringLiteral("key_4"));
        key_4->setGeometry(QRect(154, 192, 40, 40));
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
        key_5 = new QPushButton(tab_2);
        key_5->setObjectName(QStringLiteral("key_5"));
        key_5->setGeometry(QRect(202, 192, 40, 40));
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
        key_6 = new QPushButton(tab_2);
        key_6->setObjectName(QStringLiteral("key_6"));
        key_6->setGeometry(QRect(250, 192, 40, 40));
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
        key_7 = new QPushButton(tab_2);
        key_7->setObjectName(QStringLiteral("key_7"));
        key_7->setGeometry(QRect(6, 235, 40, 40));
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
        key_8 = new QPushButton(tab_2);
        key_8->setObjectName(QStringLiteral("key_8"));
        key_8->setGeometry(QRect(56, 235, 40, 40));
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
        key_9 = new QPushButton(tab_2);
        key_9->setObjectName(QStringLiteral("key_9"));
        key_9->setGeometry(QRect(105, 235, 40, 40));
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
        key_back = new QPushButton(tab_2);
        key_back->setObjectName(QStringLiteral("key_back"));
        key_back->setGeometry(QRect(202, 235, 88, 40));
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
        key_OK = new QPushButton(tab_2);
        key_OK->setObjectName(QStringLiteral("key_OK"));
        key_OK->setGeometry(QRect(211, 146, 81, 41));
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
        key_Reschedule = new QPushButton(tab_2);
        key_Reschedule->setObjectName(QStringLiteral("key_Reschedule"));
        key_Reschedule->setGeometry(QRect(100, 144, 41, 41));
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
        tableWidget = new QTableWidget(tab_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 291, 141));
        label_horas = new QLabel(tab_2);
        label_horas->setObjectName(QStringLiteral("label_horas"));
        label_horas->setGeometry(QRect(10, 153, 91, 31));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        description_label = new QLabel(tab_3);
        description_label->setObjectName(QStringLiteral("description_label"));
        description_label->setGeometry(QRect(10, 10, 261, 171));
        description_label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        description_label->setWordWrap(true);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayoutWidget = new QWidget(tab_4);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 271, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        verticalLayoutWidget_3 = new QWidget(tab_5);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(19, 19, 261, 251));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab_5, QString());
        nombre->raise();
        imagen->raise();
        closeButton->raise();
        button_parametros->raise();
        button_evento->raise();
        button_descripcion->raise();
        button_visualizacion->raise();
        button_control->raise();
        tabWidget->raise();
        label->raise();

        retranslateUi(detailedwindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(detailedwindow);
    } // setupUi

    void retranslateUi(QDialog *detailedwindow)
    {
        detailedwindow->setWindowTitle(QApplication::translate("detailedwindow", "Dialog", 0));
        nombre->setText(QApplication::translate("detailedwindow", "Nombre de Elemento", 0));
        imagen->setText(QString());
        label->setText(QApplication::translate("detailedwindow", "Par\303\241metros", 0));
        closeButton->setText(QString());
        button_parametros->setText(QString());
        button_evento->setText(QString());
        button_descripcion->setText(QString());
        button_visualizacion->setText(QString());
        button_control->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("detailedwindow", "Tab 1", 0));
        key_0->setText(QString());
        key_1->setText(QString());
        key_2->setText(QString());
        key_3->setText(QString());
        key_4->setText(QString());
        key_5->setText(QString());
        key_6->setText(QString());
        key_7->setText(QString());
        key_8->setText(QString());
        key_9->setText(QString());
        key_back->setText(QString());
        key_OK->setText(QString());
        key_Reschedule->setText(QString());
        label_horas->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("detailedwindow", "Tab 2", 0));
        description_label->setText(QApplication::translate("detailedwindow", "Descripcion", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("detailedwindow", "Tab 3", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("detailedwindow", "Tab 4", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("detailedwindow", "Tab 5", 0));
    } // retranslateUi

};

namespace Ui {
    class detailedwindow: public Ui_detailedwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILEDWINDOW_H
