/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:21:54 by asbouani          #+#    #+#             */
/*   Updated: 2026/04/23 10:21:01 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other)
{
    _numbers = other._numbers;
}
RPN RPN::operator=(const RPN& other)
{
    if (this == &other)
        return (*this);
    _numbers = other._numbers;
    return (*this);
}
RPN::~RPN() {}

int RPN::evaluate(std::stringstream& ss)
{
    std::string token;

    while (ss >> token)
    {
        //NUMBER
        if (token.length() == 1 && isdigit(token[0]))
            _numbers.push(token[0] - '0');
        //OPERATOR
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (_numbers.size() < 2)
            {
                std::cerr << "Error: invalid input" << std::endl;
                return 1;
            } 
            
            int b = _numbers.top(); _numbers.pop();
            int a = _numbers.top(); _numbers.pop();
            
            int result;
            
            if (token == "+")
                result = a + b;
            else if (token == "-")
                result = a - b;
            else if (token == "*")
                result = a * b;
            else if (token == "/")
            {
                if (b == 0)
                {
                    std::cerr << "Error: invalid input" << std::endl;
                    return 1;
                }
               result = a / b;
            }
            _numbers.push(result);
        }
        else
        {
            std::cerr << "Error: invalid input" << std::endl;
            return 1;
        }
    }
    if (_numbers.size() != 1)
    {
        std::cerr << "Error: invalid input" << std::endl;
        return 1;
    }
    std::cout << _numbers.top() << std::endl;
    return 0;
}

