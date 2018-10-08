#ifndef SQL_CMD_MANAGER_H
#define SQL_CMD_MANAGER_H
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
class sql_cmd_manager
{
public:
    sql_cmd_manager(QString str);
    ~sql_cmd_manager();

    uint query_last_id_last_activity();
    uint query_last_id_last_record();

    QString query_N_log();
    int store_activity();
    int store_record();
    uint query_last_log_ID();

    int edit_activity();
    int edit_record();
    int delete_activity();
    int delete_record();
private:
    QString input_command;
};

#endif // SQL_CMD_MANAGER_H
