#include "entity.h"
#include <sstream>



Phone::Phone() : model_(""), diagonal_(0), price_(0) {}
Phone::Phone(const std::string& model, float diagonal, unsigned price)
    : model_(model), diagonal_(diagonal), price_(price) {}

Phone& Phone::operator=(const Phone& other) {
    if (this != &other) {
        model_ = other.model_;
        diagonal_ = other.diagonal_;
        price_ = other.price_;
    }
    return *this;
}
bool Phone::operator==(const Phone& other) const {
    return model_ == other.model_ && diagonal_ == other.diagonal_ && price_ == other.price_;
}
bool Phone::operator!=(const Phone& other) const {
    return !(*this == other);
}

std::string Phone::getType() const { return "Phone"; }
std::string Phone::info() const {
    std::ostringstream ss;
    ss << model_ << ";" << diagonal_ << ";" << price_;
    return ss.str();
}
Device* Phone::clone() const { return new Phone(*this); }

std::ostream& operator<<(std::ostream& os, const Phone& phone) {
    os << phone.model_ << ";" << phone.diagonal_ << ";" << phone.price_;
    return os;
}
std::istream& operator>>(std::istream& is, Phone& phone) {
    std::string line;
    getline(is, line);
    std::istringstream ss(line);
    getline(ss, phone.model_, ';');
    ss >> phone.diagonal_;
    ss.ignore(1);
    ss >> phone.price_;
    return is;
}



Tablet::Tablet() : model_(""), diagonal_(0), price_(0), pen_(false) {}
Tablet::Tablet(const std::string& model, float diagonal, unsigned price, bool pen)
    : model_(model), diagonal_(diagonal), price_(price), pen_(pen) {}

Tablet& Tablet::operator=(const Tablet& other) {
    if (this != &other) {
        model_ = other.model_;
        diagonal_ = other.diagonal_;
        price_ = other.price_;
        pen_ = other.pen_;
    }
    return *this;
}
bool Tablet::operator==(const Tablet& other) const {
    return model_ == other.model_ && diagonal_ == other.diagonal_ && price_ == other.price_ && pen_ == other.pen_;
}
bool Tablet::operator!=(const Tablet& other) const {
    return !(*this == other);
}

std::string Tablet::getType() const { return "Tablet"; }
std::string Tablet::info() const {
    std::ostringstream ss;
    ss << model_ << ";" << diagonal_ << ";" << price_ << ";" << pen_;
    return ss.str();
}
Device* Tablet::clone() const { return new Tablet(*this); }

std::ostream& operator<<(std::ostream& os, const Tablet& tab) {
    os << tab.model_ << ";" << tab.diagonal_ << ";" << tab.price_ << ";" << tab.pen_;
    return os;
}
std::istream& operator>>(std::istream& is, Tablet& tab) {
    std::string line;
    getline(is, line);
    std::istringstream ss(line);
    getline(ss, tab.model_, ';');
    ss >> tab.diagonal_;
    ss.ignore(1);
    ss >> tab.price_;
    ss.ignore(1);
    ss >> tab.pen_;
    return is;
}
