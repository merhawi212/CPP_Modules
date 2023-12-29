#ifndef SCAVTRAP_HPP
#define  SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScaveTrap: public ClapTrap{
    private:

    public:
        ScaveTrap();
        ~ScaveTrap();

        ScaveTrap(const std::string& name);
        ScaveTrap(const ScaveTrap &another);
        ScaveTrap &operator =(const ScaveTrap &src);
        void guardGate();
};


#endif
