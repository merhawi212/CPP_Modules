#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP


#include "AForm.hpp"

class PresidentialPardonForm: public AForm{
    private:
           std::string _target;

 			PresidentialPardonForm(void);

    public:
		// Orthodox connonical form
		~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& src);
        PresidentialPardonForm &operator =(const PresidentialPardonForm &another);

		// custom constructor
		PresidentialPardonForm(const std::string &target);

		 void execute(Bureaucrat const & executor) const;

		// getter

		
};


#endif // PRESIDENTIALPARDONFORM_HPP
