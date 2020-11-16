#include "FileInfo.h"
#include <fstream>
#include <utility>
#include <vector>

FileInfo::FileInfo(std::string currentFile) {
    std::ifstream tempFile(currentFile, std::ios::binary);
    tempFile.seekg(0, std::ios::end);
    int size = tempFile.tellg();
    if (size < 0) {//это все еще некрутое избавление от минус единицы
        if (currentFile == "." || currentFile == "..")
            this->fileSize = 0;
        else
            this->fileSize = rand();
    }
    else this->fileSize = tempFile.tellg();
    this->fileName = std::move(currentFile);
}

int FileInfo::getFileSize() {
    return this->fileSize;
}

std::string FileInfo::getFileName() {
    return this->fileName;
}

void FileInfo::setDirName(std::string currentDir) {
    this->dirName = std::move(currentDir);
}

std::string FileInfo::getDirName() {
    return this->dirName;
}
