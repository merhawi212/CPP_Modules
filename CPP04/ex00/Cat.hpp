#ifndef CAT_HPP
#define  CAT_HPP

#include "Animal"

class Cat{
    private:

    public:
        Cat();
        Cat(const Cat& src);
        Cat &operator =(const Cat &another);
        Cat(const std::string& type);
        ~Cat();

        void makeSound(); // override method

};

#endif
