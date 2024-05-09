#include "AForm.hpp"

AForm::AForm(void): _name("Default form"), _gradeToSign(5), _gradeToExecute(1), _signed(false){
    std::cout << "Default Form constructor has called!" <<std::endl;

}

AForm::~AForm(){
    std::cout << "Form destructor has called!" <<std::endl;

}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute) 
		: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
	validateGrade(gradeToSign);
	validateGrade(gradeToExecute);
    std::cout << "Form constructor has called!" <<std::endl;

}


AForm::AForm(const AForm& src): _name(src._name), _gradeToSign(src._gradeToSign),
			_gradeToExecute(src._gradeToExecute), _signed(src._signed)
{
	std::cout << "Copy constructor of a Form name " << src._name << " has called!" <<std::endl;
}

AForm &AForm::operator =(const AForm &another){
	std::cout << "Copy assignment operator of a Form name " << another._name << " has called!" <<std::endl;
	if (this != &another){
		this->_signed = another._signed;
	}
		
	return *this;
}

const char* AForm::GradeTooHighException::what() const throw() {
	// < 1 is considered as too high as 1 and 150 are the highest and lowest, respectively.
	return "Ohh: Grade too high!";
}
const char* AForm::GradeTooLowException::what() const throw() {
	// > 150 is considered as too low as 1 and 150 are the highest and lowest, respectively.
	return "Ohh: Grade too low!";
}

const char* AForm::AFormNotSignedException::what() const throw() {
	// > 150 is considered as too low as 1 and 150 are the highest and lowest, respectively.
	return "Form not signed! It must be signed first in order to execute.";
}
// getters
std::string AForm::getName() const{
	return this->_name;
}
bool AForm::isSigned() const{
	return this->_signed;
}
int AForm::getGradeToSign() const{
	return this->_gradeToSign;
}
int AForm::getGradeToExecute() const{
	return this->_gradeToExecute;
}

void  AForm::beSigned(Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() > this->_gradeToSign) // since 1 is higher than 2
		throw AForm::GradeTooLowException();
	this->_signed = true;
}


void  AForm::validateGrade(const int grade){
	if (grade  > LOWEST_GRADE){
		throw GradeTooLowException();
	}else if (grade < HIGHEST_GRADE){
		throw GradeTooHighException();
	}
}


std::ostream &operator<<(std::ostream &out, const AForm &form){
	
	out << "Form name: "<< form.getName() << ", gradeToSign: >= " << form.getGradeToSign() 
			<< " and gradeToExecute: >=  " << form.getGradeToExecute() << "(remember 1 is > 2), isSigned: "<< form.isSigned()<< std::endl;
	return out;
}