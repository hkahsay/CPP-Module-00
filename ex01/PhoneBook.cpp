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

// void PhoneBook::AddContact() {
//     Contact newContact;
//     std::string add;
//     if (_index >= 8) {
//         std::cout << "Phonebook is full. It will replace the older contact." << std::endl;
//         _Contacts[_index % 8] = newContact;
//     } else {
//         _Contacts[_index] = newContact;
//     }

//     newContact.set_FirstName(getValidInput("First name", "First name cannot be empty."));
//     newContact.set_LastName(getValidInput("Last name", "Last name cannot be empty."));
//     newContact.set_NickName(getValidInput("Nick name", "Nick name cannot be empty."));
//     newContact.set_PhoneNumber(getValidInput("Phone number", "Phone number cannot be empty."));
//     newContact.set_DarkestSecret(getValidInput("Darkest secret", "Darkest secret cannot be empty."));

//     _Contacts[_index % 8] = newContact;
//     _index++;

//     std::cout  << newContact.get_FirstName() << ", Successfully added to PhoneBook [" << _index << " - 8]" << std::endl;
// }

// std::string PhoneBook::getValidInput(const std::string& field, const std::string& errorMessage) {
//     std::string input;
//     do {
//         std::cout << field << ": ";// << "Enter "
//         std::getline(std::cin, input);
//         if (input.empty()) {
//             std::cout << errorMessage << std::endl;
//         }
//     } while (input.empty());

//     return input;
// }

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
	return ;
}


void PhoneBook::PrintFullContactInfo() {

    // std::string index;
	std::cout << "Select a valid index > ";
	// std::getline(std::cin, index);
	// int i = std::stoi(index);
	int i;
	// do
	// {
		while (!(std::cin >> i) || i > _index || i > 8 || i < 1)//(std::cin >> i)|| i > 8
		{
			std::cout << "Invalid input! Please enter a valid index." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Select a valid index > ";
		}
	// } while (i < _index);
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

void PhoneBook:: SearchContact(void)//std::string input
{
	if (_index > 0)
	{
		Contact	SavedContact;

		// PhoneBook::PrintContact();
		// PhoneBook::PrintFullContactInfo();

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
