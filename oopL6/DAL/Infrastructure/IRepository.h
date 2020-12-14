//
// Created by castl on 13.12.2020.
//

#ifndef OOPL6_IREPOSITORY_H
#define OOPL6_IREPOSITORY_H

#include <map>
#include <iostream>

template<typename T>
class IRepository {
public:
    virtual T *getItem(unsigned int _id) = 0;

    virtual void create(T *item) = 0;

    //virtual void update(T *item) = 0;

    virtual std::map<unsigned int, T *> getAll() = 0;

    //virtual std::map<unsigned int, T *> find() = 0;
};

#endif //OOPL6_IREPOSITORY_H


//virtual IRepository<T>* Clone() const = 0;
//virtual void Delete() = 0;
//virtual bool IsEmpty() const = 0;
//virtual int GetCount() const = 0;
//virtual T& GetItem(int ind) = 0;
//virtual const T& GetItem(int ind) const = 0;
//IRepository<T>& operator=(const IRepository<T>&) = delete;