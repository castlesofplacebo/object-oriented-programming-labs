#ifndef OOPL2_PRODUCTFACTORY_H
#define OOPL2_PRODUCTFACTORY_H

#include <string>
#include "AbstractProduct.h"

using namespace std;

class ProductFactory {
public:
    AbstractProduct *getProduct(size_t count, double price);
};

#endif //OOPL2_PRODUCTFACTORY_H
