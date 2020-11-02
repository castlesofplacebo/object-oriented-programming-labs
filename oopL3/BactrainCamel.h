#ifndef OOPL3_BACTRAINCAMEL_H
#define OOPL3_BACTRAINCAMEL_H
#include "LandTransport.h"

class BactrainCamel : public LandTransport {
public:
    BactrainCamel();
    void updateRest() override;
};

#endif //OOPL3_BACTRAINCAMEL_H
