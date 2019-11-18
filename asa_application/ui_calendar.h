/********************************************************************************
** Form generated from reading UI file 'calendar.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDAR_H
#define UI_CALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_calendar
{
public:
    QFrame *frame;
    QListWidget *listWidget;
    QCalendarWidget *calendarWidget;
    QPushButton *push_aceptar;
    QPushButton *push_cancelar;
    QLabel *label;
    QPushButton *closeButton;

    void setupUi(QDialog *calendar)
    {
        if (calendar->objectName().isEmpty())
            calendar->setObjectName(QStringLiteral("calendar"));
        calendar->resize(800, 600);
        frame = new QFrame(calendar);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(150, 70, 521, 261));
        frame->setStyleSheet(QLatin1String("#frame{\n"
"background-image: url(:/iconos/screen800x600/iconos/Cuadro pantalla.png);\n"
"background-repeat: none;\n"
"border: none;\n"
"background-color:transparent;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        listWidget = new QListWidget(frame);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(30, 30, 101, 191));
        calendarWidget = new QCalendarWidget(frame);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(140, 30, 331, 191));
        push_aceptar = new QPushButton(frame);
        push_aceptar->setObjectName(QStringLiteral("push_aceptar"));
        push_aceptar->setGeometry(QRect(390, 224, 80, 22));
        push_cancelar = new QPushButton(frame);
        push_cancelar->setObjectName(QStringLiteral("push_cancelar"));
        push_cancelar->setGeometry(QRect(270, 224, 80, 22));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, -3, 211, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        closeButton = new QPushButton(frame);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(480, 0, 41, 41));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        closeButton->setFont(font1);
        closeButton->setFocusPolicy(Qt::NoFocus);
        closeButton->setStyleSheet(QLatin1String("#closeButton { \n"
"background-color: transparent;\n"
"/*border-image: url(:/iconos/images/Iconos/close-x.png);*/\n"
"background: none; \n"
"border: none; \n"
"background-repeat: none;\n"
"margin:5px;\n"
" } \n"
""));
        closeButton->setCheckable(false);
        closeButton->setAutoDefault(false);
        closeButton->setFlat(false);

        retranslateUi(calendar);

        QMetaObject::connectSlotsByName(calendar);
    } // setupUi

    void retranslateUi(QDialog *calendar)
    {
        calendar->setWindowTitle(QApplication::translate("calendar", "Dialog", Q_NULLPTR));
        push_aceptar->setText(QApplication::translate("calendar", "Aceptar", Q_NULLPTR));
        push_cancelar->setText(QApplication::translate("calendar", "Cancelar", Q_NULLPTR));
        label->setText(QApplication::translate("calendar", "Calendario", Q_NULLPTR));
        closeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class calendar: public Ui_calendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDAR_H
