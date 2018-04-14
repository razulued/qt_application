/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_settings
{
public:
    QLabel *label;
    QDialogButtonBox *buttonBox;
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
    QLabel *key_back_6;
    QTextEdit *textEdit;

    void setupUi(QDialog *settings)
    {
        if (settings->objectName().isEmpty())
            settings->setObjectName(QStringLiteral("settings"));
        settings->resize(1024, 768);
        label = new QLabel(settings);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(9, 9, 961, 41));
        label->setWordWrap(true);
        buttonBox = new QDialogButtonBox(settings);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(800, 700, 166, 61));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        key_frame = new QFrame(settings);
        key_frame->setObjectName(QStringLiteral("key_frame"));
        key_frame->setGeometry(QRect(30, 420, 941, 251));
        key_frame->setStyleSheet(QLatin1String("#key_frame\n"
"{\n"
"border-image: url(:/teclado/images/Texto/Teclado/Teclado_back.png);\n"
"background-repeat:none;\n"
"/*background-color: black;*/\n"
"border:none;\n"
"}"));
        key_frame->setFrameShape(QFrame::StyledPanel);
        key_frame->setFrameShadow(QFrame::Raised);
        key_0 = new QPushButton(key_frame);
        key_0->setObjectName(QStringLiteral("key_0"));
        key_0->setGeometry(QRect(759, 192, 50, 50));
        key_0->setFocusPolicy(Qt::NoFocus);
        key_0->setStyleSheet(QLatin1String("#key_0{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/0_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_0::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/0_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_0->setCheckable(false);
        key_4 = new QPushButton(key_frame);
        key_4->setObjectName(QStringLiteral("key_4"));
        key_4->setGeometry(QRect(699, 72, 50, 50));
        key_4->setFocusPolicy(Qt::NoFocus);
        key_4->setStyleSheet(QLatin1String("#key_4{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/4_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_4::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/4_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_4->setCheckable(false);
        key_5 = new QPushButton(key_frame);
        key_5->setObjectName(QStringLiteral("key_5"));
        key_5->setGeometry(QRect(759, 72, 50, 50));
        key_5->setFocusPolicy(Qt::NoFocus);
        key_5->setStyleSheet(QLatin1String("#key_5{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/5_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_5::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/5_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_5->setCheckable(false);
        key_7 = new QPushButton(key_frame);
        key_7->setObjectName(QStringLiteral("key_7"));
        key_7->setGeometry(QRect(699, 10, 50, 50));
        key_7->setFocusPolicy(Qt::NoFocus);
        key_7->setStyleSheet(QLatin1String("#key_7{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/7_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_7::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/7_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_7->setCheckable(false);
        key_8 = new QPushButton(key_frame);
        key_8->setObjectName(QStringLiteral("key_8"));
        key_8->setGeometry(QRect(759, 10, 50, 50));
        key_8->setFocusPolicy(Qt::NoFocus);
        key_8->setStyleSheet(QLatin1String("#key_8{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/8_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_8::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/8_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_8->setCheckable(false);
        key_1 = new QPushButton(key_frame);
        key_1->setObjectName(QStringLiteral("key_1"));
        key_1->setGeometry(QRect(699, 134, 50, 50));
        key_1->setFocusPolicy(Qt::NoFocus);
        key_1->setStyleSheet(QLatin1String("#key_1{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/1_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_1::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/1_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_1->setCheckable(false);
        key_6 = new QPushButton(key_frame);
        key_6->setObjectName(QStringLiteral("key_6"));
        key_6->setGeometry(QRect(819, 72, 50, 50));
        key_6->setFocusPolicy(Qt::NoFocus);
        key_6->setStyleSheet(QLatin1String("#key_6{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/6_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_6::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/6_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_6->setCheckable(false);
        key_back = new QPushButton(key_frame);
        key_back->setObjectName(QStringLiteral("key_back"));
        key_back->setGeometry(QRect(610, 10, 70, 50));
        key_back->setFocusPolicy(Qt::NoFocus);
        key_back->setStyleSheet(QLatin1String("#key_back{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/Backspace_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"\n"
"}\n"
"\n"
"#key_back::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/Backspace_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_back->setCheckable(false);
        key_3 = new QPushButton(key_frame);
        key_3->setObjectName(QStringLiteral("key_3"));
        key_3->setGeometry(QRect(819, 134, 50, 50));
        key_3->setFocusPolicy(Qt::NoFocus);
        key_3->setStyleSheet(QLatin1String("#key_3{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/3_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_3::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/3_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_3->setCheckable(false);
        key_9 = new QPushButton(key_frame);
        key_9->setObjectName(QStringLiteral("key_9"));
        key_9->setGeometry(QRect(819, 10, 50, 50));
        key_9->setFocusPolicy(Qt::NoFocus);
        key_9->setStyleSheet(QLatin1String("#key_9{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/9_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_9::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/9_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_9->setCheckable(false);
        key_2 = new QPushButton(key_frame);
        key_2->setObjectName(QStringLiteral("key_2"));
        key_2->setGeometry(QRect(759, 134, 50, 50));
        key_2->setFocusPolicy(Qt::NoFocus);
        key_2->setStyleSheet(QLatin1String("#key_2{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/2_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_2::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/2_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_2->setCheckable(false);
        key_Q = new QPushButton(key_frame);
        key_Q->setObjectName(QStringLiteral("key_Q"));
        key_Q->setGeometry(QRect(10, 10, 50, 50));
        key_Q->setFocusPolicy(Qt::NoFocus);
        key_Q->setStyleSheet(QLatin1String("#key_Q{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/Q_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_Q::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/Q_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_Q->setCheckable(false);
        key_W = new QPushButton(key_frame);
        key_W->setObjectName(QStringLiteral("key_W"));
        key_W->setGeometry(QRect(70, 10, 50, 50));
        key_W->setFocusPolicy(Qt::NoFocus);
        key_W->setStyleSheet(QLatin1String("#key_W{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/W_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_W::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/W_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_W->setCheckable(false);
        key_E = new QPushButton(key_frame);
        key_E->setObjectName(QStringLiteral("key_E"));
        key_E->setGeometry(QRect(130, 10, 50, 50));
        key_E->setFocusPolicy(Qt::NoFocus);
        key_E->setStyleSheet(QLatin1String("#key_E{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/E_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_E::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/E_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_E->setCheckable(false);
        key_R = new QPushButton(key_frame);
        key_R->setObjectName(QStringLiteral("key_R"));
        key_R->setGeometry(QRect(190, 10, 50, 50));
        key_R->setFocusPolicy(Qt::NoFocus);
        key_R->setStyleSheet(QLatin1String("#key_R{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/R_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_R::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/R_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_R->setCheckable(false);
        key_T = new QPushButton(key_frame);
        key_T->setObjectName(QStringLiteral("key_T"));
        key_T->setGeometry(QRect(250, 10, 50, 50));
        key_T->setFocusPolicy(Qt::NoFocus);
        key_T->setStyleSheet(QLatin1String("#key_T{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/T_azul.png);\n"
"border:none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_T::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/T_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_T->setCheckable(false);
        key_Y = new QPushButton(key_frame);
        key_Y->setObjectName(QStringLiteral("key_Y"));
        key_Y->setGeometry(QRect(310, 10, 50, 50));
        key_Y->setFocusPolicy(Qt::NoFocus);
        key_Y->setStyleSheet(QLatin1String("#key_Y{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/Y_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_Y::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/Y_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_Y->setCheckable(false);
        key_U = new QPushButton(key_frame);
        key_U->setObjectName(QStringLiteral("key_U"));
        key_U->setGeometry(QRect(370, 10, 50, 50));
        key_U->setFocusPolicy(Qt::NoFocus);
        key_U->setStyleSheet(QLatin1String("#key_U{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/U_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_U::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/U_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_U->setCheckable(false);
        key_I = new QPushButton(key_frame);
        key_I->setObjectName(QStringLiteral("key_I"));
        key_I->setGeometry(QRect(430, 10, 50, 50));
        key_I->setFocusPolicy(Qt::NoFocus);
        key_I->setStyleSheet(QLatin1String("#key_I{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/I_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_I::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/I_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_I->setCheckable(false);
        key_P = new QPushButton(key_frame);
        key_P->setObjectName(QStringLiteral("key_P"));
        key_P->setGeometry(QRect(550, 10, 50, 50));
        key_P->setFocusPolicy(Qt::NoFocus);
        key_P->setStyleSheet(QLatin1String("#key_P{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/P_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_P::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/P_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_P->setCheckable(false);
        key_O = new QPushButton(key_frame);
        key_O->setObjectName(QStringLiteral("key_O"));
        key_O->setGeometry(QRect(490, 10, 50, 50));
        key_O->setFocusPolicy(Qt::NoFocus);
        key_O->setStyleSheet(QLatin1String("#key_O{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/O_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_O::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/O_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_O->setCheckable(false);
        key_A = new QPushButton(key_frame);
        key_A->setObjectName(QStringLiteral("key_A"));
        key_A->setGeometry(QRect(45, 75, 50, 50));
        key_A->setFocusPolicy(Qt::NoFocus);
        key_A->setStyleSheet(QLatin1String("#key_A{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/A_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_A::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/A_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_A->setCheckable(false);
        key_L = new QPushButton(key_frame);
        key_L->setObjectName(QStringLiteral("key_L"));
        key_L->setGeometry(QRect(525, 75, 50, 50));
        key_L->setFocusPolicy(Qt::NoFocus);
        key_L->setStyleSheet(QLatin1String("#key_L{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/L_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_L::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/L_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_L->setCheckable(false);
        key_H = new QPushButton(key_frame);
        key_H->setObjectName(QStringLiteral("key_H"));
        key_H->setGeometry(QRect(345, 75, 50, 50));
        key_H->setFocusPolicy(Qt::NoFocus);
        key_H->setStyleSheet(QLatin1String("#key_H{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/H_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_H::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/H_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_H->setCheckable(false);
        key_G = new QPushButton(key_frame);
        key_G->setObjectName(QStringLiteral("key_G"));
        key_G->setGeometry(QRect(285, 75, 50, 50));
        key_G->setFocusPolicy(Qt::NoFocus);
        key_G->setStyleSheet(QLatin1String("#key_G{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/G_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_G::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/G_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_G->setCheckable(false);
        key_F = new QPushButton(key_frame);
        key_F->setObjectName(QStringLiteral("key_F"));
        key_F->setGeometry(QRect(225, 75, 50, 50));
        key_F->setFocusPolicy(Qt::NoFocus);
        key_F->setStyleSheet(QLatin1String("#key_F{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/F_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_F::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/F_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_F->setCheckable(false);
        key_S = new QPushButton(key_frame);
        key_S->setObjectName(QStringLiteral("key_S"));
        key_S->setGeometry(QRect(105, 75, 50, 50));
        key_S->setFocusPolicy(Qt::NoFocus);
        key_S->setStyleSheet(QLatin1String("#key_S{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/S_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_S::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/S_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_S->setCheckable(false);
        key_D = new QPushButton(key_frame);
        key_D->setObjectName(QStringLiteral("key_D"));
        key_D->setGeometry(QRect(165, 75, 50, 50));
        key_D->setFocusPolicy(Qt::NoFocus);
        key_D->setStyleSheet(QLatin1String("#key_D{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/D_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_D::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/D_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_D->setCheckable(false);
        key_J = new QPushButton(key_frame);
        key_J->setObjectName(QStringLiteral("key_J"));
        key_J->setGeometry(QRect(405, 75, 50, 50));
        key_J->setFocusPolicy(Qt::NoFocus);
        key_J->setStyleSheet(QLatin1String("#key_J{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/J_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_J::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/J_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_J->setCheckable(false);
        key_K = new QPushButton(key_frame);
        key_K->setObjectName(QStringLiteral("key_K"));
        key_K->setGeometry(QRect(465, 75, 50, 50));
        key_K->setFocusPolicy(Qt::NoFocus);
        key_K->setStyleSheet(QLatin1String("#key_K{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/K_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_K::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/K_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_K->setCheckable(false);
        key_dot = new QPushButton(key_frame);
        key_dot->setObjectName(QStringLiteral("key_dot"));
        key_dot->setGeometry(QRect(819, 192, 50, 50));
        key_dot->setFocusPolicy(Qt::NoFocus);
        key_dot->setStyleSheet(QLatin1String("#key_dot{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/punto_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_dot::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/punto_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_dot->setCheckable(false);
        key_slash = new QPushButton(key_frame);
        key_slash->setObjectName(QStringLiteral("key_slash"));
        key_slash->setGeometry(QRect(879, 10, 50, 50));
        key_slash->setFocusPolicy(Qt::NoFocus);
        key_slash->setStyleSheet(QLatin1String("#key_slash{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/slash_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_slash::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/slash_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_slash->setCheckable(false);
        key_plus = new QPushButton(key_frame);
        key_plus->setObjectName(QStringLiteral("key_plus"));
        key_plus->setGeometry(QRect(879, 134, 50, 50));
        key_plus->setFocusPolicy(Qt::NoFocus);
        key_plus->setStyleSheet(QLatin1String("#key_plus{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/+_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_plus::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/+_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_plus->setCheckable(false);
        key_minus = new QPushButton(key_frame);
        key_minus->setObjectName(QStringLiteral("key_minus"));
        key_minus->setGeometry(QRect(879, 72, 50, 50));
        key_minus->setFocusPolicy(Qt::NoFocus);
        key_minus->setStyleSheet(QLatin1String("#key_minus{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/- azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_minus::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/- blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_minus->setCheckable(false);
        key_X = new QPushButton(key_frame);
        key_X->setObjectName(QStringLiteral("key_X"));
        key_X->setGeometry(QRect(128, 134, 50, 50));
        key_X->setFocusPolicy(Qt::NoFocus);
        key_X->setStyleSheet(QLatin1String("#key_X{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/X_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_X::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/X_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_X->setCheckable(false);
        key_Z = new QPushButton(key_frame);
        key_Z->setObjectName(QStringLiteral("key_Z"));
        key_Z->setGeometry(QRect(68, 134, 50, 50));
        key_Z->setFocusPolicy(Qt::NoFocus);
        key_Z->setStyleSheet(QLatin1String("#key_Z{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/Z_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_Z::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/Z_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_Z->setCheckable(false);
        key_M = new QPushButton(key_frame);
        key_M->setObjectName(QStringLiteral("key_M"));
        key_M->setGeometry(QRect(428, 134, 50, 50));
        key_M->setFocusPolicy(Qt::NoFocus);
        key_M->setStyleSheet(QLatin1String("#key_M{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/M_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_M::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/M_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_M->setCheckable(false);
        key_C = new QPushButton(key_frame);
        key_C->setObjectName(QStringLiteral("key_C"));
        key_C->setGeometry(QRect(188, 134, 50, 50));
        key_C->setFocusPolicy(Qt::NoFocus);
        key_C->setStyleSheet(QLatin1String("#key_C{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/C_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_C::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/C_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_C->setCheckable(false);
        key_V = new QPushButton(key_frame);
        key_V->setObjectName(QStringLiteral("key_V"));
        key_V->setGeometry(QRect(248, 134, 50, 50));
        key_V->setFocusPolicy(Qt::NoFocus);
        key_V->setStyleSheet(QLatin1String("#key_V{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/V_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_V::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/V_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_V->setCheckable(false);
        key_B = new QPushButton(key_frame);
        key_B->setObjectName(QStringLiteral("key_B"));
        key_B->setGeometry(QRect(308, 134, 50, 50));
        key_B->setFocusPolicy(Qt::NoFocus);
        key_B->setStyleSheet(QLatin1String("#key_B{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/B_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_B::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/B_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_B->setCheckable(false);
        key_N = new QPushButton(key_frame);
        key_N->setObjectName(QStringLiteral("key_N"));
        key_N->setGeometry(QRect(368, 134, 50, 50));
        key_N->setFocusPolicy(Qt::NoFocus);
        key_N->setStyleSheet(QLatin1String("#key_N{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/N_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_N::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/N_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_N->setCheckable(false);
        key_comma = new QPushButton(key_frame);
        key_comma->setObjectName(QStringLiteral("key_comma"));
        key_comma->setGeometry(QRect(488, 134, 50, 50));
        key_comma->setFocusPolicy(Qt::NoFocus);
        key_comma->setStyleSheet(QLatin1String("#key_comma{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/coma_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_comma::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/coma_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_comma->setCheckable(false);
        key_space = new QPushButton(key_frame);
        key_space->setObjectName(QStringLiteral("key_space"));
        key_space->setGeometry(QRect(219, 190, 381, 50));
        key_space->setFocusPolicy(Qt::NoFocus);
        key_space->setStyleSheet(QLatin1String("#key_space{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/Espacio_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_space::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/Espacio_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_space->setCheckable(false);
        key_enter = new QPushButton(key_frame);
        key_enter->setObjectName(QStringLiteral("key_enter"));
        key_enter->setGeometry(QRect(585, 75, 91, 51));
        key_enter->setFocusPolicy(Qt::NoFocus);
        key_enter->setStyleSheet(QLatin1String("#key_enter{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/Enter_azul.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}\n"
"\n"
"#key_enter::pressed{ \n"
"border-image: url(:/teclado/images/Texto/Teclado/Enter_blanco.png);\n"
"border: none;\n"
"background-repeat: none;\n"
"background-position: center;\n"
"}"));
        key_enter->setCheckable(false);
        key_mayus = new QPushButton(key_frame);
        key_mayus->setObjectName(QStringLiteral("key_mayus"));
        key_mayus->setGeometry(QRect(96, 190, 111, 50));
        key_mayus->setFocusPolicy(Qt::NoFocus);
        key_mayus->setStyleSheet(QLatin1String("#key_mayus{ \n"
"background-color:none;\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: rgb(0, 167, 250);\n"
"color: rgb(0, 167, 250);\n"
"\n"
"}\n"
"\n"
"#key_mayus::checked{ \n"
"background-color:none;\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 8px;\n"
"border-color: white;\n"
"color: white;\n"
"}"));
        key_mayus->setCheckable(true);
        key_mayus->setChecked(false);
        key_back_6 = new QLabel(key_frame);
        key_back_6->setObjectName(QStringLiteral("key_back_6"));
        key_back_6->setGeometry(QRect(88, 188, 121, 61));
        key_back_6->setStyleSheet(QLatin1String("#key_back_6\n"
"{\n"
"background-color: balck;\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"}"));
        key_back_6->raise();
        key_0->raise();
        key_4->raise();
        key_5->raise();
        key_7->raise();
        key_8->raise();
        key_1->raise();
        key_6->raise();
        key_back->raise();
        key_3->raise();
        key_9->raise();
        key_2->raise();
        key_Q->raise();
        key_W->raise();
        key_E->raise();
        key_R->raise();
        key_T->raise();
        key_Y->raise();
        key_U->raise();
        key_I->raise();
        key_P->raise();
        key_O->raise();
        key_A->raise();
        key_L->raise();
        key_H->raise();
        key_G->raise();
        key_F->raise();
        key_S->raise();
        key_D->raise();
        key_J->raise();
        key_K->raise();
        key_dot->raise();
        key_slash->raise();
        key_plus->raise();
        key_minus->raise();
        key_X->raise();
        key_Z->raise();
        key_M->raise();
        key_C->raise();
        key_V->raise();
        key_B->raise();
        key_N->raise();
        key_comma->raise();
        key_space->raise();
        key_enter->raise();
        key_mayus->raise();
        textEdit = new QTextEdit(settings);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 60, 961, 311));

        retranslateUi(settings);
        QObject::connect(buttonBox, SIGNAL(accepted()), settings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), settings, SLOT(reject()));

        QMetaObject::connectSlotsByName(settings);
    } // setupUi

    void retranslateUi(QDialog *settings)
    {
        settings->setWindowTitle(QApplication::translate("settings", "Dialog", 0));
        label->setText(QApplication::translate("settings", "ADVERTENCIA: NO MODIFICAR ESTAS CONFIGURACIONES SIN CONOCIMIENTO DEL SISTEMA. RECUERDA REINICIAR EL PROGRAMA PARA APLICAR CAMBIOS", 0));
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
        key_mayus->setText(QApplication::translate("settings", "MAYUSCULAS", 0));
        key_back_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class settings: public Ui_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
