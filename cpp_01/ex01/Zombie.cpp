#include"Zombie.hpp"


Zombie:: Zombie() {

}

Zombie:: ~Zombie() {
	std:: cout << "Zombie " << this->_name << " for debugging purposes" << std:: endl;
}

void Zombie:: set_name(std:: string name) {
	this->_name = name;
	std:: cout << "set_name   " << this->_name << std:: endl;
	return ;
}

void Zombie:: announce(void) {

	std:: cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std:: endl;
	return ;

}