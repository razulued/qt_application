#include "asa_conversions.h"
#

QString conv_none_or_passthru(QString str, uint param1)
{
    return str;
}

QString conv_integer_divide_by(QString str, uint param1)
{
    uint ret = 0;
    ret = str.toInt() / param1;
    return QString::number(ret);
}
