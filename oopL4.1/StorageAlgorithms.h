//
// Created by castl on 17.11.2020.
//

#ifndef OOPL4_1_STORAGEALGORITHMS_H
#define OOPL4_1_STORAGEALGORITHMS_H

#include "IncPoint.h"
#include "FullPoint.h"
#include "RestorePoint.h"
#include "Backup.h"
#include <vector>
#include <iostream>

class StorageAlgorithms {
public:
    StorageAlgorithms();

    virtual std::string setInfo(const std::vector <FileInfo>& currentFiles, unsigned int id);
};

#endif //OOPL4_1_STORAGEALGORITHMS_H