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
            std::copy(another._ideas, another._ideas + 100, this->_ideas);
    return *this;
}

Brain::~Brain(){
    std::cout << "Brain has destroyed!" <<std::endl;

}



// getter and setter

const std::string*   Brain::getIdeas() const{
	return _ideas;
}
void  Brain::setIdeas(const std::string* &ideas){
	    std::copy(ideas, ideas + 100, this->_ideas);
}