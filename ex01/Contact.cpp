#include "Contact.hpp"

Contact::Contact(){

	setfirstName(string first_Name){
		firstName = first_Name;
	}
	setlastName(string last_Name){
		lastName = last_Name;
	}
	setnickName(string nick_Name){
		nickName = nick_Name;
	}
	setphoneNumber(string phone_Number){
		phoneNumber = phone_Number;
	}
	setdarkestSecret(string darkest_Secret){
		darkestSecret = darkest_Secret;
	}

	getfirstName(){
		return firstName;
	}
	getlastName(){
		return lastName;
	}
	getnickName(){
		return nickName;
	}
	getphoneNumber(){
		return phoneNumber;
	}
	getdarkestSecret(){
		return darkestSecret;
	}
}

int main()
{
	
}