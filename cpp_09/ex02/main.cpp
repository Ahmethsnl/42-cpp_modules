#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char* av[])
{
    PmergeMe sorter;
    
    if (!sorter.processInput(ac, av))
        return 1;
    
    sorter.executeSort();
    
    return 0;
}