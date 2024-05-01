#ifndef AFORM_HPP
#define  AFORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

# define LOWEST_GRADE 150
# define HIGHEST_GRADE 1
# define PRINT_STATEMENT(statement) std::cout << statement << std::endl

class Bureaucrat;

class AForm{
    private:
        const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _signed;

			
		void validateGrade(const int grade);
		
	protected:
		AForm(void); // Change access level to protected

    public:
		// Orthodox connonical form
		virtual ~AForm();
        AForm(const AForm& src);
        AForm &operator =(const AForm &another);

		// custom constructor
		AForm(const std::string& name, const int gradeToSign, const int gradeToExecute);

		class GradeTooHighException : public std::exception {
				public:
					virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
				public:
					virtual const char* what() const throw();
		};

		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;


		// getters
		std::string getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		
};

std::ostream &operator<<(std::ostream &out, const AForm &form);


#endif // AFORM_HPP
