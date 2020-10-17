#ifndef OOPL2_PRODUCT_H
#define OOPL2_PRODUCT_H

#include <cstddef>
#include "ProductFactory.h"


class Product : AbstractProduct {
private:
    size_t count;
    double price;
public:
    size_t getCount();

    double getPrice();

    void setPrice(double);

    void setCount(size_t);


};

#endif //OOPL2_PRODUCT_H
