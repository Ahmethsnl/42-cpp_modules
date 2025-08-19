#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// swap: değerleri değiştirir
template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

// min: küçük olanı döner, eşitse ikinciyi döner
template <typename T>
T const &min(T const &a, T const &b) {
    return (a < b ? a : b);
}

// max: büyük olanı döner, eşitse ikinciyi döner
template <typename T>
T const &max(T const &a, T const &b) {
    return (a > b ? a : b);
}

#endif
