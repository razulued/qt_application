/********************************************************************************
** Form generated from reading UI file 'record_chart.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORD_CHART_H
#define UI_RECORD_CHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_record_chart
{
public:
    QFrame *frame;
    QLabel *label;
    QPushButton *close;
    QChartView *graphicsView;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *filtro_fecha;
    QLabel *label_7;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;

    void setupUi(QDialog *record_chart)
    {
        if (record_chart->objectName().isEmpty())
            record_chart->setObjectName(QStringLiteral("record_chart"));
        record_chart->resize(800, 600);
        frame = new QFrame(record_chart);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(60, 100, 681, 461));
        frame->setStyleSheet(QLatin1String("#frame{\n"
"background-image: none;\n"
"background-color: black;\n"
"border-style: solid;\n"
"border-color: rgb(0, 167, 250);\n"
"border-width: 3px;\n"
"border-radius: 15px;\n"
"background-repeat: none;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 631, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("#label\n"
"{\n"
"color: white;\n"
"}"));
        label->setAlignment(Qt::AlignCenter);
        close = new QPushButton(frame);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(480, 10, 41, 31));
        close->setFocusPolicy(Qt::NoFocus);
        close->setStyleSheet(QLatin1String("#close\n"
"{\n"
"background-color: transparent;\n"
"border: none;\n"
"}"));
        graphicsView = new QChartView(frame);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(20, 50, 641, 301));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 360, 71, 16));
        label_2->setStyleSheet(QLatin1String("#label_2\n"
"{\n"
"color: white;\n"
"}"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 380, 201, 16));
        label_3->setStyleSheet(QLatin1String("#label_3\n"
"{\n"
"color: white;\n"
"}"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 400, 71, 16));
        label_4->setStyleSheet(QLatin1String("#label_4\n"
"{\n"
"color: white;\n"
"}"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 420, 201, 16));
        label_5->setStyleSheet(QLatin1String("#label_5\n"
"{\n"
"color: white;\n"
"}"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(310, 410, 151, 21));
        label_6->setStyleSheet(QLatin1String("#label_6\n"
"{\n"
"color: white;\n"
"}"));
        filtro_fecha = new QPushButton(frame);
        filtro_fecha->setObjectName(QStringLiteral("filtro_fecha"));
        filtro_fecha->setGeometry(QRect(265, 402, 41, 41));
        filtro_fecha->setFocusPolicy(Qt::NoFocus);
        filtro_fecha->setStyleSheet(QLatin1String("#filtro_fecha\n"
"{\n"
"background-image: url(:/iconos/screen800x600/iconos/Calendario.png);\n"
"background-position: center;\n"
"background-repeat: none;\n"
"border:none;\n"
"}"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(240, 360, 201, 21));
        label_7->setStyleSheet(QLatin1String("#label_7\n"
"{\n"
"color: yellow;\n"
"}"));
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(480, 380, 181, 64));
        groupBox->setStyleSheet(QLatin1String("QRadioButton\n"
"{\n"
"color: white;\n"
"}"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);


        retranslateUi(record_chart);

        QMetaObject::connectSlotsByName(record_chart);
    } // setupUi

    void retranslateUi(QDialog *record_chart)
    {
        record_chart->setWindowTitle(QApplication::translate("record_chart", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("record_chart", "Gr\303\241fico", Q_NULLPTR));
        close->setText(QString());
        label_2->setText(QApplication::translate("record_chart", "Desde", Q_NULLPTR));
        label_3->setText(QApplication::translate("record_chart", "dd/mm/aaaa", Q_NULLPTR));
        label_4->setText(QApplication::translate("record_chart", "Hasta", Q_NULLPTR));
        label_5->setText(QApplication::translate("record_chart", "dd/mm/aaaa", Q_NULLPTR));
        label_6->setText(QApplication::translate("record_chart", "Cambiar fechas", Q_NULLPTR));
        filtro_fecha->setText(QString());
        label_7->setText(QString());
        groupBox->setTitle(QString());
        radioButton->setText(QApplication::translate("record_chart", "Mostrar por d\303\255a", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("record_chart", "Mostrar por mes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class record_chart: public Ui_record_chart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORD_CHART_H
