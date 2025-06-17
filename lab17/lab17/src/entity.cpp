#include "entity.h"


Phone::Phone() : model_(""), diagonal_(0), price_(0) {
    std::cout << "[LOG] Phone: Default constructor\n";
}


Phone::Phone(const std::string& model, float diagonal, unsigned price)
    : model_(model), diagonal_(diagonal), price_(price) {
    std::cout << "[LOG] Phone: Args constructor\n";
}


Phone::Phone(const Phone& other)
    : model_(other.model_), diagonal_(other.diagonal_), price_(other.price_) {
    std::cout << "[LOG] Phone: Copy constructor\n";
}


Phone::~Phone() {
    std::cout << "[LOG] Phone: Destructor (" << model_ << ")\n";
}


std::string Phone::getModel() const { return model_; }
float Phone::getDiagonal() const { return diagonal_; }
unsigned Phone::getPrice() const { return price_; }


void Phone::setModel(const std::string& model) { model_ = model; }
void Phone::setDiagonal(float diagonal) { diagonal_ = diagonal; }
void Phone::setPrice(unsigned price) { price_ = price; }

void Phone::print() const {
    std::cout << "Model: " << model_
              << ", Diagonal: " << diagonal_
              << ", Price: " << price_ << std::endl;
}
