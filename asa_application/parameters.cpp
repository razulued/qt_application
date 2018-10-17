#include "parameters.h"
#include <QtDebug>
#include <QHash>
#include "asa_protocol.h"

#define SIMULATION (1)

QHash<uint, uint> active_parameter;
int getParamIndex(unsigned int id);

static void write_active_parameter();


void run_simulation()
{
//    static uint state = 0;
//    static uint last_time = 0;

//    if(last_time == 0)
//    {
//        last_time = QDateTime::currentDateTime().toTime_t();
//    }

//    switch(state)
//    {
//    case 0:
//        //Todo apagado
//        *(double *)all_parameters[getParamIndex(44)].param = 0;
//        *(double *)all_parameters[getParamIndex(92)].param = 0;

//        //Caudal in (43)
//        *(double *)all_parameters[getParamIndex(43)].param = 0;
//        // Nivel
//        *(double *)all_parameters[getParamIndex(40)].param = 5;
//        break;
//    case 1:
//        // Entra flujo

//        // Caudal in (43)
//        *(double *)all_parameters[getParamIndex(43)].param = 10;
//        break;

//    case 2:
//        // Sube Nivel carcamo
//        *(double *)all_parameters[getParamIndex(40)].param = 20; //low
//        break;
//    case 3:
//        *(double *)all_parameters[getParamIndex(40)].param = 40; // med
//        break;
//    case 4:
//        *(double *)all_parameters[getParamIndex(40)].param = 80; // full
//        break;

//    case 5:
//        // Se prenden motor
//        *(double *)all_parameters[getParamIndex(44)].param = 1;
//        break;

//    case 6:
//        // Se prende aereador en reactor
//        *(double *)all_parameters[getParamIndex(92)].param = 1;
//        break;

//    case 7:
//        // Retorno de lodo
//        *(double *)all_parameters[getParamIndex(145)].param = 40;
//        break;

//    case 8:
//        // Caudal out
//        *(double *)all_parameters[getParamIndex(162)].param = 50;
//        break;

//    case 9:
//        // Caudal in
//        *(double *)all_parameters[getParamIndex(43)].param = 0;
//        break;

//    case 10:
//        // Nivel de carcamo
//        *(double *)all_parameters[getParamIndex(40)].param = 40; // med
//        break;

//    case 11:
//        // Nivel de carcamo
//        *(double *)all_parameters[getParamIndex(40)].param = 20; // low
//        break;

//    case 12:
//        // Apagar carcamo
//        *(double *)all_parameters[getParamIndex(44)].param = 0;
//        *(double *)all_parameters[getParamIndex(40)].param = 0;
//        // Apagar retorno de lodos
//        *(double *)all_parameters[getParamIndex(145)].param = 0;
//        break;

//    case 13:
//        // Se apaga aereador en reactor
//        *(double *)all_parameters[getParamIndex(92)].param = 0;
//        break;

//    case 14:
//        // Caudal out
//        *(double *)all_parameters[getParamIndex(162)].param = 0;
//        break;

//    default:
//        //back to 0
//        state = 0;
//        break;
//    }


//    if((QDateTime::currentDateTime().toTime_t() - last_time) > 4)
//    {
//        // Move to next state
//        state++;
//        last_time = QDateTime::currentDateTime().toTime_t();
////        qDebug() << "Next state " << state;
//    }
}

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


QString invese_getParamValue(unsigned int id, float_t value)
{
    return inverse_value_by_ID_base_units(id, value);
}

QString getParamValue_and_units(unsigned int id)
{
    return get_value_by_ID(id) + get_value_units(id);
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
    return value;
}
