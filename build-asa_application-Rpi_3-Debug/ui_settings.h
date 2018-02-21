/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settings
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *regulador_ND_label;
    QLineEdit *ID_regulador_ND;
    QLabel *regulador_pH_label;
    QLineEdit *ID_regulador_pH;
    QLabel *regulador_SST_abel;
    QLineEdit *ID_regulador_SST;
    QLabel *regulturbidez_labelador_;
    QLineEdit *ID_regulador_turbidez;
    QLabel *regulador_Vp_label;
    QLabel *regulador_Ap_label;
    QLabel *regulador_FP_label;
    QLineEdit *ID_regulador_Vp;
    QLineEdit *ID_regulador_Ap;
    QLineEdit *ID_regulador_FP;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *tab_6;

    void setupUi(QDialog *settings)
    {
        if (settings->objectName().isEmpty())
            settings->setObjectName(QStringLiteral("settings"));
        settings->resize(846, 571);
        gridLayout = new QGridLayout(settings);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(settings);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(settings);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 1, 1, 1);

        tabWidget = new QTabWidget(settings);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        formLayoutWidget = new QWidget(tab);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 30, 351, 196));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        regulador_ND_label = new QLabel(formLayoutWidget);
        regulador_ND_label->setObjectName(QStringLiteral("regulador_ND_label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, regulador_ND_label);

        ID_regulador_ND = new QLineEdit(formLayoutWidget);
        ID_regulador_ND->setObjectName(QStringLiteral("ID_regulador_ND"));

        formLayout->setWidget(0, QFormLayout::FieldRole, ID_regulador_ND);

        regulador_pH_label = new QLabel(formLayoutWidget);
        regulador_pH_label->setObjectName(QStringLiteral("regulador_pH_label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, regulador_pH_label);

        ID_regulador_pH = new QLineEdit(formLayoutWidget);
        ID_regulador_pH->setObjectName(QStringLiteral("ID_regulador_pH"));

        formLayout->setWidget(1, QFormLayout::FieldRole, ID_regulador_pH);

        regulador_SST_abel = new QLabel(formLayoutWidget);
        regulador_SST_abel->setObjectName(QStringLiteral("regulador_SST_abel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, regulador_SST_abel);

        ID_regulador_SST = new QLineEdit(formLayoutWidget);
        ID_regulador_SST->setObjectName(QStringLiteral("ID_regulador_SST"));

        formLayout->setWidget(2, QFormLayout::FieldRole, ID_regulador_SST);

        regulturbidez_labelador_ = new QLabel(formLayoutWidget);
        regulturbidez_labelador_->setObjectName(QStringLiteral("regulturbidez_labelador_"));

        formLayout->setWidget(3, QFormLayout::LabelRole, regulturbidez_labelador_);

        ID_regulador_turbidez = new QLineEdit(formLayoutWidget);
        ID_regulador_turbidez->setObjectName(QStringLiteral("ID_regulador_turbidez"));

        formLayout->setWidget(3, QFormLayout::FieldRole, ID_regulador_turbidez);

        regulador_Vp_label = new QLabel(formLayoutWidget);
        regulador_Vp_label->setObjectName(QStringLiteral("regulador_Vp_label"));

        formLayout->setWidget(4, QFormLayout::LabelRole, regulador_Vp_label);

        regulador_Ap_label = new QLabel(formLayoutWidget);
        regulador_Ap_label->setObjectName(QStringLiteral("regulador_Ap_label"));

        formLayout->setWidget(5, QFormLayout::LabelRole, regulador_Ap_label);

        regulador_FP_label = new QLabel(formLayoutWidget);
        regulador_FP_label->setObjectName(QStringLiteral("regulador_FP_label"));

        formLayout->setWidget(6, QFormLayout::LabelRole, regulador_FP_label);

        ID_regulador_Vp = new QLineEdit(formLayoutWidget);
        ID_regulador_Vp->setObjectName(QStringLiteral("ID_regulador_Vp"));

        formLayout->setWidget(4, QFormLayout::FieldRole, ID_regulador_Vp);

        ID_regulador_Ap = new QLineEdit(formLayoutWidget);
        ID_regulador_Ap->setObjectName(QStringLiteral("ID_regulador_Ap"));

        formLayout->setWidget(5, QFormLayout::FieldRole, ID_regulador_Ap);

        ID_regulador_FP = new QLineEdit(formLayoutWidget);
        ID_regulador_FP->setObjectName(QStringLiteral("ID_regulador_FP"));

        formLayout->setWidget(6, QFormLayout::FieldRole, ID_regulador_FP);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tabWidget->addTab(tab_6, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 2);


        retranslateUi(settings);
        QObject::connect(buttonBox, SIGNAL(accepted()), settings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), settings, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(settings);
    } // setupUi

    void retranslateUi(QDialog *settings)
    {
        settings->setWindowTitle(QApplication::translate("settings", "Dialog", 0));
        label->setText(QApplication::translate("settings", "ADVERTENCIA: NO MODIFICAR ESTAS CONFIGURACIONES SIN CONOCIMIENTO DEL SISTEMA", 0));
        regulador_ND_label->setText(QApplication::translate("settings", "ND", 0));
        regulador_pH_label->setText(QApplication::translate("settings", "pH", 0));
        regulador_SST_abel->setText(QApplication::translate("settings", "SST", 0));
        regulturbidez_labelador_->setText(QApplication::translate("settings", "Turbidez", 0));
        regulador_Vp_label->setText(QApplication::translate("settings", "Vp", 0));
        regulador_Ap_label->setText(QApplication::translate("settings", "Ap", 0));
        regulador_FP_label->setText(QApplication::translate("settings", "F.P.", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("settings", "Regulador", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("settings", "Reactor Biologico", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("settings", "Clarificador", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("settings", "Clorador", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("settings", "Digestor de Lodos", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("settings", "Deshidratador de lodos", 0));
    } // retranslateUi

};

namespace Ui {
    class settings: public Ui_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
