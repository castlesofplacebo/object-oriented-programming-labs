//
// Created by castl on 25.11.2020.
//

#ifndef OOPL4_1_CLEANUPALGORITHMS_H
#define OOPL4_1_CLEANUPALGORITHMS_H

#include "Backup.h"

class CleanupAlgorithms {
public:
    CleanupAlgorithms();

    virtual std::vector<unsigned int> deleteRestorePoint(Backup *backup);
};

#endif //OOPL4_1_CLEANUPALGORITHMS_H
