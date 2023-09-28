#include "PhoneBook.hpp"
PhoneBook::PhoneBook(){
	this->_numberOfContacts = 0;

}
PhoneBook::~PhoneBook(){

}

void PhoneBook::addContact(){
	std::string input = "";
	if (this->_numberOfContacts <= 7)
		std::cout << "add "<< this->_numberOfContacts + 1 << " th contact";
	while(input == "")
	{

		std::cout << "Enter FirstName: ";
		std::getline(std::cin, input);
		this->_contact[this->_numberOfContacts % 8].setfirstName(input);
	}
	input = "";
	while(input == "")
	{

		std::cout << "Enter LastName: ";
		std::getline(std::cin, input);
		this->_contact[this->_numberOfContacts % 8].setlastName(input);
	}
	input = "";
	while(input == "")
	{

		std::cout << "Enter NickName: ";
		std::getline(std::cin, input);
		this->_contact[this->_numberOfContacts % 8].setnickName(input);
	}
	input = "";
	while(input == "")
	{

		std::cout << "Enter PhoneNumber: ";
		std::getline(std::cin, input);
		this->_contact[this->_numberOfContacts % 8].setphoneNumber(input);
	}
	input = "";
	while(input == "")
	{

		std::cout << "Enter Darkest Secret: ";
		std::getline(std::cin, input);
		this->_contact[this->_numberOfContacts % 8].setdarkestSecret(input);
	}
	std::cout << this->_contact[this->_numberOfContacts % 8].getFirstName();
	this->_numberOfContacts++;
}

void PhoneBook::searchContact() {
    // Your implementation here
}