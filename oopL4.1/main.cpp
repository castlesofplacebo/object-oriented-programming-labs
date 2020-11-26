#include <iostream>
#include <vector>
#include <string>
#include "Backup.h"
#include "BackupJob.h"
#include "AlgoSeparated.h"
#include "AlgoGeneral.h"
#include "CleanupByQuantity.h"
#include "CleanupHybrid.h"
#include "CleanupByDate.h"
#include "CleanupBySize.h"

int main() {
    try {
        std::vector<std::string> files;
        //files.emplace_back("test1.txt");
        //files.emplace_back("test2.txt");
        files.emplace_back("test3");
        //files.emplace_back("none");
        Backup b(files);

        //b.addObjects("test1.txt");

        AlgoGeneral s;

        BackupJob bj(&b, &s);

        b.addRestorePoint(bj.createFullPoint());
        //sleep(5);
        b.addRestorePoint(bj.createIncPoint());
        CleanupByQuantity q(1);

        //CleanupByDate c(26, 11, 2020);
        //bj.applyCleanupAlgorithm(&c);

        CleanupBySize bySize(37016);

        //bj.applyCleanupAlgorithm(&bySize);

        //CleanupHybrid ch(&q, &bySize, "max");
        std::cout<<bj.applyCleanupAlgorithm(&q)<<std::endl;

        std::cout << bj.getInfo() << std::endl;

        //b.showRestorePoints();
    }
    catch (std::exception &err) {
        std::cout << err.what() << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}