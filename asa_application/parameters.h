#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <QtGlobal>
#include <QObject>
typedef enum
{
    TYPE_NONE,
    TYPE_STRING,
    TYPE_DECIMAL,
    TYPE_HEX
}data_type_t;

typedef struct
{
    unsigned int    id;
    bool            active_show;
    QString     name;
    void*     param;
    data_type_t type;
}parameter_config_t;

data_type_t getParamType(unsigned int id);
QString getParamValue(unsigned int id);
void setParamValue(unsigned int id, double value);

QString getParamName(unsigned int id);
bool getParamActiveShow(unsigned int id);
void toggleParamActiveShow(unsigned int id);

void InitRandomParameters();
#endif // PARAMETERS_H
