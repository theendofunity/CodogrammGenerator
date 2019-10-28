#ifndef CPMESSAGE_H
#define CPMESSAGE_H

#include "stdint.h"
#include <QDataStream>

struct CpMessage
{
    double azimuth;
    double range;
    uint32_t bortNumber;
    uint32_t height;
};

inline QDataStream& operator << (QDataStream &stream, CpMessage &message)
{
    stream << message.azimuth
           << message.range
           << message.bortNumber
           << message.height;

    return stream;
}

inline QDataStream& operator >>(QDataStream &stream, CpMessage &message)
{
    stream >> message.azimuth
           >> message.range
           >> message.bortNumber
           >> message.height;

    return stream;
}

#endif // CPMESSAGE_H
