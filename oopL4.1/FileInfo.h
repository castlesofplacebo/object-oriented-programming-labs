//
// Created by castl on 15.11.2020.
//

#ifndef OOPL4_1_FILEINFO_H
#define OOPL4_1_FILEINFO_H

#include <iostream>

class FileInfo {
private:
    std::string dirName{};
    std::string fileName{};
    int fileSize = 0;
public:
    explicit FileInfo(std::string currentFile);

    int getFileSize();

    std::string getFileName();

    void setDirName(std::string currentDir);

    std::string getDirName();
};

#endif //OOPL4_1_FILEINFO_H
