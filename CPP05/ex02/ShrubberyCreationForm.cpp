/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:20:41 by asbouani          #+#    #+#             */
/*   Updated: 2026/02/12 20:28:03 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrybberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return(*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream outfile((_target + "shrubbery").c_str());
    if (outfile.is_open())
    {
        outfile << "     //\\\\" << std::endl;
        outfile << "    //  \\\\" << std::endl;
        outfile << "   //    \\\\" << std::endl;
        outfile << "  //      \\\\" << std::endl;
        outfile << " //        \\\\" << std::endl;
        outfile << "///////\\\\\\\\\\\\\\" << std::endl;
        outfile << "     | |" << std::endl;
        outfile << "     | |" << std::endl;
        outfile << "     | |" << std::endl;
        outfile << "     | |" << std::endl;
        // outfile.close(); 
        outfile << "       -" << std::endl;
        outfile << "    /~~   \\" << std::endl; 
        outfile << " /         ~~\\" << std::endl;
        outfile << "{             }" << std::endl;
        outfile << " \\ -     -   /" << std::endl;
        outfile << "   ~ \\   /  ~" << std::endl;
        outfile << "- -   | | - " << std::endl;
        outfile << "  _ - | |   -" << std::endl;
        outfile << "     // \\\\" << std::endl;
        outfile.close();
    }
    else
        std::cout << "could not create the file" << std::endl;
}
