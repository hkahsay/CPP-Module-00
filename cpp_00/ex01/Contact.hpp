#ifndef CONTACT_HPP
#define CONTACT_HPP
#include<string>
#include<iostream>


class Contact
{
	private:
		std::string _FirstName;
		std::string _LastName;
		std::string _NickName;
		std::string _PhoneNumber;
		std::string _DarkestSecret;
	public:
		Contact(void);
		~Contact();
		std::string get_FirstName(void)const;
		std::string get_LastName(void) const;
		std::string get_NickName(void) const;
		std::string get_PhoneNumber(void) const;
		std::string get_DarkestSecret(void) const;
		void set_FirstName(std::string input);
		void set_LastName(std::string input);
		void set_NickName(std::string input);
		void set_PhoneNumber(std::string input);
		void set_DarkestSecret(std::string input);
};


#endif








//    - Determine the necessary data members 
//    for each contact, such as `firstName`,  `lastName`, `phoneNumber`,
//     `nickName`and darkestSecret`.
//    - Decide on the appropriate access specifiers (`private` and `public`) 
//    for these members.
//    - Implement getter and setter functions for accessing and modifying 
//    the private data members.
//    - Consider any additional member functions that may be needed, 
//    such as constructors or utility functions.
