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

enum typePoint {
    FULL = 0,
    INC = 1
};

class Backup {
private:
    long long int backupID;
    time_t creationTime;
    int backupSize = 0;
    std::vector<RestorePoint> backupRestorePoints;
    std::vector<std::vector<FileInfo>> currentFiles;

public:
    Backup();

    explicit Backup(const std::vector<std::string> &files);

    void addObjects(const std::string &file);

    void deleteObjects(const std::string &file);

    char *getCreationTime();

    int getBackupSize();

    void getCurrentFiles();

    void addRestorePoint(typePoint point);

};

#endif //OOPL4_1_BACKUP_H