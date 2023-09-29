#include "PhoneBook.hpp"
PhoneBook::PhoneBook(){
	this->_numberOfContacts = 0;

}
PhoneBook::~PhoneBook(){

}

void PhoneBook::addContact(){
	std::string str = "";
	if (this->_numberOfContacts <= 7)
		std::cout << "++ Add "<< this->_numberOfContacts + 1 << " contact ++" <<std::endl;
	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter FirstName: ";
		if (!std::getline(std::cin, str))
            break;
		std::cout << "hey ["<< str << "]"<< std::endl;
		this->_contact[this->_numberOfContacts % 8].setfirstName(str);
	}
	str = "";
	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter LastName: ";
		if (!std::getline(std::cin, str))
            break;
		this->_contact[this->_numberOfContacts % 8].setlastName(str);
	}
	str = "";
	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter NickName: ";
		if (!std::getline(std::cin, str))
            break;
		this->_contact[this->_numberOfContacts % 8].setnickName(str);
	}
	str = "";
	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter PhoneNumber: ";
		if (!std::getline(std::cin, str))
            break;
		this->_contact[this->_numberOfContacts % 8].setphoneNumber(str);
	}
	str = "";
	while(!std::cin.eof() && str == "")
	{
		std::cout << "Enter Darkest Secret: ";
		if (!std::getline(std::cin, str))
            break;
		this->_contact[this->_numberOfContacts % 8].setdarkestSecret(str);
	}
	if (std::cin.eof())
		return;
	std::cout <<"Congrats! contact " << this->_contact[this->_numberOfContacts % 8].getFirstName()
					 << " is added to phonebook successfully." << std::endl;
	this->_numberOfContacts++;
	std::cin.clear();
	this->promptUser("adding");
}

void PhoneBook::searchContact() {
   if (this->_numberOfContacts == 0) {
        std::cout << "No contacts to display!" << std::endl;
        return;
    }
    headerFormat();
	for (int i = 0; i < this->_numberOfContacts; i++)
		displayContactDetails(_contact[i], i);
		
	fetchContact();
}

void PhoneBook::fetchContact()
{
	int index;

	std::cout << "Enter the index of the contact you want to display: ";
	std::cin >> index;
	if (std::cin.eof())
		return;
	if (index >= 0 && index < _numberOfContacts) {
		headerFormat();
		displayContactDetails(_contact[index], index);
	} else {
		std::cout << "Invalid index. No contact found at that index." << std::endl;
	}
	promptUser("searching");
}

void PhoneBook::clearStream()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void PhoneBook::promptUser(std::string type)
{
	int num = -1;

	std::cout << "Please enter 0 -> 'return back', 1 -> 'to continue " << type << "': ";
	std::cin >> num;
	if (std::cin.eof())
		return;
	if (num == 0)
		return ;
	else if (num == 1 && type == "adding"){
		this->clearStream();
		addContact();
	}
	else if (num == 1 && type == "searching")
	{
		this->clearStream();
		this->fetchContact();
	}
	else
	{
		std::cout << "Please enter valid input from the options" << std::endl;
		this->clearStream();
		this->promptUser();
	}
}
void PhoneBook::displayContactDetails(Contact contact, int i)
{
	std::cout << std::right
		<< std::setw(10) <<"|         " << i + 1 << "|"
		<< std::setw(10) << (contact.getFirstName().length() > 10 ? 
			(contact.getFirstName().substr(0, 9) + ".") : contact.getFirstName()) << "|"

		<< std::setw(10) << (contact.getLastName().length() > 10 ? 
			(contact.getLastName().substr(0, 9) + ".") : contact.getLastName()) << "|"

		<< std::setw(10) << (contact.getNickName().length() > 10 ? 
			(contact.getNickName().substr(0, 9) + ".") : contact.getNickName()) << "|"
	<< std::endl;
	_repeatedString = std::string(45, '-');
	std::cout << _repeatedString << std::endl;
}

void PhoneBook::headerFormat()
{
	_repeatedString = std::string(45, '-');
	std::cout << _repeatedString << std::endl;
	std::cout << std::right << std::setw(10) << "|     Index" << "|"
              << std::setw(10) << "FirstName" << "|"
              << std::setw(10) << "LastName" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
	_repeatedString = std::string(45, '-');
	std::cout << _repeatedString << std::endl;
}