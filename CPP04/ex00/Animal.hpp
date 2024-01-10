#ifndef ANIMAL_HPP
#define  ANIMAL_HPP

#include <iostream>
#include <string>

class Animal{
    protected:
        std::string _type;

    public:
        Animal();
        Animal(const Animal& src);
        Animal &operator =(const Animal &another);
        virtual ~Animal();

        Animal(const std::string& type);

        virtual void makeSound();

};

#endif
