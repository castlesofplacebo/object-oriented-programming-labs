#ifndef OOPL2_ABSTRACTPRODUCT_H
#define OOPL2_ABSTRACTPRODUCT_H

#include <string>

using namespace std;

class AbstractProduct {
private:
    string code;
    string name;
public:
    AbstractProduct(string code, string name);

    string getCode();

    string getName();

};

#endif //OOPL2_ABSTRACTPRODUCT_H
