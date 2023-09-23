#include "PhoneBook.hpp"
PhoneBook::PhoneBook(){

}
#include <iostream>
int main () {
	PhoneBook phoneBook;
	Contact contact;
	std::string input;
	std::cout << "Please enter a commad -> ADD or SEARCH or EXIT: ";
	while (1)
	{
		std::getline(std::cin, input);
		if (input == "ADD")
			AddContact();
		if (input == "SEARCH")
			searchContact();
		if (input == "EXIT")
			exitProgram();

	}
	return 0;
}