#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#define PRINT_STATMEMNT(statment)  std::cout << statment << std::endl;

# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <algorithm>
# include <iterator>
# include <numeric> 

#define PRINT_STATMEMNT(statment)  std::cout << statment << std::endl;

class Span{
	private:
		std::vector<int>   _numbers;
		std::size_t _maxCapacity;
		Span();
	public:
		
		~Span();
		Span(const Span & src);
		Span &operator =(const Span & other);

		Span(const unsigned int size);
		
		class SpaceAlreadyFullException : public std::exception{
			public:
				virtual const char * what () const throw ();
		};
		class NoSpanFoundException : public std::exception{
			public:
				virtual const char * what () const throw ();
		};
		class InsertionOutOfBoundException : public std::exception{
			public:
						const char * what () const throw ();
		};
		void addNumber(const int toAdd);
		
		void addRange(std::vector<int>::iterator& begin, std::vector<int>::iterator& end);
		int shortestSpan();
		int longestSpan();

		int getMaxCapacity() const;
		std::vector<int> getNumbers() const;
};
#endif //EASYFIND_HPP

