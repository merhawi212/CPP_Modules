#include "Dog.hpp"


Dog::Dog() : Animal("Dog"){
    std::cout << "Dog default constructor called!" <<std::endl;

}

Dog::Dog(const std::string& type) : Animal(type){
    std::cout << "Dog of type " << this->_type << "  has born!" <<std::endl;
}

Dog::Dog(const Dog& src) : Animal(src){
    std::cout << "Copy constructor of an Dog type " << this->_type << " has called!" <<std::endl;
      *this = src;
}

Dog &Dog::operator =(const Dog &another){
    std::cout << "Copy assignment operator of a Dog type " << this->_type << " has called!" <<std::endl;
	if (this != &another)
        this->_type = another._type;
	return *this;
}

Dog::~Dog(){
    std::cout << "Dog of type " << this->_type << " has destroyed!" <<std::endl;

}

void Dog::makeSound() const{
    std::cout << "Woof! Woof!" <<std::endl;

}