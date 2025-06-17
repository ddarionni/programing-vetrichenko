#pragma once
#include "entity.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>


class List {
private:
    Phone* arr_;
    size_t size_;
    size_t capacity_;
    void ensureCapacity(size_t minCap);

public:
    List();
    List(const List& other);
    ~List();

    List& operator=(const List& other);

    void addPhone(const Phone& phone, size_t pos = 0);
    void removePhone(size_t index);
    size_t getSize() const;

    // індексування
    Phone& operator[](size_t index);
    const Phone& operator[](size_t index) const;


    friend std::ostream& operator<<(std::ostream& os, const List& list);
    friend std::istream& operator>>(std::istream& is, List& list);

    // Для роботи з файлами
    friend std::ofstream& operator<<(std::ofstream& ofs, const List& list);
    friend std::ifstream& operator>>(std::ifstream& ifs, List& list);

    void clear();
};
