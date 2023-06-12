#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include"Contact.hpp"
#include<string>
#include<iostream>


class PhoneBook {
	private:
		Contact _contacts[8]; //we put Contact class as a type 
		//blc we access our contact form contact class
		int _index;
	public:
		PhoneBook();
		~PhoneBook();
		void AddContact(std::string input);
		void Search(std::string input);
		void Exit(std::string input);
};
#endif
