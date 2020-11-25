//
// Created by castl on 25.11.2020.
//

#ifndef OOPL4_1_CLEANUPBYDATE_H
#define OOPL4_1_CLEANUPBYDATE_H

#include "CleanupAlgorithms.h"

class CleanupByDate : public CleanupAlgorithms {
private:
    time_t currentDate{};
public:
    CleanupByDate(int date, int month, int year);
    std::vector<unsigned int> deleteRestorePoint(Backup *backup) override;
};
#endif //OOPL4_1_CLEANUPBYDATE_H
