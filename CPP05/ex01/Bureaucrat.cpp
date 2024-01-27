#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name){
	setGrade(grade);
    std::cout << "Bureaucrat constructor called!" <<std::endl;

}


Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructor has called!" <<std::endl;

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

void Bureaucrat::signForm(Form &form){
	std::string reason;
	
	if (form.getGradeToSign() < this->_grade){
		reason = "grade is lower than the requred one, which is >= " 
				+ std::to_string(form.getGradeToSign())
				 + " (remember " + std::to_string(form.getGradeToSign())  + " is > " + std::to_string(this->_grade) + ")";
	}
	else
		reason = "something wrong is there with the form!";
	if (form.getIsSigned())
		std::cout << this->_name <<  " signed " << form.getName() << std::endl;
	else
		std::cout << this->_name <<  " couldn’t sign " << form.getName()
					<< " because " << reason << std::endl;
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
	if (newGrade  > LOWEST_GRADE){
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