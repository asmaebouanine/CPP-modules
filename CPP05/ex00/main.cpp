/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:35:58 by asbouani          #+#    #+#             */
/*   Updated: 2026/02/28 23:59:02 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== TEST 1 ===" << std::endl;
    try
    {
        Bureaucrat b("Alice", 3);
        
        std::cout << b << std::endl;
        b.incrementGrade();
        b.incrementGrade();
        std::cout << b << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 2 ===" << std::endl;
    try
    {
        Bureaucrat c("Bob", 150);
        
        std::cout << c << std::endl;
        c.decrementGrade();
        std::cout << c << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "End of program!" << std::endl; 
}