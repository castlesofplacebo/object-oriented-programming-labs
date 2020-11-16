#include <iostream>
#include <vector>
#include "Backup.h"

int main() {
    try {
        std::vector<std::string> files;
        //files.emplace_back("test1.txt");
        files.emplace_back("test2.txt");
        //files.emplace_back("test3");
        //files.emplace_back("none");
        Backup b(files);
        //b.getCurrentFiles();
        b.addRestorePoint(FULL);
    }
    catch (std::exception &err) {
        std::cout << err.what() << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}