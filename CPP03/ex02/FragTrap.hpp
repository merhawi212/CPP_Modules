#ifndef FRAGTRAP_HPP
#define  FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap{
    private:

    public:
        FragTrap(const std::string& name);
        ~FragTrap();

        void attack(const std::string& target); //overrided method
        void highFivesGuys(void);
};


#endif
