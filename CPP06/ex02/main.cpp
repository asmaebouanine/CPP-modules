/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 21:07:30 by asbouani          #+#    #+#             */
/*   Updated: 2026/03/12 21:39:04 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>

int main()
{
    std::srand(std::time(NULL));
    Base* test = generate();
    std::cout << "Identify with pointer: ";
    identify(test);
    
    std::cout << "Identify with reference: ";
    identify(*test);
    
    delete test;
    
}