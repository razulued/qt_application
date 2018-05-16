#ifndef STATISTICS_H
#define STATISTICS_H
#include <Qt>
#include <QList>

void add_value_to_stats(uint param, float new_value);
QList<float> get_list_from_param(uint param);
QString get_last_value_from_param(uint param);


#endif // STATISTICS_H
