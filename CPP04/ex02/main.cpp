#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	int arraySize = 10;
	Animal *animal[arraySize];

	for (int i = 0; i < arraySize / 2; i++){
		animal[i] = new Dog();
		animal[i + arraySize / 2] = new Cat();
	}
	std::cout << "\n***Destroy all objects****"<<std::endl;
	for (int i = 0; i < arraySize; i++){
		 delete animal[i];
	}

	return 0;
}
