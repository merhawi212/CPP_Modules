#ifndef WRONGCAT_HPP
#define  WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
    private:

    public:
		//orthodox canonical form
        WrongCat();
        WrongCat(const WrongCat& src);
        WrongCat &operator =(const WrongCat &another);
        ~WrongCat();

		//custom constructor
        WrongCat(const std::string& type);

        void makeSound() const; // override method

};

#endif
