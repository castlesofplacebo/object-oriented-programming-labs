//
// Created by castl on 16.11.2020.
//

#ifndef OOPL4_1_ALGOGENERAL_H
#define OOPL4_1_ALGOGENERAL_H

#include "StorageAlgorithms.h"
#include "FileInfo.h"
#include "IncPoint.h"
#include <vector>
#include <iostream>

class AlgoGeneral : public StorageAlgorithms {
public:
    explicit AlgoGeneral();
    std::string setInfo(const std::vector<FileInfo> &currentFiles, unsigned int id) override;
};

#endif //OOPL4_1_ALGOGENERAL_H
