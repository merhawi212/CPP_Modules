#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;//should not create a leak
	delete i;


	int arraySize = 4;
	Animal *animal[arraySize];

	for (int i = 0; i < arraySize / 2; i++){
		animal[i] = new Dog();
		animal[i + arraySize / 2] = new Cat();
	}
	std::cout << "\n***Destroy all objects****"<<std::endl;
	for (int i = 0; i < arraySize; i++){
		 delete animal[i];
	}

	std::cout <<"\n***static allocation ***\n"<<std::endl;
	Cat cat;
	Cat temp = cat;
/*
	std::cout << "\n****start of Wrong Animal and Cat ****\n" << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_i = new WrongCat();
	WrongCat* wrong_cat = new WrongCat();

	std::cout << wrong_i->getType() << " " << std::endl;
	std::cout << wrong_cat->getType() << " " << std::endl;
	wrong_cat->makeSound(); //will output the wrongcat sound!
	wrong_i->makeSound(); //will output the wronganimal sound!
	wrong_meta->makeSound();

	delete wrong_cat;
    delete wrong_i;
	delete wrong_meta;
	std::cout << "\n****end of Wrong Animal and Cat ****" << std::endl;
*/

	/*
	 Brain brain;
	 
   	const  std::string* ideas = brain.getIdeas();

    // Loop through the array and print each idea
    for (int i = 0; i < 100; i++) {
        std::cout << ideas[i] << std::endl;
    }
	*/
	return 0;
}
