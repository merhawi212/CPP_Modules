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

Intern &Intern::operator =(const Intern &){
	std::cout << "Copy assignment operator of an Intern has called!" <<std::endl;
		 
	return *this;
}

AForm* Intern::createShrubberyCreationForm(const std::string &target) {
             return new ShrubberyCreationForm(target);
        }
AForm* Intern::createRobotomyRequestForm(const std::string &target) { 
	return new RobotomyRequestForm(target); 
}
AForm* Intern::createPresidentialPardonForm(const std::string &target) { 
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target){
	if (formName.empty()){
		 std::cerr << "From name is not provided" << std::endl;
		return NULL;
	}
	if (target.empty()){
		 std::cerr << "Target input is not provided" << std::endl;
		return NULL;
	}
    std::string lowercaseFormName = formName;
    // Convert formName to lowercase
	for (size_t i = 0; i < lowercaseFormName.size(); ++i) {
		lowercaseFormName[i] = std::tolower(lowercaseFormName[i]);
	}
    for (const FormCreationPair *pair = formCreators; pair->name; ++pair) {
            if (lowercaseFormName == pair->name) {
                AForm* form = pair->createFunc(target);
                return form;
            }
        }
        std::cout << "Unknown form name" << std::endl;
        return NULL;
}

const Intern::FormCreationPair Intern::formCreators[] = {
    {"shrubbery creation", &createShrubberyCreationForm},
    {"robotomy request", &createRobotomyRequestForm},
    {"presidential pardon", &createPresidentialPardonForm},
    {NULL, NULL} // The end of the array
};