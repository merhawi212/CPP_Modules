#include "Contact.hpp"

Contact::Contact(){

}

Contact::~Contact(){

}

void Contact::setfirstName(std::string first_Name){
		this->_firstName = first_Name;
	}
void Contact::setlastName(std::string last_Name){
	this->_lastName = last_Name;
}
void Contact::setnickName(std::string nick_Name){
	this->_nickName = nick_Name;
}
void Contact::setphoneNumber(std::string phone_Number){
	this->_phoneNumber = phone_Number;
}
void Contact::setdarkestSecret(std::string darkest_Secret){
	this->_darkestSecret = darkest_Secret;
}

std::string Contact::getFirstName()  {
    return this->_firstName;
}

std::string Contact::getLastName()  {
    return this->_lastName;
}

std::string Contact::getNickName()  {
    return this->_nickName;
}

std::string Contact::getPhoneNumber()  {
    return this->_phoneNumber;
}

std::string Contact::getDarkestSecret()  {
    return this->_darkestSecret;
}


