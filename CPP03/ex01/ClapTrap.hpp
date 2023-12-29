#ifndef CLAPTRAP_HPP
#define  CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap{
    private:
        std::string _name;
        unsigned int _hitPoints;  
        unsigned int _energyPoints;
        unsigned int _attackDamage;
        bool hasEnoughEnergyPoints();
        bool hasEnoughHitPoints(unsigned int amount);

    public:
        ClapTrap();
        ~ClapTrap();

        ClapTrap(const ClapTrap &another);
        ClapTrap &operator =(const ClapTrap &src);
        ClapTrap(const std::string& name,  unsigned int hitPoints = 10, unsigned int energyPoints = 10, unsigned int attackDamage = 0);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        void setAttackDamage(unsigned int amount);
        int getAttackDamage();

        void setEnergyPoints(unsigned int amount);
        int getEnergyPoints();

        void setHitPoints(unsigned int amount);
        int getHiPoints();


};

#endif
