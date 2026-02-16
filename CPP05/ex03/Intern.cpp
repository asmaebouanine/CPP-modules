/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:30:13 by asbouani          #+#    #+#             */
/*   Updated: 2026/02/15 21:25:45 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}
Intern::~Intern() {}

AForm* Intern::makePresidential(std::string target)
{
    return (new PresidentialPardonForm(target)); 
}
AForm* Intern::makeRobotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}
AForm* Intern::makeShrubbery(std::string target)
{
    return (new ShrubberyCreationForm(target));
}
AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string namesForm[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    
    AForm* (*creationsForm[])(std::string target) = {&Intern::makePresidential, &Intern::makeRobotomy, &Intern::makeShrubbery};
    for(int i = 0; i < 3; i++)
    {
        if (name == namesForm[i])
        {
            std::cout << "Intert creates " << name << std::endl;
            return (creationsForm[i](target));
        }
    }

    std::cout << "Intert cannot create " << name << std::endl;
    return (NULL);
}