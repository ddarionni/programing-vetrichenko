#include "list.h"
#include <fstream>
#include <iostream>
#include <sstream>

using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::getline;

void List::ensureCapacity(size_t minCap) {
    if (capacity_ >= minCap) return;
    size_t newCap = capacity_ ? capacity_ * 2 : 4;
    if (newCap < minCap) newCap = minCap;
    Phone* newArr = new Phone[newCap];
    for (size_t i = 0; i < size_; ++i) newArr[i] = arr_[i];
    delete[] arr_;
    arr_ = newArr;
    capacity_ = newCap;
}

List::List() : arr_(nullptr), size_(0), capacity_(0) {
    cout << "[LOG] List: Default constructor\n";
}

List::List(const List& other)
    : arr_(nullptr), size_(other.size_), capacity_(other.capacity_) {
    cout << "[LOG] List: Copy constructor\n";
    if (capacity_) {
        arr_ = new Phone[capacity_];
        for (size_t i = 0; i < size_; ++i) arr_[i] = other.arr_[i];
    }
}

List::~List() {
    cout << "[LOG] List: Destructor\n";
    delete[] arr_;
}

void List::addPhone(const Phone& phone, size_t pos) {
    if (pos > size_) pos = size_;
    ensureCapacity(size_ + 1);
    for (size_t i = size_; i > pos; --i) arr_[i] = arr_[i - 1];
    arr_[pos] = phone;
    ++size_;
}

void List::removePhone(size_t index) {
    if (index >= size_) return;
    for (size_t i = index; i + 1 < size_; ++i) arr_[i] = arr_[i + 1];
    --size_;
}

Phone& List::getPhone(size_t index) {
    if (index >= size_) throw std::out_of_range("Index out of range");
    return arr_[index];
}

const Phone& List::getPhone(size_t index) const {
    if (index >= size_) throw std::out_of_range("Index out of range");
    return arr_[index];
}

size_t List::getSize() const { return size_; }

void List::print() const {
    for (size_t i = 0; i < size_; ++i)
        cout << arr_[i].toString() << "\n";
}

const Phone& List::findCheapestPhone(float diagonal) const {
    size_t found = size_;
    for (size_t i = 0; i < size_; ++i) {
        if (arr_[i].getDiagonal() == diagonal) {
            if (found == size_ || arr_[i].getPrice() < arr_[found].getPrice())
                found = i;
        }
    }
    if (found == size_) throw std::runtime_error("No such phone found");
    return arr_[found];
}

void List::clear() {
    size_ = 0;
}

void List::readFromFile(string& fileName) {
    ifstream fin(fileName);
    if (!fin) throw std::runtime_error("Cannot open file for reading");
    clear();
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        Phone p = Phone::fromString(line);
        addPhone(p, size_);
    }
    fin.close();
}

void List::writeToFile(string& fileName) const {
    ofstream fout(fileName);
    if (!fout) throw std::runtime_error("Cannot open file for writing");
    for (size_t i = 0; i < size_; ++i) {
        fout << arr_[i].toString() << "\n";
    }
    fout.close();
}
