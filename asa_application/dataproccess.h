#ifndef DATAPROCCESS_H
#define DATAPROCCESS_H

#include <QtCore>
#include "spicomm.h"
#include<QTimer>

class DataProccess : public QThread
{
    Q_OBJECT
    public:
    explicit DataProccess(QObject *parent = nullptr);
    QList<double> getDataProcessing(void);
     ~DataProccess();
    void run();

signals:
    void spi_read_completed();

private:
    void dataSPI();
    void dataRandom();
    QTimer dataTimer;
    QList<double> dataProccessing;
    SPICOMM* spiObj;

    //Utilities function;
    double raw2phys(int rawmin, int rawmax, int physmin, int phymax, int sensor);
    double raw2modbus(int rawmin, int rawmax, int sensor, int factor);

    double calcPSIfromADC(int rawmin, int rawmax, int physmin, int phymax, int sensor);
    double calcCAUfromADC(int valueADC);

    int hexString2Int(QString inputString);
    int intString2Int(QString inputString);

public slots:
//    void dataTimerSlot();
};

#endif // DATAPROCCESS_H
