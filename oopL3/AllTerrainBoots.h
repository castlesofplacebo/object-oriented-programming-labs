#ifndef OOPL3_ALLTERRAINBOOTS_H
#define OOPL3_ALLTERRAINBOOTS_H
#include "LandTransport.h"

class AllTerrainBoots : public LandTransport {
public:
    AllTerrainBoots();
    void updateRest() override;
};

#endif //OOPL3_ALLTERRAINBOOTS_H
