#include "Serializer.hpp"
#include <iostream>

int main() {
    
    Data* data = new Data;
    data->id = 42;
    data->name = "John Doe";
    data->value = 3.14159;
    
    
    std::cout << "Original Data:" << std::endl;
    std::cout << "Address: " << data << std::endl;
    std::cout << "ID: " << data->id << std::endl;
    std::cout << "Name: " << data->name << std::endl;
    std::cout << "Value: " << data->value << std::endl;
    
    
    uintptr_t serialized = Serializer::serialize(data);
    std::cout << "\nSerialized pointer: " << serialized << std::endl;
    
    
    Data* deserialized = Serializer::deserialize(serialized);
    
    
    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "Address: " << deserialized << std::endl;
    std::cout << "ID: " << deserialized->id << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Value: " << deserialized->value << std::endl;
    
    
    std::cout << "\nPointer comparison:" << std::endl;
    std::cout << "Original pointer: " << data << std::endl;
    std::cout << "Deserialized pointer: " << deserialized << std::endl;
    std::cout << "Are they equal? " << (data == deserialized ? "Yes" : "No") << std::endl;
    
    
    delete data;
    
    return 0;
}
