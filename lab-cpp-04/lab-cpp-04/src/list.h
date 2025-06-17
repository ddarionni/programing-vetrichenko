#pragma once
#include "entity.h"
#include <vector>
#include <iostream>
#include <fstream>

class List final {
private:
    std::vector<Device*> arr_;
public:
    List();
    List(const List& other);
    ~List();

    List& operator=(const List& other);

    void add(Device* dev);
    void remove(size_t idx);
    Device& operator[](size_t idx);
    const Device& operator[](size_t idx) const;
    size_t size() const;

    void clear();

    friend std::ostream& operator<<(std::ostream& os, const List& list);
    friend std::istream& operator>>(std::istream& is, List& list);

    friend std::ofstream& operator<<(std::ofstream& ofs, const List& list);
    friend std::ifstream& operator>>(std::ifstream& ifs, List& list);
};
