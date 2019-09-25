#include "TcpServer.h"


#include <QTcpServer>
#include <QTcpSocket>

#include <QByteArray>
#include <QDataStream>
#include "libs/GenericPrototypes/BitStream.h"


#include "libs/POIProtocol.h"
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

void TcpServer::sendCp(pdp::AtcrbsCoordinatePoint &cp)
{
    if (clientSocket == nullptr)
        return;
    if (clientSocket->state() != QAbstractSocket::ConnectedState)
        return;

    qDebug() << "SENDING MESSAGE (CP)";

    qDebug() << "BoardNum: "<< cp.bortNumber << "Az: " << cp.azimuth;

    PVD::Header header;
    header.type = 91;

    std::vector<uint8_t> memory;
    BitStream stream(memory);
    stream << header;
    stream << cp;
    clientSocket->write(reinterpret_cast<const char*>(memory.data()), static_cast<int>(memory.size()));
}

void TcpServer::sendAz(dsp::PeriodRepetitionAzimuth &azimuth)
{
    if (clientSocket == nullptr)
        return;

    if (clientSocket->state() != QAbstractSocket::ConnectedState)
        return;

    qDebug() << "SENDING MESSAGE (AZ)";

    PVD::Header header;
    header.type = 25;

    qDebug() << azimuth.azimuth;

    std::vector<uint8_t> memory;

    BitStream stream(memory);

    stream << header;
    stream << azimuth;

    clientSocket->write(reinterpret_cast<const char*>(memory.data()), static_cast<int>(memory.size()));
}
