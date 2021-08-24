#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
    Zombie *zombies;

    zombies = zombieHorde(10, "coucou");
    for (int i = 0; i < 10; i++)
        zombies[i].announce();
    delete[] zombies;

    std::cout << std::endl;
    
    zombies = zombieHorde(5, "five");
    for (int i = 0; i < 10; i++)
        zombies[i].announce();
    delete[] zombies;

    return 0;
}