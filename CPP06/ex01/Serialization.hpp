#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <string>
#include <stdint.h>


# define PRINT_STATEMENT(statement) std::cout << statement << std::endl

struct Data {
    int id;
    std::string name;
    Data *next;
};

class Serialization{

    private:
        Serialization(void);
        Serialization(const Serialization& src);
        Serialization &operator =(const Serialization& );
        
    public:
        ~Serialization();

       static uintptr_t serialize(Data* ptr);
       static Data* deserialize(uintptr_t raw);

};
#endif //SERIALIZATION_HPP