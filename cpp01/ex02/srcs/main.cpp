#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main()
{
    ZombieEvent ze;
    Zombie *z1 = ze.newZombie("Jean");
    z1->announce();
    ze.setZombieType("ugly");
    
    Zombie *z2 = ze.newZombie("Mick");
    z1->announce();
    z2->announce();

    ze.randomChump();
    ze.randomChump();
    ze.randomChump();

    delete z1;
    delete z2;
    return 0;
}