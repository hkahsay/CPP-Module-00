#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"



// int main()
// {
// 	const int index = 6;
// 	AAnimal* AnimalObject[index];
// 	// AAnimal* aanimal=  new AAnimal();

// 	// Create half Dog objects and half Cat objects
// 	for (int i = 0; i < index; i++)
// 	{
// 		if(i % 2 == 0)
// 			AnimalObject[i] = new Dog();
// 		else
// 			AnimalObject[i] = new Cat();
// 	}
// 	for (int i = 0; i < index; i++)
// 		AnimalObject[i]->makeSound();
// 	for (int i = 0; i < index; i++)
// 		delete AnimalObject[i];
	
// 	Dog dogCharacter;
// 	for (int i = 0; i < 5 ; i++)
// 	{
// 		dogCharacter.getBrain()->setIdeas(0, "I am Good guard dog");
// 		dogCharacter.getBrain()->setIdeas(1, "Good temperament");
// 		dogCharacter.getBrain()->setIdeas(2, "intelligen");

// 		std::cout << "Idea " << i << " of dogCharacter : " << dogCharacter.getBrain()->getIdeas(i) << std::endl;
// 	}

// 	Cat catCharacter;
// 	for (int i = 0; i < 5 ; i++)
// 	{
// 		catCharacter.getBrain()->setIdeas(0, "I am playfulness cat");
// 		catCharacter.getBrain()->setIdeas(1, "Fearfulness");
// 		catCharacter.getBrain()->setIdeas(2, "Excessive grooming");

// 		std::cout << "Idea " << i << " of catCharacter : " << catCharacter.getBrain()->getIdeas(i) << std::endl;
// 	}

// 	return 0;
// }



int	main(void)
{
	std::cout << "\n*************  test1  *************" << std::endl;

	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();
	

	delete dog;
	delete cat;
	std::cout << "\n*************  test1  *************" << std::endl;

	Cat Birman;
	Cat Ragdollt(Birman);
	std::cout << "\n*************  test2  *************" << std::endl;

	std::cout << "\n*************  test3  *************" << std::endl;

	Dog parent;
	std::cout << "parent : " << parent.getBrain() << std::endl;
	{
		Dog tmp = parent;
		std::cout << "tmp : " << tmp.getBrain() << std::endl;
	}
	std::cout << "\n*************  end  *************" << std::endl;

	return 0;
}
