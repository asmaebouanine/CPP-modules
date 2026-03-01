/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:26:05 by asbouani          #+#    #+#             */
/*   Updated: 2026/02/28 20:24:38 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>

int main()
{
    std::srand(std::time(NULL));
    std::cout << "=== TEST 1: PRESIDENTIAL PARDON FORM ===" << std::endl;
    try
    {
        Bureaucrat charlie("Charlie", 3);
        PresidentialPardonForm pardon("Marvin");
        
        std::cout << charlie << std::endl;
        std::cout << pardon << std::endl;
        
        charlie.signForm(pardon);
        charlie.executeForm(pardon);
        std::cout << pardon << std::endl;

    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 2: ROBOTOMY REQUEST FORM ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 42);
        RobotomyRequestForm robot("Bender");

        std::cout << bob << std::endl;
        std::cout << robot << std::endl;
        
        bob.signForm(robot);
        bob.executeForm(robot);
        std::cout << robot << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "\n=== TEST 3: SHRUBBYRY CREATION FORM ===" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 149);
        ShrubberyCreationForm shrub("Home");
        
        std::cout << alice << std::endl;
        std::cout << shrub << std::endl;
        
        alice.signForm(shrub);
        alice.executeForm(shrub);
        std::cout << shrub << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "End of program!" << std::endl; 
}