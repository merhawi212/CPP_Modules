#include "Form.hpp"


Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute) 
		: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
	validateGrade(gradeToSign);
	validateGrade(gradeToExecute);
    std::cout << "Form constructor has called!" <<std::endl;

}


Form::~Form(){
    std::cout << "Form destructor has called!" <<std::endl;

}

const char* Form::GradeTooHighException::what() const throw() {
	// < 1 is considered as too high as 1 and 150 are the highest and lowest, respectively.
	return "Ohh: Grade too high!";
}
const char* Form::GradeTooLowException::what() const throw() {
	// > 150 is considered as too low as 1 and 150 are the highest and lowest, respectively.
	return "Ohh: Grade too low!";
}

// getters
std::string Form::getName() const{
	return this->_name;
}
bool Form::getIsSigned() const{
	return this->_isSigned;
}
int Form::getGradeToSign() const{
	return this->_gradeToSign;
}
int Form::getGradeToExecute() const{
	return this->_gradeToExecute;
}

void  Form::beSigned(Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() >= this->_gradeToSign) // since 1 is higher than 2
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

void  Form::validateGrade(const int grade){
	if (grade  > LOWEST_GRADE){
		throw GradeTooLowException();
	}else if (grade < HIGHEST_GRADE){
		throw GradeTooHighException();
	}
}


std::ostream &operator<<(std::ostream &out, const Form &form){
	
	out << "Name: "<< form.getName() << ", gradeToSign: >= " << form.getGradeToSign() 
			<< " and gradeToExecute: >=  " << form.getGradeToExecute() << "(remember 1 is > 2), isSigned: "<< form.getIsSigned()<< std::endl;
	return out;
}