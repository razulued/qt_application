/********************************************************************************
** Form generated from reading UI file 'simulation_input.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
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
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_simulation_input
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QScrollBar *horizontalScrollBar;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_2;
    QScrollBar *horizontalScrollBar_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_3;
    QScrollBar *horizontalScrollBar_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_4;
    QScrollBar *horizontalScrollBar_4;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_6;
    QDateTimeEdit *dateTimeEdit;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_8;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_10;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_11;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *simulation_input)
    {
        if (simulation_input->objectName().isEmpty())
            simulation_input->setObjectName(QStringLiteral("simulation_input"));
        simulation_input->resize(470, 376);
        tabWidget = new QTabWidget(simulation_input);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 448, 360));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBox = new QCheckBox(tab);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout->addWidget(checkBox);

        checkBox_4 = new QCheckBox(tab);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        horizontalLayout->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(tab);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));

        horizontalLayout->addWidget(checkBox_5);

        checkBox_6 = new QCheckBox(tab);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));

        horizontalLayout->addWidget(checkBox_6);


        horizontalLayout_3->addLayout(horizontalLayout);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_2->addWidget(label_8);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        horizontalScrollBar = new QScrollBar(tab);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalScrollBar);


        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        checkBox_2 = new QCheckBox(tab);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        horizontalLayout_4->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(tab);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        horizontalLayout_4->addWidget(checkBox_3);

        checkBox_7 = new QCheckBox(tab);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));

        horizontalLayout_4->addWidget(checkBox_7);

        checkBox_8 = new QCheckBox(tab);
        checkBox_8->setObjectName(QStringLiteral("checkBox_8"));

        horizontalLayout_4->addWidget(checkBox_8);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        gridLayout_2->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);

        horizontalScrollBar_2 = new QScrollBar(tab);
        horizontalScrollBar_2->setObjectName(QStringLiteral("horizontalScrollBar_2"));
        horizontalScrollBar_2->setMaximum(1000);
        horizontalScrollBar_2->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalScrollBar_2);


        horizontalLayout_6->addLayout(verticalLayout_2);


        gridLayout_2->addLayout(horizontalLayout_6, 3, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_7->addWidget(label_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout_3->addWidget(lineEdit_3);

        horizontalScrollBar_3 = new QScrollBar(tab);
        horizontalScrollBar_3->setObjectName(QStringLiteral("horizontalScrollBar_3"));
        horizontalScrollBar_3->setMaximum(1000);
        horizontalScrollBar_3->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(horizontalScrollBar_3);


        horizontalLayout_7->addLayout(verticalLayout_3);


        gridLayout_2->addLayout(horizontalLayout_7, 4, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_8->addWidget(label_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        verticalLayout_4->addWidget(lineEdit_4);

        horizontalScrollBar_4 = new QScrollBar(tab);
        horizontalScrollBar_4->setObjectName(QStringLiteral("horizontalScrollBar_4"));
        horizontalScrollBar_4->setMaximum(1000);
        horizontalScrollBar_4->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(horizontalScrollBar_4);


        horizontalLayout_8->addLayout(verticalLayout_4);


        gridLayout_2->addLayout(horizontalLayout_8, 5, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_9->addWidget(label_6);

        dateTimeEdit = new QDateTimeEdit(tab_2);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));

        horizontalLayout_9->addWidget(dateTimeEdit);


        gridLayout_3->addLayout(horizontalLayout_9, 0, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_10->addWidget(pushButton);

        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_10->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_10->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_10->addWidget(pushButton_3);


        gridLayout_3->addLayout(horizontalLayout_10, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        lineEdit_9 = new QLineEdit(tab_2);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        gridLayout->addWidget(lineEdit_9, 0, 1, 1, 1);

        lineEdit_5 = new QLineEdit(tab_2);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 1, 0, 1, 1);

        lineEdit_7 = new QLineEdit(tab_2);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout->addWidget(lineEdit_7, 1, 1, 1, 1);

        lineEdit_6 = new QLineEdit(tab_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 2, 0, 1, 1);

        lineEdit_8 = new QLineEdit(tab_2);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        gridLayout->addWidget(lineEdit_8, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 2, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        pushButton_6 = new QPushButton(tab_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_11->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(tab_3);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        horizontalLayout_11->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(tab_3);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        horizontalLayout_11->addWidget(pushButton_8);


        gridLayout_4->addLayout(horizontalLayout_11, 0, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        pushButton_9 = new QPushButton(tab_3);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        horizontalLayout_13->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(tab_3);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        horizontalLayout_13->addWidget(pushButton_10);


        gridLayout_4->addLayout(horizontalLayout_13, 1, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        pushButton_5 = new QPushButton(tab_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_12->addWidget(pushButton_5);

        lineEdit_10 = new QLineEdit(tab_3);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        horizontalLayout_12->addWidget(lineEdit_10);


        gridLayout_4->addLayout(horizontalLayout_12, 2, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        pushButton_11 = new QPushButton(tab_3);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        verticalLayout_5->addWidget(pushButton_11);

        plainTextEdit = new QPlainTextEdit(tab_3);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout_5->addWidget(plainTextEdit);


        gridLayout_4->addLayout(verticalLayout_5, 3, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());

        retranslateUi(simulation_input);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(simulation_input);
    } // setupUi

    void retranslateUi(QDialog *simulation_input)
    {
        simulation_input->setWindowTitle(QApplication::translate("simulation_input", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("simulation_input", "Carcamo  Motores", Q_NULLPTR));
        checkBox->setText(QApplication::translate("simulation_input", "Motor 1", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("simulation_input", "Motor 2", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("simulation_input", "Motor 3", Q_NULLPTR));
        checkBox_6->setText(QApplication::translate("simulation_input", "Motor 4", Q_NULLPTR));
        label_8->setText(QApplication::translate("simulation_input", "Carcamo Level", Q_NULLPTR));
        label_2->setText(QApplication::translate("simulation_input", "Reactor", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("simulation_input", "Motor 1", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("simulation_input", "Motor 2", Q_NULLPTR));
        checkBox_7->setText(QApplication::translate("simulation_input", "Motor 3", Q_NULLPTR));
        checkBox_8->setText(QApplication::translate("simulation_input", "Motor 4", Q_NULLPTR));
        label_3->setText(QApplication::translate("simulation_input", "Caudal in", Q_NULLPTR));
        label_4->setText(QApplication::translate("simulation_input", "Caudal out", Q_NULLPTR));
        label_5->setText(QApplication::translate("simulation_input", "Return", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("simulation_input", "Tab 1", Q_NULLPTR));
        label_6->setText(QApplication::translate("simulation_input", "Date Time", Q_NULLPTR));
        dateTimeEdit->setDisplayFormat(QApplication::translate("simulation_input", "dd/MM/yy HH:mm:ss", Q_NULLPTR));
        pushButton->setText(QApplication::translate("simulation_input", "Add hour", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("simulation_input", "Add second", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("simulation_input", "Stop time", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("simulation_input", "Run Time", Q_NULLPTR));
        label_7->setText(QApplication::translate("simulation_input", "FW update", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("simulation_input", "Tab 2", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("simulation_input", "ID ultima Actividad", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("simulation_input", "ID ultimo Registro", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("simulation_input", "Dame log N", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("simulation_input", "Store Actividad", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("simulation_input", "Store Registro", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("simulation_input", "Send Command", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("simulation_input", "Read current string (send)", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("simulation_input", "Page", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class simulation_input: public Ui_simulation_input {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATION_INPUT_H
