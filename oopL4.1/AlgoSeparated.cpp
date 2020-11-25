//
// Created by castl on 16.11.2020.
//

#include "AlgoSeparated.h"

AlgoSeparated::AlgoSeparated() = default;

std::string AlgoSeparated::setInfo(const std::vector<FileInfo> &currentFiles, unsigned int id) {
    std::string info;
    info += "Using separated algorithm:\n";
    std::string dirName = " ";

    for (auto i : currentFiles) {
        std::string pathFromBackup = "target/";

        if (i.getDirName().empty()) {//if file
            pathFromBackup += "restore-point-" + std::to_string(id) + '-' + i.getFileName() + '\n';
            info += pathFromBackup;
            pathFromBackup = "";
        }
        else {//if directory
            if (i.getDirName() != dirName) {
                pathFromBackup += "restore-point-" + std::to_string(id) + '-' + i.getDirName() + '\n';
                dirName = i.getDirName();
                info += pathFromBackup;
                pathFromBackup = "";
            }
        }
    }
    return info;
}