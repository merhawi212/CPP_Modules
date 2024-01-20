#include "Dog.hpp"


Dog::Dog(){
    this->_type = "Dog";
    this->_brain = new Brain();
    std::cout << "Dog default constructor called!" <<std::endl;

}

Dog::Dog(const std::string& type){
    this->_type = type;
    this->_brain = new Brain();
    std::cout << "Dog type has born!" <<std::endl;
}

Dog::Dog(const Dog& src) {
    this->_brain = new Brain();
    std::cout << "Copy constructor of a Dog type has called!" <<std::endl;
      *this = src;
}

Dog &Dog::operator =(const Dog &another){
    std::cout << "Copy assignment operator of a Dog has called!" <<std::endl;
	if (this != &another)
        this->_type = another._type;
	return *this;
}

Dog::~Dog(){
     delete this->_brain;
    std::cout << "Dog type has destroyed!" <<std::endl;

}

void Dog::makeSound() const{
   
    std::cout << "Woof! Woof!" <<std::endl;

}