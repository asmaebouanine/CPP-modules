/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:06:54 by asbouani          #+#    #+#             */
/*   Updated: 2026/04/13 23:54:29 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    try
    {
        Span bigSpan = Span(10000);
        std::srand(std::time(NULL));
        for (int i = 0; i < 10000; i++)
            bigSpan.addNumber(std::rand());
        std::cout << bigSpan.shortestSpan() << std::endl;
        std::cout << bigSpan.longestSpan() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}