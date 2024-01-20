#include "Animal.hpp"


Animal::Animal() : _type("Default Type"){
    std::cout << "Animal default constructor called!" <<std::endl;

}

Animal::Animal(const std::string& type) : _type(type){
    std::cout << "Animal of type " << this->_type << "  has born!" <<std::endl;
}

Animal::Animal(const Animal& src){
    std::cout << "Copy constructor of an animal type " << src._type << " has called!" <<std::endl;
    *this = src;

}

Animal &Animal::operator =(const Animal &another){
   
    std::cout << "Copy assignment operator of an animal type " << another._type << " has called!" <<std::endl;
    if (this != &another)
        this->_type = another._type;
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal of type " << this->_type << " has destroyed!" <<std::endl;

}

void Animal::makeSound() const{
    std::cout << "A Default Animal sound!" <<std::endl;

}


// getter
std::string const Animal::getType() const{
	return _type;
}
