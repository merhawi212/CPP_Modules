#include "Animal.hpp"


// getter and setter
std::string const Animal::getType() const{
	return _type;
}
void Animal::setType(const std::string &type){
	this->_type = type;
}