#include <iostream>
#include "AbstractProduct.h"
#include "Product.h"
#include "Shop.h"
#include "Dispatcher.h"

using namespace std;

int main() {
    try {
        AbstractProduct product1("1", "apple");
        AbstractProduct product2("2", "apple");
        AbstractProduct product3("3", "apple");
        AbstractProduct product4("4", "apple");
        AbstractProduct product5("5", "apple");

        AbstractProduct product6("6", "apple");
        AbstractProduct product7("7", "apple");
        AbstractProduct product8("8", "apple");
        AbstractProduct product9("9", "apple");
        AbstractProduct product10("10", "apple");

        //tests for 3-rd statement -> passed
        Shop shop1("01", "7-eleven", "Alpiysky per");
        shop1.addProductsInTheShop(product1, 2, 450.0);
        shop1.addProductsInTheShop(product2, 3, 200.0);
        shop1.addProductsInTheShop(product2, 3, 100.0);
        shop1.addProductsInTheShop(product9, 1, 1200.91);
        //shop1.setPrice(product1, 30.1);

        Shop shop2("02", "Metro", "Belorusskaya st");
        shop2.addProductsInTheShop(product1, 7, 70.1);
        shop2.addProductsInTheShop(product2, 9, 10.0);
        shop2.addProductsInTheShop(product5, 4, 30.9);

        Shop shop3("03", "Ashan", "Vyazemsky per");
        shop3.addProductsInTheShop(product1, 1, 50.1);
        shop3.addProductsInTheShop(product3, 2, 230.0);
        shop3.addProductsInTheShop(product9, 78, 1200.9);

        Dispatcher city("saint-product_list");
        city.addShop(&shop1);
        city.addShop(&shop2);
        city.addShop(&shop3);

        //test for 4-th statement -> passed
        /*
        Shop result = city.theCheapestProduct(product4);
        cout << "Shop code, name and address : " <<  result.getCode() << " " << result.getName() << " " << result.getAddress() << endl;
        */

        //test for 5-th statement -> passed
        /*vector<pair<size_t, AbstractProduct>> currentList = shop1.forTheAmount(100005000.0);
        for (auto i : currentList) {
            cout << "Count : " << i.first << "; Product code and name : " << i.second.getCode() << " " << i.second.getName() << endl;
        }*/

        //test for 6-th statement -> passed
        /*vector<pair<int, AbstractProduct>> currentList;
        currentList.emplace_back(make_pair(2, product1));
        currentList.emplace_back(make_pair(4, product2));
        cout << shop1.buyProducts(currentList) << endl;*/

        //test for 7-th statement -> passed
        /*
        vector<pair<int, AbstractProduct>> currentList;
        currentList.emplace_back(make_pair(2, product1));
        currentList.emplace_back(make_pair(3, product2));
        Shop result = city.theCheapestList(currentList);
        cout << "Shop code, name and address : " <<  result.getCode() << " " << result.getName() << " " << result.getAddress() << endl;
        */

        //to see what shop contains
        /*vector<Product> curr = shop1.getProducts();
        for (auto i : curr)
            cout << i.getCode() << " " << i.getCount() << endl;*/

    }
    catch (exception &err) {
        cout << err.what() << endl;
        return EXIT_FAILURE;
    }

    return 0;
}