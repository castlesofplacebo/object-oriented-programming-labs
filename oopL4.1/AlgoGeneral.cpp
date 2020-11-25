//
// Created by castl on 16.11.2020.
//

#include "AlgoGeneral.h"

#include <utility>

AlgoGeneral::AlgoGeneral() = default;

std::string AlgoGeneral::setInfo(const std::vector<FileInfo> &currentFiles, unsigned int id) {
    std::string info;
    info += "Using general algorithm:\n";

    std::string pathFromBackup = "target/";
    pathFromBackup += "restore-point-" + std::to_string(id) + ".zip" + '\n';
    info += pathFromBackup;

    return info;
}