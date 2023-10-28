#include "Zombie.hpp"

int main(){
	Zombie* heapZombie = newZombie("Foo");
	heapZombie->announce();
	delete heapZombie;
	randomChump("Bee");
}