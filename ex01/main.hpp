#include"PhoneBook.hpp"

int main()
{
	PhoneBook instance;
	std:: string input;

	while (input != "Exit")
	{
		if (input == "ADD")
		{
			// instance.AddContact();
		}
		else if (input == "SEARCH")
		{
			// instance.SearchContact();
		}
		else
		{
			std::cout<<"Invalid command"<<std::endl;
		}
	}
	return(0);
}