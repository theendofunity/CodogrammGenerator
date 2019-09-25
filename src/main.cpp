#include <QCoreApplication>

#include <QObject>

#include <DataGenerator.h>
#include <TcpServer.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TcpServer *server = new TcpServer;
    DataGenerator *data = new DataGenerator;

    QObject::connect(data, &DataGenerator::newAzimuth, server, &TcpServer::sendAz);
    QObject::connect(data, &DataGenerator::newCp, server, &TcpServer::sendCp);

    return a.exec();
}
