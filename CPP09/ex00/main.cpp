#include "BitcoinExchange.hpp"

int main(int argc, char **argv){

	if (argc != 2){
		  std::cerr << "Invalid input: Usage ./btc input.txt" << std::endl;
		 return 1;

	}
	btcExchange(argv[1]);
 
}



