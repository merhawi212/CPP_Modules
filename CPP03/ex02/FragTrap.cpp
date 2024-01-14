#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{

}

FragTrap::FragTrap(const std::string& name) :ClapTrap(name)
                     
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;

    std::cout << "FragTrap " << name <<" constructor called!"  << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src){
	std::cout << "Copy constructor is called to create a new FragTrap of name " << src.getName() << std::endl;
	*this = src;
}

FragTrap &FragTrap::operator =(const FragTrap &another){
	std::cout << "Copy assignment operator of FragTrap " << another.getName() 
			<<" assigned to the current object"  << std::endl;
	if (this != &another){
		this->_name = another.getName();
		this->_hitPoints = another.getHitPoints();
		this->_energyPoints = another.getEnergyPoints();
		this->_attackDamage = another.getAttackDamage();
	 }
    return *this;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap " << this->_name <<" destructor called!" << std::endl;

}

void FragTrap::highFivesGuys(void){
    std::cout << "FragTrap "<< this->_name <<" hi fives everyone." << std::endl;
}
