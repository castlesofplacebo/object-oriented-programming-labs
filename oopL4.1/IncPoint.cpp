//
// Created by castl on 16.11.2020.
//

#include "IncPoint.h"

IncPoint::IncPoint(const std::vector<FileInfo> &currentFiles, std::vector<RestorePoint> prevRestorePoints) : RestorePoint() {
    this->setPointType("inc");

    if (prevRestorePoints.empty())
        for (const auto &k : currentFiles)
            this->addRestoreFile(k);
    else {
        bool isFind = false;
        for (auto j : currentFiles) {
            for (auto i : prevRestorePoints.back().getRestoreFiles()) {
                if ((j.getDirName() == i.getDirName() && j.getFileName() == i.getFileName() && j.getFileSize() == i.getFileSize()) || isFind) {
                    isFind = true;
                    continue;
                }
                else
                    this->addRestoreFile(i);
            }
        }
    }
}