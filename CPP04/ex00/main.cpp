#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


int main()
{
	std::cout << "\n****Start of Animal, Dog and Cat ****\n" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
 	delete j;
    delete i;
	delete meta;
	std::cout << "\n****end of Animal, Dog and Cat ****\n" << std::endl;

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


	std::cout << "\n****start Custom testing****\n" << std::endl;
	Cat* cat1 = new Cat("Cat");
	Cat k("Cat");
	Cat z("Cat");
	z = k;
	Cat cat(k);
	z.makeSound();
	cat.makeSound();
	cat1->makeSound();
	delete cat1;
	std::cout << "\n****end of Custom testing and start destroying the stack allocated objects****\n" << std::endl;

	return 0;
}
