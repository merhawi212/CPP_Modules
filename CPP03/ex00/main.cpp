#include "ClapTrap.hpp"

int main( void ) {
	std::cout << "---------start of ClapTrap--------------"  << std::endl;
    ClapTrap b("B");
	ClapTrap a("A");

	b = a;
	ClapTrap c(b);
    b.attack("A");
    b.takeDamage(2);
    b.beRepaired(-10);

	std::cout << "\n-----------------------------------"  << std::endl;
	std::cout << "Attac damage: " << b.getAttackDamage() << std::endl;
	std::cout << "energy points: " << b.getEnergyPoints() << std::endl;
	std::cout << "hit points: " << b.getHitPoints() << std::endl;
	std::cout << "-----------------------------------"  << std::endl;
    std::cout << "---------end of job and start of destructor--------------"  << std::endl;
    return 0;
}
