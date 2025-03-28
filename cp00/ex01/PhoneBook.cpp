#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : oldestContactIndex(0), contactCount(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact &contact)
{
    this->contacts[this->oldestContactIndex] = contact;
    this->oldestContactIndex = (this->oldestContactIndex + 1) % 8;
    if (this->contactCount < 8)
        this->contactCount++;
}

std::string PhoneBook::truncateString(const std::string &str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::displayContactHeader() const
{
    std::cout << "|" << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void PhoneBook::displayContactRow(int index) const
{
    std::cout << "|" << std::setw(10) << index << "|";
    std::cout << std::setw(10) << truncateString(this->contacts[index].getFirstName()) << "|";
    std::cout << std::setw(10) << truncateString(this->contacts[index].getLastName()) << "|";
    std::cout << std::setw(10) << truncateString(this->contacts[index].getNickname()) << "|" << std::endl;
}

void PhoneBook::searchContact() const
{
    if (this->contactCount == 0)
    {
        std::cout << "The phonebook is empty." << std::endl;
        return;
    }
    
    this->displayContactHeader();
    for (int i = 0; i < this->contactCount; i++)
        this->displayContactRow(i);
    
    int index;
    std::cout << "Enter the index of the contact to display: ";
    std::cin >> index;
    
    // Check if the input is valid
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input. Please enter a number." << std::endl;
        return;
    }
    
    std::cin.ignore(10000, '\n');
    if (!this->displayContactDetails(index))
        std::cout << "Invalid index. Please enter a number between 0 and " << this->contactCount - 1 << std::endl;
}

bool PhoneBook::displayContactDetails(int index) const
{
    if (index < 0 || index >= this->contactCount)
        return false;
    
    std::cout << "First Name: " << this->contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret() << std::endl;
    
    return true;
}