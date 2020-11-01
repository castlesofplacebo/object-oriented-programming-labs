#ifndef OOPL2_PRODUCT_H
#define OOPL2_PRODUCT_H

#include <iostream>
#include "AbstractProduct.h"

class Product : public AbstractProduct {
private:
    unsigned int count;
    double price;
public:
    Product (AbstractProduct& abstractProduct, unsigned int count, double price);

    unsigned int getCount();

    double getPrice();

    void setPrice(double currentPrice);

    void setCount(unsigned int count);
};

#endif //OOPL2_PRODUCT_H
