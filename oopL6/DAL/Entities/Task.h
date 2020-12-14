//
// Created by castl on 13.12.2020.
//

#ifndef OOPL6_TASK_H
#define OOPL6_TASK_H

#include "Staff.h"
#include "../Infrastructure/IEntity.h"
#include <iostream>
#include <vector>

enum States {
    Open,
    Active,
    Resolved
};

struct date {
    int day;
    int month;
    int year;
};

class Task : public IEntity {
private:
    unsigned int id = 0;
    std::string name{};
    std::string description{};
    unsigned int staff = 0;
    States state{};
    std::string staffComments{};
    std::vector<std::pair<date, std::string>> changes{};
public:
    Task(std::string _name, std::string _description);

    Task(std::string _name, std::string _description, date _date);

    std::string getName();

    std::string getDescription();

    void changeState(States _state, date _date);

    void setId(unsigned int _id) override;

    void addStaffComments(const std::string &_comment, date _date);

    std::string getComment();

    void setStaff(unsigned int _id, date _date);

    std::vector<std::pair<date, std::string>> getChanges();

    unsigned int getStaffId() const;

    unsigned int getId() override;
};

#endif //OOPL6_TASK_H
