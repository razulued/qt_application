/********************************************************************************
** Form generated from reading UI file 'simulation_input.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATION_INPUT_H
#define UI_SIMULATION_INPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollBar>

QT_BEGIN_NAMESPACE

class Ui_simulation_input
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QCheckBox *checkBox;
    QLineEdit *lineEdit;
    QScrollBar *horizontalScrollBar;
    QLabel *label_2;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QScrollBar *horizontalScrollBar_2;
    QLineEdit *lineEdit_3;
    QScrollBar *horizontalScrollBar_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QScrollBar *horizontalScrollBar_4;

    void setupUi(QDialog *simulation_input)
    {
        if (simulation_input->objectName().isEmpty())
            simulation_input->setObjectName(QStringLiteral("simulation_input"));
        simulation_input->resize(604, 300);
        formLayout = new QFormLayout(simulation_input);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(simulation_input);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        checkBox = new QCheckBox(simulation_input);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, checkBox);

        lineEdit = new QLineEdit(simulation_input);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lineEdit);

        horizontalScrollBar = new QScrollBar(simulation_input);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        formLayout->setWidget(1, QFormLayout::FieldRole, horizontalScrollBar);

        label_2 = new QLabel(simulation_input);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        checkBox_2 = new QCheckBox(simulation_input);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, checkBox_2);

        checkBox_3 = new QCheckBox(simulation_input);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        formLayout->setWidget(4, QFormLayout::FieldRole, checkBox_3);

        label_3 = new QLabel(simulation_input);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_3);

        lineEdit_2 = new QLineEdit(simulation_input);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout->setWidget(6, QFormLayout::LabelRole, lineEdit_2);

        horizontalScrollBar_2 = new QScrollBar(simulation_input);
        horizontalScrollBar_2->setObjectName(QStringLiteral("horizontalScrollBar_2"));
        horizontalScrollBar_2->setOrientation(Qt::Horizontal);

        formLayout->setWidget(6, QFormLayout::FieldRole, horizontalScrollBar_2);

        lineEdit_3 = new QLineEdit(simulation_input);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        formLayout->setWidget(8, QFormLayout::LabelRole, lineEdit_3);

        horizontalScrollBar_3 = new QScrollBar(simulation_input);
        horizontalScrollBar_3->setObjectName(QStringLiteral("horizontalScrollBar_3"));
        horizontalScrollBar_3->setOrientation(Qt::Horizontal);

        formLayout->setWidget(8, QFormLayout::FieldRole, horizontalScrollBar_3);

        label_4 = new QLabel(simulation_input);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(simulation_input);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_5);

        lineEdit_4 = new QLineEdit(simulation_input);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        formLayout->setWidget(10, QFormLayout::LabelRole, lineEdit_4);

        horizontalScrollBar_4 = new QScrollBar(simulation_input);
        horizontalScrollBar_4->setObjectName(QStringLiteral("horizontalScrollBar_4"));
        horizontalScrollBar_4->setOrientation(Qt::Horizontal);

        formLayout->setWidget(10, QFormLayout::FieldRole, horizontalScrollBar_4);


        retranslateUi(simulation_input);

        QMetaObject::connectSlotsByName(simulation_input);
    } // setupUi

    void retranslateUi(QDialog *simulation_input)
    {
        simulation_input->setWindowTitle(QApplication::translate("simulation_input", "Dialog", 0));
        label->setText(QApplication::translate("simulation_input", "Carcamo Level", 0));
        checkBox->setText(QApplication::translate("simulation_input", "Active", 0));
        label_2->setText(QApplication::translate("simulation_input", "Reactor", 0));
        checkBox_2->setText(QApplication::translate("simulation_input", "Motor 1", 0));
        checkBox_3->setText(QApplication::translate("simulation_input", "Motor 2", 0));
        label_3->setText(QApplication::translate("simulation_input", "Caudal in", 0));
        label_4->setText(QApplication::translate("simulation_input", "Caudal out", 0));
        label_5->setText(QApplication::translate("simulation_input", "Return", 0));
    } // retranslateUi

};

namespace Ui {
    class simulation_input: public Ui_simulation_input {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATION_INPUT_H
