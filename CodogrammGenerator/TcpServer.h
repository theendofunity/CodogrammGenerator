#ifndef TCPCLIENT_H
#define TCPCLIENT_H


#include <QObject>

#include "pdp/public/ICpConsumers.h"
#include "pdp/AtcrbsCoordinatePoint.h"
#include "dsp/PeriodRepetitionAzimuth.h"
#include "AzimuthDistributer.h"
#include <DispatcherTools/IMessageHandler.h>


class QTcpServer;
class QTcpSocket;

class TcpServer : public QObject
                , public IParolConsumer
                , public IRbs_SConsumer
                , public AzimuthDistributer
                , public IMessageHandler<dsp::PeriodRepetitionAzimuth>
{
    Q_OBJECT

public:
    TcpServer(QObject *parent = nullptr);

    void addCp(const impl::CoordinatePoint &) override;
    void addAsInfo(asinfo_t &) override {}
    void addAlarmBearing(const Azimuth &) override {}
    void addCp(const esgrlo::CoordinatePoint &) override;
    void handle(const std::shared_ptr<dsp::PeriodRepetitionAzimuth> &message) override;
    void setAzimuth(const Azimuth &azimuth) override;
    void send(pdp::AtcrbsCoordinatePoint &cp);
    void send(dsp::PeriodRepetitionAzimuth &azimuth);

private:
    void onConnection();


private:
    QTcpServer *server = nullptr;
    QTcpSocket *clientSocket = nullptr;

    const uint16_t port = 10800;
};

#endif // TCPCLIENT_H
