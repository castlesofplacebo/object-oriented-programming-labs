#ifndef OOPL3_RACE_H
#define OOPL3_RACE_H
#include <iostream>
#include <utility>
#include <vector>
#include "Transport.h"

template <class T>
class Race {
private:
    double raceDistance{};
    std::vector<T*> transport{};
public:
    explicit Race(double distance) {
        this->raceDistance = distance;
    };

    void setTransport(T* currentTransport) {
        this->transport.emplace_back(currentTransport);
    };

    double getRaceDistance() {
        return this->raceDistance;
    };

    void addTransport(std::vector<T*> currentTransport) {
        for (auto &i : currentTransport) {
            this->setTransport(i);
        }
    };

    T* getWinner() {
        T* aWinner = nullptr;
        double aMin = 1e9;

        if (transport.empty())
            throw std::invalid_argument("No transport in the race");

        for (auto & i : transport) {
            std::string currentTransportType = i->getTransportType();
            double curTime = i->getTime(this->getRaceDistance());
            //std::cout << i->getName() << " " << curTime<< std::endl;
            if (curTime < aMin) {
                aMin = curTime;
                aWinner = i;
            }
        }
        return aWinner;
    };
};

#endif //OOPL3_RACE_H