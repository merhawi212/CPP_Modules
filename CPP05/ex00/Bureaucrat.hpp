#ifndef BUREAUCRAT_HPP
#define  BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat{
    private:
        const std::string _name;
		int _grade;

    public:

		Bureaucrat(cont std:strin& name, int grade);
		~Bureaucrat();

		void GradeTooHighException();
		void GradeTooLowException();

		void decrementGrade();
		void incrementGrade();

		// getters
		std::string getName() const;
		int getGrade() const;
		
};

#endif
