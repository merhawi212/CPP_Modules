#include "ClapTrap.hpp"

int main( void ) {

    ClapTrap b("B");
    b.setAttackDamage(2);
    b.attack("A");
    b.takeDamage(3);
    b.beRepaired(2);
    
    return 0;
}
