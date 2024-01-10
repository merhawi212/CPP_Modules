#ifndef DOG_HPP
#define  DOG_HPP

#include "Animal"

class Dog{
    private:

    public:
        Dog();
        Dog(const Dog& src);
        Dog &operator =(const Dog &another);
        ~Dog();

        Dog(const std::string& type);

        void makeSound(); // override method

};

#endif
