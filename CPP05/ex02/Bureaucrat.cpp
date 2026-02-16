/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:21:17 by asbouani          #+#    #+#             */
/*   Updated: 2026/02/15 21:30:22 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        _grade = other._grade;
    return (*this);
}
Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
    return (_name);
}
int Bureaucrat::getGrade() const
{
    return (_grade);
}
void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}
void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}
void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << "." << std::endl;
    }
    catch(AForm::GradeTooLowException& e)
    {
        std::cout << getName() << " couldn't signed " << form.getName() << " because " << e.what() << "." << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &f)
{
    try
    {
        f.execute(*this);
        std::cout << getName() << " execute " << f.getName() << "." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << getName() << " couldn't execute " << f.getName() << " because " << e.what() << "." << std::endl;
    }
}
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
     out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
     return (out);
}