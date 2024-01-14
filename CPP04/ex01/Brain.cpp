#include "Brain.hpp"


Brain::Brain(){
    std::cout << "Brain default constructor called!" <<std::endl;

}


Brain::Brain(const Brain& src){
    std::cout << "Copy constructor of a Brain  has called!" <<std::endl;
    *this = src;

}

Brain &Brain::operator =(const Brain &another){
   
    std::cout << "Copy assignment operator of a Brain has called!" <<std::endl;
    if (this != &another)
        this->_ideas = another._ideas;
    return *this;
}

Brain::~Brain(){
    std::cout << "Brain of  has destroyed!" <<std::endl;

}



// getter and setter

std::string* const  Brain::getIdeas() const{
	return _ideas;
}
void  Brain::setIdeas(const std::string* &ideas){
	this->_ideas = ideas;
}