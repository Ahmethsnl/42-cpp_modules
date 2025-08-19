#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // std::size_t

// NON-CONST DİZİ: öğeyi T& olarak geçirir -> modifiye edilebilir
template <typename T, typename F>
void iter(T* array, std::size_t length, F f) {
    if (!array || length == 0) return;
    for (std::size_t i = 0; i < length; ++i)
        f(array[i]); // T&
}

// CONST DİZİ: öğeyi const T& olarak geçirir -> sadece okunur
template <typename T, typename F>
void iter(T const* array, std::size_t length, F f) {
    if (!array || length == 0) return;
    for (std::size_t i = 0; i < length; ++i)
        f(array[i]); // const T&
}

#endif // ITER_HPP
