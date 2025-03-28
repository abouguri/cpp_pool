#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

class PhoneBook
{
private:
    Contact contacts[8];
    int     oldestContactIndex;
    int     contactCount;
    
    // Utility methods
    std::string truncateString(const std::string &str) const;
    void displayContactHeader() const;
    void displayContactRow(int index) const;
    
public:
    PhoneBook();
    ~PhoneBook();
    
    void addContact(const Contact &contact);
    void searchContact() const;
    bool displayContactDetails(int index) const;
};

#endif