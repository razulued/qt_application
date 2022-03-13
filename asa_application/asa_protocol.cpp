#include "asa_protocol.h"
#include <QHash>
#include <QDebug>
#include <QMutex>
#include "asa_conversions.h"
#include "parameters.h"
#include "sensorconfig.h"
const ASA_protocol_element_t supported_ASA_IDs[] =
{
/*+++++++++++++++++++++ COMMON ++++++++++++++++++++++*/

/*---- 0:status ID ----*/
/* Ping LE             */ 0x0000,   ASA_TYPE_NONE,      NULL,      conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Ping BE             */ 0x0001,   ASA_TYPE_NONE,      NULL,      conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Serialnumber        */ 0x0002,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* HWinfo              */ 0x0003,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* BOOTinfo            */ 0x0004,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* APPLinfo            */ 0x0005,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* GPS lat             */ 0x0006,   ASA_TYPE_DECIMAL,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* GPS long            */ 0x0007,   ASA_TYPE_DECIMAL,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Customer            */ 0x0008,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/*---- 1:status COM ---*/
/* SIG Rssi            */ 0x0100,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* SIG Ber             */ 0x0101,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* txseqnum            */ 0x0102,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dataplan_bytes      */ 0x0103,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dataplan_prepbal    */ 0x0104,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* dataplan_expiry     */ 0x0105,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/*---- 2:status ECU ---*/
/* Sysuptime           */ 0x0200,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* Session             */ 0x0201,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/* Numresets           */ 0x0202,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* HW reset reason     */ 0x0203,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* SW reset reason     */ 0x0204,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Main supply type    */ 0x0205,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Main supply level   */ 0x0206,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Backup supply type  */ 0x0207,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Backup supply level */ 0x0208,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Debug message       */ 0x0209,   ASA_TYPE_STRING,    NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Token Owner         */ 0x020A,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Shutdown warning    */ 0x020B,   ASA_TYPE_NONE,      NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/*---- 3:status IO ----*/
/* Raw data array      */ 0x0300,   ASA_TYPE_BUFFER,    NULL,    conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Uint data value     */ 0x0301,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* CRC of memory range */ 0x0302,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Rawdata RX Count    */ 0x0303,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/*---- 4:status MISC --*/
/* OK response         */ 0x0400,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* FAIL response       */ 0x0401,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* datetime            */ 0x0402,   ASA_TYPE_STRING,    NULL,    conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/*---- 5: parm ECU ----*/
    //none
/*---- 6: parm IO -----*/
/* Set memory OP addr  */ 0x0600,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Set memory OP len   */ 0x0601,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/*---- 7: param COMM --*/
/* OP1 UDP IP          */ 0x0700,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OP1 UDP Port        */ 0x0701,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OP2 UDP IP          */ 0x0702,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OP2 UDP Port        */ 0x0703,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OP1 TCP IP          */ 0x0704,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OP1 TCP Port        */ 0x0705,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OP2 TCP IP          */ 0x0706,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OP2 TCP Port        */ 0x0707,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OTAP1 UDP IP        */ 0x0708,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OTAP1 UDP Port      */ 0x0709,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OTAP2 UDP IP        */ 0x070A,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OTAP2 UDP Port      */ 0x070B,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OTAP1 TCP IP        */ 0x070C,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OTAP1 TCP Port      */ 0x070D,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OTAP2 TCP IP        */ 0x070E,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* OTAP2 TCP Port      */ 0x070F,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Phone number        */ 0x0710,   ASA_TYPE_STRING,    NULL,    conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Transfer BS max     */ 0x0711,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Transfer ST min     */ 0x0712,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Connection timeout  */ 0x0713,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Prescale Div        */ 0x0714,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/*---- 8: parm MISC ---*/
    //none
/*---- 9:control ECU --*/
/* Reset controller    */ 0x0900,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Switch session      */ 0x0901,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Emergency shut-off  */ 0x0902,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/*---- a:control IO ---*/
/* Control panel LED   */ 0x0A00,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Start memory OP cmd */ 0x0A01,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Read ID             */ 0x0A02,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Write ID            */ 0x0A03,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Transfer BC         */ 0x0A04,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Transfer Calibration*/ 0x0A05,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/*---- b:control COM --*/
/* Start connection    */ 0x0B00,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* End connection      */ 0x0B01,   ASA_TYPE_INTEGER,   NULL,   conv_hex_to_int,          conv_int_to_hex,          0,    "",
/*---- c:control MISC -*/
    //none
/*---- d: special 1 ---*/
/* CRC capsule         */ 0x0D00,   ASA_TYPE_BUFFER,    NULL,    conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Sec challenge       */ 0x0D01,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Sec key             */ 0x0D02,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* Token Transfer      */ 0x0D03,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/* User Authority      */ 0x0D04,   ASA_TYPE_INTEGER,   NULL,   conv_none_or_passthru,    conv_none_or_passthru,    0,    "",
/*---- e: special 2 ---*/
    //none
/*---- f: special 3 ---*/
    //none

///* ALARMAS */
};

QHash<uint, uint> hash_indices;
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

enum {
    ID,
    MODULE,
    NAME,
    UNITS,
    TYPE,
    CONST1,
    CONST2,
    CONST3,
    MINPRE,
    MAXPRE,
    MINPOST,
    MAXPOST,
    DEC
};
QMap<uint, sensorConfig*> map_config;
void load_sensorConfig(){
    QFile file("sensorConfig.csv");
    if(file.open(QFile::ReadOnly))
    {
        QTextStream stream(&file);
        // Discard First Line (headers)
        stream.readLine();
        QList<QString> values;
        while(!stream.atEnd())
        {
            values = stream.readLine().split(",");
            qDebug() << values;
            int id=0;
            QString module;
            QString name;
            QString units;
            QString type = "";
            float const1 = 1.0;
            float const2 = 1.0;
            float const3 = 0.0;
            float premin = 0.0;
            float premax = 65535.0;
            float postmin = 0.0;
            float postmax = 65535.0;
            int dec = 2;
            bool ok;
            if(values.size() >= TYPE){
                id = values.at(ID).toInt(&ok,16);
                if(!ok) continue;
                module = values.at(MODULE);
                name = values.at(NAME);
                units = values.at(UNITS);
                type = values.at(TYPE);
            }
            if(values.size() >= CONST3){
                const1 = values.at(CONST1).toFloat(&ok);
                if(!ok) const1 = 1.0;
                const2 = values.at(CONST2).toFloat(&ok);
                if(!ok) const2 = 1.0;
                const3 = values.at(CONST3).toFloat(&ok);
                if(!ok) const3 = 0.0;
            }
            if(values.size() >= MAXPRE){
                premin = values.at(MINPRE).toFloat(&ok);
                if(!ok) premin = 0.0;
                premax = values.at(MAXPRE).toFloat(&ok);
                if(!ok) premax = 65535.0;
            }
            if(values.size() >= MAXPOST){
                postmin = values.at(MINPOST).toFloat(&ok);
                if(!ok) postmin = 0.0;
                postmax = values.at(MAXPOST).toFloat(&ok);
                if(!ok) postmax = 65535.0;
            }
            if(values.size() >= DEC){
                dec = values.at(DEC).toInt(&ok);
                if(!ok) dec = 2;
            }
//            qDebug() << "MAKE CONF: "<< id << name << type << const1 << const2 << const3 << dec;
            map_config.insert(id, new sensorConfig(id, module, name, units,type,
                                                   const1,const2,const3,premin,premax,postmin,postmax,dec));
        }
    }
    file.close();
}

void ASA_protocol_init()
{
    uint i = 0;
//sensorConfig *sens = new sensorConfig(0x3601, "Nivel chido", "m");
    load_sensorConfig();

    //Store in known IDs and hash their index
    for(i = 0; i < (sizeof(supported_ASA_IDs) / sizeof(ASA_protocol_element_t)); i++)
    {
        hash_indices.insert(supported_ASA_IDs[i].id, i);
    }

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

}

void ASA_load_active_parameters(){
    load_active_parameters();
}

//void ASA_protocol::store_value_by_ID(uint id, QString str_value)
void store_value_by_ID(uint id, QString str_value)
{
    uint index = 0;

    if(0 != id)
    {
        data_mutex.lock();

        hash_values.insert(id, str_value);

        // Check its index in the table and run its Received function, if present.
        //Index in table (for functions)
        index = hash_indices.value(id);

        if(0 != index)
        {
            if(supported_ASA_IDs[index].receive_hanlder != NULL)
            {
                (void)supported_ASA_IDs[index].receive_hanlder(str_value);
            }
        }

        data_mutex.unlock();
    }
}

QString get_value_by_ID(uint id)
{
    QString str;
    uint index = 0;
    //Debug
    data_mutex.lock();

    //Index in table (for conversions)
    index = hash_indices.value(id);
    str = supported_ASA_IDs[index].conversion_hanlder(hash_values[id].value<QString>(), supported_ASA_IDs[index].param1);

    float number = str.toFloat();
    str = units_scale(id, number);

    data_mutex.unlock();

    return str;
}

float get_max_value_by_ID(uint id) {
    if(map_config.contains(id)){
        return map_config.value(id)->postmax;
    }
    return 0;
}

QString get_name_by_ID(uint id)
{
    if(map_config.contains(id)){
        return map_config.value(id)->name;
    }
    else{
        return "Unknown";
    }
}

QString get_value_by_ID_base_units(uint id)
{
    QString str;
    uint index = 0;
    //Debug
    data_mutex.lock();

    //Index in table (for conversions)
    index = hash_indices.value(id);
    str = supported_ASA_IDs[index].conversion_hanlder(hash_values[id].value<QString>(), supported_ASA_IDs[index].param1);
    //qDebug() << "Id: " << QString::number(id, 16) << ": " << hash_values[id].value<QString>() << "at index " << hash_indices.value(id);
    data_mutex.unlock();

    return str;
}

QString inverse_value_by_ID_base_units(uint id, float value)
{
    QString str;
    uint index = 0;
    //Debug
    data_mutex.lock();

    //Index in table (for conversions)
    index = hash_indices.value(id);
    str = supported_ASA_IDs[index].inverse_hanlder(QString::number(value), supported_ASA_IDs[index].param1);
    //qDebug() << "Id: " << QString::number(id, 16) << ": " << hash_values[id].value<QString>() << "at index " << hash_indices.value(id);
    data_mutex.unlock();

    return str;
}


QString get_value_units(uint id)
{
    QString str;
    uint index = 0;
    //Debug
    data_mutex.lock();

    //Index in table (for conversions)
    index = hash_indices.value(id);
    if(supported_ASA_IDs[index].units == "longitud")
    {
        str = " " +units_longitud;
    }
    else if(supported_ASA_IDs[index].units == "presion")
    {
        str = " " +units_presion;
    }
    else if(supported_ASA_IDs[index].units == "caudal")
    {
        str = " " +units_caudal;
    }
    else if(supported_ASA_IDs[index].units == "tiempo")
    {
        str = " " +units_tiempo;
    }
    else
    {
        if(map_config.contains(id)){
            str = map_config.value(id)->units;
        }
        else{
            str = supported_ASA_IDs[index].units;
        }
    }

    data_mutex.unlock();

    return str;
}

QString units_scale(uint id, float value)
{
    float val;
    if (map_config.contains(id)) {
        sensorConfig conf = *(map_config.value(id));
        float c1 = conf.const1;
        float c2 = conf.const2;
        float c3 = conf.const3;

        float premin = conf.premin;
        float premax = conf.premax;
        float postmin = conf.postmin;
        float postmax = conf.postmax;

        if(value < premin) value = premin;
        if(value > premax) value = premax;

        val = (float)(value * c1);
        val = (float)(val/c2);
        val = (float)(val - c3);

        if(val < postmin) val = postmin;
        if(val > postmax) val = postmax;

        int dec = map_config.value(id)->dec;
        return QString::number(val,'f',dec);
    } else {
        val = value;
    }
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
    //qDebug() << "Id: " << QString::number(id, 16) << ": " << hash_values[id].value<QString>() << "at index " << hash_indices.value(id);
    data_mutex.unlock();

    return str;
}

configuration_id ASA_get_module_sensors(QString module, QString type)
{
    configuration_id conf;
    QMapIterator<uint, sensorConfig*> i(map_config);
    while (i.hasNext()) {
        i.next();
        if(i.value()->module == module && i.value()->type == type){
//        qDebug() << "GET MODULE SENS: "<< i.key() << ": " << i.value()->id << i.value()->name;
            conf.ids.append(i.value()->id);
            conf.names.append(i.value()->name);
            conf.ids_string.append(QString::number(i.value()->id));
        }
    }
    return conf;
}
