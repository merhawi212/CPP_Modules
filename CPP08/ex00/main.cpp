#include "easyfind.hpp"

int main(){


	std::vector<int> vec;
    // Add elements to the vector using push_back
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

	int number = 0;
	int result;
	try {
		
		result = easyfind(vec, number);
		PRINT_STATMEMNT("Result = "<<result);
	}catch(const NumberNotFoundException& e){
		std::cerr << e.what() << std::endl;
	}


}