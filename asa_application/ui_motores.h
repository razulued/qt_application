/********************************************************************************
** Form generated from reading UI file 'motores.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOTORES_H
#define UI_MOTORES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_motores
{
public:
    QFrame *frame;
    QLabel *label;
    QLabel *regulador_imagen;
    QComboBox *comboBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QLabel *label_2;
    QLabel *reactor_imagen;
    QLabel *gif_blower;
    QComboBox *comboBox_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *asa_logo;
    QFrame *frame_3;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *stop_button_image;
    QFrame *frame_4;
    QLabel *label_4;
    QLabel *filtro_imagen;
    QComboBox *comboBox_3;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QFrame *frame_5;
    QLabel *label_5;
    QLabel *filtro_imagen_2;
    QComboBox *comboBox_4;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QFrame *frame_6;
    QLabel *label_6;
    QLabel *regulador_imagen_2;
    QComboBox *comboBox_5;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;

    void setupUi(QDialog *motores)
    {
        if (motores->objectName().isEmpty())
            motores->setObjectName(QStringLiteral("motores"));
        motores->resize(800, 600);
        motores->setMinimumSize(QSize(800, 600));
        motores->setMaximumSize(QSize(800, 600));
        frame = new QFrame(motores);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 380, 331, 211));
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
        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(140, 40, 171, 22));
        comboBox->setStyleSheet(QLatin1String("#comboBox\n"
"{\n"
"background-color: black;\n"
"color: white;\n"
"}"));
        gridLayoutWidget = new QWidget(frame);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(140, 90, 181, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(motores);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(380, 380, 351, 211));
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
        comboBox_2 = new QComboBox(frame_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(140, 40, 191, 22));
        comboBox_2->setStyleSheet(QLatin1String("#comboBox_2\n"
"{\n"
"background-color: black;\n"
"color: white;\n"
"}"));
        gridLayoutWidget_2 = new QWidget(frame_2);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(140, 90, 191, 111));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
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
        frame_3 = new QFrame(motores);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(20, 10, 331, 141));
        frame_3->setStyleSheet(QLatin1String("#frame_3\n"
"{\n"
"background-color: black;\n"
"color: white;\n"
"border-style: solid;\n"
"border-width:1px;\n"
"border-color: rgb(0, 167, 250);\n"
"border-radius: 10px;\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(14, 4, 301, 41));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color:white"));
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(true);
        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 50, 82, 82));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QLatin1String("#pushButton\n"
"{\n"
"background-color:transparent;\n"
"/*background-image: url(:/iconos/screen800x600/iconos/BOTON.png);*/\n"
"background-position: center;\n"
"background-repeat:none;\n"
"border:none;\n"
"}\n"
"\n"
"/*#pushButton::pressed\n"
"{\n"
"background-color:transparent;\n"
"background-image:  url(:/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/none.png);\n"
"background-position: center;\n"
"background-repeat:none;\n"
"border:none;\n"
"}\n"
"#pushButton::checked\n"
"{\n"
"background-color:transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/BOTON 2.png);\n"
"background-image:  url(:/gifs/0 Flechas de flujo/screen800x600/gifs/0 Flechas de flujo/none.png);\n"
"background-position: center;\n"
"background-repeat:none;\n"
"border:none;\n"
"}*/"));
        pushButton->setCheckable(true);
        pushButton->setChecked(false);
        stop_button_image = new QLabel(frame_3);
        stop_button_image->setObjectName(QStringLiteral("stop_button_image"));
        stop_button_image->setGeometry(QRect(120, 50, 82, 82));
        stop_button_image->setStyleSheet(QLatin1String("#stop_button_image\n"
"{\n"
"/*background-image: url(:/iconos/screen800x600/iconos/Stop-Boton-Activo.gif);*/\n"
"background-position:center;\n"
"}"));
        stop_button_image->raise();
        label_3->raise();
        pushButton->raise();
        frame_4 = new QFrame(motores);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(380, 10, 361, 191));
        frame_4->setStyleSheet(QLatin1String("#frame_4\n"
"{\n"
"background-color: black;\n"
"color: white;\n"
"border-style: solid;\n"
"border-width:1px;\n"
"border-color: rgb(0, 167, 250);\n"
"border-radius: 10px;\n"
"}"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 10, 121, 20));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color:white"));
        label_4->setAlignment(Qt::AlignCenter);
        filtro_imagen = new QLabel(frame_4);
        filtro_imagen->setObjectName(QStringLiteral("filtro_imagen"));
        filtro_imagen->setGeometry(QRect(-10, 10, 141, 161));
        filtro_imagen->setStyleSheet(QString::fromUtf8("#filtro_imagen\n"
"{\n"
"background-image: url(:/diagrama/screen800x600/diagrama/Filtro 5SDF porta\314\201til_ small.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"backgorund-color: transparent;\n"
"border: none;\n"
"}"));
        comboBox_3 = new QComboBox(frame_4);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(140, 40, 191, 22));
        comboBox_3->setStyleSheet(QLatin1String("#comboBox_3\n"
"{\n"
"background-color: black;\n"
"color: white;\n"
"}"));
        gridLayoutWidget_3 = new QWidget(frame_4);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(140, 80, 241, 101));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_5 = new QFrame(motores);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(380, 205, 361, 171));
        frame_5->setStyleSheet(QLatin1String("#frame_5\n"
"{\n"
"background-color: black;\n"
"color: white;\n"
"border-style: solid;\n"
"border-width:1px;\n"
"border-color: rgb(0, 167, 250);\n"
"border-radius: 10px;\n"
"}"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(90, 10, 211, 20));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color:white"));
        label_5->setAlignment(Qt::AlignCenter);
        filtro_imagen_2 = new QLabel(frame_5);
        filtro_imagen_2->setObjectName(QStringLiteral("filtro_imagen_2"));
        filtro_imagen_2->setGeometry(QRect(0, 50, 131, 131));
        filtro_imagen_2->setStyleSheet(QLatin1String("#filtro_imagen_2\n"
"{\n"
"background-image: url(:/diagrama/screen800x600/diagrama/motor_filtro_small.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"backgorund-color: transparent;\n"
"border: none;\n"
"}"));
        comboBox_4 = new QComboBox(frame_5);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(140, 35, 141, 22));
        comboBox_4->setStyleSheet(QLatin1String("#comboBox_4\n"
"{\n"
"background-color: black;\n"
"color: white;\n"
"}"));
        gridLayoutWidget_4 = new QWidget(frame_5);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(130, 70, 181, 81));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        frame_6 = new QFrame(motores);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setGeometry(QRect(20, 160, 331, 211));
        frame_6->setStyleSheet(QLatin1String("#frame_6\n"
"{\n"
"background-color: black;\n"
"color: white;\n"
"border-style: solid;\n"
"border-width:1px;\n"
"border-color: rgb(0, 167, 250);\n"
"border-radius: 10px;\n"
"}"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(frame_6);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(110, 10, 121, 20));
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral("color:white"));
        label_6->setAlignment(Qt::AlignCenter);
        regulador_imagen_2 = new QLabel(frame_6);
        regulador_imagen_2->setObjectName(QStringLiteral("regulador_imagen_2"));
        regulador_imagen_2->setGeometry(QRect(10, 60, 121, 121));
        regulador_imagen_2->setStyleSheet(QLatin1String("#regulador_imagen_2\n"
"{\n"
"background-image: url(:/gifs/1 Carcamo y Regulador/screen800x600/gifs/1 Carcamo y Regulador/carcamo hi quiet water.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"border: none;\n"
"}"));
        comboBox_5 = new QComboBox(frame_6);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        comboBox_5->setGeometry(QRect(140, 40, 171, 22));
        comboBox_5->setStyleSheet(QLatin1String("#comboBox\n"
"{\n"
"background-color: black;\n"
"color: white;\n"
"}"));
        gridLayoutWidget_5 = new QWidget(frame_6);
        gridLayoutWidget_5->setObjectName(QStringLiteral("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(140, 90, 181, 101));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);

        retranslateUi(motores);

        QMetaObject::connectSlotsByName(motores);
    } // setupUi

    void retranslateUi(QDialog *motores)
    {
        motores->setWindowTitle(QApplication::translate("motores", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("motores", "Regulador", Q_NULLPTR));
        regulador_imagen->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("motores", "Paro", Q_NULLPTR)
         << QApplication::translate("motores", "Automatico", Q_NULLPTR)
         << QApplication::translate("motores", "Manual", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("motores", "Reactor", Q_NULLPTR));
        reactor_imagen->setText(QString());
        gif_blower->setText(QString());
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("motores", "Paro", Q_NULLPTR)
         << QApplication::translate("motores", "Automatico", Q_NULLPTR)
         << QApplication::translate("motores", "Manual", Q_NULLPTR)
        );
        asa_logo->setText(QString());
        label_3->setText(QApplication::translate("motores", "Alto general. Presionar durante 3 segundos para activar/desactivar", Q_NULLPTR));
        pushButton->setText(QString());
        stop_button_image->setText(QString());
        label_4->setText(QApplication::translate("motores", "Filtro", Q_NULLPTR));
        filtro_imagen->setText(QString());
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("motores", "Paro", Q_NULLPTR)
         << QApplication::translate("motores", "Automatico", Q_NULLPTR)
         << QApplication::translate("motores", "Manual", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("motores", "Bomba de Alimentaci\303\263n", Q_NULLPTR));
        filtro_imagen_2->setText(QString());
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("motores", "Paro", Q_NULLPTR)
         << QApplication::translate("motores", "Automatico", Q_NULLPTR)
         << QApplication::translate("motores", "Manual", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("motores", "Carcamo", Q_NULLPTR));
        regulador_imagen_2->setText(QString());
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("motores", "Paro", Q_NULLPTR)
         << QApplication::translate("motores", "Automatico", Q_NULLPTR)
         << QApplication::translate("motores", "Manual", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class motores: public Ui_motores {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOTORES_H
