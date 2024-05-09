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

	
	PRINT_STATEMENT("\n***Test 2: Increment***\n");
	{
		
		try {
				Bureaucrat bureaucrat("Peter", 1);
				bureaucrat.incrementGrade();  
				PRINT_STATEMENT("Bureaucrat grade after incremented: " << bureaucrat);
			} catch (const Bureaucrat::GradeTooHighException& e) {
					std::cerr << e.what() << std::endl;
			}
	}
	
	PRINT_STATEMENT("\n***Test 3: Decrement***\n");
	{
		
		try {
				Bureaucrat bureaucrat("Sam", 140);
				bureaucrat.decrementGrade();  
				PRINT_STATEMENT("Bureaucrat grade after decremented: " << bureaucrat);
				// Bureaucrat b2(bureaucrat);
				// Bureaucrat bureaucrat3("Sam", 10);
				// b2 = bureaucrat3;
				// PRINT_STATEMENT("B2: " <<b2);
				// PRINT_STATEMENT("B3: " <<bureaucrat3);
		} catch (const Bureaucrat::GradeTooLowException& e) {
				std::cerr << e.what() << std::endl;
		}
	}
	return 0;

}
