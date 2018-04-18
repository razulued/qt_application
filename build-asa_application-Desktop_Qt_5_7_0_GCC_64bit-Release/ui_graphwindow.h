/********************************************************************************
** Form generated from reading UI file 'graphwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHWINDOW_H
#define UI_GRAPHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_graphwindow
{
public:
    QGraphicsView *graphicsView;
    QPushButton *top_menu_3;
    QPushButton *top_menu_1;
    QLabel *top_bar;
    QPushButton *top_menu_5;
    QPushButton *top_menu_2;

    void setupUi(QDialog *graphwindow)
    {
        if (graphwindow->objectName().isEmpty())
            graphwindow->setObjectName(QStringLiteral("graphwindow"));
        graphwindow->resize(800, 600);
        graphicsView = new QGraphicsView(graphwindow);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(30, 220, 521, 271));
        top_menu_3 = new QPushButton(graphwindow);
        top_menu_3->setObjectName(QStringLiteral("top_menu_3"));
        top_menu_3->setGeometry(QRect(100, 2, 41, 41));
        top_menu_3->setFocusPolicy(Qt::NoFocus);
        top_menu_3->setStyleSheet(QLatin1String("#top_menu_3 { \n"
"background-color: transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/Diagrama.png);\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_3->setCheckable(true);
        top_menu_1 = new QPushButton(graphwindow);
        top_menu_1->setObjectName(QStringLiteral("top_menu_1"));
        top_menu_1->setGeometry(QRect(10, 0, 31, 41));
        top_menu_1->setFocusPolicy(Qt::NoFocus);
        top_menu_1->setStyleSheet(QLatin1String("#top_menu_1 { \n"
"background-color: transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/Campana.png);\n"
"border: none; \n"
"background-repeat: none;\n"
"background-position: center;\n"
"\n"
" } "));
        top_menu_1->setCheckable(true);
        top_bar = new QLabel(graphwindow);
        top_bar->setObjectName(QStringLiteral("top_bar"));
        top_bar->setGeometry(QRect(0, 0, 759, 27));
        top_bar->setAutoFillBackground(false);
        top_bar->setStyleSheet(QLatin1String("#top_bar { \n"
"background-color: transparent;\n"
"background-image: url(:/barras/screen800x600/barras/PE_bar.png);\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_5 = new QPushButton(graphwindow);
        top_menu_5->setObjectName(QStringLiteral("top_menu_5"));
        top_menu_5->setGeometry(QRect(148, 0, 34, 41));
        top_menu_5->setFocusPolicy(Qt::NoFocus);
        top_menu_5->setStyleSheet(QLatin1String("#top_menu_5 { \n"
"background-color: transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/Ajustes azul.png);\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_5->setCheckable(true);
        top_menu_2 = new QPushButton(graphwindow);
        top_menu_2->setObjectName(QStringLiteral("top_menu_2"));
        top_menu_2->setGeometry(QRect(50, 0, 41, 41));
        top_menu_2->setFocusPolicy(Qt::NoFocus);
        top_menu_2->setStyleSheet(QLatin1String("#top_menu_2 { \n"
"background-color: transparent;\n"
"background-image: url(:/iconos/screen800x600/iconos/Bitacora azul.png);\n"
"background-position: center;\n"
"border: none; \n"
"background-repeat: none;\n"
" } "));
        top_menu_2->setCheckable(true);
        top_bar->raise();
        graphicsView->raise();
        top_menu_3->raise();
        top_menu_1->raise();
        top_menu_5->raise();
        top_menu_2->raise();

        retranslateUi(graphwindow);

        QMetaObject::connectSlotsByName(graphwindow);
    } // setupUi

    void retranslateUi(QDialog *graphwindow)
    {
        graphwindow->setWindowTitle(QApplication::translate("graphwindow", "Dialog", 0));
        top_menu_3->setText(QString());
        top_menu_1->setText(QString());
        top_bar->setText(QString());
        top_menu_5->setText(QString());
        top_menu_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class graphwindow: public Ui_graphwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHWINDOW_H
