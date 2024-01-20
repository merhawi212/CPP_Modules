#ifndef ANIMAL_HPP
#define  ANIMAL_HPP

#include <iostream>
#include <string>

class Animal{
    protected:
        std::string _type;
		//orthodox canonical form
        Animal(); 
        Animal(const Animal& src);
        Animal &operator =(const Animal &another);
		//custom constructor
        Animal(const std::string& type);

    public:
        virtual ~Animal();


		//method
        virtual void makeSound() const  = 0;

		//getter
		std::string const getType() const;

};

#endif
