#include "ClapTrap.hpp"

int main( void ) {

    ClapTrap b("B");
    b.attack("A");
    b.takeDamage(3);
    b.beRepaired(2);
    
    return 0;
}
