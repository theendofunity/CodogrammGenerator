#ifndef HEADERMESSAGE_H
#define HEADERMESSAGE_H

#include "stdint.h"
#include <QDataStream>

struct HeaderMessage
{
   uint16_t size;
   uint16_t type;
};

inline QDataStream& operator << (QDataStream &stream, HeaderMessage &message)
{
  stream << message.size
         << message.type;
  return stream;
};

inline QDataStream& operator >> (QDataStream &stream, HeaderMessage &message)
{
    stream >> message.size
           >> message.type;
    return stream;
}
#endif // HEADERMESSAGE_H
