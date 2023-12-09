#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL)
{

}

HumanB::~HumanB(){

}

void HumanB::attack()const{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
void HumanB::setWeapon( Weapon& weapon){
    this->_weapon = &weapon;
}
const Weapon* HumanB::getWeapon()const{
   return this->_weapon;
}