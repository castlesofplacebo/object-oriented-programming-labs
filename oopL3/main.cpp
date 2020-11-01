#include <iostream>
#include <vector>
#include "BactrainCamel.h"
#include "SpeedboatCamel.h"
#include "Centaur.h"
#include "AllTerrainBoots.h"
#include "MagicCarpet.h"
#include "Mortar.h"
#include "Broom.h"
#include "LandRace.h"
#include "AirRace.h"
#include "CombinedRace.h"

int main() {
    try {
        /*BactrainCamel b;
        std::cout << b.getTime(1000);*/
        /*SpeedboatCamel s;
        std::cout << s.getTime(100);*/
        /*Centaur c;
        std::cout << c.getTime(100);*/
        /*AllTerrainBoots a;
        std::cout << a.getTime(100);*/
        //LandTransport l(10, 20, "car");
        /*Broom b;
        std::cout << b.getTime(1500);*/

        //TODO : testing for races 1)land 2)air 3)combined --adding transport

        Centaur c;
        SpeedboatCamel s;
        Broom b;

        CombinedRace l(100);
        std::vector<LandTransport> land;
        land.emplace_back(c);
        land.emplace_back(s);
        /*l.addTransport(land);
        LandTransport winner = l.getWinner();
        std::cout << winner.getName();*/

        //TODO : testing for races 2)air 3)combined  --getting the winner

        std::vector<AirTransport> air;
        air.emplace_back(b);
        l.addTransport(air, land);
        Transport* winner = l.getWinner();

        std::cout << winner->getName() << std::endl;
    }

    catch (std::exception &err) {
        std::cout << err.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}