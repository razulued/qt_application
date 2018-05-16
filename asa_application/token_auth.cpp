#include "token_auth.h"
#include <QDebug>
#include "asa_conf_string.h"
#include <QMutex>
QString valid_key = "1234";
QMutex key_mutex;

uint current_user_index = 0;
typedef struct
{
    QString username;
    QString password;
}user_pass;

const user_pass user_pass_table[]=
{
    "Sin usuario",   "",
    "Juan Perez",   "1234",
    "Luis Ramirez", "abc123",
};

bool token_validity = false;

bool check_user_password(QString str)
{
    uint i= 0;
    bool ret = false;

    for(i = 0; i < (sizeof(user_pass_table)/sizeof(user_pass)); i++)
    {
        if(str == user_pass_table[i].password)
        {
            ret = true;
            current_user_index = i;
            break;
        }
        else
        {
            current_user_index = 0;
        }

    }

    return ret;
}

void validate_token(bool val)
{
    if(false == val)
    {
        current_user_index = 0;
    }

    token_validity = val;
    output_token_transfer(val);
    qDebug() << "token_validity " << token_validity;
}

bool get_validity_state()
{
    return token_validity;
}

QString get_user_name()
{
    return user_pass_table[current_user_index].username;
}
