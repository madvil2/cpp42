#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <ctime>
#include <iomanip>
#include <limits>

class BitcoinExchange {
private:
    std::map<std::string, float> _database;

    // Helper methods
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const float value) const;
    std::string findClosestDate(const std::string& date) const;
    void trimString(std::string& str) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    // Main methods
    void loadDatabase(const std::string& filename);
    void processInputFile(const std::string& filename);
    float getExchangeRate(const std::string& date) const;
    
    // Exception classes
    class FileOpenException : public std::exception {
    public:
        const char* what() const throw();
    };
    
    class DatabaseEmptyException : public std::exception {
    public:
        const char* what() const throw();
    };
};

#endif
