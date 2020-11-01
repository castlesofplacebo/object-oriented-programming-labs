#include <iostream>
#include <utility>
#include "Transport.h"
#include "LandTransport.h"
#include "AirTransport.h"
#include "BactrainCamel.h"
#include "SpeedboatCamel.h"
#include "Centaur.h"
#include "AllTerrainBoots.h"
#include "MagicCarpet.h"
#include "Mortar.h"
#include "Broom.h"
#include "Race.h"
#include "LandRace.h"
#include "AirRace.h"
#include "CombinedRace.h"

void Transport::setSpeed(int curSpeed) {
    this->speed = curSpeed;
}

void Transport::setTransportType(std::string currentTransportType) {
    this->transportType = std::move(currentTransportType);
}

int Transport::getSpeed() {
    return this->speed;
}

std::string Transport::getTransportType() {
    return this->transportType;
}

void Transport::setName(std::string currentName) {
    this->name = std::move(currentName);
}

LandTransport::LandTransport(int currentSpeed, int currentRestInterval, std::string currentName) {
    this->setSpeed(currentSpeed);
    this->restInterval = currentRestInterval;
    this->setTransportType("LandTransport");
    this->restNumber = 0;
    this->restDuration = 0;
    this->setName(std::move(currentName));
}

void LandTransport::setRestNumber() {
    ++this->restNumber;
}

int LandTransport::getRestNumber() {
    return this->restNumber;
}

void LandTransport::setRestDuration(double currentDuration) {
    this->restDuration = currentDuration;
}

int LandTransport::getRestInterval() {
    return this->restInterval;
}

double LandTransport::getRestDuration() {
    return this->restDuration;
}

double LandTransport::getTime(double distance) {
    if (distance <= 0)
        throw std::invalid_argument("Invalid distance");

    double currentDistance = 0.0;
    double nextDistance = distance;
    double time = 0.0;

    while (currentDistance != distance) {
        //distance before rest
        currentDistance += this->getSpeed() * this->getRestInterval();

        if (currentDistance >= distance) {
            time += nextDistance / this->getSpeed();
            return time;
        }
        else {
            this->setRestNumber();

            std::string s = this->getName();
            //checking for name
            if (s == "BactrainCamel") {
                if (this->getRestNumber() == 1)
                    this->setRestDuration(5);
                else this->setRestDuration(8);
            }
            else if (s == "SpeedboatCamel") {
                if (this->getRestNumber() == 1)
                    this->setRestDuration(5);
                else if (this->getRestNumber() == 2)
                    this->setRestDuration(6.5);
                else this->setRestDuration(8);
            }
            else if (s == "Centaur")
                this->setRestDuration(2);
            else if (s == "AllTerrainBoots") {
                if (this->getRestNumber() == 1)
                    this->setRestDuration(10);
                else this->setRestDuration(5);
            }
            else this->setRestDuration(0); //users transport

            time += this->getRestInterval() + this->getRestDuration();
            nextDistance = distance - currentDistance;
        }
    }
    return time;
}

std::string Transport::getName() {
    return this->name;
}

BactrainCamel::BactrainCamel()
:LandTransport(10, 30, "BactrainCamel")
{
}

SpeedboatCamel::SpeedboatCamel()
:LandTransport(40, 10, "SpeedboatCamel")
{
}

Centaur::Centaur()
:LandTransport(15, 8, "Centaur")
{
}

AllTerrainBoots::AllTerrainBoots()
:LandTransport(6, 60, "AllTerrainBoots")
{
}

AirTransport::AirTransport(int currentSpeed, std::string currentName) {
    this->setSpeed(currentSpeed);
    this->setTransportType("AirTransport");
    this->setName(std::move(currentName));
    this->coefficient = 0;
}

MagicCarpet::MagicCarpet()
:AirTransport(10, "MagicCarpet")
{
}

Mortar::Mortar()
:AirTransport(8, "Mortar")
{
}

Broom::Broom()
:AirTransport(20, "Broom")
{
}

double AirTransport::getTime(double distance) {
    if (distance <= 0)
        throw std::invalid_argument("Invalid distance");

    double currentDistance = 0.0;
    double time = 0.0;

    std::string s = this->getName();
    if (s == "MagicCarpet") {
        if (distance <= 1000)
           setCoefficient(0);

        else if (distance <= 5000)
            this->setCoefficient(3);

        else if (distance <= 10000)
            this->setCoefficient(10);

        else
            this->setCoefficient(5);
    }
    else if (s == "Mortar") {
        this->setCoefficient(6);
    }
    else if (s == "Broom") {
        int currentCoefficient = distance / 1000;
        if (currentCoefficient == 0)
            currentCoefficient = 1;

        this->setCoefficient(currentCoefficient);
    }
    else this->setCoefficient(0); //user transport

    if (this->getCoefficient() == 100)
        throw std::invalid_argument("Invalid coefficient");

    currentDistance = distance * (100 - this->getCoefficient()) / 100;
    time = currentDistance / this->getSpeed();

    return time;
}

void AirTransport::setCoefficient(int currentCoefficient) {
    this->coefficient = currentCoefficient;
}

int AirTransport::getCoefficient() {
    return this->coefficient;
}

void Race::setRaceDistance(double currentDistance) {
    this->raceDistance = currentDistance;
}

double Race::getRaceDistance() {
    return this->raceDistance;
}

LandRace::LandRace(double distance) : Race() {
    this->setRaceDistance(distance);
}

void LandRace::addTransport(std::vector<LandTransport> lTransport) {
    landTransport = std::move(lTransport);
}

LandTransport LandRace::getWinner() {
    LandTransport winner;
    double Min = 1e9;
    if (this->landTransport.empty())
        throw std::invalid_argument("No transport in the race");

    for (auto i : this->landTransport) {
        double curTime = i.getTime(this->getRaceDistance());
        //std::cout << curTime << " " << i.getName() << std::endl;
        if (curTime < Min) {
            Min = curTime;
            winner = i;
        }
    }
    return winner;
}

AirTransport AirRace::getWinner() {
    AirTransport winner;
    double Min = 1e9;
    if (this->airTransport.empty())
        throw std::invalid_argument("No transport in the race");

    for (auto i : this->airTransport) {
        double curTime = i.getTime(this->getRaceDistance());
        //std::cout << curTime << " " << i.getName() << std::endl;
        if (curTime < Min) {
            Min = curTime;
            winner = i;
        }
    }
    return winner;
}

AirRace::AirRace(double distance) : Race() {
    this->setRaceDistance(distance);
}

void AirRace::addTransport(std::vector<AirTransport> aTransport) {
    airTransport = std::move(aTransport);
}

CombinedRace::CombinedRace(double distance) : Race() {
    this->setRaceDistance(distance);
}

void CombinedRace::addTransport(std::vector<AirTransport> aTransport, std::vector<LandTransport> lTransport) {
    airTransport = std::move(aTransport);
    landTransport = std::move(lTransport);
}

Transport* CombinedRace::getWinner() {
    LandTransport* lWinner = nullptr;
    double lMin = 1e9;
    if (this->landTransport.empty())
        throw std::invalid_argument("No transport in the race");

    if (this->airTransport.empty())
        throw std::invalid_argument("No transport in the race");

    for (auto & i : landTransport) {
        double curTime = i.getTime(this->getRaceDistance());
        std::cout << curTime << " " << i.getName() << std::endl;
        if (curTime < lMin) {
            lMin = curTime;
            lWinner = &i;
        }
    }

    AirTransport* aWinner = nullptr;
    double aMin = 1e9;

    for (auto & i : this->airTransport) {
        double curTime = i.getTime(this->getRaceDistance());
        std::cout << curTime << " " << i.getName() << std::endl;
        if (curTime < aMin) {
            aMin = curTime;
            aWinner = &i;
        }
    }

    std::cout << lWinner << std::endl;
    std::cout << aWinner << std::endl;
    if (lMin < aMin)
        return lWinner;
    else return aWinner;
}