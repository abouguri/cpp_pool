#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    // Test with proper polymorphism
    std::cout << "\n===== Testing Animal polymorphism =====\n" << std::endl;
    
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); // will output the cat sound!
    j->makeSound(); // will output the dog sound!
    meta->makeSound(); // will output the animal sound!

    // Clean up
    delete meta;
    delete j;
    delete i;

    // Test with wrong polymorphism
    std::cout << "\n===== Testing WrongAnimal polymorphism =====\n" << std::endl;
    
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;
    
    wrongCat->makeSound(); // will output the WrongAnimal sound, not the WrongCat sound!
    wrongMeta->makeSound();

    // Additional test with the actual WrongCat object
    std::cout << "\n===== Additional WrongCat test =====\n" << std::endl;
    
    const WrongCat actualWrongCat;
    std::cout << actualWrongCat.getType() << " " << std::endl;
    actualWrongCat.makeSound(); // This will output the WrongCat sound

    // Clean up
    delete wrongMeta;
    delete wrongCat;

    return 0;
}