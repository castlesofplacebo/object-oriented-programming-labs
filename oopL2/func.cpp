#include "Product.h"
#include "ProductFactory.h"
#include "Dispatcher.h"
#include "Shop.h"

#include <iostream>

using namespace std;

//создание продукта
Product::Product(string& code, string& name) {
    this->code = code;
    this->name = name;
}

string &Product::getCode() {
    return this->code;
}

string &Product::getName() {
    return this->name;
}

Product::Product (Product& prod, size_t c, double pr)
: Product(prod)
{
    count = c;
    price = pr;
}

size_t Product::getCount() {
    return this->count;
}

double Product::getPrice() {
    return this->price;
}

void Product::setPrice(double pr) {
    this->price = pr;
}

void Product::setCount(size_t c) {
    this->count = c;
}

//создание магазина
Shop::Shop(string c, string n, string a) {
    code = c;
    name = n;
    address = a;
}

//добавление продуктов в магазин
void Shop::addProductsInTheShop(Product& currentProd, size_t currentCount, double currentPrice) {
    if (currentPrice <= 0) {
        string str = "Product with this code has an impossible price : " + currentProd.getCode();
        throw invalid_argument(str);
    }
    if (!p.empty()) {
        for (auto & i : p) {
            //если подобный товар уже существует
            if (i.getCode() == currentProd.getCode()) {
                if (i.getName() != currentProd.getName()) {
                    string str = "Product with this code already exists : " + i.getCode();
                    throw invalid_argument(str);
                }
                else { //добаление товара
                    if (i.getPrice() == currentPrice) { //если цена не изменилась
                        size_t prevCount = i.getCount();
                        i.setCount(prevCount + currentCount);
                    }
                    else { //изменилась цена
                        size_t prevCount = i.getCount();
                        i.setCount(prevCount + currentCount);
                        i.setPrice(currentPrice);
                    }
                }
            }
        }
    }
    p.emplace_back(Product(currentProd, currentCount, currentPrice));
}

string &Shop::getCode() {
    return this->code;
}

string &Shop::getName() {
    return this->name;
}

string &Shop::getAddress() {
    return this->address;
}

vector<Product> &Shop::getProducts() {
    return p;
}

Shop::Shop() = default;

vector<pair<size_t, Product>> Shop::forTheAmount(double amount) {
    vector<pair<size_t, Product>> productsForTheAmount;

    for (auto t : p) {
        int curCount = amount / t.getPrice();
        if (curCount != 0)
            productsForTheAmount.emplace_back(curCount, t);
    }

    if (productsForTheAmount.empty()) {
        string str = "Can not buy products in this shop : " + this->getName();
        throw invalid_argument(str);
    }

    return productsForTheAmount;
}

double Shop::buyProducts(vector<pair<size_t, Product>>& list) {
    double answer = 0;
    for (auto i : list) {
        for (auto t : p) {
            if (i.second.getCode() == t.getCode()) {
                if (i.first <= t.getCount())
                    answer += i.first * t.getPrice();
                else {
                    string str = "Can not buy the list of products in this shop : " + this->getName();
                    throw invalid_argument(str);
                }
            }
        }
    }
    return answer;
}

City::City(string & cur)
: cityName(cur)
{}

string &City::getCityName() {
    return this->cityName;
}

void City::addShop(Shop * sh) {
    if (!s.empty()) {
        for (auto &i : s) {
            if (i->getCode() == sh->getCode()) {
                string str = "Shop with this code already exists : " + i->getCode();
                throw invalid_argument(str);
            }
        }
    }
    s.emplace_back(sh);
}

Shop City::theCheapestProduct(Product & pr) {
    double minPr = 10e8;
    string name, code, address;

    if (s.empty()) {
        string str = "No shops in the city : " + getCityName();
        throw invalid_argument(str);
    }

    else {
        for (auto i : s) {
            vector <Product> curProd = i->getProducts();
            for (auto t : curProd) {
                if (t.getCode() == pr.getCode() && t.getName() == pr.getName() && t.getPrice() < minPr) {
                    minPr = t.getPrice();
                    name = i->getName();
                    code = i->getCode();
                    address = i->getAddress();
                }
            }
        }
    }

    if (name.empty()) {
        string str = "No product in the city : " + getCityName();
        throw invalid_argument(str);
    }

    return Shop(name, code, address);
}

Shop City::theCheapestList(vector<pair<size_t, Product>> & list) {
    double total = 10e8;
    double currentmin;
    string code, name, address;
    for (auto i : s) {
        vector <Product> curProd = i->getProducts();
        currentmin = 0;
        for (auto t : list) {
            for (auto k : curProd) {
                if (t.second.getCode() == k.getCode()) {
                    if (k.getCount() >= t.first) {
                        currentmin += t.first * k.getPrice();
                    }
                    else
                        continue;
                }
            }
        }

        if (currentmin < total) {
            total = currentmin;
            code = i->getCode();
            name = i->getName();
            address = i->getAddress();
        }
    }

    if (code.empty())
        throw invalid_argument("Can not buy the list of products in the city");

    return Shop(code, name, address);
}