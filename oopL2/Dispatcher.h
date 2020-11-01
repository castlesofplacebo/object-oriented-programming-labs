#ifndef OOPL2_DISPATCHER_H
#define OOPL2_DISPATCHER_H

#include <vector>
#include <string>
#include "Shop.h"

class Dispatcher {
private:
    string cityName;

    vector<Shop *> s;
public:
    explicit Dispatcher(string city);

    string getCityName();

    void addShop(Shop* shop);

    Shop theCheapestProduct(AbstractProduct& shop);

    Shop theCheapestList(vector<pair<int, AbstractProduct>>& product);
};

#endif //OOPL2_DISPATCHER_H
