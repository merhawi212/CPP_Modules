#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	PRINT_STATMEMNT("\nIterator:");
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	
	PRINT_STATMEMNT("\nsize of mutantstack=" << mstack.size() << " size of stack=" << s.size());
	{
		PRINT_STATMEMNT("\nReverse iterator:")
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
		++rit;
		--rit;
		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
	}
	{
		
		PRINT_STATMEMNT("\nConst iterator:");
		MutantStack<int>::const_iterator cit = mstack.begin();
		MutantStack<int>::const_iterator cite = mstack.end();
	
		while (cit != cite)
		{
			std::cout << *cit << std::endl;
			++cit;
		}
		
	}
	{
		
		PRINT_STATMEMNT("\nConst Reverse iterator:");
		MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
		MutantStack<int>::const_reverse_iterator crite = mstack.rend();
	
		while (crit != crite)
		{
			std::cout << *crit << std::endl;
			++crit;
		}
		
	}
/*
	{
		PRINT_STATMEMNT("\n Constructor:");
		MutantStack<int> a =  MutantStack<int>();
		a.push(2);
		a.push(3);
		MutantStack<int> b = a;
		MutantStack<int> c(a);
		PRINT_STATMEMNT("a="<< a.size());
		PRINT_STATMEMNT("b="<< b.size());
		PRINT_STATMEMNT("c="<< c.size());
	}

*/
	
	return 0;
}
