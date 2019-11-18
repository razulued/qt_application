/********************************************************************************
** Form generated from reading UI file 'contacto.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTO_H
#define UI_CONTACTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_contacto
{
public:
    QFrame *frame;
    QLabel *label;
    QLabel *qr;
    QLabel *hgm;
    QTextEdit *textEdit;
    QPushButton *close;
    QPushButton *top_menu_5;
    QPushButton *push_cancelar;
    QPushButton *push_cancelar_2;
    QPushButton *push_cancelar_3;
    QPushButton *push_cancelar_4;

    void setupUi(QDialog *contacto)
    {
        if (contacto->objectName().isEmpty())
            contacto->setObjectName(QStringLiteral("contacto"));
        contacto->resize(800, 600);
        frame = new QFrame(contacto);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(150, 70, 521, 261));
        frame->setStyleSheet(QLatin1String("#frame{\n"
"background-image: url(:/iconos/screen800x600/iconos/Cuadro pantalla.png);\n"
"background-repeat: none;\n"
"border: none;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, -3, 211, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        qr = new QLabel(frame);
        qr->setObjectName(QStringLiteral("qr"));
        qr->setGeometry(QRect(15, 30, 210, 210));
        qr->setStyleSheet(QLatin1String("#qr\n"
"{\n"
"border-image: url(:/iconos/screen800x600/iconos/QR HGM.png);\n"
"border: none;\n"
"}"));
        hgm = new QLabel(frame);
        hgm->setObjectName(QStringLiteral("hgm"));
        hgm->setGeometry(QRect(244, 30, 261, 41));
        QFont font1;
        font1.setPointSize(12);
        hgm->setFont(font1);
        hgm->setStyleSheet(QLatin1String("#hgm\n"
"{\n"
"border: none;\n"
"color: white;\n"
"}"));
        textEdit = new QTextEdit(frame);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(false);
        textEdit->setGeometry(QRect(240, 69, 271, 131));
        textEdit->setStyleSheet(QLatin1String("#textEdit\n"
"{\n"
"background-color:transparent;\n"
"border:none;\n"
"}"));
        close = new QPushButton(frame);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(480, 10, 41, 31));
        close->setFocusPolicy(Qt::NoFocus);
        close->setStyleSheet(QLatin1String("#close\n"
"{\n"
"background-color: transparent;\n"
"border: none;\n"
"}"));
        top_menu_5 = new QPushButton(frame);
        top_menu_5->setObjectName(QStringLiteral("top_menu_5"));
        top_menu_5->setGeometry(QRect(470, 210, 34, 41));
        top_menu_5->setCursor(QCursor(Qt::ArrowCursor));
        top_menu_5->setFocusPolicy(Qt::NoFocus);
        top_menu_5->setStyleSheet(QLatin1String("#top_menu_5 { \n"
"background-color: transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/Ajustes azul.png);\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_5->setCheckable(true);
        push_cancelar = new QPushButton(contacto);
        push_cancelar->setObjectName(QStringLiteral("push_cancelar"));
        push_cancelar->setGeometry(QRect(0, 0, 71, 61));
        push_cancelar->setFocusPolicy(Qt::NoFocus);
        push_cancelar->setStyleSheet(QLatin1String("#push_cancelar\n"
"{\n"
"background-color: transparent;\n"
"border: none;\n"
"}"));
        push_cancelar_2 = new QPushButton(contacto);
        push_cancelar_2->setObjectName(QStringLiteral("push_cancelar_2"));
        push_cancelar_2->setGeometry(QRect(0, 540, 71, 61));
        push_cancelar_2->setFocusPolicy(Qt::NoFocus);
        push_cancelar_2->setStyleSheet(QLatin1String("#push_cancelar_2\n"
"{\n"
"background-color: transparent;\n"
"border: none;\n"
"}"));
        push_cancelar_3 = new QPushButton(contacto);
        push_cancelar_3->setObjectName(QStringLiteral("push_cancelar_3"));
        push_cancelar_3->setGeometry(QRect(730, 540, 71, 61));
        push_cancelar_3->setFocusPolicy(Qt::NoFocus);
        push_cancelar_3->setStyleSheet(QLatin1String("#push_cancelar_3\n"
"{\n"
"background-color: transparent;\n"
"border: none;\n"
"}"));
        push_cancelar_4 = new QPushButton(contacto);
        push_cancelar_4->setObjectName(QStringLiteral("push_cancelar_4"));
        push_cancelar_4->setGeometry(QRect(730, 0, 71, 61));
        push_cancelar_4->setFocusPolicy(Qt::NoFocus);
        push_cancelar_4->setStyleSheet(QLatin1String("#push_cancelar_4\n"
"{\n"
"background-color: transparent;\n"
"border: none;\n"
"}"));

        retranslateUi(contacto);

        QMetaObject::connectSlotsByName(contacto);
    } // setupUi

    void retranslateUi(QDialog *contacto)
    {
        contacto->setWindowTitle(QApplication::translate("contacto", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("contacto", "Contacto", Q_NULLPTR));
        qr->setText(QString());
        hgm->setText(QApplication::translate("contacto", "HGM Technology", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("contacto", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">HGM TECHNOLOGY, S.A. DE C.V.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">CHIMALPOPOCA #4392-A</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">COL. EL ZAPOTE, ZAPOPAN, JALISCO.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">RFC: HTE 110512 MG7</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0p"
                        "x; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">CP. 45050 TEL/FAX: 01(33) 3121-394 / 1484-3932</p></body></html>", Q_NULLPTR));
        close->setText(QString());
        top_menu_5->setText(QString());
        push_cancelar->setText(QString());
        push_cancelar_2->setText(QString());
        push_cancelar_3->setText(QString());
        push_cancelar_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class contacto: public Ui_contacto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTO_H
