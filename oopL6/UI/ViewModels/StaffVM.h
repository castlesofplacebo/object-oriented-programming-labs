//
// Created by castl on 14.12.2020.
//

#ifndef OOPL6_STAFFVM_H
#define OOPL6_STAFFVM_H
#include <iostream>

class StaffVM {
protected:
    unsigned int id = 0;
    std::string name{};
public:
    explicit StaffVM(std::string _name);

    std::string getName();

    void setId(unsigned int _id);

    unsigned int getId() const;

};


#endif //OOPL6_STAFFVM_H
