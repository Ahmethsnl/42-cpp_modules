#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    PmergeMe sorter;
    
    if (!sorter.parseArguments(argc, argv))
        return 1;
    
    sorter.sort();
    
    return 0;
}