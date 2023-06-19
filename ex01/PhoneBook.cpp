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
		_temp = _index;
		std::cout<<"value of temp " << _temp << std:: endl;
		_index.clear();
		_index = 0; 
		_Contacts[_index % 8] = NewContact;
		_temp++;
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
			if (FirstName.empty())
				std :: cout<<"First name canot be empty ";
   		 }
			NewContact.set_FirstName(FirstName); // Set the first name
			std::cout << std::endl;
			std:: cout << "First name: " << NewContact.get_FirstName() << std::endl;

		std:: cout << "Enter last name: ";
		while (LastName.empty()) {
			std:: getline(std::cin, LastName);
			if (LastName.empty())
				std :: cout<<"Last name canot be empty ";
		}
		NewContact.set_LastName(LastName);
		std::cout << std::endl;
		std:: cout << "Last name: " << NewContact.get_LastName() << std::endl;


		std:: cout << "Enter nick name: ";
		while (NickName.empty()) {
			std:: getline(std::cin, NickName);
			if (NickName.empty())
				std:: cout<<"Nick name canot be empty ";
		}
		NewContact.set_NickName(NickName);
		std::cout << std::endl;
		std:: cout << "Nick name: " << NewContact.get_NickName() << std::endl;


		std:: cout << "Enter phone number: ";
		while(PhoneNumber.empty()) {
			std:: getline(std::cin, PhoneNumber);
			if (PhoneNumber.empty())
				std :: cout<<"Phone number canot be empty ";
		}
		NewContact.set_PhoneNumber(PhoneNumber);
		std::cout << std::endl;
		std:: cout << "Phone number: " << NewContact.get_PhoneNumber() << std::endl;

		std:: cout << "Enter darkest secret: ";
		while (DarkestSecret.empty()) {
			std:: getline(std::cin, DarkestSecret);
			if (DarkestSecret.empty())
				std:: cout<<"Darkest secret canot be empty ";
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

Contact	PhoneBook:: get_contact(int index)
{
	return (this->_Contacts[index % 8]);
}


void PhoneBook::PrintFullContactInfo() {

	std::cout<<"value of temp2 " << _temp << std:: endl;
    std::string index;
	std::cout << "Select a valid index > ";
	bool breakLoop = false;
	while (std::getline(std::cin, index))//cin.eof()
	{
		try
		{
			int i = std::stoi(index);
			i = i - 1;
			
			
			Contact savedContact = _Contacts[i];
			if ((i >= 0 && i < _index) || (i <= _temp)) {
				std::cout << "First name: " << savedContact.get_FirstName() << std::endl;
				std::cout << "Last name: " << savedContact.get_LastName() << std::endl;
				std::cout << "Nick name: " << savedContact.get_NickName() << std::endl;
				std::cout << "Phone number: " << savedContact.get_PhoneNumber() << std::endl;
				std::cout << "Darkest secret: " << savedContact.get_DarkestSecret() << std::endl;
				if (savedContact.get_FirstName().size() > 0)
					breakLoop = true;
			}
			while (!(std::cin >> i) || i > _index || i > 8 || i < 1){
				std::cout << "Invalid index " << std::endl;
			}
		}
		catch(const std::invalid_argument&)
		{
			std::cout << "Invalid input! Please enter a valid index." << std::endl;
		}
		if (breakLoop) {
            break;
        }
		std::cout << "Select a valid index > ";
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
