#include "asa_conversions.h"
#

QString conv_none_or_passthru(QString str, uint param1)
{
    return str;
}

QString conv_integer_divide_by(QString str, uint param1)
{
    float ret = 0;
    bool ok;
    int decimal = str.toInt(&ok, 16);

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

QString conv_integer_divide_by_pres2(QString str, uint param1)
{
    float ret = 0;
    bool ok;
    int decimal = str.toInt(&ok, 16);

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
