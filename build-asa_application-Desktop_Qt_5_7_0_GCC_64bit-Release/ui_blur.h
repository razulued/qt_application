/********************************************************************************
** Form generated from reading UI file 'blur.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLUR_H
#define UI_BLUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_blur
{
public:

    void setupUi(QDialog *blur)
    {
        if (blur->objectName().isEmpty())
            blur->setObjectName(QStringLiteral("blur"));
        blur->resize(400, 300);

        retranslateUi(blur);

        QMetaObject::connectSlotsByName(blur);
    } // setupUi

    void retranslateUi(QDialog *blur)
    {
        blur->setWindowTitle(QApplication::translate("blur", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class blur: public Ui_blur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUR_H
