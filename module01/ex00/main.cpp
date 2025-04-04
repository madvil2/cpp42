#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();
    randomChump("Stack Zombie");
    delete heapZombie;
    return (0);
}