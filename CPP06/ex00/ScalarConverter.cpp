/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 23:12:23 by asbouani          #+#    #+#             */
/*   Updated: 2026/03/14 00:28:17 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return (*this);
}
ScalarConverter::~ScalarConverter() {}

bool isInt(std::string str)
{
    if (str.empty())
        return false;
    int i = 0; 
    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; i < (int)str.length(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}
bool isFloat(std::string str)
{
    if (str.empty())
        return false;
    int i = 0;
    bool dot = false;
    bool digit = false;
    
    if (str[str.length() - 1] != 'f')
        return false;
    if (str[i] == '-' || str[i] == '+')
        i++;
    for(;i < (int)str.length() - 1; i++)
    {
        if (str[i] == '.')
        {
            if (dot)
                return false;
            dot = true;
        }
        else if (!isdigit(str[i]))
            return false;
        else
            digit = true;
    }
    return (dot && digit);
}
bool isDouble(std::string str)
{
    if (str.empty())
        return false;
    int i = 0;
    bool dot = false;
    bool digit = false;
    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; i < (int)str.length(); i++)
    {
        if (str[i] == '.')
        {
            if (dot)
                return false;
            dot = true;
        }
        else if (!isdigit(str[i]))
            return false;
        else
            digit = true;
    }
    return (dot && digit);
}
void printType(char c, long i, float f, double d)
{
    if (d < 0 || d > 127)
        std::cout << "char: impossible\n";
    else if (d < 32 || d == 127)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << c << "'\n";
    if(i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    if (f == std::floor(f) && f < 1000000.0f && f > -1000000.0f)
        std::cout << "float: " << f << ".0f" << std::endl;
    else 
        std::cout << "float: " << f << "f" << std::endl;
    if (d == std::floor(d) && d < 1000000.0f && d > -1000000.0f)
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(std::string str)
{
    if (str == "nanf" || str == "-inff" || str == "+inff" || str == "nan" || str == "-inf" || str == "+inf")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        if (str == "nan" || str == "-inf" || str == "+inf")
        {
            std::cout << "float: " << str << "f\n";
            std::cout << "double: " << str << "\n";
        }
        else
        {
            std::cout << "float: " << str << "\n";
            std::cout << "double: " << str.substr( 0,str.length() - 1) << "\n";
        }
    }
    else if (str.length() == 1 && !isdigit(str[0]) && isprint(str[0]))
    {
        char c = str[0];
        printType(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
    }
    else if (isInt(str))
    {
        long i = static_cast<long>(strtol(str.c_str(), NULL, 10));
        printType(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
    }
    else if (isFloat(str))
    {
        
        float f = static_cast<float>(strtof(str.c_str(), NULL));
        printType(static_cast<char>(f), static_cast<long>(f), f, static_cast<double>(f));
    }
    else if (isDouble(str))
    {
       double d = static_cast<double>(strtod(str.c_str(), NULL));
       printType(static_cast<char>(d), static_cast<long>(d), static_cast<float>(d), d);
    }
    else
        std::cout << "Type not recognized" << std::endl;
}