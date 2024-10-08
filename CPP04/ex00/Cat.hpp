#ifndef CAT_HPP
#define  CAT_HPP

#include "Animal.hpp"

class Cat: public Animal{
    private:

    public:
		//orthodox canonical form
        Cat();
        Cat(const Cat& src);
        Cat &operator =(const Cat &another);
        ~Cat();

		//custom constructor
        Cat(const std::string& type);

        void makeSound() const; // override method

};

#endif
