#include "DataGenerator.h"

#include <QTimer>
#include <QDebug>

DataGenerator::DataGenerator(QObject *parent)
    : QObject(parent)
{
    for (auto i = 0; i <= 36; i++)
    {

        azimuths.push_back(i * 10);
    }

    QTimer *cpTimer = new QTimer(this);
    connect(cpTimer, &QTimer::timeout, this, &DataGenerator::generateCpMessage);

    QTimer *azTimer = new QTimer(this);
    connect(azTimer, &QTimer::timeout, this, &DataGenerator::generateAzimuthMessage);

    cpTimer->start(100);
    azTimer->start(50);
}

void DataGenerator::generateAzimuthMessage()
{
    if (index == azimuths.size())
        index = 0;

    AzimuthMessage message;
    message.azimuth = azimuths[index]/* * 360.0 / 65536*/;

    index++;
    emit newAzimuth(message);
}

void DataGenerator::generateCpMessage()
{
    if (index == azimuths.size())
    {
        index = 0;
        turnover++;
    }

    CpMessage message;
    message.azimuth = azimuths[index] * 0.019;
    message.range = azimuths[index] * 1000;

    emit newCp(message);
}
