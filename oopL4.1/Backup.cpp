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
        for (auto &j : currentFile) {
            if (j.getFileName() == file)
                throw std::invalid_argument("File already exists");
        }
    }

    struct stat buffer{};

    if (stat(file.c_str(), &buffer) == 0) { //if file or directory exists
        std::ifstream fileOrDir(file);
        fileOrDir.seekg(0, std::ios::end);

        if (fileOrDir.good())  //if it's a file
            this->currentFiles.push_back({FileInfo(file)});

        else { //if it's directory
            const char *path = file.c_str();
            struct dirent *entry;
            DIR *dir = opendir(path);
            if (dir == nullptr) {
                return;
            }

            std::vector<FileInfo> direct;
            while ((entry = readdir(dir)) != nullptr) {
                std::string w(entry->d_name);
                FileInfo tmp(w);
                tmp.setDirName(file);
                direct.emplace_back(tmp);
            }

            //checking
            /*for (auto &item : direct) { //очень круто но размер файла все равно минус один
                std::cout << item.getFileName() << " " << item.getFileSize() << std::endl;
            }*/

            this->currentFiles.push_back({direct});

            closedir(dir);
        }
    } else
        throw std::invalid_argument("Invalid file or directory name");
}

void Backup::deleteObjects(const std::string &file) {
    bool isFind = false;
    for (int i = 0; i < currentFiles.size(); ++i) {
        for (int j = 0; j < currentFiles[i].size(); ++j) {
            if (currentFiles[i][j].getDirName() == file) {
                isFind = true;
                this->currentFiles.erase(currentFiles.begin() + i);
                break;
            }

            if (currentFiles[i][j].getFileName() == file) {
                isFind = true;
                this->currentFiles[i].erase(currentFiles[i].begin() + j);
            }
        }
    }

    if (!isFind)
        throw std::invalid_argument("Can not delete file (does not exist)");
}

void Backup::getCurrentFiles() {
    //checking 2.0
    for (const auto &i : currentFiles) {
        for (auto j : i) {
            std::cout << j.getDirName() << " " << j.getFileName() << " " << j.getFileSize() << std::endl;
        }
    }
}

void Backup::addRestorePoint(typePoint point) {
    switch (point) {
        case FULL: {
            FullPoint();
            break;
        }
        case INC: {
            IncPoint();
            break;
        }
        default:
            break;
    }
}
