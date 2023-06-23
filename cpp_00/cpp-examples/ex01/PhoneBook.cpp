#include"PhoneBook.hpp"

//classname::classname() {}--- constructor
PhoneBook:: PhoneBook() {
	_index = 0;//starts from empty or no cotacts 
}

PhoneBook:: ~PhoneBook() {

}

void PhoneBook:: AddContact(std::string input) {
	bool replaced = false;
	Contact NewContact;

	if(replaced)
	{
		std:: cout<<"oldest contact replaced"<<std::endl;
	}
	else
	{
		std:: cout<<"new contact added"<<std::endl;
	}
	if (_index >= 8)
	{
		std:: cout<< "phonebook is full it will replace the older contact"<< std:: endl;
		_index = 0; 
		_Contacts[_index % 8] = NewContact;
	}
	else
	{
		_Contacts[_index] = NewContact;
	}

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
		NewContact.set_NickName(input);
		std:: cout << "Nick name: " << NewContact.get_NickName() << std::endl;

		std:: cout << "Enter phone number: ";
		std:: getline(std::cin, input);
		NewContact.set_PhoneNumber(input);
		std:: cout << "Phone number: " << NewContact.get_PhoneNumber() << std::endl;

		std:: cout << "Enter darkest secret: ";
		std:: getline(std::cin, input);
		NewContact.set_DarkestSecret(input);
		std:: cout << "Darkest secret: " << NewContact.get_DarkestSecret() << std::endl;
		_Contacts[_index] = NewContact;
		_index++;
		std:: cout << "Successfully Added to PhoneBook [" << _index << "/8]" << std:: endl;
	
}

void print_column(std::string value) {
    if(value.size() > 9) {
        std::cout << value.substr(0, 9) << ".";

    } else {
        std::cout << std::setw(10) << value;
    }
}

void PhoneBook:: PrintContact(void)//std::string input
{
	std::cout<< "---------------------------------------------" <<std::endl;
	std::cout<< "|     Index| FirstName|  LastName|  NickName|" <<std::endl;
	std::cout<< "---------------------------------------------" <<std::endl;
	for(int i = 0; i < 8; i++) {
		if (_Contacts[i].get_FirstName().size())//&& counter++
		{
			std::cout << "|";
			print_column(std::to_string(i + 1));
			std::cout << "|";
			print_column(_Contacts[i].get_FirstName());
			std::cout << "|";
			print_column(_Contacts[i].get_LastName());
			std::cout << "|";
			print_column(_Contacts[i].get_NickName());
			std::cout << "|";
			std::cout << std::endl;
			std::cout<< "---------------------------------------------" <<std::endl;
		
		}
		
	}

}


void PhoneBook::PrintFullContactInfo() {
    std::string index;
    std::cout << "Enter a valid index: ";
    std::getline(std::cin, index);

    int i = std::stoi(index);
    std::cout << "value of i: " << i << std::endl;
    std::cout << "value of _index: " << _index << std::endl;

	if (i == 1 && _index == 1) {
		Contact savedContact = _Contacts[0];
        std::cout << "First name: " << savedContact.get_FirstName() << std::endl;
        std::cout << "Last name: " << savedContact.get_LastName() << std::endl;
        std::cout << "Nick name: " << savedContact.get_NickName() << std::endl;
        std::cout << "Phone number: " << savedContact.get_PhoneNumber() << std::endl;
    }
    else if (i >= 1 && i < _index) {
		Contact savedContact = _Contacts[i];
        std::cout << "First name: " << savedContact.get_FirstName() << std::endl;
        std::cout << "Last name: " << savedContact.get_LastName() << std::endl;
        std::cout << "Nick name: " << savedContact.get_NickName() << std::endl;
        std::cout << "Phone number: " << savedContact.get_PhoneNumber() << std::endl;
    }
	else {
        std::cout << "Invalid index " << std::endl;

	}
}

void PhoneBook:: SearchContact(void)//std::string input
{
	if (_index > 0)
	{
		// std::string index;
		Contact	SavedContact;


		PhoneBook::PrintContact();
		PrintFullContactInfo();
	}
	else {

		std::cout<< "--------------------------------------------" <<std::endl;
		std::cout<< "|    Index| FirstName|  LastName|  NickName|" <<std::endl;
		std::cout<< "|---------|----------|----------|----------|" <<std::endl;
		std::cout <<std::endl; 
		std::cout <<"Phonebook is empty"<<std::endl; 
		std::cout <<std::endl; 
	}
	

}
