#include "list.h"
#include <iostream>

int main() {
   
    Phone p1("Samsung Galaxy S21", 6.5, 800);
    Phone p2;
    Phone p3 = p1; //copy telefonchik1

    p2.setModel("iPhone 12");
    p2.setDiagonal(6.1f);
    p2.setPrice(650);

    List phones;
    phones.addPhone(p1);
    phones.addPhone(p2);
    phones.addPhone(Phone("Nokia 3310", 2.4, 50), 1);
    std::cout << "All phones:\n";
    phones.print();

    std::cout << "Cheapest with 6.5 diagonal:\n";
    try {
        phones.findCheapestPhone(6.5f).print();
    } catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }

    phones.removePhone(1);
    std::cout << "After removing index 1:\n";
    phones.print();

    return 0;
}
