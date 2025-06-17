#include "entity.h"
#include <sstream>
#include <utility>

using std::string;
using std::stringstream;
using std::cout;
using std::istream;
using std::ostream;

// kонструктор за замовчуванням
Phone::Phone() : model_(""), diagonal_(0), price_(0) {}

// kонструктор з параметрами
Phone::Phone(const string& model, float diagonal, unsigned price)
    : model_(model), diagonal_(diagonal), price_(price) {}

// kонструктор копіювання
Phone::Phone(const Phone& other)
    : model_(other.model_), diagonal_(other.diagonal_), price_(other.price_) {}


Phone::~Phone() {}

// oператор присвоювання
Phone& Phone::operator=(const Phone& other) {
    if (this != &other) {
        model_ = other.model_;
        diagonal_ = other.diagonal_;
        price_ = other.price_;
    }
    return *this;
}

// порівняння ==
bool Phone::operator==(const Phone& other) const {
    return model_ == other.model_ && diagonal_ == other.diagonal_ && price_ == other.price_;
}

// not   !=
bool Phone::operator!=(const Phone& other) const {
    return !(*this == other);
}


ostream& operator<<(ostream& os, const Phone& phone) {
    os << phone.model_ << ";" << phone.diagonal_ << ";" << phone.price_;
    return os;
}


istream& operator>>(istream& is, Phone& phone) {
    string line;
    getline(is, line);

    stringstream ss(line);
    string model;
    float diagonal;
    unsigned price;

    getline(ss, model, ';');
    ss >> diagonal;
    ss.ignore(1); // ;
    ss >> price;

    phone.model_ = model;
    phone.diagonal_ = diagonal;
    phone.price_ = price;
    return is;
}


string Phone::getModel() const { return model_; }
float Phone::getDiagonal() const { return diagonal_; }
unsigned Phone::getPrice() const { return price_; }


void Phone::setModel(const string& model) { model_ = model; }
void Phone::setDiagonal(float diagonal) { diagonal_ = diagonal; }
void Phone::setPrice(unsigned price) { price_ = price; }
