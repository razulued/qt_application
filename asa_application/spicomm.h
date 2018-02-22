#ifndef SPICOMM_H
#define SPICOMM_H

#define ONE_MICROSENCONDDELAY 171
#define TEN_MICROSENCONDDELAY 1710

//This class is a siglenton instance, it just can exist one objectof this class
class SPICOMM
{
public:
    static SPICOMM* SPInstance();
    ~SPICOMM();

    void startSPICommunication(void);
    void endSPICommuniction(void);
    void configureSPICommunication(void);
    char* getSPIdata();
    void sendSPIdata();
    void msDelay(unsigned int delay);

    //uint16_t CalculateCRC16(uint16_t crc, uint8_t *c_ptr, int len);
    SPICOMM();

private:
    static SPICOMM* _SPInstance;
    bool SPIsuccess;
    char dataInfo[1024];
    //QTimer waitToSendDato;

};

#endif // SPICOMM_H
