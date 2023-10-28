#include "Weapon.hpp"
#include "HumanA.hpp"
int main(){
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		// std::cout <<club.getType();
		bob.attack();
	}

	return 0;
}