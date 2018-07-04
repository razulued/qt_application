#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <QtGlobal>
#include <QObject>
typedef enum
{
    TYPE_NONE,
    TYPE_STRING,
    TYPE_HEX,

    TYPE_DECIMAL,
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
QString invese_getParamValue(unsigned int id, float_t value);

QString getParamValue_and_units(unsigned int id);

void setParamValue(unsigned int id, double value);
void setParamString(unsigned int id, QString value);

QString getParamName(unsigned int id);
bool getParamActiveShow(unsigned int id);
void toggleParamActiveShow(unsigned int id);
QHash<uint,uint> load_active_parameters();

void InitRandomParameters();
void run_simulation();

void write_parameter(QString filename, uint value);
uint load_parameter(QString filename);

#endif // PARAMETERS_H
