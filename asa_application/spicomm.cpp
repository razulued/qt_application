#include "spicomm.h"
#include "build_settings.h"
#if (1 == RELEASE_FOR_RPI)
#include "bcm2835.h"
#endif

#include <QDebug>
#include "my_crc_api.h"
#include <stdint.h>
#include <stdlib.h>
#include "asa_conf_string.h"

#define SPI_STX 0x02
#define SPI_ETX 0x03


char input[] = "0:demo02|1:3|2:0|3:00000002|4:00000002|5:00000000|6:00000000|12:00000000|13:00000000|22:00000000|40:0000|41:0000|42:0000|43:0000|44:00|45:0000|46:0000|47:0000|48:0000|49:0000|50:0000|51:0000|52:00|53:00|54:00|55:0000|56:0000|57:0000|58:0000|59:0000|60:0000|61:0000|62:00|63:00|64:00|70:0100|71:0400|72:0800|73:0c00|74:00000258|80:04|81:00|82:00|83:00|90:0000|91:0000|92:ff|93:ffff|94:ffff|95:ffff|96:ffff|97:ffff|98:ffff|99:ffff|100:ff|101:ff|102:00|103:0000|104:0000|105:0000|106:0000|107:0000|108:0000|109:0000|110:00|111:00|112:00|113:0000|114:0000|115:0000|116:0000|117:0000|118:0000|119:0000|120:00|121:00|126:0400|127:0800|128:00001770|129:00008ca0|130:00008ca0|131:00008ca0|135:04|136:00|137:00|138:00|145:0000|146:ff|150:0200|151:0b00|155:04|156:00|160:0000|161:0000|162:0000|163:0000|";
//// Returns Calculated CRC value
//uint16_t CalculateCRC16(uint16_t crc, uint8_t *c_ptr, int len)
//{
//    while (len--)
//    {
//        crc = (crc << 8) ^ crctable[((crc >> 8) ^ *(c_ptr++))];
//    }

//    return crc;
//}


SPICOMM *SPICOMM::_SPInstance = 0;

SPICOMM::SPICOMM()
{

    SPIsuccess = false;
    this->startSPICommunication();
    this->configureSPICommunication();

}

SPICOMM* SPICOMM::SPInstance()
{
    if(!_SPInstance)
    {
       _SPInstance = new SPICOMM;
       qDebug()<< "Create object SPICOMM";
    }

    return (_SPInstance);
}

void SPICOMM::startSPICommunication()
{
#if (1 == RELEASE_FOR_RPI)

    bool statusComm = true;
    if (!bcm2835_init())
    {
      qDebug() << "bcm2835_init failed. Are you running as root??\n";
      statusComm = false;
    }
    if (!bcm2835_spi_begin())
    {
      qDebug() << "bcm2835_spi_begin failed. Are you running as root??\n";
      statusComm = false;
    }

    if(statusComm)
    {
        SPIsuccess = true;
        qDebug() << "Connection success";
    }
#endif
}

void SPICOMM::endSPICommuniction()
{
#if (1 == RELEASE_FOR_RPI)

    if(SPIsuccess)
    {
        bcm2835_spi_end();
        bcm2835_close();
    }
#endif
}

void SPICOMM::sendSPIdata()
{
#if (1 == RELEASE_FOR_RPI)

    int i = 0;
    uint8_t checksum_string[MAX_BUFFER_SIZE];
    uint8_t temp = 0;
    uint16_t CRCvalue = 0;
    uint8_t ch = 0;

    /*Do this only if there is data in the configuration*/
    QString output_str = get_config_string();
    if(output_str.size() > 1)
    {
        //Send start of TX
        temp = bcm2835_spi_transfer(SPI_STX);
        msDelay(10U);

        //Send ASA conf string
        qDebug() << output_str;
        for(i = 0; i < output_str.size(); i++)
        {
            ch = (uint8_t)output_str[i].unicode();
            temp = bcm2835_spi_transfer(ch);
            checksum_string[i] = ch;
            msDelay(10U);
        }

        //Send end of TX
        bcm2835_spi_transfer(SPI_ETX);
        msDelay(10U);

        // CRC
        CRCvalue = ::CalculateCRC16(0xFFFF, checksum_string, (output_str.size()));

        temp = bcm2835_spi_transfer((uint8_t)((CRCvalue >> 8) & 0x00FF));
        msDelay(10U);
        temp = bcm2835_spi_transfer((uint8_t)((CRCvalue) & 0x00FF));
        msDelay(10U);
    }
#endif
}

char *SPICOMM::getSPIdata()
{
#if (1 == RELEASE_FOR_RPI)

    uint8_t dataReadFromSPI[MAX_BUFFER_SIZE];
    char dataCharReadFromSPI[MAX_BUFFER_SIZE];
    uint16_t CRCvalue = 0;
    uint16_t CRCreceived = 0;
    uint8_t temp1;
    int bufferIndex;
    uint8_t CRCtemp1 = 0;
    uint8_t CRCtemp2 = 0;
    bool endOfLineFound = false;
    bool validData = false;
    bool CRC_flag = false;
    static int counter = 0;
    static int CRC_error_counter = 0;
    static int NO_EOF_counter = 0;

    char info1[] = "<|12:00ADBC|345:0FFF|1:00DDDA|777:00BCDE|52:00CDDD|321:00BBC1|311:000EEA|23:7878|11:7777|999:123|89:5435|434:6577|77:456|>";

    //Clear the buffer dataInfo
//    memset(dataInfo, 0, sizeof dataInfo);

    for (bufferIndex = 0; bufferIndex < MAX_BUFFER_SIZE; ++bufferIndex)
    {

            //temp1 = bcm2835_spi_transfer((uint8_t)readData);
        temp1 = bcm2835_spi_transfer(0x7F);

        msDelay(10U);
            //Start Valid info
        if (SPI_STX == temp1)
        {
            validData = true;
//            qDebug() << "[SOF]";
            break;  //Not continue with FOR statement
        }
    }

    if(true == validData)
    {
        for (bufferIndex = 0; bufferIndex < MAX_BUFFER_SIZE; ++bufferIndex)
        {
            temp1 = bcm2835_spi_transfer(0x7F);

        msDelay(10U);

            //spend time
//            for(int n= 0; n<2 ; n++)
//                qDebug() << "delay ";

            if(temp1 == SPI_ETX)
            {
                validData = false;
                CRCtemp1 = bcm2835_spi_transfer(0x7F);
                msDelay(10U);

                CRCtemp2 = bcm2835_spi_transfer(0x7F);
                msDelay(10U);

                endOfLineFound  = true;
                break;
                //continue;
            }
            else
            {
                dataReadFromSPI[bufferIndex] = temp1;
                dataCharReadFromSPI[bufferIndex] = (char)temp1;
            }
        }
    }

    if(true == endOfLineFound)
    {
        CRCreceived = (((uint16_t)CRCtemp1 << 8) + CRCreceived);
        CRCreceived = (uint16_t)CRCtemp2 + CRCreceived;
        CRCvalue = ::CalculateCRC16(0xFFFF, dataReadFromSPI, bufferIndex);

        if(CRCvalue != CRCreceived)
        {
            CRC_error_counter++;
            CRC_flag = true;
        }

        qDebug() << "Data: " << dataCharReadFromSPI;
//        qDebug() << "Valid DataNumber: " << (bufferIndex + 1);
        qDebug() << "CRC value CALC: " << CRCvalue ;
        qDebug() << "CRC value from MICRO: " << CRCreceived ;
        qDebug() << "Number of frames: " << counter++;

    }
    else
    {
        NO_EOF_counter++;
    }

    qDebug() << "NO_EOF_counter: " << NO_EOF_counter;
    qDebug() << "CRC error count: " << CRC_error_counter;


//        qDebug() << "Data: " << dataCharReadFromSPI;
//        qDebug() << "Valid DataNumber: " << (bufferIndex + 1);
//        qDebug() << "CRC value CALC: " << CRCvalue ;
//        qDebug() << "CRC value from MICRO: " << CRCreceived ;



//    //            qDebug() << "Calc: "<< CRCvalue;
//    //            qDebug() << "Received: "<< CRCreceived;
//        }
//        else
//        {
//    //               qDebug() << "No realizada";
//    //               qDebug() << "Calc: "<< CRCvalue;
//    //               qDebug() << "Received: "<< CRCreceived;
//         }

        if(false == CRC_flag)
        {
            strncpy ( dataInfo, dataCharReadFromSPI, bufferIndex);
        }
#endif
return (dataInfo);

}

void SPICOMM::msDelay(unsigned int delay)
{
   volatile unsigned int waitToSendDato = 0U;

           while (waitToSendDato < (ONE_MICROSENCONDDELAY*delay)) {
               waitToSendDato++;
           }
           waitToSendDato = 0;

}

void SPICOMM::configureSPICommunication()
{
#if (1 == RELEASE_FOR_RPI)
        bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                   // The default
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_4096); // The default
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      // The default
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      // the default
#endif
}

SPICOMM::~SPICOMM()
{

    this->endSPICommuniction();
    qDebug()<< "Deallocate object: " + SPIsuccess;
}
