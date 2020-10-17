#ifndef OOPL2_ABSTRACTPRODUCT_H
#define OOPL2_ABSTRACTPRODUCT_H

#include <string>
#include "Product.h"

using namespace std;

class AbstractProduct {
private:
    string name;
    string code;
public:
    //virtual ~AbstractProduct() = 0;

    AbstractProduct(string name, string code);


    string get_name() {
        return name;
    }

    string get_code() {
        return code;
    }

};

#endif //OOPL2_ABSTRACTPRODUCT_H
