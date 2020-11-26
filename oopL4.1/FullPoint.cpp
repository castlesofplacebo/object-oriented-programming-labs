//
// Created by castl on 16.11.2020.
//

#include "FullPoint.h"
#include <iostream>
#include <utility>

FullPoint::FullPoint(std::vector<FileInfo> currentFiles) : RestorePoint(std::move(currentFiles)) {
    this->setPointType("full");
}
