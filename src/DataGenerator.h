#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include <QObject>
#include <QVector>

#include <libs/PeriodRepetitionAzimuth.h>
#include <libs/AtcrbsCoordinatePoint.h>

class DataGenerator : public QObject
{
    Q_OBJECT

public:
    DataGenerator(QObject *parent = nullptr);

    void generateAzimuthMessage();
    void generateCpMessage();

signals:
    void newCp(pdp::AtcrbsCoordinatePoint &cp);
    void newAzimuth(dsp::PeriodRepetitionAzimuth &azimuth);

private:
    QVector<uint16_t> azimuths;
    int index = 0;
};

#endif // DATAGENERATOR_H
