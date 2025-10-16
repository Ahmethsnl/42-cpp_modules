#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <limits>

class BitcoinExchange
{
private:
    std::map<std::string, double> _data;
    
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& valueStr, double& value) const;
    std::string trim(const std::string& str) const;
    double findClosestRate(const std::string& date) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    
    bool loadDatabase(const std::string& filename);
    void processInputFile(const std::string& filename);
};

#endif