#ifndef OOPL3_AIRRACE_H
#define OOPL3_AIRRACE_H
#include "Race.h"
#include <utility>
#include <vector>

class AirRace : public Race {
private:
    std::vector<AirTransport> airTransport;
public:
    explicit AirRace(double distance);
    void addTransport(std::vector<AirTransport> aTransport);

    AirTransport getWinner();
};
#endif //OOPL3_AIRRACE_H
