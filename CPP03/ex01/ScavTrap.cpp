#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{

}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
                     
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;

    std::cout << "ScavTrap  " << name <<" constructor  called!"  << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src){
	std::cout << "Copy constructor is called to create a new ScavTrap of name " << src.getName() << std::endl;
	*this = src;
}

ScavTrap &ScavTrap::operator =(const ScavTrap &another){
	std::cout << "Copy assignment operator of ScavTrap " << another.getName() 
			<<" assigned to the current object"  << std::endl;
	if (this != &another){
		this->_name = another.getName();
		this->_hitPoints = another.getHitPoints();
		this->_energyPoints = another.getEnergyPoints();
		this->_attackDamage = another.getAttackDamage();
	 }
    return *this;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap  " << this->_name <<" destructor called!" << std::endl;

}

void ScavTrap::attack(const std::string& target){
    if (this->_energyPoints <= 0){
        std::cout << "ScavTrap  " << this->_name <<" has no energy points left!" << std::endl;
        return;
    }
    this->_energyPoints -= 1;
	 std::cout << "ScavTrap " << this->_name << " attacks "<< target << ", causing " 
                << this->_attackDamage << " points of damage!" << std::endl;
}


void ScavTrap::guardGate(){
    std::cout << "ScavTrap  " << this->_name <<" is now in Gate keeper mode" << std::endl;
}
