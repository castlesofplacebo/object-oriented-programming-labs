//
// Created by castl on 26.11.2020.
//

#ifndef OOPL4_1_CLEANUPHYBRID_H
#define OOPL4_1_CLEANUPHYBRID_H
#include "CleanupAlgorithms.h"
#include <iostream>

class CleanupHybrid : public CleanupAlgorithms {
private:
    CleanupAlgorithms* algo1;
    CleanupAlgorithms* algo2;
    std::string param;
public:
    CleanupHybrid(CleanupAlgorithms* cleanAlgo1, CleanupAlgorithms* cleanAlgo2, std::string cleanParam);
    std::vector<unsigned int> deleteRestorePoint(Backup *backup) override;
};

#endif //OOPL4_1_CLEANUPHYBRID_H
