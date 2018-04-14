#include "asa_conf_string.h"
#include "QDebug"
#include <QMutex>

configuration_id plant_config;
QString conf_string;
QMutex mutex;

void init_plat_config()
{
    configuration *config = new configuration("Plant-Cfg");
    plant_config = config->get_config();
    build_string();
    qDebug() << conf_string;
}

QString build_string()
{
    mutex.lock();
    int i = 0;
    QString temp;
    for(i = 0; i < plant_config.ids.length(); i++)
    {
        temp += plant_config.names.at(i) + ":" + QString::number(plant_config.ids.at(i)) + "|";
    }
    conf_string = temp;
    mutex.unlock();
}

void get_plant_config()
{

}
