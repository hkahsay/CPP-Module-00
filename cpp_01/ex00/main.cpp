#include"Zombie.hpp"
#include<string>
int main() {

	std:: string inputName2 = "Foo from announce";
	std:: string inputName = "new peter";
	Zombie instance;
	Zombie* allocZombie = NULL;

	instance.set_name(inputName2);
	instance.announce();
	allocZombie = newZombie(inputName);
	allocZombie->announce();
	randomChump("random chump");
	delete allocZombie;

	return 0;
}