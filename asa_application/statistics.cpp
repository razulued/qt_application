#include "statistics.h"
#include <QHash>
#include <QDebug>

QHash<uint, QList<float> > last_60_seconds;

void add_value_to_stats(uint param, float new_value)
{
    QList<float> param_list = last_60_seconds.value(param);

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

QList<float> get_list_from_param(uint param)
{
    return last_60_seconds.value(param);
}

QString get_last_value_from_param(uint param)
{
    return QString::number(last_60_seconds.value(param).last());
}
