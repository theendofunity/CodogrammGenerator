
#include "libs/GenericPrototypes/GenericPrototypes.h"

#include <stdint.h>


namespace PVD
{
    struct Header : public Codogramm
    {
        enum { TotalWords = 2 };

        Header()
        {
            appendToOrder( { &type } );
        }

        BitField<uint32_t, 10> type;
    };
}
