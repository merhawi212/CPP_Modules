#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	PRINT_STATEMENT("\n***Test 1: Create bureaucrat Object***\n");
	try{
			Bureaucrat bureaucrat("John Smith", 5);
			
			PRINT_STATEMENT(bureaucrat);
			bureaucrat.incrementGrade();
			PRINT_STATEMENT(bureaucrat);
			bureaucrat.decrementGrade();
			PRINT_STATEMENT(bureaucrat);

	}catch(const Bureaucrat::GradeTooHighException& e){
		  std::cerr << e.what() << std::endl;
	}catch(const Bureaucrat::GradeTooLowException& e){
		std::cerr << e.what() << std::endl;
	}

	PRINT_STATEMENT("\n***Test 2: Create Form Object***\n");
	try{
			Form form("ShrubberyCreationForm", 25, 10);
			
			PRINT_STATEMENT(form);
	}
	catch(const Form::GradeTooHighException& e){
		  std::cerr << e.what() << std::endl;
	}catch(const Form::GradeTooLowException& e){
		std::cerr << e.what() << std::endl;
	}

	PRINT_STATEMENT("\n***Test 3: Integration testing***\n");
	try{
			Bureaucrat bureaucrat("Abrham Lincon", 20);
			PRINT_STATEMENT(bureaucrat);

			Form form("RobotomyRequestForm", 25, 10);
			PRINT_STATEMENT(form);

			try{
				form.beSigned(bureaucrat);
				PRINT_STATEMENT(form);

			}catch(const Form::GradeTooLowException& e){
				std::cerr << e.what() << std::endl;
			}

			bureaucrat.signForm(form);
			
	}catch(const Bureaucrat::GradeTooHighException& e){
		  std::cerr << e.what() << std::endl;
	}catch(const Bureaucrat::GradeTooLowException& e){
		std::cerr << e.what() << std::endl;
	}
	catch(const Form::GradeTooHighException& e){
		  std::cerr << e.what() << std::endl;
	}catch(const Form::GradeTooLowException& e){
		std::cerr << e.what() << std::endl;
	}

	
	return 0;

}
