#include "rutinas_mantenimiento.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>

def_rutina_t rutina_def_table[]=
{
    {"Revisar Balance de Aire en Difusores",        1,  1,  RUTINA_DIA,     ORIGEN_REACTOR,         STATE_NEW, 0, 0, 0,
    "Revisar visualmente en cada cámara aireada que se tenga suficiente aire sin que haya exceso de movimiento.",
     ""
    },

    {"Revisar Promedio Retorno de Lodo",            2,  1,  RUTINA_DIA,     ORIGEN_CLARIFICADOR,    STATE_NEW, 0, 0, 0,
    "Medir el flujo de retorno de lodos. Utiliza una cubeta de volumen conocido y mide en cuánto tiempo se llena; midiendo siempre en el mismo retorno.",
     "- ¿Cuál fue el volumen captado?\n"
     "__ Litros\n"
     "- ¿En cuánto tiempo se llenó?\n"
     "__ segundos"
    },

    {"Revisar y limpiar Vertedero clarificador",    3,  1,  RUTINA_DIA,     ORIGEN_CLARIFICADOR,    STATE_NEW, 0, 0, 0,
    "Limpiar y retirar basura, algas y sobrenadantes que se encuentren en los dientes de los vertederos de entrada y salida.",
     ""
    },

    {"Raspar la tolva",                             4,  1,  RUTINA_DIA,     ORIGEN_CLARIFICADOR,    STATE_NEW, 0, 0, 0,
    "Colocar el cepillo en el mango telescópico y limpiar cuidadosamente todas las paredes del clarificador. "
     "Comenzar en la parte superior, recargar el cepillo en la pared y bajar lentamente, al terminar despegar el cepillo y sacarlo lentamente.",
     ""
    },

    {"Limpiar Superficie del clarificador",         5,  1,  RUTINA_DIA,     ORIGEN_CLARIFICADOR,    STATE_NEW, 0, 0, 0,
    "Colocar la red en el mango telescópico y retirar manualmente sólidos flotantes, basura y nata de la superficie del clarificador.",
     ""
    },

    {"Realizar Pruebas de Sedimentacion",           6,  1,  RUTINA_DIA,     ORIGEN_CLARIFICADOR,    STATE_NEW, 0, 0, 0,
    "Con los sopladores en operación tomar una muestra de 1 Litro en la probeta o cono de Imhoff. Dejar media hora en reposo a la sombra.",
     "- Cantidad de sólidos sedimentados.\n"
     "__ mL/L\n"
     "- ¿Hubo flotación de lodos?\n"
     "Sí/No"
    },

    {"Verificar Medidor de Flujo",                  7,  1,  RUTINA_DIA,     ORIGEN_EFLUENTE,        STATE_NEW, 0, 0, 0,
    "Necesita explicación",
     ""
    },

    {"Verificar Medidor de Flujo",                  8,  1,  RUTINA_DIA,     ORIGEN_AFLUENTE,        STATE_NEW, 0, 0, 0,
    "Necesita explicación",
     ""
    },

    {"Revisión y limpieza en pretratamiento",       9,  1,  RUTINA_SEMANA,  ORIGEN_REGULADOR,       STATE_NEW, 0, 0, 0,
    "Retirar sólidos acumulados en canastilla. Realizar limpieza general en área de pretratamiento. En caso de ser necesario, realizar la actividad con mayor frecuencia.",
     ""
    },

    {"Limpieza General de la Planta",               11,  1,  RUTINA_SEMANA,  ORIGEN_GENERAL,         STATE_NEW, 0, 0, 0,
    "Realizar limpieza general sobre la planta y alrededores; barrer, recoger basura, lavar pisos conforme a necesidad.",
     ""
    },

    {"Revisar Fugas en válvulas de aire",           12,  1,  RUTINA_MES,     ORIGEN_GENERAL,         STATE_NEW, 0, 0, 0,
    "Verificar visualmente que no haya fuga en las válvulas de aire. Si se sospecha que hay fuga en alguna, corroborar con una solución jabonosa.",
     "- ¿Hubo fuga de aire en alguna válvula?\n"
     "Sí/No"
    },


    {"Tomar Muestra en el Efluente",                13,  1,  RUTINA_MES,     ORIGEN_CLORADOR,        STATE_NEW, 0, 0, 0,
    "Tomar una muestra de agua en el efluente y realizar pruebas de calidad apropiadas.",
     "- Claridad\n"
     "Buena/Media/Mala\n"
     "- Sólidos Suspendidos Totales\n"
     "Medidos/No medidos\n"
     "__ mg/L\n"
     "- Cloro residual\n"
     "mg/L\n"
     "- pH\n"
     "__"
    },

    {"Lubricar Candados",                           14,  1,  RUTINA_MES,     ORIGEN_GENERAL,         STATE_NEW, 0, 0, 0,
    "Realizar lubricación de candados con aceite apropiado.",
     ""
    },

    {"Revisar Tensión y Desgaste en Bandas",        15,  1,  RUTINA_MES,     ORIGEN_REACTOR,         STATE_NEW, 0, 0, 0,
    "Parar el soplador, retirar las válvulas y revisar que se encuentren en buen estado.",
     "- ¿Las bandas se encuentran en buen estado?\n"
     "Sí/No\n"
     "Cantidad de bandas en mal estado\n"
     "__ bandas"
    },

    {"Verificar Alineacion de Poleas",              16,  1,  RUTINA_MES,     ORIGEN_REACTOR,         STATE_NEW, 0, 0, 0,
    "Parar el soplador y revisar que las poleas se encuentren apropiadamente alineadas.",
     "- ¿Fue necesario realizar un ajuste a la alineación de poleas?\n"
     "Sí/No"
    },

    {"Lubricar Chumaceras",                         17,  1,  RUTINA_MES,     ORIGEN_REACTOR,         STATE_NEW, 0, 0, 0,
    "Parar el soplador  realizar lubricación con grasa en motores, dando un par de bombeos con la grasera en cada punto de lubricación.",
     "- ¿La grasa excedente se ve quemada?\n"
     "Sí/No"
    },

    {"Limpiar Ventilación de Motores",              18,  1,  RUTINA_MES,     ORIGEN_REACTOR,         STATE_NEW, 0, 0, 0,
    "Parar el soplador y realizar limpieza manual de los puntos de ventilación de soplador y motor.",
     ""
    },

    {"Verificar Nivel de Aceite en Sopladores",     19,  1,  RUTINA_MES,     ORIGEN_REACTOR,         STATE_NEW, 0, 0, 0,
    "Parar el soplador y revisar nivel actual de aceite. Rellenar en caso de ser necesario.",
     "- ¿Se requirió llenado de aceite?\n"
     "Sí/No\n"
     "- Cantidad de aceite agregado\n"
     "__ mL"
    },

    {"Limpiar Filtros de Aire",                     20,  1,  RUTINA_MES,     ORIGEN_REACTOR,         STATE_NEW, 0, 0, 0,
    "Parar el soplador, retirar cubierta metálica y realizar limpieza del filtro de aire.",
     "- Estado del filtro de aire\n"
     "Bueno/Medio/Malo"
    },

    {"Limpiar Valvulas de Alivio",                  21,  1,  RUTINA_MES,     ORIGEN_REACTOR,         STATE_NEW, 0, 0, 0,
    "Necesita explicación",
     ""
    },

    {"Limpiar y Pintar Partes Metálicas",           22,  1,  RUTINA_ANIO,    ORIGEN_GENERAL,         STATE_NEW, 0, 0, 0,
    "Necesita explicación",
    ""
    },

    {"Revisar Terminales y Disparadores",           23,  1,  RUTINA_ANIO,    ORIGEN_GENERAL,         STATE_NEW, 0, 0, 0,
    "Necesita explicación",
    ""
    },
};

uint rutinas_mantenimiento::num_of_rutinas = sizeof(rutina_def_table)/sizeof(def_rutina_t);

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
                       "explicacion VARCHAR(1024)"
                       ")"))
            {
                qDebug() << "Error: exec";
            }
            init_db();
        }


        uint i = 0;
        for(i = 0; i < num_of_rutinas; i++)
        {
            load_to_table(rutina_def_table[i].id);
        }
    }

}

rutinas_mantenimiento::~rutinas_mantenimiento()
{
    m_db.close();
    delete this;
}

void rutinas_mantenimiento::init_db(void)
{
    unsigned int i;
    QSqlQuery q;

    if(QFileInfo::exists(db_path))
    {
        for(i = 0; i < num_of_rutinas; i++)
        {
            q.prepare("INSERT INTO rutinas(id, nombre, ready, periodo, origen, state, synch_date, last_event, next_event, explicacion) "
                      "VALUES(:id, :nombre, :ready, :periodo, :origen, :state, :synch_date, :last_event, :next_event, :explicacion)");
            q.bindValue(":id",rutina_def_table[i].id);
            q.bindValue(":nombre",rutina_def_table[i].nombre);
            q.bindValue(":ready",rutina_def_table[i].ready);
            q.bindValue(":periodo", rutina_def_table[i].periodo);
            q.bindValue(":origen", rutina_def_table[i].origen);
            q.bindValue(":state", rutina_def_table[i].state);
            q.bindValue(":synch_date", rutina_def_table[i].synch_date);
            q.bindValue(":last_event", rutina_def_table[i].last_event);
            q.bindValue(":next_event", rutina_def_table[i].next_event);
            q.bindValue(":explicacion", rutina_def_table[i].explicacion);

            if(!q.exec())
            {
                qDebug() << q.lastError().text();
            }
        }
    }
    else
    {
        qDebug() << "Database doesn't exists";
    }

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

        rutina_def_table[index].state = STATE_SET_LAST_EVENT;
        break;
    case STATE_SET_LAST_EVENT:
        if(0 == rutina_def_table[index].last_event)
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
        rutina_def_table[index].next_event = rutina_def_table[index].last_event + (rutina_def_table[index].periodo * MULTIPLICADOR);
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
    case STATE_ADD_HOURS:
        rutina_def_table[index].ready = 1;
        rutina_def_table[index].state = STATE_WAIT_FOR_NEXT_EVENT;
        load_to_db(rutina_def_table[index].id);
        break;
    default:
        break;
    }
}

void rutinas_mantenimiento::complete_rutina(uint rutina)
{
    QDateTime *time;

    time = new QDateTime(get_current_time());
    rutina_def_table[rutina].next_event = time->toTime_t();

    rutina_def_table[rutina].state = STATE_COMPLETE;
}

void rutinas_mantenimiento::add_seconds_rutina(uint rutina, uint seconds)
{
    QDateTime *time;

    time = new QDateTime(get_current_time());
    rutina_def_table[rutina].next_event = time->toTime_t() + seconds;

    rutina_def_table[rutina].state = STATE_ADD_HOURS;
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
    return rutina_def_table[rutina].texto_ayuda;
}

QString rutinas_mantenimiento::explicacion(uint rutina)
{
    return rutina_def_table[rutina].explicacion;
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
#if (1 == USE_DEBUG)
    return QDateTime::currentDateTime();
#else
#define MULTIPLICADOR (3600 * 24)  /* Seconds in a day */
    return global_time;
#endif
}

void rutinas_mantenimiento::load_to_table(uint id)
{
    qDebug() << "Load ID " << id;
    uint i = 0;
    QSqlQuery q;


    // Search ID
    for(i = 0; i < num_of_rutinas; i++)
    {
        if(rutina_def_table[i].id == id)
        {
            //SELECT body FROM tbl_index WHERE id = 937
            if(!q.prepare("SELECT * FROM rutinas WHERE id = :id_found")) qDebug() << "Failed to prepare";

            q.bindValue(":id_found",rutina_def_table[i].id);

            if(!q.exec()) qDebug() << "Failed to execute";

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
            }


            qDebug() << "Save to table"
                     << rutina_def_table[i].id
                     << rutina_def_table[i].nombre
                     << rutina_def_table[i].periodo
                     << rutina_def_table[i].origen
                     << rutina_def_table[i].state
                     << rutina_def_table[i].synch_date
                     << rutina_def_table[i].last_event
                     <<rutina_def_table[i].next_event;
        }
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
                          "ready=:ready, "
                          "state=:state, "
                          "synch_date=:synch_date, "
                          "last_event=:last_event, "
                          "next_event=:next_event "
                          "WHERE id=:id_found"))
            {
                qDebug() << "Failed to prepare";
                qDebug() << q.lastError().text();
            }

            q.bindValue(":ready",rutina_def_table[i].ready);
            q.bindValue(":state",rutina_def_table[i].state);
            q.bindValue(":synch_date",rutina_def_table[i].synch_date);
            q.bindValue(":last_event",rutina_def_table[i].last_event);
            q.bindValue(":next_event",rutina_def_table[i].next_event);
            q.bindValue(":id_found",rutina_def_table[i].id);

            if(!q.exec()) qDebug() << "Failed to execute";

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
            }


            qDebug() << "Updating DB: "
                     << rutina_def_table[i].id
                     << rutina_def_table[i].nombre
                     << rutina_def_table[i].periodo
                     << rutina_def_table[i].origen
                     << rutina_def_table[i].state
                     << rutina_def_table[i].synch_date
                     << rutina_def_table[i].last_event
                     <<rutina_def_table[i].next_event;
        }
    }
}

void rutinas_mantenimiento::set_time(QDateTime time)
{
    global_time = time;
}
