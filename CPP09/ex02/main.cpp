/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:42:27 by asbouani          #+#    #+#             */
/*   Updated: 2026/05/01 17:20:07 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: invalid input" << std::endl;
        return 1;
    }
    
    PmergeMe sorter;
    
    if (sorter.parseInput(ac, av))
    {
        std::cerr << "Error: invalid input" << std::endl;
        return 1;
    }
    
    sorter.printBefor();
    sorter.sort();
    sorter.printAfter();
    sorter.printTime();
    
    return 0;
}