#include "asa_conf_string.h"
#include "QDebug"
#include <QMutex>
#include "parameters.h"
#include <QSettings>
#include <QDir>

QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);

QString conf_string;
QMutex mutex;

configuration_id plant_config;
void init_plat_config()
{
    conf.sync();
    conf.beginGroup("Plant-Cfg");

    plant_config.names = conf.childKeys();
    foreach(const QString &key, plant_config.names)
    {
        plant_config.ids_string << conf.value(key).toString();
    }

    conf.endGroup();

    conf_string = build_string(&plant_config);
    qDebug() << conf_string;

//    get_plant_config();
}

QString build_string(configuration_id *conf)
{
    mutex.lock();
    int i = 0;
    QString temp;
    // Plant Config
    for(i = 0; i < conf->names.length(); i++)
    {
        temp += conf->names.at(i) + ":" + conf->ids_string.at(i) + "|";
    }
    mutex.unlock();

    return temp;
}

void get_plant_config()
{
    qDebug() << "0x0402" << getParamValue(0x0402);
    qDebug() << "0x2001" << getParamValue(0x2001);

}

void output_control_toggle(uint id)
{
    configuration_id temp_config;


    conf.sync();
    conf.beginGroup("Plant-Cfg");

    // Modify status in config
    QString value = conf.value(QString::number(id)).toString();

    if("00" == value || "0" == value)
    {
        conf.setValue(QString::number(id), "01");
    }
    else
    {
        conf.setValue(QString::number(id), "00");
    }

    //Update String
    temp_config.names = conf.childKeys();
    foreach(const QString &key, temp_config.names)
    {
        temp_config.ids_string << conf.value(key).toString();
    }
    conf.endGroup();

    conf_string = build_string(&temp_config);

    qDebug() << conf_string;

}

void output_op_mode(uint id, QString val)
{
    configuration_id temp_config;


    conf.sync();
    conf.beginGroup("Plant-Cfg");

    // Modify status in config
    conf.setValue(QString::number(id), val);

    //Update String
    temp_config.names = conf.childKeys();
    foreach(const QString &key, temp_config.names)
    {
        temp_config.ids_string << conf.value(key).toString();
    }
    conf.endGroup();

    conf_string = build_string(&temp_config);

    qDebug() << conf_string;

}


void output_token_transfer(bool val)
{
    configuration_id temp_config;
//    uint id = 0x0D03; //Token transfer

    conf.sync();
    conf.beginGroup("Plant-Cfg");

    // Modify status in config
//    QString value = conf.value(QString::number(id)).toString();

    if(true == val)
    {
        conf.setValue("0D03", "02");
        conf.setValue("0D04", "02");
    }
    else
    {
        conf.setValue("0D03", "00");
        conf.setValue("0D04", "00");
    }

    //Update String
    temp_config.names = conf.childKeys();
    foreach(const QString &key, temp_config.names)
    {
        temp_config.ids_string << conf.value(key).toString();
    }
    conf.endGroup();

    conf_string = build_string(&temp_config);

    qDebug() << conf_string;

}

void synch_config_string()
{
    configuration_id temp_config;
    conf.sync();
    conf.beginGroup("Plant-Cfg");
    bool ok;
    //Update String
    temp_config.names = conf.childKeys();
    foreach(const QString &key, temp_config.names)
    {
        if("" != getParamValue(key.toInt(&ok, 16)))
        {
            if(conf.value(key).toString() != getParamValue(key.toInt(&ok, 16)))
            {
                qDebug() << "Config values are different " << conf.value(key).toString() << getParamValue(key.toInt(&ok, 16));
                conf.setValue(key, getParamValue(key.toInt(&ok, 16)));
            }
        }
    }
    conf.endGroup();
}

void synch_output_state()
{
    configuration_id temp_config;
    conf.sync();
    conf.beginGroup("Plant-Cfg");

    //Update String
    temp_config.names = conf.childKeys();

    //SYNCH MOTORS
    conf.setValue("3602", getParamValue(0x3000));
    conf.setValue("3603", getParamValue(0x3010));

    conf.setValue("4601", getParamValue(0x4000));
    conf.setValue("4602", getParamValue(0x4010));
    conf.setValue("4603", getParamValue(0x4020));
    conf.setValue("4604", getParamValue(0x4030));

    conf.setValue("9601", getParamValue(0x9000));
    conf.setValue("9602", getParamValue(0x9010));
    conf.setValue("9603", getParamValue(0x9020));


    //Update String
    temp_config.names = conf.childKeys();
    foreach(const QString &key, temp_config.names)
    {
        temp_config.ids_string << conf.value(key).toString();
    }
    conf.endGroup();

    conf_string = build_string(&temp_config);

    qDebug() << conf_string;
}

QString get_config_string()
{
    QString ret;
    mutex.lock();
    ret = conf_string;
    mutex.unlock();
    return ret;
}

QString get_id_state(uint id)
{
    QString value;

    configuration_id temp_config;
    conf.sync();
    conf.beginGroup("Plant-Cfg");

    //Update String
    value = conf.value(QString::number(id)).toString();
    conf.endGroup();


    return value;
}
