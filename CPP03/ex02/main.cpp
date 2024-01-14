#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main( void ) {

    
  std::cout << "\n***Start of ClapTrap*** \n"<<std::endl;
    ClapTrap b("B");
	ClapTrap a("A");
	
	ClapTrap c(a);
    b.attack("A");
    b.takeDamage(3);
    b.beRepaired(2);

	std::cout << "\n-----------------------------------"  << std::endl;
	std::cout << "Attac damage: " << b.getAttackDamage() << std::endl;
	std::cout << "enrgy points: " << b.getEnergyPoints() << std::endl;
	std::cout << "hit points: " << b.getHitPoints() << std::endl;
	std::cout << "-----------------------------------"  << std::endl;

	std::cout << "\n***Start of ScavTrap*** \n"<<std::endl;
    ScavTrap d("ARF-SC");
	ScavTrap e("ARF-SB");
	ScavTrap f(e);
	f = d;
    d.guardGate();
   	d.attack("enemy-d");
    d.takeDamage(10);
    d.beRepaired(11);
    
	std::cout << "\n***Start of FragTrap*** \n"<<std::endl;
   
    FragTrap g("ARF-FR");
    g.highFivesGuys();
    g.attack("enemy-g");
    g.takeDamage(31);
    g.beRepaired(15);
	std::cout << "\n***end of all and start of destructor*** \n"<<std::endl;
    return 0;
}
