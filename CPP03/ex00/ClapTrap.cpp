#include "ClapTrap.hpp"


ClapTrap::ClapTrap(void)
{

}

ClapTrap::ClapTrap(const std::string& name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
        std::cout << "ClapTrap " << this->_name <<" constructor called!"  << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src){
	std::cout << "Copy constructor is called to create a new ClapTrap of name " << src.getName() << std::endl;
	*this = src;
}
ClapTrap &ClapTrap::operator =(const ClapTrap &another){
	std::cout << "Copy assignment operator of ClapTrap " << another.getName() 
			<<" assigned to the current object"  << std::endl;
	if (this != &another){
		this->_name = another.getName();
		this->_hitPoints = another.getHitPoints();
		this->_energyPoints = another.getEnergyPoints();
		this->_attackDamage = another.getAttackDamage();
	 }
    return *this;
}


ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap " << this->_name <<" destructor called!" << std::endl;

}

void ClapTrap::attack(const std::string& target){
    if (this->_energyPoints <= 0){
        std::cout << "ClapTrap has no energy points left!" << std::endl;
        return;
    }
    this->_energyPoints -= 1;
    std::cout << "ClapTrap " << this->_name << " attacks "<< target << ", causing " 
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



// getter
std::string		ClapTrap::getName(void) const { return this->_name;}
unsigned int    ClapTrap::getAttackDamage(void) const { return this->_attackDamage;}
unsigned int    ClapTrap::getHitPoints(void) const { return this->_hitPoints; }
unsigned int    ClapTrap::getEnergyPoints(void) const { return this->_energyPoints; }

//setters
void            ClapTrap::setName( std::string name) { this->_name = name; }
void            ClapTrap::setAttackDamage( unsigned int attack_damage) { this->_attackDamage = attack_damage; }
void            ClapTrap::setHitPoints( unsigned int hit_points) { this->_hitPoints = hit_points; }
void            ClapTrap::setEnergyPoints( unsigned int enrgy_points) { this->_energyPoints = enrgy_points; }