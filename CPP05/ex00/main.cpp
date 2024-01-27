#include "Bureaucrat.hpp"



int main()
{
	PRINT_STATEMENT("\n***Test 1: Create Object***\n");
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

	
	PRINT_STATEMENT("\n***Test 2: Incremente***\n");
	{
		Bureaucrat bureaucrat("Peter", 1);
		try {
				bureaucrat.incrementGrade();  
				PRINT_STATEMENT("Bureaucrat grade after incremented: " << bureaucrat);
			} catch (const Bureaucrat::GradeTooHighException& e) {
					std::cerr << e.what() << std::endl;
			}
	}
	
	PRINT_STATEMENT("\n***Test 3: Decrement***\n");
	{
		Bureaucrat bureaucrat("Sam", 150);
		try {
				bureaucrat.decrementGrade();  
				PRINT_STATEMENT("Bureaucrat grade after decremented: " << bureaucrat);
		} catch (const Bureaucrat::GradeTooLowException& e) {
				std::cerr << e.what() << std::endl;
		}
	}
	return 0;

}
