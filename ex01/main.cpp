#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook phoneBook;
    std::string input;
    std::cout << "Please enter a command -> ADD or SEARCH or EXIT: ";
    while (true) {
        std::getline(std::cin, input);
        if (input == "ADD") {
            phoneBook.addContact();
        } else if (input == "SEARCH") {
            phoneBook.searchContact();
        } else if (input == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    return 0;
}
