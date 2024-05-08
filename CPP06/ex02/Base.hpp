#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Base{

    private:


    public:
        Base(void);
        virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);
#endif // BASE_HPP