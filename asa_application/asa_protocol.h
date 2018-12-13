#ifndef ASA_PROTOCOL_H
#define ASA_PROTOCOL_H
#include <QtCore>
#include <QVariant>
#include <QString>

typedef enum
{
    ASA_TYPE_NONE,
    ASA_TYPE_INTEGER,
    ASA_TYPE_DECIMAL,
    ASA_TYPE_STRING,
    ASA_TYPE_BUFFER
}ASA_protocol_types_t;

void store_value_by_ID(uint id, QString str_value);
QString get_value_by_ID(uint id);
QString get_value_by_ID_base_units(uint id);
QString get_value_units(uint id);
QString inverse_value_by_ID_base_units(uint id, float value);
QString units_scale(uint id, float value);

QString get_units_longitud(void);
QString get_units_presion(void);
QString get_units_caudal(void);
QString get_units_tiempo(void);
typedef struct
{
    uint id;
    ASA_protocol_types_t type;
    void (*receive_hanlder) (QString str);
    QString (*conversion_hanlder) (QString str, uint param1);
    QString (*inverse_hanlder) (QString str, uint param1);

    uint param1;
    QString units;
}ASA_protocol_element_t;

void ASA_protocol_init();

QString get_RAW_value_by_ID(uint id);


#endif // ASA_PROTOCOL_H
