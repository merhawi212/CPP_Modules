#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
class Weapon{
	private:
		std::string _type;

	public:
	Weapon(const std::string& type);
	~Weapon();
	void setType(const std::string& type);
	const std::string& getType() const;

};
#endif