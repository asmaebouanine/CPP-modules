/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:33:49 by asbouani          #+#    #+#             */
/*   Updated: 2026/02/02 17:14:03 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
        const std::string _name;
        int               _grade;
    
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        //getters
        std::string getName() const;
        int getGrade() const;
        //grade manipulation
        void incrementGrade();
        void decrementGrade();
        //exception
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