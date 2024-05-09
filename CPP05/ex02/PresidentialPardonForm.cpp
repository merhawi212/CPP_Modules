#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(void){
    std::cout << "Default PresidentialPardonForm constructor has called!" <<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "PresidentialPardonForm destructor has called!" <<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) 
			: AForm("Pardon", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm constructor has called!" <<std::endl;
}



PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
: AForm("Pardon", 25, 5), _target(src._target)
{
	std::cout << "Copy constructor of a Presidential Pardon Form at target " << src._target << " has called!" <<std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator =(const PresidentialPardonForm &another){
	std::cout << "Copy assignment operator of a Presidential Pardon Form at target " << another._target << " has called!" <<std::endl;
	if (this != &another){
		this->_target = another._target;
	}
		
	return *this;
}

 void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (!this->isSigned()){
		throw AFormNotSignedException();
	}
	if (executor.getGrade() > this->getGradeToExecute()){
		    throw GradeTooLowException(); 
	}
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
 }