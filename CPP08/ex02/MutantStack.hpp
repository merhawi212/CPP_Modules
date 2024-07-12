#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# define PRINT_STATMEMNT(statment)  std::cout << statment << std::endl;

# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <algorithm>
# include <iterator>
# include <stack> 


template <typename T >
class MutantStack : public std::stack<T>{
	private:
		std::stack<T> _stack; // The underlying stack container
		
	public:
		MutantStack(){}
		~MutantStack(){}
		MutantStack(const MutantStack<T> & src) : std::stack<T>(src){
			*this = src;
		}
		MutantStack &operator =(const MutantStack<T> & other){
			if (this != &other){
				this->_stack = other._stack;
			}
			return *this;
		}

		// Type aliases for iterators
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		
		// Iterator functions
		iterator begin() {
			return std::stack<T>::c.begin();
		}

		iterator end() {
			return std::stack<T>::c.end();
		}

		// const Iterator functions
		const_iterator begin() const {
			return std::stack<T>::c.begin();
		}

		const_iterator end() const {
			return std::stack<T>::c.end();
		}
		
		//Reverse Iterator functions
		reverse_iterator rbegin() {
			return std::stack<T>::c.rbegin();
		}

		reverse_iterator rend() {
			return std::stack<T>::c.rend();
		}

		// const reverse iterator functions
		const_reverse_iterator rbegin() const {
			return std::stack<T>::c.rbegin();
		}

		const_reverse_iterator rend() const {
			return std::stack<T>::c.rend();
		}
};


#endif 

