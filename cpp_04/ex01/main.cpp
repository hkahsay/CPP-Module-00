#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	const int index = 6;
	Animal* animalObject[index];

	// Create half Dog objects and half Cat objects
	for (int i = 0; i < index; i++)
	{
		if(i % 2 == 0)
			animalObject[i] = new Dog();
		else
			animalObject[i] = new Cat();
	}
	for (int i = 0; i < index; i++)
		animalObject[i]->makeSound();
	for (int i = 0; i < index; i++)
		delete animalObject[i];
	
	Dog dogCharacter;
	for (int i = 0; i < 5 ; i++)
	{
		dogCharacter.getBrain()->setIdeas(0, "I am Good guard dog");
		dogCharacter.getBrain()->setIdeas(1, "Good temperament");
		dogCharacter.getBrain()->setIdeas(2, "intelligen");

		std::cout << "Idea " << i << " of dogCharacter : " << dogCharacter.getBrain()->getIdeas(i) << std::endl;
	}

	Cat catCharacter;
	for (int i = 0; i < 5 ; i++)
	{
		catCharacter.getBrain()->setIdeas(0, "I am playfulness cat");
		catCharacter.getBrain()->setIdeas(1, "Fearfulness");
		catCharacter.getBrain()->setIdeas(2, "Excessive grooming");

		std::cout << "Idea " << i << " of catCharacter : " << catCharacter.getBrain()->getIdeas(i) << std::endl;
	}

	return 0;
}

