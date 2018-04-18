#include "statistics.h"
#include <QHash>
#include <QDebug>

QHash<uint, QList<int> > last_60_seconds;

void add_value_to_stats(uint param, int new_value)
{
    QList<int> param_list = last_60_seconds.value(param);

    if(param_list.length() >= 10)
    {
        // List reached the end, remove first element
        param_list.removeFirst();
    }
    //Add new alement to list and update Hash
    param_list.append(new_value);
    last_60_seconds.insert(param, param_list);


//    qDebug() << "param" << param << param_list;
}

QList<int> get_list_from_param(uint param)
{
    return last_60_seconds.value(param);
}
