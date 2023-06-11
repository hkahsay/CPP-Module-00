#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include<string>
#include<iostream>


class Contact {
	public:
		Contact();
		~Contact();
		int	index;
		int PhoneNumber;
		// we add const on get b/c get is only access read-only mode
		std::string  get_FirstName(void)const;
		std:: string get_LastName(void)const;
		std:: string get_NickName(void)const;
		std:: string get_DarkSecret(void)const;
		void set_FirstName(std:: string input);
		void set_LastName(std:: string input);
		void set_NickName(std:: string input);
		void set_DarkSecret(std:: string input);

		// Add(char name,)
};

class PhoneBook {
	public:
		std:: string contacts[8];
		PhoneBook();
		~PhoneBook();
		void AddContact(std:: string input);
		void Search(std:: string input);
		void Exit(std:: string input);


};
#endif
