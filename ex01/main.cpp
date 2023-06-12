// #include"PhoneBook.hpp"
#include"Contact.hpp"

#include<iostream>
#include <string>



int main()
{
	Contact instance;
	// PhoneBook instance2;

	std::string input;

	std:: cout <<"Welcome to my cheesy awesome phonebook!"<<std:: endl;
	std:: cout<<"please enter any valid command ";
	std:: getline(std:: cin, input);
	std:: cout<<"thank you ";

	instance.set_FirstName("Hermon");
	std:: cout<<"FirstName: "<< instance.get_FirstName();
	return(0);
}
	// while (true)
	// {
		// if (input == "ADD")
		// {
		// 	instance.AddContact(FirstName, LastName, NickName, PhoneNumber, DarkestSecret);
		// }
		// else if (input == "SEARCH")
		// {
		// 	// instance.SearchContact();
		// }
		// else
		// {
		// 	std::cout<<"Invalid command"<<std::endl;
		// }
	// }

// int main() {
//     std::string line;
//     std::cout << "Enter a line of text: ";
//     std::getline(std::cin, line);
//     std::cout << "You entered: " << line << std::endl;

//     return 0;
// }
