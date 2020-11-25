//
// Created by castl on 25.11.2020.
//

#include "CleanupByDate.h"

std::vector<unsigned int> CleanupByDate::deleteRestorePoint(Backup *backup) {
    std::vector<unsigned int> deletedNumbers;

    int it = 0;
    int i = 0;
    int size = backup->getRestorePoints().size();

    while (it != size) {
        if (this->currentDate < backup->getRestorePoints()[it].getCreationTime()) {
            deletedNumbers.push_back(i);
            ++i;
            --size;
            //backup->deleteRestorePoint(it);
        } else
            ++it;
    }

    return deletedNumbers;
}

CleanupByDate::CleanupByDate(int date, int month, int year) {
    struct tm t{};
    time_t t_of_day; //date in UNIX-format

    t.tm_year = year - 1900;  // Year - 1900
    t.tm_mon = month - 1;           // Month, where 0 = jan
    t.tm_mday = date;          // Day of the month
    t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 0;
    t.tm_isdst = -1;        // Is DST on? 1 = yes, 0 = no, -1 = unknown
    t_of_day = mktime(&t);

    this->currentDate = t_of_day;
};
