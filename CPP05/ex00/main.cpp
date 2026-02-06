/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:35:58 by asbouani          #+#    #+#             */
/*   Updated: 2026/02/04 17:38:53 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("Alice", 3);
        Bureaucrat c("Asmae", 150);
        
        std::cout << b << std::endl;
        b.incrementGrade();
        b.incrementGrade();
        std::cout << b << std::endl;
        
        std::cout << c << std::endl;
        c.decrementGrade();
        std::cout << c << std::endl;
    }
    
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "the program ended!!" << std::endl; 
}