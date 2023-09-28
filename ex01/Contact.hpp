#ifndef PHONEBOOK 
#define PHONEBOOK

#include <iostream>
#include <string>

class Contact{

	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;

	public:
		Contact();
		~Contact();
		void setfirstName(std::string first_Name);
		void setlastName(std::string last_Name);
		void setnickName(std::string nick_Name);
		void setphoneNumber(std::string phone_Number);
		void setdarkestSecret(std::string darkest_Secret);
		
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();

};
#endif  
