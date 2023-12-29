#include "ScaveTrap.hpp"

ScaveTrap::ScaveTrap(){
    std::cout << "ScaveTrap default constructor called!" << std::endl;

}
ScaveTrap::~ScaveTrap(){
    std::cout << "ScaveTrap default deconstructor called!" << std::endl;

}

ScaveTrap::ScaveTrap(const std::string& name) : _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20) 
{
        std::cout << "ScaveTrap constructor  " << this->_name <<" called!"  << std::endl;
}



ScaveTrap::ScaveTrap(const ScaveTrap &another){
    *this = another;
}

ScaveTrap &ScaveTrap::operator =(const ScaveTrap &src){
    if (this != &src)
        this = src;
    return *this;
}



void ScaveTrap::attack(const std::string& target){
    std::cout << "ScaveTrap "<< this->_name;
    if (!hasEnoughEnergyPoints())
        return;
    if (!hasEnoughHitPoints(this->_attackDamage))
        return;
    this->_hitPoints -= this->_attackDamage;
    this->_energyPoints -= 1;
    std::cout << " attacks "<< target << ", causing " 
                << this->_attackDamage << " points of damage!" << std::endl;
}

void ScaveTrap::takeDamage(unsigned int amount){
      std::cout << "ScaveTrap "<< this->_name;
    if (!hasEnoughHitPoints(amount))
        return;
    this->_hitPoints -= amount;
    std::cout << " takes "<< amount<< " points of damage!"<< std::endl;
}

void ScaveTrap::beRepaired(unsigned int amount){
    std::cout << "ScaveTrap "<< this->_name;
    if (!hasEnoughEnergyPoints())
        return;
    this->_hitPoints +=amount;
    this->_energyPoints -= 1;
    std::cout << " is required for "<< amount << " points!" << std::endl;
}

void guardGate(){
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl
}
