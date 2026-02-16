/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:26:05 by asbouani          #+#    #+#             */
/*   Updated: 2026/02/15 21:48:51 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));
    try{
        Bureaucrat alice("Alice", 1);
        Bureaucrat alex("alex", 150);
        
        PresidentialPardonForm p("Criminal");
        RobotomyRequestForm r("Bender");
        ShrubberyCreationForm s("Garden");
        
        std::cout << "=== test shrubbery === " << std::endl;
        
        alice.signForm(s);
        
        alex.signForm(s);
        
        alice.executeForm(s);
        
        alex.executeForm(s);
        
        std::cout << "\n=== Test robotomy === " << std::endl;
        
        alice.signForm(r);
        alice.executeForm(r);
        alice.executeForm(r);
        
        std::cout << "\n=== Test Presidential === " << std::endl;
        
        alice.signForm(p);
        alice.executeForm(p);
        
        std::cout << alice << std::endl;
        alice.incrementGrade();
    }
    catch(std::exception& e){
        std::cout << "Catch all exception: " << e.what() << std::endl;
    }
    
    std::cout << "program is finished!" << std::endl; 
}