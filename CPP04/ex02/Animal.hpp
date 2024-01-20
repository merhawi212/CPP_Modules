#ifndef ANIMAL_HPP
#define  ANIMAL_HPP

#include <iostream>
#include <string>

class Animal{
    protected:
        std::string _type;

    public:
		//method
        virtual ~Animal() = default;
        virtual void makeSound() const = 0;
        std::string const getType() const;
		void setType(const std::string &type);

};

#endif
