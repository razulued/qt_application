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

typedef struct
{
    uint id;
    ASA_protocol_types_t type;
    QString (*conversion_hanlder) (QString str, uint param1);
    uint param1;
}ASA_protocol_element_t;

//class ASA_protocol
//{
//public:
//    ASA_protocol();

//private:
//    QHash<uint, uint> hash_indices;
//    QHash<uint, QVariant> hash_values;
//};

void ASA_protocol_init();

#endif // ASA_PROTOCOL_H
