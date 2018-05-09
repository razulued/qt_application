#ifndef RUTINAS_MANTENIMIENTO_H
#define RUTINAS_MANTENIMIENTO_H
#include <QString>
#include <QSqlDatabase>
#include <QDateTime>


enum{
    SIN_RUTINA,
    RUTINA_DIA      = 1,
    RUTINA_SEMANA   = 7,
    RUTINA_MES      = 30,
    RUTINA_ANIO     = 360
};

enum
{
    STATE_NEW,
    STATE_SYNCH,
    STATE_SET_LAST_EVENT,
    STATE_SET_NEXT_EVENT,
    STATE_WAIT_FOR_NEXT_EVENT,
    STATE_WAIT_FOR_COMPLETE,
    STATE_COMPLETE,
    STATE_ADD_HOURS
};

enum
{
    ORIGEN_GENERAL,
    ORIGEN_REGULADOR,
    ORIGEN_REACTOR,
    ORIGEN_CLARIFICADOR,
    ORIGEN_CLORADOR,
    ORIGEN_SECADO,
    ORIGEN_DIGESTOR,
    ORIGEN_AFLUENTE,
    ORIGEN_EFLUENTE,
    ORIGEN_FILTRO,
};


typedef struct
{
    QString nombre;
    uint id;
    uint ready;
    uint periodo;
    uint origen;
    uint state;
    uint synch_date;
    uint last_event;
    uint next_event;
    QString explicacion;
    QString texto_ayuda;
}def_rutina_t;

class rutinas_mantenimiento
{
public:
    rutinas_mantenimiento(const QString& path);
    ~rutinas_mantenimiento();

    void init_db(void);
    void delete_db(void);
    void check_rutinas(void);
    static uint num_of_rutinas;

    uint origen(uint rutina);
    uint ready(uint rutina);
    uint id(uint rutina);
    uint periodo(uint rutina);
    uint last_event(uint rutina);
    uint next_event(uint rutina);
    QString nombre(uint rutina);
    QString explicacion(uint rutina);
    QString texto_ayuda(uint rutina);

    void complete_rutina(uint rutina);
    void add_seconds_rutina(uint rutina, uint seconds);
    void set_time(QDateTime time);
private:
//    def_rutina_t rutina_def_table[];
    QSqlDatabase m_db;
    QString db_path;
    void rutina_state_machine(int index);

    QDateTime get_current_time();

    QDateTime global_time = QDateTime::fromTime_t(0);

    void load_to_table(uint id);
    void load_to_db(uint id);
};

#endif // RUTINAS_MANTENIMIENTO_H
