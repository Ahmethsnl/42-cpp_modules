#include <iostream>
#include <limits>
 
int main()
{
    double max_doub = std::numeric_limits<double>::max();
    float max_float = std::numeric_limits<float>::max();
    double inf_doub = std::numeric_limits<double>::infinity();
    float inf_float = std::numeric_limits<float>::infinity();
    int inf_int = std::numeric_limits<int>::infinity();
    int max_int = std::numeric_limits<int>::max();
    auto max_a = std::numeric_limits<float>::max();
    auto inf_a = std::numeric_limits<double>::infinity();
 
    if (inf_doub > max_doub)
        std::cout << inf_doub << " is greater than " << max_doub << '\n';
    if (inf_float > max_float)
        std::cout << inf_float << " is greater than " << max_float << '\n';
    if (inf_int > max_int)
        std::cout << inf_int <<  " is greater than " << max_int << '\n';
    std::cout <<inf_int << "is greater than" << std::endl;
    if (inf_a > max_a)
        std::cout << inf_a << " is greater than " << max_a << std::endl;
}