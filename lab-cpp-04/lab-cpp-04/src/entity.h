#pragma once
#include <string>
#include <iostream>
#include <sstream>

class Device {
public:
    Device() = default;
    virtual ~Device() = default;

    // абстрактні методи
    virtual std::string getType() const = 0;
    virtual std::string info() const = 0;
    virtual Device* clone() const = 0;

    // оператори вводу/виводу
    friend std::ostream& operator<<(std::ostream& os, const Device& dev) {
        os << dev.info();
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Device& dev) {
   
        return is;
    }
};


class Phone final : public Device {
private:
    std::string model_;
    float diagonal_;
    unsigned price_;
public:
    Phone();
    Phone(const std::string& model, float diagonal, unsigned price);

    Phone& operator=(const Phone& other);
    bool operator==(const Phone& other) const;
    bool operator!=(const Phone& other) const;

    std::string getType() const override final;
    std::string info() const override final;
    Device* clone() const override final;

    friend std::ostream& operator<<(std::ostream& os, const Phone& phone);
    friend std::istream& operator>>(std::istream& is, Phone& phone);
};


class Tablet final : public Device {
private:
    std::string model_;
    float diagonal_;
    unsigned price_;
    bool pen_;
public:
    Tablet();
    Tablet(const std::string& model, float diagonal, unsigned price, bool pen);

    Tablet& operator=(const Tablet& other);
    bool operator==(const Tablet& other) const;
    bool operator!=(const Tablet& other) const;

    std::string getType() const override final;
    std::string info() const override final;
    Device* clone() const override final;

    friend std::ostream& operator<<(std::ostream& os, const Tablet& tab);
    friend std::istream& operator>>(std::istream& is, Tablet& tab);
};
