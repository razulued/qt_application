#ifndef ASA_CONVERSIONS_H
#define ASA_CONVERSIONS_H

#include <QtCore>
#include <QString>

QString conv_none_or_passthru(QString str, uint param1);
QString conv_integer_divide_by(QString str, uint param1);
QString conv_hex_to_int(QString str, uint param1);
QString conv_integer_caudal(QString str, uint param1);
QString conv_integer_presion(QString str, uint param1);


#endif // ASA_CONVERSIONS_H
