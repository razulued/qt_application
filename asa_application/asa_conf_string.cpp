#include "asa_conf_string.h"
#include "QDebug"
#include <QMutex>
#include "parameters.h"
#include <QSettings>
#include <QDir>

QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);

int demo_percentaje = 0;

QString conf_string;
QMutex mutex;
bool calibration_needed = false;
QString calib_string;
QStringList one_time_transmit;

configuration_id plant_config;
void init_out_string()
{
    mutex.lock();

    conf.sync();
    conf.beginGroup("Plant-Cfg");
    qDebug() << "path" << QDir::currentPath();
    plant_config.names = conf.childKeys();
    foreach(const QString &key, plant_config.names)
    {
        plant_config.ids_string << conf.value(key).toString();
    }

    conf.endGroup();

    conf_string = build_out_string(&plant_config);
    qDebug() << conf_string;

    mutex.unlock();
}

QString build_out_string(configuration_id *conf)
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
    qDebug() << "0x0402" << getParamValue_base_units(0x0402);
    qDebug() << "0x2001" << getParamValue_base_units(0x2001);

}

void output_control_toggle(uint id)
{
    mutex.lock();
    configuration_id temp_config;

    conf.sync();
    conf.beginGroup("Plant-Cfg");

    // Modify status in config
    QString value = conf.value(QString::number(id, 16).toUpper()).toString();
//    qDebug() << "EL VALUE: " << value;
    if("00" == value || "0" == value)
    {
//        qDebug() << "CHANGING: " << QString::number(id, 16).toUpper() << "1";
        conf.setValue(QString::number(id, 16).toUpper(), "01");
    }
    else
    {
//        qDebug() << "CHANGING: " << QString::number(id, 16).toUpper() << "0";
        conf.setValue(QString::number(id, 16).toUpper(), "00");
    }

    //Update String
    temp_config.names = conf.childKeys();
    foreach(const QString &key, temp_config.names)
    {
        temp_config.ids_string << conf.value(key).toString();
    }
    conf.endGroup();

    conf_string = build_out_string(&temp_config);

    qDebug() << conf_string;
    mutex.unlock();
}

void output_op_mode(QString id, QString val)
{
    mutex.lock();
    configuration_id temp_config;


    conf.sync();
    conf.beginGroup("Plant-Cfg");

    // Modify status in config
    //conf.setValue(QString::number(id), val);
    conf.setValue(id, val);
    //Update String
    temp_config.names = conf.childKeys();
    foreach(const QString &key, temp_config.names)
    {
        temp_config.ids_string << conf.value(key).toString();
    }
    conf.endGroup();

    conf_string = build_out_string(&temp_config);

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

    conf_string = build_out_string(&temp_config);

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

    conf_string = build_out_string(&temp_config);

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
        else if("" != getParamValue_base_units(key.toInt(&ok, 16)))
        {
            if(conf.value(key).toString() != getParamValue_base_units(key.toInt(&ok, 16)))
            {
                qDebug() << "Config values are different " << conf.value(key).toString() << getParamValue_base_units(key.toInt(&ok, 16));
                conf.setValue(key, getParamValue_base_units(key.toInt(&ok, 16)));
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

    //CARCAMO
    conf.setValue("3602", getParamValue_base_units(0x3000));
    conf.setValue("3603", getParamValue_base_units(0x3010));

    //REGULADOR
    conf.setValue("3E02", getParamValue_base_units(0x3800));
    conf.setValue("3E03", getParamValue_base_units(0x3810));

    conf.setValue("4601", getParamValue_base_units(0x4000));
    conf.setValue("4602", getParamValue_base_units(0x4010));
    conf.setValue("4603", getParamValue_base_units(0x4020));
    conf.setValue("4604", getParamValue_base_units(0x4030));

    conf.setValue("9601", getParamValue_base_units(0x9000));
    conf.setValue("9602", getParamValue_base_units(0x9010));
    conf.setValue("9603", getParamValue_base_units(0x9020));

    conf.setValue("9701", getParamValue_base_units(0x9080));

    conf.setValue("9640", getParamValue_base_units(0x9100));
    conf.setValue("9641", getParamValue_base_units(0x9101));
    conf.setValue("9642", getParamValue_base_units(0x9102));


    //Update String
    temp_config.names = conf.childKeys();
    foreach(const QString &key, temp_config.names)
    {
        temp_config.ids_string << conf.value(key).toString();
    }
    conf.endGroup();

    conf_string = build_out_string(&temp_config);

    qDebug() << conf_string;
    mutex.unlock();
}

QString get_config_string()
{
    QString ret;
    static uint last_calibration_request = 0;


    mutex.lock();
//    save_calibrations();

    if(0 == getParamValue(0x0A05).toInt())
    {
        if(2 == last_calibration_request)
        {
            // Write was requested, write file in the transition from 2 to 0
            save_calibrations();
        }
        else if(false == calibration_needed)
        {
            ret = conf_string;
        }
        else
        {
            calibration_needed = false;
            ret = calib_string;

            qDebug() << "Calibration sent: " << ret;
        }
    }
    else if(1 == getParamValue(0x0A05).toInt())
    {
        // load calibration string
        get_calibrations_and_set_config_str();
        calibration_needed = false;

        // Send calibration string
        ret = calib_string;
    }

    last_calibration_request = getParamValue(0x0A05).toInt();

    uint i = 0;
    for(i = 0; i < (uint)one_time_transmit.length(); i++)
    {
        ret.append(one_time_transmit.at(i));
    }
//    qDebug() << "STRING: " << one_time_transmit;
//    qDebug() << "conf: " << conf_string;
    one_time_transmit.clear();

    // For DEMO
    QString percent_string = "A001:0|A000:"+QString::number(demo_percentaje,16).toUpper();
    ret.append(percent_string);

//    qDebug() << "SENDING: " << ret;
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
    if(motor_control =="3602"){    return getParamValue_base_units(0x3000).toInt();}
    else if(motor_control =="3603"){return getParamValue_base_units(0x3010).toInt();}

    else if(motor_control =="3E02" || motor_control =="3e02"){return getParamValue_base_units(0x3800).toInt();}
    else if(motor_control =="3E03" || motor_control =="3e03"){return getParamValue_base_units(0x3810).toInt();}

    else if(motor_control =="4601"){return getParamValue_base_units(0x4000).toInt();}
    else if(motor_control =="4602"){return getParamValue_base_units(0x4010).toInt();}
    else if(motor_control =="4603"){return getParamValue_base_units(0x4020).toInt();}
    else if(motor_control =="4604"){return getParamValue_base_units(0x4030).toInt();}

    else if(motor_control =="9601"){return getParamValue_base_units(0x9000).toInt();}
    else if(motor_control =="9602"){return getParamValue_base_units(0x9010).toInt();}
    else if(motor_control =="9603"){return getParamValue_base_units(0x9020).toInt();}

    else if(motor_control =="9701"){return getParamValue_base_units(0x9080).toInt();}

    else if(motor_control =="9640"){return getParamValue_base_units(0x9100).toInt();}
    else if(motor_control =="9641"){return getParamValue_base_units(0x9101).toInt();}
    else if(motor_control =="9642"){return getParamValue_base_units(0x9102).toInt();}
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

void get_calibrations_and_set_config_str()
{
    conf.sync();
    conf.beginGroup("Calibrations");

    QString calibrations;

    calibrations += "0D03:2";
    calibrations += "|0D04:2";
    //Carcamo
    calibrations += "|3400:" + conf.value("3400").toString();
    calibrations += "|3401:" + conf.value("3401").toString();
    calibrations += "|3402:" + conf.value("3402").toString();
    calibrations += "|3403:" + conf.value("3403").toString();
    calibrations += "|3501:" + conf.value("3501").toString();
    calibrations += "|3502:" + conf.value("3502").toString();
    calibrations += "|2403:" + conf.value("2403").toString();

    //Regulador
    calibrations += "|3C00:" + conf.value("3C00").toString();
    calibrations += "|3C01:" + conf.value("3C01").toString();
    calibrations += "|3C02:" + conf.value("3C02").toString();
    calibrations += "|3C03:" + conf.value("3C03").toString();
    calibrations += "|3D01:" + conf.value("3D01").toString();
    calibrations += "|3D02:" + conf.value("3D02").toString();
    calibrations += "|2402:" + conf.value("2402").toString();

    calibrations += "|4400:" + conf.value("4400").toString();
    calibrations += "|4401:" + conf.value("4401").toString();
    calibrations += "|4501:" + conf.value("4501").toString();
    calibrations += "|4502:" + conf.value("4502").toString();
    calibrations += "|4540:" + conf.value("4540").toString();
    calibrations += "|4541:" + conf.value("4541").toString();

//    calibrations += "|4600:" + conf.value("4600").toString();

    calibrations += "|9400:" + conf.value("9400").toString();
    calibrations += "|9401:" + conf.value("9401").toString();
    calibrations += "|9402:" + conf.value("9402").toString();
    calibrations += "|9403:" + conf.value("9403").toString();
    calibrations += "|9404:" + conf.value("9404").toString();

    calibrations += "|9500:" + conf.value("9500").toString();
    calibrations += "|9501:" + conf.value("9501").toString();
    calibrations += "|9502:" + conf.value("9502").toString();
    calibrations += "|9503:" + conf.value("9503").toString();
    calibrations += "|9504:" + conf.value("9504").toString();

    // carcamo
    calibrations += "|1006:" + conf.value("1006").toString();
    calibrations += "|1007:" + conf.value("1007").toString();
    calibrations += "|1008:" + conf.value("1008").toString();
    calibrations += "|1009:" + conf.value("1009").toString();
    calibrations += "|100A:" + conf.value("100A").toString();
    calibrations += "|100B:" + conf.value("100B").toString();
    // regulador
    calibrations += "|1126:" + conf.value("1126").toString();
    calibrations += "|1127:" + conf.value("1127").toString();
    calibrations += "|1128:" + conf.value("1128").toString();
    calibrations += "|1129:" + conf.value("1129").toString();
    calibrations += "|112A:" + conf.value("112A").toString();
    calibrations += "|112B:" + conf.value("112B").toString();

    // carcamo
    calibrations += "|101E:" + conf.value("101E").toString();
    calibrations += "|101F:" + conf.value("101F").toString();
    calibrations += "|1020:" + conf.value("1020").toString();
    calibrations += "|1021:" + conf.value("1021").toString();
    calibrations += "|1022:" + conf.value("1022").toString();
    calibrations += "|1023:" + conf.value("1023").toString();
    // regulador
    calibrations += "|113E:" + conf.value("113E").toString();
    calibrations += "|113F:" + conf.value("113F").toString();
    calibrations += "|1140:" + conf.value("1140").toString();
    calibrations += "|1141:" + conf.value("1141").toString();
    calibrations += "|1142:" + conf.value("1142").toString();
    calibrations += "|1143:" + conf.value("1143").toString();


    calibrations += "|103C:" + conf.value("103C").toString();
    calibrations += "|103D:" + conf.value("103D").toString();
    calibrations += "|103E:" + conf.value("103E").toString();
    calibrations += "|103F:" + conf.value("103F").toString();
    calibrations += "|1040:" + conf.value("1040").toString();
    calibrations += "|1041:" + conf.value("1041").toString();

    calibrations += "|1042:" + conf.value("1042").toString();
    calibrations += "|1043:" + conf.value("1043").toString();
    calibrations += "|1044:" + conf.value("1044").toString();
    calibrations += "|1045:" + conf.value("1045").toString();
    calibrations += "|1046:" + conf.value("1046").toString();
    calibrations += "|1047:" + conf.value("1047").toString();

    calibrations += "|1048:" + conf.value("1048").toString();
    calibrations += "|1049:" + conf.value("1049").toString();
    calibrations += "|104A:" + conf.value("104A").toString();
    calibrations += "|104B:" + conf.value("104B").toString();
    calibrations += "|104C:" + conf.value("104C").toString();
    calibrations += "|104D:" + conf.value("104D").toString();

    calibrations += "|1060:" + conf.value("1060").toString();
    calibrations += "|1061:" + conf.value("1061").toString();
    calibrations += "|1062:" + conf.value("1062").toString();
    calibrations += "|1063:" + conf.value("1063").toString();
    calibrations += "|1064:" + conf.value("1064").toString();
    calibrations += "|1065:" + conf.value("1065").toString();

    calibrations += "|1090:" + conf.value("1090").toString();
    calibrations += "|1091:" + conf.value("1091").toString();
    calibrations += "|1092:" + conf.value("1092").toString();
    calibrations += "|1093:" + conf.value("1093").toString();
    calibrations += "|1094:" + conf.value("1094").toString();
    calibrations += "|1095:" + conf.value("1095").toString();

    calibrations += "|109C:" + conf.value("109C").toString();
    calibrations += "|109D:" + conf.value("109D").toString();
    calibrations += "|109E:" + conf.value("109E").toString();
    calibrations += "|109F:" + conf.value("109F").toString();
    calibrations += "|10A0:" + conf.value("10A0").toString();
    calibrations += "|10A1:" + conf.value("10A1").toString();

    //Filtro
    calibrations += "|10A2:" + conf.value("10A2").toString();
    calibrations += "|10A3:" + conf.value("10A3").toString();
    calibrations += "|10A4:" + conf.value("10A4").toString();
    calibrations += "|10A5:" + conf.value("10A5").toString();
    calibrations += "|10A6:" + conf.value("10A6").toString();
    calibrations += "|10A7:" + conf.value("10A7").toString();

    calibrations += "|10A8:" + conf.value("10A8").toString();
    calibrations += "|10A9:" + conf.value("10A9").toString();
    calibrations += "|10AA:" + conf.value("10AA").toString();
    calibrations += "|10AB:" + conf.value("10AB").toString();
    calibrations += "|10AC:" + conf.value("10AC").toString();
    calibrations += "|10AD:" + conf.value("10AD").toString();

    calibrations += "|10AE:" + conf.value("10AE").toString();
    calibrations += "|10AF:" + conf.value("10AF").toString();
    calibrations += "|10B0:" + conf.value("10B0").toString();
    calibrations += "|10B1:" + conf.value("10B1").toString();
    calibrations += "|10B2:" + conf.value("10B2").toString();
    calibrations += "|10B3:" + conf.value("10B3").toString();

    calibrations += "|10B4:" + conf.value("10B4").toString();
    calibrations += "|10B5:" + conf.value("10B5").toString();
    calibrations += "|10B6:" + conf.value("10B6").toString();
    calibrations += "|10B7:" + conf.value("10B7").toString();
    calibrations += "|10B8:" + conf.value("10B8").toString();
    calibrations += "|10B9:" + conf.value("10B9").toString();

    calibrations += "|10D8:" + conf.value("10D8").toString();
    calibrations += "|10D9:" + conf.value("10D9").toString();
    calibrations += "|10DA:" + conf.value("10DA").toString();
    calibrations += "|10DB:" + conf.value("10DB").toString();
    calibrations += "|10DC:" + conf.value("10DC").toString();
    calibrations += "|10DD:" + conf.value("10DD").toString();

    calibrations += "|10DE:" + conf.value("10DE").toString();
    calibrations += "|10DF:" + conf.value("10DF").toString();
    calibrations += "|10E0:" + conf.value("10E0").toString();
    calibrations += "|10E1:" + conf.value("10E1").toString();
    calibrations += "|10E2:" + conf.value("10E2").toString();
    calibrations += "|10E3:" + conf.value("10E3").toString();

    calibrations += "|10EA:" + conf.value("10EA").toString();
    calibrations += "|10EB:" + conf.value("10EB").toString();
    calibrations += "|10EC:" + conf.value("10EC").toString();
    calibrations += "|10ED:" + conf.value("10ED").toString();
    calibrations += "|10EE:" + conf.value("10EE").toString();
    calibrations += "|10EF:" + conf.value("10EF").toString();

    calibrations += "|10F0:" + conf.value("10F0").toString();
    calibrations += "|10F1:" + conf.value("10F1").toString();
    calibrations += "|10F2:" + conf.value("10F2").toString();
    calibrations += "|10F3:" + conf.value("10F3").toString();
    calibrations += "|10F4:" + conf.value("10F4").toString();
    calibrations += "|10F5:" + conf.value("10F5").toString();

    calibrations += "|10FC:" + conf.value("10FC").toString();
    calibrations += "|10FD:" + conf.value("10FD").toString();
    calibrations += "|10FE:" + conf.value("10FE").toString();
    calibrations += "|10FF:" + conf.value("10FF").toString();
    calibrations += "|1100:" + conf.value("1100").toString();
    calibrations += "|1101:" + conf.value("1101").toString();

    calibrations += "|1102:" + conf.value("1102").toString();
    calibrations += "|1103:" + conf.value("1103").toString();
    calibrations += "|1104:" + conf.value("1104").toString();
    calibrations += "|1105:" + conf.value("1105").toString();
    calibrations += "|1106:" + conf.value("1106").toString();
    calibrations += "|1107:" + conf.value("1107").toString();

    set_calibration(calibrations);

    qDebug() << "CALIBRATION: " << calibrations;

    conf.endGroup();
}

void save_calibrations()
{
    conf.sync();
    conf.beginGroup("Calibrations");

    //Carcamo
    conf.setValue("3400", getParamValue_RAW(0x3400));
    conf.setValue("3401", getParamValue_RAW(0x3401));
    conf.setValue("3402", getParamValue_RAW(0x3402));
    conf.setValue("3403", getParamValue_RAW(0x3403));
    conf.setValue("3501", getParamValue_RAW(0x3501));
    conf.setValue("3502", getParamValue_RAW(0x3502));
    conf.setValue("2403", getParamValue_RAW(0x2403));

    //Regulador
    conf.setValue("3C00", getParamValue_RAW(0x3C00));
    conf.setValue("3C01", getParamValue_RAW(0x3C01));
    conf.setValue("3C02", getParamValue_RAW(0x3C02));
    conf.setValue("3C03", getParamValue_RAW(0x3C03));
    conf.setValue("3D01", getParamValue_RAW(0x3D01));
    conf.setValue("3D02", getParamValue_RAW(0x3D02));
    conf.setValue("2402", getParamValue_RAW(0x2402));

    conf.setValue("4400", getParamValue_RAW(0x4400));
    conf.setValue("4401", getParamValue_RAW(0x4401));
    conf.setValue("4501", getParamValue_RAW(0x4501));
    conf.setValue("4502", getParamValue_RAW(0x4502));
    conf.setValue("4540", getParamValue_RAW(0x4540));
    conf.setValue("4541", getParamValue_RAW(0x4541));

//    conf.setValue("4600", getParamValue_RAW_base_units(0x4600).toDouble());

//    ui->control_5400->setValue(getParamValue_RAW_base_units(0x5400).toDouble());
//    ui->control_5401->setValue(getParamValue_RAW_base_units(0x5401).toDouble());

    conf.setValue("9400", getParamValue_RAW(0x9400));
    conf.setValue("9401", getParamValue_RAW(0x9401));
    conf.setValue("9402", getParamValue_RAW(0x9402));
    conf.setValue("9403", getParamValue_RAW(0x9403));
    conf.setValue("9404", getParamValue_RAW(0x9404));
    conf.setValue("9500", getParamValue_RAW(0x9500));
    conf.setValue("9501", getParamValue_RAW(0x9501));
    conf.setValue("9502", getParamValue_RAW(0x9502));
    conf.setValue("9503", getParamValue_RAW(0x9503));
    conf.setValue("9504", getParamValue_RAW(0x9504));

    // ALARMAS
    // Carcamo
    conf.setValue("1006", getParamValue_RAW(0x1006));
    conf.setValue("1007", getParamValue_RAW(0x1007));
    conf.setValue("1008", getParamValue_RAW(0x1008));
    conf.setValue("1009", getParamValue_RAW(0x1009));
    conf.setValue("100A", getParamValue_RAW(0x100A));
    conf.setValue("100B", getParamValue_RAW(0x100B));
    // regulador
    conf.setValue("1126", getParamValue_RAW(0x1126));
    conf.setValue("1127", getParamValue_RAW(0x1127));
    conf.setValue("1128", getParamValue_RAW(0x1128));
    conf.setValue("1129", getParamValue_RAW(0x1129));
    conf.setValue("112A", getParamValue_RAW(0x112A));
    conf.setValue("112B", getParamValue_RAW(0x112B));

    // Carcamo
    conf.setValue("101E", getParamValue_RAW(0x101E));
    conf.setValue("101F", getParamValue_RAW(0x101F));
    conf.setValue("1020", getParamValue_RAW(0x1020));
    conf.setValue("1021", getParamValue_RAW(0x1021));
    conf.setValue("1022", getParamValue_RAW(0x1022));
    conf.setValue("1023", getParamValue_RAW(0x1023));
    // regulador
    conf.setValue("113E", getParamValue_RAW(0x113E));
    conf.setValue("113F", getParamValue_RAW(0x113F));
    conf.setValue("1140", getParamValue_RAW(0x1140));
    conf.setValue("1141", getParamValue_RAW(0x1141));
    conf.setValue("1142", getParamValue_RAW(0x1142));
    conf.setValue("1143", getParamValue_RAW(0x1143));


    conf.setValue("103C", getParamValue_RAW(0x103C));
    conf.setValue("103D", getParamValue_RAW(0x103D));
    conf.setValue("103E", getParamValue_RAW(0x103E));
    conf.setValue("103F", getParamValue_RAW(0x103F));
    conf.setValue("1040", getParamValue_RAW(0x1040));
    conf.setValue("1041", getParamValue_RAW(0x1041));

    conf.setValue("1042", getParamValue_RAW(0x1042));
    conf.setValue("1043", getParamValue_RAW(0x1043));
    conf.setValue("1044", getParamValue_RAW(0x1044));
    conf.setValue("1045", getParamValue_RAW(0x1045));
    conf.setValue("1046", getParamValue_RAW(0x1046));
    conf.setValue("1047", getParamValue_RAW(0x1047));

    conf.setValue("1048", getParamValue_RAW(0x1048));
    conf.setValue("1049", getParamValue_RAW(0x1049));
    conf.setValue("104A", getParamValue_RAW(0x104A));
    conf.setValue("104B", getParamValue_RAW(0x104B));
    conf.setValue("104C", getParamValue_RAW(0x104C));
    conf.setValue("104D", getParamValue_RAW(0x104D));

    conf.setValue("1060", getParamValue_RAW(0x1060));
    conf.setValue("1061", getParamValue_RAW(0x1061));
    conf.setValue("1062", getParamValue_RAW(0x1062));
    conf.setValue("1063", getParamValue_RAW(0x1063));
    conf.setValue("1064", getParamValue_RAW(0x1064));
    conf.setValue("1065", getParamValue_RAW(0x1065));

    conf.setValue("1090", getParamValue_RAW(0x1090));
    conf.setValue("1091", getParamValue_RAW(0x1091));
    conf.setValue("1092", getParamValue_RAW(0x1092));
    conf.setValue("1093", getParamValue_RAW(0x1093));
    conf.setValue("1094", getParamValue_RAW(0x1094));
    conf.setValue("1095", getParamValue_RAW(0x1095));

    conf.setValue("109C", getParamValue_RAW(0x109C));
    conf.setValue("109D", getParamValue_RAW(0x109D));
    conf.setValue("109E", getParamValue_RAW(0x109E));
    conf.setValue("109F", getParamValue_RAW(0x109F));
    conf.setValue("10A0", getParamValue_RAW(0x10A0));
    conf.setValue("10A1", getParamValue_RAW(0x10A1));

    //Filtro
    conf.setValue("10A2", getParamValue_RAW(0x10A2));
    conf.setValue("10A3", getParamValue_RAW(0x10A3));
    conf.setValue("10A4", getParamValue_RAW(0x10A4));
    conf.setValue("10A5", getParamValue_RAW(0x10A5));
    conf.setValue("10A6", getParamValue_RAW(0x10A6));
    conf.setValue("10A7", getParamValue_RAW(0x10A7));

    conf.setValue("10A8", getParamValue_RAW(0x10A8));
    conf.setValue("10A9", getParamValue_RAW(0x10A9));
    conf.setValue("10AA", getParamValue_RAW(0x10AA));
    conf.setValue("10AB", getParamValue_RAW(0x10AB));
    conf.setValue("10AC", getParamValue_RAW(0x10AC));
    conf.setValue("10AD", getParamValue_RAW(0x10AD));

    conf.setValue("10AE", getParamValue_RAW(0x10AE));
    conf.setValue("10AF", getParamValue_RAW(0x10AF));
    conf.setValue("10B0", getParamValue_RAW(0x10B0));
    conf.setValue("10B1", getParamValue_RAW(0x10B1));
    conf.setValue("10B2", getParamValue_RAW(0x10B2));
    conf.setValue("10B3", getParamValue_RAW(0x10B3));

    conf.setValue("10B4", getParamValue_RAW(0x10B4));
    conf.setValue("10B5", getParamValue_RAW(0x10B5));
    conf.setValue("10B6", getParamValue_RAW(0x10B6));
    conf.setValue("10B7", getParamValue_RAW(0x10B7));
    conf.setValue("10B8", getParamValue_RAW(0x10B8));
    conf.setValue("10B9", getParamValue_RAW(0x10B9));

    conf.setValue("10D8", getParamValue_RAW(0x10D8));
    conf.setValue("10D9", getParamValue_RAW(0x10D9));
    conf.setValue("10DA", getParamValue_RAW(0x10DA));
    conf.setValue("10DB", getParamValue_RAW(0x10DB));
    conf.setValue("10DC", getParamValue_RAW(0x10DC));
    conf.setValue("10DD", getParamValue_RAW(0x10DD));

    conf.setValue("10DE", getParamValue_RAW(0x10DE));
    conf.setValue("10DF", getParamValue_RAW(0x10DF));
    conf.setValue("10E0", getParamValue_RAW(0x10E0));
    conf.setValue("10E1", getParamValue_RAW(0x10E1));
    conf.setValue("10E2", getParamValue_RAW(0x10E2));
    conf.setValue("10E3", getParamValue_RAW(0x10E3));

    conf.setValue("10EA", getParamValue_RAW(0x10EA));
    conf.setValue("10EB", getParamValue_RAW(0x10EB));
    conf.setValue("10EC", getParamValue_RAW(0x10EC));
    conf.setValue("10ED", getParamValue_RAW(0x10ED));
    conf.setValue("10EE", getParamValue_RAW(0x10EE));
    conf.setValue("10EF", getParamValue_RAW(0x10EF));

    conf.setValue("10F0", getParamValue_RAW(0x10F0));
    conf.setValue("10F1", getParamValue_RAW(0x10F1));
    conf.setValue("10F2", getParamValue_RAW(0x10F2));
    conf.setValue("10F3", getParamValue_RAW(0x10F3));
    conf.setValue("10F4", getParamValue_RAW(0x10F4));
    conf.setValue("10F5", getParamValue_RAW(0x10F5));

    conf.setValue("10FC", getParamValue_RAW(0x10FC));
    conf.setValue("10FD", getParamValue_RAW(0x10FD));
    conf.setValue("10FE", getParamValue_RAW(0x10FE));
    conf.setValue("10FF", getParamValue_RAW(0x10FF));
    conf.setValue("1100", getParamValue_RAW(0x1100));
    conf.setValue("1101", getParamValue_RAW(0x1101));

    conf.setValue("1102", getParamValue_RAW(0x1102));
    conf.setValue("1103", getParamValue_RAW(0x1103));
    conf.setValue("1104", getParamValue_RAW(0x1104));
    conf.setValue("1105", getParamValue_RAW(0x1105));
    conf.setValue("1106", getParamValue_RAW(0x1106));
    conf.setValue("1107", getParamValue_RAW(0x1107));
    conf.endGroup();

}

void demo_set_percentaje(int per)
{
    if(per > 100)
    {
        per = 100;
    }
    if(per < 0)
    {
        per = 0;
    }
    qDebug() << "-------Valve at "<< per << "%";
    demo_percentaje = 100 - per;
}
