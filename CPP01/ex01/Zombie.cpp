#include "Zombie.hpp"

Zombie::Zombie() {
}

Zombie::~Zombie() {
    std::cout << this->_name << ": has destroyed" << std::endl;
}

void Zombie::announce() const {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

void Zombie::setName(const std::string& name) {
	this->_name = name;
}