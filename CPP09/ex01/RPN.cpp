#include "RPN.hpp"

int performOperation(std::stack<int> &stack, char c){
	// Remember stuck is LIFO (Last In First Out), so the first top will be the second number inserted.
	int operand2 = stack.top(); // get the 1st top value, but it's at least the 2nd inserted value.
	stack.pop(); // remove 1st top value
	int operand1 = stack.top(); // get the 2nd top value
	stack.pop(); // remove 2st top value
	if (c == '+')
		stack.push(operand1 + operand2);
	if (c == '-')
		stack.push(operand1 - operand2);
	if (c == '*')
		stack.push(operand1 * operand2);
	if (c == '/'){
		if (operand2 == 0){
			std::cerr << "Error: zero division." << std::endl;
			return -1; // Exit if divider is zero
		}
		stack.push(operand1 / operand2);
	}
	return 0;
}

// stack must have one value at the end
bool isStackValid(std::stack<int> &stack){
	if (stack.empty()){
		// Invalid char
		std::cerr << "Error: Invalid input." << std::endl;
		return false; // Exit if the stack is empty
	}
	if (stack.size() > 1){
		// Insufficent Operators
		std::cerr << "Error: Invalid input." << std::endl;
		return false; // Exit if the stack has more than one number
	}
	return true;
}

int do_rpn(const std::string &arg){
	std::stack<int> stack;

	std::string::const_iterator it = arg.begin();
	
	while (it != arg.end()){
		char c = (*it++);
		if (std::isspace(c) != 0) //isspace will return 0 if the char is not whitespace, otherwise none zero value.
			continue; // Move to the next char

		if (std::isdigit(c)){
			int value = c - '0';
			stack.push(value); //store the value to stuck
		}else if (c == '+' || c == '-' || c == '*' || c == '/'){
			if (stack.size() < 2){
				//Insufficent numbers
				std::cerr << "Error: Invalid input." << std::endl;
				return -1; // Exit if there is invalid token sequence.
			}else{
				if (performOperation(stack, c) == -1)
					return -1; // Exit, something bad happening.
			}

		}else{
			std::cerr << "Error" << std::endl;
			return -1; // Exit if there is invalid token.
		}
	}
	if (!isStackValid(stack))
		return -1;
	PRINT_STATMEMNT(stack.top()); // Print the result to the standard ouput
	stack.pop(); // make stack empty
	return 0;
}

/*
// Function to display tokens
void displayTokens(std::deque<std::string> tokens){
	std::deque<std::string>::iterator it = tokens.begin();
  while (it != tokens.end())
   PRINT_STATMEMNT("output: "<< *it++);
}

*/