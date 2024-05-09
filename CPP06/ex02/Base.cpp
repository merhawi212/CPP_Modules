#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::Base(void){
    std::cout << "Base class constructor called." << std::endl;
}

Base::~Base(){
    std::cout << "Base class destructor called." << std::endl;
}

Base* generate(){

    srand(time(NULL)); // Seed the random number generator
    int random = rand() % 3; // Generate a random number between 0 and 2

    switch(random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}


void identify(Base* p){
    if (dynamic_cast<A*>(p)){
         std::cout << "Class A" << std::endl;
    }
    else if (dynamic_cast<B*>(p)){
         std::cout << "Class B" << std::endl;
    }
    else if (dynamic_cast<C*>(p)){
         std::cout << "Class C" << std::endl;
    }
    else  {
        std::cout << "Unknown Class type" << std::endl;
    }
}

void identify(Base& p){
   try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Class A with reference" << std::endl;
	}
	catch (std::exception& e)
	{
        try {
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "Class B with reference" << std::endl;
        }
        catch (std::exception& e)
        {
            try {
                C& c = dynamic_cast<C&>(p);
				(void)c;
                std::cout << "Class C with reference" << std::endl;
            }  catch (std::exception& e)
            {
                std::cout << "Unknown class Type" << std::endl;
            }
        }
    
	}

}

