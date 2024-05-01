#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include "AForm.hpp"

class RobotomyRequestForm: public AForm{
    private:
           std::string _target;

    	RobotomyRequestForm(void);

    public:
		// Orthodox connonical form
		~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& src);
        RobotomyRequestForm &operator =(const RobotomyRequestForm &another);

		RobotomyRequestForm(const std::string &target);

		 void execute(Bureaucrat const & executor) const;

		// getter

		
};


#endif // ROBOTOMYREQUESTFORM_HPP
