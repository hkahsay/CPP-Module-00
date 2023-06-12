#include <iostream>
#include <string>
#include <vector>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string nickName;

public:
    // Constructor
    Contact(const std::string& first, const std::string& last, const std::string& phone, const std::string& nick)
        : firstName(first), lastName(last), phoneNumber(phone), nickName(nick) {}

    // Getter functions
    std::string getFirstName() const {
        return firstName;
    }

    std::string getLastName() const {
        return lastName;
    }

    std::string getPhoneNumber() const {
        return phoneNumber;
    }

    std::string getNickName() const {
        return nickName;
    }
};

class PhoneBook {
private:
    std::vector<Contact> contacts;

public:
    // Method to add a new contact
    void addContact(const std::string& first, const std::string& last, const std::string& phone, const std::string& nick) {
        if (contacts.size() >= 8) {
            // Replace the oldest contact
            contacts.erase(contacts.begin());
        }

        contacts.emplace_back(first, last, phone, nick);
    }

    // Method to search for a contact
    void searchContact(int index) {
        if (index >= 0 && index < contacts.size()) {
            Contact contact = contacts[index];
            std::cout << "First Name: " << contact.getFirstName() << std::endl;
            std::cout << "Last Name: " << contact.getLastName() << std::endl;
            std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
            std::cout << "Nick Name: " << contact.getNickName() << std::endl;
        } else {
            std::cout << "Invalid index!" << std::endl;
        }
    }
};

int main() {
    PhoneBook phoneBook;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, or EXIT): ";
        std::string command;
        std::cin >> command;

        if (command == "ADD") {
            std::string firstName, lastName, phoneNumber, nickName;
            std::cout << "Enter first name: ";
            std::cin >> firstName;
            std::cout << "Enter last name: ";
            std::cin >> lastName;
            std::cout << "Enter phone number: ";
            std::cin >> phoneNumber;
            std::cout << "Enter nick name: ";
            std::cin >> nickName;

            phoneBook.addContact(firstName, lastName, phoneNumber, nickName);
            std::cout << "Contact added successfully!" << std::endl;
        } else if (command == "SEARCH") {
            int index;
            std::cout << "Enter the index of the contact to search: ";
            std::cin >> index;

            phoneBook.searchContact(index);
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command!" << std::endl;
        }
    }

    return 0;
}
