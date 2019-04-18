#include "dataproccess.h"
#include <QDebug>
#include "parameters.h"
#include "asa_protocol.h"
#include "mainwindow.h"
#include "build_settings.h"
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

    store_value_by_ID(0x3800, "3");
    store_value_by_ID(0x3810, "3");
    store_value_by_ID(0x3820, "3");
    store_value_by_ID(0x3830, "3");

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
//            QThread::msleep(5000);
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


#define USE_SIM (1)
//void DataProccess::dataTimerSlot()
//{
//    this->dataSPI();
//}

void DataProccess::dataSPI()
{
    static bool send_ASA_Conf = false;

    if(true == send_ASA_Conf)
    {
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
#if SHOW_DEBUG
        qDebug() << "Receive data";
#endif
        QStringList ID_Parameters = bufferString.split("|");
        QStringList realParameters ;

#if SHOW_DEBUG
        qDebug() << "Number of parameters: " << ID_Parameters.length();
#endif
        for(int i = 0; i < ID_Parameters.length() ; i++)
        {
            realParameters = ID_Parameters[i].split(":");

//#if USE_SIM
            if(MainWindow::demo_mode_enabled == true)
            {
                if( 0x3301  == intString2Int(realParameters[0]) ||
                0x3305  == intString2Int(realParameters[0]) ||
                0x3201  == intString2Int(realParameters[0]) ||
                0x3203  == intString2Int(realParameters[0]) ||
                0x3004  == intString2Int(realParameters[0]) ||
                0x3005  == intString2Int(realParameters[0]) ||
                0x3006  == intString2Int(realParameters[0]) ||
                0x4307  == intString2Int(realParameters[0]) ||
                0x4205  == intString2Int(realParameters[0]) ||
                0x4004  == intString2Int(realParameters[0]) ||
                0x4005  == intString2Int(realParameters[0]) ||
                0x4006  == intString2Int(realParameters[0]) ||
                0x6303  == intString2Int(realParameters[0]) ||
                0x6305  == intString2Int(realParameters[0]) )
                {
                    continue;
                }
            }
//#endif
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

        if(MainWindow::demo_mode_enabled == true)
        {
    //    #if USE_SIM
            uint val;
            static uint count = 0;
            static uint count_2 = 0;
        //    if(count_2 > 10)
        //    {
        //        store_value_by_ID((0x3000), "1");
        //        count_2++;
        //        if(count_2 > 20)
        //        {
        //            count_2 = 0;
        //        }
        //    }
        //    else
        //    {
        //        store_value_by_ID((0x3000), "0");
        //        count_2++;
        //    }

        //    static uint count_3 = 0;
        //    if(count_3 > 20)
        //    {
        //        store_value_by_ID((0x4000), "1");
        //        count_3++;
        //        if(count_3 > 30)
        //        {
        //            count_3 = 0;
        //        }
        //    }
        //    else
        //    {
        //        store_value_by_ID((0x4000), "0");
        //        count_3++;
        //    }

            if(count++ > 4)
            {
                count = 0;
                // PH 6-8
                val = qrand() % 200 + 600;
                store_value_by_ID((0x3301), QString("%1").arg(val, 0, 16));

                // SST 250-350
                val = qrand() % 10000 + 25000;
                store_value_by_ID((0x3305), QString("%1").arg(val, 0, 16));

                // ND  1-3
                val = qrand() % 200 + 100;
                store_value_by_ID((0x3201), QString("%1").arg(val, 0, 16));

                // Q  5-10
                val = qrand() % 131 + 438;
                store_value_by_ID((0x3203), QString("%1").arg(val, 0, 16));

                // A L1
                val = qrand() % 2000 + 3000;
                store_value_by_ID((0x3004), QString("%1").arg(val, 0, 16));
                val = qrand() % 2000 + 3000;
                store_value_by_ID((0x3005), QString("%1").arg(val, 0, 16));
                val = qrand() % 2000 + 3000;
                store_value_by_ID((0x3006), QString("%1").arg(val, 0, 16));

                // REACTOR
                // OD  1.5-2.5
                val = qrand() % 100 + 150;
                store_value_by_ID((0x4307), QString("%1").arg(val, 0, 16));

                // P  5.5-6
                val = qrand() % 19 + 660;
                store_value_by_ID((0x4205), QString("%1").arg(val, 0, 16));

                // A L1
                val = qrand() % 2000 + 6500;
                store_value_by_ID((0x4004), QString("%1").arg(val, 0, 16));
                val = qrand() % 2000 + 6500;
                store_value_by_ID((0x4005), QString("%1").arg(val, 0, 16));
                val = qrand() % 2000 + 6500;
                store_value_by_ID((0x4006), QString("%1").arg(val, 0, 16));

                // Cloracion
                // turbidez
                val = qrand() % 130 + 30;
                store_value_by_ID((0x6303), QString("%1").arg(val, 0, 16));

                // turbidez
                val = qrand() % 600 + 500;
                store_value_by_ID((0x6305), QString("%1").arg(val, 0, 16));

            }
    //    #endif

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
