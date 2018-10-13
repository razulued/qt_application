#include "dataproccess.h"
#include <QDebug>
#include "parameters.h"
#include "asa_protocol.h"
#include "mainwindow.h"
#include "build_settings.h"

DataProccess::DataProccess(QObject *parent)
{
#if (1 == RELEASE_FOR_RPI)
    spiObj = spiObj->SPInstance();
#else
    // Will use random numbers

#endif
}

DataProccess::~DataProccess()
{
    delete spiObj;
}

void DataProccess::run()
{
    // Init motors not available
    store_value_by_ID(0x4000, "3");
    store_value_by_ID(0x4010, "3");
    store_value_by_ID(0x4020, "3");
    store_value_by_ID(0x4030, "3");

    store_value_by_ID(0x3000, "3");
    store_value_by_ID(0x3010, "3");
    store_value_by_ID(0x3020, "3");
    store_value_by_ID(0x3030, "3");

    store_value_by_ID(0x9000, "3");
    store_value_by_ID(0x9010, "3");
    store_value_by_ID(0x9020, "3");
    store_value_by_ID(0x9030, "3");
    store_value_by_ID(0x9080, "3");

    while(1)
    {
        if(false == MainWindow::simulation)
        {
#if (1 == RELEASE_FOR_RPI)

            this->dataSPI();
#endif
            QThread::msleep(200);
        }
        else
        {
            this->dataRandom();
            QThread::msleep(1000);
        }
        spi_read_completed();
    }
}

int DataProccess::hexString2Int(QString inputString)
{
    int temp;
    bool ok;
    temp = inputString.toInt(&ok,16); //Casting from String to Int (Hexadecimal representation)
    return temp;
}

int DataProccess::intString2Int(QString inputString)
{
    int temp;
    bool ok;
//    temp = inputString.toInt(); //Casting from String to Int (Hexadecimal representation)
    temp = inputString.toInt(&ok,16); //Casting from String to Int (Hexadecimal representation)

    if(false == ok)
    {
        temp = 0;
    }
    return temp;
}



//void DataProccess::dataTimerSlot()
//{
//    this->dataSPI();
//}

void DataProccess::dataSPI()
{
    static bool send_ASA_Conf = false;

    if(true == send_ASA_Conf)
    {
        qDebug() << "Send data";
        send_ASA_Conf = false;

        spiObj->sendSPIdata();
    }
    else
    {
        QString bufferString;
        char *SPIinfo = spiObj->getSPIdata();
        //    QRegExp separator("(<|>)");
        //    QStringList initial = str.split(separator);
        bufferString =  QString(SPIinfo);   //Cast Char array to STRING


        send_ASA_Conf = true;
        qDebug() << "Receive data";

        QStringList ID_Parameters = bufferString.split("|");
        QStringList realParameters ;

        qDebug() << "Number of parameters: " << ID_Parameters.length();
        for(int i = 0; i < ID_Parameters.length() ; i++)
        {
            realParameters = ID_Parameters[i].split(":");

            if(realParameters.length() > 1)
            {
//                qDebug() << "+++++++" << realParameters[0] << realParameters[1];
                store_value_by_ID(intString2Int(realParameters[0]) , realParameters[1]);
            }
            else
            {
                // only one part was found, this could be a zero lengh ID
//                qDebug() << "++++(Z)" << realParameters[0];
                store_value_by_ID(intString2Int(realParameters[0]) , "");
            }
        }
    }
}

void DataProccess::dataRandom()
{
//    int i = 0;
//    uint random = 0;
//    static int count = 0;
//    //Add here IDs to generate random numbers
//    QList<int> id_list = QList<int>() << 0x3001 << 0x3002 << 0x3003 << 0x3004 << 0x3005 << 0x3006
//                                      << 0x3203 << 0x4203 << 0x5201 << 0x3201 << 0x4204 << 0x8204
//                                      << 0x3307 << 0x3305 << 0x3303 << 0x3301 << 0x5307 << 0x5305 << 0x5303 << 0x5301;

//    for(i = 0; i < id_list.size(); i++)
//    {
//        store_value_by_ID(id_list.at(i), QString::number(random));
//    }

//    store_value_by_ID((0x3201), "64");
//    if(0 == count)
//    {
//        count = 1;
//        store_value_by_ID((0x3000), "1");
//    }
//    else
//    {
//        count = 0;
//        store_value_by_ID(0x3000, "1");
//    }
////    qDebug() << "count " << count;
///
//    store_value_by_ID(0x4000, "3");
//    store_value_by_ID(0x4010, "3");
//    store_value_by_ID(0x4020, "3");
//    store_value_by_ID(0x4030, "3");

//    store_value_by_ID(0x3000, "1");
//    store_value_by_ID(0x3010, "3");
//    store_value_by_ID(0x3020, "3");
//    store_value_by_ID(0x3030, "3");

//    store_value_by_ID(0x4001, "5DC");
//    store_value_by_ID(0x3004, "4B0");

//    // /100
//    store_value_by_ID(0x3400, "96");
//    store_value_by_ID(0x3401, "FA");
//    store_value_by_ID(0x3402, "15E");
//    store_value_by_ID(0x3403, "1C2");
//    // /1
//    store_value_by_ID(0x3501, "226");
//    store_value_by_ID(0x3502, "28A");

//    // / 100
//    store_value_by_ID(0x4400, "12C");
//    store_value_by_ID(0x4401, "258");

//    // /1
//    store_value_by_ID(0x4501, "25");
//    store_value_by_ID(0x4502, "50");

//    // /1
//    store_value_by_ID(0x4540, "75");
//    store_value_by_ID(0x9203, "1F4");

//    //presion
//    store_value_by_ID(0x5400, "123");
//    store_value_by_ID(0x5401, "123");

//    // /10
//    store_value_by_ID(0x9400, "12C");
//    store_value_by_ID(0x9401, "258");
//    store_value_by_ID(0x9402, "2BC");

//    // /10
//    store_value_by_ID(0x9403, "64");

//    // /1
//    store_value_by_ID(0x9501, "10");
//    store_value_by_ID(0x9502,
}

QList<double> DataProccess::getDataProcessing()
{
    return dataProccessing;
}
