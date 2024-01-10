#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) :ClapTrap(name)
                     
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;

    std::cout << "ScavTrap " << name <<" constructor   called!"  << std::endl;
}


ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap " << this->_name <<" deconstructor called!" << std::endl;

}


void ScavTrap::attack(const std::string& target){
    if (this->_energyPoints <= 0){
        std::cout << "ScavTrap "<< this->_name <<" has no energy points left!" << std::endl;
        return;
    }
    this->_energyPoints -= 1;
    std::cout << "ScavTrap attacks "<< target << ", causing " 
                << this->_attackDamage << " points of damage!" << std::endl;
}


void ScavTrap::guardGate(){
    std::cout << "ScavTrap "<< this->_name <<" is now in Gate keeper mode" << std::endl;
}
