#ifndef OOPL3_SPEEDBOATCAMEL_H
#define OOPL3_SPEEDBOATCAMEL_H
#include "LandTransport.h"

class SpeedboatCamel : public LandTransport {
public:
    SpeedboatCamel();
    void updateRest() override;
};


#endif //OOPL3_SPEEDBOATCAMEL_H
