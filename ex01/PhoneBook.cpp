#include"PhoneBook.hpp"

//classname::classname() {}--- constructor
PhoneBook:: PhoneBook() {
	_index = 0;//starts from empty or no cotacts 
}

PhoneBook:: ~PhoneBook() {

}

void PhoneBook:: AddContact(std::string input) {
	bool replaced = false;
	if (_index >= 8)
	{
		std:: cout<< "phonebook is full it will replace the older contact"<< std:: endl;
		_index = 0; //reset index to overwrite the first contact
		for (int i = 7; i > 0; i--)
		_Contacts[i] = _Contacts[i - 1];
	}
	if(replaced)
	{
		std:: cout<<"oldest contact replaced"<<std::endl;
	}
	else
	{
		std:: cout<<"new contact added"<<std::endl;
	}
	Contact NewContact;

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
	NewContact.set_FirstName(input); // Set the first name
	std:: cout << "First name: " << NewContact.get_FirstName() << std::endl;

	std:: cout << "Enter last name: ";
	std:: getline(std::cin, input);
	NewContact.set_LastName(input);
	std:: cout << "Last name: " << NewContact.get_LastName() << std::endl;

	std:: cout << "Enter nick name: ";
	std:: getline(std::cin, input);
	NewContact.set_LastName(input);
	std:: cout << "Nick name: " << NewContact.get_LastName() << std::endl;

	std:: cout << "Enter phone number: ";
	std:: getline(std::cin, input);
	NewContact.set_LastName(input);
	std:: cout << "Phone number: " << NewContact.get_LastName() << std::endl;

	std:: cout << "Enter darkest secret: ";
	std:: getline(std::cin, input);
	NewContact.set_LastName(input);
	std:: cout << "Darkest secret: " << NewContact.get_LastName() << std::endl;
	_index++;
	std:: cout << "Successfully Added to PhoneBook [" << _index << "/8]" << std:: endl;
}

void PhoneBook:: PrintContact(void)//std::string input
{
	std::cout<< "----------------------------------------" <<std::endl;
	std::cout<< " Index | FirstName | LastName | NickName" <<std::endl;
	std::cout<< "----------------------------------------" <<std::endl;
	std::cout<< "       |           |          |         " <<std::endl;


	std::cout<< std:: setw(10);//set max string width 10character
	// std::cin>> _index;
}

void PhoneBook:: SearchContact(void)//std::string input
{
	PhoneBook::PrintContact();
}
