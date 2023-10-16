#include"Zombie.hpp"

Zombie*  newZombie(std:: string name){

	Zombie* allocZombie = new Zombie();
	allocZombie->set_name(name);
	return allocZombie;
}

