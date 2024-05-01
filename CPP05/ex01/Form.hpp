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
		bool _signed;

		void validateGrade(const int grade);
		
		Form(void);

    public:
		// Orthodox connonical form
		~Form();
        Form(const Form& src);
        Form &operator =(const Form &another);

		// custom constructor
		Form(const std::string& name, const int gradeToSign, const int gradeToExecute);

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
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		
};

std::ostream &operator<<(std::ostream &out, const Form &form);


#endif // FORM_HPP
