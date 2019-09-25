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

    cpTimer->start(5000);
    azTimer->start(1000);
}

void DataGenerator::generateAzimuthMessage()
{
    if (index == azimuths.size())
        index = 0;

    dsp::PeriodRepetitionAzimuth message;
    message.azimuth.setValue(azimuths[index]);

    index++;
    emit newAzimuth(message);
}

void DataGenerator::generateCpMessage()
{
    if (index == azimuths.size())
        index = 0;

    pdp::AtcrbsCoordinatePoint message;
    message.azimuth.setValue((azimuths[index] * 0.1));
    message.range = azimuths[index + 1] * 100;

    index++;

    emit newCp(message);
}
