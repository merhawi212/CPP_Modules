#ifndef DOG_HPP
#define  DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
    private:
		Brain* _brain;

    public:
        Dog();
        Dog(const Dog& src);
        Dog &operator =(const Dog &another);
        ~Dog();

        Dog(const std::string& type);

        void makeSound() const; // override method

		Brain*  getBrain() const;
};

#endif
