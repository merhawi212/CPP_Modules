#include "ScavTrap.hpp"

int main( void ) {

    ScavTrap a("ARF-SC");
    a.guardGate();
    a.attack("enemy-a");
    a.takeDamage(10);
    a.beRepaired(11);
    
    return 0;
}
