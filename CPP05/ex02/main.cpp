#include "Bureaucrat.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


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

	PRINT_STATEMENT("\n***Test 2: Create ShrubberyCreationForm Object***\n");
	try{
			ShrubberyCreationForm shrubberyCreationForm("ShrubberyCreationForm");
			
			PRINT_STATEMENT(shrubberyCreationForm);
	}
	catch(const ShrubberyCreationForm::GradeTooHighException& e){
		  std::cerr << e.what() << std::endl;
	}catch(const ShrubberyCreationForm::GradeTooLowException& e){
		std::cerr << e.what() << std::endl;
	}

	PRINT_STATEMENT("\n***Test 3: Integration Bureaucrat with Shrubbery Creation Form testing***\n");
	try{
			Bureaucrat bureaucrat("Abrham Lincon", 130);
			PRINT_STATEMENT(bureaucrat);

			ShrubberyCreationForm form("ShrubberyCreationForm");
			PRINT_STATEMENT(form);

			try{
				form.beSigned(bureaucrat);
				PRINT_STATEMENT(form);
				form.execute(bureaucrat);

			}catch(const ShrubberyCreationForm::GradeTooLowException& e){
				std::cerr << e.what() << std::endl;
			}

			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
			
	}catch(const Bureaucrat::GradeTooHighException& e){
		  std::cerr << e.what() << std::endl;
	}catch(const Bureaucrat::GradeTooLowException& e){
		std::cerr << e.what() << std::endl;
	}
	catch(const ShrubberyCreationForm::GradeTooHighException& e){
		  std::cerr << e.what() << std::endl;
	}catch(const ShrubberyCreationForm::GradeTooLowException& e){
		std::cerr << e.what() << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	PRINT_STATEMENT("\n***Test 4: Integration Bureaucrat with Rbotomy testing***\n");
	try{
			Bureaucrat bureaucrat("Abrham Lincon", 30);
			PRINT_STATEMENT(bureaucrat);

			RobotomyRequestForm form("RobotomyRequestForm");
			PRINT_STATEMENT(form);

			try{
				form.beSigned(bureaucrat);
				PRINT_STATEMENT(form);
				form.execute(bureaucrat);

			}catch(const RobotomyRequestForm::GradeTooLowException& e){
				std::cerr << e.what() << std::endl;
			}

			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
			
	}catch(const Bureaucrat::GradeTooHighException& e){
		  std::cerr << e.what() << std::endl;
	}catch(const Bureaucrat::GradeTooLowException& e){
		std::cerr << e.what() << std::endl;
	}
	catch(const RobotomyRequestForm::GradeTooHighException& e){
		  std::cerr << e.what() << std::endl;
	}catch(const RobotomyRequestForm::GradeTooLowException& e){
		std::cerr << e.what() << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
PRINT_STATEMENT("\n***Test 5: Integration Bureaucrat with Presidential testing***\n");
	try{
			Bureaucrat bureaucrat("Abrham Lincon", 2);
			PRINT_STATEMENT(bureaucrat);

			PresidentialPardonForm form("PresidentialPardonForm");
			PRINT_STATEMENT(form);

			try{
				form.beSigned(bureaucrat);
				PRINT_STATEMENT(form);
				form.execute(bureaucrat);

			}catch(const PresidentialPardonForm::GradeTooLowException& e){
				std::cerr << e.what() << std::endl;
			}

			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
			
	}catch(const Bureaucrat::GradeTooHighException& e){
		  std::cerr << e.what() << std::endl;
	}catch(const Bureaucrat::GradeTooLowException& e){
		std::cerr << e.what() << std::endl;
	}
	catch(const PresidentialPardonForm::GradeTooHighException& e){
		  std::cerr << e.what() << std::endl;
	}catch(const PresidentialPardonForm::GradeTooLowException& e){
		std::cerr << e.what() << std::endl;
	}


	return 0;

}
