#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void){
    std::cout << "Default RobotomyRequestForm constructor has called!" <<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm destructor has called!" <<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
			: AForm("Robotomym", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor has called!" <<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
: AForm("Robotomy", 72, 45), _target(src._target)
{
	std::cout << "Copy constructor of a Robotomy Request Form at target " << src._target << " has called!" <<std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator =(const RobotomyRequestForm &another){
	std::cout << "Copy assignment operator of a Robotomy Request Form at target " << another._target << " has called!" <<std::endl;
	if (this != &another){
		this->_target = another._target;
	}
		
	return *this;
}
 void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (!this->isSigned()){
		throw GradeTooLowException();
	}
	if (executor.getGrade() > this->getGradeToExecute()){
		    throw GradeTooLowException(); 
	}
    std::srand(std::time(NULL)); // Seed the random number generator

    // Simulate the robotomy procedure
    bool success = (std::rand() % 2 == 0); // Randomly determine success or failure (50% chance)

    // Inform about the result of the robotomy procedure
    if (success) {
        std::cout << "Bzzzzz... drilling noises..." << std::endl;
        std::cout << "Robotomy successful! " << getName() << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "Bzzzzz... drilling noises..." << std::endl;
        std::cout << "Robotomy failed! " << getName() << " could not be robotomized." << std::endl;
    }
}