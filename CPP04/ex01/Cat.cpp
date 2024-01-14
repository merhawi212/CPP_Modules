#include "Cat.hpp"


Cat::Cat() : Animal("Cat"){
    std::cout << "Cat default constructor called!" <<std::endl;

}

Cat::Cat(const std::string& type) : Animal(type){
    std::cout << "Cat of type " << this->_type << "  has born!" <<std::endl;
}
Cat::Cat(const Cat &src) : Animal(src){
	std::cout << "Copy constructor of a Cat type " << src._type << " has called!" <<std::endl;
    *this = src;
}

Cat &Cat::operator =(const Cat& another) {
	std::cout << "Copy assignment operator of a Cat type " << another._type << " has called!" <<std::endl;
    if (this != &another)
        this->_type = another._type;
    return *this;

}


Cat::~Cat(){
    std::cout << "Cat of type " << this->_type << " has destroyed!" <<std::endl;

}

void Cat::makeSound() const{
    std::cout << "Meow! Meow!" <<std::endl;

}