#include "Cat.hpp"


Cat::Cat(){
    std::cout << "Cat default constructor called!" <<std::endl;

}

Cat::Cat(const std::string& type) _type("Cat"){
    std::cout << "Cat of type " << this->_type << "  has born!" <<std::endl;
}

Cat::Cat(const Cat& src){
    if (this != &src)
        this->_type = src._type;
    std::cout << "Copy constructor of an Cat type " << this->_type << " has called!" <<std::endl;
    return *this;

}

Cat::Cat &operator =(const Cat &another){
    *this = another;
    std::cout << "Copy assignment operator of an Cat type " << this->_type << " has called!" <<std::endl;
}

Cat::~Cat(){
    std::cout << "Cat of type " << this->_type << " has destroyed!" <<std::endl;

}

void Cat::makeSound(){
    std::cout << "Meow! Meow!" <<std::endl;

}