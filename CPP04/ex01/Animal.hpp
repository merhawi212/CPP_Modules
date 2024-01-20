#ifndef ANIMAL_HPP
#define  ANIMAL_HPP

#include <iostream>
#include <string>

class Animal{
    protected:
        std::string _type;

    public:
		//orthodox canonical form
        Animal(); 
        Animal(const Animal& src);
        Animal &operator =(const Animal &another);
        virtual ~Animal();

		//custom constructor
        Animal(const std::string& type);

		//method
        virtual void makeSound() const;

		//getter
		std::string const getType() const;

};

#endif
