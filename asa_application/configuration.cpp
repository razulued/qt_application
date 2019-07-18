#include "configuration.h"
#include <QSettings>
#include <QDir>
#include <QDebug>

configuration::configuration(QString name)
{
    load_configuration(name);
}


void configuration::load_configuration(QString name)
{
    bool test;
    QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
    conf.sync();


    conf.beginGroup(name);
    process_conf.names = conf.childKeys();
    foreach(const QString &key, process_conf.names)
    {
        process_conf.ids << conf.value(key).toString().toInt(&test,16);
        process_conf.ids_string << conf.value(key).toString();
    }
    conf.endGroup();
}

QString configuration::get_value(const QString &name, const QString &key)
{
    QString ret;
    QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
    conf.sync();


    conf.beginGroup(name);
    ret = conf.value(key).toString();
    conf.endGroup();

    return ret;
}


configuration_id configuration::get_config()
{
    return process_conf;
}

configuration_id configuration::get_id_conf_from_module(QString name, elemnt_type type)
{
    QString module_name;
    QStringList values;
    configuration_id temp_conf;
    bool ok;

    if(false == QDir("conf").exists())
    {
        QDir().mkdir("conf");
    }
    else
    {
        /* Folder exist, get dir names and hash configurations */
        if(QDir().cd("conf"))
        {
            module_name = "./conf/"+ name + "/conf.csv";
            QFile file(module_name);
            if(file.open(QFile::ReadOnly))
            {
                QTextStream stream(&file);
                // Discard First Line
                stream.readLine();
                while(!stream.atEnd())
                {
                    values = stream.readLine().split(",");

                    //Only append items from the same type
                    if(type == values.at(2).at(0).toLatin1() - 0x30 ) /* Get first character */
                    {
                        temp_conf.names << values.at(1);
                        temp_conf.ids << values.at(0).toInt(&ok, 16);
                        temp_conf.ids_string << values.at(0);
                    }
                }
                qDebug() << "HERE:" << temp_conf.ids;
            }
            file.close();
        }
    }
    return temp_conf;
}

void configuration::saveSettings(const QString &name, const QString &key, const QString &value)
{
    QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
    conf.sync();
    conf.beginGroup(name);
    conf.setValue(key, value);
    conf.endGroup();
}
