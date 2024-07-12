#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define PRINT_STATMEMNT(statment)  std::cout << statment << std::endl;

# include <iostream>
# include <string>
# include <iterator>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib> // For strtod

	/*
	Instruction: 
		. The program name is btc.
		• Your program must take a file as argument.
		• Each line in this file must use the following format: "date | value".
		• A valid date will always be in the following format: Year-Month-Day.
		• A valid value must be either a float or a positive integer, between 0 and 1000 (exclusive probably).
		. You must use at least one container in your code to validate this exercise. 
		. You should handle possible errors with an appropriate error message.
		. Your program will use the value in your input file (input.txt).
		. Your program should display on the standard output the result of the value multiplied 
			by the exchange rate according to the date indicated in your database (given, data.csv).
		. If the date used in the input does not exist in your DB then you must use the closest date contained in your DB.
		. Be careful to use the lower date and not the upper one.

	Test:
		$> head input.txt
			date | value
			2011-01-03 | 3
			2011-01-03 | 2
			2011-01-03 | 1
			2011-01-03 | 1.2
			2011-01-09 | 1
			2012-01-11 | -1
			2001-42-42
			2012-01-11 | 1
			2012-01-11 | 2147483648
		$> ./btc
		Error: could not open file.
		$> ./btc input.txt
		2011-01-03 => 3 = 0.9
		2011-01-03 => 2 = 0.6
		2011-01-03 => 1 = 0.3
		2011-01-03 => 1.2 = 0.36
		2011-01-09 => 1 = 0.32
		Error: not a positive number.
		Error: bad input => 2001-42-42
		2012-01-11 => 1 = 7.1
		Error: too large a number.
	*/

/* Function(s) in DB.cpp*/
int readDB(std::map<time_t, double> &exchangeRate_db);

/* Function(s) in BitcoinExchange.cpp*/
int btcExchange(const std::string file);

/*Helper functions in Utils.cpp*/
time_t toEpoch(const std::string &dateStr);
bool isWhitespace(const std::string& str);
std::string trim(const std::string &str);
void toLowercase(std::string& str);

#endif 

