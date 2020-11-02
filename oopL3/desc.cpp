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
            this->updateRest();

            time += this->getRestInterval() + this->getRestDuration();
            nextDistance = distance - currentDistance;
        }
    }
    return time;
}

std::string Transport::getName() {
    return this->name;
}

void Transport::setRaceDistance(double currentRaceDistance) {
    raceDistance = currentRaceDistance;
}

double Transport::getRaceDistance() {
    return this->raceDistance;
}

BactrainCamel::BactrainCamel()
:LandTransport(10, 30, "BactrainCamel")
{
}

void BactrainCamel::updateRest() {
    if (this->getRestNumber() == 1)
        this->setRestDuration(5);
    else this->setRestDuration(8);
}

SpeedboatCamel::SpeedboatCamel()
:LandTransport(40, 10, "SpeedboatCamel")
{
}

void SpeedboatCamel::updateRest() {
    if (this->getRestNumber() == 1)
        this->setRestDuration(5);
    else if (this->getRestNumber() == 2)
        this->setRestDuration(6.5);
    else this->setRestDuration(8);
}

Centaur::Centaur()
:LandTransport(15, 8, "Centaur")
{
}

void Centaur::updateRest() {
    this->setRestDuration(2);
}

AllTerrainBoots::AllTerrainBoots()
:LandTransport(6, 60, "AllTerrainBoots")
{
}

void AllTerrainBoots::updateRest() {
    if (this->getRestNumber() == 1)
        this->setRestDuration(10);
    else this->setRestDuration(5);
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
    if (this->getRaceDistance() <= 1000)
        setCoefficient(0);

    else if (this->getRaceDistance() <= 5000)
        this->setCoefficient(3);

    else if (this->getRaceDistance() <= 10000)
        this->setCoefficient(10);

    else
        this->setCoefficient(5);
}

Mortar::Mortar()
:AirTransport(8, "Mortar")
{
    this->setCoefficient(6);
}

Broom::Broom()
:AirTransport(20, "Broom")
{
    int currentCoefficient = this->getRaceDistance() / 1000;
    if (currentCoefficient == 0)
        currentCoefficient = 1;

    this->setCoefficient(currentCoefficient);
}

double AirTransport::getTime(double distance) {
    if (distance <= 0)
        throw std::invalid_argument("Invalid distance");

    if (this->getCoefficient() == 100)
        throw std::invalid_argument("Invalid coefficient");

    double currentDistance;
    double time;
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