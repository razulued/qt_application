#include "protocol/asa_protocol.h"
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
    init_hash_table();

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

    data_mutex.unlock();

    return str;
}

QString get_value_by_ID_base_units(uint id)
{
    QString str;
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
