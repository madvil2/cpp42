#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    // Test ClapTrap constructors
    std::cout << "=== Creating ClapTrap instances ===" << std::endl;
    ClapTrap clap1("CL4P-TP");
    
    std::cout << "\n=== Creating ScavTrap instances ===" << std::endl;
    ScavTrap scav1("SC4V-TP");
    ScavTrap scav2("Guardian");
    ScavTrap scav3(scav2); // Testing copy constructor
    
    std::cout << std::endl;

    // Test attacks
    std::cout << "=== Testing attacks ===" << std::endl;
    clap1.attack("Bandit");
    scav1.attack("Super Bandit");
    
    std::cout << std::endl;

    // Test taking damage
    std::cout << "=== Testing damage ===" << std::endl;
    clap1.takeDamage(5);
    scav1.takeDamage(30);
    
    std::cout << std::endl;

    // Test repairs
    std::cout << "=== Testing repairs ===" << std::endl;
    clap1.beRepaired(3);
    scav1.beRepaired(15);
    
    std::cout << std::endl;

    // Test ScavTrap special ability
    std::cout << "=== Testing guardGate ===" << std::endl;
    scav1.guardGate();
    scav2.guardGate();
    
    std::cout << std::endl;

    // Test ScavTrap with fatal damage
    std::cout << "=== Testing ScavTrap with fatal damage ===" << std::endl;
    scav3.takeDamage(100); // This should knock out scav3
    scav3.attack("Someone"); // This should fail
    scav3.guardGate(); // This should fail
    
    std::cout << std::endl;
    
    // Test energy depletion
    std::cout << "=== Testing energy depletion on ScavTrap ===" << std::endl;
    // ScavTrap has 50 energy points, so let's use them all
    for (int i = 0; i < 50; i++) {
        if (i % 10 == 0) {
            std::cout << "Attack attempt " << i + 1 << ": ";
            scav2.attack("Energy Tester");
        } else {
            scav2.attack("Energy Tester");
        }
    }
    
    // One more attack should fail due to no energy
    std::cout << "\nOne more attack with depleted energy: ";
    scav2.attack("Energy Tester");
    
    std::cout << "\n=== End of tests ===" << std::endl;
    std::cout << "\n=== Objects will be destroyed now ===" << std::endl;
    
    return 0;
}
