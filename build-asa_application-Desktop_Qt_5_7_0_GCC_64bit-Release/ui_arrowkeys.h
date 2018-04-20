/********************************************************************************
** Form generated from reading UI file 'arrowkeys.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARROWKEYS_H
#define UI_ARROWKEYS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_arrowkeys
{
public:
    QFrame *frame;
    QPushButton *key_rigth;
    QPushButton *key_down;
    QPushButton *key_up;
    QPushButton *key_left;

    void setupUi(QDialog *arrowkeys)
    {
        if (arrowkeys->objectName().isEmpty())
            arrowkeys->setObjectName(QStringLiteral("arrowkeys"));
        arrowkeys->resize(800, 600);
        arrowkeys->setStyleSheet(QLatin1String("#arrowkeys\n"
"{\n"
"background-color:transparent;\n"
"border-image:none;\n"
"}"));
        frame = new QFrame(arrowkeys);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(650, 460, 141, 91));
        frame->setStyleSheet(QLatin1String("#frame\n"
"{\n"
"border:none;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        key_rigth = new QPushButton(frame);
        key_rigth->setObjectName(QStringLiteral("key_rigth"));
        key_rigth->setGeometry(QRect(100, 50, 41, 41));
        key_rigth->setFocusPolicy(Qt::NoFocus);
        key_rigth->setStyleSheet(QLatin1String("#key_rigth{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/arrow_rigth_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_rigth::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/arrow_rigth_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_rigth->setCheckable(false);
        key_down = new QPushButton(frame);
        key_down->setObjectName(QStringLiteral("key_down"));
        key_down->setGeometry(QRect(50, 50, 41, 41));
        key_down->setFocusPolicy(Qt::NoFocus);
        key_down->setStyleSheet(QLatin1String("#key_down{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/arrow_down_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_down::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/arrow_down_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_down->setCheckable(false);
        key_up = new QPushButton(frame);
        key_up->setObjectName(QStringLiteral("key_up"));
        key_up->setGeometry(QRect(50, 0, 41, 41));
        key_up->setFocusPolicy(Qt::NoFocus);
        key_up->setStyleSheet(QLatin1String("#key_up{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/arrow_up_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_up::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/arrow_up_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_up->setCheckable(false);
        key_left = new QPushButton(frame);
        key_left->setObjectName(QStringLiteral("key_left"));
        key_left->setGeometry(QRect(0, 50, 41, 41));
        key_left->setFocusPolicy(Qt::NoFocus);
        key_left->setStyleSheet(QLatin1String("#key_left{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/arrow_left_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_left::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/arrow_left_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_left->setCheckable(false);

        retranslateUi(arrowkeys);

        QMetaObject::connectSlotsByName(arrowkeys);
    } // setupUi

    void retranslateUi(QDialog *arrowkeys)
    {
        arrowkeys->setWindowTitle(QApplication::translate("arrowkeys", "Dialog", 0));
        key_rigth->setText(QString());
        key_down->setText(QString());
        key_up->setText(QString());
        key_left->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class arrowkeys: public Ui_arrowkeys {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARROWKEYS_H
