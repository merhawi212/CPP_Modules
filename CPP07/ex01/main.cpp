
#include "iter.hpp"



int main( void ) {
	
	PRINT_STATMENT("Test 0: int array");
	int a[] = {10, 20, 30};
	size_t length = 3;
	iter(a, length, print);

	PRINT_STATMENT("\nTest 1: char array");
	char b[] = {'a', 'b', 'c', 'd'};
	size_t length1 = 4;
	iter(b, length1, print);

	PRINT_STATMENT("\nTest 2: string array");
	std::string c[] = {"C", "CPP", "JAV"};
	size_t length2 = 3;
	iter(c, length2, print);

	PRINT_STATMENT("\nTest 3: double array");
	double d[] = {2.02,  10.6, -20.87};
	size_t length3 = 3;
	iter(d, length3, print);

	return 0;
}