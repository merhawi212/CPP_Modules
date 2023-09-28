#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook {
private:
    Contact _contact[8];
    int _numberOfContacts;

public:
    PhoneBook();
    ~PhoneBook();
    void addContact();
    void searchContact(); 
};

#endif
