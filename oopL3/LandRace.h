#ifndef OOPL3_LANDRACE_H
#define OOPL3_LANDRACE_H
#include "Race.h"
#include <utility>
#include <vector>

class LandRace : public Race {
private:
    std::vector <LandTransport> landTransport;
public:
    explicit LandRace(double distance);
    void addTransport(std::vector<LandTransport> lTransport);

    LandTransport getWinner();
};



#endif //OOPL3_LANDRACE_H