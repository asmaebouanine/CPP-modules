/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 23:12:23 by asbouani          #+#    #+#             */
/*   Updated: 2026/03/12 21:55:36 by asbouani         ###   ########.fr       */
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
    for (; i < (int)str.length() - 1; i++)
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
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << ".0f\n";
        std::cout << "double: " << static_cast<double>(c) << ".0\n";
    }
    else if (isInt(str))
    {
        long num = strtol(str.c_str(), NULL, 10);
        if (num < 0 || num > 127)
            std::cout << "char: impossible\n";
        else if (num < 32 || num == 127)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: '" << static_cast<char>(num) << "'\n";
        if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << num << "\n";
        std::cout << "float: " << static_cast<float>(num) << ".0f\n";
        std::cout << "double: " << static_cast<double>(num) << ".0\n";
    }
    else if (isFloat(str))
    {
        float f = strtof(str.c_str(), NULL);
        if (f < 0 || f > 127)
            std::cout << "char: impossible\n";
        else if (f < 32 || f == 127)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: '" << static_cast<char>(f) << "'\n";
        // int
        if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << static_cast<int>(f) << "\n";
        // float
        if (f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max())
            std::cout << "float: inff\n";
        else
            std::cout << "float: " << f << "f\n";
        // double
        if (static_cast<double>(f) > std::numeric_limits<double>::max() || 
            static_cast<double>(f) < -std::numeric_limits<double>::max())
            std::cout << "double: inf\n";
        else
            std::cout << "double: " << static_cast<double>(f) << "\n";
    }
    else if (isDouble(str))
    {
       double d = strtod(str.c_str(), NULL);
        // char
        if (d < 0 || d > 127)
            std::cout << "char: impossible\n";
        else if (d < 32 || d == 127)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: '" << static_cast<char>(d) << "'\n";
        // int
        if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << static_cast<int>(d) << "\n";
        // float
        std::cout << "float: " << static_cast<float>(d) << "f\n";
        // double
        std::cout << "double: " << d << "\n";
    }
    else
        std::cout << "Type ont recognized" << std::endl;
}