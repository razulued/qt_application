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
                        +q.value("log_date").toString()+","
                        +q.value("user").toString();
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

uint sql_cmd_manager::query_last_log_ID()
{
    uint ret;
    QSqlQuery q;

    if(q.prepare("SELECT MAX(log_id) FROM log"))
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
            qDebug() << "query_last_log_ID. Failed to exec." << q.lastError();
        }
    }
    else
    {
        qDebug() << "query_last_log_ID. Failed to prepare." << q.lastError();
    }

    return ret;
}

int sql_cmd_manager::store_activity()
{
    int ret = 0;
    QSqlQuery q;

    qDebug() << "STORE ACTIVITY: " << input_command;
    QStringList list = input_command.split(",");

    //   0      1       2       3        4        5             6
    // ID_table,Name,IDProceso,Periodo,epoch,[Descripcion],[regID,regID...]
    QString id_table     = list.at(0);
    QString Name        = list.at(1);
    QString IDProceso   = list.at(2);
    QString Periodo     = list.at(3);
    QString epoch       = list.at(4);

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


    if( q.prepare("INSERT INTO rutinas(id, nombre, ready, periodo, origen, state, synch_date, last_event, next_event, explicacion, schedule_to, record_links) "
                         "VALUES(:id, :nombre, :ready, :periodo, :origen, :state, :synch_date, :last_event, :next_event, :explicacion, :schedule_to, :record_links)"))
    {
    //    q.bindValue(":id",rutina_def_table[i].id);
        q.bindValue(":id",id_table);
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
            qDebug() << "last query: " << q.lastQuery();
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
        qDebug() << "last query: " << q.lastQuery();
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
    // ID_Table,Descripcion,Tipo,Unit1,Unit2,Unit3
    QString ID_table    = list.at(0);
    QString Descripcion = list.at(1);
    QString Tipo        = list.at(2);
    QString Unit1       = list.at(3);
    QString Unit2       = list.at(4);
    QString Unit3       = list.at(5);

    if(Unit1 == "null" || Unit1 == "NULL") Unit1 = "";
    if(Unit2 == "null" || Unit2 == "NULL") Unit2 = "";
    if(Unit3 == "null" || Unit3 == "NULL") Unit3 = "";

    if(Tipo == "1") Tipo = "NUMBER";
    else if(Tipo == "2") Tipo = "CHOICE";
    else Tipo = "";

    if( q.prepare("INSERT INTO records(id, name, type, field_1, field_2, field_3) "
                         "VALUES(:id, :name, :type, :field_1, :field_2, :field_3)"))
    {
        q.bindValue(":id",ID_table);
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

int sql_cmd_manager::edit_activity()
{
    int ret = 0;
    QSqlQuery q;

    QStringList list = input_command.split(",");

    //validation
    if("" == input_command ||
            list.length() < 5)
    {
        return 0;
    }

    //     1       2       3        4        5             6
    // ID,Name,IDProceso,Periodo,epoch,[Descripcion],[regID,regID...]
    QString ID = list.at(0);
    QString Name = list.at(1);
    QString IDProceso = list.at(2);
    QString Periodo = list.at(3);
    QString epoch = list.at(4);

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

    if(!q.prepare("UPDATE rutinas SET  "
                  "id=:id_found, "
                  "nombre=:nombre, "
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
    else
    {
        q.bindValue(":id_found",ID);
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
            qDebug() << q.lastError() << "edit_activity";
        }
        else
        {
            // Reload table
            rutinas_mantenimiento::update_db = true;
        }
    }

    return ret;
}
int sql_cmd_manager::edit_record()
{
    int ret = 0;
    QSqlQuery q;

    QStringList list = input_command.split(",");

    //validation
    if("" == input_command ||
            list.length() < 4)
    {
        return 0;
    }
    //  0      1       2     3     4     5
    // ID,Descripcion,Tipo,Unit1,Unit2,Unit3
    QString ID = list.at(0);
    QString Descripcion = list.at(1);
    QString Tipo = list.at(2);
    QString Unit1 = list.at(3);
    QString Unit2 = list.at(4);
    QString Unit3 = list.at(5);

    if(Unit1 == "null" || Unit1 == "NULL") Unit1 = "";
    if(Unit2 == "null" || Unit2 == "NULL") Unit2 = "";
    if(Unit3 == "null" || Unit3 == "NULL") Unit3 = "";

    if(Tipo == "1") Tipo = "NUMBER";
    else if(Tipo == "2") Tipo = "CHOICE";
    else Tipo = "";

    if( q.prepare("UPDATE records SET "
                  "name=:name, "
                  "type=:type, "
                  "field_1=:field_1, "
                  "field_2=:field_2, "
                  "field_3=:field_3 "
                  "WHERE id=:id_found"))
    {
        q.bindValue(":id_found",ID);
        q.bindValue(":name",Descripcion);
        q.bindValue(":type",Tipo);
        q.bindValue(":field_1", Unit1);
        q.bindValue(":field_2", Unit2);
        q.bindValue(":field_3", Unit3);

        if(!q.exec())
        {
            qDebug() << q.lastError().text() << "edit_record";
            qDebug() << q.lastQuery();
        }
        else
        {
            // Reload table
//            rutinas_mantenimiento::update_db = true;
        }
    }
    else
    {
        qDebug() << q.lastError().text() << "edit_record";
        qDebug() << q.lastQuery();

    }

    return ret;
}
int sql_cmd_manager::delete_activity()
{
    int ret = 0;
    QSqlQuery q;


    if( q.prepare("DELETE FROM rutinas WHERE id = :id_wanted"))
    {
        q.bindValue(":id_wanted",input_command);

        if(!q.exec())
        {
            qDebug() << q.lastError().text() << "delete_activity";
            qDebug() << q.lastQuery();
        }
        else
        {
            // Reload table
            rutinas_mantenimiento::update_db = true;
        }
    }
    else
    {
        qDebug() << q.lastError().text() << "delete_activity";
        qDebug() << q.lastQuery();

    }

    return ret;
}
int sql_cmd_manager::delete_record()
{
    int ret = 0;
    QSqlQuery q;


    if( q.prepare("DELETE FROM records WHERE id = :id_wanted"))
    {
        q.bindValue(":id_wanted",input_command);

        if(!q.exec())
        {
            qDebug() << q.lastError().text() << "delete_record";
            qDebug() << q.lastQuery();
        }
        else
        {
            // Reload table
//            rutinas_mantenimiento::update_db = true;
        }
    }
    else
    {
        qDebug() << q.lastError().text() << "delete_record";
        qDebug() << q.lastQuery();

    }

    return ret;
}
