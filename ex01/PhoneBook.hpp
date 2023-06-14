#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include"Contact.hpp"
#include<string>
#include<iostream>
#include<iomanip>


class PhoneBook {
	private:
		Contact _Contacts[8]; //we put Contact class as a type 
		//blc we access our contact form contact class
		int _index;
	public:
		PhoneBook();
		~PhoneBook();
		void AddContact(std::string input);
		void SearchContact(void);//std::string input
		void PrintContact(void);//std::string input
		void Exit(std::string input);
};
#endif
