#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include <sys/time.h>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int> _deq;
    
    // Helper methods for vector
    void mergeInsertSortVec(std::vector<int>& arr);
    void insertionSortVec(std::vector<int>& arr, int left, int right);
    void mergeVec(std::vector<int>& arr, int left, int mid, int right);
    
    // Helper methods for deque
    void mergeInsertSortDeq(std::deque<int>& arr);
    void insertionSortDeq(std::deque<int>& arr, int left, int right);
    void mergeDeq(std::deque<int>& arr, int left, int mid, int right);
    
    // Time measurement
    double getTimeInMicroseconds(struct timeval start, struct timeval end) const;
    
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    // Main methods
    void parseAndSort(int argc, char **argv);
    void displayResults(double vecTime, double deqTime) const;
    
    // Getters
    const std::vector<int>& getVec() const;
    const std::deque<int>& getDeq() const;
    
    // Exception classes
    class InvalidInputException : public std::exception {
    public:
        const char* what() const throw();
    };
};

#endif
