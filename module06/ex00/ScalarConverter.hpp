#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cmath>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    static bool isChar(const std::string& literal);
    static bool isInt(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);
    static bool isPseudoLiteral(const std::string& literal);

    static void convertFromChar(char c);
    static void convertFromInt(int i);
    static void convertFromFloat(float f);
    static void convertFromDouble(double d);
    static void handlePseudoLiteral(const std::string& literal);

    static void printChar(char c);
    static void printInt(int i);
    static void printFloat(float f);
    static void printDouble(double d);

public:
    static void convert(const std::string& literal);
};

#endif