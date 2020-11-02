#ifndef OOPL3_CENTAUR_H
#define OOPL3_CENTAUR_H
#include "LandTransport.h"

class Centaur : public LandTransport {
public:
    Centaur();
    void updateRest() override;
};

#endif //OOPL3_CENTAUR_H
