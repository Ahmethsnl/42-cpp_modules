#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <sys/time.h>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <climits>

struct ElementGroup {
    int larger;
    int smaller;
    
    ElementGroup() : larger(0), smaller(0) {}
    ElementGroup(int l, int s) : larger(l), smaller(s) {}
};

struct GroupComparator {
    bool operator()(const ElementGroup& a, const ElementGroup& b) const {
        return a.larger < b.larger;
    }
};

class PmergeMe {
private:
    std::vector<int> _vecContainer;
    std::deque<int> _deqContainer;
    
    void fordJohnsonVector(std::vector<int>& dataSet);
    void fordJohnsonDeque(std::deque<int>& dataSet);
    void hybridInsertionSort(std::vector<int>& data);
    void hybridInsertionSortDeque(std::deque<int>& data);
    void insertElementWithBinarySearch(std::vector<int>& sequence, int element);
    
    bool validateInput(const std::string& input) const;
    double getCurrentTime() const;
    void displaySequence(const std::vector<int>& sequence, bool showAll) const;

public:
    PmergeMe();
    PmergeMe(const PmergeMe& source);
    PmergeMe& operator=(const PmergeMe& source);
    ~PmergeMe();
    
    bool processInput(int argc, char* argv[]);
    void executeSort();
};

#endif