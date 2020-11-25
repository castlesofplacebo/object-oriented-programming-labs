//
// Created by castl on 26.11.2020.
//

#include "CleanupHybrid.h"

#include <utility>

CleanupHybrid::CleanupHybrid(CleanupAlgorithms *cleanAlgo1, CleanupAlgorithms *cleanAlgo2, std::string cleanParam) {
    this->algo1 = cleanAlgo1;
    this->algo2 = cleanAlgo2;
    if (cleanParam == "max" || cleanParam == "min")
        this->param = std::move(cleanParam);
    else
        throw std::invalid_argument("Invalid param of CleanupHybrid : use 'max' or 'min'");
}

std::vector<unsigned int> CleanupHybrid::deleteRestorePoint(Backup *backup) {
    std::vector<unsigned int> numbersToDelete1(this->algo1->deleteRestorePoint(backup));
    int first = backup->getRestorePoints().size() - numbersToDelete1.size();//оставить в 1 случае

    std::vector<unsigned int> numbersToDelete2(this->algo2->deleteRestorePoint(backup));
    int second = backup->getRestorePoints().size() - numbersToDelete2.size();//оставить во 2 случае

    if (this->param == "max") {
        if (first <= second) {
            return numbersToDelete2;
        }
        else return numbersToDelete1;
    }
    else {
        if (first <= second)
            return numbersToDelete1;
        else
            return numbersToDelete2;
    }
}
