#ifndef SENSORCONFIG_H
#define SENSORCONFIG_H
#include <QString>

class sensorConfig
{
public:
    sensorConfig(int id, QString module, QString name, QString units, QString type,
                 float const1,float const2, float const3,
                 float premin, float premax, float postmin, float postmax, int dec);
    int id;
    QString module;
    QString name;
    QString units;
    QString type;
    float const1;
    float const2;
    float const3;
    float premin;
    float premax;
    float postmin;
    float postmax;
    int dec;
};

#endif // SENSORCONFIG_H
