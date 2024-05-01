#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP


#include "AForm.hpp"

class ShrubberyCreationForm: public AForm{
    private:
           std::string _target;

    	ShrubberyCreationForm(void);

    public:
		// Orthodox connonical form
		~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& src);
        ShrubberyCreationForm &operator =(const ShrubberyCreationForm &another);

		// custom constructor
		ShrubberyCreationForm(const std::string &target);

		 void execute(Bureaucrat const & executor) const;

		// getter

		
};


#endif // SHRUBBERYCREATIONFORM_HPP
