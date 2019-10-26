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
    QTimer dataTimer;
    QList<double> dataProccessing;
    SPICOMM* spiObj;

    int hexString2Int(QString inputString);
    int intString2Int(QString inputString);

public slots:
//    void dataTimerSlot();
};

#endif // DATAPROCCESS_H
