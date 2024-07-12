#ifndef RPN_HPP
#define RPN_HPP

#define PRINT_STATMEMNT(statment)  std::cout << statment << std::endl;

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

	/*
	Instruction: 
		. The program name is RPN.
		• Your program must take an inverted Polish mathematical expression as an argument.
		• The numbers used in this operation and passed as arguments will always be less
		than 10. The calculation itself but also the result do not take into account this rule.
		• Your program must process this expression and output the correct result on the
		standard output.
		• If an error occurs during the execution of the program an error message should be
		displayed on the standard output.
		• Your program must be able to handle operations with these tokens: "+ - / *".
	*/

int do_rpn(const std::string &arg);

#endif 

