#include"Zombie.hpp"


Zombie:: Zombie() {

}

Zombie:: ~Zombie() {
	std:: cout << "Zombie " << this->_name << " for debugging purposes" << std:: endl;
}

void Zombie:: set_name(std:: string name) {
	this->_name = name;
}

void Zombie:: announce(void) {

	// Zombie instance;
	// std:: string name;
	// instance.set_name(name);

	std:: cout << this->_name << " BraiiiiiiinnnzzzZ..." << std:: endl;

}



	// std:: cout << "Enter a name: ";
	// std:: getline(std::cin, name);