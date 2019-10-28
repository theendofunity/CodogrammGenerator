#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include <QObject>
#include <QVector>

#include <libs/CpMessage.h>
#include <libs/AzimuthMessage.h>

class DataGenerator : public QObject
{
    Q_OBJECT

public:
    DataGenerator(QObject *parent = nullptr);

    void generateAzimuthMessage();
    void generateCpMessage();

signals:
    void newCp(CpMessage &cp);
    void newAzimuth(AzimuthMessage & az);

private:
    QVector<uint16_t> azimuths;
    int index = 0;
    int turnover = 1;
};

#endif // DATAGENERATOR_H
