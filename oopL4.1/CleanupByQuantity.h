//
// Created by castl on 25.11.2020.
//

#ifndef OOPL4_1_CLEANUPBYQUANTITY_H
#define OOPL4_1_CLEANUPBYQUANTITY_H

#include "CleanupAlgorithms.h"

class CleanupByQuantity : public CleanupAlgorithms {
private:
    int quant = 0;
public:
    explicit CleanupByQuantity(int quantity);
    std::vector<unsigned int> deleteRestorePoint(Backup *backup) override;
};
#endif //OOPL4_1_CLEANUPBYQUANTITY_H
