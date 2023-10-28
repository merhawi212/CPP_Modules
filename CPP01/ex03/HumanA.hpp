#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA{
	private:
		std::string _name;
		Weapon& _weapon;
	public:
		HumanA(const std::string& name, Weapon& Weapon);
		~HumanA();
		void attack() const;

};
#endif