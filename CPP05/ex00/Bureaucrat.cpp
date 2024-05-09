#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(void){
 std::cout << "Default Bureaucrat constructor called!" <<std::endl;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructor has called!" <<std::endl;

}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name){
	setGrade(grade);
    std::cout << "Bureaucrat constructor called!" <<std::endl;

}

Bureaucrat::Bureaucrat(const Bureaucrat& src) {
	std::cout << "Copy constructor of A Bureaucrat name " << src._name << " has called!" <<std::endl;
    *this = src;
}
Bureaucrat &Bureaucrat::operator =(const Bureaucrat &another){
	std::cout << "Copy assignment operator of A Bureaucrat name " << another._name << " has called!" <<std::endl;
	if (this != &another){
		this->_grade = another._grade;
	}
		 
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	// < 1 is considered as too high as 1 and 150 are the highest and lowest, respectively.
	return "Ohh: Grade too high!";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	// > 150 is considered as too low as 1 and 150 are the highest and lowest, respectively.
	return "Ohh: Grade too low!";
}

void Bureaucrat::decrementGrade(){
	 std::cout << "Grade is trying to decrement " <<std::endl;
	 if ((this->_grade + 1) > LOWEST_GRADE)
	 	throw Bureaucrat::GradeTooLowException();
	 else
		this->_grade++; // this is increased by one since high grade means low value
	 std::cout << "Grade has decremented" <<std::endl;
}

void Bureaucrat::incrementGrade(){
	 std::cout << "Grade is trying to increment " <<std::endl;
	 if ((this->_grade - 1) < HIGHEST_GRADE)
	 	throw Bureaucrat::GradeTooHighException();
	 else
		this->_grade--; // this is decremented by one since lowest grade means high value
	 std::cout << "Grade has incremented" <<std::endl;
}

	// getters
std::string Bureaucrat::getName() const{
	return this->_name;
}
int Bureaucrat::getGrade() const{
	return this->_grade;
}

//setters
void Bureaucrat::setGrade(int newGrade){
	if (newGrade > LOWEST_GRADE){
		throw GradeTooLowException();
	}else if (newGrade < HIGHEST_GRADE){
		throw GradeTooHighException();
	}
	this->_grade = newGrade;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat){
	out << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return out;
}