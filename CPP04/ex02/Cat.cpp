#include "Cat.hpp"


Cat::Cat(){
    this->_type = "Cat";
    this->_brain = new Brain();
    std::cout << "Cat default constructor called!" <<std::endl;

}

Cat::Cat(const std::string& type){
    this->_type = type;
    std::cout << "Cat type has born!" <<std::endl;
}
Cat::Cat(const Cat &src){
	std::cout << "Copy constructor of a Cat type has called!" <<std::endl;
    *this = src;
}

Cat &Cat::operator =(const Cat& another) {
	std::cout << "Copy assignment operator of a Cat type has called!" <<std::endl;
    if (this != &another)
        this->_type = another._type;
    return *this;

}


Cat::~Cat(){
    delete this->_brain;

    std::cout << "a Cat type has destroyed!" <<std::endl;

}

void Cat::makeSound() const{
    std::cout << "Meow! Meow!" <<std::endl;

}