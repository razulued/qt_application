#ifndef STATISTICS_H
#define STATISTICS_H
#include <Qt>
#include <QList>

void add_value_to_stats(uint param, float new_value);
QList<float> get_list_last_60_sec_from_param(uint param);
QList<float> get_list_last_60_min_from_param(uint param);
QList<float> get_list_last_24_hour_from_param(uint param);
QString get_last_value_from_param(uint param);


#endif // STATISTICS_H
