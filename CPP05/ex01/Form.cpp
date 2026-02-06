/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:20:02 by asbouani          #+#    #+#             */
/*   Updated: 2026/02/04 18:58:12 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _gradeSign(150), _gradeExec(150), _signed(false) {}

Form::Form(const std::string& name, const int gradeSign, const int gradeExec) : _name(name),
             _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}
Form::Form(const Form& other) : _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec), _signed(other._signed){}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        _signed = other._signed;
    return (*this);
}

Form::~Form() {}

std::string Form::getName() const
{
    return (_name);
}
int Form::getGradeSign() const
{
    return (_gradeSign);
}
int Form::getGradeExec() const
{
    return (_gradeExec);
}
bool Form::getSigned() const
{
    return (_signed);
}

void Form::beSigned(Bureaucrat& b)
{
    if (b.getGrade() <= getGradeSign())
        _signed = true;
    else
        throw GradeTooLowException();
}
const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form grade is too high");
}
const char* Form::GradeTooLowException::what() const throw()
{
    return ("From grade is too low");
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
    out << f.getName() << " Grade to Sign " << f.getGradeSign() << " Grade to Execute "
        << f.getGradeExec() << " signed " << f.getSigned() << ".";
    return (out);
}
