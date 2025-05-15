#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    // Deep copy - create a new Brain with the same ideas
    this->brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        
        // Deep copy - delete the old brain and create a new one
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
    return this->brain;
}