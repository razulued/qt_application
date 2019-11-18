/********************************************************************************
** Form generated from reading UI file 'bitacora.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
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
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *tableWidget_2;
    QLabel *label_2;
    QLabel *label_horas;
    QPushButton *key_Reschedule;
    QPushButton *key_OK;
    QPushButton *tab1_to_top;
    QPushButton *tab1_to_bottom;
    QWidget *tab_2;
    QTableWidget *tableWidget;
    QPushButton *key_Reschedule_2;
    QLabel *label_3;
    QPushButton *log_button;
    QLabel *label_4;
    QPushButton *tab2_to_top;
    QPushButton *tab2_to_bottom;
    QWidget *tab_3;
    QTableWidget *tableWidget_3;
    QPushButton *clear_filters;
    QPushButton *filtro_fecha;
    QLabel *label_quitar_filtros;
    QLabel *label_filtro_fecha;
    QPushButton *filtro_record;
    QLabel *label_filtro_record;
    QPushButton *graph_button;
    QLabel *label_mostrar_graficos;
    QPushButton *tab3_to_top;
    QPushButton *tab3_to_bottom;
    QPushButton *top_menu_1;
    QPushButton *top_menu_3;
    QPushButton *top_menu_5;
    QPushButton *top_menu_2;
    QLabel *top_bar;
    QLabel *prof_label;
    QPushButton *label_title;
    QPushButton *prof_pic;
    QLabel *num_of_act;

    void setupUi(QDialog *bitacora)
    {
        if (bitacora->objectName().isEmpty())
            bitacora->setObjectName(QStringLiteral("bitacora"));
        bitacora->resize(800, 600);
        bitacora->setMinimumSize(QSize(800, 600));
        bitacora->setMaximumSize(QSize(1024, 768));
        bitacora->setStyleSheet(QStringLiteral(""));
        tabWidget = new QTabWidget(bitacora);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 39, 801, 561));
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tabWidget->setStyleSheet(QLatin1String("QTabWidget::tab-bar{\n"
"alignment: right;\n"
"}\n"
"\n"
"QTabBar::tab { min-width:200px; }\n"
"\n"
"QTabBar::tab:!selected{\n"
"background-color: #000000;\n"
"color: rgb(0, 167, 250);\n"
"font-size:8pt;\n"
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
        tableWidget_2->setGeometry(QRect(0, 0, 791, 451));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 460, 291, 51));
        label_2->setWordWrap(true);
        label_horas = new QLabel(tab);
        label_horas->setObjectName(QStringLiteral("label_horas"));
        label_horas->setGeometry(QRect(414, 478, 120, 18));
        key_Reschedule = new QPushButton(tab);
        key_Reschedule->setObjectName(QStringLiteral("key_Reschedule"));
        key_Reschedule->setGeometry(QRect(410, 468, 151, 41));
        key_Reschedule->setFocusPolicy(Qt::NoFocus);
        key_Reschedule->setStyleSheet(QLatin1String("#key_Reschedule{ \n"
"background-image: url(:/iconos/screen800x600/iconos/Posponer azul largo.png);\n"
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
        key_OK->setGeometry(QRect(580, 466, 81, 41));
        key_OK->setFocusPolicy(Qt::NoFocus);
        key_OK->setStyleSheet(QLatin1String("#key_OK{ \n"
"background-image: url(:/iconos/screen800x600/iconos/Listo azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"color:black;\n"
"}\n"
"\n"
"#key_OK::pressed{ \n"
"background-image: url(:/iconos/screen800x600/iconos/Listo blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"color:black;\n"
"}"));
        key_OK->setCheckable(false);
        tab1_to_top = new QPushButton(tab);
        tab1_to_top->setObjectName(QStringLiteral("tab1_to_top"));
        tab1_to_top->setGeometry(QRect(764, 3, 31, 41));
        tab1_to_top->setFocusPolicy(Qt::NoFocus);
        tab1_to_top->setStyleSheet(QLatin1String("#tab1_to_top\n"
"{\n"
"border: none;\n"
"background-color:transparent;\n"
"}"));
        tab1_to_bottom = new QPushButton(tab);
        tab1_to_bottom->setObjectName(QStringLiteral("tab1_to_bottom"));
        tab1_to_bottom->setGeometry(QRect(764, 411, 31, 41));
        tab1_to_bottom->setFocusPolicy(Qt::NoFocus);
        tab1_to_bottom->setStyleSheet(QLatin1String("#tab1_to_bottom\n"
"{\n"
"border: none;\n"
"background-color:transparent;\n"
"}"));
        tabWidget->addTab(tab, QString());
        tableWidget_2->raise();
        label_2->raise();
        key_Reschedule->raise();
        key_OK->raise();
        label_horas->raise();
        tab1_to_top->raise();
        tab1_to_bottom->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableWidget = new QTableWidget(tab_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 791, 451));
        key_Reschedule_2 = new QPushButton(tab_2);
        key_Reschedule_2->setObjectName(QStringLiteral("key_Reschedule_2"));
        key_Reschedule_2->setGeometry(QRect(340, 458, 51, 41));
        key_Reschedule_2->setFocusPolicy(Qt::NoFocus);
        key_Reschedule_2->setStyleSheet(QLatin1String("#key_Reschedule_2{ \n"
"background-image: url(:/iconos/images/Iconos/Posponer_azul_old.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_Reschedule_2::pressed{ \n"
"background-image: url(:/iconos/images/Iconos/Posponer_blanco_old.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_Reschedule_2->setCheckable(false);
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(393, 450, 291, 51));
        label_3->setWordWrap(true);
        log_button = new QPushButton(tab_2);
        log_button->setObjectName(QStringLiteral("log_button"));
        log_button->setGeometry(QRect(20, 455, 61, 50));
        log_button->setFocusPolicy(Qt::NoFocus);
        log_button->setStyleSheet(QLatin1String("#log_button{ \n"
"background-image: url(:/iconos/screen800x600/iconos/Historial_small.png);\n"
"background-color: transparent;\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 448, 191, 61));
        label_4->setWordWrap(true);
        tab2_to_top = new QPushButton(tab_2);
        tab2_to_top->setObjectName(QStringLiteral("tab2_to_top"));
        tab2_to_top->setGeometry(QRect(764, 1, 31, 41));
        tab2_to_top->setFocusPolicy(Qt::NoFocus);
        tab2_to_top->setStyleSheet(QLatin1String("#tab2_to_top\n"
"{\n"
"border: none;\n"
"background-color:transparent;\n"
"}"));
        tab2_to_bottom = new QPushButton(tab_2);
        tab2_to_bottom->setObjectName(QStringLiteral("tab2_to_bottom"));
        tab2_to_bottom->setGeometry(QRect(764, 410, 31, 41));
        tab2_to_bottom->setFocusPolicy(Qt::NoFocus);
        tab2_to_bottom->setStyleSheet(QLatin1String("#tab2_to_bottom\n"
"{\n"
"border: none;\n"
"background-color:transparent;\n"
"}"));
        tabWidget->addTab(tab_2, QString());
        tableWidget->raise();
        key_Reschedule_2->raise();
        label_3->raise();
        label_4->raise();
        log_button->raise();
        tab2_to_top->raise();
        tab2_to_bottom->raise();
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tableWidget_3 = new QTableWidget(tab_3);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(0, 0, 791, 451));
        clear_filters = new QPushButton(tab_3);
        clear_filters->setObjectName(QStringLiteral("clear_filters"));
        clear_filters->setGeometry(QRect(20, 461, 131, 31));
        clear_filters->setFocusPolicy(Qt::NoFocus);
        clear_filters->setStyleSheet(QLatin1String("#clear_filters\n"
"{\n"
"background-image: url(:/iconos/screen800x600/iconos/Limpiar-filtro.png);\n"
"background-position: left;\n"
"background-repeat: none;\n"
"border:none;\n"
"background-color:transparent;\n"
"/*background-color: black;\n"
"color: rgb(0, 167, 250);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-color: rgb(0, 167, 250);\n"
"border-radius: 10;*/\n"
"}"));
        filtro_fecha = new QPushButton(tab_3);
        filtro_fecha->setObjectName(QStringLiteral("filtro_fecha"));
        filtro_fecha->setGeometry(QRect(620, 457, 151, 41));
        filtro_fecha->setFocusPolicy(Qt::NoFocus);
        filtro_fecha->setStyleSheet(QLatin1String("#filtro_fecha\n"
"{\n"
"background-image: url(:/iconos/screen800x600/iconos/Calendario.png);\n"
"background-position: left;\n"
"background-repeat: none;\n"
"border:none;\n"
"background-color:transparent;\n"
"}"));
        label_quitar_filtros = new QLabel(tab_3);
        label_quitar_filtros->setObjectName(QStringLiteral("label_quitar_filtros"));
        label_quitar_filtros->setGeometry(QRect(50, 470, 111, 21));
        label_filtro_fecha = new QLabel(tab_3);
        label_filtro_fecha->setObjectName(QStringLiteral("label_filtro_fecha"));
        label_filtro_fecha->setGeometry(QRect(662, 470, 131, 21));
        filtro_record = new QPushButton(tab_3);
        filtro_record->setObjectName(QStringLiteral("filtro_record"));
        filtro_record->setGeometry(QRect(420, 460, 161, 41));
        filtro_record->setFocusPolicy(Qt::NoFocus);
        filtro_record->setStyleSheet(QLatin1String("#filtro_record\n"
"{\n"
"background-image: url(:/iconos/screen800x600/iconos/Ayuda azul.png);\n"
"background-position: left;\n"
"background-repeat: none;\n"
"border:none;\n"
"background-color:transparent;\n"
"}"));
        label_filtro_record = new QLabel(tab_3);
        label_filtro_record->setObjectName(QStringLiteral("label_filtro_record"));
        label_filtro_record->setGeometry(QRect(440, 470, 171, 21));
        graph_button = new QPushButton(tab_3);
        graph_button->setObjectName(QStringLiteral("graph_button"));
        graph_button->setGeometry(QRect(204, 465, 151, 31));
        graph_button->setFocusPolicy(Qt::NoFocus);
        graph_button->setStyleSheet(QLatin1String("#graph_button\n"
"{\n"
"background-image: url(:/iconos/screen800x600/iconos/graph-icon.png);\n"
"background-position: left;\n"
"background-repeat: none;\n"
"border:none;\n"
"background-color:transparent;\n"
"}"));
        label_mostrar_graficos = new QLabel(tab_3);
        label_mostrar_graficos->setObjectName(QStringLiteral("label_mostrar_graficos"));
        label_mostrar_graficos->setGeometry(QRect(240, 470, 131, 21));
        tab3_to_top = new QPushButton(tab_3);
        tab3_to_top->setObjectName(QStringLiteral("tab3_to_top"));
        tab3_to_top->setGeometry(QRect(764, 0, 31, 41));
        tab3_to_top->setFocusPolicy(Qt::NoFocus);
        tab3_to_top->setStyleSheet(QLatin1String("#tab3_to_top\n"
"{\n"
"border: none;\n"
"background-color:transparent;\n"
"}"));
        tab3_to_bottom = new QPushButton(tab_3);
        tab3_to_bottom->setObjectName(QStringLiteral("tab3_to_bottom"));
        tab3_to_bottom->setGeometry(QRect(764, 411, 31, 41));
        tab3_to_bottom->setFocusPolicy(Qt::NoFocus);
        tab3_to_bottom->setStyleSheet(QLatin1String("#tab3_to_bottom\n"
"{\n"
"border: none;\n"
"background-color:transparent;\n"
"}"));
        tabWidget->addTab(tab_3, QString());
        tableWidget_3->raise();
        label_quitar_filtros->raise();
        label_filtro_fecha->raise();
        label_filtro_record->raise();
        label_mostrar_graficos->raise();
        clear_filters->raise();
        graph_button->raise();
        filtro_record->raise();
        filtro_fecha->raise();
        tab3_to_top->raise();
        tab3_to_bottom->raise();
        top_menu_1 = new QPushButton(bitacora);
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
        top_menu_3 = new QPushButton(bitacora);
        top_menu_3->setObjectName(QStringLiteral("top_menu_3"));
        top_menu_3->setGeometry(QRect(10, 2, 31, 41));
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
        top_menu_5->setGeometry(QRect(55, 0, 34, 41));
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
        top_bar = new QLabel(bitacora);
        top_bar->setObjectName(QStringLiteral("top_bar"));
        top_bar->setGeometry(QRect(0, 2, 759, 27));
        top_bar->setAutoFillBackground(false);
        top_bar->setStyleSheet(QLatin1String("#top_bar { \n"
"background-color: transparent;\n"
"background-image: url(:/barras/screen800x600/barras/Indice diagrama limpio.png);\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        prof_label = new QLabel(bitacora);
        prof_label->setObjectName(QStringLiteral("prof_label"));
        prof_label->setGeometry(QRect(580, 20, 141, 21));
        label_title = new QPushButton(bitacora);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(259, -1, 261, 30));
        QFont font;
        font.setPointSize(16);
        label_title->setFont(font);
        label_title->setFocusPolicy(Qt::NoFocus);
        label_title->setStyleSheet(QLatin1String("#label_title\n"
"{\n"
"background-color: transparent;\n"
"border: none;\n"
"}"));
        prof_pic = new QPushButton(bitacora);
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
        num_of_act = new QLabel(bitacora);
        num_of_act->setObjectName(QStringLiteral("num_of_act"));
        num_of_act->setGeometry(QRect(174, 5, 21, 20));
        num_of_act->setStyleSheet(QLatin1String("#num_of_act\n"
"{\n"
"color: yellow;\n"
"border:none;\n"
"background-color: transparent;\n"
"}"));
        num_of_act->raise();
        top_bar->raise();
        tabWidget->raise();
        top_menu_1->raise();
        top_menu_3->raise();
        top_menu_5->raise();
        top_menu_2->raise();
        prof_label->raise();
        label_title->raise();
        prof_pic->raise();

        retranslateUi(bitacora);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(bitacora);
    } // setupUi

    void retranslateUi(QDialog *bitacora)
    {
        bitacora->setWindowTitle(QApplication::translate("bitacora", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("bitacora", "SELECIONAR UNA RUTINA DE LA LISTA", Q_NULLPTR));
        label_horas->setText(QString());
        key_Reschedule->setText(QString());
        key_OK->setText(QApplication::translate("bitacora", "Completado", Q_NULLPTR));
        tab1_to_top->setText(QString());
        tab1_to_bottom->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("bitacora", "Pendientes", Q_NULLPTR));
        key_Reschedule_2->setText(QString());
        label_3->setText(QApplication::translate("bitacora", "SELECIONAR UNA RUTINA DE LA LISTA Y HACER CLICK AQUI PARA MODIFICAR EL SIGUIENTE EVENTO", Q_NULLPTR));
        log_button->setText(QString());
        label_4->setText(QApplication::translate("bitacora", "Ver historial de eventos para la actividad seleccionada", Q_NULLPTR));
        tab2_to_top->setText(QString());
        tab2_to_bottom->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("bitacora", "Todas", Q_NULLPTR));
        clear_filters->setText(QString());
        filtro_fecha->setText(QString());
        label_quitar_filtros->setText(QApplication::translate("bitacora", "Quitar Filtros", Q_NULLPTR));
        label_filtro_fecha->setText(QApplication::translate("bitacora", "Filtrar por fecha", Q_NULLPTR));
        filtro_record->setText(QString());
        label_filtro_record->setText(QApplication::translate("bitacora", "Filtro por pregunta", Q_NULLPTR));
        graph_button->setText(QString());
        label_mostrar_graficos->setText(QApplication::translate("bitacora", "Mostrar gr\303\241fico", Q_NULLPTR));
        tab3_to_top->setText(QString());
        tab3_to_bottom->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("bitacora", "Registros", Q_NULLPTR));
        top_menu_1->setText(QString());
        top_menu_3->setText(QString());
        top_menu_5->setText(QString());
        top_menu_2->setText(QString());
        top_bar->setText(QString());
        prof_label->setText(QApplication::translate("bitacora", "Sin usuario", Q_NULLPTR));
        label_title->setText(QApplication::translate("bitacora", "Bit\303\241cora", Q_NULLPTR));
        prof_pic->setText(QString());
        num_of_act->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class bitacora: public Ui_bitacora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BITACORA_H
