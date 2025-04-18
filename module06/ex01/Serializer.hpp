#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer {
private:
    // Private constructor to prevent instantiation
    Serializer();
    // Private copy constructor
    Serializer(const Serializer& other);
    // Private assignment operator
    Serializer& operator=(const Serializer& other);
    // Private destructor
    ~Serializer();

public:
    // Static method to serialize a pointer to Data
    static uintptr_t serialize(Data* ptr);
    
    // Static method to deserialize an unsigned integer to a pointer to Data
    static Data* deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP
