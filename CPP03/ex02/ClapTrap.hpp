#ifndef CLAPTRAP_HPP
#define  CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap{
    protected:
        std::string _name;
        unsigned int _hitPoints;  
        unsigned int _energyPoints;
        unsigned int _attackDamage;

    public:
        ClapTrap(const std::string& name);
        ~ClapTrap();

        ClapTrap(const ClapTrap& src);
        ClapTrap &operator =(const ClapTrap &another);


       virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);


};

#endif
