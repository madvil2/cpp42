#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}


ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other; 
}


ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other; 
    return *this;
}


ScalarConverter::~ScalarConverter() {}


bool ScalarConverter::isChar(const std::string& literal) {
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}


bool ScalarConverter::isInt(const std::string& literal) {
    if (literal.empty()) return false;
    
    size_t i = 0;
    if (literal[0] == '+' || literal[0] == '-') i++;
    
    for (; i < literal.length(); i++) {
        if (!isdigit(literal[i])) return false;
    }
    
    return true;
}


bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") return true;
    
    if (literal.length() < 2 || literal[literal.length() - 1] != 'f') return false;
    
    size_t i = 0;
    bool hasDecimal = false;
    
    if (literal[0] == '+' || literal[0] == '-') i++;
    
    for (; i < literal.length() - 1; i++) {
        if (literal[i] == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (!isdigit(literal[i])) {
            return false;
        }
    }
    
    return hasDecimal;
}


bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal == "nan" || literal == "+inf" || literal == "-inf") return true;
    
    size_t i = 0;
    bool hasDecimal = false;
    
    if (literal[0] == '+' || literal[0] == '-') i++;
    
    for (; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (!isdigit(literal[i])) {
            return false;
        }
    }
    
    return hasDecimal;
}


bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
    return (literal == "nan" || literal == "+inf" || literal == "-inf" ||
            literal == "nanf" || literal == "+inff" || literal == "-inff");
}


void ScalarConverter::printChar(char c) {
    if (isprint(c)) {
        std::cout << "char: '" << c << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }
}


void ScalarConverter::printInt(int i) {
    std::cout << "int: " << i << std::endl;
}


void ScalarConverter::printFloat(float f) {
    if (f == static_cast<int>(f)) {
        std::cout << "float: " << f << ".0f" << std::endl;
    } else {
        std::cout << "float: " << f << "f" << std::endl;
    }
}


void ScalarConverter::printDouble(double d) {
    if (d == static_cast<int>(d)) {
        std::cout << "double: " << d << ".0" << std::endl;
    } else {
        std::cout << "double: " << d << std::endl;
    }
}


void ScalarConverter::convertFromChar(char c) {
    printChar(c);
    printInt(static_cast<int>(c));
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}


void ScalarConverter::convertFromInt(int i) {
    
    if (i >= 0 && i <= 127) {
        printChar(static_cast<char>(i));
    } else {
        std::cout << "char: impossible" << std::endl;
    }
    
    printInt(i);
    printFloat(static_cast<float>(i));
    printDouble(static_cast<double>(i));
}


void ScalarConverter::convertFromFloat(float f) {
    
    if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127) {
        std::cout << "char: impossible" << std::endl;
    } else {
        printChar(static_cast<char>(f));
    }
    
    
    if (std::isnan(f) || std::isinf(f) || f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        printInt(static_cast<int>(f));
    }
    
    printFloat(f);
    printDouble(static_cast<double>(f));
}


void ScalarConverter::convertFromDouble(double d) {
    
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127) {
        std::cout << "char: impossible" << std::endl;
    } else {
        printChar(static_cast<char>(d));
    }
    
    
    if (std::isnan(d) || std::isinf(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        printInt(static_cast<int>(d));
    }
    
    
    if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max()) {
        std::cout << "float: impossible" << std::endl;
    } else {
        printFloat(static_cast<float>(d));
    }
    
    printDouble(d);
}


void ScalarConverter::handlePseudoLiteral(const std::string& literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (literal == "nan" || literal == "+inf" || literal == "-inf") {
        if (literal == "nan") {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        } else if (literal == "+inf") {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        } else { 
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
    } else { 
        if (literal == "nanf") {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        } else if (literal == "+inff") {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        } else { 
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
    }
}


void ScalarConverter::convert(const std::string& literal) {
    
    if (isPseudoLiteral(literal)) {
        handlePseudoLiteral(literal);
        return;
    }
    
    
    if (isChar(literal)) {
        convertFromChar(literal[1]);
        return;
    }
    
    
    if (isInt(literal)) {
        long long value = std::atoll(literal.c_str());
        if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(value) << std::endl;
        } else {
            convertFromInt(static_cast<int>(value));
        }
        return;
    }
    
    
    if (isFloat(literal)) {
        float value = std::atof(literal.c_str());
        convertFromFloat(value);
        return;
    }
    
    
    if (isDouble(literal)) {
        double value = std::atof(literal.c_str());
        convertFromDouble(value);
        return;
    }
    
    
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}
