#include "ClapTrap.hpp"

int main(void) {
    // Test constructors
    std::cout << "=== Creating ClapTrap instances ===" << std::endl;
    ClapTrap defaultTrap;
    ClapTrap clap1("CL4P-TP");
    ClapTrap clap2("FR4G-TP");
    ClapTrap clap3(clap1); // Copy constructor
    
    std::cout << std::endl;

    // Test attacks
    std::cout << "=== Testing attacks ===" << std::endl;
    clap1.attack("Bandit");
    clap2.attack("Skag");
    
    std::cout << std::endl;

    // Test taking damage
    std::cout << "=== Testing damage ===" << std::endl;
    clap1.takeDamage(5);
    clap2.takeDamage(15); // This should knock out FR4G-TP
    
    std::cout << std::endl;

    // Test repairs
    std::cout << "=== Testing repairs ===" << std::endl;
    clap1.beRepaired(3);
    clap2.beRepaired(5); // This should fail because FR4G-TP is knocked out
    
    std::cout << std::endl;

    // Test energy depletion
    std::cout << "=== Testing energy depletion ===" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "Attack attempt " << i + 1 << ": ";
        clap3.attack("Energy Tester");
    }
    
    // One more attack should fail due to no energy
    std::cout << "\nOne more attack with depleted energy: ";
    clap3.attack("Energy Tester");
    
    std::cout << std::endl;
    
    // Test repair with depleted energy
    std::cout << "=== Testing repair with depleted energy ===" << std::endl;
    clap3.beRepaired(1);
    
    std::cout << std::endl;
    std::cout << "=== End of tests ===" << std::endl;
    
    return 0;
}
