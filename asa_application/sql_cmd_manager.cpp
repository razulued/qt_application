#include "sql_cmd_manager.h"
#include <QDebug>
#include <QRegularExpression>
#include "rutinas_mantenimiento.h"

sql_cmd_manager::sql_cmd_manager(QString str)
{
    input_command = str;
}

sql_cmd_manager::~sql_cmd_manager()
{

}

uint sql_cmd_manager::query_last_id_last_activity()
{
    uint ret = 0;
    QSqlQuery q;

    if(q.prepare("SELECT MAX(id) FROM rutinas"))
    {
        if(q.exec())
        {
            while(q.next())
            {
                ret = q.value(0).toInt();
            }
        }
        else
        {
            qDebug() << "query_last_id_last_activity. Failed to exec." << q.lastError();
        }
    }
    else
    {
        qDebug() << "query_last_id_last_activity. Failed to prepare." << q.lastError();
    }

    return ret;
}

uint sql_cmd_manager::query_last_id_last_record()
{
    uint ret = 0;
    QSqlQuery q;

    if(q.prepare("SELECT MAX(id) FROM records"))
    {
        if(q.exec())
        {
            while(q.next())
            {
                ret = q.value(0).toInt();
            }
        }
        else
        {
            qDebug() << "query_last_id_last_record. Failed to exec." << q.lastError();
        }
    }
    else
    {
        qDebug() << "query_last_id_last_record. Failed to prepare." << q.lastError();
    }

    return ret;
}

QString sql_cmd_manager::query_N_log()
{
    QString ret;
    QSqlQuery q;

    if(q.prepare("SELECT * FROM log WHERE log_id = :id_wanted"))
    {
        q.bindValue(":id_wanted",input_command);
        if(q.exec())
        {
            while(q.next())
            {
                ret = q.value("log_id").toString()+","
                        +q.value("rutina_id").toString()+","
                        +q.value("record_id").toString()+","
                        +q.value("record_value").toString()+","
                        +q.value("log_date").toString();
            }
        }
        else
        {
            qDebug() << "query_N_record. Failed to exec." << q.lastError();
        }
    }
    else
    {
        qDebug() << "query_N_record. Failed to prepare." << q.lastError();
    }

    return ret;
}

int sql_cmd_manager::store_activity()
{
    int ret = 0;
    QSqlQuery q;

    QStringList list = input_command.split(",");

    //   0      1       2       3        4              5
    // Name,IDProceso,Periodo,epoch,[Descripcion],[regID,regID...]
    QString Name = list.at(0);
    QString IDProceso = list.at(1);
    QString Periodo = list.at(2);
    QString epoch = list.at(3);

    qDebug() << "LA LISTA: " << Name << IDProceso << Periodo << epoch;

    uint i = 0;
    bool left_found = false;
    uint ini_index = 0;
    uint end_index = 0;

    // Get description
    QString Descripcion;
    for(i = 0; i < (uint)input_command.length(); i++)
    {
        if(left_found == false)
        {
            if(input_command.at(i) == '[')
            {
                // Left [ found
                left_found = true;
                ini_index = i;
            }
        }
        else
        {
            if(input_command.at(i) == ']')
            {
                // Left [ found
                left_found = false;
                end_index = i;
                Descripcion = input_command.mid(ini_index +1, (end_index - ini_index -1));
                break;
            }
        }
    }
    qDebug() << "Descripcion: " << Descripcion;

    // Get description
    QString RegIDs;
    for(i = end_index; i < (uint)input_command.length(); i++)
    {
        if(left_found == false)
        {
            if(input_command.at(i) == '[')
            {
                // Left [ found
                left_found = true;
                ini_index = i;
            }
        }
        else
        {
            if(input_command.at(i) == ']')
            {
                // Left [ found
                left_found = false;
                end_index = i;
                RegIDs = input_command.mid(ini_index +1, (end_index - ini_index -1));
                break;
            }
        }
    }
    qDebug() << "RegIDs: " << RegIDs;


    if( q.prepare("INSERT INTO rutinas(nombre, ready, periodo, origen, state, synch_date, last_event, next_event, explicacion, schedule_to, record_links) "
                         "VALUES(:nombre, :ready, :periodo, :origen, :state, :synch_date, :last_event, :next_event, :explicacion, :schedule_to, :record_links)"))
    {
    //    q.bindValue(":id",rutina_def_table[i].id);
        q.bindValue(":nombre",Name);
        q.bindValue(":ready",0);
        q.bindValue(":periodo", Periodo);
        q.bindValue(":origen", IDProceso);
        q.bindValue(":state", 0);
        q.bindValue(":synch_date", 0);
        q.bindValue(":last_event", 0);
        q.bindValue(":next_event", epoch);
        q.bindValue(":explicacion", Descripcion);
        q.bindValue(":schedule_to", 0);
        q.bindValue(":record_links", RegIDs);

        if(!q.exec())
        {
            qDebug() << q.lastError().text() << "store_activity";
        }
        else
        {
            // Reload table
            rutinas_mantenimiento::update_db = true;
        }
    }
    else
    {
        qDebug() << q.lastError().text() << "store_activity";
    }

    return ret;
}

int sql_cmd_manager::store_record()
{
    int ret = 0;
    QSqlQuery q;

    QStringList list = input_command.split(",");

    //   0      1       2       3     4
    // Descripcion,Tipo,Unit1,Unit2,Unit3
    QString Descripcion = list.at(0);
    QString Tipo = list.at(1);
    QString Unit1 = list.at(2);
    QString Unit2 = list.at(3);
    QString Unit3 = list.at(4);

    if(Unit1 == "null" || Unit1 == "NULL") Unit1 = "";
    if(Unit2 == "null" || Unit2 == "NULL") Unit2 = "";
    if(Unit3 == "null" || Unit3 == "NULL") Unit3 = "";

    if(Tipo == "1") Tipo = "NUMBER";
    else if(Tipo == "2") Tipo = "CHOICE";
    else Tipo = "";

    if( q.prepare("INSERT INTO records(name, type, field_1, field_2, field_3) "
                         "VALUES(:name, :type, :field_1, :field_2, :field_3)"))
    {
        q.bindValue(":name",Descripcion);
        q.bindValue(":type",Tipo);
        q.bindValue(":field_1", Unit1);
        q.bindValue(":field_2", Unit2);
        q.bindValue(":field_3", Unit3);

        if(!q.exec())
        {
            qDebug() << q.lastError().text() << "store_record";
        }
        else
        {
            // Reload table
//            rutinas_mantenimiento::update_db = true;
        }
    }
    else
    {
        qDebug() << q.lastError().text() << "store_record";
    }

    return ret;
}
