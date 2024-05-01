#include "Intern.hpp"


Intern::Intern(void){
 std::cout << "Default Intern constructor called!" <<std::endl;
}

Intern::~Intern(){
    std::cout << "Intern destructor has called!" <<std::endl;

}

Intern::Intern(const Intern& src) {
	std::cout << "Copy constructor of an Intern has called!" <<std::endl;
    *this = src;
}

Intern &Intern::operator =(const Intern &another){
	std::cout << "Copy assignment operator of an Intern has called!" <<std::endl;
		 
	return *this;
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target){
    return ;
}