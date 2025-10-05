#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    PmergeMe sorter;
    
    if (!sorter.processInput(argc, argv))
        return 1;
    
    sorter.executeSort();
    
    return 0;
}