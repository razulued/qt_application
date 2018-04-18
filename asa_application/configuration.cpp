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
    QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
    conf.sync();


    conf.beginGroup(name);

//    const QStringList regulador_keys = conf.childKeys();
    process_conf.names = conf.childKeys();
    foreach(const QString &key, process_conf.names)
    {
        process_conf.ids << conf.value(key).toInt();
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

void configuration::saveSettings(const QString &name, const QString &key, const QString &value)
{
    QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);

    conf.beginGroup(name);
    conf.setValue(key, value);
    conf.endGroup();
}
