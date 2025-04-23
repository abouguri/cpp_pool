#include "Zombie.hpp"

int main()
{
    std::cout << "Creating a zombie on the stack:" << std::endl;
    randomChump("Stack Zombie");
    std::cout << std::endl;

    std::cout << "Creating a zombie on the heap:" << std::endl;
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();
    
    delete heapZombie;

    return 0;
}