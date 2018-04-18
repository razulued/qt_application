#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <QList>
#include <QString>
typedef struct
{
    QStringList names;
    QList<int>  ids;
    QList<QString> ids_string;
}configuration_id;

class configuration
{
public:
    configuration(QString name);
    ~configuration();

    void load_configuration(QString name);

    QString get_value(const QString &name, const QString &key);
    void saveSettings(const QString &name, const QString &key, const QString &value);
    configuration_id get_config();

private:
    configuration_id process_conf;
    configuration_id conf_reactor;
};

#endif // CONFIGURATION_H
