cmake_minimum_required(VERSION 3.15)
project(oopL4_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(oopL4_1 main.cpp Backup.h Backup.cpp FileInfo.cpp FileInfo.h RestorePoint.cpp RestorePoint.h FullPoint.cpp FullPoint.h IncPoint.cpp IncPoint.h AlgoGeneral.cpp AlgoGeneral.h AlgoSeparated.cpp AlgoSeparated.h StorageAlgorithms.cpp StorageAlgorithms.h BackupJob.cpp BackupJob.h CleanupAlgorithms.cpp CleanupAlgorithms.h CleanupByQuantity.cpp CleanupByQuantity.h CleanupByDate.cpp CleanupByDate.h CleanupBySize.cpp CleanupBySize.h CleanupHybrid.cpp CleanupHybrid.h)