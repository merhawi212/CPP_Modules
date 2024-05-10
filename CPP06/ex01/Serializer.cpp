#include "Serializer.hpp"

Serializer::Serializer(void){
    std::cout << "Default Serializer constructor called."  << std::endl;
}

Serializer::~Serializer(void){
    std::cout << "Serializer destructor called."  << std::endl;
}
Serializer::Serializer(const Serializer & src){
    std::cout << "Copy assignment Serializer constructor called."  << std::endl;
    *this = src;
}

Serializer &Serializer::operator =(const Serializer &){
    std::cout << "Copy assignment operator Serializer constructor called."  << std::endl;
    return *this;
}


uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}