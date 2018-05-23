#include "statistics.h"
#include <QHash>
#include <QDebug>

QHash<uint, QList<float> > last_60_seconds;
QHash<uint, QList<float> > last_60_minutes;
QHash<uint, QList<float> > last_24_hours;

void add_value_to_stats(uint param, float new_value)
{
    static uint sec_count = 0;
    static uint min_count = 0;
    static uint hour_count = 0;

    QList<float> param_list_seconds;
    QList<float> param_list_minutes;
    QList<float> param_list_hours;

    float average_seconds = 0;
    float average_minutes = 0;
    uint i = 0;

    // SEGUNDOS
    param_list_seconds = last_60_seconds.value(param);
    if(param_list_seconds.length() >= 60)
    {
        // List reached the end, remove first element
        param_list_seconds.removeFirst();
    }
    //Add new alement to list and update Hash
    param_list_seconds.append(new_value);
    last_60_seconds.insert(param, param_list_seconds);

    sec_count++;
    if(sec_count > 60)
    {
        sec_count = 0;

        // MINUTOS
        param_list_minutes = last_60_minutes.value(param);
        if(param_list_minutes.length() >= 60)
        {
            // List reached the end, remove first element
            param_list_minutes.removeFirst();
        }
        // AVERAGE seconds
        for(i = 0; i < param_list_seconds.length(); i++)
        {
            average_seconds += param_list_seconds.at(i);
        }
        average_seconds = average_seconds/param_list_seconds.length();

        //Add new alement to list and update Hash
        param_list_minutes.append(average_seconds);
        last_60_minutes.insert(param, param_list_minutes);

        min_count++;
        if(min_count > 60)
        {
            min_count = 0;

            // HORAS
            param_list_hours = last_24_hours.value(param);
            if(param_list_hours.length() >= 24)
            {
                // List reached the end, remove first element
                param_list_hours.removeFirst();
            }
            // AVERAGE seconds
            for(i = 0; i < param_list_minutes.length(); i++)
            {
                average_minutes += param_list_minutes.at(i);
            }
            average_minutes = average_seconds/param_list_minutes.length();
            //Add new alement to list and update Hash
            param_list_hours.append(average_minutes);
            last_24_hours.insert(param, param_list_hours);

            hour_count++;
            if(hour_count > 24)
            {
                hour_count = 0;
            }
        }
    }
}

QList<float> get_list_last_60_sec_from_param(uint param)
{
    return last_60_seconds.value(param);
}

QList<float> get_list_last_60_min_from_param(uint param)
{
    return last_60_minutes.value(param);
}

QList<float> get_list_last_24_hour_from_param(uint param)
{
    return last_24_hours.value(param);
}

QString get_last_value_from_param(uint param)
{
    return QString::number(last_60_seconds.value(param).last());
}
