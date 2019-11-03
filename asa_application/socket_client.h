#ifndef SOCKET_CLIENT_H
#define SOCKET_CLIENT_H
#include <QObject>
#include <QTcpSocket>
#include <QTimer>
class socket_client : public QObject
{
    Q_OBJECT
public:
    socket_client();

private slots:
    void timer_expired();
    void ready_complete();
    void socket_disconnected();
    void socket_error(QAbstractSocket::SocketError err);

signals:
    void new_data_comming();

private:
    QTcpSocket* m_socket = NULL;
    QTimer *timer_connect = NULL;
};

#endif // SOCKET_CLIENT_H
