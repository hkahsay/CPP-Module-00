#include"PhoneBook.hpp"

//classname::classname() {}--- constructor
PhoneBook:: PhoneBook() {
	_index = 0;//starts from empty or no cotacts 
}

PhoneBook:: ~PhoneBook() {

}

void PhoneBook:: AddContact() {
	Contact NewContact;

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
    	while (FirstName.empty()) {
       		std::getline(std::cin, FirstName);
			std :: cout<<"First name canot be empty ";
   		 }
			NewContact.set_FirstName(FirstName); // Set the first name
			std::cout << std::endl;
			std:: cout << "First name: " << NewContact.get_FirstName() << std::endl;

		std:: cout << "Enter last name: ";
		while (LastName.empty()) {
			std:: getline(std::cin, LastName);
			std :: cout<<"Last name canot be empty ";
		}
		NewContact.set_LastName(LastName);
		std::cout << std::endl;
		std:: cout << "Last name: " << NewContact.get_LastName() << std::endl;


		std:: cout << "Enter nick name: ";
		while (NickName.empty()) {
			std:: getline(std::cin, NickName);
			std :: cout<<"Nick name canot be empty ";
		}
		NewContact.set_NickName(NickName);
		std::cout << std::endl;
		std:: cout << "Nick name: " << NewContact.get_NickName() << std::endl;


		std:: cout << "Enter phone number: ";
		while(PhoneNumber.empty()) {
			std:: getline(std::cin, PhoneNumber);
			std :: cout<<"Phone number canot be empty ";
		}
		NewContact.set_PhoneNumber(PhoneNumber);
		std::cout << std::endl;
		std:: cout << "Phone number: " << NewContact.get_PhoneNumber() << std::endl;

		std:: cout << "Enter darkest secret: ";
		while (DarkestSecret.empty()) {
			std:: getline(std::cin, DarkestSecret);
			std :: cout<<"Darkest secret canot be empty ";
		}
		NewContact.set_DarkestSecret(DarkestSecret);
		std::cout << std::endl;
		std:: cout << "Darkest secret: " << NewContact.get_DarkestSecret() << std::endl;

		_Contacts[_index % 8] = NewContact;
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
    std::cout << "Enter a valid index > ";
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
        std::cout << "Darkest secret: " << savedContact.get_DarkestSecret() << std::endl;
		
    }
    else if (i >= 1 && i <= _index) {
		Contact savedContact = _Contacts[i];
        std::cout << "First name: " << savedContact.get_FirstName() << std::endl;
        std::cout << "Last name: " << savedContact.get_LastName() << std::endl;
        std::cout << "Nick name: " << savedContact.get_NickName() << std::endl;
        std::cout << "Phone number: " << savedContact.get_PhoneNumber() << std::endl;
        std::cout << "Darkest secret: " << savedContact.get_DarkestSecret() << std::endl;

    }
	else {
        std::cout << "Invalid index " << std::endl;

	}
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
