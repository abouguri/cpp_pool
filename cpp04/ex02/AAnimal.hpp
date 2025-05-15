#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

// Abstract class (renamed with 'A' prefix as suggested)
class AAnimal {
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const AAnimal &other);
    AAnimal &operator=(const AAnimal &other);
    virtual ~AAnimal(); // Virtual destructor is crucial

    std::string getType() const;
    
    // Pure virtual function makes this class abstract
    virtual void makeSound() const = 0;
};

#endif