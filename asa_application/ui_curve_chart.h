/********************************************************************************
** Form generated from reading UI file 'curve_chart.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVE_CHART_H
#define UI_CURVE_CHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_curve_chart
{
public:
    QChartView *graphicsView;

    void setupUi(QWidget *curve_chart)
    {
        if (curve_chart->objectName().isEmpty())
            curve_chart->setObjectName(QStringLiteral("curve_chart"));
        curve_chart->resize(400, 300);
        graphicsView = new QChartView(curve_chart);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 401, 301));

        retranslateUi(curve_chart);

        QMetaObject::connectSlotsByName(curve_chart);
    } // setupUi

    void retranslateUi(QWidget *curve_chart)
    {
        curve_chart->setWindowTitle(QApplication::translate("curve_chart", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class curve_chart: public Ui_curve_chart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVE_CHART_H
