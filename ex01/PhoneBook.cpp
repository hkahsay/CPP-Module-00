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
	std::cout<< "-------------------------------------------" <<std::endl;
	std::cout<< "     Index| FirstName|  LastName|  NickName" <<std::endl;
	std::cout<< "-------------------------------------------" <<std::endl;

    // Just to test, insert a contact:
    _index = 1;
    _Contacts[0].set_FirstName("Matthieuuuuuuuuu");
    _Contacts[0].set_LastName("Bovel");
    _Contacts[0].set_NickName("Matt");
    _Contacts[0].set_PhoneNumber("118218");
    _Contacts[0].set_DarkestSecret("bloop");
    _index = 2;
    _Contacts[1].set_FirstName("Matthieu");
    _Contacts[1].set_LastName("Bovel");
    _Contacts[1].set_NickName("Matt");
    _Contacts[1].set_PhoneNumber("118218");
    _Contacts[1].set_DarkestSecret("bloop");
     

    for(int i = 0; i < 8; i++)
    {
        print_column(std::to_string(i + 1));
        std::cout << "|";
        print_column(_Contacts[i].get_FirstName());
        std::cout << "|";
        print_column(_Contacts[i].get_LastName());
        std::cout << "|";
        print_column(_Contacts[i].get_NickName());
        std::cout << std::endl;
    }
}

void PhoneBook:: SearchContact(void)//std::string input
{
	PhoneBook::PrintContact();
}
