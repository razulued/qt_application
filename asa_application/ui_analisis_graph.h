/********************************************************************************
** Form generated from reading UI file 'analisis_graph.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALISIS_GRAPH_H
#define UI_ANALISIS_GRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_analisis_graph
{
public:
    QWidget *controls;
    QPushButton *start_test;
    QTableWidget *tableWidget;
    QProgressBar *progressBar;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QWidget *widget;
    QPushButton *graph_button;
    QWidget *datewidget;
    QLabel *label;

    void setupUi(QDialog *analisis_graph)
    {
        if (analisis_graph->objectName().isEmpty())
            analisis_graph->setObjectName(QStringLiteral("analisis_graph"));
        analisis_graph->resize(800, 600);
        controls = new QWidget(analisis_graph);
        controls->setObjectName(QStringLiteral("controls"));
        controls->setGeometry(QRect(20, 430, 761, 161));
        controls->setStyleSheet(QLatin1String("#controls\n"
"{\n"
"background-color: rgb(32,29,72);\n"
"border: none;\n"
"border-radius: 10px;\n"
"}"));
        start_test = new QPushButton(controls);
        start_test->setObjectName(QStringLiteral("start_test"));
        start_test->setGeometry(QRect(10, 10, 111, 111));
        start_test->setStyleSheet(QLatin1String("#start_test\n"
"{\n"
"background-color: transparent;\n"
"background-image: url(:/demo/images/Demo/Play.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"border: none;\n"
"}"));
        tableWidget = new QTableWidget(controls);
        if (tableWidget->columnCount() < 10)
            tableWidget->setColumnCount(10);
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
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(210, 20, 541, 131));
        tableWidget->setStyleSheet(QLatin1String("#tableWidget\n"
"{\n"
"border-radius: 10px;\n"
"}"));
        progressBar = new QProgressBar(controls);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(10, 130, 111, 23));
        progressBar->setStyleSheet(QLatin1String("#progressBar\n"
"{\n"
"background-color: transparent;\n"
"border: 2px solid gray;\n"
"border-radius: 10px;\n"
"}\n"
"#progressBar:chunk\n"
"{\n"
"background-color: rgb(70,154,170);\n"
"width: 2px;\n"
"margin: 1px;\n"
"}"));
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        comboBox = new QComboBox(controls);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(130, 49, 74, 22));
        comboBox_2 = new QComboBox(controls);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(130, 76, 74, 22));
        comboBox_3 = new QComboBox(controls);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(130, 103, 74, 22));
        widget = new QWidget(analisis_graph);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 60, 761, 341));
        graph_button = new QPushButton(analisis_graph);
        graph_button->setObjectName(QStringLiteral("graph_button"));
        graph_button->setGeometry(QRect(720, 10, 61, 41));
        graph_button->setStyleSheet(QLatin1String("#graph_button\n"
"{\n"
"background-color: transparent;\n"
"background-image: url(:/demo/images/Demo/Graph Home.png);\n"
"background-repeat: none;\n"
"background-position: center;\n"
"border: none;\n"
"}"));
        datewidget = new QWidget(analisis_graph);
        datewidget->setObjectName(QStringLiteral("datewidget"));
        datewidget->setGeometry(QRect(310, 5, 180, 50));
        label = new QLabel(analisis_graph);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(296, 400, 161, 20));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(analisis_graph);

        comboBox->setCurrentIndex(13);
        comboBox_2->setCurrentIndex(1);
        comboBox_3->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(analisis_graph);
    } // setupUi

    void retranslateUi(QDialog *analisis_graph)
    {
        analisis_graph->setWindowTitle(QApplication::translate("analisis_graph", "Dialog", Q_NULLPTR));
        start_test->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("analisis_graph", "P1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("analisis_graph", "P2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("analisis_graph", "P3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("analisis_graph", "P4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("analisis_graph", "P5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("analisis_graph", "P6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("analisis_graph", "P7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("analisis_graph", "P8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("analisis_graph", "P9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("analisis_graph", "P10", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("analisis_graph", "Caudal", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Presi\303\263n", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Voltaje AVG", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Voltaje L1-L2", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Voltaje L2-L3", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Voltaje L3-L1", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Amperaje AVG", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Amperaje L1-L2", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Amperaje L2-L3", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Amperaje L3-L1", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "FP", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Coseno Phi", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Frecuencia", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "%Valvula", Q_NULLPTR)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("analisis_graph", "Caudal", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Presi\303\263n", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Voltaje AVG", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Voltaje L1-L2", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Voltaje L2-L3", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Voltaje L3-L1", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Amperaje AVG", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Amperaje L1-L2", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Amperaje L2-L3", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Amperaje L3-L1", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "FP", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Coseno Phi", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Frecuencia", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "%Valvula", Q_NULLPTR)
        );
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("analisis_graph", "Caudal", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Presi\303\263n", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Voltaje AVG", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Voltaje L1-L2", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Voltaje L2-L3", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Voltaje L3-L1", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Amperaje AVG", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Amperaje L1-L2", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Amperaje L2-L3", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Amperaje L3-L1", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "FP", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Coseno Phi", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "Frecuencia", Q_NULLPTR)
         << QApplication::translate("analisis_graph", "%Valvula", Q_NULLPTR)
        );
        graph_button->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class analisis_graph: public Ui_analisis_graph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALISIS_GRAPH_H
