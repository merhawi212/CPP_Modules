#include "Serialization.hpp"

Serialization::Serialization(void){
    std::cout << "Default Serialization constructor called."  << std::endl;
}

Serialization::~Serialization(void){
    std::cout << "Serialization destructor called."  << std::endl;
}
Serialization::Serialization(const Serialization & src){
    std::cout << "Copy assignment Serialization constructor called."  << std::endl;
    *this = src;
}

Serialization &Serialization::operator =(const Serialization &){
    std::cout << "Copy assignment operator Serialization constructor called."  << std::endl;
    return *this;
}

