/********************************************************************************
** Form generated from reading UI file 'records.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDS_H
#define UI_RECORDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_records
{
public:
    QFrame *key_frame;
    QPushButton *key_0;
    QPushButton *key_4;
    QPushButton *key_5;
    QPushButton *key_7;
    QPushButton *key_8;
    QPushButton *key_1;
    QPushButton *key_6;
    QPushButton *key_back;
    QPushButton *key_3;
    QPushButton *key_9;
    QPushButton *key_2;
    QPushButton *key_Q;
    QPushButton *key_W;
    QPushButton *key_E;
    QPushButton *key_R;
    QPushButton *key_T;
    QPushButton *key_Y;
    QPushButton *key_U;
    QPushButton *key_I;
    QPushButton *key_P;
    QPushButton *key_O;
    QPushButton *key_A;
    QPushButton *key_L;
    QPushButton *key_H;
    QPushButton *key_G;
    QPushButton *key_F;
    QPushButton *key_S;
    QPushButton *key_D;
    QPushButton *key_J;
    QPushButton *key_K;
    QPushButton *key_dot;
    QPushButton *key_slash;
    QPushButton *key_plus;
    QPushButton *key_minus;
    QPushButton *key_X;
    QPushButton *key_Z;
    QPushButton *key_M;
    QPushButton *key_C;
    QPushButton *key_V;
    QPushButton *key_B;
    QPushButton *key_N;
    QPushButton *key_comma;
    QPushButton *key_space;
    QPushButton *key_enter;
    QPushButton *key_mayus;
    QPushButton *key_L_corchete;
    QPushButton *key_equal;
    QPushButton *key_R_corchete;
    QFrame *frame;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *opt_text_name_label;
    QLabel *opt_text_units_label;
    QTextEdit *opt_text_textEdit;
    QPushButton *pushButton;
    QLabel *button_image;
    QWidget *tab_2;
    QLabel *opt_ch_name_label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;

    void setupUi(QDialog *records)
    {
        if (records->objectName().isEmpty())
            records->setObjectName(QStringLiteral("records"));
        records->resize(800, 600);
        key_frame = new QFrame(records);
        key_frame->setObjectName(QStringLiteral("key_frame"));
        key_frame->setGeometry(QRect(10, 380, 781, 191));
        key_frame->setStyleSheet(QLatin1String("#key_frame\n"
"{\n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/fondo teclado 2.png);\n"
"background-repeat:none;\n"
"/*background-color: black;*/\n"
"border:none;\n"
"}"));
        key_frame->setFrameShape(QFrame::StyledPanel);
        key_frame->setFrameShadow(QFrame::Raised);
        key_0 = new QPushButton(key_frame);
        key_0->setObjectName(QStringLiteral("key_0"));
        key_0->setGeometry(QRect(536, 96, 41, 41));
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
        key_4 = new QPushButton(key_frame);
        key_4->setObjectName(QStringLiteral("key_4"));
        key_4->setGeometry(QRect(582, 49, 41, 41));
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
        key_5 = new QPushButton(key_frame);
        key_5->setObjectName(QStringLiteral("key_5"));
        key_5->setGeometry(QRect(625, 49, 41, 41));
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
        key_7 = new QPushButton(key_frame);
        key_7->setObjectName(QStringLiteral("key_7"));
        key_7->setGeometry(QRect(581, 4, 41, 41));
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
        key_8 = new QPushButton(key_frame);
        key_8->setObjectName(QStringLiteral("key_8"));
        key_8->setGeometry(QRect(625, 4, 41, 41));
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
        key_1 = new QPushButton(key_frame);
        key_1->setObjectName(QStringLiteral("key_1"));
        key_1->setGeometry(QRect(582, 96, 41, 41));
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
        key_6 = new QPushButton(key_frame);
        key_6->setObjectName(QStringLiteral("key_6"));
        key_6->setGeometry(QRect(670, 49, 41, 41));
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
        key_back = new QPushButton(key_frame);
        key_back->setObjectName(QStringLiteral("key_back"));
        key_back->setGeometry(QRect(470, 4, 61, 41));
        key_back->setFocusPolicy(Qt::NoFocus);
        key_back->setStyleSheet(QLatin1String("#key_back{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Backspace azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"\n"
"}\n"
"\n"
"#key_back::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Backspace blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_back->setCheckable(false);
        key_3 = new QPushButton(key_frame);
        key_3->setObjectName(QStringLiteral("key_3"));
        key_3->setGeometry(QRect(663, 92, 50, 50));
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
        key_9 = new QPushButton(key_frame);
        key_9->setObjectName(QStringLiteral("key_9"));
        key_9->setGeometry(QRect(668, 3, 41, 41));
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
        key_2 = new QPushButton(key_frame);
        key_2->setObjectName(QStringLiteral("key_2"));
        key_2->setGeometry(QRect(626, 97, 41, 41));
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
        key_Q = new QPushButton(key_frame);
        key_Q->setObjectName(QStringLiteral("key_Q"));
        key_Q->setGeometry(QRect(27, 5, 41, 41));
        key_Q->setFocusPolicy(Qt::NoFocus);
        key_Q->setStyleSheet(QLatin1String("#key_Q{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Q azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_Q::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Q blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_Q->setCheckable(false);
        key_W = new QPushButton(key_frame);
        key_W->setObjectName(QStringLiteral("key_W"));
        key_W->setGeometry(QRect(72, 4, 41, 41));
        key_W->setFocusPolicy(Qt::NoFocus);
        key_W->setStyleSheet(QLatin1String("#key_W{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/W azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_W::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/W blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_W->setCheckable(false);
        key_E = new QPushButton(key_frame);
        key_E->setObjectName(QStringLiteral("key_E"));
        key_E->setGeometry(QRect(116, 4, 41, 41));
        key_E->setFocusPolicy(Qt::NoFocus);
        key_E->setStyleSheet(QLatin1String("#key_E{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/E azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_E::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/E blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_E->setCheckable(false);
        key_R = new QPushButton(key_frame);
        key_R->setObjectName(QStringLiteral("key_R"));
        key_R->setGeometry(QRect(161, 5, 41, 41));
        key_R->setFocusPolicy(Qt::NoFocus);
        key_R->setStyleSheet(QLatin1String("#key_R{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/R azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_R::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/R blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_R->setCheckable(false);
        key_T = new QPushButton(key_frame);
        key_T->setObjectName(QStringLiteral("key_T"));
        key_T->setGeometry(QRect(204, 5, 41, 41));
        key_T->setFocusPolicy(Qt::NoFocus);
        key_T->setStyleSheet(QLatin1String("#key_T{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/T azul.png);\n"
"border:none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_T::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/T blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_T->setCheckable(false);
        key_Y = new QPushButton(key_frame);
        key_Y->setObjectName(QStringLiteral("key_Y"));
        key_Y->setGeometry(QRect(246, 4, 41, 41));
        key_Y->setFocusPolicy(Qt::NoFocus);
        key_Y->setStyleSheet(QLatin1String("#key_Y{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Y azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_Y::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Y blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_Y->setCheckable(false);
        key_U = new QPushButton(key_frame);
        key_U->setObjectName(QStringLiteral("key_U"));
        key_U->setGeometry(QRect(291, 4, 41, 41));
        key_U->setFocusPolicy(Qt::NoFocus);
        key_U->setStyleSheet(QLatin1String("#key_U{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/U azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_U::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/U blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_U->setCheckable(false);
        key_I = new QPushButton(key_frame);
        key_I->setObjectName(QStringLiteral("key_I"));
        key_I->setGeometry(QRect(335, 4, 41, 41));
        key_I->setFocusPolicy(Qt::NoFocus);
        key_I->setStyleSheet(QLatin1String("#key_I{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/I azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_I::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/I blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_I->setCheckable(false);
        key_P = new QPushButton(key_frame);
        key_P->setObjectName(QStringLiteral("key_P"));
        key_P->setGeometry(QRect(422, 5, 41, 41));
        key_P->setFocusPolicy(Qt::NoFocus);
        key_P->setStyleSheet(QLatin1String("#key_P{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/P azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_P::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/P blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_P->setCheckable(false);
        key_O = new QPushButton(key_frame);
        key_O->setObjectName(QStringLiteral("key_O"));
        key_O->setGeometry(QRect(379, 5, 41, 41));
        key_O->setFocusPolicy(Qt::NoFocus);
        key_O->setStyleSheet(QLatin1String("#key_O{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/O azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_O::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/O blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_O->setCheckable(false);
        key_A = new QPushButton(key_frame);
        key_A->setObjectName(QStringLiteral("key_A"));
        key_A->setGeometry(QRect(11, 50, 41, 41));
        key_A->setFocusPolicy(Qt::NoFocus);
        key_A->setStyleSheet(QLatin1String("#key_A{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/A azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_A::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/A blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_A->setCheckable(false);
        key_L = new QPushButton(key_frame);
        key_L->setObjectName(QStringLiteral("key_L"));
        key_L->setGeometry(QRect(359, 49, 41, 41));
        key_L->setFocusPolicy(Qt::NoFocus);
        key_L->setStyleSheet(QLatin1String("#key_L{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/L azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_L::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/L blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_L->setCheckable(false);
        key_H = new QPushButton(key_frame);
        key_H->setObjectName(QStringLiteral("key_H"));
        key_H->setGeometry(QRect(228, 50, 41, 41));
        key_H->setFocusPolicy(Qt::NoFocus);
        key_H->setStyleSheet(QLatin1String("#key_H{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/H azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_H::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/H blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_H->setCheckable(false);
        key_G = new QPushButton(key_frame);
        key_G->setObjectName(QStringLiteral("key_G"));
        key_G->setGeometry(QRect(184, 50, 41, 41));
        key_G->setFocusPolicy(Qt::NoFocus);
        key_G->setStyleSheet(QLatin1String("#key_G{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/G azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_G::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/G blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_G->setCheckable(false);
        key_F = new QPushButton(key_frame);
        key_F->setObjectName(QStringLiteral("key_F"));
        key_F->setGeometry(QRect(142, 50, 41, 41));
        key_F->setFocusPolicy(Qt::NoFocus);
        key_F->setStyleSheet(QLatin1String("#key_F{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/F azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_F::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/F blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_F->setCheckable(false);
        key_S = new QPushButton(key_frame);
        key_S->setObjectName(QStringLiteral("key_S"));
        key_S->setGeometry(QRect(55, 50, 41, 41));
        key_S->setFocusPolicy(Qt::NoFocus);
        key_S->setStyleSheet(QLatin1String("#key_S{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/S azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_S::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/S blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_S->setCheckable(false);
        key_D = new QPushButton(key_frame);
        key_D->setObjectName(QStringLiteral("key_D"));
        key_D->setGeometry(QRect(98, 51, 41, 41));
        key_D->setFocusPolicy(Qt::NoFocus);
        key_D->setStyleSheet(QLatin1String("#key_D{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/D azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_D::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/D blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_D->setCheckable(false);
        key_J = new QPushButton(key_frame);
        key_J->setObjectName(QStringLiteral("key_J"));
        key_J->setGeometry(QRect(271, 50, 41, 41));
        key_J->setFocusPolicy(Qt::NoFocus);
        key_J->setStyleSheet(QLatin1String("#key_J{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/J azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_J::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/J blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_J->setCheckable(false);
        key_K = new QPushButton(key_frame);
        key_K->setObjectName(QStringLiteral("key_K"));
        key_K->setGeometry(QRect(316, 50, 41, 41));
        key_K->setFocusPolicy(Qt::NoFocus);
        key_K->setStyleSheet(QLatin1String("#key_K{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/K azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_K::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/K blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_K->setCheckable(false);
        key_dot = new QPushButton(key_frame);
        key_dot->setObjectName(QStringLiteral("key_dot"));
        key_dot->setGeometry(QRect(470, 97, 41, 41));
        key_dot->setFocusPolicy(Qt::NoFocus);
        key_dot->setStyleSheet(QLatin1String("#key_dot{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Punto azul 2.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_dot::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Punto blanco 2.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_dot->setCheckable(false);
        key_slash = new QPushButton(key_frame);
        key_slash->setObjectName(QStringLiteral("key_slash"));
        key_slash->setGeometry(QRect(536, 4, 41, 41));
        key_slash->setFocusPolicy(Qt::NoFocus);
        key_slash->setStyleSheet(QLatin1String("#key_slash{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/slash azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_slash::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/slash blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_slash->setCheckable(false);
        key_plus = new QPushButton(key_frame);
        key_plus->setObjectName(QStringLiteral("key_plus"));
        key_plus->setGeometry(QRect(715, 96, 41, 41));
        key_plus->setFocusPolicy(Qt::NoFocus);
        key_plus->setStyleSheet(QLatin1String("#key_plus{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/plus_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_plus::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/plus_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_plus->setCheckable(false);
        key_minus = new QPushButton(key_frame);
        key_minus->setObjectName(QStringLiteral("key_minus"));
        key_minus->setGeometry(QRect(715, 49, 41, 41));
        key_minus->setFocusPolicy(Qt::NoFocus);
        key_minus->setStyleSheet(QLatin1String("#key_minus{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/minus_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_minus::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/minus_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_minus->setCheckable(false);
        key_X = new QPushButton(key_frame);
        key_X->setObjectName(QStringLiteral("key_X"));
        key_X->setGeometry(QRect(160, 97, 41, 41));
        key_X->setFocusPolicy(Qt::NoFocus);
        key_X->setStyleSheet(QLatin1String("#key_X{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/X azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_X::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/X blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_X->setCheckable(false);
        key_Z = new QPushButton(key_frame);
        key_Z->setObjectName(QStringLiteral("key_Z"));
        key_Z->setGeometry(QRect(117, 97, 41, 41));
        key_Z->setFocusPolicy(Qt::NoFocus);
        key_Z->setStyleSheet(QLatin1String("#key_Z{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Z azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_Z::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Z blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_Z->setCheckable(false);
        key_M = new QPushButton(key_frame);
        key_M->setObjectName(QStringLiteral("key_M"));
        key_M->setGeometry(QRect(378, 96, 41, 41));
        key_M->setFocusPolicy(Qt::NoFocus);
        key_M->setStyleSheet(QLatin1String("#key_M{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/M azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_M::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/M blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_M->setCheckable(false);
        key_C = new QPushButton(key_frame);
        key_C->setObjectName(QStringLiteral("key_C"));
        key_C->setGeometry(QRect(204, 96, 41, 41));
        key_C->setFocusPolicy(Qt::NoFocus);
        key_C->setStyleSheet(QLatin1String("#key_C{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/C azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_C::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/C blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_C->setCheckable(false);
        key_V = new QPushButton(key_frame);
        key_V->setObjectName(QStringLiteral("key_V"));
        key_V->setGeometry(QRect(248, 96, 41, 41));
        key_V->setFocusPolicy(Qt::NoFocus);
        key_V->setStyleSheet(QLatin1String("#key_V{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/V azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_V::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/V blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_V->setCheckable(false);
        key_B = new QPushButton(key_frame);
        key_B->setObjectName(QStringLiteral("key_B"));
        key_B->setGeometry(QRect(291, 96, 41, 41));
        key_B->setFocusPolicy(Qt::NoFocus);
        key_B->setStyleSheet(QLatin1String("#key_B{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/B azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_B::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/B blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_B->setCheckable(false);
        key_N = new QPushButton(key_frame);
        key_N->setObjectName(QStringLiteral("key_N"));
        key_N->setGeometry(QRect(335, 96, 41, 41));
        key_N->setFocusPolicy(Qt::NoFocus);
        key_N->setStyleSheet(QLatin1String("#key_N{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/N azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_N::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/N blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_N->setCheckable(false);
        key_comma = new QPushButton(key_frame);
        key_comma->setObjectName(QStringLiteral("key_comma"));
        key_comma->setGeometry(QRect(422, 97, 41, 41));
        key_comma->setFocusPolicy(Qt::NoFocus);
        key_comma->setStyleSheet(QLatin1String("#key_comma{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/coma azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_comma::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/coma blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_comma->setCheckable(false);
        key_space = new QPushButton(key_frame);
        key_space->setObjectName(QStringLiteral("key_space"));
        key_space->setGeometry(QRect(148, 136, 281, 50));
        key_space->setFocusPolicy(Qt::NoFocus);
        key_space->setStyleSheet(QLatin1String("#key_space{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Espacio azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_space::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Espacio blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_space->setCheckable(false);
        key_enter = new QPushButton(key_frame);
        key_enter->setObjectName(QStringLiteral("key_enter"));
        key_enter->setGeometry(QRect(494, 49, 81, 41));
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
        key_mayus = new QPushButton(key_frame);
        key_mayus->setObjectName(QStringLiteral("key_mayus"));
        key_mayus->setGeometry(QRect(24, 97, 91, 41));
        key_mayus->setFocusPolicy(Qt::NoFocus);
        key_mayus->setStyleSheet(QLatin1String("#key_mayus{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Mayus azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_mayus::checked{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Mayus bco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_mayus->setCheckable(true);
        key_mayus->setChecked(false);
        key_L_corchete = new QPushButton(key_frame);
        key_L_corchete->setObjectName(QStringLiteral("key_L_corchete"));
        key_L_corchete->setGeometry(QRect(403, 50, 41, 41));
        key_L_corchete->setFocusPolicy(Qt::NoFocus);
        key_L_corchete->setStyleSheet(QLatin1String("#key_L_corchete{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Corchete izq. azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_L_corchete::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Corchete izq. blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_L_corchete->setCheckable(false);
        key_equal = new QPushButton(key_frame);
        key_equal->setObjectName(QStringLiteral("key_equal"));
        key_equal->setGeometry(QRect(715, 4, 41, 41));
        key_equal->setFocusPolicy(Qt::NoFocus);
        key_equal->setStyleSheet(QLatin1String("#key_equal{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Igual azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_equal::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Igual blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_equal->setCheckable(false);
        key_R_corchete = new QPushButton(key_frame);
        key_R_corchete->setObjectName(QStringLiteral("key_R_corchete"));
        key_R_corchete->setGeometry(QRect(447, 50, 41, 41));
        key_R_corchete->setFocusPolicy(Qt::NoFocus);
        key_R_corchete->setStyleSheet(QLatin1String("#key_R_corchete{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Corchete der. azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_R_corchete::pressed{ \n"
"background-image: url(:/texto/screen800x600/texto/Teclado 1.1/Corchete der. blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_R_corchete->setCheckable(false);
        frame = new QFrame(records);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(110, 9, 561, 261));
        frame->setStyleSheet(QLatin1String("#frame\n"
"{\n"
"background-image: url(:/iconos/screen800x600/iconos/Cuadro pantalla.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"background-color: transparent;\n"
"border:none;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(50, 20, 461, 161));
        tabWidget->setStyleSheet(QLatin1String("#tabWidget { \n"
"background-color: none;\n"
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
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setStyleSheet(QStringLiteral(""));
        opt_text_name_label = new QLabel(tab);
        opt_text_name_label->setObjectName(QStringLiteral("opt_text_name_label"));
        opt_text_name_label->setGeometry(QRect(0, 0, 461, 81));
        opt_text_name_label->setWordWrap(true);
        opt_text_units_label = new QLabel(tab);
        opt_text_units_label->setObjectName(QStringLiteral("opt_text_units_label"));
        opt_text_units_label->setGeometry(QRect(333, 100, 71, 31));
        opt_text_units_label->setStyleSheet(QLatin1String("#opt_text_units_label\n"
"{\n"
"background-color: transparent;\n"
"border: none;\n"
"}"));
        opt_text_units_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        opt_text_textEdit = new QTextEdit(tab);
        opt_text_textEdit->setObjectName(QStringLiteral("opt_text_textEdit"));
        opt_text_textEdit->setGeometry(QRect(279, 99, 51, 41));
        opt_text_textEdit->setStyleSheet(QLatin1String("#opt_text_textEdit\n"
"{\n"
"background-color: transparent;\n"
"border: none;\n"
"}"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(410, 100, 31, 31));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QLatin1String("#pushButton\n"
"{\n"
"background-color: transparent;\n"
"border:none;\n"
"}"));
        button_image = new QLabel(tab);
        button_image->setObjectName(QStringLiteral("button_image"));
        button_image->setGeometry(QRect(270, 100, 171, 31));
        button_image->setStyleSheet(QLatin1String("#button_image\n"
"{\n"
"background-image: url(:/iconos/screen800x600/iconos/boton_records_2.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        tabWidget->addTab(tab, QString());
        button_image->raise();
        opt_text_name_label->raise();
        opt_text_units_label->raise();
        opt_text_textEdit->raise();
        pushButton->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        opt_ch_name_label = new QLabel(tab_2);
        opt_ch_name_label->setObjectName(QStringLiteral("opt_ch_name_label"));
        opt_ch_name_label->setGeometry(QRect(10, 0, 451, 81));
        opt_ch_name_label->setWordWrap(true);
        horizontalLayoutWidget = new QWidget(tab_2);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 80, 361, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(373, 95, 41, 31));
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        pushButton_2->setStyleSheet(QLatin1String("#pushButton_2\n"
"{\n"
"background-image: url(:/iconos/screen800x600/iconos/boton_records_ok.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"border:none;\n"
"}"));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(records);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(records);
    } // setupUi

    void retranslateUi(QDialog *records)
    {
        records->setWindowTitle(QApplication::translate("records", "Dialog", Q_NULLPTR));
        key_0->setText(QString());
        key_4->setText(QString());
        key_5->setText(QString());
        key_7->setText(QString());
        key_8->setText(QString());
        key_1->setText(QString());
        key_6->setText(QString());
        key_back->setText(QString());
        key_3->setText(QString());
        key_9->setText(QString());
        key_2->setText(QString());
        key_Q->setText(QString());
        key_W->setText(QString());
        key_E->setText(QString());
        key_R->setText(QString());
        key_T->setText(QString());
        key_Y->setText(QString());
        key_U->setText(QString());
        key_I->setText(QString());
        key_P->setText(QString());
        key_O->setText(QString());
        key_A->setText(QString());
        key_L->setText(QString());
        key_H->setText(QString());
        key_G->setText(QString());
        key_F->setText(QString());
        key_S->setText(QString());
        key_D->setText(QString());
        key_J->setText(QString());
        key_K->setText(QString());
        key_dot->setText(QString());
        key_slash->setText(QString());
        key_plus->setText(QString());
        key_minus->setText(QString());
        key_X->setText(QString());
        key_Z->setText(QString());
        key_M->setText(QString());
        key_C->setText(QString());
        key_V->setText(QString());
        key_B->setText(QString());
        key_N->setText(QString());
        key_comma->setText(QString());
        key_space->setText(QString());
        key_enter->setText(QString());
        key_mayus->setText(QString());
        key_L_corchete->setText(QString());
        key_equal->setText(QString());
        key_R_corchete->setText(QString());
        opt_text_name_label->setText(QApplication::translate("records", "Pregunta:", Q_NULLPTR));
        opt_text_units_label->setText(QString());
        pushButton->setText(QString());
        button_image->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QString());
        opt_ch_name_label->setText(QApplication::translate("records", "Pregunta:", Q_NULLPTR));
        pushButton_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QString());
    } // retranslateUi

};

namespace Ui {
    class records: public Ui_records {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDS_H