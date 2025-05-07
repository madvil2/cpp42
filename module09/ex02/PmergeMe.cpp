#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

const char* PmergeMe::InvalidInputException::what() const throw() {
    return "Error";
}

const std::vector<int>& PmergeMe::getVec() const {
    return _vec;
}

const std::deque<int>& PmergeMe::getDeq() const {
    return _deq;
}

double PmergeMe::getTimeInMicroseconds(struct timeval start, struct timeval end) const {
    return (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

// Ford-Johnson algorithm implementation for vector
void PmergeMe::insertionSortVec(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeVec(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    std::vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::mergeInsertSortVec(std::vector<int>& arr) {
    int n = arr.size();
    
    // Base case
    if (n <= 1)
        return;
    
    // For small arrays, use insertion sort
    if (n <= 16) {
        insertionSortVec(arr, 0, n - 1);
        return;
    }
    
    // Recursively sort
    int mid = n / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());
    
    mergeInsertSortVec(left);
    mergeInsertSortVec(right);
    
    // Merge the sorted halves
    std::merge(left.begin(), left.end(), right.begin(), right.end(), arr.begin());
}

// Ford-Johnson algorithm implementation for deque
void PmergeMe::insertionSortDeq(std::deque<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeDeq(std::deque<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    std::deque<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::mergeInsertSortDeq(std::deque<int>& arr) {
    int n = arr.size();
    
    // Base case
    if (n <= 1)
        return;
    
    // For small arrays, use insertion sort
    if (n <= 16) {
        insertionSortDeq(arr, 0, n - 1);
        return;
    }
    
    // Recursively sort
    int mid = n / 2;
    std::deque<int> left(arr.begin(), arr.begin() + mid);
    std::deque<int> right(arr.begin() + mid, arr.end());
    
    mergeInsertSortDeq(left);
    mergeInsertSortDeq(right);
    
    // Merge the sorted halves
    std::merge(left.begin(), left.end(), right.begin(), right.end(), arr.begin());
}

void PmergeMe::parseAndSort(int argc, char **argv) {
    // Parse input
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        int num;
        
        // Check if the argument is a valid positive integer
        std::istringstream iss(arg);
        if (!(iss >> num) || num <= 0 || iss.rdbuf()->in_avail() != 0) {
            throw InvalidInputException();
        }
        
        _vec.push_back(num);
        _deq.push_back(num);
    }
    
    if (_vec.empty()) {
        throw InvalidInputException();
    }
    
    // Display unsorted sequence
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); i++) {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;
    
    // Sort with vector and measure time
    struct timeval vecStart, vecEnd;
    gettimeofday(&vecStart, NULL);
    mergeInsertSortVec(_vec);
    gettimeofday(&vecEnd, NULL);
    double vecTime = getTimeInMicroseconds(vecStart, vecEnd);
    
    // Sort with deque and measure time
    struct timeval deqStart, deqEnd;
    gettimeofday(&deqStart, NULL);
    mergeInsertSortDeq(_deq);
    gettimeofday(&deqEnd, NULL);
    double deqTime = getTimeInMicroseconds(deqStart, deqEnd);
    
    // Display sorted sequence
    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); i++) {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;
    
    // Display timing information
    displayResults(vecTime, deqTime);
}

void PmergeMe::displayResults(double vecTime, double deqTime) const {
    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " 
              << std::fixed << std::setprecision(5) << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " 
              << std::fixed << std::setprecision(5) << deqTime << " us" << std::endl;
}
