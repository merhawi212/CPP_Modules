#include "RPN.hpp"

int main(int argc, char **argv){

	if (argc != 2){
		std::cerr << "Invalid input: Usage ./RPN \"8 9 * 8 - 1 ... \"" << std::endl;
		 return 1;

	}
	do_rpn(argv[1]);
 	return 0;
}



