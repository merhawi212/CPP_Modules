#ifndef FRAGTRAP_HPP
#define  FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap{

	private:
		FragTrap(void);
		
    public:
       	FragTrap(const std::string& name);
		FragTrap(const FragTrap& src);
        FragTrap &operator =(const FragTrap &another);
        ~FragTrap();

        void highFivesGuys(void);
};


#endif
