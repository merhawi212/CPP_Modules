#ifndef BUREAUCRAT_HPP
#define  BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <sstream>  // Create a stringstream
#include "AForm.hpp"

# define LOWEST_GRADE 150
# define HIGHEST_GRADE 1
# define PRINT_STATEMENT(statement) std::cout << statement << std::endl

class AForm;

class Bureaucrat{
    private:
        const std::string _name;
		int _grade;
			//setters
		void setGrade(int newGrade);
		Bureaucrat(void);

    public:
		// Orthodox connonical form
		~Bureaucrat();
        Bureaucrat(const Bureaucrat& src);
        Bureaucrat &operator =(const Bureaucrat &another);

		//custom constructor
		Bureaucrat(const std::string& name, int grade);

		class GradeTooHighException : public std::exception {
				public:
					virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
				public:
					virtual const char* what() const throw();
		};

		void decrementGrade();
		void incrementGrade();
		void signForm(AForm &form);
		void executeForm(AForm const & form) const;

		// getters
		std::string getName() const;
		int getGrade() const;
		
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);


#endif
