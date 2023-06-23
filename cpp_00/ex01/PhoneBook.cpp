#include"PhoneBook.hpp"

//classname::classname() {}--- constructor
PhoneBook:: PhoneBook() {
	_index = 0;//starts from empty or no cotacts 
}

PhoneBook:: ~PhoneBook() {

}

void PhoneBook::AddContact() {
	Contact NewContact;
	std::string Add;
	if (_index >= 8)
	{
		std:: cout << "Phonebook is full. It will replace the oldest contact," << std::endl;
		_Contacts[_index % 8] = NewContact;
	}
	else {
		_Contacts[_index] = NewContact;
	}
	NewContact.set_FirstName(GetValidInput("First Name", "First Name canot be empty."));
	NewContact.set_LastName(GetValidInput("Last Name", "Last Name cannot be empty."));
	NewContact.set_NickName(GetValidInput("Nick Name", "Nick Name canot be empty."));
	NewContact.set_PhoneNumber(GetValidInput("Phone Number", "Phone Number canot be empty."));
	NewContact.set_DarkestSecret(GetValidInput("Darkest Secret", "Darkest Secret canot be empty."));
	_Contacts[_index % 8] = NewContact;
	_index++;
	std:: cout << NewContact.get_FirstName() << ", is added Successfully to PhoneBook.[" <<_index << " - 8]" << std:: endl;
	
}

std::string PhoneBook:: GetValidInput(const std:: string& Field, const std:: string& ErrorMessage) {
	std:: string Input;
	do
	{
		std:: cout << Field << ": ";
		std:: getline(std::cin, Input);
		if (Input.empty()) {
			std:: cout <<ErrorMessage << std:: endl;
		}
	} while (Input.empty());
	return Input;
}

void print_column(std::string value) {
    if(value.size() > 9) {
        std::cout << value.substr(0, 9) << ".";

    } else {
        std::cout << std::setw(10) << value;
    }
}


void PhoneBook:: PrintContact(void)
{
	std::cout<< "---------------------------------------------" <<std::endl;
	std::cout<< "|     Index| FirstName|  LastName|  NickName|" <<std::endl;
	std::cout<< "---------------------------------------------" <<std::endl;
	for(int i = 0; i < 8; i++) {
		if (_Contacts[i].get_FirstName().size())
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
	return ;
}


void PhoneBook::PrintFullContactInfo() {

	std::cout << "Select a valid index > ";
	int i;
		while (!(std::cin >> i) || i > _index || i > 8 || i < 1)
		{
			std::cout << "Invalid input! Please enter a valid index." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Select a valid index > ";
		}
	Contact savedContact = _Contacts[i - 1];

	std::cout << "First name: " << savedContact.get_FirstName() << std::endl;
	std::cout << "Last name: " << savedContact.get_LastName() << std::endl;
	std::cout << "Nick name: " << savedContact.get_NickName() << std::endl;
	std::cout << "Phone number: " << savedContact.get_PhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << savedContact.get_DarkestSecret() << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return ;
}

void PhoneBook:: SearchContact(void)
{
	if (_index > 0)
	{
		PrintContact();
		
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
