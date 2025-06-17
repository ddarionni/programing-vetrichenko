#include "entity.h"
#include <iostream>
#include <sstream>

using std::string;
using std::stringstream;
using std::cout;


Phone::Phone() : model_(""), diagonal_(0), price_(0) {
    cout << "[LOG] Phone: Default constructor\n";
}


Phone::Phone(const string& model, float diagonal, unsigned price)
    : model_(model), diagonal_(diagonal), price_(price) {
    cout << "[LOG] Phone: Args constructor\n";
}


Phone::Phone(const Phone& other)
    : model_(other.model_), diagonal_(other.diagonal_), price_(other.price_) {
    cout << "[LOG] Phone: Copy constructor\n";
}


Phone::~Phone() {
    cout << "[LOG] Phone: Destructor (" << model_ << ")\n";
}


string Phone::getModel() const { return model_; }
float Phone::getDiagonal() const { return diagonal_; }
unsigned Phone::getPrice() const { return price_; }

void Phone::setModel(const string& model) { model_ = model; }
void Phone::setDiagonal(float diagonal) { diagonal_ = diagonal; }
void Phone::setPrice(unsigned price) { price_ = price; }

string Phone::toString() const {
    stringstream ss;
    ss << model_ << ";" << diagonal_ << ";" << price_;
    return ss.str();
}


Phone Phone::fromString(const string& line) {
    stringstream ss(line);
    string model;
    float diagonal;
    unsigned price;

    getline(ss, model, ';');
    ss >> diagonal;
    ss.ignore(1); // Пропуск ';'
    ss >> price;

    return Phone(model, diagonal, price);
}
