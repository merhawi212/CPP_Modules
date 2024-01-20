#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal("WrongCat"){
    std::cout << "WrongCat default constructor called!" <<std::endl;

}

WrongCat::WrongCat(const std::string& type) : WrongAnimal(type){
    std::cout << "WrongCat of type " << this->_type << "  has born!" <<std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src){
	std::cout << "Copy constructor of a WrongCat type " << src._type << " has called!" <<std::endl;
    *this = src;
}

WrongCat &WrongCat::operator =(const WrongCat& another) {
	std::cout << "Copy assignment operator of a WrongCat type " << another._type << " has called!" <<std::endl;
    if (this != &another)
        this->_type = another._type;
    return *this;

}


WrongCat::~WrongCat(){
    std::cout << "WrongCat of type " << this->_type << " has destroyed!" <<std::endl;

}

void WrongCat::makeSound() const{
    std::cout << "Meow! Meow!" <<std::endl;

}