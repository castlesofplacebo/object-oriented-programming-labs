#ifndef OOPL3_COMBINEDRACE_H
#define OOPL3_COMBINEDRACE_H
#include "Race.h"
#include <utility>
#include <vector>

class CombinedRace : public Race {
private:
    std::vector<AirTransport> airTransport;
    std::vector<LandTransport> landTransport;
public:
    explicit CombinedRace(double distance);
    void addTransport(std::vector<AirTransport> aTransport, std::vector<LandTransport> lTransport);

    Transport* getWinner();
};

#endif //OOPL3_COMBINEDRACE_H
