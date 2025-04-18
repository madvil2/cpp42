#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/**
 * @brief Swaps the values of two given parameters.
 *
 * @tparam T The type of the parameters.
 * @param a The first parameter.
 * @param b The second parameter.
 */
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

/**
 * @brief Compares the two values passed as parameters and returns the smallest one.
 *        If they are equal, it returns the second one.
 *
 * @tparam T The type of the parameters.
 * @param a The first parameter.
 * @param b The second parameter.
 * @return T The smallest value, or the second one if they are equal.
 */
template <typename T>
T const & min(T const & a, T const & b) {
    return (a < b) ? a : b;
}

/**
 * @brief Compares the two values passed as parameters and returns the greatest one.
 *        If they are equal, it returns the second one.
 *
 * @tparam T The type of the parameters.
 * @param a The first parameter.
 * @param b The second parameter.
 * @return T The greatest value, or the second one if they are equal.
 */
template <typename T>
T const & max(T const & a, T const & b) {
    return (a > b) ? a : b;
}

#endif // WHATEVER_HPP
