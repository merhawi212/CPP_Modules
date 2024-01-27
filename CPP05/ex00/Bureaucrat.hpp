#ifndef BUREAUCRAT_HPP
#define  BUREAUCRAT_HPP

#include <iostream>
#include <string>

# define PRINT_STATEMENT(statement) std::cout << statement << std::endl

class Bureaucrat{
    private:
        const std::string _name;
		int _grade;
		//setters
		void setGrade(int newGrade);

    public:

		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();

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

		// getters
		std::string getName() const;
		int getGrade() const;

		
		
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);


#endif
