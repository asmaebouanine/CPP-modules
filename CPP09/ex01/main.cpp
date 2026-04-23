/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:19:15 by asbouani          #+#    #+#             */
/*   Updated: 2026/04/23 10:20:40 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: bad input." << std::endl;
        return 1;
    }
    
    std::stringstream ss(av[1]);
    RPN rpn;
    if (rpn.evaluate(ss))
        return 1;
    return 0;
}