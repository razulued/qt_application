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

void Query_ID_last_activity(QString str);
void Query_ID_last_record(QString str);
void Query_N_record(QString str);
void Query_last_log(QString str);
void Store_activity(QString str);
void Store_record(QString str);
void Edit_activity(QString str);
void Edit_record(QString str);
void Delete_activity(QString str);
void Delete_record(QString str);
#endif // ASA_CONVERSIONS_H
