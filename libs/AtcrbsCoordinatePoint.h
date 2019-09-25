#ifndef GUARD_6a75db93_e23c_4c0c_8214_b76757d6bac2
#define GUARD_6a75db93_e23c_4c0c_8214_b76757d6bac2


#include <libs/GenericPrototypes/GenericPrototypes.h>

#include "Answer.h"



namespace pdp
{


struct AtcrbsCoordinatePoint : public Codogramm
{
    enum { MessageTypeCode = 113 };
    
    enum SystemMode
    {
        SystemMode_Undefined = 0,
        SystemMode_RBS = 1,
        SystemMode_NRZ = 2,
        SystemMode_ParolAlarm = 3,
        SystemMode_ModeS = 4,
    };
    
    struct RbsCodes : public Codogramm
    {
        RbsCodes()
        {
            appendToOrder( { &code } );
            appendToOrder( { &confidenceCode } );
        }
        
        RbsCodes(const RbsCodes& orig)
            : RbsCodes()
        {
            *this = orig;
        }
        
        Field<int32_t> code;
        Field<int32_t> confidenceCode;
    };
    
    struct Parol : public Codogramm
    {
        Parol()
        {
            appendToOrder( { &heigth } );
            appendToOrder( { &bortNumber } );
            appendToOrder( { &fuelCapacity } );
            appendToOrder( { &disaster } );
            appendToOrder( { &ur } );
            appendToOrder( { &di_4 } );
            appendToOrder( { &di_6 } );
            appendToOrder( { &isFriendCommonRecognition } );
            appendToOrder( { &isFriendGuaranteedRecognition } );
            appendToOrder( { &isFriendIndividualRecognition } );
        }
        
        Parol(const Parol& orig)
            : Parol()
        {
            *this = orig;
        }
        
        Field<uint32_t> heigth;
        Field<uint32_t> bortNumber;
        Field<uint8_t> fuelCapacity;
        Field<uint8_t> disaster;
        Field<uint8_t> ur;
        Field<uint8_t> di_4;
        Field<uint8_t> di_6;
        BitField<uint8_t, 1> isFriendCommonRecognition;
        BitField<uint8_t, 1> isFriendGuaranteedRecognition;
        BitField<uint8_t, 1> isFriendIndividualRecognition;
    };
    
    struct ModeS : public Codogramm
    {
        ModeS()
        {
            appendToOrder( { &AA } );
            appendToOrder( { &identity } );
            appendToOrder( { &altitude } );
            appendToOrder( { &PrS } );
        }
        
        ModeS(const ModeS& orig)
            : ModeS()
        {
            *this = orig;
        }
        
        Field<uint32_t> AA;
        Field<uint32_t> identity;
        Field<uint32_t> altitude;
        BitField<uint8_t, 3> PrS;
    };
    
    AtcrbsCoordinatePoint()
    {
        appendToOrder( { &rejectedByVaru } );
        appendToOrder( { &range } );
        appendToOrder( { &azimuth } );
        appendToOrder( { &amplitude } );
        appendToOrder( { &xImpulse } );
        appendToOrder( { &mode } );
        appendToOrder( { &unitCode } );
        appendToOrder( { &bortNumber } );
        appendToOrder( { &altitude } );
        appendToOrder( { &spi } );
        appendToOrder( { &militaryAlarm } );
        appendToOrder( { &mode_1 } );
        appendToOrder( { &mode_2 } );
        appendToOrder( { &mode_3A } );
        appendToOrder( { &mode_C } );
        appendToOrder( { &parol } );
        appendToOrder( { &modes } );
        appendToOrder( { &isRollCall } );
        appendToOrder( { &M } );
        appendToOrder( { &packsNum } );
        appendToOrder( { &pack } );
    }
    
    AtcrbsCoordinatePoint(const AtcrbsCoordinatePoint& orig)
        : AtcrbsCoordinatePoint()
    {
        *this = orig;
    }
    
    BitField<uint8_t, 1> rejectedByVaru;
    Field<double> range;
    Field<double> azimuth;
    Field<uint16_t> amplitude;
    BitField<uint8_t, 1> xImpulse;
    BitField<uint8_t, 5> mode;
    Field<uint32_t> unitCode;
    Field<uint32_t> bortNumber;
    Field<uint32_t> altitude;
    BitField<uint8_t, 1> spi;
    BitField<uint8_t, 1> militaryAlarm;
    Field<RbsCodes> mode_1;
    Field<RbsCodes> mode_2;
    Field<RbsCodes> mode_3A;
    Field<RbsCodes> mode_C;
    Field<Parol> parol;
    Field<ModeS> modes;
    BitField<uint8_t, 1> isRollCall;
    Field<uint16_t> M;
    Field<uint16_t> packsNum;
    PeriodicBitField<Answer> pack = { packsNum };               
};


} // namespace pdp


#endif // GUARD_6a75db93_e23c_4c0c_8214_b76757d6bac2
