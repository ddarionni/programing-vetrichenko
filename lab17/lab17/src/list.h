#pragma once
#include "entity.h"
#include <cstddef>


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

    void addPhone(const Phone& phone, size_t pos = 0);
    void removePhone(size_t index);
    Phone& getPhone(size_t index);
    const Phone& getPhone(size_t index) const;
    size_t getSize() const;

    void print() const;

    const Phone& findCheapestPhone(float diagonal) const;
};
