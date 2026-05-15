/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:21:13 by asbouani          #+#    #+#             */
/*   Updated: 2026/05/13 20:58:19 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    BitcoinExchange data;
    std::map<std::string, float> db = data.loadDatabase("data.csv");
    if (db.empty())
    {
        std::cout << "Error: invalid database" << std::endl;
        return 1;   
    }
    if (data.processInput(av[1], db))
        return 1;
     return (0);
}