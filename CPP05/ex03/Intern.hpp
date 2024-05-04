#ifndef INTERN_HPP
#define  INTERN_HPP

#include <iostream>
#include <string>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"




# define PRINT_STATEMENT(statement) std::cout << statement << std::endl

class AForm;

class Intern{
    private:

        struct FormCreationPair {
            const char* name;
            AForm* (*createFunc)(const std::string&);
        };

        static AForm* createShrubberyCreationForm(const std::string &target) {
             return new ShrubberyCreationForm(target);
        }
        static AForm* createRobotomyRequestForm(const std::string &target) { 
            return new RobotomyRequestForm(target); 
        }
        static AForm* createPresidentialPardonForm(const std::string &target) { 
            return new PresidentialPardonForm(target);
        }

        static const FormCreationPair formCreators[];


    public:
		// Orthodox connonical form
        Intern(void);
		~Intern();
        Intern(const Intern& src);
        Intern &operator =(const Intern &);
		
		AForm* makeForm(const std::string &formName, const std::string &target);
		
};

std::ostream &operator<<(std::ostream &out, const Intern &intern);


#endif
