//
// Created by castl on 16.11.2020.
//

#ifndef OOPL4_1_INCPOINT_H
#define OOPL4_1_INCPOINT_H

#include "RestorePoint.h"

class IncPoint : public RestorePoint {
public:
    explicit IncPoint(const std::vector<FileInfo> &currentFiles, std::vector<RestorePoint> prevRestorePoints);
};

#endif //OOPL4_1_INCPOINT_H