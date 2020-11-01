#ifndef OOPL3_AIRTRANSPORT_H
#define OOPL3_AIRTRANSPORT_H
#include "Transport.h"

class AirTransport : public Transport {
private:
    int coefficient{};
public:
    AirTransport() = default;
    AirTransport(int currentSpeed, std::string currentName);
    void setCoefficient(int currentCoefficient);

    int getCoefficient();
    double getTime(double distance) override;
};



#endif //OOPL3_AIRTRANSPORT_H
