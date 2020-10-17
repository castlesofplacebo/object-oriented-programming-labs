#ifndef OOPL2_DISPATCHER_H
#define OOPL2_DISPATCHER_H

#include <vector>
#include <string>
#include "Shop.h"

class Dispatcher {
private:
    string &cityName;

    vector<Shop *> s;
public:
    explicit Dispatcher(string &);

    string &getCityName();

    void addShop(Shop *);

    Shop theCheapestProduct(ProductFactory &);

    Shop theCheapestList(vector <pair<size_t, ProductFactory>> &);
};

#endif //OOPL2_DISPATCHER_H
