#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

/**
 * @brief Finds the first occurrence of an integer in a container.
 * 
 * @tparam T The type of the container.
 * @param container The container to search in.
 * @param value The integer value to find.
 * @return Iterator to the first occurrence of the value in the container.
 * @throw std::runtime_error If the value is not found in the container.
 */
template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end()) {
        throw std::runtime_error("Value not found in container");
    }
    
    return it;
}

/**
 * @brief Finds the first occurrence of an integer in a const container.
 * 
 * @tparam T The type of the container.
 * @param container The const container to search in.
 * @param value The integer value to find.
 * @return Const iterator to the first occurrence of the value in the container.
 * @throw std::runtime_error If the value is not found in the container.
 */
template <typename T>
typename T::const_iterator easyfind(const T& container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end()) {
        throw std::runtime_error("Value not found in container");
    }
    
    return it;
}

#endif // EASYFIND_HPP
