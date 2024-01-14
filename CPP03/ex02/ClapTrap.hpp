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

        ClapTrap(void); // orthodox canonical form

    public:
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& src);
        ClapTrap &operator =(const ClapTrap &another);
       virtual ~ClapTrap();

		// methods
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

		    // setter and getters
        std::string		getName(void) const;
        void            setName( std::string name);

        unsigned int    getAttackDamage(void) const;
        void            setAttackDamage( unsigned int attack_damage);

        unsigned int    getHitPoints(void) const;
        void            setHitPoints( unsigned int hit_points);

        unsigned int    getEnergyPoints(void) const;
        void            setEnergyPoints( unsigned int enrgy_points);
		
};


#endif
