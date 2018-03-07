#include "dataproccess.h"
#include <QDebug>
#include "parameters.h"


#define PSI_RAWMIN   0x0194         //ADC 415  == 0
#define PSI_RAWMAX   0x08E7         //2294     == 1.82
#define PSI_PHYSMIN  0              //4mA
#define PSI_PHYSMAX  147             //20mA

#define CAUDAL_RAWMIN   0x0188      //ADC 456
#define CAUDAL_RAWMAX   0x08E7      //ADC 2279
#define CAUDAL_PHYSMIN  0           //4mA
#define CAUDAL_PHYSMAX  305        //20mA

#define LEVEL_RAWMIN   0x01C8       //ADC 456
#define LEVEL_RAWMAX   0x08E7       //ADC 2279
#define LEVEL_PHYSMIN  0            //4mA
#define LEVEL_PHYSMAX  8            //20mA

#define VOLTS_RAWMIN   0x0000
#define VOLTS_RAWMAX   0x0A28
#define VOLTS_PHYSMIN  0
#define VOLTS_PHYSMAX  260

#define FP_RAWMIN   0x0000
#define FP_RAWMAX   0x0A28
#define FP_PHYSMIN  0
#define FP_PHYSMAX  260


#define CURRENT_RAWMIN   0x0000
#define CURRENT_RAWMAX   0x0A28
#define CURRENT_PHYSMIN  0
#define CURRENT_PHYSMAX  260


#define DO2_RAWMIN   0x0000
#define DO2_RAWMAX   0x0FFF
#define DO2_PHYSMIN  0
#define DO2_PHYSMAX  100

#define DPH_RAWMIN   0
#define DPH_RAWMAX   140
#define DPH_PHYSMIN  0
#define DPH_PHYSMAX  14

#define DTU_RAWMIN   0x0000
#define DTU_RAWMAX   0x0fff
#define DTU_PHYSMIN  0
#define DTU_PHYSMAX  100

#define DPR_RAWMIN   521
#define DPR_RAWMAX   898
#define DPR_PHYSMIN  90
#define DPR_PHYSMAX  7

#define DCA_RAWMIN   505
#define DCA_RAWMAX   1559
#define DCA_PHYSMIN  73.9
#define DCA_PHYSMAX  12.3

#define DSS_RAWMIN   0x0000
#define DSS_RAWMAX   0x0fff
#define DSS_PHYSMIN  0
#define DSS_PHYSMAX  100


DataProccess::DataProccess(QObject *parent) : QObject(parent)
{
    dataProccessing = QList<double>() << 0.0 << 0.0 << 0.0  << 0.0 << 0.0  << 0.0 << 0.0 << 0.0 << 0.0  << 0.0 << 0.0 << 0.0  << 0.0 << 0.0  << 0.0 << 0.0  << 0.0 << 0.0 ;
    //dataProccessing.append(0.0);
    spiObj = spiObj->SPInstance();
    dataTimer.setInterval(200);
    connect(&dataTimer, SIGNAL(timeout()),this,SLOT(dataTimerSlot()));
    dataTimer.start();
}

DataProccess::~DataProccess()
{
    delete spiObj;
}

double DataProccess::raw2phys(int rawmin, int rawmax, int physmin, int phymax, int sensor)
{
    double scaled;

//    if((sensor < (rawmin)) || (sensor > (rawmax))) {
//        scaled = 0;
//    }
//    else {
        scaled = (double)(physmin + ((sensor - rawmin) * (phymax - physmin))) / (rawmax - rawmin);
//t    }

    return scaled;
}

double DataProccess::raw2modbus(int rawmin, int rawmax, int sensor, int factor)
{
    double scaled;

//    if((sensor < (rawmin)) || (sensor > (rawmax))) {
//        scaled = 0;
//    }
//    else {
        scaled = (double)(sensor) / (factor);
//    }

    return scaled;
}

double DataProccess::calcPSIfromADC(int rawmin, int rawmax, int physmin, int phymax, int sensor)
//{
//    double PSI_PHY_lookup_values[] = {7,8,11,14,16,21,25,28,34,39,45,50,56,62,69,71,74,81,85,88,97};
//    double PSI_ADC_lookup_values[] = {514,535,566,600,636,692,746,787,869,920,1003,1060,1139,1222,1320,1336,1374,1462,1508,1548,1672};

//    int i = 0;
//    double output = 0;

////    if(valueADC < PSI_ADC_lookup_values[0])
////    {
////        output = PSI_PHY_lookup_values[0];
////    }
////    else if(valueADC > PSI_ADC_lookup_values[20])
////    {
////        output = PSI_PHY_lookup_values[20];
////    }
////    else
////    {
//        for(i = 0; i <= 20; i++) {
//            if( (valueADC >= PSI_ADC_lookup_values[i]) && (valueADC <= PSI_ADC_lookup_values[i+1]) ) {
//                output = PSI_PHY_lookup_values[i] + ( ((PSI_PHY_lookup_values[i+1] - PSI_PHY_lookup_values[i]) * (valueADC -  PSI_ADC_lookup_values[i])) / (PSI_ADC_lookup_values[i+1] - PSI_ADC_lookup_values[i]) );
//                break;
//            }
//        }
////    }
//    return output;

//}
{
    double scaled;

    if(sensor < rawmin) {
        scaled = 0;
    }
    else if (sensor > rawmax){
        sensor = rawmax;
    }

    else {
        scaled = (double)(physmin + ((sensor - rawmin) * (phymax - physmin))) / (rawmax - rawmin);
    }

    return scaled;
}

double DataProccess::calcCAUfromADC(int valueADC)
{
    double CAU_PHY_lookup_values[] = {0,13.5,18.7,23.1,31.9,35.1,37.4,44.7,51,55.9,59.7,64.4,67,69.4,70.4,71.5,72.8,73.2,73.4,73.6,73.6};
    double CAU_ADC_lookup_values[] = {447,528,557,586,641,657,669,716,751,785,806,834,850,864,871,876,883,884,886,891,891};

    int i = 0;
    double output = 0;

//    if(valueADC < CAU_ADC_lookup_values[0])
//    {
//        output = CAU_PHY_lookup_values[0];
//    }
//    else if(valueADC > CAU_ADC_lookup_values[20])
//    {
//        output = CAU_PHY_lookup_values[20];
//    }
//    else
//    {
        for(i = 0; i <= 20; i++) {
            if( (valueADC >= CAU_ADC_lookup_values[i]) && (valueADC <= CAU_ADC_lookup_values[i+1]) ) {
                output = CAU_PHY_lookup_values[i] + ( ((CAU_PHY_lookup_values[i+1] - CAU_PHY_lookup_values[i]) * (valueADC -  CAU_ADC_lookup_values[i])) / (CAU_ADC_lookup_values[i+1] - CAU_ADC_lookup_values[i]) );
                break;
            }
        }
//    }
    return output;

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
    temp = inputString.toInt(); //Casting from String to Int (Hexadecimal representation)
    return temp;
}

void DataProccess::dataTimerSlot()
{
    this->dataSPI();
    ////qDebug() << sizeof(int);
    ////qDebug() << "Hola Eslava";
    ////qDebug() << "We are printing someting";
}

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

        double currentAVG = 0;
        double voltajeAVG = 0;
        double FPAVG = 0;

        double realValue = 0;


        send_ASA_Conf = true;
        qDebug() << "Receive data";

        QStringList ID_Parameters = bufferString.split("|");
        QStringList realParameters ;


        for(int i = 0; i < ID_Parameters.length() ; i++)
        {
            realParameters = ID_Parameters[i].split(":");


            //for (int j = 0; j < realParameters.length(); ++j) {
               // temp = realParameters[j];
                ////qDebug() << "Los valore [" << i << "][" << j << "] = " <<  realParameters[j]  << " len = " << realParameters[j].size();

            if(realParameters.length() > 1)
            {
                switch (intString2Int(realParameters[0])) {

                case 40:
                    realValue = raw2modbus(DSS_RAWMIN, DSS_RAWMAX, hexString2Int(realParameters[1]), 1);
    //                realValue = static_cast<double>(hexString2Int(realParameters[1]));
                    dataProccessing[1] = realValue;
    //                qDebug() << "Value in CASE 40 : " <<  realParameters[1];
                    break;

                case 41:
                    realValue  = raw2modbus(DPH_RAWMIN, DPH_RAWMIN, hexString2Int(realParameters[1]), 100);
    //                realValue = static_cast<double>(hexString2Int(realParameters[1]));
                    dataProccessing[5] = realValue;
                    //qDebug() << "Value in CASE 43 : " <<  intString2Int(realParameters[1]);
                    break;

                case 42:
                    realValue  = raw2modbus(DSS_RAWMIN, DSS_RAWMAX, hexString2Int(realParameters[1]), 100);
    //                realValue = static_cast<double>(hexString2Int(realParameters[1]));
                    dataProccessing[6] = realValue;
                    //qDebug() << "Value in CASE 43 : " <<  intString2Int(realParameters[1]);
                    break;


                case 43:
                    realValue  = calcCAUfromADC(hexString2Int(realParameters[1]));
    //                realValue = static_cast<double>(hexString2Int(realParameters[1]));
                    dataProccessing[0] = realValue;
                    //qDebug() << "Value in CASE 43 : " <<  intString2Int(realParameters[1]);
                    break;

                case 45:
                    realValue  = raw2modbus(VOLTS_RAWMIN, VOLTS_RAWMAX, hexString2Int(realParameters[1]), 10);
    //                realValue = static_cast<double>(hexString2Int(realParameters[1]));
                    dataProccessing[12] = realValue;
                    //qDebug() << "Value in CASE 43 : " <<  intString2Int(realParameters[1]);
                    voltajeAVG = voltajeAVG + (realValue/3);
                    break;

                case 46:
                case 47:
                    realValue  = raw2modbus(VOLTS_RAWMIN, VOLTS_RAWMAX, hexString2Int(realParameters[1]), 10);
                    voltajeAVG = voltajeAVG + (realValue/3);
                    break;

                case 48:
                    realValue  = raw2modbus(CURRENT_RAWMIN, CURRENT_RAWMAX, hexString2Int(realParameters[1]), 1000);
    //                realValue = static_cast<double>(hexString2Int(realParameters[1]));
                    dataProccessing[13] = realValue;
                    //qDebug() << "Value in CASE 43 : " <<  intString2Int(realParameters[1]);
                    currentAVG = currentAVG + (realValue/3);
                    break;

                case 49:
                case 50:
                    realValue  = raw2modbus(CURRENT_RAWMIN, CURRENT_RAWMAX, hexString2Int(realParameters[1]), 1000);
                    currentAVG = currentAVG + (realValue/3);
                    break;

                case 52:
                    realValue  = raw2modbus(FP_RAWMIN, FP_RAWMAX, hexString2Int(realParameters[1]), 100);
    //                realValue = static_cast<double>(hexString2Int(realParameters[1]));
                    dataProccessing[14] = realValue;
                    dataProccessing[17] = realValue;
                    //qDebug() << "Value in CASE 43 : " <<  intString2Int(realParameters[1]);
                    FPAVG = FPAVG + (realValue/2);
                    break;
                case 53:
                    realValue  = hexString2Int(realParameters[1])/ 100;
                    break;
                case 63:
                    realValue  = raw2modbus(FP_RAWMIN, FP_RAWMAX, hexString2Int(realParameters[1]), 10);
                    FPAVG = FPAVG + (realValue/2);

                    break;

                case 65:
                    realValue  = raw2modbus(DTU_RAWMIN, DTU_RAWMAX, hexString2Int(realParameters[1]), 10);
    //                realValue = static_cast<double>(hexString2Int(realParameters[1]));
                    dataProccessing[7] = realValue;
                    //qDebug() << "Value in CASE 43 : " <<  intString2Int(realParameters[1]);
                    break;


                case 90:
                    realValue  = raw2modbus(DO2_RAWMIN, DO2_RAWMAX, hexString2Int(realParameters[1]), 100);
    //                realValue = static_cast<double>(hexString2Int(realParameters[1]));
                    dataProccessing[8] = realValue;
                    //qDebug() << "Value in CASE 43 : " <<  intString2Int(realParameters[1]);
                    break;
                case 93:
                    realValue  = raw2modbus(VOLTS_RAWMIN, VOLTS_RAWMAX, hexString2Int(realParameters[1]), 10);
                    break;
                case 96:
                    realValue  = raw2modbus(CURRENT_RAWMIN, CURRENT_RAWMAX, hexString2Int(realParameters[1]), 1000);
                    break;
                case 101:
                    realValue  = hexString2Int(realParameters[1])/ 100;
                    break;
                case 122:
                    realValue  = calcPSIfromADC(PSI_RAWMIN, PSI_RAWMAX, PSI_PHYSMIN, PSI_PHYSMAX, hexString2Int(realParameters[1]));
    //                realValue = static_cast<double>(hexString2Int(realParameters[1]));
                    dataProccessing[2] = realValue;
                    //qDebug() << "Value in CASE 43 : " <<  intString2Int(realParameters[1]);
                    break;
                    ////qDebug() << "Value in CASE 1 : " <<  intString2Int(realParameters[1]);
                    break;

                case 145:

                    //Nivel Dinamico
                    realValue  = raw2modbus(DO2_RAWMIN, DO2_RAWMAX, hexString2Int(realParameters[1]), 1);
    //                realValue = static_cast<double>(hexString2Int(realParameters[1]));
                    dataProccessing[3] = realValue;
                    //qDebug() << "Value in CASE 43 : " <<  intString2Int(realParameters[1]);
                    break;

                case 160:
                    realValue  = raw2modbus(DPH_RAWMIN, DPH_RAWMIN, hexString2Int(realParameters[1]), 100);
    //                realValue = static_cast<double>(hexString2Int(realParameters[1]));
                    dataProccessing[9] = realValue;
                    //qDebug() << "Value in CASE 43 : " <<  intString2Int(realParameters[1]);
                    break;


                case 161:
                    realValue  = raw2modbus(DSS_RAWMIN, DSS_RAWMIN, hexString2Int(realParameters[1]), 100);
    //                realValue = static_cast<double>(hexString2Int(realParameters[1]));
                    dataProccessing[10] = realValue;
                    //qDebug() << "Value in CASE 43 : " <<  intString2Int(realParameters[1]);
                    break;


                case 162:
                    realValue  = calcPSIfromADC(CAUDAL_RAWMIN, CAUDAL_RAWMAX, CAUDAL_PHYSMIN, CAUDAL_PHYSMAX, hexString2Int(realParameters[1]));
    //                realValue = static_cast<double>(hexString2Int(realParameters[1]));
                    dataProccessing[4] = realValue;
                    //qDebug() << "Value in CASE 162 : " <<  hexString2Int(realParameters[1]);
                    break;

                case 163:
                    realValue  = raw2modbus(DTU_RAWMIN, DTU_RAWMAX, hexString2Int(realParameters[1]), 10);
    //                realValue = static_cast<double>(hexString2Int(realParameters[1]));
                    dataProccessing[11] = realValue;
                    //qDebug() << "Value in CASE 43 : " <<  intString2Int(realParameters[1]);
                    break;

                case 165:
                    realValue  = calcPSIfromADC(0x194, CAUDAL_RAWMAX, CAUDAL_PHYSMIN, 147, hexString2Int(realParameters[1]));
    //                realValue = static_cast<double>(hexString2Int(realParameters[1]));
                    dataProccessing[4] = realValue;
                    //qDebug() << "Value in CASE 43 : " <<  intString2Int(realParameters[1]);
                    break;

                default:
                    realValue = intString2Int(realParameters[0]);
                    break;
                }
                setParamValue(intString2Int(realParameters[0]), realValue);
            }

        }
        dataProccessing[15] = voltajeAVG;
        dataProccessing[16] = currentAVG;
    //    dataProccessing[17] = FPAVG;

    }
}

QList<double> DataProccess::getDataProcessing()
{
    return dataProccessing;
}
