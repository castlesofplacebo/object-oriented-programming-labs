#include <vector>
#include <string>

#ifndef OOPL2_SHOP_H
#define OOPL2_SHOP_H

using namespace std;

class Shop {
private:
    string code;
    string name;
    string address;

    vector<Product> p;
public:
    Shop();

    Shop(string name, string code, string address);

    string &getCode();

    string &getName();

    string &getAddress();

    vector<Product> &getProducts();

    void addProductsInTheShop(ProductFactory &, size_t, double);

    vector<pair<size_t, ProductFactory>> forTheAmount(double);

    double buyProducts(vector<pair<size_t, ProductFactory>> &);
};

#endif //OOPL2_SHOP_H
