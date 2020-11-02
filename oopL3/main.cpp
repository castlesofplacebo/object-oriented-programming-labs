#include <iostream>
#include <vector>
#include "BactrainCamel.h"
#include "SpeedboatCamel.h"
#include "Centaur.h"
#include "AllTerrainBoots.h"
#include "MagicCarpet.h"
#include "Mortar.h"
#include "Broom.h"
#include "Race.h"
#include "AirTransport.h"
#include "LandTransport.h"
#include "Transport.h"

int main() {
    try {
        Centaur c;
        SpeedboatCamel s;
        Broom b;
        MagicCarpet m;

        Race<AirTransport> a(1000);
        std::vector<AirTransport*> air;
        air.emplace_back(&b);
        air.emplace_back(&m);
        a.addTransport(air);
        Transport* winner = a.getWinner();
        std::cout << winner->getName();
    }
    catch (std::exception &err) {
        std::cout << err.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}