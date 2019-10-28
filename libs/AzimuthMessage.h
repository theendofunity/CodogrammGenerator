#ifndef AZIMUTHMESSAGE_H
#define AZIMUTHMESSAGE_H

#include <stdint.h>
#include <QDataStream>

struct AzimuthMessage
{
    uint16_t azimuth;
};

inline QDataStream& operator << (QDataStream &stream, AzimuthMessage &message)
{
    stream << message.azimuth;
    return stream;
};

inline QDataStream& operator >>(QDataStream &stream, AzimuthMessage &message)
{
    stream >> message.azimuth;
    return  stream;
};

#endif // AZIMUTHMESSAGE_H
