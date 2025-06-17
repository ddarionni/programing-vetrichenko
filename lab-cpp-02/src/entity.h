#pragma once
#include <string>
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

   
    std::string getModel() const;
    float getDiagonal() const;
    unsigned getPrice() const;

    
    void setModel(const std::string& model);
    void setDiagonal(float diagonal);
    void setPrice(unsigned price);

    
    std::string toString() const;

 
    static Phone fromString(const std::string& line);
};
