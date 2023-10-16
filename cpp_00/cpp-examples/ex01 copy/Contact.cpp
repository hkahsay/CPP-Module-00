#include"Contact.hpp"

Contact:: Contact() {

}

Contact:: ~Contact() {

}
//return type class name functionname with parameter the the curly braces
std::string Contact ::get_FirstName(void)const {
	return(this->_FirstName);
}

std::string Contact ::get_LastName(void)const {
	return(this->_LastName);
}

std::string Contact ::get_NickName(void)const {
	return (this->_NickName);
}

std::string Contact ::get_PhoneNumber(void)const {
	return (this->_PhoneNumber);
}

std::string Contact ::get_DarkestSecret(void)const {
	return(this->_DarkestSecret);
}

void Contact ::set_FirstName(std:: string input) {
	this->_FirstName = input;
}

void Contact ::set_LastName(std:: string input) {
	this->_LastName = input;
}

void Contact ::set_NickName(std:: string input) {
	this->_NickName = input;
}

void Contact ::set_PhoneNumber(std:: string input) {
	this->_PhoneNumber = input;
}

void Contact ::set_DarkestSecret(std:: string input) {
	this->_DarkestSecret = input;
}