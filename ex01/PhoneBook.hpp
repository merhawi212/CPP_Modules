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

public:
    PhoneBook();
    ~PhoneBook();
    void addContact();
    void searchContact(); 
	void headerFormat();
	void displayContactDetails(Contact contact, int i);
	void fetchContact();
	void promptUser(std::string type);

};

#endif
