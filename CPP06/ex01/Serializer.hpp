#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>


# define PRINT_STATEMENT(statement) std::cout << statement << std::endl

struct Data {
    int id;
    std::string name;
    Data *next;
};

class Serializer{

    private:
        Serializer(void);
        Serializer(const Serializer& src);
        Serializer &operator =(const Serializer& );
        
    public:
        ~Serializer();

       static uintptr_t serialize(Data* ptr);
       static Data* deserialize(uintptr_t raw);

};

#endif //SERIALIZER_HPP