#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook phoneBook;
    std::string input = "";
    while (!std::cin.eof()) {
        std::cout << "Please enter a command -> ADD or SEARCH or EXIT: ";
        if (!std::getline(std::cin, input))
            break;
        if (input == "ADD") {
            phoneBook.addContact();
        } else if (input == "SEARCH") {
            phoneBook.searchContact();
        } else if (input == "EXIT") {
            break;
        }
    }
    return 0;
}

