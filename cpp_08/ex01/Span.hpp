#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span(unsigned int maxSize);

    ~Span();

    Span(const Span& other);
    Span& operator=(const Span& other);

    void addNumber(int number);
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end);
    int shortestSpan() const;
    int longestSpan() const;

    class SpanFullException : public std::exception {
    public:
        const char* what() const throw() {
            return "Span is already full";
        }
    };

    class NoSpanException : public std::exception {
    public:
        const char* what() const throw() {
            return "Not enough numbers to find a span";
        }
    };
};

#endif
