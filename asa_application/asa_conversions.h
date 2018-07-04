#ifndef ASA_CONVERSIONS_H
#define ASA_CONVERSIONS_H

#include <QtCore>
#include <QString>

QString conv_none_or_passthru(QString str, uint param1);
QString conv_integer_divide_by(QString str, uint param1);
QString conv_integer_divide_by_pres2(QString str, uint param1);

QString conv_hex_to_int(QString str, uint param1);
QString conv_integer_caudal(QString str, uint param1);
QString conv_integer_caudal_2(QString str, uint param1);
QString conv_integer_presion(QString str, uint param1);
QString conv_integer_presion_2(QString str, uint param1);

QString conv_integer_multiply_by(QString str, uint param1);
QString conv_int_to_hex(QString str, uint param1);
QString conv_integer_caudal_inv(QString str, uint param1);
QString conv_integer_caudal_inv_2(QString str, uint param1);
QString conv_integer_presion_inv(QString str, uint param1);
QString conv_integer_presion_inv_2(QString str, uint param1);
QString conv_nivel_1(QString str, uint param1);
QString conv_nivel_1_inv(QString str, uint param1);


#endif // ASA_CONVERSIONS_H
