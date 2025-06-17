#pragma once
#include <string>
#include <iostream>
#include <sstream>


class Phone {
private:
    std::string model_;
    float diagonal_;
    unsigned price_;
public:
    Phone();
    Phone(const std::string& model, float diagonal, unsigned price);
    Phone(const Phone& other);
    ~Phone();

    Phone& operator=(const Phone& other); // oператор присвоювання

    // oператори порівняння
    bool operator==(const Phone& other) const;
    bool operator!=(const Phone& other) const;

    // oператори потокового введення/виведення
    friend std::ostream& operator<<(std::ostream& os, const Phone& phone);
    friend std::istream& operator>>(std::istream& is, Phone& phone);

    std::string getModel() const;
    float getDiagonal() const;
    unsigned getPrice() const;

    void setModel(const std::string& model);
    void setDiagonal(float diagonal);
    void setPrice(unsigned price);
};
