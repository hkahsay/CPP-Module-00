#include"PhoneBook.hpp"

//classname::classname() {}--- constructor
PhoneBook:: PhoneBook() {
	_index = 0;//starts from empty or no cotacts 
}

PhoneBook:: ~PhoneBook() {

}

void PhoneBook::AddContact() {
    Contact newContact;
    std::string add;
    if (_index >= 8) {
        std::cout << "Phonebook is full. It will replace the older contact." << std::endl;
        _Contacts[_index % 8] = newContact;
    } else {
        _Contacts[_index] = newContact;
    }

    newContact.set_FirstName(getValidInput("First name", "First name cannot be empty."));
    newContact.set_LastName(getValidInput("Last name", "Last name cannot be empty."));
    newContact.set_NickName(getValidInput("Nick name", "Nick name cannot be empty."));
    newContact.set_PhoneNumber(getValidInput("Phone number", "Phone number cannot be empty."));
    newContact.set_DarkestSecret(getValidInput("Darkest secret", "Darkest secret cannot be empty."));

    _Contacts[_index % 8] = newContact;
    _index++;

    std::cout << "Successfully added to PhoneBook [" << _index << " - 8]" << std::endl;

    // Print the added contact's information
    std::cout << "First name: " << newContact.get_FirstName() << std::endl;
    std::cout << "Last name: " << newContact.get_LastName() << std::endl;
    std::cout << "Nick name: " << newContact.get_NickName() << std::endl;
    std::cout << "Phone number: " << newContact.get_PhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << newContact.get_DarkestSecret() << std::endl;
}

std::string PhoneBook::getValidInput(const std::string& field, const std::string& errorMessage) {
    std::string input;
    do {
        std::cout << field << ": ";// << "Enter "
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << errorMessage << std::endl;
        }
    } while (input.empty());

    return input;
}


// Contact PhoneBook:: get_contact(std:: string Add)
// {
// 	Contact NewContact;
// 	std:: string ContactField[5] = {"FirstName", "LastName", "NickName", "PhoneNumber", "DarkestSecret"};
// 	// std:: string Add[5];
// 	for (int i = 0; i < 5; i++)
// 	{
// 		std:: cout<< "Enter "<< ContactField[i] << ": ";
// 		do
// 		{
// 			std::getline(std::cin, ContactField[i]);
// 			if (ContactField[i].empty())
// 			{
// 				std :: cout<<"First name canot be empty ";
// 			}
			
// 		} while (ContactField[i].empty());

// 	NewContact.set_FirstName(Add); // Set the first name
// 	std:: cout <<NewContact.get_FirstName() << std:: endl; // Set the first name << "First name" <<
// 	NewContact.set_LastName(Add);
// 	std:: cout  <<NewContact.get_LastName()<< std:: endl;//<< " Last name"
// 	NewContact.set_NickName(Add);
// 	std:: cout  <<NewContact.get_NickName()<< std:: endl;//<< " Nick name"
// 	NewContact.set_PhoneNumber(Add);
// 	std:: cout  <<NewContact.get_PhoneNumber()<< std:: endl;//<< "Phone nummber"
// 	NewContact.set_DarkestSecret(Add);
// 	std:: cout  <<NewContact.get_DarkestSecret()<< std:: endl;//<< "Darkest Secret" 
// 	}
// 	return (NewContact);
// }

// void PhoneBook:: AddContact() {
// 	Contact NewContact;
// 	std:: string Add;
// 	std::string FirstName;
// 	std::string LastName;
// 	std::string NickName;
// 	std::string PhoneNumber;
// 	std::string DarkestSecret;
// 	// std::string firstName, lastName, nickName, phoneNumber, darkestSecret;(possible this way declaration also)
// 	if (_index >= 8)
// 	{
// 		std:: cout<< "phonebook is full it will replace the older contact"<< std:: endl;
// 		// _index = 0; 
// 		_Contacts[_index % 8] = NewContact;
// 	}
// 	else
// 	{
// 		_Contacts[_index] = NewContact;

// 	}
// 	// NewContact = get_contact(Add);
// 	std:: cout<< "Enter first name: ";
// 	while (FirstName.empty()) {
// 		std::getline(std::cin, FirstName);
// 		if (FirstName.empty())
// 			std :: cout<<"First name canot be empty ";
// 		}
// 		NewContact.set_FirstName(FirstName); // Set the first name
// 		std::cout << std::endl;
// 		std:: cout << "First name: " << NewContact.get_FirstName() << std::endl;

// 	std:: cout << "Enter last name: ";
// 	while (LastName.empty()) {
// 		std:: getline(std::cin, LastName);
// 		if (LastName.empty())
// 			std :: cout<<"Last name canot be empty ";
// 	}
// 	NewContact.set_LastName(LastName);
// 	std::cout << std::endl;
// 	std:: cout << "Last name: " << NewContact.get_LastName() << std::endl;


// 	std:: cout << "Enter nick name: ";
// 	while (NickName.empty()) {
// 		std:: getline(std::cin, NickName);
// 		if (NickName.empty())
// 			std:: cout<<"Nick name canot be empty ";
// 	}
// 	NewContact.set_NickName(NickName);
// 	std::cout << std::endl;
// 	std:: cout << "Nick name: " << NewContact.get_NickName() << std::endl;


// 	std:: cout << "Enter phone number: ";
// 	while(PhoneNumber.empty()) {
// 		std:: getline(std::cin, PhoneNumber);
// 		if (PhoneNumber.empty())
// 			std :: cout<<"Phone number canot be empty ";
// 	}
// 	NewContact.set_PhoneNumber(PhoneNumber);
// 	std::cout << std::endl;
// 	std:: cout << "Phone number: " << NewContact.get_PhoneNumber() << std::endl;

// 	std:: cout << "Enter darkest secret: ";
// 	while (DarkestSecret.empty()) {
// 		std:: getline(std::cin, DarkestSecret);
// 		if (DarkestSecret.empty())
// 			std:: cout<<"Darkest secret canot be empty ";
// 	}
// 	NewContact.set_DarkestSecret(DarkestSecret);
// 	std::cout << std::endl;
// 	std:: cout << "Darkest secret: " << NewContact.get_DarkestSecret() << std::endl;
// 	_Contacts[_index % 8] = NewContact;
// 	_index++;
// 	std:: cout << "Successfully Added to PhoneBook [" << _index << "/8]" << std:: endl;
	
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
