#include "Dog.hpp"


Dog::Dog(){
    std::cout << "Dog default constructor called!" <<std::endl;

}

Dog::Dog(const std::string& type) _type("Dog"){
    std::cout << "Dog of type " << this->_type << "  has born!" <<std::endl;
}

Dog::Dog(const Dog& src){
    if (this != &src)
        this->_type = src._type;
    std::cout << "Copy constructor of an Dog type " << this->_type << " has called!" <<std::endl;
    return *this;

}

Dog::Dog &operator =(const Dog &another){
    *this = another;
    std::cout << "Copy assignment operator of an Dog type " << this->_type << " has called!" <<std::endl;
}

Dog::~Dog(){
    std::cout << "Dog of type " << this->_type << " has destroyed!" <<std::endl;

}

void Dog::makeSound(){
    std::cout << "Woof! Woof!" <<std::endl;

}