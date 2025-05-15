#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define ANIMALS_COUNT 10

int main() {
    // Basic test as per the exercise
    std::cout << "\n===== Basic Test =====\n" << std::endl;
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j; // should not create a leak
    delete i;
    
    // Array of animals test
    std::cout << "\n===== Array of Animals Test =====\n" << std::endl;
    
    Animal* animals[ANIMALS_COUNT];
    
    // Create half dogs and half cats
    for (int i = 0; i < ANIMALS_COUNT; i++) {
        if (i < ANIMALS_COUNT / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    // Delete all animals
    for (int i = 0; i < ANIMALS_COUNT; i++) {
        delete animals[i];
    }
    
    // Deep copy test
    std::cout << "\n===== Deep Copy Test for Dog =====\n" << std::endl;
    
    Dog* originalDog = new Dog();
    // Set some ideas in the original dog's brain
    originalDog->getBrain()->setIdea(0, "I love bones!");
    originalDog->getBrain()->setIdea(1, "I want to chase cats!");
    
    // Create a copy of the dog
    Dog* copyDog = new Dog(*originalDog);
    
    // Show that they have the same ideas initially
    std::cout << "Original Dog idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Dog idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;
    
    // Change an idea in the original dog and show the copy is unchanged (deep copy)
    originalDog->getBrain()->setIdea(0, "I hate bones now!");
    std::cout << "After modifying original:" << std::endl;
    std::cout << "Original Dog idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Dog idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;
    
    delete originalDog;
    delete copyDog;
    
    // Deep copy test for Cat
    std::cout << "\n===== Deep Copy Test for Cat =====\n" << std::endl;
    
    Cat* originalCat = new Cat();
    // Set some ideas in the original cat's brain
    originalCat->getBrain()->setIdea(0, "I love fish!");
    originalCat->getBrain()->setIdea(1, "I want to sleep all day!");
    
    // Test copy constructor
    Cat* copyCat = new Cat(*originalCat);
    
    // Show that they have the same ideas initially
    std::cout << "Original Cat idea 0: " << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Cat idea 0: " << copyCat->getBrain()->getIdea(0) << std::endl;
    
    // Change an idea in the original cat and show the copy is unchanged (deep copy)
    originalCat->getBrain()->setIdea(0, "I hate fish now!");
    std::cout << "After modifying original:" << std::endl;
    std::cout << "Original Cat idea 0: " << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Cat idea 0: " << copyCat->getBrain()->getIdea(0) << std::endl;
    
    // Test assignment operator
    Cat* assignmentCat = new Cat();
    *assignmentCat = *originalCat;
    
    std::cout << "Original Cat idea 0: " << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "Assignment Cat idea 0: " << assignmentCat->getBrain()->getIdea(0) << std::endl;
    
    // Change an idea in the original cat and show the assignment is unchanged (deep copy)
    originalCat->getBrain()->setIdea(0, "Fish are boring!");
    std::cout << "After modifying original:" << std::endl;
    std::cout << "Original Cat idea 0: " << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "Assignment Cat idea 0: " << assignmentCat->getBrain()->getIdea(0) << std::endl;
    
    delete originalCat;
    delete copyCat;
    delete assignmentCat;
    
    return 0;
}