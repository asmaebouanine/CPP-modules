/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:05:03 by asbouani          #+#    #+#             */
/*   Updated: 2026/02/04 18:17:11 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name; //name of the form
        const int         _gradeSign; // the minimum grade requered to sign the form
        const int         _gradeExec;  // 
        bool              _signed; // the status of the contrat if signed of not
    
    public:
        Form();
        Form(const std::string& name, const int gradeSign, const int gradeExec);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        
        std::string getName() const;
        int         getGradeSign() const;
        int         getGradeExec() const;
        bool        getSigned() const;
        
        void    beSigned(Bureaucrat& b);
        
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif