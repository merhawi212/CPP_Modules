#include "PhoneBook.hpp"
PhoneBook::PhoneBook(){
	this->_numberOfContacts = 0;

}
PhoneBook::~PhoneBook(){

}

std::string PhoneBook::getinput(int index, std::string str, std::string input)
{
	
	while(!std::cin.eof())
	{
		std::cout << "Enter "<< input <<": ";
		if (!std::getline(std::cin, str))
            break;
		str.erase(0, str.find_first_not_of(" \t"));
        str.erase(str.find_last_not_of(" \t") + 1);
		if (str == "")
			continue ;
		else if (input == "FirstName")
			this->_contact[index % 8].setfirstName(str);
		else if (input == "LastName")
			this->_contact[index % 8].setlastName(str);
		else if (input == "NickName")
			this->_contact[index % 8].setnickName(str);
		else if (input == "PhoneNumber")
			this->_contact[index % 8].setphoneNumber(str);
		else if (input == "DarkestSecret")
			this->_contact[index % 8].setdarkestSecret(str);
		break ;	
	}
	str = "";
	return str;
}

void PhoneBook::addContact(){
	int index = this->_numberOfContacts % 8;
	if (this->_numberOfContacts <= 7)
		std::cout << "++ Add "<< index + 1 << " contact ++" <<std::endl;
	else
		std::cout << "++ update contact "<< this->_contact[index % 8].getFirstName() << " by new contact ++" <<std::endl;
	std::string str = "";
	str = getinput(index, str, "FirstName");
	str = getinput(index, str, "LastName");
	str = getinput(index, str, "NickName");
	str = getinput(index, str, "PhoneNumber");
	str = getinput(index, str, "DarkestSecret");
	if (std::cin.eof())
		return;
	std::cout <<"Congrats! contact " << this->_contact[index % 8].getFirstName()
					 << " is added to phonebook successfully." << std::endl;
	this->_numberOfContacts++;
	this->promptUser("adding");
}

void PhoneBook::searchContact() {
   if (this->_numberOfContacts == 0) {
        std::cout << "No contacts to display!" << std::endl;
        return;
    }
    this->viewContacts();
	this->fetchContact();
}

void PhoneBook::fetchContact()
{
	int index;

	while(true)
	{
		std::cout << "Enter the index of the contact you want to display: ";
		if (!(std::cin >> index))
		{
			this->clearStream();
			std::cout << "Invalid value input" << std::endl;
			continue ;
		}
		if (std::cin.eof())
			return;
		if (index >= 0 && index < _numberOfContacts) {
			std::cout << "\n++++++++Contact #"<<index + 1 <<"++++++++" << std::endl;
			this->_contact[index].displayContactDetails();
		} else {
			std::cout << "Invalid index. No contact found at that index." << std::endl;
			continue ;
		}
		break ;
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
	if (!(std::cin >> num) || !(num >= 0 && num <= 1))
	{
		if (std::cin.eof())
			return;
		this->clearStream();
		std::cout << "Please enter valid input from the options" << std::endl;
		this->promptUser(type);
	}
	this->clearStream();
	if (std::cin.eof())
		return;
	if (num == 0)
		return ;
	else if (num == 1 && type == "adding")
		addContact();
	else if (num == 1 && type == "searching")
		this->fetchContact();
}

void PhoneBook::viewContacts()
{
	int num_of_contacts = this->_numberOfContacts >= 8? 8:this->_numberOfContacts;
	_repeatedString = std::string(45, '-');
	std::cout << _repeatedString << std::endl;

	std::cout << std::right << std::setw(10) << "|     Index" << "|"
              << std::setw(10) << "FirstName" << "|"
              << std::setw(10) << "LastName" << "|"
              << std::setw(10) << "Nickname" << "|" 
	<< std::endl;
	_repeatedString = std::string(45, '-');
	std::cout << _repeatedString << std::endl;
	for (int i = 0; i < num_of_contacts; i++)
	{
		std::cout << std::right
		<< std::setw(10) <<"|         " << i + 1 << "|"
		<< std::setw(10) << (_contact[i].getFirstName().length() > 10 ? 
			(_contact[i].getFirstName().substr(0, 9) + ".") : _contact[i].getFirstName()) << "|"

		<< std::setw(10) << (_contact[i].getLastName().length() > 10 ? 
			(_contact[i].getLastName().substr(0, 9) + ".") : _contact[i].getLastName()) << "|"

		<< std::setw(10) << (_contact[i].getNickName().length() > 10 ? 
			(_contact[i].getNickName().substr(0, 9) + ".") : _contact[i].getNickName()) << "|"
		<< std::endl;
		_repeatedString = std::string(45, '-');
		std::cout << _repeatedString << std::endl;
	}
}