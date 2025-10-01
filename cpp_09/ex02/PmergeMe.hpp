#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <sys/time.h>

class PmergeMe
{
private:
    std::vector<int> _vectorData;
    std::deque<int> _dequeData;
    
    // Helper functions for vector
    void mergeInsertSortVector(std::vector<int>& container);
    void generateJacobsthalVector(std::vector<int>& jacobsthal, int n);
    
    // Helper functions for deque
    void mergeInsertSortDeque(std::deque<int>& container);
    void generateJacobsthalDeque(std::vector<int>& jacobsthal, int n);
    
    // Utility functions
    bool isValidNumber(const std::string& str) const;
    double getTime() const;
    void printContainer(const std::vector<int>& container, bool showAll = true) const;

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    bool parseArguments(int argc, char* argv[]);
    void sort();
};

#endif