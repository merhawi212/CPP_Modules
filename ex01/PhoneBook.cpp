#include "PhoneBook.hpp"
PhoneBook::PhoneBook(){
	this->_numberOfContacts = 0;

}
PhoneBook::~PhoneBook(){

}

std::string PhoneBook::_getinput(int index, std::string str, std::string input)
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

void PhoneBook::_fetchContact()
{
	int index;
	int temp = this->_numberOfContacts >= 8? 8:this->_numberOfContacts;

	while(!std::cin.eof())
	{
		std::cout << "Enter the index of the contact you want to display: ";
		
		if (!(std::cin >> index))
		{
			if (std::cin.eof())
				return;
			this->_clearStream();
			std::cout << RED_TEXT"Invalid value input" RESET_COLOR << std::endl;
			continue ;
		}
		if (index >= 0 && index < temp) {
			std::cout << BLUE_TEXT"\n++++++++Contact #"<<index + 1 <<"++++++++" RESET_COLOR<< std::endl;
			this->_contact[index].displayContactDetails();
		} else {
			std::cout << RED_TEXT"Invalid index. No contact found at that index." RESET_COLOR<< std::endl;
			continue ;
		}
		break ;
	}
	_promptUser("searching");
}

void PhoneBook::_clearStream()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void PhoneBook::_promptUser(std::string type)
{
	int num = -1;

	if (std::cin.eof())
			return;
	std::cout <<YELLOW_TEXT "Please enter 0 -> 'return back', 1 -> 'to continue " << type << "': " RESET_COLOR;
	if (!(std::cin >> num) || !(num >= 0 && num <= 1))
	{
		if (std::cin.eof())
			return;
		this->_clearStream();
		std::cout << RESET_COLOR"Please enter valid input from the options" RESET_COLOR<< std::endl;
		this->_promptUser(type);
		return ;
	}
	this->_clearStream();
	if (std::cin.eof() && num == 0)
		return ;
	else if (num == 1 && type == "adding")
		addContact();
	else if (num == 1 && type == "searching")
		this->_fetchContact();
}


void PhoneBook::addContact(){
	int index = this->_numberOfContacts % 8;
	if (this->_numberOfContacts <= 7)
		std::cout << BLUE_TEXT"++ Add "<< index + 1 << " contact ++" RESET_COLOR<<std::endl;
	else
	{
		std::cout << ORANGE_TEXT"++ Attention! You are updating contact "
			<< this->_contact[index % 8].getFirstName() << " by new contact ++" RESET_COLOR<<std::endl;
	}
	std::string str = "";
	str = _getinput(index, str, "FirstName");
	str = _getinput(index, str, "LastName");
	str = _getinput(index, str, "NickName");
	str = _getinput(index, str, "PhoneNumber");
	str = _getinput(index, str, "DarkestSecret");
	if (std::cin.eof())
		return;
	std::cout <<GREEN_TEXT"Congrats! contact " << this->_contact[index % 8].getFirstName()
					 << " is added to phonebook successfully." RESET_COLOR<< std::endl;
	this->_numberOfContacts++;
	this->_promptUser("adding");
}

void PhoneBook::searchContact() {
   if (this->_numberOfContacts == 0) {
        std::cout << RED_TEXT"No contacts to display!" RESET_COLOR<< std::endl;
        return;
    }
    this->_viewContacts();
	this->_fetchContact();
}



void PhoneBook::_viewContacts()
{
	int num_of_contacts = this->_numberOfContacts >= 8? 8:this->_numberOfContacts;
	this->_repeatedString = std::string(45, '-');
	std::cout << this->_repeatedString << std::endl;

	std::cout << std::right << std::setw(10) <<BLUE_TEXT"|     Index" << "|"
              << std::setw(10) << "FirstName" << "|"
              << std::setw(10) << "LastName" << "|"
              << std::setw(10) << "Nickname" << "|" RESET_COLOR
	<< std::endl;
	this->_repeatedString = std::string(45, '-');
	std::cout << this->_repeatedString << std::endl;
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
		this->_repeatedString = std::string(45, '-');
		std::cout << this->_repeatedString << std::endl;
	}
}
