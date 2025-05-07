#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <stdexcept>

class RPN {
private:
    std::stack<int> _stack;
    
    // Helper methods
    bool isOperator(const char c) const;
    int performOperation(const char op, int a, int b) const;
    
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    
    // Main method
    int evaluate(const std::string& expression);
    
    // Exception classes
    class InvalidExpressionException : public std::exception {
    public:
        const char* what() const throw();
    };
    
    class DivisionByZeroException : public std::exception {
    public:
        const char* what() const throw();
    };
};

#endif
