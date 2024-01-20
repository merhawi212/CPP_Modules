#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : _type("WrongAnimal Default Type"){
    std::cout << "WrongAnimal default constructor called!" <<std::endl;

}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type){
    std::cout << "WrongAnimal of type " << this->_type << "  has born!" <<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src){
    std::cout << "Copy constructor of a WrongAnimal type " << this->_type << " has called!" <<std::endl;
    *this = src;

}

WrongAnimal &WrongAnimal::operator =(const WrongAnimal &another){
   
    std::cout << "Copy assignment operator of a WrongAnimal type " << this->_type << " has called!" <<std::endl;
    if (this != &another)
        this->_type = another._type;
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal of type " << this->_type << " has destroyed!" <<std::endl;

}

void WrongAnimal::makeSound() const{
    std::cout << "A Default WrongAnimal sound!" <<std::endl;

}


// getter
std::string const WrongAnimal::getType() const{
	return _type;
}
