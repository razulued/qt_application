#include "asa_conversions.h"
#include "sql_cmd_manager.h"
#include "asa_conf_string.h"


// Receive functions.
void Query_ID_last_activity(QString str)
{
    QString str_response;
    qDebug() << "Query_ID_last_activity: " << str;

    sql_cmd_manager *query = new sql_cmd_manager(str);
    str_response = "1900:" + QString::number(query->query_last_id_last_activity()) +"|";
    qDebug() << "Query_ID_last_activity(response): " << str_response;

    add_to_one_time_transmit(str_response);
    query->~sql_cmd_manager();
}

void Query_ID_last_record(QString str)
{
    QString str_response;
    qDebug() << "Query_ID_last_record: " << str;
    sql_cmd_manager *query = new sql_cmd_manager(str);
    str_response = "1901:" + QString::number(query->query_last_id_last_record()) +"|";
    qDebug() << "Query_ID_last_record(response): " << str_response;

    add_to_one_time_transmit(str_response);
    query->~sql_cmd_manager();
}

void Query_N_record(QString str)
{
    QString str_response;
    qDebug() << "Query_N_record: " << str;
    sql_cmd_manager *query = new sql_cmd_manager(str);
    str_response = "1902:" + query->query_N_log() +"|";
    qDebug() << "Query_N_record(response): " << str_response;
    add_to_one_time_transmit(str_response);
    query->~sql_cmd_manager();
}

void Query_last_log(QString str)
{
    QString str_response;
    qDebug() << "Query_last_log: " << str;

    sql_cmd_manager *query = new sql_cmd_manager(str);
    str_response = "1903:" + QString::number(query->query_last_log_ID()) +"|";
    qDebug() << "Query_last_log(response): " << str_response;

    add_to_one_time_transmit(str_response);
    query->~sql_cmd_manager();
}


void Store_activity(QString str)
{
    sql_cmd_manager *query = new sql_cmd_manager(str);
    qDebug() << "Store_activity: " << str;

    qDebug() << "Store_activity(return): " << query->store_activity();
    query->~sql_cmd_manager();
}

void Store_record(QString str)
{
    qDebug() << "NEW RECORD:STRING: " << str;
    qDebug() << "Store_record: " << str;

    sql_cmd_manager *query = new sql_cmd_manager(str);
    qDebug() << "Store_record(return)" << query->store_record();
    query->~sql_cmd_manager();
}

void Edit_activity(QString str)
{
    sql_cmd_manager *query = new sql_cmd_manager(str);
    qDebug() << "Edit_activity: " << str;
    qDebug() << "Edit_activity(return): " << query->edit_activity();
    query->~sql_cmd_manager();
}

void Edit_record(QString str)
{
    sql_cmd_manager *query = new sql_cmd_manager(str);
    qDebug() << "Edit_record: " << str;
    qDebug() << "Edit_record(return): " << query->edit_record();
    query->~sql_cmd_manager();
}

void Delete_activity(QString str)
{
    sql_cmd_manager *query = new sql_cmd_manager(str);
    qDebug() << "Delete_activity: " << str;
    qDebug() << "Delete_activity(return): " << query->delete_activity();
    query->~sql_cmd_manager();
}

void Delete_record(QString str)
{
    sql_cmd_manager *query = new sql_cmd_manager(str);
    qDebug() << "Delete_record: " << str;
    qDebug() << "Delete_record(return): " << query->delete_record();
    query->~sql_cmd_manager();
}
