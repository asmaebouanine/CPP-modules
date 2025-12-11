/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:44:03 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/11 17:39:46 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Error: more or less then 3 arguments." << std::endl;
        return 1;
    }
    
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    
    if (s1.empty())
    {
        std::cout << "Error: s1 is emply string" << std::endl;
        return 1;
    }
    
    Replacer replacer(filename, s1, s2);
    replacer.replace();
    return 0;
 }