#ifndef SCAVTRAP_HPP
#define  SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
    private:

		ScavTrap(void);
    public:
        ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& src);
        ScavTrap &operator =(const ScavTrap &another);
        ~ScavTrap();
        
        void attack(const std::string& target); //override method
        void guardGate();
};


#endif
