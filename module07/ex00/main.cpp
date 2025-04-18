#include "whatever.hpp"
#include <iostream>
#include <string>

int main() {
    
    int a = 2;
    int b = 3;
    
    std::cout << "=== Testing with integers ===" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    
    std::cout << "swap(a, b)" << std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    
    
    float c = 42.42f;
    float d = 21.21f;
    
    std::cout << "\n=== Testing with floats ===" << std::endl;
    std::cout << "c = " << c << ", d = " << d << std::endl;
    
    std::cout << "swap(c, d)" << std::endl;
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
    
    
    std::string e = "chaine1";
    std::string f = "chaine2";
    
    std::cout << "\n=== Testing with strings ===" << std::endl;
    std::cout << "e = " << e << ", f = " << f << std::endl;
    
    std::cout << "swap(e, f)" << std::endl;
    ::swap(e, f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    
    std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
    std::cout << "max(e, f) = " << ::max(e, f) << std::endl;
    
    
    int g = 42;
    int h = 42;
    
    std::cout << "\n=== Testing with equal values ===" << std::endl;
    std::cout << "g = " << g << ", h = " << h << std::endl;
    
    std::cout << "min(g, h) = " << ::min(g, h) << " (should be h)" << std::endl;
    std::cout << "max(g, h) = " << ::max(g, h) << " (should be h)" << std::endl;
    
    
    std::cout << "\n=== Testing with the example from the subject ===" << std::endl;
    int i = 2;
    int j = 3;
    ::swap(i, j);
    std::cout << "i = " << i << ", j = " << j << std::endl;
    std::cout << "min(i, j) = " << ::min(i, j) << std::endl;
    std::cout << "max(i, j) = " << ::max(i, j) << std::endl;
    
    return 0;
}
