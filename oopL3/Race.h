#ifndef OOPL3_RACE_H
#define OOPL3_RACE_H
#include <iostream>
#include <utility>
#include <vector>
#include "Transport.h"

class Race {
private:
    double raceDistance;
public:
    void setRaceDistance(double currentDistance);

    double getRaceDistance();
};

#endif //OOPL3_RACE_H