/********************************************************************************
** Form generated from reading UI file 'motores.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOTORES_H
#define UI_MOTORES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_motores
{
public:
    QPushButton *lock_button;
    QPushButton *top_menu_6;
    QPushButton *top_menu_1;
    QPushButton *top_menu_3;
    QPushButton *top_menu_2;
    QFrame *frame;
    QLabel *label;
    QLabel *regulador_imagen;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QLabel *label_2;
    QLabel *reactor_imagen;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *gif_blower;
    QPushButton *asa_logo;

    void setupUi(QDialog *motores)
    {
        if (motores->objectName().isEmpty())
            motores->setObjectName(QStringLiteral("motores"));
        motores->resize(800, 600);
        motores->setMinimumSize(QSize(800, 600));
        motores->setMaximumSize(QSize(800, 600));
        lock_button = new QPushButton(motores);
        lock_button->setObjectName(QStringLiteral("lock_button"));
        lock_button->setGeometry(QRect(170, 0, 31, 41));
        lock_button->setFocusPolicy(Qt::NoFocus);
        lock_button->setStyleSheet(QLatin1String("#lock_button { \n"
"background-image: url(:/iconos/screen800x600/iconos/Candado azul.png);\n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        top_menu_6 = new QPushButton(motores);
        top_menu_6->setObjectName(QStringLiteral("top_menu_6"));
        top_menu_6->setGeometry(QRect(130, 0, 34, 41));
        top_menu_6->setFocusPolicy(Qt::NoFocus);
        top_menu_6->setStyleSheet(QLatin1String("#top_menu_6 { \n"
"background-color: transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/Encendido azul.png);\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_6->setCheckable(true);
        top_menu_1 = new QPushButton(motores);
        top_menu_1->setObjectName(QStringLiteral("top_menu_1"));
        top_menu_1->setGeometry(QRect(0, 0, 31, 41));
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
        top_menu_3 = new QPushButton(motores);
        top_menu_3->setObjectName(QStringLiteral("top_menu_3"));
        top_menu_3->setGeometry(QRect(90, 2, 31, 41));
        top_menu_3->setFocusPolicy(Qt::NoFocus);
        top_menu_3->setStyleSheet(QLatin1String("#top_menu_3 { \n"
"background-color: transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/Diagrama.png);\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_3->setCheckable(true);
        top_menu_2 = new QPushButton(motores);
        top_menu_2->setObjectName(QStringLiteral("top_menu_2"));
        top_menu_2->setGeometry(QRect(40, 0, 31, 41));
        top_menu_2->setFocusPolicy(Qt::NoFocus);
        top_menu_2->setStyleSheet(QLatin1String("#top_menu_2 { \n"
"background-color: transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/Bitacora azul.png);\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_2->setCheckable(true);
        frame = new QFrame(motores);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(50, 170, 341, 231));
        frame->setStyleSheet(QLatin1String("#frame\n"
"{\n"
"background-color: black;\n"
"color: white;\n"
"border-style: solid;\n"
"border-width:1px;\n"
"border-color: rgb(0, 167, 250);\n"
"border-radius: 10px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 10, 121, 20));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color:white"));
        label->setAlignment(Qt::AlignCenter);
        regulador_imagen = new QLabel(frame);
        regulador_imagen->setObjectName(QStringLiteral("regulador_imagen"));
        regulador_imagen->setGeometry(QRect(10, 60, 121, 121));
        regulador_imagen->setStyleSheet(QLatin1String("#regulador_imagen\n"
"{\n"
"background-image: url(:/gifs/1 Carcamo y Regulador/screen800x600/gifs/1 Carcamo y Regulador/carcamo hi quiet water.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"border: none;\n"
"}"));
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(140, 39, 191, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(motores);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(410, 170, 341, 231));
        frame_2->setStyleSheet(QLatin1String("#frame_2\n"
"{\n"
"background-color: black;\n"
"color: white;\n"
"border-style: solid;\n"
"border-width:1px;\n"
"border-color: rgb(0, 167, 250);\n"
"border-radius: 10px;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 10, 121, 20));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color:white"));
        label_2->setAlignment(Qt::AlignCenter);
        reactor_imagen = new QLabel(frame_2);
        reactor_imagen->setObjectName(QStringLiteral("reactor_imagen"));
        reactor_imagen->setGeometry(QRect(10, 60, 121, 121));
        reactor_imagen->setStyleSheet(QLatin1String("#reactor_imagen\n"
"{\n"
"background-image: url(:/gifs/2 Reactor/screen800x600/gifs/2 Reactor/reac hi quiet water 03.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"border: none;\n"
"}"));
        verticalLayoutWidget_2 = new QWidget(frame_2);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(140, 39, 191, 181));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        gif_blower = new QLabel(frame_2);
        gif_blower->setObjectName(QStringLiteral("gif_blower"));
        gif_blower->setGeometry(QRect(10, 30, 110, 110));
        gif_blower->setStyleSheet(QLatin1String("#gif_blower\n"
"{\n"
"background-image: url(:/gifs/0 Equipos/screen800x600/gifs/0 Equipos/Blower Jet off.png);\n"
"background-color: transparent;\n"
"background-repeat: none;\n"
"background-position:center;\n"
"border:none;\n"
"}"));
        asa_logo = new QPushButton(motores);
        asa_logo->setObjectName(QStringLiteral("asa_logo"));
        asa_logo->setGeometry(QRect(740, 550, 51, 51));
        asa_logo->setFocusPolicy(Qt::NoFocus);
        asa_logo->setStyleSheet(QLatin1String("#asa_logo{ \n"
"background-image: url(:/iconos/screen800x600/iconos/ASA logo.png);\n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"} "));
        asa_logo->setCheckable(true);

        retranslateUi(motores);

        QMetaObject::connectSlotsByName(motores);
    } // setupUi

    void retranslateUi(QDialog *motores)
    {
        motores->setWindowTitle(QApplication::translate("motores", "Dialog", 0));
        lock_button->setText(QString());
        top_menu_6->setText(QString());
        top_menu_1->setText(QString());
        top_menu_3->setText(QString());
        top_menu_2->setText(QString());
        label->setText(QApplication::translate("motores", "Regulador", 0));
        regulador_imagen->setText(QString());
        label_2->setText(QApplication::translate("motores", "Reactor", 0));
        reactor_imagen->setText(QString());
        gif_blower->setText(QString());
        asa_logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class motores: public Ui_motores {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOTORES_H
