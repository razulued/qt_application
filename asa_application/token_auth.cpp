#include "token_auth.h"
#include <QDebug>
#include "asa_conf_string.h"
#include <QMutex>
#include <QSettings>
#include <QDir>
#include <QCryptographicHash>

QMutex key_mutex;

QString current_user_key;

bool token_validity = false;

bool check_user_password(QString str)
{
    bool ret = false;

    QString hash_password = QString(QCryptographicHash::hash(str.toLocal8Bit(),QCryptographicHash::Sha1).toHex());

    //Open access.ini
    QSettings conf(QDir::currentPath() + "/access.ini", QSettings::IniFormat);
    conf.sync();
    conf.beginGroup("Passwords");
    QList<QString> current_passwords = conf.childKeys();
    foreach(const QString &key, current_passwords)
    {
        if(key == hash_password)
        {
//            qDebug() << "KEY FOUND - ID: " << conf.value(key);
            current_user_key = key;
            ret = true;
            break;
        }
    }
    conf.endGroup();

    return ret;
}

void validate_token(bool val)
{
    if(false == val)
    {
        current_user_key = "";
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
    QString username = QObject::tr("Sin Usuario");
    QSettings conf(QDir::currentPath() + "/access.ini", QSettings::IniFormat);
    conf.sync();
    conf.beginGroup("Passwords");
    QList<QString> current_passwords = conf.childKeys();
    foreach(const QString &key, current_passwords)
    {
        if(key == current_user_key)
        {
            username = conf.value(key).toString();
            break;
        }
    }
    conf.endGroup();
    return username;
}

QString get_user_initials(void)
{
    QString name = get_user_name();
    QString initials;

    uint i = 0;
    bool next_char_is_initial = true;

    for(i = 0; i < (uint)name.length(); i++)
    {
        if((true == next_char_is_initial) && name.at(i).isLetter())
        {
            initials.append(name.at(i));
            next_char_is_initial = false;
        }

        if(name.at(i).isNull() || name.at(i).isSpace())
        {
            next_char_is_initial = true;
        }
    }

    return initials;
}
