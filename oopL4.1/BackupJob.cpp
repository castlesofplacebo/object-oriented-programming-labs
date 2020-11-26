//
// Created by castl on 18.11.2020.
//

#include "BackupJob.h"

BackupJob::BackupJob(Backup *backup1, StorageAlgorithms *algorithm1) {
    this->backup = backup1;
    this->algorithm = algorithm1;
}

FullPoint BackupJob::createFullPoint() {
    this->incId();
    FullPoint fullPoint(this->backup->getCurrentFiles());

    this->info += this->algorithm->setInfo(fullPoint.getRestoreFiles(), this->getId());
    return fullPoint;
}

IncPoint BackupJob::createIncPoint() {
    this->incId();
    std::vector<RestorePoint> prevRestorePoints(this->backup->getRestorePoints());
    IncPoint incPoint(this->backup->getCurrentFiles(), prevRestorePoints);

    this->info += this->algorithm->setInfo(incPoint.getRestoreFiles(), this->getId());
    return incPoint;
}

std::string BackupJob::getInfo() {
    return this->info;
}

std::string BackupJob::applyCleanupAlgorithm(CleanupAlgorithms *cleanupAlgorithm1) {
    std::vector<unsigned int> numbersToDelete(cleanupAlgorithm1->deleteRestorePoint(backup));
    std::string warning = "--";

    if (!numbersToDelete.empty())
        for (auto i : numbersToDelete) {
            if (i != backup->getRestorePoints().size() && backup->getRestorePoints()[i + 1].getPointType() == "inc") {
                warning += "This point does not delete " + std::to_string(i + 1);
                continue;
            }
            backup->deleteRestorePoint(i);
            this->addInfo("Deleted point: restore-point-" + std::to_string(i + 1) + '\n');
        }
    warning += "--";
    return warning;
}

void BackupJob::incId() {
    ++this->id;
}

unsigned int BackupJob::getId() {
    return this->id;
}

void BackupJob::addInfo(const std::string &newInfo) {
    this->info += newInfo;
}