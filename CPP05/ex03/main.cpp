/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:19:30 by asbouani          #+#    #+#             */
/*   Updated: 2026/02/26 00:10:07 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
    Intern intern;
    Bureaucrat b("bureacrat", 1);

    std::cout << "=== TEST 1: PRESIDENTIAL PARDON ===" << std::endl;
    AForm* ppf;
    ppf = intern.makeForm("presidential pardon", "Criminal");
    if (ppf)
    {
        b.signForm(*ppf);
        b.executeForm(*ppf);
        delete (ppf);
    }

    std::cout << "\n=== TEST 2: ROBOTOMY REQUEST ===" << std::endl;
    AForm* rpf;
    rpf = intern.makeForm("robotomy request", "Bender");
    if (rpf)
    {
        b.signForm(*rpf);
        b.executeForm(*rpf);
        delete (rpf);
    }

    std::cout << "\n=== TEST 3: SHRUBBERY CREATION ===" << std::endl;
    AForm* scf;
    scf = intern.makeForm("shrubbery creation", "garden");
    if (scf)
    {
        b.signForm(*scf);
        b.executeForm(*scf);
        delete (scf);
    }
    
    std::cout << "\n=== TEST 4: UNKWON FORM ===" << std::endl;
    AForm* uf;
    uf = intern.makeForm("test form", "test");
    if (uf)
    {
        b.signForm(*uf);
        delete uf;
    }
    std::cout << "\n End of program" << std::endl;
}

