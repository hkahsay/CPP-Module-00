#include"PhoneBook.hpp"
// #include"Contact.hpp"

#include<iostream>
#include <string>



int main()
{
	// Contact instance;
	PhoneBook instance2;

	std::string input;

	std:: cout<<std:: endl;
	std:: cout <<"Welcome to my cheesy awesome phonebook!"<<std:: endl <<std:: endl;
	// std:: getline(std:: cin, input);
	// std:: cout<<"thank you ";

	while (true)
	{
		std:: cout<<"please enter a valid command:\n";
		std:: getline(std:: cin, input);
		if (input == "ADD")
		{
			instance2.AddContact(input);// call AddContact function from phonebook class
			input.clear();
		}
		if (input == "SEARCH")
		{
			instance2.SearchContact();// call SearchContact function from phonebook class
		}
		if (input == "EXIT")
		{
			std::cout <<"Comeback again"<<std:: endl;
			exit(0);
		}
	}
	return(0);
}
		// else if (input == "SEARCH")
		// {
		// 	// instance.SearchContact();
		// }
		// else
		// {
		// 	std::cout<<"Invalid command"<<std::endl;
		// }

// int main() {
//     std::string line;
//     std::cout << "Enter a line of text: ";
//     std::getline(std::cin, line);
//     std::cout << "You entered: " << line << std::endl;

//     return 0;
// }
