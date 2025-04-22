#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
private:
    Brain *brain;

public:
    Dog(void);
    Dog(const Dog &src);
    Dog &operator=(const Dog &rhs);
    virtual ~Dog(void);

    virtual void makeSound(void) const;
    
    std::string getBrainIdea(int index) const;
    void setBrainIdea(int index, std::string idea);
};

#endif
