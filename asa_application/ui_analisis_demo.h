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
#include <QtWidgets/QDoubleSpinBox>
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
    QWidget *left_menu;
    QPushButton *graph_button;
    QPushButton *close_menu;
    QPushButton *show_menu;
    QWidget *datewidget;
    QDoubleSpinBox *control_A000;

    void setupUi(QDialog *analisis_demo)
    {
        if (analisis_demo->objectName().isEmpty())
            analisis_demo->setObjectName(QStringLiteral("analisis_demo"));
        analisis_demo->resize(800, 600);
        pushButton = new QPushButton(analisis_demo);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(730, 10, 51, 51));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QLatin1String("#pushButton\n"
"{\n"
"background-color: transparent;\n"
"background-image: url(:/demo/images/Demo/Home .png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"border: none;\n"
"}"));
        frame = new QFrame(analisis_demo);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(80, 90, 691, 431));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(frame);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(160, 10, 180, 200));
        widget_2 = new QWidget(frame);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(340, 10, 180, 200));
        widget_3 = new QWidget(frame);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(160, 225, 180, 200));
        widget_4 = new QWidget(frame);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(340, 225, 180, 200));
        aleta1 = new QWidget(frame);
        aleta1->setObjectName(QStringLiteral("aleta1"));
        aleta1->setGeometry(QRect(20, 56, 151, 91));
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
        aleta2->setGeometry(QRect(510, 56, 151, 91));
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
        aleta3->setGeometry(QRect(20, 270, 151, 91));
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
        aleta4->setGeometry(QRect(510, 270, 151, 91));
        aleta4->setStyleSheet(QLatin1String("#aleta4\n"
"{\n"
"background-color: transparent;\n"
"background-image: url(:/demo/images/Demo/Aleta-Dere.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"border: none;\n"
"}"));
        left_menu = new QWidget(analisis_demo);
        left_menu->setObjectName(QStringLiteral("left_menu"));
        left_menu->setGeometry(QRect(0, 0, 70, 600));
        left_menu->setStyleSheet(QLatin1String("#left_menu\n"
"{\n"
"background-color: rgb(19,19,50);\n"
"}"));
        graph_button = new QPushButton(left_menu);
        graph_button->setObjectName(QStringLiteral("graph_button"));
        graph_button->setGeometry(QRect(10, 80, 51, 41));
        graph_button->setFocusPolicy(Qt::NoFocus);
        graph_button->setStyleSheet(QLatin1String("#graph_button\n"
"{\n"
"background-color: transparent;\n"
"background-image: url(:/demo/images/Demo/Graph Menu.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"border: none;\n"
"}"));
        close_menu = new QPushButton(left_menu);
        close_menu->setObjectName(QStringLiteral("close_menu"));
        close_menu->setGeometry(QRect(10, 20, 51, 41));
        close_menu->setFocusPolicy(Qt::NoFocus);
        close_menu->setStyleSheet(QLatin1String("#close_menu\n"
"{\n"
"background-color: transparent;\n"
"background-image: url(:/demo/images/Demo/Close Menu.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"border: none;\n"
"}"));
        show_menu = new QPushButton(analisis_demo);
        show_menu->setObjectName(QStringLiteral("show_menu"));
        show_menu->setGeometry(QRect(10, 20, 51, 41));
        show_menu->setFocusPolicy(Qt::NoFocus);
        show_menu->setStyleSheet(QLatin1String("#show_menu\n"
"{\n"
"background-color: transparent;\n"
"background-image: url(:/demo/images/Demo/Menu.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"border: none;\n"
"}"));
        datewidget = new QWidget(analisis_demo);
        datewidget->setObjectName(QStringLiteral("datewidget"));
        datewidget->setGeometry(QRect(310, 5, 180, 50));
        control_A000 = new QDoubleSpinBox(analisis_demo);
        control_A000->setObjectName(QStringLiteral("control_A000"));
        control_A000->setGeometry(QRect(150, 10, 81, 71));
        control_A000->setAccelerated(true);
        control_A000->setDecimals(0);
        control_A000->setMinimum(0);
        control_A000->setMaximum(1e+10);
        control_A000->setSingleStep(1);
        show_menu->raise();
        frame->raise();
        left_menu->raise();
        pushButton->raise();
        datewidget->raise();
        control_A000->raise();

        retranslateUi(analisis_demo);

        QMetaObject::connectSlotsByName(analisis_demo);
    } // setupUi

    void retranslateUi(QDialog *analisis_demo)
    {
        analisis_demo->setWindowTitle(QApplication::translate("analisis_demo", "Dialog", Q_NULLPTR));
        pushButton->setText(QString());
        graph_button->setText(QString());
        close_menu->setText(QString());
        show_menu->setText(QString());
        control_A000->setPrefix(QString());
        control_A000->setSuffix(QString());
    } // retranslateUi

};

namespace Ui {
    class analisis_demo: public Ui_analisis_demo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALISIS_DEMO_H
