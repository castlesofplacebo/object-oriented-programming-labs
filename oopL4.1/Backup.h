//
// Created by castl on 15.11.2020.
//

#ifndef OOPL4_1_BACKUP_H
#define OOPL4_1_BACKUP_H

#include <iostream>
#include <ctime>
#include <vector>
#include <map>
#include "FileInfo.h"
#include "RestorePoint.h"
#include "StorageAlgorithms.h"

class Backup {
private:
    long long int backupID;
    time_t creationTime;
    int backupSize = 0;
    std::vector<FileInfo> currentFiles;
    std::vector<RestorePoint> backupRestorePoints;
public:
    Backup();

    explicit Backup(const std::vector<std::string> &files);

    void addObjects(const std::string &file);

    void deleteObjects(const std::string &file);

    char *getCreationTime();

    int getBackupSize();

    std::vector<FileInfo> getCurrentFiles();

    void addRestorePoint(RestorePoint point);

    std::vector<RestorePoint> getRestorePoints();

    void deleteRestorePoint(unsigned int it);

    //to check
    void showRestorePoints();

};

#endif //OOPL4_1_BACKUP_H