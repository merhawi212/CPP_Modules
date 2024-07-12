#include "Span.hpp"
/*
void display(std::vector<int> numbers){

	for (std::vector<int>::iterator iter = numbers.begin(); iter !=numbers.end(); ++iter){
		PRINT_STATMEMNT(*iter);
	}
}
*/

int main()
{
	try {

		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		PRINT_STATMEMNT("\nAfter adding one by one values");
		std::cout << "shortestSpan="<<sp.shortestSpan() << std::endl;
		std::cout << "longestSpan="<<sp.longestSpan() << std::endl;
		// display(sp.getNumbers());

		std::vector<int> range; 
		range.push_back(4);
		range.push_back(12);
		range.push_back(7);
		range.push_back(100000000);

		std::vector<int>::iterator begin = range.begin(); 
		std::vector<int>::iterator end = range.end(); 
		sp.addRange(begin, end);
		PRINT_STATMEMNT("\nAfter adding range of values");
		// display(sp.getNumbers());
		PRINT_STATMEMNT("shortestSpan="<<sp.shortestSpan());
		PRINT_STATMEMNT( "longestSpan="<<sp.longestSpan());
	

	}catch(const Span::SpaceAlreadyFullException & e){
		std::cerr << e.what() << std::endl;
	}catch(const Span::NoSpanFoundException & e){
		std::cerr << e.what() << std::endl;
	}catch(const Span::InsertionOutOfBoundException & e){
		std::cerr << e.what() << std::endl;
	}catch(const std::exception & e){
		std::cerr << e.what() << std::endl;
	}

	
	return 0;
}