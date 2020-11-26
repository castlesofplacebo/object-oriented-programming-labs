//
// Created by castl on 16.11.2020.
//

#ifndef OOPL4_1_RESTOREPOINT_H
#define OOPL4_1_RESTOREPOINT_H

#include <ctime>
#include <vector>
#include "FileInfo.h"

class RestorePoint {
private:
    //unsigned int id = 0;
    std::string pointType {};
    time_t creationTime = 0;
    std::vector<FileInfo> restoreFiles {};
public:
    RestorePoint();
    explicit RestorePoint(std::vector<FileInfo> currentFiles);
    void addRestoreFile(const FileInfo& currentFile);
    void setPointType(std::string type);
    std::string getPointType();

    time_t getCreationTime();
    std::vector<FileInfo> getRestoreFiles();
};

#endif //OOPL4_1_RESTOREPOINT_H