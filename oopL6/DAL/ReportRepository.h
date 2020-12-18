//
// Created by castl on 13.12.2020.
//

#ifndef OOPL6_REPORTREPOSITORY_H
#define OOPL6_REPORTREPOSITORY_H

#include "Infrastructure/IRepository.h"
#include "Entities/Report.h"

class ReportRepository : public IRepository<Report> {
private:
    std::map<unsigned int, Report *> _reports{};
public:
    ReportRepository();

    ~ReportRepository();

    void create(Report *item) override;

    Report *getItem(unsigned int _id) override;

    //void update(Report *item) override;

    std::map<unsigned int, Report *> getAll() override;

    //std::map<unsigned int, Report *> find() override;

};

#endif //OOPL6_REPORTREPOSITORY_H
