#include "asa_conversions.h"
#include "sql_cmd_manager.h"
#include "asa_conf_string.h"

QString conv_none_or_passthru(QString str, uint param1)
{
    return str;
}

QString conv_integer_caudal(QString str, uint param1)
{
    float ret = 0;
    bool ok;
    float decimal = (float)str.toInt(&ok, 16);
/*
 *  Para el rango de [0,302.4] [l/m]:
    Caudal= 0.16312*Cuentas [l/m /adc]-66.54025 [l/m]
    Si el resultado de la ecuación es MENOR a 9.45, la página deberá mostrar 0.
*/

    ret = decimal * 0.16312;
    ret = ret - 66.54025;

    if(ret < 9.45)
    {
        return "0.0";
    }
    else
    {
        return QString::number(ret,'f',1);
    }

}

QString conv_integer_caudal_inv(QString str, uint param1)
{
    float ret = 0;
    bool ok;
    float decimal = (float)str.toFloat(&ok);
/*
 *  Para el rango de [0,302.4] [l/m]:
    Caudal= 0.16312*Cuentas [l/m /adc]-66.54025 [l/m]
    Si el resultado de la ecuación es MENOR a 9.45, la página deberá mostrar 0.
*/

    ret = decimal + 66.54025;
    ret = ret / 0.16312;

    uint to_decimal = (uint)ret;
    QString str2 = QString("%1").arg(to_decimal, 0, 16);
    return str2;

}

QString conv_integer_caudal_2(QString str, uint param1)
{
    float ret = 0;
    bool ok;
    float decimal = (float)str.toInt(&ok, 16);
/*
 *  Caudal [l/min]= 0.528982*Cuentas [l/m /adc] - 194.969575 [l/m]
*/

    if(decimal < 463)
    {
        return "0";
    }

    ret = decimal * 0.528982;
    ret = ret - 194.969575;

    if(ret < 0)
    {
        return "0.0";
    }
    else
    {
        return QString::number(ret,'f',1);
    }

}

QString conv_integer_caudal_inv_2(QString str, uint param1)
{
    float ret = 0;
    bool ok;
    float decimal = (float)str.toFloat(&ok);
/*
 *  Caudal [l/min]= 0.528982*Cuentas [l/m /adc] - 194.969575 [l/m]
*/

    ret = decimal + 194.969575;
    ret = ret / 0.528982;

    uint to_decimal = (uint)ret;
    QString str2 = QString("%1").arg(to_decimal, 0, 16);
    return str2;

}
QString conv_integer_presion(QString str, uint param1)
{
    float ret = 0;
    bool ok;
    float decimal = (float)str.toInt(&ok, 16);
/*
    Para el rango de 0 a 145.038psi: PSI=0.080255644*Cuentas [psi/adc] - 36.2594[psi]
*/

    if(decimal < 410)
    {
        return "Falla [cuentas <410]";
    }

    ret = decimal *0.080255644;
    ret = ret - 36.2594;
    if(ret < 0)
    {
        return "0";
    }
    else if(ret > 145.038)
    {
        return "Falla [>145.038]";
    }
    else
    {
        return QString::number(ret,'f',1);
    }

}

QString conv_integer_presion_inv(QString str, uint param1)
{
    float ret = 0;
    bool ok;
    float decimal = (float)str.toFloat(&ok);
/*
    Para el rango de 0 a 145.038psi: PSI=0.080255644*Cuentas [psi/adc] - 36.2594[psi]
*/

    ret = decimal + 36.2594;
    ret = ret  / 0.080255644;

    uint to_decimal = (uint)ret;
    QString str2 = QString("%1").arg(to_decimal, 0, 16);
    return str2;
}

QString conv_integer_presion_2(QString str, uint param1)
{
    float ret = 0;
    bool ok;
    float decimal = (float)str.toInt(&ok, 16);
/*
    Presión [PSI]= 0.02784*Cuentas [PSI /adc] - 12.8931 [PSI]
*/

//    if(decimal < 410)
//    {
//        return "Falla [cuentas <410]";
//    }

    ret = decimal *0.02784;
    ret = ret - 12.8931;
    if(ret < 0)
    {
        return "0";
    }
    else
    {
        return QString::number(ret,'f',1);
    }
//    else if(ret > 145.038)
//    {
//        return "Falla [>145.038]";
//    }

}

QString conv_integer_presion_inv_2(QString str, uint param1)
{
    float ret = 0;
    bool ok;
    float decimal = (float)str.toFloat(&ok);
/*
    Presión [PSI]= 0.02784*Cuentas [PSI /adc] - 12.8931 [PSI]
*/

    ret = decimal + 12.8931;
    ret = ret  / 0.02784;

    uint to_decimal = (uint)ret;
    QString str2 = QString("%1").arg(to_decimal, 0, 16);
    return str2;
}

QString conv_nivel_1(QString str, uint param1)
{
    float ret = 0;
    bool ok;
    float decimal = (float)str.toInt(&ok, 16);
/*
 *  Midel= 0.0016972*Cuentas [m /adc] - 0.7858[l/m] (VERIFICADO!)
*/

    ret = decimal * 0.0016972;
    ret = ret - 0.7858;

    if(ret < 0)
    {
        return "0";
    }
    else
    {
        return QString::number(ret,'f',2);
    }
}

QString conv_nivel_1_inv(QString str, uint param1)
{
    float ret = 0;
    bool ok;
    float decimal = (float)str.toInt(&ok, 16);
/*
 *  Midel= 0.0016972*Cuentas [m /adc] - 0.7858[l/m] (VERIFICADO!)
*/

    ret = decimal + 0.7858;
    ret = ret / 0.0016972;


    uint to_decimal = (uint)ret;
    QString str2 = QString("%1").arg(to_decimal, 0, 16);
    return str2;
}

QString conv_integer_divide_by(QString str, uint param1)
{
    float ret = 0;
    bool ok;
    float decimal = (float)str.toInt(&ok, 16);

    if(param1 != 0)
    {
        ret = decimal / param1;
        return QString::number(ret,'f',1);
    }
    else
    {
        return QString("Fail");
    }
}

QString conv_integer_multiply_by(QString str, uint param1)
{
    float ret = 0;
    bool ok;
    float decimal = (float)str.toFloat(&ok);

    ret = decimal * param1;
    uint to_decimal = (uint)ret;
    QString str2 = QString("%1").arg(to_decimal, 0, 16);
    return str2;
}

QString conv_integer_divide_by_pres2(QString str, uint param1)
{
    float ret = 0;
    bool ok;
    float decimal = (float)str.toInt(&ok, 16);

    if(param1 != 0)
    {
        ret = decimal / param1;
        return QString::number(ret,'f',2);
    }
    else
    {
        return QString("Fail");
    }

}

QString conv_hex_to_int(QString str, uint param1)
{
    bool ok;
    int value = str.toInt(&ok, 16);

    return QString::number(value);
}

QString conv_int_to_hex(QString str, uint param1)
{
    bool ok;
    int value = str.toInt(&ok, 10);

    return  QString("%1").arg(value, 0, 16);
}


// Receive functions.
void Query_ID_last_activity(QString str)
{
    QString str_response;
    sql_cmd_manager *query = new sql_cmd_manager(str);
    str_response = "1900:" + QString::number(query->query_last_id_last_activity()) +"|";
    add_to_one_time_transmit(str_response);
    query->~sql_cmd_manager();
}

void Query_ID_last_record(QString str)
{
    QString str_response;
    sql_cmd_manager *query = new sql_cmd_manager(str);
    str_response = "1901:" + QString::number(query->query_last_id_last_record()) +"|";
    add_to_one_time_transmit(str_response);
    query->~sql_cmd_manager();
}

void Query_N_record(QString str)
{
    QString str_response;
    sql_cmd_manager *query = new sql_cmd_manager(str);
    str_response = "1902:" + query->query_N_log() +"|";
    add_to_one_time_transmit(str_response);
    query->~sql_cmd_manager();
}

void Query_last_log(QString str)
{
    QString str_response;
    sql_cmd_manager *query = new sql_cmd_manager(str);
    str_response = "1903:" + QString::number(query->query_last_log_ID()) +"|";
    add_to_one_time_transmit(str_response);
    query->~sql_cmd_manager();
}


void Store_activity(QString str)
{
    sql_cmd_manager *query = new sql_cmd_manager(str);
    qDebug() << "Store_activity: " << query->store_activity();
    query->~sql_cmd_manager();
}

void Store_record(QString str)
{
    qDebug() << "NEW RECORD:STRING: " << str;
    sql_cmd_manager *query = new sql_cmd_manager(str);
    qDebug() << "Store_record: " << query->store_record();
    query->~sql_cmd_manager();
}

void Edit_activity(QString str)
{
    sql_cmd_manager *query = new sql_cmd_manager(str);
    qDebug() << "Edit_activity: " << query->edit_activity();
    query->~sql_cmd_manager();
}

void Edit_record(QString str)
{
    sql_cmd_manager *query = new sql_cmd_manager(str);
    qDebug() << "Edit_record: " << query->edit_record();
    query->~sql_cmd_manager();
}

void Delete_activity(QString str)
{
    sql_cmd_manager *query = new sql_cmd_manager(str);
    qDebug() << "Delete_activity: " << query->delete_activity();
    query->~sql_cmd_manager();
}

void Delete_record(QString str)
{
    sql_cmd_manager *query = new sql_cmd_manager(str);
    qDebug() << "Delete_record: " << query->delete_record();
    query->~sql_cmd_manager();
}
