//
// Created by castl on 16.11.2020.
//

#include "RestorePoint.h"
#include <utility>

RestorePoint::RestorePoint() {
    //this->incId();
    this->creationTime = time(nullptr);
}

RestorePoint::RestorePoint(std::vector<FileInfo> currentFiles) : RestorePoint() {
    this->restoreFiles = std::move(currentFiles);
}

time_t RestorePoint::getCreationTime() {
  return creationTime;
}

std::vector<FileInfo> RestorePoint::getRestoreFiles() {
    return this->restoreFiles;
}

void RestorePoint::addRestoreFile(const FileInfo& currentFile) {
    this->restoreFiles.emplace_back(currentFile);
}

void RestorePoint::setPointType(std::string type) {
    this->pointType = std::move(type);
}

std::string RestorePoint::getPointType() {
    return this->pointType;
}
