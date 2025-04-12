#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
protected:
    std::string type;

public:
    Animal(void);
    Animal(std::string type);
    Animal(const Animal &src);
    Animal &operator=(const Animal &rhs);
    virtual ~Animal(void);

    std::string getType(void) const;
    virtual void makeSound(void) const;
};

#endif
