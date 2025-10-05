#include "RPN.hpp"
#include <stdexcept>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string& token) const
{
    if (token.empty())
        return false;
    
    if (token.length() == 1 && isdigit(token[0]))
        return true;
    
    return false;
}

double RPN::performOperation(double a, double b, const std::string& op) const
{
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    else if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("Division by zero");
        return a / b;
    }
    throw std::runtime_error("Unknown operator");
}

double RPN::calculate(const std::string& expression)
{
    while (!_stack.empty())
        _stack.pop();
    
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token)
    {
        if (isNumber(token))
        {
            double num = std::atof(token.c_str());
            _stack.push(num);
        }
        else if (isOperator(token))
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");
            
            double b = _stack.top();
            _stack.pop();
            double a = _stack.top();
            _stack.pop();
            
            double result = performOperation(a, b, token);
            _stack.push(result);
        }
        else
        {
            throw std::runtime_error("Error");
        }
    }
    
    if (_stack.size() != 1)
        throw std::runtime_error("Error");
    
    return _stack.top();
}