#ifndef OOPL2_SHOP_H
#define OOPL2_SHOP_H

#include <vector>
#include <string>
using namespace std;

class Shop {
private:
    string code;
    string name;
    string address;

    vector<Product> productList;
public:
    Shop(string code, string name, string address);

    string getCode();

    string getName();

    string getAddress();

    vector<Product>& getProducts();

    void addProductsInTheShop(AbstractProduct& abstractProduct, unsigned int count, double price);

    void setPrice(AbstractProduct& abstractProduct, double price);

    vector<pair<unsigned int, AbstractProduct>> forTheAmount(double amount);

    double buyProducts(vector<pair<int, AbstractProduct>>& list);
};

#endif //OOPL2_SHOP_H
