#include "ScavTrap.hpp"

int main( void ) {

	std::cout << "---------start of ClapTrap--------------------"  << std::endl;
    ClapTrap b("B");
	ClapTrap a("A");
	
	ClapTrap c(a);
    b.attack("A");
    b.takeDamage(3);
    b.beRepaired(2);

	std::cout << "\n-----------------------------------"  << std::endl;
	std::cout << "Attack damage: " << b.getAttackDamage() << std::endl;
	std::cout << "energy points: " << b.getEnergyPoints() << std::endl;
	std::cout << "hit points: " << b.getHitPoints() << std::endl;
	std::cout << "-----------------------------------"  << std::endl;

	std::cout << "\n-------start of ScavTrap---------------"  << std::endl;
    ScavTrap d("ARF-SC");
	ScavTrap e("ARF-SB");
	ScavTrap f(e);
	f = d;
    d.guardGate();
   	d.attack("enemy-d");
    d.takeDamage(10);
    d.beRepaired(11);
    std::cout << "\n-------end of task and start destructor---------------"  << std::endl;
    return 0;
}
