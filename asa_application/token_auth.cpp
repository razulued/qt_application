#include "token_auth.h"
#include <QDebug>
QString valid_key = "1234";

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
    qDebug() << "token_validity " << token_validity;
}
