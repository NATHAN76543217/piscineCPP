#include "ZombieHorde.hpp"

int main()
{
    std::cout << "first horde" << std::endl;
    ZombieHorde zh(5);
    zh.announce();
    std::cout << "second horde (heap)" << std::endl;
    ZombieHorde *zh2 = new ZombieHorde(8);
    zh2->announce();

    std::cout << "destroying second (heap) horde" << std::endl;
    delete zh2;

    std::cout << "leaving function main." << std::endl;

    return 0;
}