//
// Created by castl on 16.11.2020.
//

#ifndef OOPL4_1_FULLPOINT_H
#define OOPL4_1_FULLPOINT_H

#include "RestorePoint.h"

class FullPoint : public RestorePoint {
public:
    explicit FullPoint(std::vector<FileInfo> currentFiles);
};

#endif //OOPL4_1_FULLPOINT_H
