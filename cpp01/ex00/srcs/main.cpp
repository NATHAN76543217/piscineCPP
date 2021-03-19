#include "Pony.hpp"

void	ponyOnTheStack()
{
    Pony    stackyPony("steacky");

    stackyPony.look();
    stackyPony.run();
    stackyPony.jump();
    stackyPony.run();
    stackyPony.look();
    stackyPony.jump();
    stackyPony.jump();
    stackyPony.look();
    stackyPony.run();
    std::cout << "Leaving 'ponyOnStack' function." << std::endl;
	return ;
}

void	ponyOnTheHeap()
{
    Pony    *heapyPony = new Pony("heapy");

    heapyPony->look();
    heapyPony->run();
    heapyPony->jump();
    heapyPony->run();
    heapyPony->look();
    heapyPony->jump();
    heapyPony->jump();
    heapyPony->look();
    heapyPony->run();
    std::cout << "Leaving 'ponyonHeap' function." << std::endl;
	delete heapyPony;
    return ;
}

int main()
{
    std::cout << "Enter in 'ponyOnStack' function." << std::endl;
    ponyOnTheStack();
    std::cout << "Enter in 'ponyOnHeap' function." << std::endl;
    ponyOnTheHeap();
    return 0;
}