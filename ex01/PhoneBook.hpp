#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip> 
#include <string>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact _contact[8];
		int _numberOfContacts;
		std::string _repeatedString;
		void viewContacts();
		void clearStream();
		void promptUser(std::string type);
		void fetchContact();
		std::string getinput(int index, std::string str, std::string input);

	public:
		PhoneBook();
		~PhoneBook();
		void addContact();
		void searchContact(); 

};

#endif
