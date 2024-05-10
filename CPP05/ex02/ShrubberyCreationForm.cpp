#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void){
    std::cout << "Default ShrubberyCreationForm constructor has called!" <<std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm destructor has called!" <<std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
			: AForm("Shrubbery", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor has called!" <<std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
: AForm("Shrubbery Creation Form", 145, 137), _target(src._target)
{
	std::cout << "Copy constructor of a Shrubbery Creation Form at target " << src._target << " has called!" <<std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator =(const ShrubberyCreationForm &another){
	std::cout << "Copy assignment operator of a Shrubbery Creation Form at target " << another._target << " has called!" <<std::endl;
	if (this != &another){
		this->_target = another._target;
	}
		
	return *this;
}

 void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (!this->isSigned()){
		throw AFormNotSignedException();
	}
	if (executor.getGrade() > this->getGradeToExecute()){
		    throw GradeTooLowException(); 
	}
	std::string filename = this->_target + "_shrubbery";
    std::ofstream ofs(filename.c_str());
    if (!ofs) {
		std::cerr << "Error: Unable to open output file " << filename << std::endl;
		 throw GenericException(); 
    }
    ofs << "      *\n"
        << "     ***\n"
        << "    *****\n"
        << "   *******\n"
        << "  *********\n"
        << " ***********\n"
        << "*************\n"
        << "     |||\n"
        << "     |||\n"
        << "     |||\n"
        << "     |||\n"
        << "     |||\n"
        << "  @@@@@@@@@@@\n"
        << " @@@@ @ @@@@ ~\n"
        << "+~ +x @@ ~ @ @ ~ \n"
        << std::endl;

    ofs.close();
 }