/********************************************************************************
** Form generated from reading UI file 'detailedwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILEDWINDOW_H
#define UI_DETAILEDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>

QT_BEGIN_NAMESPACE

class Ui_detailedwindow
{
public:
    QLabel *nombre;
    QLabel *imagen;
    QLabel *label;
    QListView *listView;

    void setupUi(QDialog *detailedwindow)
    {
        if (detailedwindow->objectName().isEmpty())
            detailedwindow->setObjectName(QStringLiteral("detailedwindow"));
        detailedwindow->resize(400, 300);
        nombre = new QLabel(detailedwindow);
        nombre->setObjectName(QStringLiteral("nombre"));
        nombre->setGeometry(QRect(10, 20, 161, 17));
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        nombre->setFont(font);
        imagen = new QLabel(detailedwindow);
        imagen->setObjectName(QStringLiteral("imagen"));
        imagen->setGeometry(QRect(10, 60, 181, 181));
        imagen->setStyleSheet(QStringLiteral(""));
        label = new QLabel(detailedwindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 20, 91, 17));
        label->setFont(font);
        listView = new QListView(detailedwindow);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(210, 50, 171, 181));

        retranslateUi(detailedwindow);

        QMetaObject::connectSlotsByName(detailedwindow);
    } // setupUi

    void retranslateUi(QDialog *detailedwindow)
    {
        detailedwindow->setWindowTitle(QApplication::translate("detailedwindow", "Dialog", 0));
        nombre->setText(QApplication::translate("detailedwindow", "Nombre de Elemento", 0));
        imagen->setText(QString());
        label->setText(QApplication::translate("detailedwindow", "Par\303\241metros", 0));
    } // retranslateUi

};

namespace Ui {
    class detailedwindow: public Ui_detailedwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILEDWINDOW_H
