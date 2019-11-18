/********************************************************************************
** Form generated from reading UI file 'filtrowindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTROWINDOW_H
#define UI_FILTROWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_filtrowindow
{
public:
    QPushButton *filtro_button;
    QPushButton *go_to_main;
    QPushButton *pb_quimicos;
    QLabel *active_param_label;
    QPushButton *pb_fisicos;
    QLabel *bottom_bar;
    QPushButton *pushButton;
    QPushButton *pb_electricos;
    QPushButton *asa_logo;
    QLabel *label_dia;
    QPushButton *prof_pic;
    QLabel *label_hora;
    QLabel *prof_label;
    QWidget *widget_3;
    QWidget *widget_2;
    QWidget *widget;
    QPushButton *modulo_1;
    QPushButton *top_menu_2;
    QPushButton *top_menu_3;
    QPushButton *top_menu_6;
    QPushButton *top_menu_1;
    QPushButton *label_title;
    QLabel *top_bar;
    QPushButton *modulo_2;
    QWidget *widget_6;
    QWidget *widget_4;
    QWidget *widget_5;

    void setupUi(QDialog *filtrowindow)
    {
        if (filtrowindow->objectName().isEmpty())
            filtrowindow->setObjectName(QStringLiteral("filtrowindow"));
        filtrowindow->resize(800, 600);
        filtro_button = new QPushButton(filtrowindow);
        filtro_button->setObjectName(QStringLiteral("filtro_button"));
        filtro_button->setGeometry(QRect(250, 91, 321, 411));
        filtro_button->setFocusPolicy(Qt::NoFocus);
        filtro_button->setStyleSheet(QString::fromUtf8("#filtro_button {\n"
"background-image: url(:/diagrama/screen800x600/diagrama/Filtro 5SDF porta\314\201til_1.png);\n"
"border:none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        go_to_main = new QPushButton(filtrowindow);
        go_to_main->setObjectName(QStringLiteral("go_to_main"));
        go_to_main->setGeometry(QRect(5, 260, 31, 71));
        go_to_main->setFocusPolicy(Qt::NoFocus);
        go_to_main->setStyleSheet(QLatin1String("#go_to_main {\n"
"background-image: url(:/iconos/images/Iconos/Flecha_izquierda.png);\n"
"border:none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        pb_quimicos = new QPushButton(filtrowindow);
        pb_quimicos->setObjectName(QStringLiteral("pb_quimicos"));
        pb_quimicos->setGeometry(QRect(530, 560, 71, 41));
        pb_quimicos->setFocusPolicy(Qt::NoFocus);
        pb_quimicos->setStyleSheet(QLatin1String("#pb_quimicos { \n"
"background-image: url(:/iconos/screen800x600/iconos/Matraz azul.png);\n"
"background-color:transparent;\n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        pb_quimicos->setCheckable(true);
        active_param_label = new QLabel(filtrowindow);
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
        pb_fisicos = new QPushButton(filtrowindow);
        pb_fisicos->setObjectName(QStringLiteral("pb_fisicos"));
        pb_fisicos->setGeometry(QRect(450, 560, 51, 41));
        pb_fisicos->setFocusPolicy(Qt::NoFocus);
        pb_fisicos->setStyleSheet(QLatin1String("#pb_fisicos { \n"
"background-image: url(:/iconos/screen800x600/iconos/Medidor azul.png);\n"
"background-color:transparent;\n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        pb_fisicos->setCheckable(true);
        bottom_bar = new QLabel(filtrowindow);
        bottom_bar->setObjectName(QStringLiteral("bottom_bar"));
        bottom_bar->setGeometry(QRect(0, 529, 766, 70));
        bottom_bar->setAutoFillBackground(false);
        bottom_bar->setStyleSheet(QLatin1String("#bottom_bar { \n"
"background-color: transparent;\n"
"border-image: url(:/barras/images/Barras/Parametros_azul.png); background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        pushButton = new QPushButton(filtrowindow);
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
        pb_electricos = new QPushButton(filtrowindow);
        pb_electricos->setObjectName(QStringLiteral("pb_electricos"));
        pb_electricos->setGeometry(QRect(610, 560, 81, 41));
        pb_electricos->setFocusPolicy(Qt::NoFocus);
        pb_electricos->setStyleSheet(QLatin1String("#pb_electricos { \n"
"background-image: url(:/iconos/screen800x600/iconos/Clavija azul.png);\n"
"background-color:transparent;\n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        pb_electricos->setCheckable(true);
        asa_logo = new QPushButton(filtrowindow);
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
        label_dia = new QLabel(filtrowindow);
        label_dia->setObjectName(QStringLiteral("label_dia"));
        label_dia->setGeometry(QRect(275, 28, 231, 21));
        label_dia->setAlignment(Qt::AlignCenter);
        prof_pic = new QPushButton(filtrowindow);
        prof_pic->setObjectName(QStringLiteral("prof_pic"));
        prof_pic->setGeometry(QRect(540, 10, 41, 41));
        prof_pic->setFocusPolicy(Qt::NoFocus);
        prof_pic->setStyleSheet(QLatin1String("#prof_pic { \n"
"background-image: url(:/iconos/screen800x600/iconos/Prof pic azul.png);\n"
"background-color:transparent;\n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        label_hora = new QLabel(filtrowindow);
        label_hora->setObjectName(QStringLiteral("label_hora"));
        label_hora->setGeometry(QRect(310, 50, 161, 31));
        label_hora->setAlignment(Qt::AlignCenter);
        prof_label = new QLabel(filtrowindow);
        prof_label->setObjectName(QStringLiteral("prof_label"));
        prof_label->setGeometry(QRect(580, 20, 151, 21));
        widget_3 = new QWidget(filtrowindow);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(450, 100, 41, 31));
        widget_2 = new QWidget(filtrowindow);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(590, 130, 41, 31));
        widget_2->setStyleSheet(QStringLiteral(""));
        widget = new QWidget(filtrowindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(590, 230, 41, 31));
        modulo_1 = new QPushButton(filtrowindow);
        modulo_1->setObjectName(QStringLiteral("modulo_1"));
        modulo_1->setGeometry(QRect(310, 190, 181, 221));
        modulo_1->setFocusPolicy(Qt::NoFocus);
        modulo_1->setAutoFillBackground(false);
        modulo_1->setStyleSheet(QLatin1String("#modulo_1 { \n"
"border: none; \n"
"background-color: transparent;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        modulo_1->setFlat(true);
        top_menu_2 = new QPushButton(filtrowindow);
        top_menu_2->setObjectName(QStringLiteral("top_menu_2"));
        top_menu_2->setGeometry(QRect(100, 0, 31, 41));
        top_menu_2->setFocusPolicy(Qt::NoFocus);
        top_menu_2->setStyleSheet(QLatin1String("#top_menu_2 { \n"
"background-color: transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/Bitacora azul.png);\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_2->setCheckable(true);
        top_menu_3 = new QPushButton(filtrowindow);
        top_menu_3->setObjectName(QStringLiteral("top_menu_3"));
        top_menu_3->setGeometry(QRect(10, 1, 31, 41));
        top_menu_3->setFocusPolicy(Qt::NoFocus);
        top_menu_3->setStyleSheet(QLatin1String("#top_menu_3 { \n"
"background-color: transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/Monitor1.png);\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_3->setCheckable(true);
        top_menu_6 = new QPushButton(filtrowindow);
        top_menu_6->setObjectName(QStringLiteral("top_menu_6"));
        top_menu_6->setGeometry(QRect(50, 0, 34, 41));
        top_menu_6->setFocusPolicy(Qt::NoFocus);
        top_menu_6->setStyleSheet(QLatin1String("#top_menu_6 { \n"
"background-color: transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/Encendido azul.png);\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_6->setCheckable(true);
        top_menu_1 = new QPushButton(filtrowindow);
        top_menu_1->setObjectName(QStringLiteral("top_menu_1"));
        top_menu_1->setGeometry(QRect(150, 0, 31, 41));
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
        label_title = new QPushButton(filtrowindow);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(259, -1, 261, 30));
        QFont font1;
        font1.setPointSize(16);
        label_title->setFont(font1);
        label_title->setFocusPolicy(Qt::NoFocus);
        label_title->setStyleSheet(QLatin1String("#label_title\n"
"{\n"
"background-color: transparent;\n"
"color: black;\n"
"border: none;\n"
"}"));
        top_bar = new QLabel(filtrowindow);
        top_bar->setObjectName(QStringLiteral("top_bar"));
        top_bar->setGeometry(QRect(0, 2, 759, 27));
        top_bar->setAutoFillBackground(false);
        top_bar->setStyleSheet(QLatin1String("#top_bar { \n"
"background-color: transparent;\n"
"background-image: url(:/barras/screen800x600/barras/Indice diagrama limpio.png);\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        modulo_2 = new QPushButton(filtrowindow);
        modulo_2->setObjectName(QStringLiteral("modulo_2"));
        modulo_2->setGeometry(QRect(80, 310, 211, 131));
        modulo_2->setFocusPolicy(Qt::NoFocus);
        modulo_2->setAutoFillBackground(false);
        modulo_2->setStyleSheet(QLatin1String("#modulo_2 { \n"
"border: none; \n"
"background-color: transparent;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"background-image: url(:/diagrama/screen800x600/diagrama/motor_filtro.png);\n"
"} "));
        modulo_2->setFlat(true);
        widget_6 = new QWidget(filtrowindow);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(120, 230, 41, 31));
        widget_4 = new QWidget(filtrowindow);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(90, 170, 41, 31));
        widget_5 = new QWidget(filtrowindow);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(180, 180, 41, 31));
        top_bar->raise();
        filtro_button->raise();
        go_to_main->raise();
        bottom_bar->raise();
        label_dia->raise();
        label_hora->raise();
        prof_label->raise();
        prof_pic->raise();
        active_param_label->raise();
        pb_quimicos->raise();
        pb_electricos->raise();
        pb_fisicos->raise();
        asa_logo->raise();
        widget_3->raise();
        widget_2->raise();
        widget->raise();
        modulo_1->raise();
        pushButton->raise();
        top_menu_2->raise();
        top_menu_3->raise();
        top_menu_6->raise();
        top_menu_1->raise();
        label_title->raise();
        modulo_2->raise();
        widget_6->raise();
        widget_4->raise();
        widget_5->raise();

        retranslateUi(filtrowindow);

        QMetaObject::connectSlotsByName(filtrowindow);
    } // setupUi

    void retranslateUi(QDialog *filtrowindow)
    {
        filtrowindow->setWindowTitle(QApplication::translate("filtrowindow", "Dialog", Q_NULLPTR));
        filtro_button->setText(QString());
        go_to_main->setText(QString());
        pb_quimicos->setText(QString());
        active_param_label->setText(QApplication::translate("filtrowindow", "Par\303\241metros", Q_NULLPTR));
        pb_fisicos->setText(QString());
        bottom_bar->setText(QString());
        pushButton->setText(QString());
        pb_electricos->setText(QString());
        asa_logo->setText(QString());
        label_dia->setText(QApplication::translate("filtrowindow", "Dia", Q_NULLPTR));
        prof_pic->setText(QString());
        label_hora->setText(QApplication::translate("filtrowindow", "Hora", Q_NULLPTR));
        prof_label->setText(QApplication::translate("filtrowindow", "Sin usuario", Q_NULLPTR));
        modulo_1->setText(QString());
        top_menu_2->setText(QString());
        top_menu_3->setText(QString());
        top_menu_6->setText(QString());
        top_menu_1->setText(QString());
        label_title->setText(QApplication::translate("filtrowindow", "Diagrama", Q_NULLPTR));
        top_bar->setText(QString());
        modulo_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class filtrowindow: public Ui_filtrowindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTROWINDOW_H
