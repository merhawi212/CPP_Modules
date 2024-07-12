#include "PmergeMe.hpp"

int main(int argc, char **argv){

	if (argc < 2){
		 std::cerr << "Invalid input: Usage ./PmergeMe num_1 num_2 ...num_n" << std::endl;
		 return 1;

	}
	
	do_pmergeMe(argc, argv);

 	return 0;
}



