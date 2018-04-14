#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <QList>

typedef struct
{
    QStringList names;
    QList<int>  ids;
}configuration_id;

class configuration
{
public:
    configuration(QString name);
    ~configuration();

    void load_configuration(QString name);
    configuration_id get_config();

private:
    configuration_id process_conf;
    configuration_id conf_reactor;
};

#endif // CONFIGURATION_H
