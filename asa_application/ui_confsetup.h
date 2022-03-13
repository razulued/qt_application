/********************************************************************************
** Form generated from reading UI file 'confsetup.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFSETUP_H
#define UI_CONFSETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_confsetup
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *DirLayout;
    QTableWidget *tableWidget;
    QGroupBox *ButtonBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *add_pushButton;
    QPushButton *edit_pushButton;
    QPushButton *remove_pushButton;
    QPushButton *save_changes_pushButton;
    QPushButton *closeButton;

    void setupUi(QDialog *confsetup)
    {
        if (confsetup->objectName().isEmpty())
            confsetup->setObjectName(QStringLiteral("confsetup"));
        confsetup->resize(800, 600);
        verticalLayoutWidget = new QWidget(confsetup);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 101, 271));
        DirLayout = new QVBoxLayout(verticalLayoutWidget);
        DirLayout->setObjectName(QStringLiteral("DirLayout"));
        DirLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(confsetup);
        if (tableWidget->columnCount() < 13)
            tableWidget->setColumnCount(13);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(120, 20, 671, 191));
        ButtonBox = new QGroupBox(confsetup);
        ButtonBox->setObjectName(QStringLiteral("ButtonBox"));
        ButtonBox->setGeometry(QRect(120, 220, 671, 71));
        ButtonBox->setStyleSheet(QLatin1String("#ButtonBox\n"
"{\n"
"background-color: black;\n"
"color: rgb(0, 167, 250);\n"
"border: none;\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(ButtonBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        add_pushButton = new QPushButton(ButtonBox);
        add_pushButton->setObjectName(QStringLiteral("add_pushButton"));
        add_pushButton->setEnabled(true);
        add_pushButton->setStyleSheet(QLatin1String("#add_pushButton\n"
"{\n"
"background-color: black;\n"
"color: rgb(0, 167, 250);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(0, 167, 250);\n"
"border-radius: 10px;\n"
"}\n"
""));

        horizontalLayout->addWidget(add_pushButton);

        edit_pushButton = new QPushButton(ButtonBox);
        edit_pushButton->setObjectName(QStringLiteral("edit_pushButton"));
        edit_pushButton->setStyleSheet(QLatin1String("#edit_pushButton\n"
"{\n"
"background-color: black;\n"
"color: rgb(0, 167, 250);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(0, 167, 250);\n"
"border-radius: 10px;\n"
"}\n"
""));

        horizontalLayout->addWidget(edit_pushButton);

        remove_pushButton = new QPushButton(ButtonBox);
        remove_pushButton->setObjectName(QStringLiteral("remove_pushButton"));
        remove_pushButton->setStyleSheet(QLatin1String("#remove_pushButton\n"
"{\n"
"background-color: black;\n"
"color: rgb(0, 167, 250);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(0, 167, 250);\n"
"border-radius: 10px;\n"
"}\n"
""));

        horizontalLayout->addWidget(remove_pushButton);

        save_changes_pushButton = new QPushButton(ButtonBox);
        save_changes_pushButton->setObjectName(QStringLiteral("save_changes_pushButton"));
        save_changes_pushButton->setStyleSheet(QLatin1String("#save_changes_pushButton\n"
"{\n"
"background-color: black;\n"
"color: rgb(0, 167, 250);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(0, 167, 250);\n"
"border-radius: 10px;\n"
"}\n"
""));

        horizontalLayout->addWidget(save_changes_pushButton);

        closeButton = new QPushButton(confsetup);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(690, 560, 93, 28));
        closeButton->setStyleSheet(QLatin1String("#closeButton\n"
"{\n"
"background-color: black;\n"
"color: rgb(0, 167, 250);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(0, 167, 250);\n"
"border-radius: 3px;\n"
"}\n"
""));

        retranslateUi(confsetup);

        QMetaObject::connectSlotsByName(confsetup);
    } // setupUi

    void retranslateUi(QDialog *confsetup)
    {
        confsetup->setWindowTitle(QApplication::translate("confsetup", "Dialog", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("confsetup", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("confsetup", "Nombre", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("confsetup", "Tipo", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("confsetup", "Unidades", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("confsetup", "Min. Mostrar", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("confsetup", "Max. Mostrar", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("confsetup", "Min. Crudo", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("confsetup", "Max. Crudo", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("confsetup", "Tama\303\261o Dato", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("confsetup", "Tipo Calculo", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("confsetup", "Const1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("confsetup", "Const2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("confsetup", "Const3", Q_NULLPTR));
        ButtonBox->setTitle(QApplication::translate("confsetup", "Acciones", Q_NULLPTR));
        add_pushButton->setText(QApplication::translate("confsetup", "Agregar", Q_NULLPTR));
        edit_pushButton->setText(QApplication::translate("confsetup", "Editar", Q_NULLPTR));
        remove_pushButton->setText(QApplication::translate("confsetup", "Borrar", Q_NULLPTR));
        save_changes_pushButton->setText(QApplication::translate("confsetup", "Guardar Camios", Q_NULLPTR));
        closeButton->setText(QApplication::translate("confsetup", "Cerrar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class confsetup: public Ui_confsetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFSETUP_H
