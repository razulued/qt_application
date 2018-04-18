/********************************************************************************
** Form generated from reading UI file 'login_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_DIALOG_H
#define UI_LOGIN_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login_dialog
{
public:
    QPushButton *key_4;
    QPushButton *key_0;
    QPushButton *key_1;
    QPushButton *key_5;
    QPushButton *key_2;
    QPushButton *key_6;
    QPushButton *key_8;
    QPushButton *key_7;
    QPushButton *key_9;
    QPushButton *key_3;
    QPushButton *key_enter;
    QPlainTextEdit *textedit;

    void setupUi(QDialog *login_dialog)
    {
        if (login_dialog->objectName().isEmpty())
            login_dialog->setObjectName(QStringLiteral("login_dialog"));
        login_dialog->resize(213, 320);
        login_dialog->setStyleSheet(QLatin1String("#login_dialog\n"
"{\n"
"background-color: black;\n"
"}"));
        key_4 = new QPushButton(login_dialog);
        key_4->setObjectName(QStringLiteral("key_4"));
        key_4->setGeometry(QRect(20, 141, 50, 50));
        key_4->setFocusPolicy(Qt::NoFocus);
        key_4->setStyleSheet(QLatin1String("#key_4{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/4 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_4::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/4 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_4->setCheckable(false);
        key_0 = new QPushButton(login_dialog);
        key_0->setObjectName(QStringLiteral("key_0"));
        key_0->setGeometry(QRect(21, 261, 50, 50));
        key_0->setFocusPolicy(Qt::NoFocus);
        key_0->setStyleSheet(QLatin1String("#key_0{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/0 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_0::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/0 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_0->setCheckable(false);
        key_1 = new QPushButton(login_dialog);
        key_1->setObjectName(QStringLiteral("key_1"));
        key_1->setGeometry(QRect(20, 203, 50, 50));
        key_1->setFocusPolicy(Qt::NoFocus);
        key_1->setStyleSheet(QLatin1String("#key_1{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/1 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_1::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/1 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_1->setCheckable(false);
        key_5 = new QPushButton(login_dialog);
        key_5->setObjectName(QStringLiteral("key_5"));
        key_5->setGeometry(QRect(80, 141, 50, 50));
        key_5->setFocusPolicy(Qt::NoFocus);
        key_5->setStyleSheet(QLatin1String("#key_5{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/5 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_5::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/5 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_5->setCheckable(false);
        key_2 = new QPushButton(login_dialog);
        key_2->setObjectName(QStringLiteral("key_2"));
        key_2->setGeometry(QRect(80, 203, 50, 50));
        key_2->setFocusPolicy(Qt::NoFocus);
        key_2->setStyleSheet(QLatin1String("#key_2{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/2 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_2::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/2 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_2->setCheckable(false);
        key_6 = new QPushButton(login_dialog);
        key_6->setObjectName(QStringLiteral("key_6"));
        key_6->setGeometry(QRect(140, 141, 50, 50));
        key_6->setFocusPolicy(Qt::NoFocus);
        key_6->setStyleSheet(QLatin1String("#key_6{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/6 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_6::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/6 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_6->setCheckable(false);
        key_8 = new QPushButton(login_dialog);
        key_8->setObjectName(QStringLiteral("key_8"));
        key_8->setGeometry(QRect(80, 79, 50, 50));
        key_8->setFocusPolicy(Qt::NoFocus);
        key_8->setStyleSheet(QLatin1String("#key_8{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/8 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_8::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/8 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_8->setCheckable(false);
        key_7 = new QPushButton(login_dialog);
        key_7->setObjectName(QStringLiteral("key_7"));
        key_7->setGeometry(QRect(20, 79, 50, 50));
        key_7->setFocusPolicy(Qt::NoFocus);
        key_7->setStyleSheet(QLatin1String("#key_7{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/7 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_7::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/7 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_7->setCheckable(false);
        key_9 = new QPushButton(login_dialog);
        key_9->setObjectName(QStringLiteral("key_9"));
        key_9->setGeometry(QRect(140, 79, 50, 50));
        key_9->setFocusPolicy(Qt::NoFocus);
        key_9->setStyleSheet(QLatin1String("#key_9{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/9 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_9::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/9 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_9->setCheckable(false);
        key_3 = new QPushButton(login_dialog);
        key_3->setObjectName(QStringLiteral("key_3"));
        key_3->setGeometry(QRect(140, 203, 50, 50));
        key_3->setFocusPolicy(Qt::NoFocus);
        key_3->setStyleSheet(QLatin1String("#key_3{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/3 azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_3::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/3 blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_3->setCheckable(false);
        key_enter = new QPushButton(login_dialog);
        key_enter->setObjectName(QStringLiteral("key_enter"));
        key_enter->setGeometry(QRect(80, 260, 111, 51));
        key_enter->setFocusPolicy(Qt::NoFocus);
        key_enter->setStyleSheet(QLatin1String("#key_enter{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Enter azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_enter::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Enter blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_enter->setCheckable(false);
        textedit = new QPlainTextEdit(login_dialog);
        textedit->setObjectName(QStringLiteral("textedit"));
        textedit->setGeometry(QRect(20, 10, 171, 51));

        retranslateUi(login_dialog);

        QMetaObject::connectSlotsByName(login_dialog);
    } // setupUi

    void retranslateUi(QDialog *login_dialog)
    {
        login_dialog->setWindowTitle(QApplication::translate("login_dialog", "Dialog", 0));
        key_4->setText(QString());
        key_0->setText(QString());
        key_1->setText(QString());
        key_5->setText(QString());
        key_2->setText(QString());
        key_6->setText(QString());
        key_8->setText(QString());
        key_7->setText(QString());
        key_9->setText(QString());
        key_3->setText(QString());
        key_enter->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login_dialog: public Ui_login_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_DIALOG_H
