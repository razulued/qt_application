/********************************************************************************
** Form generated from reading UI file 'date_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATE_WIDGET_H
#define UI_DATE_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_date_widget
{
public:
    QLabel *label_hour;
    QLabel *label_ampm;
    QFrame *line;
    QLabel *label_day;
    QLabel *label_month;
    QLabel *label_year;

    void setupUi(QWidget *date_widget)
    {
        if (date_widget->objectName().isEmpty())
            date_widget->setObjectName(QStringLiteral("date_widget"));
        date_widget->resize(180, 50);
        label_hour = new QLabel(date_widget);
        label_hour->setObjectName(QStringLiteral("label_hour"));
        label_hour->setGeometry(QRect(-7, 10, 81, 31));
        QFont font;
        font.setPointSize(20);
        label_hour->setFont(font);
        label_hour->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_ampm = new QLabel(date_widget);
        label_ampm->setObjectName(QStringLiteral("label_ampm"));
        label_ampm->setGeometry(QRect(75, 11, 21, 16));
        line = new QFrame(date_widget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(83, 10, 20, 31));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_day = new QLabel(date_widget);
        label_day->setObjectName(QStringLiteral("label_day"));
        label_day->setGeometry(QRect(103, 10, 41, 31));
        label_day->setFont(font);
        label_day->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_month = new QLabel(date_widget);
        label_month->setObjectName(QStringLiteral("label_month"));
        label_month->setGeometry(QRect(145, 11, 31, 16));
        label_year = new QLabel(date_widget);
        label_year->setObjectName(QStringLiteral("label_year"));
        label_year->setGeometry(QRect(145, 25, 31, 13));
        line->raise();
        label_hour->raise();
        label_ampm->raise();
        label_day->raise();
        label_month->raise();
        label_year->raise();

        retranslateUi(date_widget);

        QMetaObject::connectSlotsByName(date_widget);
    } // setupUi

    void retranslateUi(QWidget *date_widget)
    {
        date_widget->setWindowTitle(QApplication::translate("date_widget", "Form", Q_NULLPTR));
        label_hour->setText(QApplication::translate("date_widget", "22:36", Q_NULLPTR));
        label_ampm->setText(QApplication::translate("date_widget", "PM", Q_NULLPTR));
        label_day->setText(QApplication::translate("date_widget", "30", Q_NULLPTR));
        label_month->setText(QApplication::translate("date_widget", "SEP", Q_NULLPTR));
        label_year->setText(QApplication::translate("date_widget", "2019", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class date_widget: public Ui_date_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATE_WIDGET_H
