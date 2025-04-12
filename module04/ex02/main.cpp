#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main() {
    std::cout << "=== Basic tests ===" << std::endl;
    // Cannot instantiate Animal directly anymore: const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); // Will output the cat sound!
    j->makeSound(); // Will output the dog sound!
    // meta->makeSound(); // Would be animal sound, but no longer possible
    
    delete j; // Should not create a leak
    delete i;
    
    // Try to uncomment this to see compilation error:
    // Animal test; // Cannot instantiate abstract class
    
    std::cout << "\n=== Array of Animals Test ===" << std::endl;
    const int numAnimals = 10;
    Animal* animals[numAnimals];
    
    // Fill the array with half Dogs and half Cats
    for (int k = 0; k < numAnimals; k++) {
        if (k < numAnimals / 2) {
            animals[k] = new Dog();
            std::cout << "Created Dog at index " << k << std::endl;
        } else {
            animals[k] = new Cat();
            std::cout << "Created Cat at index " << k << std::endl;
        }
    }
    
    std::cout << "\n=== Setting some brain ideas ===" << std::endl;
    // Set some ideas for first dog and first cat
    Dog* dogPtr = dynamic_cast<Dog*>(animals[0]);
    Cat* catPtr = dynamic_cast<Cat*>(animals[numAnimals / 2]);
    
    if (dogPtr) {
        dogPtr->setBrainIdea(0, "I want to chase cats!");
        dogPtr->setBrainIdea(1, "I want to play fetch!");
        std::cout << "Dog's first idea: " << dogPtr->getBrainIdea(0) << std::endl;
        std::cout << "Dog's second idea: " << dogPtr->getBrainIdea(1) << std::endl;
    }
    
    if (catPtr) {
        catPtr->setBrainIdea(0, "I want to sleep all day!");
        catPtr->setBrainIdea(1, "I want to ignore my human!");
        std::cout << "Cat's first idea: " << catPtr->getBrainIdea(0) << std::endl;
        std::cout << "Cat's second idea: " << catPtr->getBrainIdea(1) << std::endl;
    }
    
    std::cout << "\n=== Testing deep copy with Dog ===" << std::endl;
    Dog originalDog;
    originalDog.setBrainIdea(0, "Original dog idea");
    std::cout << "Original dog's idea: " << originalDog.getBrainIdea(0) << std::endl;
    
    Dog copyDog = originalDog; // Test copy constructor
    std::cout << "Copy dog's idea: " << copyDog.getBrainIdea(0) << std::endl;
    
    // Modify the copy and check that the original remains unchanged
    copyDog.setBrainIdea(0, "Modified copy dog idea");
    std::cout << "After modification:" << std::endl;
    std::cout << "Original dog's idea: " << originalDog.getBrainIdea(0) << std::endl;
    std::cout << "Copy dog's idea: " << copyDog.getBrainIdea(0) << std::endl;
    
    std::cout << "\n=== Testing deep copy with Cat ===" << std::endl;
    Cat originalCat;
    originalCat.setBrainIdea(0, "Original cat idea");
    
    Cat assignCat;
    assignCat = originalCat; // Test assignment operator
    
    // Modify the assigned cat and check that the original remains unchanged
    assignCat.setBrainIdea(0, "Modified assigned cat idea");
    std::cout << "After modification:" << std::endl;
    std::cout << "Original cat's idea: " << originalCat.getBrainIdea(0) << std::endl;
    std::cout << "Assigned cat's idea: " << assignCat.getBrainIdea(0) << std::endl;
    
    std::cout << "\n=== Deleting array of animals ===" << std::endl;
    // Delete all animals in the array
    for (int k = 0; k < numAnimals; k++) {
        std::cout << "Deleting animal at index " << k << std::endl;
        delete animals[k];
    }
    
    std::cout << "\n=== End of tests ===" << std::endl;
    
    return 0;
}
