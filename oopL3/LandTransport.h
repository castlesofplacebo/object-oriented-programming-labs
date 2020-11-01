#ifndef OOPL3_LANDTRANSPORT_H
#define OOPL3_LANDTRANSPORT_H
#include "Transport.h"

class LandTransport : public Transport {
private:
    int restInterval{};
    double restDuration{};
    int restNumber{};
public:
    LandTransport() = default;
    LandTransport(int currentSpeed, int currentRestInterval, std::string currentName);

    void setRestNumber();
    void setRestDuration(double currentDuration);

    int getRestInterval();
    double getRestDuration();
    int getRestNumber();

    double getTime(double distance) override;
};

#endif //OOPL3_LANDTRANSPORT_H
