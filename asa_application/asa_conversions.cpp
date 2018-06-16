#include "asa_conversions.h"
#

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

    ret = decimal / 0.16312;
    ret = ret + 66.54025;

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

    ret = decimal  / 0.080255644;
    ret = ret + 36.2594;

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
