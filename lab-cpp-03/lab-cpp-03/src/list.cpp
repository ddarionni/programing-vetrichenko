#include "list.h"
#include <sstream>

using std::string;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;


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


List::List() : arr_(nullptr), size_(0), capacity_(0) {}

//копіювання
List::List(const List& other)
    : arr_(nullptr), size_(other.size_), capacity_(other.capacity_) {
    if (capacity_) {
        arr_ = new Phone[capacity_];
        for (size_t i = 0; i < size_; ++i) arr_[i] = other.arr_[i];
    }
}


List::~List() {
    delete[] arr_;
}


List& List::operator=(const List& other) {
    if (this != &other) {
        delete[] arr_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        if (capacity_) {
            arr_ = new Phone[capacity_];
            for (size_t i = 0; i < size_; ++i) arr_[i] = other.arr_[i];
        } else {
            arr_ = nullptr;
        }
    }
    return *this;
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

size_t List::getSize() const { return size_; }

// Оператор індексування
Phone& List::operator[](size_t index) {
    if (index >= size_) throw std::out_of_range("Index out of range");
    return arr_[index];
}
const Phone& List::operator[](size_t index) const {
    if (index >= size_) throw std::out_of_range("Index out of range");
    return arr_[index];
}


ostream& operator<<(ostream& os, const List& list) {
    for (size_t i = 0; i < list.size_; ++i) {
        os << list.arr_[i] << "\n";
    }
    return os;
}


istream& operator>>(istream& is, List& list) {
    list.clear();
    string line;
    while (getline(is, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        Phone p;
        ss >> p;
        list.addPhone(p, list.size_);
    }
    return is;
}


ofstream& operator<<(ofstream& ofs, const List& list) {
    for (size_t i = 0; i < list.size_; ++i) {
        ofs << list.arr_[i] << "\n";
    }
    return ofs;
}


ifstream& operator>>(ifstream& ifs, List& list) {
    list.clear();
    string line;
    while (getline(ifs, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        Phone p;
        ss >> p;
        list.addPhone(p, list.size_);
    }
    return ifs;
}

void List::clear() {
    size_ = 0;
}
