#include "list.h"
#include "entity.h"
#include <iostream>
#include <string>
#include <limits>

using std::cout;
using std::cin;
using std::string;

void inputDevice(List& devices) {
    cout << "1. Phone\n2. Tablet\nВиберіть тип пристрою: ";
    int type = 1;
    cin >> type;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (type == 1) {
        cout << "Введіть дані телефону (model;diagonal;price): ";
        Phone* p = new Phone();
        cin >> *p;
        devices.add(p);
    } else if (type == 2) {
        cout << "Введіть дані планшету (model;diagonal;price;pen[0/1]): ";
        Tablet* t = new Tablet();
        cin >> *t;
        devices.add(t);
    }
}

int main() {
    List devices;
    bool running = true;
    while (running) {
        cout << "\n1. Додати пристрій\n2. Видалити пристрій\n3. Вивести всі\n4. Зчитати з файлу\n5. Записати у файл\n0. Вихід\n>> ";
        int choice = 0;
        cin >> choice;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice == 1) {
            inputDevice(devices);
        } else if (choice == 2) {
            cout << "Введіть індекс: ";
            size_t idx;
            cin >> idx;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            devices.remove(idx);
        } else if (choice == 3) {
            cout << devices;
        } else if (choice == 4) {
            cout << "Введіть ім'я файлу: ";
            string fname;
            getline(cin, fname);
            std::ifstream fin(fname);
            if (fin) {
                fin >> devices;
                cout << "OK\n";
            } else {
                cout << "Помилка відкриття файлу\n";
            }
        } else if (choice == 5) {
            cout << "Введіть ім'я файлу: ";
            string fname;
            getline(cin, fname);
            std::ofstream fout(fname);
            if (fout) {
                fout << devices;
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
