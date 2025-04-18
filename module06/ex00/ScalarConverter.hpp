#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cmath>

class ScalarConverter {
private:
    // Private constructor to prevent instantiation
    ScalarConverter();
    // Private copy constructor
    ScalarConverter(const ScalarConverter& other);
    // Private assignment operator
    ScalarConverter& operator=(const ScalarConverter& other);
    // Private destructor
    ~ScalarConverter();

    // Helper methods for type detection
    static bool isChar(const std::string& literal);
    static bool isInt(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);
    static bool isPseudoLiteral(const std::string& literal);

    // Helper methods for conversion
    static void convertFromChar(char c);
    static void convertFromInt(int i);
    static void convertFromFloat(float f);
    static void convertFromDouble(double d);
    static void handlePseudoLiteral(const std::string& literal);

    // Helper methods for printing
    static void printChar(char c);
    static void printInt(int i);
    static void printFloat(float f);
    static void printDouble(double d);

public:
    // Static method to convert a literal
    static void convert(const std::string& literal);
};

#endif // SCALARCONVERTER_HPP
