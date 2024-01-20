#ifndef WRONGANIMAL_HPP
#define  WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal{
    protected:
        std::string _type;

    public:
		//orthodox canonical form
        WrongAnimal(); 
        WrongAnimal(const WrongAnimal& src);
        WrongAnimal &operator =(const WrongAnimal &another);
        virtual ~WrongAnimal();

		//custom constructor
        WrongAnimal(const std::string& type);

		//method
        void makeSound() const;

		//getter
		std::string const getType() const;

};

#endif
