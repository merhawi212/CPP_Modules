#ifndef PHONEBOOK 
#define PHONEBOOK

#include <iostream>
#include <string>

class Contact{

	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		Contact();
		~Contact();

};
#endif  
