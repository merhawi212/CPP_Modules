#ifndef FORM_HPP
#define  FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

# define LOWEST_GRADE 150
# define HIGHEST_GRADE 1
# define PRINT_STATEMENT(statement) std::cout << statement << std::endl

class Bureaucrat;

class Form{
    private:
        const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _isSigned;

			
		void validateGrade(const int grade);

    public:

		Form(const std::string& name, const int gradeToSign, const int gradeToExecute);
		~Form();

		class GradeTooHighException : public std::exception {
				public:
					virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
				public:
					virtual const char* what() const throw();
		};

		void beSigned(Bureaucrat &bureaucrat);

		// getters
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		
};

std::ostream &operator<<(std::ostream &out, const Form &Form);


#endif // FORM_HPP
