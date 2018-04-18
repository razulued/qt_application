#ifndef STATISTICS_H
#define STATISTICS_H
#include <Qt>
#include <QList>

void add_value_to_stats(uint param, int new_value);
QList<int> get_list_from_param(uint param);


#endif // STATISTICS_H
