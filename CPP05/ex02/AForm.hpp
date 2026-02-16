/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:21:31 by asbouani          #+#    #+#             */
/*   Updated: 2026/02/09 12:09:20 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name; //name of the form
        const int         _gradeSign; // the minimum grade requered to sign the form
        const int         _gradeExec;  // 
        bool              _signed; // the status of the contrat if signed of not
    
    public:
        AForm();
        AForm(const std::string& name, const int gradeSign, const int gradeExec);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        
        std::string getName() const;
        int         getGradeSign() const;
        int         getGradeExec() const;
        bool        getSigned() const;
        
        void    beSigned(Bureaucrat& b);
        
        void execute(Bureaucrat const &executor) const; //add function
        virtual void executeAction() const = 0; // new
        
        
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif