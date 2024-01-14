#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	int arraySize = 10;
	Animal *animal[arraySize];

	for (int i = 0; i < arraySize / 2; i++){
		animal[i] = new Dog();
		animal[i + arraySize / 2] = new Cat();
	}

	for (int i = 0; i < arraySize; i++){
		 delete animal[i];
	}


	return 0;
}
