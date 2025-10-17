#include "PmergeMe.hpp"

ElementGroup::ElementGroup() : larger(0), smaller(0) {}

ElementGroup::ElementGroup(int l, int s) : larger(l), smaller(s) {}

bool GroupComparator::operator()(const ElementGroup& a, const ElementGroup& b) const {
    return a.larger < b.larger;
}

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
    
    for (size_t idx = 0; idx < input.length(); ++idx) {
        if (!isdigit(input[idx]))
            return false;
    }
    
    long numValue = std::atol(input.c_str());
    return numValue >= 0 && numValue <= INT_MAX;
}

double PmergeMe::getCurrentTime() const {
    struct timeval timeStruct;
    gettimeofday(&timeStruct, NULL);
    return (timeStruct.tv_sec * 1000000.0) + timeStruct.tv_usec;
}

bool PmergeMe::processInput(int ac, char** av) {
    if (ac < 2) {
        std::cerr << "Error" << std::endl;
        return false;
    }
    
    for (int i = 1; i < ac; ++i) {
        if (!validateInput(av[i])) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        
        int convertedValue = std::atoi(av[i]);
        _vecContainer.push_back(convertedValue);
        _deqContainer.push_back(convertedValue);
    }
    
    return true;
}

void PmergeMe::displaySequence(const std::vector<int>& sequence, bool showAll) const {
    size_t displayLimit = showAll ? sequence.size() : std::min(static_cast<size_t>(5), sequence.size());
    
    for (size_t pos = 0; pos < displayLimit; ++pos) {
        std::cout << sequence[pos];
        if (pos < displayLimit - 1)
            std::cout << " ";
    }
    
    if (!showAll && sequence.size() > 5)
        std::cout << " [...]";
}

void PmergeMe::hybridInsertionSort(std::vector<int>& data) {
    for (size_t i = 1; i < data.size(); ++i) {
        int keyElement = data[i];
        int insertPos = static_cast<int>(i) - 1;
        
        while (insertPos >= 0 && data[insertPos] > keyElement) {
            data[insertPos + 1] = data[insertPos];
            insertPos--;
        }
        data[insertPos + 1] = keyElement;
    }
}

void PmergeMe::hybridInsertionSortDeque(std::deque<int>& data) {
    for (size_t i = 1; i < data.size(); ++i) {
        int keyElement = data[i];
        size_t insertionPoint = i;
        
        while (insertionPoint > 0 && data[insertionPoint - 1] > keyElement) {
            data[insertionPoint] = data[insertionPoint - 1];
            insertionPoint--;
        }
        data[insertionPoint] = keyElement;
    }
}

void PmergeMe::insertElementWithBinarySearch(std::vector<int>& sequence, int element) {
    if (sequence.empty()) {
        sequence.push_back(element);
        return;
    }
    
    size_t leftIndex = 0;
    size_t rightIndex = sequence.size();
    
    while (leftIndex < rightIndex) {
        size_t midIndex = leftIndex + (rightIndex - leftIndex) / 2;
        if (sequence[midIndex] < element) {
            leftIndex = midIndex + 1;
        } else {
            rightIndex = midIndex;
        }
    }
    
    sequence.insert(sequence.begin() + leftIndex, element);
}

void PmergeMe::fordJohnsonVector(std::vector<int>& dataSet) {
    if (dataSet.size() <= 1)
        return;
    
    if (dataSet.size() <= 20) {
        hybridInsertionSort(dataSet);
        return;
    }
    
    std::vector<ElementGroup> groups;
    size_t groupSize = 2;
    bool hasRemainder = (dataSet.size() % groupSize) != 0;
    std::vector<int> remainderElements;
    
    for (size_t i = 0; i + groupSize - 1 < dataSet.size(); i += groupSize) {
        ElementGroup group;
        if (dataSet[i] > dataSet[i + 1]) {
            group.larger = dataSet[i];
            group.smaller = dataSet[i + 1];
        } else {
            group.larger = dataSet[i + 1];
            group.smaller = dataSet[i];
        }
        groups.push_back(group);
    }
    
    if (hasRemainder) {
        size_t startIndex = (dataSet.size() / groupSize) * groupSize;
        for (size_t i = startIndex; i < dataSet.size(); ++i) {
            remainderElements.push_back(dataSet[i]);
        }
    }
    
    std::sort(groups.begin(), groups.end(), GroupComparator());
    
    std::vector<int> mainSequence;
    std::vector<int> insertionCandidates;
    
    if (!groups.empty()) {
        mainSequence.push_back(groups[0].smaller);
    }
    
    for (size_t i = 0; i < groups.size(); ++i) {
        mainSequence.push_back(groups[i].larger);
        if (i > 0) {
            insertionCandidates.push_back(groups[i].smaller);
        }
    }
    
    for (size_t i = 0; i < insertionCandidates.size(); ++i) {
        insertElementWithBinarySearch(mainSequence, insertionCandidates[i]);
    }
    
    for (size_t i = 0; i < remainderElements.size(); ++i) {
        insertElementWithBinarySearch(mainSequence, remainderElements[i]);
    }
    
    dataSet = mainSequence;
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& dataSet) {
    if (dataSet.size() <= 1)
        return;
    
    if (dataSet.size() <= 20) {
        hybridInsertionSortDeque(dataSet);
        return;
    }
    
    std::vector<int> tempVector;
    tempVector.reserve(dataSet.size());
    
    for (std::deque<int>::iterator it = dataSet.begin(); it != dataSet.end(); ++it) {
        tempVector.push_back(*it);
    }
    
    fordJohnsonVector(tempVector);
    
    dataSet.clear();
    for (std::vector<int>::iterator it = tempVector.begin(); it != tempVector.end(); ++it) {
        dataSet.push_back(*it);
    }
}

void PmergeMe::executeSort() {
    if (_vecContainer.empty())
        return;
    
    std::cout << "Before: ";
    displaySequence(_vecContainer, _vecContainer.size() <= 5);
    std::cout << std::endl;
    
    std::vector<int> vectorWorkspace = _vecContainer;
    std::deque<int> dequeWorkspace = _deqContainer;
    
    double startTimer = getCurrentTime();
    fordJohnsonVector(vectorWorkspace);
    double vectorElapsed = getCurrentTime() - startTimer;
    
    startTimer = getCurrentTime();
    fordJohnsonDeque(dequeWorkspace);
    double dequeElapsed = getCurrentTime() - startTimer;
    
    std::cout << "After: ";
    displaySequence(vectorWorkspace, vectorWorkspace.size() <= 5);
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << _vecContainer.size() 
              << " elements with std::vector : " << std::fixed 
              << std::setprecision(5) << vectorElapsed << " us" << std::endl;
    std::cout << "Time to process a range of " << _deqContainer.size() 
              << " elements with std::deque : " << std::fixed 
              << std::setprecision(5) << dequeElapsed << " us" << std::endl;
}
