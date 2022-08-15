/********************************************************************************
** Form generated from reading UI file 'earm_update.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EARM_UPDATE_H
#define UI_EARM_UPDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_earm_update
{
public:
    QProgressBar *progressBar;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *earm_update)
    {
        if (earm_update->objectName().isEmpty())
            earm_update->setObjectName(QStringLiteral("earm_update"));
        earm_update->resize(800, 600);
        earm_update->setStyleSheet(QStringLiteral(""));
        progressBar = new QProgressBar(earm_update);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(290, 280, 221, 51));
        progressBar->setStyleSheet(QLatin1String("#progressBar\n"
"{\n"
"color: green;\n"
"}"));
        progressBar->setValue(0);
        label = new QLabel(earm_update);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 205, 391, 71));
        label->setStyleSheet(QLatin1String("#label\n"
"{\n"
"color:white;\n"
"font-size: 30px;\n"
"}"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(earm_update);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(400, 530, 181, 20));
        label_2->setStyleSheet(QLatin1String("#label_2\n"
"{\n"
"color:white;\n"
"font-size: 15px;\n"
"}"));
        label_3 = new QLabel(earm_update);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(400, 560, 351, 20));
        label_3->setStyleSheet(QLatin1String("#label_3\n"
"{\n"
"color:white;\n"
"font-size: 15px;\n"
"}"));
        label_4 = new QLabel(earm_update);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(140, 350, 511, 71));
        label_4->setStyleSheet(QLatin1String("#label_4\n"
"{\n"
"color:red;\n"
"font-size: 30px;\n"
"}"));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(earm_update);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(400, 500, 181, 20));
        label_5->setStyleSheet(QLatin1String("#label_5\n"
"{\n"
"color:white;\n"
"font-size: 15px;\n"
"}"));

        retranslateUi(earm_update);

        QMetaObject::connectSlotsByName(earm_update);
    } // setupUi

    void retranslateUi(QDialog *earm_update)
    {
        earm_update->setWindowTitle(QApplication::translate("earm_update", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("earm_update", "Actualizaci\303\263n en progreso", Q_NULLPTR));
        label_2->setText(QApplication::translate("earm_update", "Calidad de se\303\261al:", Q_NULLPTR));
        label_3->setText(QApplication::translate("earm_update", "Tiempo de conexi\303\263n:", Q_NULLPTR));
        label_4->setText(QString());
        label_5->setText(QApplication::translate("earm_update", "Numero de serie:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class earm_update: public Ui_earm_update {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EARM_UPDATE_H
