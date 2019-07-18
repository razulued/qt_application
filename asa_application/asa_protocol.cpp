#include "asa_protocol.h"
#include <QHash>
#include <QDebug>
#include <QMutex>
#include "asa_conversions.h"
#include "parameters.h"

typedef enum
{
    IO_TYPE_NONE,
    IO_TYPE_ELECTRIC,
    IO_TYPE_CHEMICAL,
    IO_TYPE_PHYSICAL,
    IO_TYPE_OUTPUT,
    IO_TYPE_OTHER
}io_type;

typedef struct
{
    int         ID;
    QString     *name;
    io_type     type;
    QString     *units;
    int         min_show;
    int         max_show;
    int         min_raw;
    int         max_raw;
//    int         calc_type;
//    int         const_1;
//    int         const_2;
//    int         const_3;
}data_conf_t;



QHash<uint, data_conf_t> hash_conf;

QHash<uint, QVariant> hash_values;
QMutex data_mutex;

QString units_longitud;
QString units_presion;
QString units_caudal;
QString units_tiempo;

float factor_longitud;
float factor_presion;
float factor_caudal;
float factor_tiempo;

void init_hash_table()
{
    QStringList list_dir;
    int i = 0;
    QString module_name;
    QStringList values;
    data_conf_t data_conf;
    bool ok;

    //Read configurations from folder and files from ./conf
    /* Check Config folder exist, else create*/
    if(false == QDir("conf").exists())
    {
        QDir().mkdir("conf");
    }
    else
    {
        /* Folder exist, get dir names and hash configurations */
        if(QDir().cd("conf"))
        {
            list_dir = QDir("conf").entryList(QDir::Dirs | QDir::NoDotAndDotDot);
            for(i = 0; i < list_dir.length(); i++)
            {
                module_name = "./conf/"+ list_dir.at(i) + "/conf.csv";
                QFile file(module_name);
                if(file.open(QFile::ReadOnly))
                {
                    QTextStream stream(&file);
                    // Discard First Line
                    stream.readLine();
                    values.clear();
                    memset(&data_conf, 0, sizeof(data_conf_t));
                    while(!stream.atEnd())
                    {
                        values = stream.readLine().split(",");
                        data_conf.ID = values.at(0).toInt(&ok, 16);
                        data_conf.name = new QString(values.at(1));
                        data_conf.type = (io_type)0;/*values.at(2).toInt();*/
                        data_conf.units = new QString(values.at(3));
                        data_conf.min_show = values.at(4).toInt();
                        data_conf.max_show = values.at(5).toInt();
                        data_conf.min_raw = values.at(6).toInt();
                        data_conf.max_raw = values.at(7).toInt();

                        //put data in hash table
                        hash_conf.insert(data_conf.ID, data_conf);
                    }
                }
                file.close();
            }
        }
    }
}

void ASA_protocol_init()
{
    uint i = 0;

    init_hash_table();

    QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
    conf.sync();
    conf.beginGroup("Units");
    switch(conf.value("longitud").toInt())
    {
        case 1:
            units_longitud = "cm";
            factor_longitud = 100;
        break;
        case 2:
            units_longitud = "ft";
            factor_longitud = 3.28;
        break;
        default:
        case 0:
            units_longitud = "m";
            factor_longitud = 1;
        break;
    }

    switch(conf.value("presion").toInt())
    {
        case 1:
            units_presion = "kg/cm²";
            factor_presion = 0.0703;
        break;
        case 2:
            units_presion = "Bar";
            factor_presion = 0.0689;
        break;
        case 3:
            units_presion ="m.c.a";
            factor_presion = 0.703;
        break;
        default:
        case 0:
            units_presion = "PSI";
            factor_presion = 1;
        break;
    }

    switch(conf.value("caudal").toInt())
    {
        case 1:
            units_caudal = "l/m";
            factor_caudal = 1;
        break;
        case 2:
            units_caudal = "l/h";
            factor_caudal = 60;
        break;
        case 3:
            units_caudal = "gal/s";
            factor_caudal = 0.0044;
        break;
        case 4:
            units_caudal = "gal/m";
            factor_caudal = 0.264;
        break;
        case 5:
            units_caudal = " gal/h";
            factor_caudal = 15.84;
        break;
        case 6:
            units_caudal = "m³/h";
            factor_caudal = 0.004616;
        break;
        default:
        case 0:
            units_caudal = "l/s";
            factor_caudal = 0.0167;
        break;
    }

    switch(conf.value("tiempo").toInt())
    {
        case 1:
            units_tiempo = "min";
            factor_tiempo = 60;
        break;
        case 2:
            units_tiempo = "h";
            factor_tiempo = 3600;
        break;
        default:
        case 0:
            units_tiempo = "s";
            factor_tiempo = 1;
        break;
    }
    conf.endGroup();

    load_active_parameters();
}

//void ASA_protocol::store_value_by_ID(uint id, QString str_value)
void store_value_by_ID(uint id, QString str_value)
{
    if(0 != id)
    {
        data_mutex.lock();
        qDebug() << "Add: " << id << "" << str_value;
        hash_values.insert(id, str_value);

        // Check its index in the table and run its Received function, if present.

        //Add here specials (bitacora updates)
        if(0)
        {
//            if(supported_ASA_IDs[index].receive_hanlder != NULL)
//            {
//                (void)supported_ASA_IDs[index].receive_hanlder(str_value);
//            }
        }

        data_mutex.unlock();
    }
}

//void ASA_protocol::get_value_by_ID(uint id)
QString get_value_by_ID(uint id)
{
    QString str;
    bool ok;
    int temp_int;
    double temp_double;
    //Debug
    data_mutex.lock();

    //All numeric conversions will be divided by 10000, string values will pass directly
    temp_int = hash_values[id].value<QString>().toInt(&ok, 16);
//    if(id == 0x1234)
//    {
//        qDebug() << "ID:" << id << " val:" << temp_int << " ok:" << ok;
//    }
    if(ok)
    {
        // Value is a number, divide by 10000
        temp_double = (float)temp_int/10000;
        str = QString::number(temp_double);
    }
    else
    {
        // Value is not number, return same value
        str = hash_values[id].value<QString>();
    }

//    str = supported_ASA_IDs[index].conversion_hanlder(hash_values[id].value<QString>(), supported_ASA_IDs[index].param1);

//    //Apply scale by units for non-pass thrus or hex to ints
//    if(supported_ASA_IDs[index].conversion_hanlder != conv_none_or_passthru &&
//       supported_ASA_IDs[index].conversion_hanlder != conv_hex_to_int)
//    {
//        float number = str.toFloat();
//        str = units_scale(id, number);
//    }

    data_mutex.unlock();

    return str;
}

QString get_value_by_ID_base_units(uint id)
{
    QString str;
    uint index = 0;
    //Debug
    data_mutex.lock();
    //Return value as RAW
    str = hash_values[id].value<QString>();
    data_mutex.unlock();

    return str;
}

QString inverse_value_by_ID_base_units(uint id, float value)
{
    QString str;
    //Debug
    data_mutex.lock();

    //Not sure what to return here
    data_mutex.unlock();

    return str;
}


QString get_value_units(uint id)
{
    QString str;
    //Debug
    data_mutex.lock();
    /* Return units */
    str = *hash_conf[id].units;
    data_mutex.unlock();

    return str;
}

QString units_scale(uint id, float value)
{
    float val;
    uint index = 0;
    //Index in table (for conversions)
    index = 0;
    //May not be needed
//    if(supported_ASA_IDs[index].units == "longitud")
//    {
//        val = value * factor_longitud;
//    }
//    else if(supported_ASA_IDs[index].units == "presion")
//    {
//        val = value * factor_presion;
//    }
//    else if(supported_ASA_IDs[index].units == "caudal")
//    {
//        val = value * factor_caudal;
//    }
//    else if(supported_ASA_IDs[index].units == "tiempo")
//    {
//        val = value * factor_tiempo;
//    }
//    else
//    {
//        val = value;
//    }
    return QString::number(val,'f',2);
}

QString get_units_longitud(void)
{
    return units_longitud;
}

QString get_units_presion(void)
{
    return units_presion;
}

QString get_units_caudal(void)
{
    return units_caudal;
}

QString get_units_tiempo(void)
{
    return units_tiempo;
}

QString get_RAW_value_by_ID(uint id)
{
    QString str;
//    uint index = 0;
    //Debug
    data_mutex.lock();

    //Index in table (for conversions)
    str = hash_values[id].value<QString>();

    if(str == "")
    {
        str = "0";
    }
    //str = supported_ASA_IDs[index].conversion_hanlder(hash_values[id].value<QString>(), supported_ASA_IDs[index].param1);
    data_mutex.unlock();

    return str;
}
