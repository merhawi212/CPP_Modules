#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB{
	private:
		std::string _name;
		Weapon* _weapon;
	public:
		HumanB(const std::string& name);
		~HumanB();
		void attack() const;
        void setWeapon( Weapon& weapon);
        const Weapon* getWeapon() const;

};
#endif