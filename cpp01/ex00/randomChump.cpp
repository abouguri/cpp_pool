#include "Zombie.hpp"

// Creates a zombie on the stack that announces itself
void randomChump(std::string name) {
    Zombie zombie(name);
    zombie.announce();
}