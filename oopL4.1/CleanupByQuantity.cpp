//
// Created by castl on 25.11.2020.
//
#include <iostream>
#include "CleanupByQuantity.h"

CleanupByQuantity::CleanupByQuantity(int quantity) {
    if (quantity < 0)
        throw std::invalid_argument("Impossible quantity in this cleanup algorithm");
    this->quant = quantity;
}

std::vector<unsigned int> CleanupByQuantity::deleteRestorePoint(Backup *backup) {
    std::vector<unsigned int> deletedNumbers;

    int it = 0;
    int i = 0;
    int size = backup->getRestorePoints().size();

    if ((size - this->quant) <= 0)
        return {};

    while (it != size) {
        if (i <= (size - this->quant)) {
            //backup->deleteRestorePoint(it);
            deletedNumbers.push_back(i);
            ++i;
            --size;
        }
        else
            ++it;
    }

    return deletedNumbers;
}
