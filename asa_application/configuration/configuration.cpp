#include "configuration/configuration.h"
#include <QSettings>
#include <QDir>
#include <QDebug>

QString configuration::window_title;
QString configuration::username;
bool configuration::token_state = false;

bool configuration::filtro_present;

configuration_id configuration::conf_car_elect;
configuration_id configuration::conf_car_fisic;
configuration_id configuration::conf_car_quimic;

configuration_id configuration::conf_reg_elect;
configuration_id configuration::conf_reg_fisic;
configuration_id configuration::conf_reg_quimic;

configuration_id configuration::conf_react_elect;
configuration_id configuration::conf_react_fisic;
configuration_id configuration::conf_react_quimi;

configuration_id configuration::conf_clarif_elect;
configuration_id configuration::conf_clarif_fisic;
configuration_id configuration::conf_clarif_quimi;

configuration_id configuration::conf_clora_elect;
configuration_id configuration::conf_clora_fisic;
configuration_id configuration::conf_clora_quimi;

configuration_id configuration::conf_digest_elect;
configuration_id configuration::conf_digest_fisic;
configuration_id configuration::conf_digest_quimi;

configuration_id configuration::conf_deshid_elect;
configuration_id configuration::conf_deshid_fisic;
configuration_id configuration::conf_deshid_quimi;

configuration_id configuration::conf_afluente_elect;
configuration_id configuration::conf_afluente_fisic;
configuration_id configuration::conf_afluente_quimi;

configuration_id configuration::conf_efluente_elect;
configuration_id configuration::conf_efluente_fisic;
configuration_id configuration::conf_efluente_quimi;

configuration_id configuration::conf_filtro_elect;
configuration_id configuration::conf_filtro_fisic;
configuration_id configuration::conf_filtro_quimi;

configuration_id configuration::conf_filtro_bomba_elect;
configuration_id configuration::conf_filtro_bomba_fisic;
configuration_id configuration::conf_filtro_bomba_quimi;

configuration_id configuration::car_outputs;
configuration_id configuration::reg_outputs;
configuration_id configuration::react_outputs;
configuration_id configuration::clarif_outputs;
configuration_id configuration::clora_outputs;
configuration_id configuration::digest_outputs;
configuration_id configuration::deshid_outputs;
configuration_id configuration::afluente_outputs;
configuration_id configuration::efluente_outputs;
configuration_id configuration::filtro_outputs;
configuration_id configuration::filtro_bomba_outputs;

configuration::configuration(QString name)
{
    reload_parameters();

    window_title = get_value("Titulos", "Diagrama");
    username = QObject::tr("Sin Usuario");

    if ("1" == get_value("Product-Config", "Filtro"))
    {
        filtro_present = true;
    }
    else
    {
        filtro_present = false;
    }
}


QString configuration::get_value(const QString &name, const QString &key)
{
    QString ret;
    QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
    conf.sync();


    conf.beginGroup(name);
    ret = conf.value(key).toString();
    conf.endGroup();

    return ret;
}


configuration_id configuration::get_id_conf_from_module(QString name, elemnt_type type)
{
    QString module_name;
    QStringList values;
    configuration_id temp_conf;
    bool ok;

    if(false == QDir("conf").exists())
    {
        QDir().mkdir("conf");
    }
    else
    {
        /* Folder exist, get dir names and hash configurations */
        if(QDir().cd("conf"))
        {
            module_name = "./conf/"+ name + "/conf.csv";
            QFile file(module_name);
            if(file.open(QFile::ReadOnly))
            {
                QTextStream stream(&file);
                // Discard First Line
                stream.readLine();
                while(!stream.atEnd())
                {
                    values = stream.readLine().split(",");

                    //Only append items from the same type
                    if(type == values.at(2).at(0).toLatin1() - 0x30 ) /* Get first character */
                    {
                        temp_conf.names << values.at(1);
                        temp_conf.ids << values.at(0).toInt(&ok, 16);
                        temp_conf.ids_string << values.at(0);
                    }
                }
                temp_conf.group_name = name + QString::number(type);
                temp_conf.type = type;
            }
            file.close();
        }
    }
    return temp_conf;
}

void configuration::saveSettings(const QString &group, const QString &key, const QVariant &value)
{
    QSettings conf(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
    conf.sync();
    conf.beginGroup(group);
    conf.setValue(key, value);
    conf.endGroup();
}

QString configuration::get_units_longitud(void)
{
    return "units_longitud";
}

QString configuration::get_units_presion(void)
{
    return "units_presion";
}

QString configuration::get_units_caudal(void)
{
    return "units_caudal";
}

void configuration::reload_parameters()
{
    conf_car_elect = get_id_conf_from_module("Carcamo", PARAMETER_ELECTRIC);
    conf_car_fisic = get_id_conf_from_module("Carcamo", PARAMETER_PHYSICAL);
    conf_car_quimic = get_id_conf_from_module("Carcamo", PARAMETER_CHEMICAL);
    car_outputs = get_id_conf_from_module("Carcamo", PARAMETER_OUTPUT);

    conf_reg_elect = get_id_conf_from_module("Regulador", PARAMETER_ELECTRIC);
    conf_reg_fisic = get_id_conf_from_module("Regulador", PARAMETER_PHYSICAL);
    conf_reg_quimic = get_id_conf_from_module("Regulador", PARAMETER_CHEMICAL);
    reg_outputs = get_id_conf_from_module("Regulador", PARAMETER_OUTPUT);

    conf_react_elect = get_id_conf_from_module("Reactor", PARAMETER_ELECTRIC);
    conf_react_fisic = get_id_conf_from_module("Reactor", PARAMETER_PHYSICAL);
    conf_react_quimi = get_id_conf_from_module("Reactor", PARAMETER_CHEMICAL);
    react_outputs =    get_id_conf_from_module("Reactor", PARAMETER_OUTPUT);

    conf_clarif_elect = get_id_conf_from_module("Clarificador", PARAMETER_ELECTRIC);
    conf_clarif_fisic = get_id_conf_from_module("Clarificador", PARAMETER_PHYSICAL);
    conf_clarif_quimi = get_id_conf_from_module("Clarificador", PARAMETER_CHEMICAL);
    clarif_outputs    = get_id_conf_from_module("Clarificador", PARAMETER_OUTPUT);

    conf_clora_elect = get_id_conf_from_module("Clorador", PARAMETER_ELECTRIC);
    conf_clora_fisic = get_id_conf_from_module("Clorador", PARAMETER_PHYSICAL);
    conf_clora_quimi = get_id_conf_from_module("Clorador", PARAMETER_CHEMICAL);
    clora_outputs    = get_id_conf_from_module("CARCAMO", PARAMETER_OUTPUT);

    conf_digest_elect = get_id_conf_from_module("Digestor", PARAMETER_ELECTRIC);
    conf_digest_fisic = get_id_conf_from_module("Digestor", PARAMETER_PHYSICAL);
    conf_digest_quimi = get_id_conf_from_module("Digestor", PARAMETER_CHEMICAL);
    digest_outputs    = get_id_conf_from_module("Digestor", PARAMETER_OUTPUT);

    conf_deshid_elect = get_id_conf_from_module("Deshidratador", PARAMETER_ELECTRIC);
    conf_deshid_fisic = get_id_conf_from_module("Deshidratador", PARAMETER_PHYSICAL);
    conf_deshid_quimi = get_id_conf_from_module("Deshidratador", PARAMETER_CHEMICAL);
    deshid_outputs = get_id_conf_from_module("Deshidratador", PARAMETER_OUTPUT);

    conf_afluente_elect = get_id_conf_from_module("Afluente", PARAMETER_ELECTRIC);
    conf_afluente_fisic = get_id_conf_from_module("Afluente", PARAMETER_PHYSICAL);
    conf_afluente_quimi = get_id_conf_from_module("Afluente", PARAMETER_CHEMICAL);
    afluente_outputs = get_id_conf_from_module("Afluente", PARAMETER_OUTPUT);

    conf_efluente_elect = get_id_conf_from_module("Efluente", PARAMETER_ELECTRIC);
    conf_efluente_fisic = get_id_conf_from_module("Efluente", PARAMETER_PHYSICAL);
    conf_efluente_quimi = get_id_conf_from_module("Efluente", PARAMETER_CHEMICAL);
    efluente_outputs = get_id_conf_from_module("Efluente", PARAMETER_OUTPUT);

    conf_filtro_elect = get_id_conf_from_module("Filtro", PARAMETER_ELECTRIC);
    conf_filtro_fisic = get_id_conf_from_module("Filtro", PARAMETER_PHYSICAL);
    conf_filtro_quimi = get_id_conf_from_module("Filtro", PARAMETER_CHEMICAL);
    filtro_outputs = get_id_conf_from_module("Filtro", PARAMETER_OUTPUT);

    conf_filtro_bomba_elect = get_id_conf_from_module("Filtro Bomba", PARAMETER_ELECTRIC);
    conf_filtro_bomba_fisic = get_id_conf_from_module("Filtro Bomba", PARAMETER_PHYSICAL);
    conf_filtro_bomba_quimi = get_id_conf_from_module("Filtro Bomba", PARAMETER_CHEMICAL);
    filtro_bomba_outputs = get_id_conf_from_module("Filtro Bomba", PARAMETER_OUTPUT);
}

void configuration::update_window_title(QString title)
{
    window_title = title;
    saveSettings("Titulos", "Diagrama", title);
}

void configuration::validate_token(bool tk)
{
    if(tk)
    {
        username = "chompy";
        token_state = true;
    }
    else
    {
        username = QObject::tr("Sin Usuario");
        token_state = false;
    }
}
