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
    }
    conf.endGroup();

    qDebug() << name;
    int i = 0;
    for(i = 0; i < process_conf.names.size(); i++)
    {
        qDebug() << process_conf.names[i]<<": "<<process_conf.ids[i];
    }
}

void store_ASA_conf(QString gpo, QString name, int value)
{
    QSettings conf(QDir::currentPath() + "/ASA_conf.ini", QSettings::IniFormat);
    conf.sync();
    conf.beginGroup(gpo);
    conf.setValue(name, value);
    conf.endGroup();
    conf.sync();
}

int load_ASA_conf(QString gpo, QString name)
{
    int ret = 0;
    QSettings conf(QDir::currentPath() + "/ASA_conf.ini", QSettings::IniFormat);
    conf.sync();
    conf.beginGroup(gpo);
    ret = conf.value(name, 0).toInt();
    conf.endGroup();
    conf.sync();

    return ret;
}


configuration_id configuration::get_config()
{
    return process_conf;
}
