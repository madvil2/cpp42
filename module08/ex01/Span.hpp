#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    // Constructors and destructor
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    ~Span();

    // Assignment operator
    Span& operator=(const Span& other);

    // Member functions
    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    // Add a range of numbers using iterators
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        unsigned int rangeSize = std::distance(begin, end);
        
        if (_numbers.size() + rangeSize > _maxSize) {
            throw std::out_of_range("Cannot add range: would exceed maximum size");
        }
        
        _numbers.insert(_numbers.end(), begin, end);
    }

    // Exception classes
    class FullSpanException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NoSpanException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif // SPAN_HPP
