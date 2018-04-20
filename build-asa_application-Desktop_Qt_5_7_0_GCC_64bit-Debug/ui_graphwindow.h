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
    QLabel *volts_1;
    QLabel *volts_2;
    QLabel *volts_3;
    QLabel *amps_1;
    QLabel *amps_2;
    QLabel *amps_3;
    QWidget *tab_2;
    QWidget *tab_3;

    void setupUi(QDialog *graphwindow)
    {
        if (graphwindow->objectName().isEmpty())
            graphwindow->setObjectName(QStringLiteral("graphwindow"));
        graphwindow->resize(800, 600);
        graphicsView = new QGraphicsView(graphwindow);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(30, 240, 521, 271));
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
        volts_1 = new QLabel(tab);
        volts_1->setObjectName(QStringLiteral("volts_1"));
        volts_1->setGeometry(QRect(50, 60, 41, 21));
        QFont font2;
        font2.setPointSize(14);
        volts_1->setFont(font2);
        volts_1->setAlignment(Qt::AlignCenter);
        volts_2 = new QLabel(tab);
        volts_2->setObjectName(QStringLiteral("volts_2"));
        volts_2->setGeometry(QRect(110, 60, 41, 21));
        volts_2->setFont(font2);
        volts_2->setAlignment(Qt::AlignCenter);
        volts_3 = new QLabel(tab);
        volts_3->setObjectName(QStringLiteral("volts_3"));
        volts_3->setGeometry(QRect(170, 60, 41, 21));
        volts_3->setFont(font2);
        volts_3->setAlignment(Qt::AlignCenter);
        amps_1 = new QLabel(tab);
        amps_1->setObjectName(QStringLiteral("amps_1"));
        amps_1->setGeometry(QRect(490, 60, 41, 21));
        amps_1->setFont(font2);
        amps_1->setAlignment(Qt::AlignCenter);
        amps_2 = new QLabel(tab);
        amps_2->setObjectName(QStringLiteral("amps_2"));
        amps_2->setGeometry(QRect(550, 60, 41, 21));
        amps_2->setFont(font2);
        amps_2->setAlignment(Qt::AlignCenter);
        amps_3 = new QLabel(tab);
        amps_3->setObjectName(QStringLiteral("amps_3"));
        amps_3->setGeometry(QRect(610, 60, 41, 21));
        amps_3->setFont(font2);
        amps_3->setAlignment(Qt::AlignCenter);
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
        volts_1->raise();
        volts_2->raise();
        volts_3->raise();
        amps_1->raise();
        amps_2->raise();
        amps_3->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        top_bar->raise();
        graphicsView->raise();
        top_menu_3->raise();
        top_menu_1->raise();
        top_menu_5->raise();
        top_menu_2->raise();
        barra_grafica->raise();
        tabWidget->raise();

        retranslateUi(graphwindow);

        tabWidget->setCurrentIndex(0);


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
        volts_1->setText(QApplication::translate("graphwindow", "V", 0));
        volts_2->setText(QApplication::translate("graphwindow", "V", 0));
        volts_3->setText(QApplication::translate("graphwindow", "V", 0));
        amps_1->setText(QApplication::translate("graphwindow", "V", 0));
        amps_2->setText(QApplication::translate("graphwindow", "V", 0));
        amps_3->setText(QApplication::translate("graphwindow", "V", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("graphwindow", "Electricos", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("graphwindow", "Fisicos", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("graphwindow", "Quimicos", 0));
    } // retranslateUi

};

namespace Ui {
    class graphwindow: public Ui_graphwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHWINDOW_H
