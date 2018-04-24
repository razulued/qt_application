#include "token_auth.h"
#include <QDebug>
#include "asa_conf_string.h"
#include <QMutex>
QString valid_key = "1234";
QMutex key_mutex;


bool token_validity = false;

bool check_user_password(QString str)
{
    bool ret = false;

    if(str == valid_key)
    {
        ret = true;
    }

    return ret;
}

void validate_token(bool val)
{
    token_validity = val;
    output_token_transfer(val);
    qDebug() << "token_validity " << token_validity;
}

bool get_validity_state()
{
    return token_validity;
}
