#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(cont std:strin& name, int grade) : _name(name), _grade(grade){
    std::cout << "Bureaucrat default constructor called!" <<std::endl;

}


Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructor has called!" <<std::endl;

}

void Bureaucrat::GradeTooHighException(){

}
void Bureaucrat::GradeTooLowException(){

}

void Bureaucrat::decrementGrade(){
	this->_grade++; // this is increased by one since high grade means low value
}
void Bureaucrat::incrementGrade(){
	this->_grade--; // this is decremented by one since lowest grade means high value
}
