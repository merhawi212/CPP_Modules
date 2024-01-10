#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) :ClapTrap(name)
                     
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;

    std::cout << "FragTrap " << name <<" constructor called!"  << std::endl;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap " << this->_name <<" deconstructor called!" << std::endl;

}

void FragTrap::attack(const std::string& target){
    if (this->_energyPoints <= 0){
        std::cout << "FragTrap "<<  this->_name <<"has no energy points left!" << std::endl;
        return;
    }
    this->_energyPoints -= 1;
    std::cout << "FragTrap attacks "<< target << ", causing " 
                << this->_attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(){
    std::cout << "FragTrap "<< this->_name <<" hi fives everyone." << std::endl;
}
