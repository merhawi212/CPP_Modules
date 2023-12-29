#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    std::cout << "Default deconstractor called!" << std::endl;

}

ClapTrap::ClapTrap(const std::string& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage)
        : _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage) {
        std::cout << "Constractor " << this->_name <<" called!"  << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "Default deconstractor called!" << std::endl;

}

void ClapTrap::attack(const std::string& target){
    std::cout << "ClapTrap "<< this->_name;
    if (!hasEnoughEnergyPoints())
        return;
    if (!hasEnoughHitPoints(this->_attackDamage))
        return;
    this->_hitPoints -= this->_attackDamage;
    this->_energyPoints -= 1;
    std::cout << " attacks "<< target << ", causing " 
                << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
      std::cout << "ClapTrap "<< this->_name;
    if (!hasEnoughHitPoints(amount))
        return;
    this->_hitPoints -= amount;
    std::cout << " takes "<< amount<< " points of damage!"<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    std::cout << "ClapTrap "<< this->_name;
    if (!hasEnoughEnergyPoints())
        return;
    this->_hitPoints +=amount;
    this->_energyPoints -= 1;
    std::cout << " is required for "<< amount << " points!" << std::endl;
}

bool ClapTrap::hasEnoughEnergyPoints(){
  if (this->_energyPoints <= 0){
        std::cout << " has no enery points left!" << std::endl;
        return 0 ;
    }
    return 1;
}

bool ClapTrap::hasEnoughHitPoints(unsigned int amount){
    if ((signed)(this->_hitPoints - amount) < 0){
        std::cout << " has no enough hit points left!" << std::endl;
        return 0;
    }
    return 1;
}

void ClapTrap::setAttackDamage(unsigned int amount){
    this->_attackDamage = amount;
}

int ClapTrap::getAttackDamage(){
   return this->_attackDamage;
}


 void ClapTrap::setEnergyPoints(unsigned int amount){
    this->_energyPoints = amount;

 }
int ClapTrap::getEnergyPoints(){
    return this->_energyPoints;
}
void ClapTrap::setHitPoints(unsigned int amount){
    this->_hitPoints = amount;
}
int ClapTrap::getHiPoints(){
    return this->_hitPoints;
}
