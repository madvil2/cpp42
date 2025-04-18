#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // For size_t

/**
 * @brief Applies a function to each element of an array.
 * 
 * @tparam T The type of the array elements.
 * @tparam F The type of the function.
 * @param array The address of the array.
 * @param length The length of the array.
 * @param func The function to apply to each element.
 */
template <typename T, typename F>
void iter(T* array, size_t length, F func) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

#endif // ITER_HPP
