#include"Weapon.hpp"


Weapon:: Weapon() {

}

Weapon:: ~Weapon() {

}

Weapon:: Weapon(std:: string type)
:_type(type) {

}

const std:: string&  Weapon:: getType(void)const {

	return _type;

}

void Weapon::setType(std:: string newType) {
	_type = newType;
}