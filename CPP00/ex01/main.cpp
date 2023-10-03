#include "PhoneBook.hpp"

int main() {
    PhoneBook phoneBook;
    std::string input = "";
	std::cout << YELLOW_TEXT"+++++Welcome to Phone Book App!+++++" RESET_COLOR<<std::endl;
	std::cout << std::endl;
	std::cout << "Please follow the instructions to procceed." << std::endl;
	std::cout << std::endl;
    while (!std::cin.eof()) {
        std::cout <<YELLOW_TEXT "Please enter a command -> ADD or SEARCH or EXIT: " RESET_COLOR;
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

