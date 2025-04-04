#include "Zombie.hpp"

int main(void)
{
    int N = 5;
    Zombie* horde = zombieHorde(N, "Zombie");
    if (!horde)
    {
        std::cout << "Failed to create horde" << std::endl;
        return (1);
    }
    for (int i = 0; i < N; i++)
    {
        std::cout << "Zombie " << i << ": ";
        horde[i].announce();

    }
    delete[] horde;
    return (0);
}