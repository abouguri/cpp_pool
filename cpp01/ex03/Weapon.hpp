#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
private:
    std::string type; // Private attribute to store the weapon's type

public:
    // Constructor
    Weapon(const std::string& type);

    // Getter: Returns a const reference to the weapon's type
    const std::string& getType() const;

    // Setter: Sets the weapon's type
    void setType(const std::string& newType);
};

#endif