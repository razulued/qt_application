/********************************************************************************
** Form generated from reading UI file 'stop_button.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOP_BUTTON_H
#define UI_STOP_BUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_stop_button
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *stop_button)
    {
        if (stop_button->objectName().isEmpty())
            stop_button->setObjectName(QStringLiteral("stop_button"));
        stop_button->resize(50, 50);
        pushButton = new QPushButton(stop_button);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 50, 50));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QLatin1String("#pushButton\n"
"{\n"
"background-color:transparent;\n"
"border-image: url(:/iconos/screen800x600/iconos/BOTON.png);\n"
"background-position: center;\n"
"background-repeat:none;\n"
"}\n"
"#pushButton::pressed\n"
"{\n"
"background-color:transparent;\n"
"border-image: url(:/iconos/screen800x600/iconos/BOTON 2.png);\n"
"background-position: center;\n"
"background-repeat:none;\n"
"}\n"
"#pushButton::checked\n"
"{\n"
"background-color:transparent;\n"
"border-image: url(:/iconos/screen800x600/iconos/BOTON 2.png);\n"
"background-position: center;\n"
"background-repeat:none;\n"
"}"));
        pushButton->setCheckable(true);
        pushButton->setChecked(false);

        retranslateUi(stop_button);

        QMetaObject::connectSlotsByName(stop_button);
    } // setupUi

    void retranslateUi(QDialog *stop_button)
    {
        stop_button->setWindowTitle(QApplication::translate("stop_button", "Dialog", Q_NULLPTR));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class stop_button: public Ui_stop_button {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOP_BUTTON_H
