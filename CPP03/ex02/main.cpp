#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main( void ) {

    ScavTrap a("ARF-SC");
    a.guardGate();
    a.attack("enemy-a");
    a.takeDamage(15);
    a.beRepaired(20);

   std::cout << "\n***end of ScavTrap*** \n"<<std::endl;
   
    FragTrap b("ARF-FR");
    b.highFivesGuys();
    b.attack("enemy-b");
    b.takeDamage(31);
    b.beRepaired(15);

    
   
    
    return 0;
}
