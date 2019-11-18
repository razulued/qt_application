/********************************************************************************
** Form generated from reading UI file 'calendario_filtro.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDARIO_FILTRO_H
#define UI_CALENDARIO_FILTRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_calendario_filtro
{
public:
    QFrame *frame;
    QPushButton *close;
    QPushButton *fecha_fin_btn;
    QPushButton *fecha_inicio_btn;
    QLabel *fecha_inicio_text;
    QLabel *fecha_fin_text;
    QPushButton *ok_button;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *back_1;
    QLabel *back_2;

    void setupUi(QDialog *calendario_filtro)
    {
        if (calendario_filtro->objectName().isEmpty())
            calendario_filtro->setObjectName(QStringLiteral("calendario_filtro"));
        calendario_filtro->resize(800, 600);
        frame = new QFrame(calendario_filtro);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(150, 70, 521, 261));
        frame->setStyleSheet(QLatin1String("#frame{\n"
"background-color: transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/Cuadro pantalla.png);\n"
"background-repeat: none;\n"
"border: none;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        close = new QPushButton(frame);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(480, 10, 41, 31));
        close->setFocusPolicy(Qt::NoFocus);
        close->setStyleSheet(QLatin1String("#close\n"
"{\n"
"background-color: transparent;\n"
"border: none;\n"
"}"));
        fecha_fin_btn = new QPushButton(frame);
        fecha_fin_btn->setObjectName(QStringLiteral("fecha_fin_btn"));
        fecha_fin_btn->setGeometry(QRect(231, 178, 145, 31));
        fecha_fin_btn->setFocusPolicy(Qt::NoFocus);
        fecha_fin_btn->setStyleSheet(QLatin1String("#fecha_fin_btn\n"
"{\n"
"background-color:transparent;\n"
"background-position: center;\n"
"background-repeat: none;\n"
"border:none;\n"
"}"));
        fecha_inicio_btn = new QPushButton(frame);
        fecha_inicio_btn->setObjectName(QStringLiteral("fecha_inicio_btn"));
        fecha_inicio_btn->setGeometry(QRect(93, 177, 131, 31));
        fecha_inicio_btn->setFocusPolicy(Qt::NoFocus);
        fecha_inicio_btn->setStyleSheet(QLatin1String("#fecha_inicio_btn\n"
"{\n"
"background-color:transparent;\n"
"background-position: center;\n"
"background-repeat: none;\n"
"border:none;\n"
"}"));
        fecha_inicio_text = new QLabel(frame);
        fecha_inicio_text->setObjectName(QStringLiteral("fecha_inicio_text"));
        fecha_inicio_text->setGeometry(QRect(160, 182, 71, 20));
        fecha_inicio_text->setAlignment(Qt::AlignCenter);
        fecha_fin_text = new QLabel(frame);
        fecha_fin_text->setObjectName(QStringLiteral("fecha_fin_text"));
        fecha_fin_text->setGeometry(QRect(300, 182, 67, 20));
        fecha_fin_text->setAlignment(Qt::AlignCenter);
        ok_button = new QPushButton(frame);
        ok_button->setObjectName(QStringLiteral("ok_button"));
        ok_button->setGeometry(QRect(377, 173, 41, 41));
        ok_button->setFocusPolicy(Qt::NoFocus);
        ok_button->setStyleSheet(QLatin1String("#ok_button\n"
"{\n"
"background-image: url(:/iconos/screen800x600/iconos/boton_records_ok.png);\n"
"background-position: center;\n"
"background-repeat: none;\n"
"border:none;\n"
"}"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 80, 371, 41));
        label->setStyleSheet(QStringLiteral("color:white"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(122, 183, 41, 20));
        label_2->setStyleSheet(QLatin1String("#label_2\n"
"{\n"
"background-color: transparent;\n"
"color: black;\n"
"boder:none;\n"
"}"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(264, 182, 31, 20));
        label_3->setStyleSheet(QLatin1String("#label_3\n"
"{\n"
"background-color: transparent;\n"
"color: black;\n"
"boder:none;\n"
"}"));
        back_1 = new QLabel(frame);
        back_1->setObjectName(QStringLiteral("back_1"));
        back_1->setGeometry(QRect(86, 177, 151, 31));
        back_1->setStyleSheet(QLatin1String("#back_1\n"
"{\n"
"background-image: url(:/iconos/screen800x600/iconos/Inicio.png);\n"
"background-position: center;\n"
"background-repeat: none;\n"
"border:none;\n"
"}"));
        back_2 = new QLabel(frame);
        back_2->setObjectName(QStringLiteral("back_2"));
        back_2->setGeometry(QRect(229, 177, 151, 31));
        back_2->setStyleSheet(QLatin1String("#back_2\n"
"{\n"
"background-image: url(:/iconos/screen800x600/iconos/Inicio.png);\n"
"background-position: center;\n"
"background-repeat: none;\n"
"border:none;\n"
"}"));
        back_2->raise();
        close->raise();
        ok_button->raise();
        label->raise();
        back_1->raise();
        label_2->raise();
        fecha_inicio_text->raise();
        fecha_inicio_btn->raise();
        label_3->raise();
        fecha_fin_text->raise();
        fecha_fin_btn->raise();

        retranslateUi(calendario_filtro);

        QMetaObject::connectSlotsByName(calendario_filtro);
    } // setupUi

    void retranslateUi(QDialog *calendario_filtro)
    {
        calendario_filtro->setWindowTitle(QApplication::translate("calendario_filtro", "Dialog", Q_NULLPTR));
        close->setText(QString());
        fecha_fin_btn->setText(QString());
        fecha_inicio_btn->setText(QString());
        fecha_inicio_text->setText(QString());
        fecha_fin_text->setText(QString());
        ok_button->setText(QString());
        label->setText(QApplication::translate("calendario_filtro", "Seleccione el Periodo a Visualizar", Q_NULLPTR));
        label_2->setText(QApplication::translate("calendario_filtro", "Inicio", Q_NULLPTR));
        label_3->setText(QApplication::translate("calendario_filtro", "Fin", Q_NULLPTR));
        back_1->setText(QString());
        back_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class calendario_filtro: public Ui_calendario_filtro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARIO_FILTRO_H
