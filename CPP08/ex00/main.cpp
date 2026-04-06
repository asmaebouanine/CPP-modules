/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:23:05 by asbouani          #+#    #+#             */
/*   Updated: 2026/04/06 11:18:08 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main()
{
    try
    {
        std::vector<int> v ;
        v.push_back(99);
        v.push_back(33);
        v.push_back(55);
        v.push_back(88);
        v.push_back(22);    
        int n = 88;
    
        std::vector<int>::iterator result = easyfind(v, n);
        std::cout << "Value found: " << *result << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << "Value not found" << std::endl;
    }
};