#include "Cat.hpp"


Cat::Cat() : Animal("Cat"){
    this->_brain = new Brain();

    std::cout << "Cat default constructor called!" <<std::endl;

}

Cat::Cat(const std::string& type) : Animal(type){
	 this->_brain = new Brain();
    std::cout << "Cat custom constructor: an Animal of type " << this->_type << "  has born!" <<std::endl;
}

Cat::Cat(const Cat &src) : Animal(src){
	 this->_brain = new Brain();
	std::cout << "Cat copy constructor: an Animal type " << src._type << " has called!" <<std::endl;
    *this = src;
}

Cat &Cat::operator =(const Cat& another) {
	std::cout << "Cat copy assignment operator: an Animal type " << another._type << " has called!" <<std::endl;
    if (this != &another)
        this->_type = another._type;
    return *this;

}


Cat::~Cat(){
    delete this->_brain;

     std::cout << "Cat destructor: Animal of type " << this->_type << " has destroyed!" <<std::endl;
}

void Cat::makeSound() const{
    std::cout << "Meow! Meow!" <<std::endl;

}


Brain*  Cat::getBrain() const {
    return _brain;
}
