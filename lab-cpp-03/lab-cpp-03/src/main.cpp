#include "list.h"
#include <iostream>
#include <string>
#include <limits>
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;

void inputPhone(List& phones) {
    cout << "Введіть дані телефону (model;diagonal;price): ";
    Phone p;
    cin.ignore();
    cin >> p;
    phones.addPhone(p, phones.getSize());
}

int main() {
    List phones;
    bool running = true;
    while (running) {
        cout << "\n1. Додати телефон\n2. Видалити телефон\n3. Вивести всі\n4. Зчитати з файлу\n5. Записати у файл\n0. Вихід\n>> ";
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
            cout << phones;
        } else if (choice == 4) {
            cout << "Введіть ім'я файлу: ";
            string fname;
            getline(cin, fname);
            ifstream fin(fname);
            if (fin) {
                fin >> phones;
                cout << "OK\n";
            } else {
                cout << "Помилка відкриття файлу\n";
            }
        } else if (choice == 5) {
            cout << "Введіть ім'я файлу: ";
            string fname;
            getline(cin, fname);
            ofstream fout(fname);
            if (fout) {
                fout << phones;
                cout << "OK\n";
            } else {
                cout << "Помилка відкриття файлу\n";
            }
        } else if (choice == 0) {
            running = false;
        }
    }
    return 0;
}
