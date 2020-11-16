cmake_minimum_required(VERSION 3.15)
project(oopL4_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(oopL4_1 main.cpp Backup.h Backup.cpp FileInfo.cpp FileInfo.h RestorePoint.cpp RestorePoint.h FullPoint.cpp FullPoint.h IncPoint.cpp IncPoint.h)