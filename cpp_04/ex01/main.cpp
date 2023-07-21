#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	const Animal* meta = new Animal();

	const Animal* j = new Dog();

	const Animal* i = new Cat();

	const Animal *anotherDog = new Dog("buddy");

	const Animal *anotherCat = new Cat("Tomy");

	std::cout << std::endl;
	const WrongAnimal *WCat = new WrongCat();
	std::cout << std::endl;


	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();

	std::cout << std::endl;

	std::cout << anotherDog->getType() << " " << std::endl;
	std::cout << anotherCat->getType() << " " << std::endl;
	anotherDog->makeSound(); //will output the cat sound!
	anotherCat->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	
	std:: cout<< WCat->getType()<< "" <<std::endl;
	WCat->makeSound();
	std::cout << std::endl;


	delete j;
	delete i;
	delete meta;
	delete anotherDog;
	delete anotherCat;
	delete WCat;

	return 0;

}


