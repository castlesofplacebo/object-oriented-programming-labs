#include <iostream>
#include "ProductFactory.h"
#include "AbstractProduct.h"
#include "Product.h"
#include "Shop.h"

using namespace std;

int main() {
    try {


        ProductFactory fact1;

        AbstractProduct pr1("product_code1", "product_name1");

        cout << "hello git!!!!";


        Shop shop1("code1", "name1", "address1");



        shop1.setPrice("code"); // TODO setPrice, naming, create headers for all classes

    }
    catch (exception &err) {
        cout << err.what() << endl;
        return EXIT_FAILURE;
    }

    return 0;
}