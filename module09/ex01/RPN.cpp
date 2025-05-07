#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

const char* RPN::InvalidExpressionException::what() const throw() {
    return "Error";
}

const char* RPN::DivisionByZeroException::what() const throw() {
    return "Error: division by zero";
}

bool RPN::isOperator(const char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::performOperation(const char op, int a, int b) const {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                throw DivisionByZeroException();
            }
            return a / b;
        default:
            throw InvalidExpressionException();
    }
}

int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        // Check if token is a single digit number
        if (token.length() == 1 && isdigit(token[0])) {
            _stack.push(token[0] - '0');
        }
        // Check if token is an operator
        else if (token.length() == 1 && isOperator(token[0])) {
            if (_stack.size() < 2) {
                throw InvalidExpressionException();
            }
            
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();
            
            int result = performOperation(token[0], a, b);
            _stack.push(result);
        }
        // Invalid token
        else {
            throw InvalidExpressionException();
        }
    }
    
    // After processing all tokens, the stack should contain exactly one value
    if (_stack.size() != 1) {
        throw InvalidExpressionException();
    }
    
    return _stack.top();
}
