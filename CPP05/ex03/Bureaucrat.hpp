/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:15:27 by asbouani          #+#    #+#             */
/*   Updated: 2026/02/09 18:15:28 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string _name;
        int               _grade;
    
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        //getters
        std::string getName() const;
        int getGrade() const;
        //grade manipulation
        void incrementGrade();
        void decrementGrade();
        
        void signForm(AForm& form);  //add function 
        void executeForm(AForm const &f);     //NEW
       
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw(); // function that describe the error
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw(); // function that describe the error
        };
};
//operator overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif