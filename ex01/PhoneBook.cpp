#include"PhoneBook.hpp"

//classname::classname() {}--- constructor
PhoneBook:: PhoneBook() {
	_index = 0;//starts from empty or no cotacts
}

PhoneBook:: ~PhoneBook() {

}

void PhoneBook:: AddContact(std::string input) {

	if (_index >= 8)
	{
		std:: cout<< "phonebook is full it will replace the older contact"<< std:: endl;
	}
	Contact ContactInstance;

	//declare variables that will be used to store the user's 
	//input for the contact's

	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;
	// std::string firstName, lastName, nickName, phoneNumber, darkestSecret;(possible this way declaration also)

	std:: cout<< "Enter first name: ";
	std::getline(std::cin, input);
	ContactInstance.set_FirstName(input); // Set the first name
	std:: cout << "First name: " << ContactInstance.get_FirstName() << std::endl;

	std:: cout << "Enter last name: ";
	std:: getline(std::cin, input);
	ContactInstance.set_LastName(input);
	std:: cout << "Last name: " << ContactInstance.get_LastName() << std::endl;

	std:: cout << "Enter nick name: ";
	std:: getline(std::cin, input);
	ContactInstance.set_LastName(input);
	std:: cout << "Nick name: " << ContactInstance.get_LastName() << std::endl;

	std:: cout << "Enter phone number: ";
	std:: getline(std::cin, input);
	ContactInstance.set_LastName(input);
	std:: cout << "Phone number: " << ContactInstance.get_LastName() << std::endl;

	std:: cout << "Enter darkest secret: ";
	std:: getline(std::cin, input);
	ContactInstance.set_LastName(input);
	std:: cout << "Darkest secret: " << ContactInstance.get_LastName() << std::endl;
	_index++;
	std:: cout << "Successfully Added to PhoneBook [" << _index << "/8]" << std:: endl;



}
