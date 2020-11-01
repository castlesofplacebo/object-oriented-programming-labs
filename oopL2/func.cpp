#include "Product.h"
#include "Dispatcher.h"
#include "Shop.h"
#include "AbstractProduct.h"

#include <iostream>
#include <utility>

using namespace std;

//создание продукта
AbstractProduct::AbstractProduct(string code, string name) {
    this->code = std::move(code);
    this->name = std::move(name);
}

string AbstractProduct::getCode() {
    return this->code;
}

string AbstractProduct::getName() {
    return this->name;
}

Product::Product(AbstractProduct &abstractProduct, unsigned int count, double price)
        : AbstractProduct(abstractProduct) {
    this->count = count;
    this->price = price;
}

unsigned int Product::getCount() {
    return this->count;
}

double Product::getPrice() {
    return this->price;
}

void Product::setPrice(double currentPrice) {
    this->price = currentPrice;
}

void Product::setCount(unsigned int currentCount) {
    this->count = currentCount;
}

//создание магазина
Shop::Shop(string code, string name, string address) {
    this->code = std::move(code);
    this->name = std::move(name);
    this->address = std::move(address);
}

string Shop::getCode() {
    return this->code;
}

string Shop::getName() {
    return this->name;
}

string Shop::getAddress() {
    return this->address;
}

//добавление продуктов в магазин
void Shop::addProductsInTheShop(AbstractProduct &product, unsigned int currentCount, double currentPrice) {
    if (currentPrice <= 0 || currentCount <= 0) {
        string str = "Product with this code has an impossible price or amount: " + product.getCode();
        throw invalid_argument(str);
    }

    bool doesExist = false;

    if (!productList.empty()) {
        for (auto &i :  productList) {
            //если подобный товар уже существует
            if (i.getCode() == product.getCode()) {
                doesExist = true;
                if (i.getName() != product.getName()) {
                    string str = "Product with this code already exists : " + i.getCode();
                    throw invalid_argument(str);
                } else { //добаление товара
                    if (i.getPrice() == currentPrice) { //если цена не изменилась
                        size_t prevCount = i.getCount();
                        i.setCount(prevCount + currentCount);
                    } else { //изменилась цена
                        size_t prevCount = i.getCount();
                        i.setCount(prevCount + currentCount);
                        i.setPrice(currentPrice);
                    }
                }
            }
        }
        if (!doesExist)
            productList.emplace_back(Product(product, currentCount, currentPrice));
    } else
        productList.emplace_back(Product(product, currentCount, currentPrice));
}

vector<Product> &Shop::getProducts() {
    return productList;
}

vector<pair<unsigned int, AbstractProduct>> Shop::forTheAmount(double amount) {
    vector<pair<unsigned int, AbstractProduct>> productsForTheAmount;

    if (amount < 0) {
        string str = "Invalid amount in this shop : " + this->getName();
        throw invalid_argument(str);
    }

    for (auto t :  productList) {
        int curCount = amount / t.getPrice();
        if (curCount != 0) {
            if (curCount < t.getCount())
                productsForTheAmount.emplace_back(curCount, t);
            else
                productsForTheAmount.emplace_back(t.getCount(), t);
        }
    }

    if (productsForTheAmount.empty()) {
        string str = "Can not buy products in this shop : " + this->getName();
        throw invalid_argument(str);
    }

    return productsForTheAmount;
}

double Shop::buyProducts(vector<pair<int, AbstractProduct>> &list) {
    double answer = 0;
    for (auto i : list) {
        bool findProduct = false;
        for (auto &t :  productList) {
            if (i.first < 0) {
                string str = "Invalid amount of product (should be positive number)";
                throw invalid_argument(str);
            }

            if (i.second.getCode() == t.getCode()) {
                if (i.first <= t.getCount()) {
                    answer += i.first * t.getPrice();
                    unsigned int res = t.getCount() - i.first;
                    t.setCount(res);
                    findProduct = true;
                    if (res == 0) {
                        for (unsigned int q = 0; q < productList.size(); ++q) {
                            if (productList[q].getCode() == t.getCode())
                                productList.erase(productList.begin() + q);
                        }
                        continue;
                    }
                } else {
                    string str = "Can not buy the list of products in this shop : " + this->getName();
                    throw invalid_argument(str);
                }
            }

        }
        if (!findProduct) {
            string str = "Can not find the product in the shop : " + i.second.getCode();
            throw invalid_argument(str);
        }
    }

    return answer;
}

void Shop::setPrice(AbstractProduct &product, double price) {
    bool doesProductExist = false;
    if (!productList.empty()) {
        for (auto &i : productList) {
            //если подобный товар уже существует
            if (i.getCode() == product.getCode()) {
                i.setPrice(price);
                doesProductExist = true;
            }
        }
        if (!doesProductExist) {
            string str = "Product with this code does not exist : " + product.getCode();
            throw invalid_argument(str);
        }
    } else
        throw invalid_argument("No products in shop");
}

Dispatcher::Dispatcher(string city)
        : cityName(std::move(city)) {}

string Dispatcher::getCityName() {
    return this->cityName;
}

void Dispatcher::addShop(Shop *currentShop) {
    if (!s.empty()) {
        for (auto &i : s) {
            if (i->getCode() == currentShop->getCode()) {
                string str = "Shop with this code already exists : " + i->getCode();
                throw invalid_argument(str);
            }
        }
    }
    s.emplace_back(currentShop);
}

Shop Dispatcher::theCheapestProduct(AbstractProduct &product) {
    double minPr = 10e8;
    string name, code, address;

    if (s.empty()) {
        string str = "No shops in the city : " + getCityName();
        throw invalid_argument(str);
    } else {
        for (auto i : s) {
            vector<Product> curProd = i->getProducts();
            for (auto t : curProd) {
                if (t.getCode() == product.getCode() && t.getName() == product.getName() && t.getPrice() < minPr) {
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

    return Shop(code, name, address);
}

Shop Dispatcher::theCheapestList(vector<pair<int, AbstractProduct>> &list) {
    double total = 10e8;
    double currentMin;
    string code, name, address;
    for (auto i : s) {
        vector<Product> curProd = i->getProducts();
        currentMin = 0;
        size_t checkCount = 0;
        for (auto t : list) {
            if (t.first < 0) {
                string str = "Invalid amount of product (should be positive number)";
                throw invalid_argument(str);
            }
            for (auto k : curProd) {
                if (t.second.getCode() == k.getCode()) {
                    if (k.getCount() >= t.first) {
                        currentMin += t.first * k.getPrice();
                        ++checkCount;
                    } else
                        continue;
                }
            }
        }

        if (checkCount != list.size())
            break;

        if (currentMin < total) {
            total = currentMin;
            code = i->getCode();
            name = i->getName();
            address = i->getAddress();
        }
    }

    if (code.empty())
        throw invalid_argument("Can not buy the list of products in the city");

    return Shop(code, name, address);
}