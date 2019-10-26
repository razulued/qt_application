#include "socket_client.h"
#include <QDebug>

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
    qDebug() << "READ: " << m_socket->readAll();

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
