#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

const char* BitcoinExchange::FileOpenException::what() const throw() {
    return "Error: could not open file.";
}

const char* BitcoinExchange::DatabaseEmptyException::what() const throw() {
    return "Error: database is empty.";
}

void BitcoinExchange::trimString(std::string& str) const {
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    if (start == std::string::npos) {
        str = "";
        return;
    }

    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    str = str.substr(start, end - start + 1);
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    // Check format: YYYY-MM-DD
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    // Check if all other characters are digits
    for (size_t i = 0; i < date.length(); i++) {
        if (i != 4 && i != 7 && !isdigit(date[i]))
            return false;
    }

    // Extract year, month, and day
    int year, month, day;
    std::stringstream ss(date);
    char dash;
    ss >> year >> dash >> month >> dash >> day;

    // Check ranges
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    // Check days in month
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) return false;
    } else if (month == 2) {
        // Check for leap year
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeapYear ? 29 : 28)) return false;
    }

    return true;
}

bool BitcoinExchange::isValidValue(const float value) const {
    return value >= 0 && value <= 1000;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw FileOpenException();
    }

    std::string line;
    // Skip header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        float rate;

        if (std::getline(ss, date, ',') && ss >> rate) {
            trimString(date);
            if (isValidDate(date)) {
                _database[date] = rate;
            }
        }
    }

    if (_database.empty()) {
        throw DatabaseEmptyException();
    }
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const {
    // If the date exists in the database, return it
    std::map<std::string, float>::const_iterator it = _database.find(date);
    if (it != _database.end()) {
        return date;
    }

    // Find the closest lower date
    it = _database.lower_bound(date);
    if (it == _database.begin() && date < it->first) {
        // The date is before the first entry in the database
        return "";
    }

    if (it != _database.begin() && (it == _database.end() || it->first > date)) {
        --it; // Get the previous (lower) date
    }

    return it->first;
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
    if (_database.empty()) {
        throw DatabaseEmptyException();
    }

    std::string closestDate = findClosestDate(date);
    if (closestDate.empty()) {
        return 0.0f; // No valid exchange rate found
    }

    return _database.at(closestDate);
}

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw FileOpenException();
    }

    std::string line;
    // Skip header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        // Check if the line contains the pipe separator
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string dateStr = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 1);

        trimString(dateStr);
        trimString(valueStr);

        // Validate date
        if (!isValidDate(dateStr)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Parse and validate value
        float value;
        std::stringstream valueStream(valueStr);

        if (!(valueStream >> value)) {
            std::cout << "Error: not a valid number." << std::endl;
            continue;
        }

        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        // Get exchange rate and calculate result
        float rate = getExchangeRate(dateStr);
        float result = value * rate;

        std::cout << dateStr << " => " << value << " = " << result << std::endl;
    }
}
