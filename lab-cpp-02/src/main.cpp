#include "list.h"
#include <iostream>
#include <string>
#include <limits>

using std::cout;
using std::cin;
using std::string;

void inputPhone(List& phones) {
    string line;
    cout << "введіть данні телефона (model;diagonal;price): ";
    getline(cin, line);
    Phone p = Phone::fromString(line);
    phones.addPhone(p, phones.getSize());
}

int main() {
    List phones;
    bool running = true;
    while (running) {
        cout << "\n1. Add phone\n2. Remove phone\n3. Print all\n4. Find cheapest by diagonal\n5. Read from file\n6. Write to file\n0. Exit\n>> ";
        int choice;
        cin >> choice;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice == 1) {
            inputPhone(phones);
        } else if (choice == 2) {
            cout << "Введіть індекс: ";
            size_t idx;
            cin >> idx;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            phones.removePhone(idx);
        } else if (choice == 3) {
            phones.print();
        } else if (choice == 4) {
            cout << "Введиить діагональ: ";
            float d;
            cin >> d;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            try {
                cout << phones.findCheapestPhone(d).toString() << "\n";
            } catch (std::exception& e) {
                cout << e.what() << "\n";
            }
        } else if (choice == 5) {
            cout << "Введіть імʼя файла: ";
            string fname;
            getline(cin, fname);
            try {
                phones.readFromFile(fname);
                cout << "OK\n";
            } catch (std::exception& e) {
                cout << e.what() << "\n";
            }
        } else if (choice == 6) {
            cout << "Введіть імʼя файла: ";
            string fname;
            getline(cin, fname);
            try {
                phones.writeToFile(fname);
                cout << "OK\n";
            } catch (std::exception& e) {
                cout << e.what() << "\n";
            }
        } else if (choice == 0) {
            running = false;
        }
    }
    return 0;
}
