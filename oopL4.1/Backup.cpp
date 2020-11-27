//
// Created by castl on 15.11.2020.
//
#include "Backup.h"
#include <fstream>
#include <sys/stat.h>
#include <dirent.h>
#include <algorithm>
#include "FullPoint.h"
#include "IncPoint.h"
#include <sys/stat.h>
#include <filesystem>

Backup::Backup() : creationTime(time(nullptr)),
                   backupID(time(nullptr)) {}

Backup::Backup(const std::vector<std::string> &files) : Backup() {
    for (const auto &file : files) {
        addObjects(file);
    }
}

char *Backup::getCreationTime() {
    return ctime(&creationTime);
}

int Backup::getBackupSize() {
    return this->backupSize;
}

void Backup::addObjects(const std::string &file) {
    for (auto &currentFile : currentFiles) {
        if (currentFile.getFileName() == file)
            throw std::invalid_argument("File already exists");
    }

    struct stat buffer{};

    if (stat(file.c_str(), &buffer) == 0) { //if file or directory exists
        std::ifstream fileOrDir(file);
        fileOrDir.seekg(0, std::ios::end);


        if (buffer.st_mode & (unsigned int) S_IFREG) {
            FileInfo tmp(file);
            this->currentFiles.emplace_back(tmp);
        } else if (buffer.st_mode & (unsigned int) S_IFDIR) {
            std::filesystem::path p(file);
            /* struct dirent *entry;
             DIR *dir = opendir(path);
             if (dir == nullptr) {
                 return;
             }

             while ((entry = readdir(dir)) != nullptr) {
                 std::string w(entry->d_name);
                 FileInfo tmp(w);
                 tmp.setDirName(file);
                 this->currentFiles.emplace_back(tmp);
             } */
            for (const auto & entry : std::filesystem::directory_iterator(p)){
                FileInfo tmp(entry.path().string()); // Возможно стоит отсечь полный путь к файлу, а мб и нет)
                tmp.setDirName(file);
                this->currentFiles.emplace_back(tmp);
            }

                //checking
                /*for (auto &item : direct) { //очень круто но размер файла все равно минус один
                    std::cout << item.getFileName() << " " << item.getFileSize() << std::endl;
                }*/

              //  closedir(dir);
        }


    } else
        throw std::invalid_argument("Invalid file or directory name");
}

std::string currentFileName{};

bool IsMarkedToDelete(FileInfo &o) {
    return o.getDirName() == currentFileName || o.getFileName() == currentFileName;
}

void Backup::deleteObjects(const std::string &file) {
    currentFileName = file;

    for (auto i : currentFiles)
        if (i.getFileName() == file || i.getDirName() == file)
            this->backupSize = this->backupSize - i.getFileSize();

    currentFiles.erase(
            std::remove_if(currentFiles.begin(), currentFiles.end(), IsMarkedToDelete),
            currentFiles.end());
}

std::vector<FileInfo> Backup::getCurrentFiles() {
    return this->currentFiles;
}

void Backup::addRestorePoint(RestorePoint point) {
    this->backupRestorePoints.emplace_back(point);

    for (auto i : point.getRestoreFiles())
        this->backupSize += i.getFileSize();
}

void Backup::showRestorePoints() {
    for (auto i : backupRestorePoints) {
        for (auto j : i.getRestoreFiles())
            std::cout << j.getDirName() << " " << j.getFileName() << std::endl;
        std::cout << i.getCreationTime() << std::endl;
    }
}

std::vector<RestorePoint> Backup::getRestorePoints() {
    return this->backupRestorePoints;
}

void Backup::deleteRestorePoint(unsigned int it) {
    for (auto i : this->backupRestorePoints[it].getRestoreFiles())
        this->backupSize = this->backupSize - i.getFileSize();

    this->backupRestorePoints.erase(this->backupRestorePoints.begin() + it);
}