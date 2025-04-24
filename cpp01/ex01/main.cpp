#include "Zombie.hpp"
#include <sstream>

int main()
{
    int N = 5;
    std::string baseName = "Horde Zombie";
    
    std::cout << "Creating a zombie horde of " << N << " zombies" << std::endl;
    
    Zombie* horde = zombieHorde(N, baseName);
    
    for (int i = 0; i < N; i++)
    {
        std::cout << "Zombie #" << i + 1 << ": ";
        horde[i].announce();
    }
    
    std::cout << "\nDestroying the zombie horde" << std::endl;

    delete[] horde;
    
    return 0;
}
