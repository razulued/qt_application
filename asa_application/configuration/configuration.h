#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <QList>
#include <QString>
typedef struct
{
    QString group_name;
    QStringList names;
    QList<int>  ids;
    QList<QString> ids_string;
}configuration_id;

typedef enum
{
    PARAMETER_NONE,
    PARAMETER_ELECTRIC,
    PARAMETER_PHYSICAL,
    PARAMETER_CHEMICAL,
    PARAMETER_OUTPUT
}elemnt_type;

class configuration
{
public:
    configuration(QString name);
    ~configuration();

    QString get_value(const QString &name, const QString &key);

    QString get_units_longitud(void);
    QString get_units_presion(void);
    QString get_units_caudal(void);

    void reload_parameters(void);

    static void saveSettings(const QString &group, const QString &key, const QVariant &value);
    static void update_window_title(QString title);

    static QString window_title;
    static bool filtro_present;
    //Carcamo
    static configuration_id conf_car_elect;
    static configuration_id conf_car_fisic;
    static configuration_id conf_car_quimic;
    //Regulador
    static configuration_id conf_reg_elect;
    static configuration_id conf_reg_fisic;
    static configuration_id conf_reg_quimic;
    //Reactor
    static configuration_id conf_react_elect;
    static configuration_id conf_react_fisic;
    static configuration_id conf_react_quimi;
    //Clarificador
    static configuration_id conf_clarif_elect;
    static configuration_id conf_clarif_fisic;
    static configuration_id conf_clarif_quimi;
    //Clorador
    static configuration_id conf_clora_elect;
    static configuration_id conf_clora_fisic;
    static configuration_id conf_clora_quimi;
    //Digestor
    static configuration_id conf_digest_elect;
    static configuration_id conf_digest_fisic;
    static configuration_id conf_digest_quimi;
    //Deshidratador
    static configuration_id conf_deshid_elect;
    static configuration_id conf_deshid_fisic;
    static configuration_id conf_deshid_quimi;
    //Afluente
    static configuration_id conf_afluente_elect;
    static configuration_id conf_afluente_fisic;
    static configuration_id conf_afluente_quimi;
    //Efluente
    static configuration_id conf_efluente_elect;
    static configuration_id conf_efluente_fisic;
    static configuration_id conf_efluente_quimi;
    //Filtro
    static configuration_id conf_filtro_elect;
    static configuration_id conf_filtro_fisic;
    static configuration_id conf_filtro_quimi;
    //Filtro bomba
    static configuration_id conf_filtro_bomba_elect;
    static configuration_id conf_filtro_bomba_fisic;
    static configuration_id conf_filtro_bomba_quimi;
    //Salidas
    static configuration_id car_outputs;
    static configuration_id reg_outputs;
    static configuration_id react_outputs;
    static configuration_id clarif_outputs;
    static configuration_id clora_outputs;
    static configuration_id digest_outputs;
    static configuration_id deshid_outputs;
    static configuration_id afluente_outputs;
    static configuration_id efluente_outputs;
    static configuration_id filtro_outputs;
    static configuration_id filtro_bomba_outputs;
private:
    configuration_id get_id_conf_from_module(QString name, elemnt_type type);
};

#endif // CONFIGURATION_H
