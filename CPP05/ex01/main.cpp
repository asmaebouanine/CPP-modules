/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:53:26 by asbouani          #+#    #+#             */
/*   Updated: 2026/02/04 18:58:43 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b("Alice", 6);
        Bureaucrat c("Asmae", 150);
        Form f("texForm", 77, 5);
        Form m("Second form", 2, 6);
        b.signForm(f);
        f.beSigned(b);
    
        std::cout << f << std::endl;
        
        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
        
        std::cout << c << std::endl;
        c.decrementGrade();
        std::cout << c << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    catch(Form::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Form::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "program is finished!" << std::endl;
    
}