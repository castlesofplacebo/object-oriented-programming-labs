#ifndef OOPL3_TRANSPORT_H
#define OOPL3_TRANSPORT_H
#include <iostream>

class Transport {
private:
    int speed;
    std::string transportType;
    std::string name;
public:
    void setSpeed(int curSpeed);
    void setTransportType(std::string currentTransportType);
    void setName(std::string currentName);

    int getSpeed();
    std::string getName();
    std::string getTransportType();

    virtual double getTime(double distance) = 0;
};

#endif //OOPL3_TRANSPORT_Hr
