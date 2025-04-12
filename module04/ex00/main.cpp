#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Basic tests from subject ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); // Will output the cat sound!
    j->makeSound(); // Will output the dog sound!
    meta->makeSound(); // Will output the animal sound!
    
    delete meta;
    delete j;
    delete i;
    
    std::cout << "\n=== Testing WrongAnimal/WrongCat ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;
    
    wrongCat->makeSound(); // Will output the WrongAnimal sound, not the WrongCat sound!
    wrongMeta->makeSound();
    
    delete wrongMeta;
    delete wrongCat;
    
    std::cout << "\n=== Testing additional scenarios ===" << std::endl;
    
    // Testing the direct usage of derived classes (not through base class pointer)
    std::cout << "\n-- Direct usage of derived classes --" << std::endl;
    Dog directDog;
    Cat directCat;
    
    std::cout << "Direct Dog type: " << directDog.getType() << std::endl;
    std::cout << "Direct Cat type: " << directCat.getType() << std::endl;
    
    std::cout << "Direct Dog sound: ";
    directDog.makeSound();
    std::cout << "Direct Cat sound: ";
    directCat.makeSound();
    
    // Testing copy constructor and assignment operator
    std::cout << "\n-- Testing copy constructor --" << std::endl;
    Dog originalDog;
    Dog copyDog(originalDog);
    
    std::cout << "Original Dog type: " << originalDog.getType() << std::endl;
    std::cout << "Copy Dog type: " << copyDog.getType() << std::endl;
    
    std::cout << "\n-- Testing assignment operator --" << std::endl;
    Cat originalCat;
    Cat assignCat;
    assignCat = originalCat;
    
    std::cout << "Original Cat type: " << originalCat.getType() << std::endl;
    std::cout << "Assigned Cat type: " << assignCat.getType() << std::endl;
    
    // Direct usage of WrongCat (will have its own sound)
    std::cout << "\n-- Direct usage of WrongCat --" << std::endl;
    WrongCat directWrongCat;
    
    std::cout << "Direct WrongCat type: " << directWrongCat.getType() << std::endl;
    std::cout << "Direct WrongCat sound: ";
    directWrongCat.makeSound(); // This will correctly use WrongCat's sound
    
    std::cout << "\n=== End of tests ===" << std::endl;
    
    return 0;
}
