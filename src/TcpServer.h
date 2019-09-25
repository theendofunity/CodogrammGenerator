#ifndef TCPCLIENT_H
#define TCPCLIENT_H


#include <QObject>

#include <libs/AtcrbsCoordinatePoint.h>
#include <libs/PeriodRepetitionAzimuth.h>


class QTcpServer;
class QTcpSocket;

class TcpServer : public QObject

{
    Q_OBJECT

public:
    TcpServer(QObject *parent = nullptr);

    void sendCp(pdp::AtcrbsCoordinatePoint &cp);
    void sendAz(dsp::PeriodRepetitionAzimuth &azimuth);

private:
    void onConnection();


private:
    QTcpServer *server = nullptr;
    QTcpSocket *clientSocket = nullptr;

    const uint16_t port = 10800;
};

#endif // TCPCLIENT_H
