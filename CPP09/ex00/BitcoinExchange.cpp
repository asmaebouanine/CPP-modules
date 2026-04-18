/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:54:01 by asbouani          #+#    #+#             */
/*   Updated: 2026/04/18 22:53:48 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, float> loadDatabase(const std::string& filename)
{
    std::map<std::string, float> db;
    std::ifstream file(filename.c_str());
      
    if (!file.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        return (db);
    }
    std::string line;
    std::getline(file, line); //skip header
    
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
bool parseDate(std::string& date)
{
    if (date.length() != 11)
        return false;
        
    for(size_t i = 0; i < date.length()- 1 ; i++)
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
    
    //Extract year, month, day
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (month < 1 || month > 12)
        return false;
    if (day < 0 || day > 31)
        return false;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            if (day == 31)
                return false;
        }
    return true;
}
bool isNumber(const std::string& str)
{
    size_t i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; i < str.length(); i++)
    {
        if (!isdigit(str[i]) && str[i] != '.')
            return false;
    }
    return true;
}
int processInput(const std::string& inputFile, const std::map<std::string, float>& db)
{
    
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: cannot open input file" << std::endl;
        return 1;
    }
    std::string line;
    std::getline(file, line); //skip header
    
    while(std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string valueStr;

        std::getline(ss, date, '|');
        std::getline(ss, valueStr);
        
        //remove spaces
        if (!valueStr.empty() && valueStr[0] == ' ')
            valueStr = valueStr.substr(1);
        if (!parseDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (!isNumber(valueStr))
        {
            std::cout << "Error: not a number." << std::endl;
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
        std::cout << date << "=> " << value << " = " << result << std::endl;
    }
    return 0;
}
