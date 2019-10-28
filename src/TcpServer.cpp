#include "TcpServer.h"


#include <QTcpServer>
#include <QTcpSocket>

#include <QDataStream>
#include <QByteArray>

#include "libs/HeaderMessage.h"
#include <QTime>

#include <QDebug>

TcpServer::TcpServer(QObject *parent)
    : QObject (parent)
{
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &TcpServer::onConnection);
    if (!server->listen(QHostAddress(QHostAddress::Any), port))
    {
        qDebug() << "TCP Server Error" << server->errorString();
        server->close();
        return;
    }
    else
    {
        qDebug() << "Server Ready" << server->serverAddress() << server->serverPort();
    }
}

void TcpServer::onConnection()
{
    qDebug() << "NEW CONNECTION";

    clientSocket = server->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::disconnected, clientSocket, &QTcpSocket::deleteLater);
}

void TcpServer::sendCp(CpMessage &cp)
{
    if (clientSocket == nullptr)
        return;
    if (clientSocket->state() != QAbstractSocket::ConnectedState)
        return;

    qDebug() << "SENDING MESSAGE (CP)";

    qDebug() << "BoardNum: "<< cp.bortNumber << "Az: " << cp.azimuth;

    HeaderMessage header;
    header.type = 391;
    header.size =  static_cast<uint16_t>(sizeof (cp) + sizeof (header));

    QDataStream stream(clientSocket);

    stream << header;
    stream << cp;
}

void TcpServer::sendAz(AzimuthMessage &azimuth)
{
    if(clientSocket == nullptr)
        return;

    if (clientSocket->state() != QAbstractSocket::ConnectedState)
        return;

    qDebug() << "SENDING MESSAGE (AZ)";

    qDebug() << azimuth.azimuth;

    HeaderMessage header;
    header.type = 350;
    header.size =  static_cast<uint16_t>(sizeof (azimuth) + sizeof (header));

    QDataStream stream(clientSocket);

    stream << header;
    stream << azimuth;
}
