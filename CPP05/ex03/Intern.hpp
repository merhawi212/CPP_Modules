#ifndef INTERN_HPP
#define  INTERN_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"


# define PRINT_STATEMENT(statement) std::cout << statement << std::endl

class AForm;

class Intern{
    private:
		Intern(void);

    public:
		// Orthodox connonical form
		~Intern();
        Intern(const Intern& src);
        Intern &operator =(const Intern &another);

		
		AForm* makeForm(const std::string &formName, const std::string &target);
		
};

std::ostream &operator<<(std::ostream &out, const Intern &intern);


#endif
