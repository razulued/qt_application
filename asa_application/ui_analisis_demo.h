/********************************************************************************
** Form generated from reading UI file 'analisis_demo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALISIS_DEMO_H
#define UI_ANALISIS_DEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_analisis_demo
{
public:
    QPushButton *pushButton;
    QFrame *frame;
    QWidget *widget;
    QWidget *widget_2;
    QWidget *widget_3;
    QWidget *widget_4;
    QWidget *aleta1;
    QWidget *aleta2;
    QWidget *aleta3;
    QWidget *aleta4;

    void setupUi(QDialog *analisis_demo)
    {
        if (analisis_demo->objectName().isEmpty())
            analisis_demo->setObjectName(QStringLiteral("analisis_demo"));
        analisis_demo->resize(800, 600);
        pushButton = new QPushButton(analisis_demo);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 20, 75, 51));
        frame = new QFrame(analisis_demo);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(80, 90, 691, 391));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(frame);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(170, 10, 180, 180));
        widget_2 = new QWidget(frame);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(350, 10, 180, 180));
        widget_3 = new QWidget(frame);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(170, 190, 180, 180));
        widget_4 = new QWidget(frame);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(350, 190, 180, 180));
        aleta1 = new QWidget(frame);
        aleta1->setObjectName(QStringLiteral("aleta1"));
        aleta1->setGeometry(QRect(30, 56, 151, 91));
        aleta1->setStyleSheet(QLatin1String("#aleta1\n"
"{\n"
"background-color: transparent;\n"
"background-image: url(:/demo/images/Demo/Aleta-izq.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"border: none;\n"
"}"));
        aleta2 = new QWidget(frame);
        aleta2->setObjectName(QStringLiteral("aleta2"));
        aleta2->setGeometry(QRect(520, 56, 151, 91));
        aleta2->setStyleSheet(QLatin1String("#aleta2\n"
"{\n"
"background-color: transparent;\n"
"background-image: url(:/demo/images/Demo/Aleta-Dere.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"border: none;\n"
"}"));
        aleta3 = new QWidget(frame);
        aleta3->setObjectName(QStringLiteral("aleta3"));
        aleta3->setGeometry(QRect(30, 236, 151, 91));
        aleta3->setStyleSheet(QLatin1String("#aleta3\n"
"{\n"
"background-color: transparent;\n"
"background-image: url(:/demo/images/Demo/Aleta-izq.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"border: none;\n"
"}"));
        aleta4 = new QWidget(frame);
        aleta4->setObjectName(QStringLiteral("aleta4"));
        aleta4->setGeometry(QRect(520, 236, 151, 91));
        aleta4->setStyleSheet(QLatin1String("#aleta4\n"
"{\n"
"background-color: transparent;\n"
"background-image: url(:/demo/images/Demo/Aleta-Dere.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"border: none;\n"
"}"));

        retranslateUi(analisis_demo);

        QMetaObject::connectSlotsByName(analisis_demo);
    } // setupUi

    void retranslateUi(QDialog *analisis_demo)
    {
        analisis_demo->setWindowTitle(QApplication::translate("analisis_demo", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("analisis_demo", "GO BACK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class analisis_demo: public Ui_analisis_demo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALISIS_DEMO_H
