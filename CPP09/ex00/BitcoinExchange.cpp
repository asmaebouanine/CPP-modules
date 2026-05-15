/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:54:01 by asbouani          #+#    #+#             */
/*   Updated: 2026/05/14 18:54:44 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    _database = other._database;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _database = other._database;
    return (*this);
}
BitcoinExchange::~BitcoinExchange() {}

std::map<std::string, float> BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::map<std::string, float> db;
    std::ifstream file(filename.c_str());
    
    if (!file.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        return (db);
    }
    std::string line;
    std::getline(file, line);
    
    while(std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string priceStr;
        std::getline(ss, date, ',');
        std::getline(ss, priceStr);
        
        float price = atof(priceStr.c_str());
        db[date] = price;
    }
    return (db);
}

std::string findClosestDate(const std::map<std::string, float>& db, const std::string& date)
{
    std::map<std::string, float>::const_iterator it = db.lower_bound(date);
    
    if (it != db.end() && it->first == date)
        return it->first;

    if (it == db.begin())
        return "";
    --it;
    
    return it->first;
}

bool isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool parseDate(std::string& date)
{
    if (date.length() != 10)
        return false;
    
    for(size_t i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                return false;
        }
        else
        {
            if (!isdigit(date[i]))
                return false;
        }
    }
    int year = std::atoi(date.substr(0,4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
  
    if (day < 1 || day > 31)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (month == 2)
    {
        if (isLeapYear(year))
        {
            if (day > 29)
                return false;
        }
        else
        {
            if (day > 28)
                return false;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day == 31)
            return false;
    }
    return true;
}

bool isNumber(const std::string& valueStr)
{
    size_t i = 0;
    int flag = 0;
    if (valueStr.empty())
        return false;
    if (valueStr[i] == '-' || valueStr[i] == '+')
        i++;
    if (valueStr.length() == i)
        return false;
    for (; i < valueStr.length(); i++)
    {
        if (!isdigit(valueStr[i]) && valueStr[i] != '.')
            return false;
        if (valueStr[i] == '.')
            flag++;
    }
    if (flag > 1)
        return false;
    return true;
}

std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t");
    return (str.substr(first, (last - first + 1)));
}

int BitcoinExchange::processInput(const std::string& inputFile, const std::map<std::string, float>& db)
{
    std::ifstream file(inputFile.c_str());
    
    if (!file.is_open())
    {
        std::cout << "Error: cannot open input file" << std::endl;
        return 1;
    }
    std::string line;
    
    if (!std::getline(file, line))
    {
        std::cout << "Error: empty file" << std::endl;
        return 1;
    }
    
    while(std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string valueStr;
        std::getline(ss, date, '|');
        std::getline(ss, valueStr);
        
        date = trim(date);
        valueStr = trim(valueStr);
        
        if (!parseDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (!isNumber(valueStr))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue ;
        }
        float value = std::atof(valueStr.c_str());
    
        if (!(value >= 0 ))
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue ;
        }
        if (!(value <= 1000))
        {
            std::cout << "Error: too large a number." << std::endl;
            continue ;
        }
        std::string closestDate = findClosestDate(db, date);
        if (closestDate.empty())
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
    
        float price = db.at(closestDate);
        float result = price * value;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    
    return 0;
}