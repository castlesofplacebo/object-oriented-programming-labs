//
// Created by castl on 18.11.2020.
//

#ifndef OOPL4_1_BACKUPJOB_H
#define OOPL4_1_BACKUPJOB_H

#include <iostream>
#include "Backup.h"
#include "StorageAlgorithms.h"
#include "CleanupAlgorithms.h"

class BackupJob {
private:
    unsigned int id = 0; //number of restore point
    Backup* backup;
    StorageAlgorithms* algorithm;
    std::string info {};
public:
    BackupJob(Backup* backup1, StorageAlgorithms* algorithm1);

    std::string applyCleanupAlgorithm(CleanupAlgorithms* cleanupAlgorithm1);

    FullPoint createFullPoint();
    IncPoint createIncPoint();

    void incId();
    unsigned int getId();

    std::string getInfo();
    void addInfo(const std::string& newInfo);
};

#endif //OOPL4_1_BACKUPJOB_H