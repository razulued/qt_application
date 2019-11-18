/********************************************************************************
** Form generated from reading UI file 'donut_chart.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DONUT_CHART_H
#define UI_DONUT_CHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_donut_chart
{
public:
    QLabel *valuelabel;
    QChartView *graphicsView;
    QLabel *namelabel;

    void setupUi(QWidget *donut_chart)
    {
        if (donut_chart->objectName().isEmpty())
            donut_chart->setObjectName(QStringLiteral("donut_chart"));
        donut_chart->resize(180, 200);
        donut_chart->setStyleSheet(QStringLiteral(""));
        valuelabel = new QLabel(donut_chart);
        valuelabel->setObjectName(QStringLiteral("valuelabel"));
        valuelabel->setGeometry(QRect(10, 40, 151, 50));
        QFont font;
        font.setPointSize(26);
        valuelabel->setFont(font);
        valuelabel->setAlignment(Qt::AlignCenter);
        graphicsView = new QChartView(donut_chart);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(20, 20, 100, 100));
        namelabel = new QLabel(donut_chart);
        namelabel->setObjectName(QStringLiteral("namelabel"));
        namelabel->setGeometry(QRect(10, 139, 151, 41));
        QFont font1;
        font1.setPointSize(10);
        namelabel->setFont(font1);
        namelabel->setAlignment(Qt::AlignCenter);
        graphicsView->raise();
        valuelabel->raise();
        namelabel->raise();

        retranslateUi(donut_chart);

        QMetaObject::connectSlotsByName(donut_chart);
    } // setupUi

    void retranslateUi(QWidget *donut_chart)
    {
        donut_chart->setWindowTitle(QApplication::translate("donut_chart", "Form", Q_NULLPTR));
        valuelabel->setText(QApplication::translate("donut_chart", "100", Q_NULLPTR));
        namelabel->setText(QApplication::translate("donut_chart", "Name", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class donut_chart: public Ui_donut_chart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DONUT_CHART_H
