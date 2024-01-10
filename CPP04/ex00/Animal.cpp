#include "Animal.hpp"


Animal::Animal(){
    std::cout << "Animal default constructor called!" <<std::endl;

}

Animal::Animal(const std::string& type) : _type("General Animal"){
    std::cout << "Animal of type " << this->_type << "  has born!" <<std::endl;
}

Animal::Animal(const Animal& src){
    *this = src;
        std::cout << "Copy constructor of an animal type " << this->_type << " has called!" <<std::endl;

}

Animal::Animal &operator =(const Animal &another){
   
    std::cout << "Copy assignment operator of an animal type " << this->_type << " has called!" <<std::endl;
    if (this != &src)
        this->_type = src._type;
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal of type " << this->_type << " has destroyed!" <<std::endl;

}

void Animal::makeSound(){
    std::cout << "An indistnict Animal sound!" <<std::endl;

}