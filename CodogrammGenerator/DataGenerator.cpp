#include "DataGenerator.h"

#include <QTimer>

DataGenerator::DataGenerator(QObject *parent)
    : QObject(parent)
{
    for (uint16_t i = 0; i <= 20; i++)
    {
        azimuths.push_back(i);
    }

    QTimer *cpTimer = new QTimer(this);
    connect(cpTimer, &QTimer::timeout, this, &DataGenerator::generateCpMessage);

    QTimer *azTimer = new QTimer(this);
    connect(azTimer, &QTimer::timeout, this, &DataGenerator::generateAzimuthMessage);

    cpTimer->start(10000);
    azTimer->start(5000);
}

void DataGenerator::generateAzimuthMessage()
{
    if (index == azimuths.size())
        index = 0;

    dsp::PeriodRepetitionAzimuth message;
    message.azimuth.setValue(azimuths[index]);

    emit newAzimuth(message);
}

void DataGenerator::generateCpMessage()
{
    if (index == azimuths.size())
        index = 0;

    pdp::AtcrbsCoordinatePoint message;
    message.azimuth.setValue(azimuths[index]);
    message.range = azimuths[index + 1] * 10;

    emit newCp(message);
}
