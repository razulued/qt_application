#include "sensorconfig.h"
#include <QDebug>
sensorConfig::sensorConfig(int id, QString module, QString name, QString units, QString type,
                           float const1, float const2, float const3, float premin, float premax,
                           float postmin, float postmax, int dec):
    id(id),module(module),name(name),units(units),type(type),const1(const1),const2(const2),const3(const3),
    premin(premin),premax(premax),postmin(postmin),postmax(postmax),dec(dec)
{
//    qDebug() << "sensorConfig" << id << const1 << const2 << const3 << premin << premax;
}
