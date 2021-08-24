#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void    randomChump( std::string name );


int main()
{
    Zombie *zombie;
    Zombie *zombie2;

    randomChump("numero 1");
    std::cout << std::endl;

    randomChump("numero 2");
    std::cout << std::endl;

    randomChump("numero 3");
    std::cout << std::endl;

    zombie = newZombie("numero 4");
    zombie->announce();
    std::cout << std::endl;
    
    zombie2 = newZombie("numero 5");
    zombie2->announce();
    delete zombie;
    delete zombie2;
    return 0;
}