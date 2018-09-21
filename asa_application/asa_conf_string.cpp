#include "asa_conf_string.h"
#include "QDebug"
#include <QMutex>
#include "parameters.h"
#include <QSettings>
#include <QDir>

QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);

QString conf_string;
QMutex mutex;
bool calibration_needed = false;
QString calib_string;
QStringList one_time_transmit;

configuration_id plant_config;
void init_plat_config()
{
    mutex.lock();

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

    mutex.unlock();
}

QString build_string(configuration_id *conf)
{
    int i = 0;
    QString temp;
    // Plant Config
    for(i = 0; i < conf->names.length(); i++)
    {
        temp += conf->names.at(i) + ":" + conf->ids_string.at(i) + "|";
    }

    return temp;
}

void get_plant_config()
{
    qDebug() << "0x0402" << getParamValue(0x0402);
    qDebug() << "0x2001" << getParamValue(0x2001);

}

void output_control_toggle(uint id)
{
    mutex.lock();
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
    mutex.unlock();

}

void output_op_mode(uint id, QString val)
{
    mutex.lock();
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
    mutex.unlock();

}


void output_token_transfer(bool val)
{
    mutex.lock();
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
    mutex.unlock();

}

void emergency_stop(bool val)
{
    mutex.lock();
    configuration_id temp_config;
//    uint id = 0x0D03; //Token transfer

    conf.sync();
    conf.beginGroup("Plant-Cfg");

    // Modify status in config
//    QString value = conf.value(QString::number(id)).toString();

    if(true == val)
    {
        conf.setValue("0902", "01");
    }
    else
    {
        conf.setValue("0902", "00");
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
    mutex.unlock();

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
        if(key.toInt(&ok, 16) == 0x0902)
        {
            //do not synch emergency stop
        }
        else if("" != getParamValue(key.toInt(&ok, 16)))
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
    // Skip synchcronization is system is stop
    if(get_id_state("0902").toInt() == 1)
    {
        return;
    }

    mutex.lock();
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

    conf.setValue("9701", getParamValue(0x9080));

    conf.setValue("9640", getParamValue(0x9100));
    conf.setValue("9641", getParamValue(0x9101));
    conf.setValue("9642", getParamValue(0x9102));


    //Update String
    temp_config.names = conf.childKeys();
    foreach(const QString &key, temp_config.names)
    {
        temp_config.ids_string << conf.value(key).toString();
    }
    conf.endGroup();

    conf_string = build_string(&temp_config);

    qDebug() << conf_string;
    mutex.unlock();
}

QString get_config_string()
{
    QString ret;
    mutex.lock();
    if(false == calibration_needed)
    {
        ret = conf_string;
    }
    else
    {
        calibration_needed = false;
        ret = calib_string;
    }

    uint i = 0;
    for(i = 0; i < one_time_transmit.length(); i++)
    {
        ret.append(one_time_transmit.at(i));
    }
    one_time_transmit.clear();
    mutex.unlock();
    return ret;
}

QString get_id_state(QString str_id)
{
    QString value;

    configuration_id temp_config;
    conf.sync();
    conf.beginGroup("Plant-Cfg");

    //Update String
    value = conf.value(str_id).toString();
    conf.endGroup();


    return value;
}

uint motor_state(QString motor_control)
{
//    qDebug() << "motor_control " << motor_control;
    if(motor_control =="3602"){    return getParamValue(0x3000).toInt();}
    else if(motor_control =="3603"){return getParamValue(0x3010).toInt();}

    else if(motor_control =="4601"){return getParamValue(0x4000).toInt();}
    else if(motor_control =="4602"){return getParamValue(0x4010).toInt();}
    else if(motor_control =="4603"){return getParamValue(0x4020).toInt();}
    else if(motor_control =="4604"){return getParamValue(0x4030).toInt();}

    else if(motor_control =="9601"){return getParamValue(0x9000).toInt();}
    else if(motor_control =="9602"){return getParamValue(0x9010).toInt();}
    else if(motor_control =="9603"){return getParamValue(0x9020).toInt();}

    else if(motor_control =="9701"){return getParamValue(0x9080).toInt();}

    else if(motor_control =="9640"){return getParamValue(0x9100).toInt();}
    else if(motor_control =="9641"){return getParamValue(0x9101).toInt();}
    else if(motor_control =="9642"){return getParamValue(0x9102).toInt();}
    return 0;
}

void set_calibration(QString str)
{
    calib_string = str;
    calibration_needed = true;
}

void add_to_one_time_transmit(QString str)
{
    one_time_transmit.append(str);
}
