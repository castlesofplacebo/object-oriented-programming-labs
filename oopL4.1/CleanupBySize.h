//
// Created by castl on 25.11.2020.
//

#ifndef OOPL4_1_CLEANUPBYSIZE_H
#define OOPL4_1_CLEANUPBYSIZE_H

#include "CleanupAlgorithms.h"

class CleanupBySize : public CleanupAlgorithms {
private:
    int size = 0;
public:
    explicit CleanupBySize(int size);
    std::vector<unsigned int> deleteRestorePoint(Backup *backup) override;
};

#endif //OOPL4_1_CLEANUPBYSIZE_H
