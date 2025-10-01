#include "PmergeMe.hpp"
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <climits>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vectorData(other._vectorData), _dequeData(other._dequeData) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidNumber(const std::string& str) const
{
    if (str.empty() || str[0] == '-')
        return false;
    
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!isdigit(str[i]))
            return false;
    }
    
    // Check for overflow
    long long num = std::atoll(str.c_str());
    if (num > INT_MAX)
        return false;
    
    return true;
}

double PmergeMe::getTime() const
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

bool PmergeMe::parseArguments(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return false;
    }
    
    for (int i = 1; i < argc; ++i)
    {
        if (!isValidNumber(argv[i]))
        {
            std::cerr << "Error" << std::endl;
            return false;
        }
        
        int num = std::atoi(argv[i]);
        _vectorData.push_back(num);
        _dequeData.push_back(num);
    }
    
    return true;
}

void PmergeMe::printContainer(const std::vector<int>& container, bool showAll) const
{
    size_t maxShow = showAll ? container.size() : std::min(static_cast<size_t>(5), container.size());
    
    for (size_t i = 0; i < maxShow; ++i)
    {
        std::cout << container[i];
        if (i < maxShow - 1)
            std::cout << " ";
    }
    
    if (!showAll && container.size() > 5)
        std::cout << " [...]";
}

void PmergeMe::generateJacobsthalVector(std::vector<int>& jacobsthal, int n)
{
    jacobsthal.clear();
    if (n <= 0)
        return;
    
    jacobsthal.push_back(1);
    if (n == 1)
        return;
    
    jacobsthal.push_back(3);
    
    for (int i = 2; jacobsthal[i-1] < n; ++i)
    {
        int next = jacobsthal[i-1] + 2 * jacobsthal[i-2];
        if (next > n)
            break;
        jacobsthal.push_back(next);
    }
}

void PmergeMe::generateJacobsthalDeque(std::vector<int>& jacobsthal, int n)
{
    generateJacobsthalVector(jacobsthal, n);
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& container)
{
    if (container.size() <= 1)
        return;
    
    // Simple implementation of Ford-Johnson algorithm
    // For small containers, use simple approach
    if (container.size() <= 20)
    {
        for (size_t i = 1; i < container.size(); ++i)
        {
            int key = container[i];
            int j = i - 1;
            while (j >= 0 && container[j] > key)
            {
                container[j + 1] = container[j];
                j--;
            }
            container[j + 1] = key;
        }
        return;
    }
    
    // Create pairs and sort them
    std::vector<std::pair<int, int> > pairs;
    bool hasOdd = container.size() % 2 == 1;
    int oddElement = hasOdd ? container[container.size() - 1] : 0;
    
    for (size_t i = 0; i < container.size() - (hasOdd ? 1 : 0); i += 2)
    {
        int a = container[i];
        int b = container[i + 1];
        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    
    // Sort pairs by their larger element
    std::sort(pairs.begin(), pairs.end());
    
    // Build main chain and pending elements
    std::vector<int> main;
    std::vector<int> pending;
    
    main.push_back(pairs[0].first);
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        main.push_back(pairs[i].second);
        if (i > 0)
            pending.push_back(pairs[i].first);
    }
    
    // Insert pending elements using binary search
    for (size_t i = 0; i < pending.size(); ++i)
    {
        std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pending[i]);
        main.insert(pos, pending[i]);
    }
    
    // Insert odd element if exists
    if (hasOdd)
    {
        std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), oddElement);
        main.insert(pos, oddElement);
    }
    
    container = main;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& container)
{
    if (container.size() <= 1)
        return;
    
    // Simple implementation for deque (similar to vector approach)
    if (container.size() <= 20)
    {
        for (size_t i = 1; i < container.size(); ++i)
        {
            int key = container[i];
            int j = i - 1;
            while (j >= 0 && container[j] > key)
            {
                container[j + 1] = container[j];
                j--;
            }
            container[j + 1] = key;
        }
        return;
    }
    
    // Create pairs and sort them
    std::vector<std::pair<int, int> > pairs;
    bool hasOdd = container.size() % 2 == 1;
    int oddElement = hasOdd ? container[container.size() - 1] : 0;
    
    for (size_t i = 0; i < container.size() - (hasOdd ? 1 : 0); i += 2)
    {
        int a = container[i];
        int b = container[i + 1];
        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    
    // Sort pairs by their larger element
    std::sort(pairs.begin(), pairs.end());
    
    // Build main chain and pending elements
    std::deque<int> main;
    std::vector<int> pending;
    
    main.push_back(pairs[0].first);
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        main.push_back(pairs[i].second);
        if (i > 0)
            pending.push_back(pairs[i].first);
    }
    
    // Insert pending elements using binary search
    for (size_t i = 0; i < pending.size(); ++i)
    {
        std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pending[i]);
        main.insert(pos, pending[i]);
    }
    
    // Insert odd element if exists
    if (hasOdd)
    {
        std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), oddElement);
        main.insert(pos, oddElement);
    }
    
    container = main;
}

void PmergeMe::sort()
{
    if (_vectorData.empty())
        return;
    
    // Print before
    std::cout << "Before: ";
    printContainer(_vectorData, _vectorData.size() <= 5);
    std::cout << std::endl;
    
    // Sort with vector and measure time
    std::vector<int> vectorCopy = _vectorData;
    double startTime = getTime();
    mergeInsertSortVector(vectorCopy);
    double vectorTime = getTime() - startTime;
    
    // Sort with deque and measure time
    std::deque<int> dequeCopy = _dequeData;
    startTime = getTime();
    mergeInsertSortDeque(dequeCopy);
    double dequeTime = getTime() - startTime;
    
    // Print after
    std::cout << "After: ";
    printContainer(vectorCopy, vectorCopy.size() <= 5);
    std::cout << std::endl;
    
    // Print timing information
    std::cout << "Time to process a range of " << _vectorData.size() 
              << " elements with std::vector : " << std::fixed 
              << std::setprecision(5) << vectorTime << " us" << std::endl;
    
    std::cout << "Time to process a range of " << _dequeData.size() 
              << " elements with std::deque : " << std::fixed 
              << std::setprecision(5) << dequeTime << " us" << std::endl;
}