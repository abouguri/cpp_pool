#include "PhoneBook.hpp"
#include <iostream>
#include <string>

Contact createContact()
{
    Contact contact;
    std::string input;
    
    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    while (input.empty())
    {
        std::cout << "First name cannot be empty. Please enter a first name: ";
        std::getline(std::cin, input);
    }
    contact.setFirstName(input);
    
    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    while (input.empty())
    {
        std::cout << "Last name cannot be empty. Please enter a last name: ";
        std::getline(std::cin, input);
    }
    contact.setLastName(input);
    
    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    while (input.empty())
    {
        std::cout << "Nickname cannot be empty. Please enter a nickname: ";
        std::getline(std::cin, input);
    }
    contact.setNickname(input);
    
    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    while (input.empty())
    {
        std::cout << "Phone number cannot be empty. Please enter a phone number: ";
        std::getline(std::cin, input);
    }
    contact.setPhoneNumber(input);
    
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    while (input.empty())
    {
        std::cout << "Darkest secret cannot be empty. Please enter a darkest secret: ";
        std::getline(std::cin, input);
    }
    contact.setDarkestSecret(input);
    
    return contact;
}

int main()
{
    PhoneBook phoneBook;
    std::string command;
    
    std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
    std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
    
    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, command);
        
        if (command == "ADD")
        {
            Contact newContact = createContact();
            phoneBook.addContact(newContact);
            std::cout << "Contact added successfully." << std::endl;
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContact();
        }
        else if (command == "EXIT")
        {
            std::cout << "Goodbye! All your contacts are lost forever!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid command. Available commands: ADD, SEARCH, EXIT" << std::endl;
        }
    }
    
    return 0;
}