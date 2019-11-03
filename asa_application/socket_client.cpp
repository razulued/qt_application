#include "socket_client.h"
#include <QDebug>
#include "protocol/asa_protocol.h" // TODO remove this

#define PTAR_PORT (1234)

socket_client::socket_client()
{
    // Create Scoket
    m_socket = new QTcpSocket(this);

    // Setup timer for reconnection
    timer_connect = new QTimer(this);
    connect(timer_connect, SIGNAL(timeout()), this, SLOT(timer_expired()));

    m_socket->connectToHost("127.0.0.1",1234);
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(ready_complete()));
    connect(m_socket, SIGNAL(disconnected()), this, SLOT(socket_disconnected()));
    connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this,
            SLOT(socket_error(QAbstractSocket::SocketError)));
}

void socket_client::timer_expired()
{
    m_socket->connectToHost("127.0.0.1",PTAR_PORT);
    timer_connect->stop();
}

void socket_client::ready_complete()
{
    bool ok;
    QString stringo = QString::fromUtf8(m_socket->readAll());
    qDebug() << "READ: " << stringo;

    // TODO REMOVE THIS
    QStringList ID_Parameters = stringo.split("|");
    QStringList realParameters;
    for(int i = 0; i < ID_Parameters.length() ; i++)
    {
        realParameters = ID_Parameters[i].split(":");
        if(realParameters.length() > 1)
        {
            store_value_by_ID(realParameters[0].toInt(&ok,16) , realParameters[1]);
        }
    }

    this->new_data_comming();
}

void socket_client::socket_disconnected()
{
    qDebug() << "Socket Disconnected retry connection in 5 seconds";
}

void socket_client::socket_error(QAbstractSocket::SocketError err)
{
    if(err == QAbstractSocket::RemoteHostClosedError)
    {
        qDebug() << "Remote close error";
        timer_connect->start(5000);
    }
    else if(err == QAbstractSocket::ConnectionRefusedError)
    {
        qDebug() << "Connection Refused";
        timer_connect->start(5000);
    }
    else
    {
        qDebug() << "Other error";
    }

    qDebug() << "Error: " << err;
}
