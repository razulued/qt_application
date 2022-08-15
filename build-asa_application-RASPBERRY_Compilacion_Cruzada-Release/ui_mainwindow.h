/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
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
    QLabel *top_bar;
    QPushButton *asa_logo;
    QLabel *label_hora;
    QLabel *label_dia;
    QPushButton *prof_pic;
    QLabel *prof_label;
    QPushButton *label_title;
    QLabel *num_of_act;
    QPushButton *modulo_9;
    QWidget *widget_25;
    QWidget *widget_26;
    QWidget *widget_27;
    QLabel *water_level;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QLatin1String("#centralWidget{\n"
"background-image:url(:/images/images/P FF.png);\n"
"}\n"
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
        top_bar = new QLabel(centralWidget);
        top_bar->setObjectName(QStringLiteral("top_bar"));
        top_bar->setGeometry(QRect(0, 2, 759, 27));
        top_bar->setAutoFillBackground(false);
        top_bar->setStyleSheet(QLatin1String("#top_bar { \n"
"background-color: transparent;\n"
"background-image: url(:/barras/screen800x600/barras/Indice diagrama limpio.png);\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        asa_logo = new QPushButton(centralWidget);
        asa_logo->setObjectName(QStringLiteral("asa_logo"));
        asa_logo->setGeometry(QRect(740, 550, 51, 51));
        asa_logo->setFocusPolicy(Qt::NoFocus);
        asa_logo->setStyleSheet(QLatin1String("#asa_logo{ \n"
"background-image: url(:/iconos/screen800x600/iconos/Logo.png);\n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        asa_logo->setCheckable(true);
        label_hora = new QLabel(centralWidget);
        label_hora->setObjectName(QStringLiteral("label_hora"));
        label_hora->setGeometry(QRect(320, 50, 141, 31));
        label_hora->setAlignment(Qt::AlignCenter);
        label_dia = new QLabel(centralWidget);
        label_dia->setObjectName(QStringLiteral("label_dia"));
        label_dia->setGeometry(QRect(245, 28, 291, 21));
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
        prof_label->setGeometry(QRect(580, 20, 141, 21));
        label_title = new QPushButton(centralWidget);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(259, -1, 261, 30));
        QFont font1;
        font1.setPointSize(16);
        label_title->setFont(font1);
        label_title->setFocusPolicy(Qt::NoFocus);
        num_of_act = new QLabel(centralWidget);
        num_of_act->setObjectName(QStringLiteral("num_of_act"));
        num_of_act->setGeometry(QRect(174, 5, 21, 20));
        num_of_act->setStyleSheet(QLatin1String("#num_of_act\n"
"{\n"
"color: yellow;\n"
"border:none;\n"
"background-color: transparent;\n"
"}"));
        modulo_9 = new QPushButton(centralWidget);
        modulo_9->setObjectName(QStringLiteral("modulo_9"));
        modulo_9->setGeometry(QRect(20, 390, 181, 121));
        modulo_9->setFocusPolicy(Qt::NoFocus);
        modulo_9->setAutoFillBackground(false);
        modulo_9->setStyleSheet(QLatin1String("#modulo_9 { \n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_9->setFlat(true);
        widget_25 = new QWidget(centralWidget);
        widget_25->setObjectName(QStringLiteral("widget_25"));
        widget_25->setGeometry(QRect(290, 220, 10, 10));
        widget_26 = new QWidget(centralWidget);
        widget_26->setObjectName(QStringLiteral("widget_26"));
        widget_26->setGeometry(QRect(290, 180, 10, 10));
        widget_27 = new QWidget(centralWidget);
        widget_27->setObjectName(QStringLiteral("widget_27"));
        widget_27->setGeometry(QRect(290, 150, 10, 10));
        water_level = new QLabel(centralWidget);
        water_level->setObjectName(QStringLiteral("water_level"));
        water_level->setGeometry(QRect(720, 50, 81, 461));
        water_level->setStyleSheet(QLatin1String("#water_level{\n"
"background-image:url(:/images/images/watertile.png);\n"
"border:none;\n"
"background-position: bottom left;\n"
"}"));
        MainWindow->setCentralWidget(centralWidget);
        num_of_act->raise();
        top_bar->raise();
        bottom_bar->raise();
        pushButton->raise();
        pb_fisicos->raise();
        pb_quimicos->raise();
        pb_electricos->raise();
        active_param_label->raise();
        asa_logo->raise();
        label_hora->raise();
        label_dia->raise();
        prof_pic->raise();
        prof_label->raise();
        label_title->raise();
        modulo_9->raise();
        widget_27->raise();
        widget_26->raise();
        widget_25->raise();
        water_level->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        MainWindow->setAccessibleName(QApplication::translate("MainWindow", "mainWindow", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        pushButton->setText(QString());
        bottom_bar->setText(QString());
        pb_fisicos->setText(QString());
        pb_quimicos->setText(QString());
        pb_electricos->setText(QString());
        active_param_label->setText(QApplication::translate("MainWindow", "Par\303\241metros", Q_NULLPTR));
        top_bar->setText(QString());
        asa_logo->setText(QString());
        label_hora->setText(QApplication::translate("MainWindow", "Hora", Q_NULLPTR));
        label_dia->setText(QApplication::translate("MainWindow", "Dia", Q_NULLPTR));
        prof_pic->setText(QString());
        prof_label->setText(QApplication::translate("MainWindow", "Sin usuario", Q_NULLPTR));
        label_title->setText(QApplication::translate("MainWindow", "Diagrama", Q_NULLPTR));
        num_of_act->setText(QString());
        modulo_9->setText(QString());
        water_level->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
