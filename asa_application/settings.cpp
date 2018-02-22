#include "settings.h"
#include "ui_settings.h"
#include <QDebug>
#include <QDir>
#include "configuration.h"

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

    ui->cfg_out_rel_1_MSB->setCurrentIndex(load_ASA_conf("out","cfg_out_rel_1_MSB"));
    ui->cfg_out_rel_1_LSB->setCurrentIndex(load_ASA_conf("out","cfg_out_rel_1_LSB"));
    ui->cfg_out_rel_2_MSB->setCurrentIndex(load_ASA_conf("out","cfg_out_rel_2_MSB"));
    ui->cfg_out_rel_2_LSB->setCurrentIndex(load_ASA_conf("out","cfg_out_rel_2_LSB"));
    ui->cfg_out_rel_3_MSB->setCurrentIndex(load_ASA_conf("out","cfg_out_rel_3_MSB"));
    ui->cfg_out_rel_3_LSB->setCurrentIndex(load_ASA_conf("out","cfg_out_rel_3_LSB"));
    ui->cfg_out_rel_4_MSB->setCurrentIndex(load_ASA_conf("out","cfg_out_rel_4_MSB"));
    ui->cfg_out_rel_4_LSB->setCurrentIndex(load_ASA_conf("out","cfg_out_rel_4_LSB"));

    ui->cfg_out_led_1_MSB->setCurrentIndex(load_ASA_conf("out","cfg_out_led_1_MSB"));
    ui->cfg_out_led_1_LSB->setCurrentIndex(load_ASA_conf("out","cfg_out_led_1_LSB"));
    ui->cfg_out_led_2_MSB->setCurrentIndex(load_ASA_conf("out","cfg_out_led_2_MSB"));
    ui->cfg_out_led_2_LSB->setCurrentIndex(load_ASA_conf("out","cfg_out_led_2_LSB"));
    ui->cfg_out_led_3_MSB->setCurrentIndex(load_ASA_conf("out","cfg_out_led_3_MSB"));
    ui->cfg_out_led_3_LSB->setCurrentIndex(load_ASA_conf("out","cfg_out_led_3_LSB"));
    ui->cfg_out_led_4_MSB->setCurrentIndex(load_ASA_conf("out","cfg_out_led_4_MSB"));
    ui->cfg_out_led_4_LSB->setCurrentIndex(load_ASA_conf("out","cfg_out_led_4_LSB"));

    ui->cfg_ana_1_MSB->setCurrentIndex(load_ASA_conf("in","cfg_ana_1_MSB"));
    ui->cfg_ana_1_LSB->setCurrentIndex(load_ASA_conf("in","cfg_ana_1_LSB"));
    ui->cfg_ana_2_MSB->setCurrentIndex(load_ASA_conf("in","cfg_ana_2_MSB"));
    ui->cfg_ana_2_LSB->setCurrentIndex(load_ASA_conf("in","cfg_ana_2_LSB"));
    ui->cfg_ana_3_MSB->setCurrentIndex(load_ASA_conf("in","cfg_ana_3_MSB"));
    ui->cfg_ana_3_LSB->setCurrentIndex(load_ASA_conf("in","cfg_ana_3_LSB"));
    ui->cfg_ana_4_MSB->setCurrentIndex(load_ASA_conf("in","cfg_ana_4_MSB"));
    ui->cfg_ana_4_LSB->setCurrentIndex(load_ASA_conf("in","cfg_ana_4_LSB"));
    ui->cfg_ana_5_MSB->setCurrentIndex(load_ASA_conf("in","cfg_ana_5_MSB"));
    ui->cfg_ana_5_LSB->setCurrentIndex(load_ASA_conf("in","cfg_ana_5_LSB"));
    ui->cfg_ana_6_MSB->setCurrentIndex(load_ASA_conf("in","cfg_ana_6_MSB"));
    ui->cfg_ana_6_LSB->setCurrentIndex(load_ASA_conf("in","cfg_ana_6_LSB"));
    ui->cfg_ana_7_MSB->setCurrentIndex(load_ASA_conf("in","cfg_ana_7_MSB"));
    ui->cfg_ana_7_LSB->setCurrentIndex(load_ASA_conf("in","cfg_ana_7_LSB"));
    ui->cfg_ana_8_MSB->setCurrentIndex(load_ASA_conf("in","cfg_ana_8_MSB"));
    ui->cfg_ana_8_LSB->setCurrentIndex(load_ASA_conf("in","cfg_ana_8_LSB"));
    ui->cfg_ana_9_MSB->setCurrentIndex(load_ASA_conf("in","cfg_ana_9_MSB"));
    ui->cfg_ana_9_LSB->setCurrentIndex(load_ASA_conf("in","cfg_ana_9_LSB"));


    ui->cfg_modbus_MSB_0->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_MSB_0"));
    ui->cfg_modbus_LSB_0->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_LSB_0"));
    ui->cfg_modbus_MSB_1->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_MSB_1"));
    ui->cfg_modbus_LSB_1->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_LSB_1"));
    ui->cfg_modbus_MSB_2->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_MSB_2"));
    ui->cfg_modbus_LSB_2->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_LSB_2"));
    ui->cfg_modbus_MSB_3->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_MSB_3"));
    ui->cfg_modbus_LSB_3->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_LSB_3"));
    ui->cfg_modbus_MSB_4->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_MSB_4"));
    ui->cfg_modbus_LSB_4->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_LSB_4"));
    ui->cfg_modbus_MSB_5->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_MSB_5"));
    ui->cfg_modbus_LSB_5->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_LSB_5"));
    ui->cfg_modbus_MSB_6->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_MSB_6"));
    ui->cfg_modbus_LSB_6->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_LSB_6"));
    ui->cfg_modbus_MSB_7->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_MSB_7"));
    ui->cfg_modbus_LSB_7->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_LSB_7"));
    ui->cfg_modbus_MSB_8->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_MSB_8"));
    ui->cfg_modbus_LSB_8->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_LSB_8"));
    ui->cfg_modbus_MSB_9->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_MSB_9"));
    ui->cfg_modbus_LSB_9->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_LSB_9"));
    ui->cfg_modbus_MSB_10->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_MSB_10"));
    ui->cfg_modbus_LSB_10->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_LSB_10"));
    ui->cfg_modbus_MSB_11->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_MSB_11"));
    ui->cfg_modbus_LSB_11->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_LSB_11"));
    ui->cfg_modbus_MSB_12->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_MSB_12"));
    ui->cfg_modbus_LSB_12->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_LSB_12"));
    ui->cfg_modbus_MSB_13->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_MSB_13"));
    ui->cfg_modbus_LSB_13->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_LSB_13"));
    ui->cfg_modbus_MSB_14->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_MSB_14"));
    ui->cfg_modbus_LSB_14->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_LSB_14"));
    ui->cfg_modbus_MSB_15->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_MSB_15"));
    ui->cfg_modbus_LSB_15->setCurrentIndex(load_ASA_conf("modbus1","cfg_modbus_LSB_15"));

    ui->cfg_modbus_2_byte_addr_0_ch_0->setCurrentIndex(load_ASA_conf("modbus2","cfg_modbus_2_byte_addr_0_ch_0"));
    ui->cfg_modbus_2_byte_addr_0_ch_1->setCurrentIndex(load_ASA_conf("modbus2","cfg_modbus_2_byte_addr_0_ch_1"));
    ui->cfg_modbus_2_byte_addr_0_ch_2->setCurrentIndex(load_ASA_conf("modbus2","cfg_modbus_2_byte_addr_0_ch_2"));
    ui->cfg_modbus_2_byte_addr_0_ch_3->setCurrentIndex(load_ASA_conf("modbus2","cfg_modbus_2_byte_addr_0_ch_3"));
    ui->cfg_modbus_2_byte_addr_1_ch_0->setCurrentIndex(load_ASA_conf("modbus2","cfg_modbus_2_byte_addr_1_ch_0"));
    ui->cfg_modbus_2_byte_addr_1_ch_1->setCurrentIndex(load_ASA_conf("modbus2","cfg_modbus_2_byte_addr_1_ch_1"));
    ui->cfg_modbus_2_byte_addr_1_ch_2->setCurrentIndex(load_ASA_conf("modbus2","cfg_modbus_2_byte_addr_1_ch_2"));
    ui->cfg_modbus_2_byte_addr_1_ch_3->setCurrentIndex(load_ASA_conf("modbus2","cfg_modbus_2_byte_addr_1_ch_3"));

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

    /*Store ASA conf*/
    store_ASA_conf("out","cfg_out_rel_1_MSB", ui->cfg_out_rel_1_MSB->currentIndex());
    store_ASA_conf("out","cfg_out_rel_1_LSB", ui->cfg_out_rel_1_LSB->currentIndex());
    store_ASA_conf("out","cfg_out_rel_2_MSB", ui->cfg_out_rel_2_MSB->currentIndex());
    store_ASA_conf("out","cfg_out_rel_2_LSB", ui->cfg_out_rel_2_LSB->currentIndex());
    store_ASA_conf("out","cfg_out_rel_3_MSB", ui->cfg_out_rel_3_MSB->currentIndex());
    store_ASA_conf("out","cfg_out_rel_3_LSB", ui->cfg_out_rel_3_LSB->currentIndex());
    store_ASA_conf("out","cfg_out_rel_4_MSB", ui->cfg_out_rel_4_MSB->currentIndex());
    store_ASA_conf("out","cfg_out_rel_4_LSB", ui->cfg_out_rel_4_LSB->currentIndex());

    store_ASA_conf("out","cfg_out_led_1_MSB", ui->cfg_out_led_1_MSB->currentIndex());
    store_ASA_conf("out","cfg_out_led_1_LSB", ui->cfg_out_led_1_LSB->currentIndex());
    store_ASA_conf("out","cfg_out_led_2_MSB", ui->cfg_out_led_2_MSB->currentIndex());
    store_ASA_conf("out","cfg_out_led_2_LSB", ui->cfg_out_led_2_LSB->currentIndex());
    store_ASA_conf("out","cfg_out_led_3_MSB", ui->cfg_out_led_3_MSB->currentIndex());
    store_ASA_conf("out","cfg_out_led_3_LSB", ui->cfg_out_led_3_LSB->currentIndex());
    store_ASA_conf("out","cfg_out_led_4_MSB", ui->cfg_out_led_4_MSB->currentIndex());
    store_ASA_conf("out","cfg_out_led_4_LSB", ui->cfg_out_led_4_LSB->currentIndex());

    store_ASA_conf("in","cfg_ana_1_MSB", ui->cfg_ana_1_MSB->currentIndex());
    store_ASA_conf("in","cfg_ana_1_LSB", ui->cfg_ana_1_LSB->currentIndex());
    store_ASA_conf("in","cfg_ana_2_MSB", ui->cfg_ana_2_MSB->currentIndex());
    store_ASA_conf("in","cfg_ana_2_LSB", ui->cfg_ana_2_LSB->currentIndex());
    store_ASA_conf("in","cfg_ana_3_MSB", ui->cfg_ana_3_MSB->currentIndex());
    store_ASA_conf("in","cfg_ana_3_LSB", ui->cfg_ana_3_LSB->currentIndex());
    store_ASA_conf("in","cfg_ana_4_MSB", ui->cfg_ana_4_MSB->currentIndex());
    store_ASA_conf("in","cfg_ana_4_LSB", ui->cfg_ana_4_LSB->currentIndex());
    store_ASA_conf("in","cfg_ana_5_MSB", ui->cfg_ana_5_MSB->currentIndex());
    store_ASA_conf("in","cfg_ana_5_LSB", ui->cfg_ana_5_LSB->currentIndex());
    store_ASA_conf("in","cfg_ana_6_MSB", ui->cfg_ana_6_MSB->currentIndex());
    store_ASA_conf("in","cfg_ana_6_LSB", ui->cfg_ana_6_LSB->currentIndex());
    store_ASA_conf("in","cfg_ana_7_MSB", ui->cfg_ana_7_MSB->currentIndex());
    store_ASA_conf("in","cfg_ana_7_LSB", ui->cfg_ana_7_LSB->currentIndex());
    store_ASA_conf("in","cfg_ana_8_MSB", ui->cfg_ana_8_MSB->currentIndex());
    store_ASA_conf("in","cfg_ana_8_LSB", ui->cfg_ana_8_LSB->currentIndex());
    store_ASA_conf("in","cfg_ana_9_MSB", ui->cfg_ana_9_MSB->currentIndex());
    store_ASA_conf("in","cfg_ana_9_LSB", ui->cfg_ana_9_LSB->currentIndex());


    store_ASA_conf("modbus1","cfg_modbus_MSB_0", ui->cfg_modbus_MSB_0->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_LSB_0", ui->cfg_modbus_LSB_0->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_MSB_1", ui->cfg_modbus_MSB_1->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_LSB_1", ui->cfg_modbus_LSB_1->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_MSB_2", ui->cfg_modbus_MSB_2->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_LSB_2", ui->cfg_modbus_LSB_2->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_MSB_3", ui->cfg_modbus_MSB_3->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_LSB_3", ui->cfg_modbus_LSB_3->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_MSB_4", ui->cfg_modbus_MSB_4->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_LSB_4", ui->cfg_modbus_LSB_4->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_MSB_5", ui->cfg_modbus_MSB_5->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_LSB_5", ui->cfg_modbus_LSB_5->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_MSB_6", ui->cfg_modbus_MSB_6->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_LSB_6", ui->cfg_modbus_LSB_6->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_MSB_7", ui->cfg_modbus_MSB_7->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_LSB_7", ui->cfg_modbus_LSB_7->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_MSB_8", ui->cfg_modbus_MSB_8->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_LSB_8", ui->cfg_modbus_LSB_8->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_MSB_9", ui->cfg_modbus_MSB_9->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_LSB_9", ui->cfg_modbus_LSB_9->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_MSB_10", ui->cfg_modbus_MSB_10->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_LSB_10", ui->cfg_modbus_LSB_10->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_MSB_11", ui->cfg_modbus_MSB_11->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_LSB_11", ui->cfg_modbus_LSB_11->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_MSB_12", ui->cfg_modbus_MSB_12->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_LSB_12", ui->cfg_modbus_LSB_12->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_MSB_13", ui->cfg_modbus_MSB_13->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_LSB_13", ui->cfg_modbus_LSB_13->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_MSB_14", ui->cfg_modbus_MSB_14->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_LSB_14", ui->cfg_modbus_LSB_14->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_MSB_15", ui->cfg_modbus_MSB_15->currentIndex());
    store_ASA_conf("modbus1","cfg_modbus_LSB_15", ui->cfg_modbus_LSB_15->currentIndex());

    store_ASA_conf("modbus2","cfg_modbus_2_byte_addr_0_ch_0", ui->cfg_modbus_2_byte_addr_0_ch_0->currentIndex());
    store_ASA_conf("modbus2","cfg_modbus_2_byte_addr_0_ch_1", ui->cfg_modbus_2_byte_addr_0_ch_1->currentIndex());
    store_ASA_conf("modbus2","cfg_modbus_2_byte_addr_0_ch_2", ui->cfg_modbus_2_byte_addr_0_ch_2->currentIndex());
    store_ASA_conf("modbus2","cfg_modbus_2_byte_addr_0_ch_3", ui->cfg_modbus_2_byte_addr_0_ch_3->currentIndex());
    store_ASA_conf("modbus2","cfg_modbus_2_byte_addr_1_ch_0", ui->cfg_modbus_2_byte_addr_1_ch_0->currentIndex());
    store_ASA_conf("modbus2","cfg_modbus_2_byte_addr_1_ch_1", ui->cfg_modbus_2_byte_addr_1_ch_1->currentIndex());
    store_ASA_conf("modbus2","cfg_modbus_2_byte_addr_1_ch_2", ui->cfg_modbus_2_byte_addr_1_ch_2->currentIndex());
    store_ASA_conf("modbus2","cfg_modbus_2_byte_addr_1_ch_3", ui->cfg_modbus_2_byte_addr_1_ch_3->currentIndex());
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

void settings::on_buttonBox_accepted()
{

}
