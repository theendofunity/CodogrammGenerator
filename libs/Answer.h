#ifndef GUARD_57340f43_b02c_48ee_b6d0_96c20572389c
#define GUARD_57340f43_b02c_48ee_b6d0_96c20572389c


#include <libs/GenericPrototypes/GenericPrototypes.h>



namespace pdp
{


struct Answer : public Codogramm
{
    enum { MessageTypeCode = 127 };
    
    struct ExtendedInfo : public Codogramm
    {
        ExtendedInfo()
        {
            appendToOrder( { &otherModeData } );
            appendToOrder( { &bds1 } );
            appendToOrder( { &bds2 } );
            appendToOrder( { &modesDataSize } );
            appendToOrder( { &modeS } );
        }
        
        ExtendedInfo(const ExtendedInfo& orig)
            : ExtendedInfo()
        {
            *this = orig;
        }
        
        Field<uint32_t> otherModeData;
        BitField<uint8_t, 4> bds1;
        BitField<uint8_t, 4> bds2;
        Field<uint8_t> modesDataSize;
        PeriodicBitField<uint32_t> modeS = { modesDataSize };       
    };
    
    struct ResponseSignalInfo : public Codogramm
    {
        ResponseSignalInfo()
        {
            appendToOrder( { &Dos } );
            appendToOrder( { &dDS } );
            appendToOrder( { &ASP } );
            appendToOrder( { &HIP } );
            appendToOrder( { &empty1 } );
            appendToOrder( { &oP1 } );
            appendToOrder( { &oP2 } );
            appendToOrder( { &oP3 } );
            appendToOrder( { &oP4 } );
            appendToOrder( { &empty2 } );
            appendToOrder( { &oP6 } );
            appendToOrder( { &oM1 } );
            appendToOrder( { &oM2 } );
            appendToOrder( { &oRA } );
            appendToOrder( { &oM4 } );
            appendToOrder( { &empty3 } );
            appendToOrder( { &oRC } );
            appendToOrder( { &oRS } );
            appendToOrder( { &exInfo } );
        }
        
        ResponseSignalInfo(const ResponseSignalInfo& orig)
            : ResponseSignalInfo()
        {
            *this = orig;
        }
        
        BitField<uint32_t, 20> Dos;
        BitField<uint16_t, 10> dDS;
        BitField<uint8_t, 1> ASP;
        BitField<uint8_t, 1> HIP;
        BitField<uint8_t, 2> empty1;
        BitField<uint8_t, 1> oP1;
        BitField<uint8_t, 1> oP2;
        BitField<uint8_t, 1> oP3;
        BitField<uint8_t, 1> oP4;
        BitField<uint8_t, 1> empty2;
        BitField<uint8_t, 1> oP6;
        BitField<uint8_t, 1> oM1;
        BitField<uint8_t, 1> oM2;
        BitField<uint8_t, 1> oRA;
        BitField<uint8_t, 1> oM4;
        BitField<uint8_t, 1> empty3;
        BitField<uint8_t, 1> oRC;
        BitField<uint8_t, 2> oRS;
        Field<ExtendedInfo> exInfo;
    };
    
    struct Amplitude : public Codogramm
    {
        Amplitude()
        {
            appendToOrder( { &sum } );
            appendToOrder( { &dif } );
            appendToOrder( { &pbl } );
        }
        
        Amplitude(const Amplitude& orig)
            : Amplitude()
        {
            *this = orig;
        }
        
        Field<uint32_t> sum;
        Field<uint32_t> dif;
        Field<uint32_t> pbl;
    };
    
    struct PelengatedInfo : public Codogramm
    {
        PelengatedInfo()
        {
            appendToOrder( { &distance } );
            appendToOrder( { &azimuth } );
            appendToOrder( { &phase } );
            appendToOrder( { &amplitude } );
        }
        
        PelengatedInfo(const PelengatedInfo& orig)
            : PelengatedInfo()
        {
            *this = orig;
        }
        
        Field<double> distance;
        Field<double> azimuth;
        Field<double> phase;
        Field<Amplitude> amplitude;
    };
    
    Answer()
    {
        appendToOrder( { &radio } );
        appendToOrder( { &monopulseAzimuth } );
        appendToOrder( { &monopulseCorrection } );
        appendToOrder( { &phase } );
        appendToOrder( { &distance } );
        appendToOrder( { &info } );
    }
    
    Answer(const Answer& orig)
        : Answer()
    {
        *this = orig;
    }
    
    Field<PelengatedInfo> radio;
    Field<double> monopulseAzimuth;
    Field<double> monopulseCorrection;
    Field<double> phase;
    Field<double> distance;
    Field<ResponseSignalInfo> info;
};


} // namespace pdp


#endif // GUARD_57340f43_b02c_48ee_b6d0_96c20572389c
