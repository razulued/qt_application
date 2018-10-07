#include "rutinas_mantenimiento.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include "mainwindow.h"
#include <QVector>

#define FIRST_MONDAY_EPOCH (345600)
#define SECONDS_IN_A_WEEK (60 * 60 * 24 * 7)
#define HOURS_TO_SECONDS(x)  (x * 60 * 60)

int multiplicador = (10);//(3600 * 24);

QVector <def_rutina_t> rutina_def_table;

//Static vars
uint rutinas_mantenimiento::num_of_rutinas = 0;
bool rutinas_mantenimiento::update_db = false;

rutinas_mantenimiento::rutinas_mantenimiento(const QString &path)
{
    db_path = path;

    if(!QSqlDatabase::isDriverAvailable("QSQLITE"))
    {
        qDebug() << "Driver not available";
    }
    else
    {
        if((true == QFileInfo(db_path).exists()) && (QFileInfo(db_path).isFile()))
        {
            qDebug() << "Ya existe la DB";

            m_db = QSqlDatabase::addDatabase("QSQLITE");
            m_db.setDatabaseName(db_path);

            if (!m_db.open())
            {
               qDebug() << "Error: connection with database fail";
            }
            else
            {
               qDebug() << "Database: connection ok";
            }

            QSqlQuery q;

            // Load DB to Table
//            q.exec("SELECT * FROM rutinas");

//            while(q.next())
//            {
//                qDebug() << "DATABASE: "
//                         << q.value("id")
//                         << q.value("synch_date");

//            }

        }
        else
        {
            m_db = QSqlDatabase::addDatabase("QSQLITE");
            m_db.setDatabaseName(db_path);

            if (!m_db.open())
            {
               qDebug() << "Error: connection with database fail";
            }
            else
            {
               qDebug() << "Database: connection ok";
            }

            QSqlQuery q;
            if(!q.exec("CREATE TABLE IF NOT EXISTS rutinas("
                       "id INTEGER NOT NULL PRIMARY KEY,"
                       "nombre VARCHAR(255) NOT NULL,"
                       "ready INTEGER,"
                       "periodo INTEGER,"
                       "origen  INTEGER,"
                       "state   INTEGER,"
                       "synch_date  INTEGER,"
                       "last_event  INTEGER,"
                       "next_event  INTEGER,"
                       "explicacion VARCHAR(1024),"
                       "schedule_to INTEGER"
                       ")"))
            {
                qDebug() << "Error: exec";
            }
            init_db();
        }

        // Load DB to table.
        load_to_table();

    }

}

rutinas_mantenimiento::~rutinas_mantenimiento()
{
    m_db.close();
    delete this;
}

void rutinas_mantenimiento::init_db(void)
{
//    unsigned int i;
//    QSqlQuery q;

//    if(QFileInfo::exists(db_path))
//    {
//        for(i = 0; i < num_of_rutinas; i++)
//        {
//            q.prepare("INSERT INTO rutinas(id, nombre, ready, periodo, origen, state, synch_date, last_event, next_event, explicacion, schedule_to, record_links) "
//                      "VALUES(:id, :nombre, :ready, :periodo, :origen, :state, :synch_date, :last_event, :next_event, :explicacion, :schedule_to, :record_links)");
//            q.bindValue(":id",rutina_def_table[i].id);
//            q.bindValue(":nombre",rutina_def_table[i].nombre);
//            q.bindValue(":ready",rutina_def_table[i].ready);
//            q.bindValue(":periodo", rutina_def_table[i].periodo);
//            q.bindValue(":origen", rutina_def_table[i].origen);
//            q.bindValue(":state", rutina_def_table[i].state);
//            q.bindValue(":synch_date", rutina_def_table[i].synch_date);
//            q.bindValue(":last_event", rutina_def_table[i].last_event);
//            q.bindValue(":next_event", rutina_def_table[i].next_event);
//            q.bindValue(":explicacion", rutina_def_table[i].explicacion);
//            q.bindValue(":schedule_to", rutina_def_table[i].schedule_to);
//            q.bindValue(":record_links", rutina_def_table[i].record_links);

//            if(!q.exec())
//            {
//                qDebug() << q.lastError().text();
//            }
//        }
//    }
//    else
//    {
//        qDebug() << "Database doesn't exists";
//    }

}

void rutinas_mantenimiento::delete_db(void)
{
    QSqlQuery q;

    q.clear();
    m_db.close();
    QFile::remove(db_path);
}

void rutinas_mantenimiento::check_rutinas(void)
{
    unsigned int i;

    if(0 == global_time.toTime_t())
    {
        return;
    }

    if(update_db == true)
    {
        load_to_table();
        update_db = false;
    }
    for(i = 0; i < num_of_rutinas; i++)
    {
        rutina_state_machine(i);
    }
}

void rutinas_mantenimiento::rutina_state_machine(int index)
{
    QDateTime *time;

//    qDebug() << "STM: " << index << rutina_def_table[index].state << rutina_def_table[index].ready;
    switch(rutina_def_table[index].state)
    {
    case STATE_NEW:
        //Check if sych time has not been set
        if(0 == rutina_def_table[index].synch_date)
        {
            qDebug() << "Rutina " << index << "is not synched";
            rutina_def_table[index].state = STATE_SYNCH;
        }
        else
        {
            rutina_def_table[index].state = STATE_WAIT_FOR_NEXT_EVENT;
        }
        break;
    case STATE_SYNCH:
        //TODO: Add here a way no know current time.
        time = new QDateTime(get_current_time());
        rutina_def_table[index].synch_date = time->toTime_t();
//        qDebug() << "Synch time for " << index << "is " << *time << "UTC: " << rutina_def_table[index].synch_date;

        if(0 != rutina_def_table[index].synch_date)
        {
            // solo arrancar hasta que tiempo es diferente a 0
            rutina_def_table[index].state = STATE_SET_LAST_EVENT;
        }
        break;
    case STATE_SET_LAST_EVENT:
        if(0 == rutina_def_table[index].last_event &&
           0 == rutina_def_table[index].next_event)
        {
//            qDebug() << "Rutina " << index << "last time not set, use time from synch";
            time = new QDateTime(QDateTime::fromTime_t(rutina_def_table[index].synch_date));

            rutina_def_table[index].last_event = time->toTime_t();
//            qDebug() << "Rutina " << index << "last time is " << *time << "UTC: " << rutina_def_table[index].synch_date;
        }
        else
        {
            //TODO: Add here a way no know current time.
            time = new QDateTime(QDateTime::fromTime_t(rutina_def_table[index].next_event));
            rutina_def_table[index].last_event = time->toTime_t();
//            qDebug() << "Rutina " << index << "last time is " << *time << "UTC: " << rutina_def_table[index].last_event;
        }

        rutina_def_table[index].state = STATE_SET_NEXT_EVENT;

        break;

    case STATE_SET_NEXT_EVENT:
//        rutina_def_table[index].next_event = rutina_def_table[index].last_event + (rutina_def_table[index].periodo * multiplicador);
        rutina_def_table[index].next_event = find_next_schedule(rutina_def_table[index].periodo, rutina_def_table[index].last_event, rutina_def_table[index].schedule_to);
        time = new QDateTime(QDateTime::fromTime_t(rutina_def_table[index].next_event));
//        qDebug() << "Rutina " << index << "next time " << *time << "UTC: " << rutina_def_table[index].next_event;

        rutina_def_table[index].state = STATE_WAIT_FOR_NEXT_EVENT;

        load_to_db(rutina_def_table[index].id);
        break;

    case STATE_WAIT_FOR_NEXT_EVENT:
        time = new QDateTime(get_current_time());

        if(*time >= QDateTime::fromTime_t(rutina_def_table[index].next_event))
        {
//            qDebug() << "Alarm Trigger " << index;
            rutina_def_table[index].state = STATE_WAIT_FOR_COMPLETE;
            rutina_def_table[index].ready = 0;

            load_to_db(rutina_def_table[index].id);
        }
        break;

    case STATE_WAIT_FOR_COMPLETE:
        // Do nothing, state change externally
        break;

    case STATE_COMPLETE:
        rutina_def_table[index].ready = 1;
        rutina_def_table[index].state = STATE_SET_LAST_EVENT;
        load_to_db(rutina_def_table[index].id);
        break;
    case STATE_RESCHEDULE:
        rutina_def_table[index].ready = 1;
        rutina_def_table[index].state = STATE_WAIT_FOR_NEXT_EVENT;
        load_to_db(rutina_def_table[index].id);
        break;
    default:
        break;
    }
}

void rutinas_mantenimiento::update_rutina(uint rutina)
{
    load_to_db(rutina_def_table[rutina].id);
}

void rutinas_mantenimiento::complete_rutina(uint rutina)
{
    QDateTime *time;

    time = new QDateTime(get_current_time());
    rutina_def_table[rutina].next_event = time->toTime_t();

    rutina_def_table[rutina].state = STATE_COMPLETE;
}

void rutinas_mantenimiento::reschedule_rutina(uint rutina, uint new_time)
{
    QDateTime *time;

    time = new QDateTime(get_current_time());

    if(new_time > time->toTime_t())
    {
        rutina_def_table[rutina].next_event = new_time;
        time = new QDateTime(QDateTime::fromTime_t(new_time));

    }

    switch(rutina_def_table[rutina].periodo)
    {
    case SIN_RUTINA:
        break;
    case RUTINA_DIA:
        rutina_def_table[rutina].schedule_to = time->time().hour();
        break;

    case RUTINA_SEMANA:
        rutina_def_table[rutina].schedule_to = time->date().dayOfWeek();
        break;

    case RUTINA_MES:
        rutina_def_table[rutina].schedule_to = time->date().day();
      break;

    case RUTINA_ANIO:
        rutina_def_table[rutina].schedule_to = time->date().day();
        break;
    default:
        break;
    }
    rutina_def_table[rutina].state = STATE_RESCHEDULE;
}

uint rutinas_mantenimiento::origen(uint rutina)
{
    return rutina_def_table[rutina].origen;
}

uint rutinas_mantenimiento::ready(uint rutina)
{
    return rutina_def_table[rutina].ready;
}

uint rutinas_mantenimiento::id(uint rutina)
{
    return rutina_def_table[rutina].id;
}

uint rutinas_mantenimiento::periodo(uint rutina)
{
    return rutina_def_table[rutina].periodo;
}

QString rutinas_mantenimiento::nombre(uint rutina)
{
    return rutina_def_table[rutina].nombre;
}

QString rutinas_mantenimiento::texto_ayuda(uint rutina)
{
    return rutina_def_table[rutina].record_links;
}

QString rutinas_mantenimiento::explicacion(uint rutina)
{
    return rutina_def_table[rutina].explicacion;
}

uint rutinas_mantenimiento::schedule_to(uint rutina)
{
    return rutina_def_table[rutina].schedule_to;
}

uint rutinas_mantenimiento::last_event(uint rutina)
{
    return rutina_def_table[rutina].last_event;
}

uint rutinas_mantenimiento::next_event(uint rutina)
{
    return rutina_def_table[rutina].next_event;
}

QDateTime rutinas_mantenimiento::get_current_time()
{
//    if(true == MainWindow::simulation)
//    {
//        return QDateTime::currentDateTime();
//        multiplicador = 10;
//    }
//    else
//    {
        return global_time;
        multiplicador = (3600 * 24);
//    }
}

void rutinas_mantenimiento::load_to_table()
{
    uint i = 0;
    QSqlQuery q;
    def_rutina_t temp_rutina_def;

    rutina_def_table.clear();

    if(!q.prepare("SELECT * FROM rutinas")) qDebug() << "Failed to prepare";

//            q.bindValue(":id_found",rutina_def_table[i].id);

    if(!q.exec()) qDebug() << "Failed to execute: rutinas load_to_table()";

    while (q.next())
    {
        temp_rutina_def.id = q.value("id").toInt();
        temp_rutina_def.nombre = q.value("nombre").toString();
        temp_rutina_def.ready = q.value("ready").toInt();
        temp_rutina_def.periodo = q.value("periodo").toInt();
        temp_rutina_def.origen = q.value("origen").toInt();
        temp_rutina_def.state = q.value("state").toInt();
        temp_rutina_def.synch_date = q.value("synch_date").toInt();
        temp_rutina_def.last_event = q.value("last_event").toInt();
        temp_rutina_def.next_event = q.value("next_event").toInt();
        temp_rutina_def.explicacion = q.value("explicacion").toInt();
        temp_rutina_def.schedule_to = q.value("schedule_to").toInt();
        temp_rutina_def.record_links = q.value("record_links").toString();
        rutina_def_table.append(temp_rutina_def);
         i++;

    }

    num_of_rutinas = i;

    for(i = 0; num_of_rutinas < 3; i++)
    {
        qDebug() << "Save to table"
                 << rutina_def_table[i].id
                 << rutina_def_table[i].nombre
                 << rutina_def_table[i].periodo
                 << rutina_def_table[i].origen
                 << rutina_def_table[i].state
                 << rutina_def_table[i].synch_date
                 << rutina_def_table[i].last_event
                 << rutina_def_table[i].next_event
                 << rutina_def_table[i].schedule_to
                 << rutina_def_table[i].record_links;
    }
}

void rutinas_mantenimiento::load_to_db(uint id)
{
    qDebug() << "Load ID " << id;
    uint i = 0;
    QSqlQuery q;

    // Search ID
    for(i = 0; i < num_of_rutinas; i++)
    {
        if(rutina_def_table[i].id == id)
        {
            //UPDATE Customers SET ContactName = 'Alfred Schmidt', City= 'Frankfurt' WHERE CustomerID = 1;
            if(!q.prepare("UPDATE rutinas SET  "
                          "id=:id_found, "
                          "nombre=:nombre, "
                          "ready=:ready, "
                          "periodo=:periodo, "
                          "origen=:origen, "
                          "state=:state, "
                          "synch_date=:synch_date, "
                          "last_event=:last_event, "
                          "next_event=:next_event, "
                          "explicacion=:explicacion, "
                          "schedule_to=:schedule_to, "
                          "record_links=:record_links "
                          "WHERE id=:id_found"))
            {
                qDebug() << "Failed to prepare";
                qDebug() << q.lastError().text();
            }

            q.bindValue(":id_found",rutina_def_table[i].id);
            q.bindValue(":nombre",rutina_def_table[i].nombre);
            q.bindValue(":ready",rutina_def_table[i].ready);
            q.bindValue(":periodo",rutina_def_table[i].periodo);
            q.bindValue(":origen",rutina_def_table[i].origen);
            q.bindValue(":state",rutina_def_table[i].state);
            q.bindValue(":synch_date",rutina_def_table[i].synch_date);
            q.bindValue(":last_event",rutina_def_table[i].last_event);
            q.bindValue(":next_event",rutina_def_table[i].next_event);
            q.bindValue(":explicacion",rutina_def_table[i].explicacion);
            q.bindValue(":schedule_to",rutina_def_table[i].schedule_to);
            q.bindValue(":record_links",rutina_def_table[i].record_links);

            if(!q.exec()) qDebug() << "Failed to execute: rutinas load_to_db() " << q.lastError();
//            qDebug() << q.lastQuery();
            while (q.next())
            {
                rutina_def_table[i].id = q.value("id").toInt();
                rutina_def_table[i].nombre = q.value("nombre").toString();
                rutina_def_table[i].ready = q.value("ready").toInt();
                rutina_def_table[i].periodo = q.value("periodo").toInt();
                rutina_def_table[i].origen = q.value("origen").toInt();
                rutina_def_table[i].state = q.value("state").toInt();
                rutina_def_table[i].synch_date = q.value("synch_date").toInt();
                rutina_def_table[i].last_event = q.value("last_event").toInt();
                rutina_def_table[i].next_event = q.value("next_event").toInt();
                rutina_def_table[i].schedule_to = q.value("schedule_to").toInt();
            }


            qDebug() << "Updating DB: "
                     << rutina_def_table[i].id
                     << rutina_def_table[i].nombre
                     << rutina_def_table[i].periodo
                     << rutina_def_table[i].origen
                     << rutina_def_table[i].state
                     << rutina_def_table[i].synch_date
                     << rutina_def_table[i].last_event
                     << rutina_def_table[i].next_event
                     << rutina_def_table[i].schedule_to;

            break;
        }
    }
}

uint rutinas_mantenimiento::find_next_schedule(uint periodo, uint last_event, uint schedule_to)
{
    QDateTime *datetime_last_event;
    QDateTime *datetime_next_event;

    uint i = 0;
    uint absolute_week = 0;
    QDateTime *temp_monday_datetime;

    datetime_last_event = new QDateTime(QDateTime::fromTime_t(last_event));
    switch(periodo)
    {
    case SIN_RUTINA:
        break;
    case RUTINA_DIA:
        // set date at the beggining of the day
        datetime_next_event = new QDateTime(datetime_last_event->date());

        //Add hours  within the same day
        *datetime_next_event = datetime_next_event->addSecs(HOURS_TO_SECONDS(schedule_to));
        //Add a day
        *datetime_next_event = datetime_next_event->addDays(1);
        break;

    case RUTINA_SEMANA:
        // go to the beggining of the week

        // find last thursday and add seconds to next monday
        absolute_week = datetime_last_event->toTime_t() / SECONDS_IN_A_WEEK;
        temp_monday_datetime = new QDateTime(QDateTime::fromTime_t((absolute_week * SECONDS_IN_A_WEEK) + FIRST_MONDAY_EPOCH));

//        if(temp_monday_datetime > datetime_last_event)
//        {
//            datetime_next_event = new QDateTime(QDateTime::fromTime_t(temp_monday_datetime->toTime_t()));
//        }
//        else
//        {
            datetime_next_event = new QDateTime(QDateTime::fromTime_t(temp_monday_datetime->toTime_t()));
            *datetime_next_event = datetime_next_event->addDays(7);
//        }

        // Add days (patch)
        *datetime_next_event = datetime_next_event->addDays(schedule_to);
        // set date at the beggining of the day
        datetime_next_event = new QDateTime(datetime_next_event->date());
        //Add 9 hours  within the same day
        *datetime_next_event = datetime_next_event->addSecs(HOURS_TO_SECONDS(9));
        break;

    case RUTINA_ANIO:
    case RUTINA_MES:
    {
        // set date at the beggining of the month
        QDate *month_date = new QDate(datetime_last_event->date().year(), datetime_last_event->date().month(), 1);
        datetime_next_event = new QDateTime(*month_date);

        //Add 1 month
        *datetime_next_event = datetime_next_event->addMonths(1);
        //Add a day
        if(schedule_to > 1)
        {
            *datetime_next_event = datetime_next_event->addDays(schedule_to - 1);
        }

        // set date at the beggining of the day
        datetime_next_event = new QDateTime(datetime_next_event->date());
        //Add 9 hours  within the same day
        *datetime_next_event = datetime_next_event->addSecs(HOURS_TO_SECONDS(9));


    }
        break;

    default:
        break;
    }

    return datetime_next_event->toTime_t();
}

void rutinas_mantenimiento::set_time(QDateTime time)
{
    global_time = time;
}
