#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data {
    int id;
    std::string name;

    Data(int _id, const std::string& _name) : id(_id), name(_name) {}
};

#endif // DATA_HPP
