#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#define PRINT_STATMENT(statment) std::cout << statment << std::endl;

template <class T>

class Array{
	private:
		T* _array;
		size_t _size;

	public:
	// orthodox canonical form
		Array(void);
		~Array(void);
		Array(const Array &src);
		Array &operator = (const Array& another);

		Array(size_t n);

		class IndexOutOfBoundException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
	
		size_t size() const;
		T &operator [](size_t n) const;
};

template <class T>
std::ostream& operator<<( std::ostream& out, const Array<T>& array );

// include the template implementation file
#include "Array.tpp"

#endif //ARRAY_HPP