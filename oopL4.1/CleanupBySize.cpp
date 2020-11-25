//
// Created by castl on 25.11.2020.
//

#include "CleanupBySize.h"

CleanupBySize::CleanupBySize(int size) {
    if (size <= 0)
        throw std::invalid_argument("Impossible size in this cleanup algorithm");
    this->size = size;
}

std::vector<unsigned int> CleanupBySize::deleteRestorePoint(Backup *backup) {
    std::vector<unsigned int> deletedNumbers;

    int it = 0;
    int rpSize = backup->getRestorePoints().size();
    int backupSize = backup->getBackupSize();
    int i = rpSize - 1;

    if (this->size >= backup->getBackupSize())
        return {};

    while (it != rpSize) {
        if (this->size < backupSize) {
            //backup->deleteRestorePoint(i);
            deletedNumbers.push_back(it);
            --i;
            --rpSize;
            backupSize = backupSize - this->size;
        }
        else
            break;
    }

    return deletedNumbers;
}
