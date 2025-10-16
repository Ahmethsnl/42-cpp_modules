#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _data = other._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string& str) const
{
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10)
        return false;
    
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    for (size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }
    
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (year < 2009 || year > 2025)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    
    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28))
            return false;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return false;
    }
    
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, double& value) const
{
    if (valueStr.empty())
        return false;
    
    char* endptr;
    value = std::strtod(valueStr.c_str(), &endptr);
    
    if (*endptr != '\0')
        return false;
    
    if (value < 0)
        return false;
    if (value > 1000)
        return false;
    
    return true;
}

bool BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return false;
    }
    
    std::string line;
    bool firstLine = true;
    
    while (std::getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue;
        }
        
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
            continue;
        
        std::string date = trim(line.substr(0, commaPos));
        std::string rateStr = trim(line.substr(commaPos + 1));
        
        if (!isValidDate(date))
            continue;
        
        char* endptr;
        double rate = std::strtod(rateStr.c_str(), &endptr);
        if (*endptr != '\0')
            continue;
        
        _data[date] = rate;
    }
    
    file.close();
    return true;
}

double BitcoinExchange::findClosestRate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = _data.find(date);
    if (it != _data.end())
        return it->second;
    
    it = _data.lower_bound(date);
    if (it == _data.begin())
        return 0;
    
    --it;
    return it->second;
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    bool firstLine = true;
    
    while (std::getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue;
        }
        
        size_t pipePos = line.find(" | ");
        if (pipePos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 3));
        
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        double value;
        if (!isValidValue(valueStr, value))
        {
            if (valueStr.find('-') != std::string::npos)
                std::cerr << "Error: not a positive number." << std::endl;
            else
                std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        
        double rate = findClosestRate(date);
        double result = value * rate;
        
        std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << result << std::endl;
    }
    
    file.close();
}