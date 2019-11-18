/********************************************************************************
** Form generated from reading UI file 'screen_saver.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREEN_SAVER_H
#define UI_SCREEN_SAVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_screen_saver
{
public:
    QLabel *label_hour;
    QLabel *label_day;
    QLabel *notification;
    QLabel *background;
    QLabel *bell;
    QLabel *label_month;
    QLabel *label_am_pm;
    QLabel *label_seconds;

    void setupUi(QDialog *screen_saver)
    {
        if (screen_saver->objectName().isEmpty())
            screen_saver->setObjectName(QStringLiteral("screen_saver"));
        screen_saver->resize(800, 600);
        screen_saver->setStyleSheet(QLatin1String("#screen_saver\n"
"{\n"
"background-color: transparent;\n"
"}"));
        label_hour = new QLabel(screen_saver);
        label_hour->setObjectName(QStringLiteral("label_hour"));
        label_hour->setGeometry(QRect(141, 529, 131, 51));
        QFont font;
        font.setPointSize(36);
        label_hour->setFont(font);
        label_hour->setStyleSheet(QLatin1String("#label_hour\n"
"{\n"
"color: rgb(0, 167, 250);\n"
"}"));
        label_hour->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_day = new QLabel(screen_saver);
        label_day->setObjectName(QStringLiteral("label_day"));
        label_day->setGeometry(QRect(20, 490, 121, 101));
        QFont font1;
        font1.setPointSize(72);
        label_day->setFont(font1);
        label_day->setStyleSheet(QLatin1String("#label_day\n"
"{\n"
"color: rgb(17, 110, 141);\n"
"}"));
        label_day->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        notification = new QLabel(screen_saver);
        notification->setObjectName(QStringLiteral("notification"));
        notification->setGeometry(QRect(684, 33, 51, 41));
        QFont font2;
        font2.setPointSize(14);
        notification->setFont(font2);
        notification->setStyleSheet(QLatin1String("#notification\n"
"{\n"
"color: black;\n"
"border: none;\n"
"background-color:transparent;\n"
"}"));
        notification->setAlignment(Qt::AlignCenter);
        background = new QLabel(screen_saver);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(0, 0, 800, 600));
        background->setStyleSheet(QLatin1String("#background\n"
"{\n"
"background-image: url(:/iconos/screen800x600/gifs/PTAR-VAB.gif);\n"
"background-position: center;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        bell = new QLabel(screen_saver);
        bell->setObjectName(QStringLiteral("bell"));
        bell->setGeometry(QRect(670, 10, 111, 111));
        bell->setStyleSheet(QLatin1String("#bell\n"
"{\n"
"/*background-image: url(:/iconos/screen800x600/gifs/OK.gif);*/\n"
"background-image: url(:/iconos/screen800x600/iconos/Bell_2.png);\n"
"background-position: left;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        label_month = new QLabel(screen_saver);
        label_month->setObjectName(QStringLiteral("label_month"));
        label_month->setGeometry(QRect(141, 490, 251, 51));
        QFont font3;
        font3.setPointSize(26);
        label_month->setFont(font3);
        label_month->setStyleSheet(QLatin1String("#label_month\n"
"{\n"
"color: rgb(0, 167, 250);\n"
"}"));
        label_month->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_am_pm = new QLabel(screen_saver);
        label_am_pm->setObjectName(QStringLiteral("label_am_pm"));
        label_am_pm->setGeometry(QRect(275, 533, 41, 21));
        QFont font4;
        font4.setPointSize(12);
        label_am_pm->setFont(font4);
        label_am_pm->setStyleSheet(QLatin1String("#label_am_pm\n"
"{\n"
"color: rgb(17, 110, 141);\n"
"}"));
        label_am_pm->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_seconds = new QLabel(screen_saver);
        label_seconds->setObjectName(QStringLiteral("label_seconds"));
        label_seconds->setGeometry(QRect(273, 551, 41, 21));
        QFont font5;
        font5.setPointSize(18);
        label_seconds->setFont(font5);
        label_seconds->setStyleSheet(QLatin1String("#label_seconds\n"
"{\n"
"color: rgb(17, 110, 141);\n"
"}"));
        label_seconds->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        background->raise();
        label_am_pm->raise();
        label_seconds->raise();
        label_hour->raise();
        label_day->raise();
        bell->raise();
        label_month->raise();
        notification->raise();

        retranslateUi(screen_saver);

        QMetaObject::connectSlotsByName(screen_saver);
    } // setupUi

    void retranslateUi(QDialog *screen_saver)
    {
        screen_saver->setWindowTitle(QApplication::translate("screen_saver", "Dialog", Q_NULLPTR));
        label_hour->setText(QApplication::translate("screen_saver", "11:45", Q_NULLPTR));
        label_day->setText(QApplication::translate("screen_saver", "25", Q_NULLPTR));
        notification->setText(QApplication::translate("screen_saver", "13", Q_NULLPTR));
        background->setText(QString());
        bell->setText(QString());
        label_month->setText(QApplication::translate("screen_saver", "Noviembre", Q_NULLPTR));
        label_am_pm->setText(QApplication::translate("screen_saver", "PM", Q_NULLPTR));
        label_seconds->setText(QApplication::translate("screen_saver", "32", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class screen_saver: public Ui_screen_saver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREEN_SAVER_H
