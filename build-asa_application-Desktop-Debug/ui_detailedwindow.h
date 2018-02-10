/********************************************************************************
** Form generated from reading UI file 'detailedwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
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
    QPushButton *button_visualizacion_2;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QWidget *tab_2;
    QWidget *tab_3;
    QLabel *description_label;
    QWidget *tab_4;
    QWidget *tab_5;

    void setupUi(QDialog *detailedwindow)
    {
        if (detailedwindow->objectName().isEmpty())
            detailedwindow->setObjectName(QStringLiteral("detailedwindow"));
        detailedwindow->resize(614, 328);
        detailedwindow->setMinimumSize(QSize(614, 328));
        detailedwindow->setMaximumSize(QSize(614, 16777215));
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
        label->setGeometry(QRect(300, 15, 281, 41));
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        closeButton = new QPushButton(detailedwindow);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(580, 14, 20, 20));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        closeButton->setFont(font1);
        closeButton->setFocusPolicy(Qt::NoFocus);
        closeButton->setStyleSheet(QLatin1String("#closeButton { \n"
"background-color: transparent;\n"
"border-image: none;\n"
"background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
"color: rgb(0, 167, 250);\n"
" } "));
        closeButton->setCheckable(false);
        closeButton->setAutoDefault(false);
        closeButton->setFlat(false);
        button_parametros = new QPushButton(detailedwindow);
        button_parametros->setObjectName(QStringLiteral("button_parametros"));
        button_parametros->setGeometry(QRect(20, 270, 23, 23));
        button_parametros->setFocusPolicy(Qt::NoFocus);
        button_parametros->setStyleSheet(QLatin1String("#button_parametros{ \n"
"background-color: transparent;\n"
"border-image: url(:/iconos/images/Iconos/Punto_contrasena.png);\n"
"background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        button_parametros->setCheckable(true);
        button_evento = new QPushButton(detailedwindow);
        button_evento->setObjectName(QStringLiteral("button_evento"));
        button_evento->setGeometry(QRect(70, 270, 23, 23));
        button_evento->setFocusPolicy(Qt::NoFocus);
        button_evento->setStyleSheet(QLatin1String("#button_parametros{ \n"
"background-color: transparent;\n"
"border-image: url(:/iconos/images/Iconos/Punto_contrasena.png);\n"
"background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        button_evento->setCheckable(true);
        button_descripcion = new QPushButton(detailedwindow);
        button_descripcion->setObjectName(QStringLiteral("button_descripcion"));
        button_descripcion->setGeometry(QRect(120, 270, 23, 23));
        button_descripcion->setFocusPolicy(Qt::NoFocus);
        button_descripcion->setStyleSheet(QLatin1String("#button_parametros{ \n"
"background-color: transparent;\n"
"border-image: url(:/iconos/images/Iconos/Punto_contrasena.png);\n"
"background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        button_descripcion->setCheckable(true);
        button_visualizacion = new QPushButton(detailedwindow);
        button_visualizacion->setObjectName(QStringLiteral("button_visualizacion"));
        button_visualizacion->setGeometry(QRect(170, 270, 23, 23));
        button_visualizacion->setFocusPolicy(Qt::NoFocus);
        button_visualizacion->setStyleSheet(QLatin1String("#button_parametros{ \n"
"background-color: transparent;\n"
"border-image: url(:/iconos/images/Iconos/Punto_contrasena.png);\n"
"background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        button_visualizacion->setCheckable(true);
        button_visualizacion_2 = new QPushButton(detailedwindow);
        button_visualizacion_2->setObjectName(QStringLiteral("button_visualizacion_2"));
        button_visualizacion_2->setGeometry(QRect(220, 270, 23, 23));
        button_visualizacion_2->setFocusPolicy(Qt::NoFocus);
        button_visualizacion_2->setStyleSheet(QLatin1String("#button_parametros{ \n"
"background-color: transparent;\n"
"border-image: url(:/iconos/images/Iconos/Punto_contrasena.png);\n"
"background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        button_visualizacion_2->setCheckable(true);
        tabWidget = new QTabWidget(detailedwindow);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(false);
        tabWidget->setGeometry(QRect(290, 60, 291, 251));
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
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        description_label = new QLabel(tab_3);
        description_label->setObjectName(QStringLiteral("description_label"));
        description_label->setGeometry(QRect(10, 10, 261, 131));
        description_label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget->addTab(tab_5, QString());

        retranslateUi(detailedwindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(detailedwindow);
    } // setupUi

    void retranslateUi(QDialog *detailedwindow)
    {
        detailedwindow->setWindowTitle(QApplication::translate("detailedwindow", "Dialog", 0));
        nombre->setText(QApplication::translate("detailedwindow", "Nombre de Elemento", 0));
        imagen->setText(QString());
        label->setText(QApplication::translate("detailedwindow", "Par\303\241metros", 0));
        closeButton->setText(QApplication::translate("detailedwindow", "\342\235\214", 0));
        button_parametros->setText(QString());
        button_evento->setText(QString());
        button_descripcion->setText(QString());
        button_visualizacion->setText(QString());
        button_visualizacion_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("detailedwindow", "Tab 1", 0));
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
