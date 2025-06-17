#include "list.h"
#include <sstream>
#include <typeinfo>

List::List() {}
List::List(const List& other) {
    for (const auto* dev : other.arr_) {
        arr_.push_back(dev->clone());
    }
}
List::~List() { clear(); }

List& List::operator=(const List& other) {
    if (this != &other) {
        clear();
        for (const auto* dev : other.arr_) {
            arr_.push_back(dev->clone());
        }
    }
    return *this;
}

void List::add(Device* dev) {
    arr_.push_back(dev);
}
void List::remove(size_t idx) {
    if (idx < arr_.size()) {
        delete arr_[idx];
        arr_.erase(arr_.begin() + idx);
    }
}
Device& List::operator[](size_t idx) {
    return *arr_[idx];
}
const Device& List::operator[](size_t idx) const {
    return *arr_[idx];
}
size_t List::size() const { return arr_.size(); }
void List::clear() {
    for (auto* dev : arr_) delete dev;
    arr_.clear();
}

std::ostream& operator<<(std::ostream& os, const List& list) {
    for (const auto* dev : list.arr_) {
        os << dev->getType() << ":" << dev->info() << "\n";
    }
    return os;
}
std::istream& operator>>(std::istream& is, List& list) {
    list.clear();
    std::string line;
    while (getline(is, line)) {
        if (line.find("Phone:") == 0) {
            std::istringstream ss(line.substr(6));
            Phone* p = new Phone();
            ss >> *p;
            list.add(p);
        } else if (line.find("Tablet:") == 0) {
            std::istringstream ss(line.substr(7));
            Tablet* t = new Tablet();
            ss >> *t;
            list.add(t);
        }
    }
    return is;
}
std::ofstream& operator<<(std::ofstream& ofs, const List& list) {
    for (const auto* dev : list.arr_) {
        ofs << dev->getType() << ":" << dev->info() << "\n";
    }
    return ofs;
}
std::ifstream& operator>>(std::ifstream& ifs, List& list) {
    std::string line;
    while (getline(ifs, line)) {
        if (line.find("Phone:") == 0) {
            std::istringstream ss(line.substr(6));
            Phone* p = new Phone();
            ss >> *p;
            list.add(p);
        } else if (line.find("Tablet:") == 0) {
            std::istringstream ss(line.substr(7));
            Tablet* t = new Tablet();
            ss >> *t;
            list.add(t);
        }
    }
    return ifs;
}
