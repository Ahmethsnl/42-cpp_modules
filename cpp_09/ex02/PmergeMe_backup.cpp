#include "PmergeMe.hpp"
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <climits>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& source) : _vecContainer(source._vecContainer), _deqContainer(source._deqContainer) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& source) {
    if (this != &source) {
        _vecContainer = source._vecContainer;
        _deqContainer = source._deqContainer;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::validateInput(const std::string& input) const {
    if (input.empty() || input[0] == '-')
        return false;
    
    for (std::string::const_iterator it = input.begin(); it != input.end(); ++it) {
        if (!isdigit(*it))
            return false;
    }
    
    long value = std::atol(input.c_str());
    return value <= INT_MAX;
}

double PmergeMe::getCurrentTime() const {
    struct timeval timeValue;
    gettimeofday(&timeValue, NULL);
    return timeValue.tv_sec * 1000000.0 + timeValue.tv_usec;
}

bool PmergeMe::processInput(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return false;
    }
    
    for (int i = 1; i < argc; ++i) {
        if (!validateInput(argv[i])) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        
        int value = std::atoi(argv[i]);
        _vecContainer.push_back(value);
        _deqContainer.push_back(value);
    }
    
    return true;
}

void PmergeMe::displaySequence(const std::vector<int>& sequence, bool full) const {
    size_t limit = full ? sequence.size() : std::min(static_cast<size_t>(5), sequence.size());
    
    for (size_t i = 0; i < limit; ++i) {
        std::cout << sequence[i];
        if (i < limit - 1)
            std::cout << " ";
    }
    
    if (!full && sequence.size() > 5)
        std::cout << " [...]";
}

void PmergeMe::fordJohnsonVector(std::vector<int>& data) {
    if (data.size() <= 1)
        return;
    
    if (data.size() <= 15) {
        for (size_t i = 1; i < data.size(); ++i) {
            int current = data[i];
            int position = i - 1;
            while (position >= 0 && data[position] > current) {
                data[position + 1] = data[position];
                position--;
            }
            data[position + 1] = current;
        }
        return;
    }
    
    std::vector<std::pair<int, int> > elementPairs;
    bool hasUnpairedElement = data.size() % 2 == 1;
    int unpairedValue = hasUnpairedElement ? data.back() : 0;
    
    size_t pairCount = data.size() / 2;
    for (size_t i = 0; i < pairCount; ++i) {
        int first = data[i * 2];
        int second = data[i * 2 + 1];
        if (first < second)
            elementPairs.push_back(std::make_pair(second, first));
        else
            elementPairs.push_back(std::make_pair(first, second));
    }
    
    std::sort(elementPairs.begin(), elementPairs.end());
    
    std::vector<int> sortedSequence;
    std::vector<int> pendingElements;
    
    sortedSequence.push_back(elementPairs[0].second);
    for (size_t i = 0; i < elementPairs.size(); ++i) {
        sortedSequence.push_back(elementPairs[i].first);
        if (i > 0)
            pendingElements.push_back(elementPairs[i].second);
    }
    
    for (size_t i = 0; i < pendingElements.size(); ++i) {
        std::vector<int>::iterator insertPos = std::lower_bound(
            sortedSequence.begin(), sortedSequence.end(), pendingElements[i]);
        sortedSequence.insert(insertPos, pendingElements[i]);
    }
    
    if (hasUnpairedElement) {
        std::vector<int>::iterator insertPos = std::lower_bound(
            sortedSequence.begin(), sortedSequence.end(), unpairedValue);
        sortedSequence.insert(insertPos, unpairedValue);
    }
    
    data = sortedSequence;
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& data) {
    if (data.size() <= 1)
        return;
    
    if (data.size() <= 15) {
        for (size_t i = 1; i < data.size(); ++i) {
            int current = data[i];
            int position = i - 1;
            while (position >= 0 && data[position] > current) {
                data[position + 1] = data[position];
                position--;
            }
            data[position + 1] = current;
        }
        return;
    }
    
    std::vector<std::pair<int, int> > elementPairs;
    bool hasUnpairedElement = data.size() % 2 == 1;
    int unpairedValue = hasUnpairedElement ? data.back() : 0;
    
    size_t pairCount = data.size() / 2;
    for (size_t i = 0; i < pairCount; ++i) {
        int first = data[i * 2];
        int second = data[i * 2 + 1];
        if (first < second)
            elementPairs.push_back(std::make_pair(second, first));
        else
            elementPairs.push_back(std::make_pair(first, second));
    }
    
    std::sort(elementPairs.begin(), elementPairs.end());
    
    std::deque<int> sortedSequence;
    std::vector<int> pendingElements;
    
    sortedSequence.push_back(elementPairs[0].second);
    for (size_t i = 0; i < elementPairs.size(); ++i) {
        sortedSequence.push_back(elementPairs[i].first);
        if (i > 0)
            pendingElements.push_back(elementPairs[i].second);
    }
    
    for (size_t i = 0; i < pendingElements.size(); ++i) {
        std::deque<int>::iterator insertPos = std::lower_bound(
            sortedSequence.begin(), sortedSequence.end(), pendingElements[i]);
        sortedSequence.insert(insertPos, pendingElements[i]);
    }
    
    if (hasUnpairedElement) {
        std::deque<int>::iterator insertPos = std::lower_bound(
            sortedSequence.begin(), sortedSequence.end(), unpairedValue);
        sortedSequence.insert(insertPos, unpairedValue);
    }
    
    data = sortedSequence;
}

void PmergeMe::executeSort() {
    if (_vecContainer.empty())
        return;
    
    std::cout << "Before: ";
    displaySequence(_vecContainer, _vecContainer.size() <= 5);
    std::cout << std::endl;
    
    std::vector<int> vectorCopy = _vecContainer;
    std::deque<int> dequeCopy = _deqContainer;
    
    double startTime = getCurrentTime();
    fordJohnsonVector(vectorCopy);
    double vectorDuration = getCurrentTime() - startTime;
    
    startTime = getCurrentTime();
    fordJohnsonDeque(dequeCopy);
    double dequeDuration = getCurrentTime() - startTime;
    
    std::cout << "After: ";
    displaySequence(vectorCopy, vectorCopy.size() <= 5);
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << _vecContainer.size() 
              << " elements with std::vector : " << std::fixed 
              << std::setprecision(5) << vectorDuration << " us" << std::endl;
    std::cout << "Time to process a range of " << _deqContainer.size() 
              << " elements with std::deque : " << std::fixed 
              << std::setprecision(5) << dequeDuration << " us" << std::endl;
}