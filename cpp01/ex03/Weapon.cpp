#include "Weapon.hpp"

// Constructor
Weapon::Weapon(const std::string& type) : type(type) {}

// Getter for the weapon type
const std::string& Weapon::getType() const
{
    return this->type;
}

// Setter for the weapon type
void Weapon::setType(const std::string& newType)
{
    this->type = newType;
}