//
// Created by castl on 16.11.2020.
//

#ifndef OOPL4_1_ALGOSEPARATED_H
#define OOPL4_1_ALGOSEPARATED_H

#include "StorageAlgorithms.h"
#include "FileInfo.h"
#include <iostream>
#include <vector>

class AlgoSeparated : public StorageAlgorithms {
public:
    AlgoSeparated();
    std::string setInfo(const std::vector<FileInfo> &currentFiles, unsigned int id) override;
};

#endif //OOPL4_1_ALGOSEPARATED_H
