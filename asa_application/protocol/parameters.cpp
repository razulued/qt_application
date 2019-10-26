#include "parameters.h"
#include <QtDebug>
#include <QHash>
#include "protocol/asa_protocol.h"

#define SIMULATION (1)

QHash<uint, uint> active_parameter;
int getParamIndex(unsigned int id);

static void write_active_parameter();

static void write_active_parameter()
{
   QString filename = "active_parameters.txt";
   QFile myFile(filename);
   if (!myFile.open(QIODevice::WriteOnly))
   {
       qDebug() << "Could not write to file:" << filename << "Error string:" << myFile.errorString();
       return;
   }

   QDataStream out(&myFile);
   out.setVersion(QDataStream::Qt_5_7);
   out << active_parameter;
   myFile.close();
}


QHash<uint,uint> load_active_parameters()
{
    QString filename = "active_parameters.txt";
    QFile myFile(filename);

    QDataStream in(&myFile);
    in.setVersion(QDataStream::Qt_5_7);

    if (!myFile.open(QIODevice::ReadOnly))
    {
        //qDebug() << "Could not read the file:" << filename << "Error string:" << myFile.errorString();
        return active_parameter;
    }

    in >> active_parameter;
    myFile.close();

    return active_parameter;
}

QString getParamValue(unsigned int id)
{
    return get_value_by_ID(id);
}

QString getParamValue_base_units(unsigned int id)
{
    return get_value_by_ID_base_units(id);
}

QString getParamValue_RAW(unsigned int id)
{
    return get_RAW_value_by_ID(id);
}


QString invese_getParamValue(unsigned int id, float_t value)
{
    return inverse_value_by_ID_base_units(id, value);
}

QString getParamValue_and_units(unsigned int id)
{
    return get_value_by_ID(id) + " " +get_value_units(id);
}

bool getParamActiveShow(unsigned int id)
{
    return active_parameter.value(id);
}

void toggleParamActiveShow(unsigned int id)
{
    if(0 == active_parameter.value(id))
    {
       active_parameter.insert(id, 1);
    }
    else
    {
        active_parameter.insert(id, 0);
    }

    write_active_parameter();
}

void write_parameter(QString filename, uint value)
{
   QFile myFile(filename);
   if (!myFile.open(QIODevice::WriteOnly))
   {
       qDebug() << "Could not write to file:" << filename << "Error string:" << myFile.errorString();
       return;
   }

   QDataStream out(&myFile);
   out.setVersion(QDataStream::Qt_5_7);
   out << value;
   myFile.close();

}


uint load_parameter(QString filename)
{
    QFile myFile(filename);
    uint value;
    QDataStream in(&myFile);
    in.setVersion(QDataStream::Qt_5_7);

    if (!myFile.open(QIODevice::ReadOnly))
    {
        //qDebug() << "Could not read the file:" << filename << "Error string:" << myFile.errorString();
        return value;
    }

    in >> value;
    myFile.close();

    return value;
}
