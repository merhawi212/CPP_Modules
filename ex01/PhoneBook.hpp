#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define RESET_COLOR "\x1b[0m"
#define RED_TEXT "\x1b[31m"
#define GREEN_TEXT "\x1b[32m"
#define YELLOW_TEXT "\x1b[33m"
#define BLUE_TEXT "\x1b[34m"
#define ORANGE_TEXT "\x1b[38;5;208m"


class PhoneBook {
	private:
		Contact _contact[8];
		int _numberOfContacts;
		std::string _repeatedString;
		void _viewContacts();
		void _clearStream();
		void _promptUser(std::string type);
		void _fetchContact();
		std::string _getinput(int index, std::string str, std::string input);

	public:
		PhoneBook();
		~PhoneBook();
		void addContact();
		void searchContact(); 

};

#endif
