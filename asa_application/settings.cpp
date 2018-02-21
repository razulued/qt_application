#include "settings.h"
#include "ui_settings.h"
#include <QDebug>
#include <QDir>
settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);

//    ui->ID_regulador_Ap->setText(conf.value("Ap", 0).toString());
//    ui->ID_regulador_FP->setText(conf.value("FP", 0).toString());
//    ui->ID_regulador_ND->setText(conf.value("ND", 0).toString());
//    ui->ID_regulador_Q->setText(conf.value("Q", 0).toString());
//    ui->ID_regulador_SST->setText(conf.value("SST", 0).toString());
//    ui->ID_regulador_turbidez->setText(conf.value("Turbidez", 0).toString());
//    ui->ID_regulador_Vp->setText(conf.value("Vp", 0).toString());
//    ui->ID_regulador_pH->setText(conf.value("pH", 0).toString());
//    conf.endGroup();
//    conf.sync();

    QString filename="config.ini";
    config_file = new QFile(filename);

    if(!config_file->exists())
    {
        qDebug() << "No existe el archivo";
    }
    else
    {
        qDebug() << "Archivo encontrado";
    }

    QString line;
    ui->textEdit->clear();

    if(config_file->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream stream(config_file);
        while(!stream.atEnd())
        {
            line = stream.readLine();
            ui->textEdit->setText(ui->textEdit->toPlainText()+line+"\n");
        }
    }

    this->show();
}

settings::~settings()
{
    delete ui;
}

void settings::sync_regulador_IDs()
{
    QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
    conf.sync();
    conf.beginGroup("Regulador");

    const QStringList regulador_keys = conf.childKeys();
    QList<int> regulador_IDs;
    foreach(const QString &regulador_key, regulador_keys)
    {
        regulador_IDs << conf.value(regulador_key).toInt();
    }
    conf.endGroup();

    int i = 0;
    for(i = 0; i < regulador_keys.size(); i++)
    {
        qDebug() << regulador_keys[i] << ": " << regulador_IDs[i];
    }
}

void settings::on_settings_accepted()
{
//    saveSettings("Regulador", ui->regulador_ND_label->text(), ui->ID_regulador_ND->text().toInt());
    QTextStream stream(config_file);
    config_file->resize(0);
    stream << ui->textEdit->toPlainText();
    config_file->flush();
    config_file->close();

}

void settings::on_settings_rejected()
{
    config_file->close();
}


void saveSettings(const QString &group, const QString &key, const QVariant &value)
{
    QSettings S;

    S.beginGroup(group);
    S.setValue(key, value);
    S.endGroup();
}
