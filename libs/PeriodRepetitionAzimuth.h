#ifndef GUARD_f5811de3_847a_49a8_8e9b_db6a89de8de7
#define GUARD_f5811de3_847a_49a8_8e9b_db6a89de8de7


#include <libs/GenericPrototypes/GenericPrototypes.h>



namespace dsp
{


struct PeriodRepetitionAzimuth : public Codogramm
{
    enum { MessageTypeCode = 1 };
    
    PeriodRepetitionAzimuth()
    {
        appendToOrder( { &azimuth } );
        appendToOrder( { &empty1 } );
        appendToOrder( { &nrdTime } );
    }
    
    PeriodRepetitionAzimuth(const PeriodRepetitionAzimuth& orig)
        : PeriodRepetitionAzimuth()
    {
        *this = orig;
    }
    
    Field<uint16_t> azimuth = lsb{ 360.0 / 65536 };             
    Field<uint16_t> empty1;
    Field<uint32_t> nrdTime = lsb{ 0.00000000625 };             
};


} // namespace dsp


#endif // GUARD_f5811de3_847a_49a8_8e9b_db6a89de8de7
