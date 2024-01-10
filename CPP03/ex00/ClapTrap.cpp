#include "ClapTrap.hpp"


ClapTrap::ClapTrap(const std::string& name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
        std::cout << "ClapTrap " << this->_name <<" constractor called!"  << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap " << this->_name <<" deconstractor called!" << std::endl;

}

void ClapTrap::attack(const std::string& target){
    if (this->_energyPoints <= 0){
        std::cout << "ClapTrap has no energy points left!" << std::endl;
        return;
    }
    this->_energyPoints -= 1;
    std::cout << "ClapTrap attacks "<< target << ", causing " 
                << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->_hitPoints <= amount){
        std::cout << "ClapTrap "<< this->_name << " has dead!"<< std::endl;
        return;
    }
    this->_hitPoints -= amount;
    std::cout << "ClapTrap "<< this->_name << " takes "<< amount<< " points of damage!"<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->_energyPoints <= 0){
        std::cout << "ClapTrap has no energy points left!" << std::endl;
        return;
    }
    this->_hitPoints +=amount;
    this->_energyPoints -= 1;
    std::cout << "ClapTrap "<< this->_name << " is required for "<< amount << " points!" << std::endl;
}
